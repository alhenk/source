#include "strings.h"
//
int16_t strLength(uint8_t *str){
	uint8_t *s;
	for (s=str;*s;++s)
		;
	return (int16_t)(s-str);
}
 
void reverse(uint8_t *str){
	int i,j;
	uint8_t temp;

	for(i=0,j=strLength(str)-1;i<j;i++,j--){
		temp=str[i];
	    str[i]=str[j];
	    str[j]=temp;
	}
}
 
//integer to ASCII, formated: converts d into r symbols, placed in str
void itoaf(int16_t val, uint8_t *s,int16_t field_width,tIntFormat mode){
	int16_t k,idx,pads,shift;
	int16_t sign=0;

	if (val < 0){
		sign=1;
		val=-val;
	}

	for (idx=0;val;++idx){
		s[idx]=val%10+'0';
	    val=val/10;
	}
	s[idx]='\0';

	if (strLength(s)+sign>field_width){
		for (k=0;k<field_width;++k){
			s[k]='?';
		}
		s[k]='\0';
		return;
	}

	pads=field_width-strLength(s)-sign;

	switch (mode){
	case ZEROS_ON_LEFT:     //Pads with zeros on left
		s[idx]='\0';
		for (k=0;k<pads;++k,++idx){
    		s[idx]='0';
		}

		if (sign){
			s[idx]='-';
			++idx;
		}
		s[idx]='\0';
		reverse(s);
	break;

	case SPACES_ON_LEFT:    //Pads with spaces on left

		if (sign){
			s[idx]='-';
			++idx;
		}
		s[idx]='\0';
		for (k=0;k<pads;++k,++idx){
			s[idx]=' ';
		}
		s[idx]='\0';
		reverse(s);
	break;

	case SPACES_ON_RIGHT:   //Pads with spaces on right
		if (sign){
			s[idx]='-';
			++idx;
		}
		s[idx]='\0';
		reverse(s);
		for (k=0;k<pads;++k,++idx){
			s[idx]=' ';
		}
		s[idx]='\0';
	break;
	case CENTERED_WITH_SPACES:   //Pads with spaces on right
		if (sign){
			s[idx]='-';
			++idx;
		}
		s[idx]='\0';

		for (k=0;k<pads/2;++k,++idx){
			s[idx]=' ';
		}

/*		if ((pads/2)*2 == pads){
			for (k=0;k<(pads/2);++k,++idx){
				s[idx]=' ';
			}
		}else{
			for (k=0;k<(pads/2)+1;++k,++idx){
				s[idx]=' ';
			}
		}*/



		s[idx]='\0';
		reverse(s);
		if ((pads/2)*2 == pads){
			for (k=0;k<(pads/2);++k,++idx){
				s[idx]=' ';
			}
		}else{
			for (k=0;k<(pads/2)+1;++k,++idx){
				s[idx]=' ';
			}
		}

/*		for (k=0;k<pads/2;++k,++idx){
					s[idx]=' ';
				}*/


		s[idx]='\0';

	break;
	default:
	break;
	}
}


#define BUFSIZE (sizeof(long) * 8 + 1)

uint8_t *ltoa(long N, uint8_t *str, int base)
{
      register int i = 2;
      long uarg;
      uint8_t *tail, *head = str, buf[BUFSIZE];

      if (36 < base || 2 > base)
            base = 10;                    /* can only use 0-9, A-Z        */
      tail = &buf[BUFSIZE - 1];           /* last character position      */
      *tail-- = '\0';

      if (10 == base && N < 0L)
      {
            *head++ = '-';
            uarg    = -N;
      }
      else  uarg = N;

      if (uarg)
      {
            for (i = 1; uarg; ++i)
            {
                  register ldiv_t r;
                  r       = ldiv(uarg, base);
                  *tail-- = (char)(r.rem + ((9L < r.rem) ?
                                  ('A' - 10L) : '0'));
                  uarg    = r.quot;
            }
      }
      else  *tail-- = '0';

      memcpy(head, ++tail, i);
      return str;
}



uint8_t *ftoa(float f, int *status)
{
    long mantissa, int_part, frac_part;
    short exp2;
    LF_t x;
    uint8_t *p;
    static uint8_t outbuf[15];

    *status = 0;
    if (f == 0.0){
        outbuf[0] = '0';
        outbuf[1] = '.';
        outbuf[2] = '0';
        outbuf[3] = 0;
        return outbuf;
    }
    x.F = f;

    exp2 = (unsigned char)(x.L >> 23) - 127;
    mantissa = (x.L & 0xFFFFFF) | 0x800000;
    frac_part = 0;
    int_part = 0;
	if (exp2 >= 31){
        *status = 1;   //_FTOA_TOO_LARGE
        return 0;
    }
    else if (exp2 < -23){
        *status = -1; //_FTOA_TOO_SMALL
        return 0;
    }
    else if (exp2 >= 23)
        int_part = mantissa << (exp2 - 23);
        else if (exp2 >= 0) {
        int_part = mantissa >> (23 - exp2);
        frac_part = (mantissa << (exp2 + 1)) & 0xFFFFFF;
    }
    else /* if (exp2 < 0) */
        frac_part = (mantissa & 0xFFFFFF) >> -(exp2 + 1);

    p = outbuf;

    if (x.L < 0)
        *p++ = '-';

    if (int_part == 0)
        *p++ = '0';
    else{
        ltoa(int_part, p, 10);
        while (*p)
    p++;
    }
    *p++ = '.';

    if (frac_part == 0)
        *p++ = '0';
    else{
        uint8_t m, max;
        max = sizeof (outbuf) - (p - outbuf) - 1;
        if (max > 7)
            max = 7;
        /* print BCD */
        for (m = 0; m < max; m++){
            /* frac_part *= 10; */
            frac_part = (frac_part << 3) + (frac_part << 1); 
            *p++ = (frac_part >> 24) + '0';
            frac_part &= 0xFFFFFF;
        }
        /* delete ending zeroes */
        for (--p; p[0] == '0' && p[-1] != '.'; --p)
                           ;
        ++p;
    }
    *p = 0;

    return outbuf;
}

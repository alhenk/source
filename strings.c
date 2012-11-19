///
#include "strings.h"


int16_t strlength(uint8_t *str)
{
	const uint8_t *s;

	for (s = str; *s; ++s)
		;
	return (s - str);
}
 
 /* reverse string */
 void reverse(uint8_t *s)
 {
     int i, j;
     uint8_t c;
 
     for (i = 0, j = strlength(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }
 
 /* itoa:  convert n into symbols s */
  void itoa(int16_t n, uint8_t *s)
 {
     int i, sign;
 
     if ((sign = n) < 0) /* define sign */
         n = -n;         /* make n positive */
     i = 0;
     do        /* generate symbols in reverse order */
      {
	    s[i++] = n % 10 + '0';  /* next digit */
      } 
	 while ((n /= 10) > 0);     /*  */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }

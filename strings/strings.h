#include <stdlib.h>
#include <string.h>
#include "stm32f10x.h"
#include "RTC.h"

typedef union 
     {
        long  L;
        float F;
     } LF_t;

typedef enum{
    ZEROS_ON_LEFT,
	SPACES_ON_LEFT,
	SPACES_ON_RIGHT
} tIntFormat;


//int16_t strlength(uint8_t *str);
int16_t strLength(uint8_t *str);
void reverse(uint8_t *s);
void itoaf(int16_t val, uint8_t *s,int16_t field_width,tIntFormat mode);
uint8_t *ftoa(float f, int *status);

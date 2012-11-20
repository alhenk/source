#include <stdlib.h>
#include <string.h>

typedef char uint8_t;

typedef union 
     {
        long  L;
        float F;
     } LF_t;

typedef enum{
    ZEROS_ON_LEFT,
	SPACES_ON_LEFT,
	SPACES_ON_RIGHT,
	CENTERED_WITH_SPACES
} tIntFormat;


//int16_t strlength(uint8_t *str);
int16_t strLength(uint8_t *str);
void reverse(uint8_t *s);
uint8_t *itoaf(int16_t val, uint8_t *str,int16_t field_width,tIntFormat mode);
uint8_t *ftoa(float f, int *status);


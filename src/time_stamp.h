/* Preprocessor's directives definition*/
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int hour;
    int minute;
    int second;
}tTime;

 void getTime(tTime *p_time);
 void showTimeStamp(void);
 void timeTreat(int start_pos, char *str);

/*
 ============================================================================
 Name        : test_strings.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "strings.h"


int main(void) {
//	uint8_t min[9];
//	uint8_t hour[9];
	uint8_t buff[9];
//	int16_t i,j;


/*    for (i=0;i<24;i++){
    	for (j=0;j<60;j++){
    		itoaf(j,min,2,0);
    		itoaf(i,hour,2,0);
    		//printf("\%s\%c\%s\n",hour,':',min);
    	}
    }*/
/*    itoaf(123,buff,9,ZEROS_ON_LEFT);
    printf("%s %s %s\n","<<<",buff,">>>");
    itoaf(123,buff,9,SPACES_ON_LEFT);
    printf("%s %s %s\n","<<<",buff,">>>");
    itoaf(123,buff,9,SPACES_ON_RIGHT);
    printf("%s %s %s\n","<<<",buff,">>>");
    puts("****123456789****");
    puts(" ");
    itoaf(-123,buff,9,ZEROS_ON_LEFT);
    printf("%s %s %s\n","<<<",buff,">>>");
    itoaf(-123,buff,9,SPACES_ON_LEFT);
    printf("%s %s %s\n","<<<",buff,">>>");
    itoaf(-123,buff,9,SPACES_ON_RIGHT);
    printf("%s %s %s\n","<<<",buff,">>>");
    puts("****123456789****");
    puts(" ");
    itoaf(-123,buff,4,ZEROS_ON_LEFT);
    printf("%s %s %s\n","<<<",buff,">>>");
    itoaf(-123,buff,4,SPACES_ON_LEFT);
    printf("%s %s %s\n","<<<",buff,">>>");
    itoaf(-123,buff,4,SPACES_ON_RIGHT);
    printf("%s %s %s\n","<<<",buff,">>>");
    puts("****1234****");
    puts(" ");
    itoaf(-123,buff,3,ZEROS_ON_LEFT);
    printf("%s %s %s\n","<<<",buff,">>>");
    itoaf(-123,buff,3,SPACES_ON_LEFT);
    printf("%s %s %s\n","<<<",buff,">>>");
    itoaf(-123,buff,3,SPACES_ON_RIGHT);
    printf("%s %s %s\n","<<<",buff,">>>");
    puts("****123****");
    puts(" ");
    itoaf(1234,buff,3,ZEROS_ON_LEFT);
    printf("%s%s%s\n","<<<",buff,">>>");
    itoaf(1234,buff,3,SPACES_ON_LEFT);
    printf("%s%s%s\n","<<<",buff,">>>");
    itoaf(1234,buff,3,SPACES_ON_RIGHT);
    printf("%s%s%s\n","<<<",buff,">>>");
    puts("***123***");
    puts(" ");*/


    itoaf(1,buff,4,CENTERED_WITH_SPACES);
    printf("%s%s%s\n","<<<",buff,">>>");
    itoaf(-1,buff,4,CENTERED_WITH_SPACES);
    printf("%s%s%s\n","<<<",buff,">>>");
    itoaf(12,buff,4,CENTERED_WITH_SPACES);
    printf("%s%s%s\n","<<<",buff,">>>");
    itoaf(-21,buff,4,CENTERED_WITH_SPACES);
    printf("%s%s%s\n","<<<",buff,">>>");
    itoaf(-921,buff,4,CENTERED_WITH_SPACES);
    printf("%s%s%s\n","<<<",buff,">>>");
    itoaf(921,buff,4,CENTERED_WITH_SPACES);
    printf("%s%s%s\n","<<<",buff,">>>");
    itoaf(-9212,buff,4,CENTERED_WITH_SPACES);
    printf("%s%s%s\n","<<<",buff,">>>");
    puts("***1234***");

 	return EXIT_SUCCESS;
}


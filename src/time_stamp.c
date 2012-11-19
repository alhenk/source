#include "time_stamp.h"
#include "strings.h"
/*Main function configuration*/
/*int main(void)
{ 
    showTimeStamp();

	return 0;
}*/

//showTimeStamp
void showTimeStamp(void){
	char str[]="00:00:00";
    int start_pos;

	start_pos=0;
	timeTreat(start_pos,str);
    start_pos=3;
	timeTreat(start_pos,str);
	start_pos=6;
	timeTreat(start_pos,str);
	
/*	d=time.minute;
	itoaf(d,buf,2);
	s[3]=buf[0];
	s[4]=buf[1];

	d=time.second;
	itoaf(d,buf,2);
	s[6]=buf[0];
	s[7]=buf[1];
*/
}

void timeTreat(int start_pos,char *str){
	int time_value,i,j;
	int up_bound=60;
	char buf[20];
    tTime time;
	tTime *p_time;
	p_time = &time;
	getTime(p_time);

	if (start_pos==0){
	    time_value=time.hour;
		up_bound=24;
	}
	else if(start_pos==3){
	    time_value=time.minute;
	}
	else{
	    time_value=time.second;
	}

	if (time_value>0 && time_value<up_bound){
	    itoaf(time_value,buf,2,0);
		for(i=start_pos,j=0;i<start_pos+2;i++,j++){
		    str[i]=buf[j];
		}
	}
	else{
	    for(i=start_pos;i<start_pos+2;i++){
		    str[i]='*';
		}
	}
}


//getTime
void getTime(tTime *p_time){
    p_time->hour=12;
    p_time->minute=3;
    p_time->second=45;
}//end getTime


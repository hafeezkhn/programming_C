#include<signal.h>
#include<time.h>

#include<errno.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<memory.h>
#include<stdint.h>
#include<stdbool.h>


static void print_current_system_time(){

	time_t t;
	time(&t);
	printf("%s ",ctime(&t));

}

//user defined number
 typedef struct pair_number{
   int a; 
   int b;
 }pair_t;

pair_t pair = {10,20};

//timer callback which will call every time the timer expires
//signature of function : void <fnc-name>(union  sigval)
void timer_callback(union sigval arg)
{
 print_current_system_time();
 
 pair_t *pair = (pair_t *) arg.sival_ptr; //extract user data struct

 printf("pair :[%u %u]",pair->a,pair->b);

}

void timer_demo()
{
 int ret;
 struct sigevent evp;

 timer_t timer;
 memset(&timer,0,sizeof(timer_t));
 memset(&evp,0,sizeof(struct sigevent));
//fill user defined data sturuct
//when timer expire this will be passed as arg to timer callback
 evp.sigev_value.sival_ptr = (void *)&pair;

 evp.sigev_notify = SIGEV_THREAD;
 evp.sigev_notify_function = timer_callback;
 
 ret = timer_create(CLOCK_REALTIME,&evp,&timer);

 if(ret <0)
 {
 printf("%d\n",errno);
 exit(0);
 }

struct itimerspec ts;

 ts.it_value.tv_sec = 5;
 ts.it_value.tv_nsec = 0;

 ts.it_interval.tv_sec = 3;
 ts.it_interval.tv_nsec = 0;

ret = timer_settime(timer,0,&ts,NULL);

}

int main(int argc,char **argv)
{
  timer_demo();
  pause();
return 0;
}

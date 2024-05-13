/*1. From one parent create 5 child processes.
Each child should run for 5 seconds and print count along with its pid.
Parent should wait for all child processes
to complete and clean all of them. 
Hint: use loop to fork() multiple child processes.*/


#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
 int ret,i,s;
 for(i=1;i<6;i++)
 {  
   int count = 0;
	ret = fork();
	if(ret==0)
	{       
		 	//child task
		   printf("child process %d  executing\n",i);
		   while(count != 5)
		    {
			 count++;
			 sleep(1);
			 printf("%d\n",count);
		    }
		  // printf("%d\n",count);
		   printf("%d\n",getpid());
			//sleep(5);
			printf("end of child process %d..\n",i);
			_exit(0);
   	}
 }	
 
	//parent task (do its own task and also read the exit status of child process)
    printf("parent process executing..");
	for(i=0;i<5;i++)
	{
	 waitpid(-1,&s,0);//same as wait(&s)
	 printf("child %d exit:%d\n",i,WEXITSTATUS(s));
	}
  
  return 0;
}


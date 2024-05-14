#include<stdio.h>
#include<unistd.h>
#include<signal.h>
int main()
{
int ret,pid,sig;
printf("enter a pid:\n");
scanf("%d",&pid);

printf("Enter a sig:\n");
scanf("%d",&sig);

ret = kill(pid,sig);
printf("%d\n",ret);

return 0;
}

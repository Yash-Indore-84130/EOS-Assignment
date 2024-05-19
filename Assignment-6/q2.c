#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int ret1, ret2, ret3, s1, s2, s3, i, ret4, s4;
    ret1 = fork();
    if(ret1 == 0)
    {
        ret2 = fork();
        if(ret2 == 0)
        {
            ret3 = fork();
            if(ret3 == 0)
            {
                ret4 = fork();
                if(ret4 == 0)
                {    
                    for(i = 1; i <= 5; i++)
                    {
                        printf("D\n");
                        sleep(5);
                    }
                    _exit(0);
                }
                for(i = 1; i <= 5; i++)
                {
                    printf("C\n");
                    sleep(5);
                }
                waitpid(ret4, &s4, 0);
                _exit(0);
            }
            for(i = 1; i <= 5; i++)
            {
                printf("B\n");
                sleep(5);
            }
            waitpid(ret3, &s3, 0);
            _exit(0);
        }
        for(i = 1; i <= 5; i++)
        {
            printf("A\n");
            sleep(5);
        }
        waitpid(ret2, &s2, 0);
        _exit(0);
    }
    for(i = 1; i <= 5; i++)
    {
        printf("parent\n");
        sleep(5);
    }
    waitpid(ret1, &s1, 0);
    return 0;
}


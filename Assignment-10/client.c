#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

// p1 -- writer
int main() {
	int fd, n1,n2,fd1;
    int num1,num2,sum;
	fd = open("/tmp/desd_fifo", O_WRONLY);
	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("Enter a two numbers : ");
	scanf("%d %d",&num1,&num2);

	write(fd, &num1, sizeof(num1));
	write(fd, &num2, sizeof(num2));
	fd1 = open("/tmp/desd_fifo", O_RDONLY);
	
	read(fd1, &sum, sizeof(sum));
	printf("Addition two number is: %d \n", sum);

	close(fd);
	close(fd1);
	return 0;
}


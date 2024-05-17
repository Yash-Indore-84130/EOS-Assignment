#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

// p2 -- reader
int main() {
	int fd, cnt,fd1;
    int sum,n1,n2;
	fd = open("/tmp/desd_fifo", O_RDONLY);

	if(fd < 0) {
		perror("open() failed");
		_exit(1);
	}

	printf("waiting for data...\n");
	 read(fd, &n1, sizeof(n1));
	 read(fd, &n2, sizeof(n2));
	printf("num1 and num2 is = %d %d",n1,n2);
	sum = n1+n2;
	fd1 = open("/tmp/desd_fifo", O_WRONLY);


	write(fd1, &sum, sizeof(sum));
//	printf("read from fifo: %d bytes -- %s\n", cnt, str);

	close(fd);
	close(fd1);
	return 0;
}



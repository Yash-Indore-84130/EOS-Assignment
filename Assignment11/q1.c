#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>


int arr[] = {2,4,9,3,1,5,8,6,10,7};

void *thread_func(void *param) {

    int *arr = (int*)param;

	for (int i = 0; i < 10; i++) {
      int min_index = i;
        // Find the minimum element in
        // unsorted array
 
        for (int j = i + 1; j < 10; j++) {
            if (arr[j] < arr[min_index])
                min_index = j;
        }

        // Swap the found minimum element
        // with the first element
        int temp = arr[i];
		arr[i] = arr[min_index];
		arr[min_index] = temp;
	}
	
	pthread_exit(NULL);

}

int main() {
	int ret;
	pthread_t t1;
	
    ret = pthread_create(&t1, NULL, thread_func, arr);
	printf("main thread waiting for t1 thread...\n");
	pthread_join(t1, NULL); 
		// current thread (main) will wait for completion of given thread (t1)
		// step1: block current thread until completion of given thread
		// step2: collect result of given thread
		printf("main thread\n");
		for(int i = 0; i<10; i++){
           printf("%3d",arr[i]);
		  
		}

   printf("\n");
	return 0;
}

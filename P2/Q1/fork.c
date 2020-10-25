/*  
 *  forks two times and printks pids
 */


#include <stdio.h>
#include <unistd.h>


int main(void) {

    sleep(1);

    int child = fork();
    while (child == -1) {
        child = fork();
    }
    if (child > 0) {
	printf("first pid: %d\n", getpid());
	wait(child);
	return 0;
    }
 
    int grand_child = fork();
    while (grand_child == -1) {
        grand_child = fork();
    }
    if (grand_child > 0) {
        printf("second pid: %d\n", getpid());
	wait(grand_child);
	return 0;
    }

    printf("third pid: %d\n", getpid());
    return 0;
}

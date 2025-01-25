#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <errno.h>

int main() {
        printf("Testing custom create_process syscall\n");
        for (int i = 0; i < 2; i++) {
                printf("Invoking system call, iteration #%d\n", i + 1);
                long result = syscall(337);

                if (result == 0) printf("Syscall executed successfully on iter %d\n", i + 1);
                else printf("Syscall failed with error: %ld (%s)\n", result, strerror(errno));
        }
        return 0;
}


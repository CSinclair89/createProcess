# Linux implementation of createProcess() system call
This was a final project where we were free to choose any OS-related undertaking -- being unfamiliar with Linux, I chose to implement a basic system call in the kernel. 
The full paper on the challenges throughout the project can be found here: https://chrisso.tv/pdf/createProcess.pdf

In short, a paper published in 2019, titled "A fork() in the road", suggests deprecating the fork() system call and either teaching around it, using alternatives, or implementing
a modern Windows function that combines both fork() and its common counterpart, exec(). I took a stab at a very basic implementation of this and was able to print the output
to the kernel log. Other additions not included in this repository are the updated system call table as well as the syscalls.h header file. Also worth mentioning that on my local machine,
this code is not a separate createProcess.c file, but rather sits comfortably inside the code of /kernel/fork.c.

Remaining items that I may implement down the line:
1. [ ] Update unistd.c/h on my local machine so I can simply call 'createProcess();' in the code to execute the system call.
2. [ ] Add an input argument for the program to be executed (would need to be within struct size constraints, e.g. a string).

It was a fun project that pushed me further into the direction of kernel development as well as the mechanics of the C programming language. Most of my more recent OS-related work
can be found in my PiOS repository: https://github.com/CSinclair89/PiOS

Enjoy! -Chris

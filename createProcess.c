#define MAX_PROCESSES 128
#define MAX_MEM_SIZE 100

struct Process {
        int pid;
        char mem[MAX_MEM_SIZE];
};

static struct Process processTable[MAX_PROCESSES];
static struct Process *curr = NULL;
static int cms_processCount = 0;

SYSCALL_DEFINE0(create_process) {
        printk(KERN_INFO "Syscall entered, current processCount: %d\n", cms_processCount);

        if (cms_processCount >= MAX_PROCESSES) {
                printk(KERN_ERR "Process limit reached.\n");
                return -1;
        }

        struct Process *child = &processTable[cms_processCount];
        child->pid = cms_processCount;
        printk(KERN_INFO "Hello from PID %d\n", child->pid);

        const char *newProgram = "New Program Executed";
        size_t len = strlen(newProgram);

        if (curr) printk(KERN_INFO "Hello from PID: %d\n", curr->pid);

        if (len < MAX_MEM_SIZE) {
                strncpy(child->mem, newProgram, MAX_MEM_SIZE - 1);
                child->mem[MAX_MEM_SIZE - 1] = '\0';
        }
        curr = child;
        cms_processCount++;

        if (cms_processCount == 2) printk(KERN_INFO "Final process (PID %d): %s\n", curr->pid, curr->mem);
        return 0;
}


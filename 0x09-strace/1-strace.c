#include "strace.h"
#include "syscalls.h"

void trace_sysname(pid_t pid)
{
	int wstatus;
	long sysnum;

	setbuf(stdout, NULL);
	waitpid(pid, &wstatus, 0);
	ptrace(PTRACE_SETOPTIONS, pid, 0, PTRACE_O_TRACESYSGOOD);
	while (1)
	{
		if (!step_syscall(pid))
			break;
		sysnum = ptrace(PTRACE_PEEKUSER, pid, sizeof(long) * ORIG_RAX);
		printf("%s", syscalls_64_g[sysnum].name);
		if (!step_syscall(pid))
			break;
		putchar('\n');
	}
	putchar('\n');
}

int main(int argc, char *argv[])
{
	pid_t pid;

	if (parse_args(argc, argv))
		return (1);
	pid = fork();
	if (!pid)
		return (attach(argv + 1) == -1);
	trace_sysname(pid);
	return (0);
}

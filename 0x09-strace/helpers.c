#include "strace.h"

int step_syscall(pid_t pid)
{
	int wstatus;

	while (1)
	{
		ptrace(PTRACE_SYSCALL, pid, NULL, NULL);
		waitpid(pid, &wstatus, 0);
		if (WIFSTOPPED(wstatus) && WSTOPSIG(wstatus) & 0x80)
			return (1);
		if (WIFEXITED(wstatus))
			return (0);
	}
}

int attach(char *args[])
{
	if (ptrace(PTRACE_TRACEME) == -1)
		return (-1);
	kill(getpid(), SIGSTOP);
	return (execvp(*args, args));
}

int parse_args(int argc, char *argv[])
{
	struct stat sb;

	if (argc < 2)
	{
		fprintf(stderr, "%s command [args...]\n", *argv);
		return (1);
	}
	if (stat(argv[1], &sb) == -1)
	{
		fprintf(stderr, "%s: Can't stat '%s': No such file or directory\n",
						*argv, argv[1]);
	}
	return (0);
}

#include "env.h"
#include "strings.h"
#include "operators.h"
#include "hsh.h"
/**
 * _pipe - function enviroment
 * desc: print the enviroment
 * @argc: the parameters
 * @argv: the parameters
 * @lenv: the enviroment list
 * @execnt: the counter
 * Return: 1 in success.
 */
int _pipe(int argc, char **argv, lenv_s **lenv, unsigned int *execnt)
{
	pid_t pid;
	int j;
	int fd[2];
	char **command_one, **command_two;

	command_one = malloc((3) * sizeof(char **));
	command_two = malloc((3) * sizeof(char **));
	command_one[0] = argv[0];
	command_two[0] = argv[0];
	command_one[1] = argv[1];
	command_two[1] = argv[3];
	pipe(fd);
	pid = fork();

	if (pid == 0)
	{
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[READ_END]), close(fd[WRITE_END]);
		myexec(1, command_one, lenv, execnt);
		exit(1);
	}
	else
	{
		pid = fork();

		if (pid == 0)
		{
			dup2(fd[READ_END], STDIN_FILENO);
			close(fd[WRITE_END]), close(fd[READ_END]);
			myexec(1, command_two, lenv, execnt), exit(1);
		}
		else
		{
			int status;

			close(fd[READ_END]), close(fd[WRITE_END]);
			waitpid(pid, &status, 0);
		}
	}
}

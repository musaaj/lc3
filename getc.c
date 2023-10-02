#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <termios.h>
#include "lc3.h"

struct termios original_mode;


void die(char *s)
{
	write(STDIN_FILENO, "\x1b[2J", 4);
	write(STDIN_FILENO, "\x1b[H", 3);
	perror(s);
	exit(EXIT_FAILURE);
}

void enable_row_mode(void)
{
	if (tcgetattr(STDIN_FILENO, &original_mode) == -1) die("host exception!");

	struct termios mode = original_mode;
	mode.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
	mode.c_oflag &= ~(OPOST);
	mode.c_cflag |= (CS8);
	mode.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
	mode.c_cc[VMIN] = 0;
	mode.c_cc[VTIME] = 1;
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &mode) == -1) die("io exception!");
}

void disable_raw_mode(void)
{
	if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_mode) == -1) die("io exception");
}

uint16_t _getc(void)
{
	int c, n;
	write(STDIN_FILENO, ">> ", 3);
	enable_row_mode();
	while ((n = read(STDIN_FILENO, &c, 1)) != 1)
	{
		if (n == -1 && errno != EAGAIN) die("io exception");
	}
	disable_raw_mode();
	return (uint16_t) c;
}

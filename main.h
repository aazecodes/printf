#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define FLAG_MINUS 1
#define FLAG_PLUS 2
#define FLAG_ZERO 4
#define FLAG_HASH 8
#define FLAG_SPACE 16

#define SIZE_LONG 2
#define SIZE_SHORT 1

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int run_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);


int fetch_flags(const char *f, int *i);
int fetch_width(const char *f, int *i, va_list list);
int fetch_precision(const char *f, int *i, va_list list);
int fetch_size(const char *f, int *i);

void handle_buffers(char buffer[], int *buff_ind);

#endif /* MAIN_H */

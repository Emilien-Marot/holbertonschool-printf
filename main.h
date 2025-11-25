#include <stdarg.h>
#ifndef MYHEADER_H
#define MYHEADER_H

int _print_var(char t, int m, va_list *args, char *buf, int *len_buf);
int _printf(const char *format, ...);
int print_str(char t, char *str, char *buf, int *len_buf);
int print_char(char t, char c, char *buf, int *len_buf);
int print_buf(char *buf, int *len_buf);
int add_buf(char c, char *buf, int *len_buf);
int _print_p(unsigned long int num, char *buf, int *len_buf);
int _print_base(unsigned long int num, char t, char *buf, int *len_buf);
int _print_i(long int num, char *buf, int *len_buf);
int _print_s(char *str, char *buf, int *len_buf);
int _print_s2(char *str, char *buf, int *len_buf);
int _print_r(char *str, int i, char *buf, int *len_buf);
int _print_r2(char *str, char *buf, int *len_buf);

#endif

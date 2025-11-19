#ifndef MYHEADER_H
#define MYHEADER_H

int _printf(const char *format, ...);
void add_buf(char c, char *buf, int *len_buf);
void print_buf(char *buf, int *len_buf);
int _print_s(char *str, char *buf, int *len_buf);
int _print_i(int num, char *buf, int *len_buf);
int _print_p(long unsigned int num, char *buf, int *len_buf);
int _print_x(unsigned int num, char t, char *buf, int *len_buf);
int _print_o(unsigned int num, char *buf, int *len_buf);
int _print_u(unsigned int num, char *buf, int *len_buf);
int _print_b(unsigned int num, char *buf, int *len_buf);

#endif

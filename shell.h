#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <uinstd.h>
#include <strin.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>


/* commands for read/write */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1


/* command to convert numbers */
#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2

/* COMMANDS FOR CHAINING NUMS */
#define CMD_NORM 0
#define CMD_OR 1
#define CMD_AND 2
#define CMD_CHAIN 3

/* COMMANDS FOR GETLINE */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE "simple_shell_history"
#define HIST_MAX 4096

extern char **environ;

/* commands for typedef functions */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;


typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argv;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;


	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} info_t;


#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \ 0, 0, 0,}


typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

/* COMMANDS */
int hsh(info_t *, char **);
int find_builtin(info_t *);
void find_cmd(info_t *);
void fork_cmd(info_t *);


/* COMMANDS */
void eputs(char *);
int _eputchar(char);
iny _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* COMMANDS */
int is_cmd(info_t *, char *);
char *dup_chars(char *, int, int);
char *find_path(info_t *, char *, char *);

/* COMMANDS */
int loophsh(char **);

/* COMMANDS */
int _strlen(char *);
int _strcmp(char *, char *);
char *starts_with(const char *, const char *);
char *_strcat(char *, char *);

/* COMMANDS */
char *strcpy(char *, char *);
char *strdup(const char *);
void _puts(char *);
int _putchar(char);

/* COMMANDS */
char *strncpy(char *, char *, int);
char *strncat(char *, char *, int);
char *strchr(char *, char);

/* COMMANDS */
char **strtow(char *, char *);
char **strtow2(char *, char);

/* COMMANDS */
char *_memset(char *, char, unsigned int);
void ffree(char **);
void *_realloc(void *, unsigned int, unsigned int);

/* COMMANDS */
int bfree(void **);

/* COMMANDS */
int interactive(info_t *);
int is_delim(char, char *);
int isalpha(int);
int _atoi(char *);

/* COMMANDS */
int _erratoi(char *);
void print_error(info_t *, char *);
int print_d(int, int);
char *convert_number(long int, int, int);
void remove_comments(char *);

/* COMMANDS */
int _myexit(info_t *);
int _mycd(info_t);
int _myhelp(info_t *);

/* COMMANDS */
int _myhistory(info_t *);
int _myalias(info_t *);

/* COMMANDS */
ssize_t get_input(info_t *);
int _getline(info_t *, char **, size_t *);
void sigintHandler(int);

/* COMMANDS */
void clear_info(info_t *);
void set_info(info_t *, char **);
void free_info(info_t *, int);

/* COMMANDS */
char *getenv(info_t *, const char *);
int _myenv(info_t *);
int _mysetenv(info_t *);
int _myunsetenv(info_t *);
int populate_env_list(info_t *);

/* COMMANDS */
char *get_history_file(info_t *info);
int write_history(info_t *info);
int read_history(info_t *info);
int build_history_list(info_t *info, char *buf, int linecount);
int renumber_history(info_t *info);

/* COMMANDS */
list_t *add_node(list_t **, const char *, int);
list_t *add_node_end(list_t **, const char *, int);
size_t print_list_str(const list_t *);
int delete_node_at_index(list_t **, unsigned int);
void free_list(list_t **);

/* COMMANDS */
size_t list_len(const list_t *);
char **list_to_strings(list_t *);
size_t *node_starts_with(list_t *, char *, char);
ssize_t get_node_index(list_t *, list_t *);

/* COMMANDS */
int is_chain(info_t *, char *, size_t *);
void check_chain(info_t *, char *, size_t, size_t);
int replace_alias(info_t *);
int replace_vars(info_t *);
int replace_string(char **, char *);


#endif

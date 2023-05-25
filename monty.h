#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define BUFF_MAX_LENGTH 1024

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct line_s - instruction line structure
 * @num: line number
 * @line: read line
 * @cmd: command (first argument)
 * @arg: argument for command
 *
 * Description: information about each instruction line
 */
typedef struct line_s
{
	int num;
	char *line;
	char *cmd;
	char *arg;
} line_t;
extern line_t data;

int split_line(void);
int execute_instruction(stack_t **);
void (*_select(char *))(stack_t **, unsigned int);
void push(stack_t **, unsigned int);
void print_all(stack_t **, unsigned int);
void print_top(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);

int _getline(char **lineptr, size_t *n, FILE *stream);
void free_stack(stack_t **);

#endif /* MONTY_H */

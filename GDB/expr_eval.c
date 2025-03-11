#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum
{
	/*
	 * Put in the precedence order. All are assumed to be of different
	 * precedence, and left associative among itself
	 */
	e_op_pow,
	e_op_div,
	e_op_mul,
	e_op_add,
	e_op_sub,
	e_op_max
} Operators;

typedef enum
{
	e_operand,
	e_operator
} NodeType;

typedef struct _Node
{
	NodeType type;
	union
	{
		float val;
		char op;
	};
	struct _Node *next;
} Node;

typedef float (*ComputeFn)(float, float);

float divf(float a, float b)
{
	return a / b;
}

float mulf(float a, float b)
{
	return a * b;
}

float addf(float a, float b)
{
	return a + b;
}

float subf(float a, float b)
{
	return a - b;
}

static const char op_sym[e_op_max] = {'^', '/', '*', '+', '-'};
static const ComputeFn compute_oper[e_op_max] = {powf, divf, mulf, addf, subf};

void init_expr(Node *l)
/* Setting up the head node */
{
	l->type = e_operator; /* as the first thing needs to be operand */
	l->next = NULL;
}

int isoper(int c)
{
	int i;

	for (i = 0; i < e_op_max; i++)
	{
		if (c == op_sym[i])
		{
			return 1;
		}
	}
	return 0;
}

int add_operand(char *c, Node **mover)
{
	if ((*mover = (Node *)(malloc(sizeof(Node)))) == NULL)
	{
		return -1;
	}
	(*mover)->type = e_operand;
	(*mover)->val = (float)(atoi(c));
	(*mover)->next = NULL;

	return 0;
}

int add_operator(char c, Node **mover)
{
	if ((*mover = (Node *)(malloc(sizeof(Node)))) == NULL)
	{
		return -1;
	}
	(*mover)->type = e_operator;
	(*mover)->op = c;
	(*mover)->next = NULL;

	return 0;
}

int read_expr(Node *l)
{
	NodeType prev_type;
	Node **moverp;
	int i;
	char c[16], ct;

	prev_type = l->type;
	moverp = &l->next;
	i = 0;
	while ((c[i] = getchar()) != '\n')
	{
		if (isdigit(c[i]))
		{
			/* Receiving operand */
			if (prev_type == e_operand)
			{
				return -1;
			}
			else
			{
				i++;
				continue;
			}
		}
		else if (isblank(c[i]))
		{
			if (i == 0)
			{
				continue;
			}
			c[i] = 0;
			if (add_operand(c, moverp) == -1)
			{
				return -1;
			}
			else
			{
				prev_type = (*moverp)->type;
				moverp = &(*moverp)->next;
			}
			i = 0;
		}
		else if (isoper(c[i]))
		{
			if (i == 0)
			{
				/* Received an operator */
				if (prev_type == e_operator)
				{
					return -1;
				}
				else
				{
					if (add_operator(c[i], moverp) == -1)
					{
						return -1;
					}
					else
					{
						prev_type = (*moverp)->type;
						moverp = &(*moverp)->next;
					}
					continue;
				}
			}
			else
			{
				ct = c[i];
				c[i] = 0;
				/* Received an operand */
				if (prev_type == e_operand)
				{
					return -1;
				}
				/* else proceed further */
				if (add_operand(c, moverp) == -1)
				{
					return -1;
				}
				else
				{
					prev_type = (*moverp)->type;
					moverp = &(*moverp)->next;
				}
				if (add_operator(ct, moverp) == -1)
				{
					return -1;
				}
				else
				{
					prev_type = (*moverp)->type;
					moverp = &(*moverp)->next;
				}
				i = 0;
			}
		}
		else /* Invalid input */
		{
			return -1;
		}
	}
	if (prev_type == e_operator)
	/* Last item is an operator */
	{
		return -1;
	}
	return 0;
}

void compute_expr(Node *l)
{
	int i;
	Node *mover, *tmp;

	for (i = 0; i < e_op_max; i++)
	{
		mover = l->next; /* Is definitely non-NULL */
		while (mover->next)
		{
			if ((mover->next->type == e_operator) &&
				(mover->next->op == op_sym[i]))
			{
				mover->val = compute_oper[i](mover->val, mover->next->next->val);
				tmp = mover->next;
				mover->next = tmp->next->next;
				free(tmp->next);
				free(tmp);
			}
			else
			{
				mover = mover->next;
			}
		}
	}
}

void print_expr(Node *l)
{
	printf("Expression Result is %f.\n", l->next->val);
}

void cleanup_expr(Node *l)
{
	if (l->next)
	{
		if (l->next->next)
		{
			cleanup_expr(l->next);
		}
		else
		{
			free(l->next);
		}
	}
}

int main(void)
{
	Node expr; /* Head Node */

	init_expr(&expr);
	printf("Enter your arithmetic expression using ^/*+-:\n");
	if (read_expr(&expr) == -1)
	{
		printf("Expression evaluation failed\n");
		cleanup_expr(&expr);
		return 1;
	}
	compute_expr(&expr);
	print_expr(&expr);
	cleanup_expr(&expr);

	return 0;
}

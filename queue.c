// PingPongOS - PingPong Operating System
// Matheus Henrique Jandre Ferraz - Bacharelado Ciência da Computação
// GRR: 20215397

#include "queue.h"

int queue_size(queue_t *queue)
{
	return 0;
}

void queue_print(char *name, queue_t *queue, void print_elem(void *))
{
	printf("Hello world.");
}

int queue_append(queue_t **queue, queue_t *elem)
{
	if (!queue)
		perror("A fila não existe.");

	if (!elem)
		perror("O elemento não existe.");

	if (elem->next != NULL || elem->prev != NULL)
		perror("O elemento está em outra fila.");

	queue_t *aux;

	aux = *queue;

	return 0;
}

int queue_remove(queue_t **queue, queue_t *elem)
{
	return 0;
}

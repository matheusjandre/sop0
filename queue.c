// PingPongOS - PingPong Operating System
// Matheus Henrique Jandre Ferraz - Bacharelado Ciência da Computação
// GRR: 20215397

#include <stdio.h>
#include "queue.h"

int queue_size(queue_t *queue)
{
	queue_t *aux = queue;
	int c = 0;

	if (!queue)
		return 0;

	do
	{
		c++;
		aux = aux->next;
	} while (aux != queue);

	return c;
}

void queue_print(char *name, queue_t *queue, void print_elem(void *))
{
	printf("Hello world.");
}

int queue_append(queue_t **queue, queue_t *elem)
{
	queue_t *aux;

	if (!queue)
	{
		perror("A fila não existe.");
		return -1;
	}

	if (!elem)
	{
		perror("O elemento não existe.");
		return -1;
	}

	if (elem->next != NULL || elem->prev != NULL)
	{
		perror("O elemento está em outra fila.");
		return -1;
	}

	if (!(*queue)) // Se fila vazia, adiciona o elemento e aponta para si
	{
		*queue = elem;
		elem->next = elem;
		elem->prev = elem;
		return 0;
	}

	aux = (*queue)->prev;	 // Ultimo elemento
	aux->next = elem;			 // Ultimo elemento -> novo elemento
	elem->prev = aux;			 // Ultimo elemento <- novo elemento
	elem->next = *queue;	 // Novo elemento -> cabeça
	(*queue)->prev = elem; // Novo elemento <- cabeça.

	return 0;
}

//------------------------------------------------------------------------------
// Remove o elemento indicado da fila, sem o destruir.
// Condicoes a verificar, gerando msgs de erro:
// - a fila deve existir
// - a fila nao deve estar vazia
// - o elemento deve existir
// - o elemento deve pertencer a fila indicada
// Retorno: 0 se sucesso, <0 se ocorreu algum erro
int queue_remove(queue_t **queue, queue_t *elem)
{
	queue_t *aux;

	if (!queue)
	{
		perror("A fila não existe.");
		return -1;
	}

	if (!(*queue))
	{
		perror("A fila está vazia.");
		return -1;
	}

	if (!elem)
	{
		perror("O elemento não existe.");
		return -1;
	}

	aux = *queue;

	do
	{
		if (aux == elem) // Elemento encontrado
		{
			if (aux == *queue) // Se for o primeiro elemento
			{
				if (aux->next == *queue) // Se for o único elemento
				{
					aux->next = NULL; // Fila vazia
					aux->prev = NULL; // Fila vazia
					*queue = NULL;		// Fila vazia
					return 0;					// Elemento removido
				}
				else
				{
					*queue = aux->next; // Cabeça aponta para o próximo
				}
			}
			aux->prev->next = aux->next; // Elemento anterior -> próximo
			aux->next->prev = aux->prev; // Elemento próximo <- anterior
			aux->next = NULL;						 // Elemento não aponta para nada
			aux->prev = NULL;						 // Elemento não aponta para nada
			return 0;										 // Elemento removido
		}

		aux = aux->next; // Elemento não encontrado. Próximo elemento

	} while (aux != *queue); // Se voltar para a cabeça, termina a busca

	perror("O elemento não pertence a fila.");
	return -1;
}

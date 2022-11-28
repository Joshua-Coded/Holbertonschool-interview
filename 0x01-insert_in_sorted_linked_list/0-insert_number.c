#include "lists.h"


listint_t *insert_node(listint_t **head, int number)
{
    listint_t* new_node = NULL;
    listint_t* focus_node = NULL;

    /* If pointer to head is null, return NULL */
    if (head == NULL)
    {
        return (NULL);
    }

    /* Allocate memory for new node and initialize values*/
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
    {
        return (NULL);
    }
    new_node->n = number;
    new_node->next = NULL;

    /* If list is empty, initialize with new node */
    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    /* If new node n is less than starting node n */
    if (new_node->n < (*head)->n)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node);
    }

    /* Traverse list to find proper insertion place */
    focus_node = *head;
    while (focus_node->next != NULL)
    {
        /* If number is less than next number in list, insert between current and next */
        if (new_node->n <= focus_node->next->n)
        {
            new_node->next = focus_node->next;
            focus_node->next = new_node;
            return (new_node);
        }
        /* Otherwise move forward */
        focus_node = focus_node->next;
    }

    /* If new node's value is greater than any in list, insert at end of list */
    focus_node->next = new_node;
    return (new_node);
}
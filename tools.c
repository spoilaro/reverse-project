#include "tools.h"
#include <stdio.h>
#include <stdlib.h>

Node *read_file(char *filename)
{
    // https://stackoverflow.com/questions/3501338/c-read-file-line-by-line

    FILE *fp;
    char line[256];

    Node *head = NULL;
    Node *current = NULL;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Could not read the file");
        exit(1);
    }

    while (fgets(line, sizeof(line), fp))
    {
        Node *new = (Node *)malloc(sizeof(Node));
        new->line = strdup(line);
        new->next = NULL;

        if (head == NULL)
        {
            current = head = new;
        }
        else
        {
            current = current->next = new;
        }
    }

    fclose(fp);

    for (current = head; current; current = current->next)
    {
        printf("%s", current->line);
    }

    // print_nodes(head);
}

Node *new_node(char *line)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        perror("Could not allocate memory for node");
    }

    node->line = line;
    node->next = NULL;

    return node;
}

Node *add_node(Node *head, char *line)
{
    Node *new = new_node(line);

    if (head != NULL)
    {

        printf("Head is %s", head->line);
    }
    printf("Next is %s", new->line);
    new->next = head;

    return new;
}

void print_nodes(Node *head)
{
    while (head != NULL)
    {
        printf("%s", head->line);
        head = head->next;
    }
}

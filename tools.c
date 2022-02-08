#include "tools.h"
#include <stdio.h>
#include <stdlib.h>

void read_file(char *filename, Node *head){
    // https://stackoverflow.com/questions/3501338/c-read-file-line-by-line

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    size_t read;

    char test_line[5] = "test";

    fp = fopen(filename, "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    while ((read = getline(&line, &len, fp)) != -1) {
        // TODO add to linked list
        head = add_node(head, test_line);
    }

    fclose(fp);
    if (line)
        free(line);
    exit(EXIT_SUCCESS);
}

Node *add_node(Node *head, char *line){
    Node *new = (Node*)malloc(sizeof(Node));
    // TODO Check memory reservation

    new->line = line;
    new->next = NULL;

    printf("%s \n", new->line);

    if (head == NULL){
        head = new;
    }

    while (head != NULL){
        head = head->next;
    }

    head->next = new;

    return head;
}

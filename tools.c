#include "tools.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Node *read_file(char *filename, Node *head) {
    // https://stackoverflow.com/questions/3501338/c-read-file-line-by-line

    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    size_t read;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", filename);
        exit(1);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        head = add_node(head, line);
    }

    fclose(fp);

    return head;
}

Node *new_node(char *line) {
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "malloc failed");
        exit(1);
    }

    node->line = strdup(line);
    node->next = NULL;

    return node;
}

Node *add_node(Node *head, char *line) {
    Node *new = new_node(line);
    new->next = head;
    return new;
}

void print_nodes(Node *head, bool new_lines)

{
    while (head != NULL) {
        printf("%s", head->line);

        // Adds new lines if lines were read from stdinput
        if (new_lines) {
            printf("\n");
        }

        head = head->next;
    }
}

Node *dynamic_input(char *line, Node *head) {
    // https://mkyong.com/c/how-to-handle-unknow-size-user-input-in-c/
    int len_max = 128;
    int current_size = 0;

    line = malloc(len_max);
    current_size = len_max;

    printf("Enter a line: ");
    if (line != NULL) {
        int c = EOF;
        int i = 0;
        while ((c = getchar()) != '\n' && c != EOF) {
            line[i++] = (char)c;

            if (i == current_size) {
                current_size = i + len_max;
                line = realloc(line, current_size);
            }
        }
        line[i] = '\0';

        head = add_node(head, line);
    }

    return head;
}

void write_file(char *filename, Node *head) {
    FILE *fp = fopen(filename, "wr");

    if (fp == NULL) {
        fprintf(stderr, "error: cannot open file '%s'\n", filename);
        exit(1);
    }

    while (head != NULL) {
        fprintf(fp, "%s", head->line);
        head = head->next;
    }
}

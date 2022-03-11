#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"

int main(int argc, char **argv) {
    Node *head = NULL;
    char *line;

    switch (argc) {
        case 1:
            // Case where no file names were provided
            printf("Enter lines, entering 0 will print reversed lines: \n");

            // Asks lines until "0" is given after which the loop is broken
            int run = 1;
            while (run) {
                head = dynamic_input(line, head);
                int cmp_res = strcmp("0", head->line);
                if (cmp_res == 0) {
                    break;
                }
            }
            print_nodes(head, true);

            break;
        case 2:
            // Case where only input file was provided
            head = read_file(argv[1], head);
            print_nodes(head, false);
            break;
        case 3:
            head = read_file(argv[1], head);
            write_file(argv[2], head);
            break;
        default:
            fprintf(stderr, "usage: reverse <input> <output>\n");
            exit(1);
            break;
    }

    // TODO: Free nodes

    return 0;
}
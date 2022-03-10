#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

int main(int argc, char **argv)
{

    Node *head = NULL;

    head = read_file("input.txt", head);
    print_nodes(head);

    return 0;
}

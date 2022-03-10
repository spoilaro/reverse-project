

typedef struct Node
{

    char *line;
    struct Node *next;
} Node;

Node *read_file(char *filename, Node *head);
Node *add_node(Node *head, char line[255]);
Node *new_node(char *line);
void print_nodes(Node *head);

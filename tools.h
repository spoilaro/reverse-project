

typedef struct Node{

    char *line;
    struct Node *next;
} Node;

void read_file(char *filename, Node *head);
Node *add_node(Node *head, char line[255]);

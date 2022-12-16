struct Node {
    struct Node *next;
    int x;
};

struct Node * push_front(struct Node * head, int x) {
    struct Node * new_head = malloc(sizeof(*head));
    new_head->next = *head;
    new_head->x = x;
    return new_head;
}

int main() {
    struct Node * root = NULL;
    int a;
    int b;

    root = push_front(root, 1);

}

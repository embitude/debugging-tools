//Makes a linked list of length 7 and prints it out
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data);
struct node *create_list(int length);
void print_list(struct node *list);

int main(void){
    struct node *list1 = create_list(7);
    print_list(list1);

    return 0;
}

struct node *create_node(int data){
    struct node *new = malloc(sizeof(struct node));
    assert(new != NULL);
    new->data = data;
    new->next = NULL;
    return new;
}

struct node *create_list(int length) {

    struct node *head = NULL;
    if (length > 0) {
        head = create_node(0);
        int i = 1;
        struct node *curr = head;
        while (i < length) {
            curr->next = create_node(i);
            curr = curr->next;
            i++;
        }
    }
    return head;
}

void print_list(struct node *list){
    struct node *curr = list;

    while (curr != NULL) {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}
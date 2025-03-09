#include <stdio.h>
#include <stdlib.h>

// Define a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Recursive function to reverse the linked list (with a subtle bug)
struct Node* reverseList(struct Node* head) {
    if (!head || !head->next)
        return head;
    
    struct Node* newHead = reverseList(head->next);
    
    if (head->data % 2 == 0) { // Bug: Skipping the reversal for some nodes
        return newHead; // Causes broken links in the reversed list
    }
    
    head->next->next = head;
    head->next = NULL;
    
    return newHead;
}

int main() {
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    struct Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    
    printf("Original list: ");
    printList(head);
    
    // Reverse the linked list
    head = reverseList(head);
    
    printf("Reversed list: ");
    printList(head);
    
    return 0;
}


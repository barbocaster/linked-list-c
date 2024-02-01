#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct LinkedList {
    int length;
    struct Node *head;
};

struct LinkedList *init_linked_list() {
    struct LinkedList *ll = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    ll->head = NULL;
    ll->length = 0;
    return ll;
}

const char* enqueue(int data, struct LinkedList *ll) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    
    node->data = data;
    node->next = NULL;

    if(ll->head == NULL) {
        ll->head = node;   
        ll->length += 1;
        return "No Head Found, Inserted at Head";
    }
 
    struct Node* current = ll->head;

    while(current->next != NULL) {
        current = current->next;
    }
    
    ll->length += 1;

    current->next = node;
    return "Inserted";
}

const char* dequeue(struct LinkedList *ll) {

    if(ll->head == NULL) {
        return "Nothing to Remove";
    }

    ll->length -= 1;
    ll->head = ll->head->next;
    return "Removed";
}

int print_list(struct LinkedList *ll) {
    struct Node* current = ll->head;
    
    if(ll->head == NULL) {
        printf("No Head, Insert First");
        return -1;
    }

    printf("Length: %i \n \n", ll->length);
    printf("%i -> ", current->data);

    while(current->next != NULL) {
        current = current->next;
        printf("%i -> ", current->data);
    }
    
    printf("NULL \n");
    return 0;
}

int main() {
    int end = 0;
    int option = 0;
    int insertion = 0;
    char any[1024];
    struct LinkedList *ll = init_linked_list();
 
    while(end != 1) {
        printf("1 - Enqueue | 2 - Dequeue | 3 - Print List \n \n");
        
        printf("Option: ");
        scanf("%i", &option);
        printf("\n");

        switch(option) {
            case 1:
                system("clear");
                printf("Insert Data: "); 
                scanf("%i", &insertion);
                printf("%s", enqueue(insertion, ll));
                break;
            case 2:
                dequeue(ll);
                break;
            case 3:
                system("clear");
                print_list(ll);
                printf("\nDigit any key to Exit ");
                scanf("%s", any);
                break;
        }

        printf("\n \n");
        system("clear");
    }

    return 0;
}

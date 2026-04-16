#ifndef BORROW_MANAGER_H
#define BORROW_MANAGER_H
#include "Library.h"

typedef struct Node {
    char entry[100];
    struct Node* next;
} Node;

typedef struct BorrowManager {
    Node *front, *rear;
} BorrowManager;

BorrowManager* createBorrowManager();
void borrowBook(BorrowManager* bm, Library* lib, char* isbn, char* user);
void getBorrowHistory(BorrowManager* bm);

// Implementation for Person 3
BorrowManager* createBorrowManager() {
    BorrowManager* bm = (BorrowManager*)malloc(sizeof(BorrowManager));
    bm->front = bm->rear = NULL;
    return bm;
}

void borrowBook(BorrowManager* bm, Library* lib, char* isbn, char* user) {
    Book* b = searchByISBN(lib, isbn);
    if (b && isAvailable(b)) {
        setAvailability(b, 0); // Mark as borrowed [cite: 15]
        
        // Enqueue to history [cite: 22]
        Node* newNode = (Node*)malloc(sizeof(Node));
        sprintf(newNode->entry, "User [%s] borrowed [%s]", user, getTitle(b));
        newNode->next = NULL;
        
        if (bm->rear == NULL) {
            bm->front = bm->rear = newNode;
        } else {
            bm->rear->next = newNode;
            bm->rear = newNode;
        }
        printf("Success: Book borrowed by %s\n", user);
    } else {
        printf("Error: Book is already borrowed or does not exist.\n");
    }
}

void getBorrowHistory(BorrowManager* bm) {
    Node* temp = bm->front;
    printf("\n--- BORROW HISTORY (QUEUE) ---\n");
    while (temp != NULL) {
        printf("%s\n", temp->entry);
        temp = temp->next;
    }
}
#endif

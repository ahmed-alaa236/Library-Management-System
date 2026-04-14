#include <stdio.h>
#include <stdlib.h>
#include "Book.h"
#include "Library.h"
#include "BorrowManager.h"

int main() {
    Library* lib = createLibrary();

    int choice;
    int id;
    char title[100];

    while (1) {
        printf("\n===== Library System =====\n");
        printf("1. Add Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book\n");
        printf("4. Display All Books\n");
        printf("5. Borrow Book\n");
        printf("6. Return Book\n");
        printf("7. Sort Books\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID and Title: ");
                scanf("%d %s", &id, title);
                addBook(lib, id, title);
                break;

            case 2:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                removeBook(lib, id);
                break;

            case 3:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                if (searchBook(lib, id))
                    printf("Book Found\n");
                else
                    printf("Book Not Found\n");
                break;

            case 4:
                displayAll(lib);
                break;

            case 5:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                borrowBook(lib, id);
                break;

            case 6:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                returnBook(lib, id);
                break;

            case 7:
                sortBooks(lib);
                break;

            case 0:
                freeLibrary(lib);
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
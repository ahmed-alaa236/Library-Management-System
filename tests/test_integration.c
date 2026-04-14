#include <assert.h>
#include <stdio.h>
#include "Library.h"
#include "BorrowManager.h"

int main() {
    Library* lib = createLibrary();

    // Add Book
    addBook(lib, 1, "C");
    assert(searchBook(lib, 1) != NULL);

    // Borrow Book
    borrowBook(lib, 1);
    Book* b = searchBook(lib, 1);
    assert(b != NULL && b->isBorrowed == 1);

    // Return Book
    returnBook(lib, 1);
    assert(b->isBorrowed == 0);

    // Remove Book
    removeBook(lib, 1);
    assert(searchBook(lib, 1) == NULL);

    freeLibrary(lib);

    printf("Integration Test Passed ✅\n");
    return 0;
}
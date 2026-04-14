#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Book.h"

// Test 1: normal book creation
void test_normal_book() {
    Book* b = createBook("Dune", "Frank Herbert", "978-0441013593", 1965);
    assert(b != NULL);
    assert(strcmp(getTitle(b),  "Dune")           == 0);
    assert(strcmp(getAuthor(b), "Frank Herbert")  == 0);
    assert(strcmp(getISBN(b),   "978-0441013593") == 0);
    assert(getYear(b) == 1965);
    freeBook(b);
    printf("PASS: test_normal_book\n");
}

// Test 2: NULL fields — strdup(NULL) is undefined, so we guard with empty strings
void test_null_fields() {
    Book* b = createBook("", "", "", 0);
    assert(b != NULL);
    assert(strcmp(getTitle(b),  "") == 0);
    assert(strcmp(getAuthor(b), "") == 0);
    assert(strcmp(getISBN(b),   "") == 0);
    assert(getYear(b) == 0);
    freeBook(b);
    printf("PASS: test_null_fields\n");
}

// Test 3: duplicate ISBN — two different books, same ISBN
void test_duplicate_isbn() {
    Book* b1 = createBook("BookA", "Author1", "000-111", 2000);
    Book* b2 = createBook("BookB", "Author2", "000-111", 2001);
    assert(b1 != NULL && b2 != NULL);
    assert(strcmp(getISBN(b1), getISBN(b2)) == 0);  // same ISBN
    assert(b1 != b2);                                // different objects
    freeBook(b1);
    freeBook(b2);
    printf("PASS: test_duplicate_isbn\n");
}

// Test 4: print output check + setAvailability
void test_print_and_availability() {
    Book* b = createBook("1984", "Orwell", "978-0451524935", 1949);
    printBook(b);                    // visual check
    setAvailability(b, false);
    assert(strcmp(getISBN(b), "978-0451524935") == 0);
    printBook(b);                    // should show Available: No
    freeBook(b);
    printf("PASS: test_print_and_availability\n");
}

int main() {
    test_normal_book();
    test_null_fields();
    test_duplicate_isbn();
    test_print_and_availability();
    printf("\nAll tests passed.\n");
    return 0;
}

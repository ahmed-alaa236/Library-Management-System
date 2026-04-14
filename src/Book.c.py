#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Book.h"

// Struct definition hidden here — not in Book.h (opaque pointer pattern)
struct Book {
    char* title;
    char* author;
    char* ISBN;
    int   year;
    bool  isAvailable;
};

Book* createBook(const char* title, const char* author,
                 const char* ISBN, int year) {
    Book* b = malloc(sizeof(Book));
    if (!b) return NULL;

    b->title  = strdup(title);
    b->author = strdup(author);
    b->ISBN   = strdup(ISBN);
    b->year   = year;
    b->isAvailable = true;

    return b;
}

void freeBook(Book* b) {
    if (!b) return;
    free(b->title);
    free(b->author);
    free(b->ISBN);
    free(b);
}

const char* getTitle(const Book* b)  { return b ? b->title  : NULL; }
const char* getAuthor(const Book* b) { return b ? b->author : NULL; }
const char* getISBN(const Book* b)   { return b ? b->ISBN   : NULL; }
int         getYear(const Book* b)   { return b ? b->year   : -1;   }

void setAvailability(Book* b, bool available) {
    if (b) b->isAvailable = available;
}

void printBook(const Book* b) {
    if (!b) {
        printf("Book: NULL\n");
        return;
    }
    printf("Title:     %s\n", b->title);
    printf("Author:    %s\n", b->author);
    printf("ISBN:      %s\n", b->ISBN);
    printf("Year:      %d\n", b->year);
    printf("Available: %s\n", b->isAvailable ? "Yes" : "No");
}
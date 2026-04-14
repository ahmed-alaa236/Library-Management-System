#ifndef BOOK_H
#define BOOK_H

#include <stdbool.h>

typedef struct Book Book;

// Lifecycle
Book* createBook(const char* title, const char* author,
                 const char* ISBN, int year);
void  freeBook(Book* b);

// Getters
const char* getTitle(const Book* b);
const char* getAuthor(const Book* b);
const char* getISBN(const Book* b);
int         getYear(const Book* b);

// Setter
void setAvailability(Book* b, bool available);

// Display
void printBook(const Book* b);

#endif
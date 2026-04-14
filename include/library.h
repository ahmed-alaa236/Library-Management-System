#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

typedef struct {
    Book books[100];
    int count;
} Library;

Library* createLibrary();
void freeLibrary(Library *lib);

void addBook(Library *lib, int id, char title[]);
void removeBook(Library *lib, int id);
Book* searchBook(Library *lib, int id);

void displayAll(Library *lib);
void sortBooks(Library *lib);

#endif
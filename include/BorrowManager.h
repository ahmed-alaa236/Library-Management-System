#ifndef BORROW_MANAGER_H
#define BORROW_MANAGER_H

#include "Library.h"

void borrowBook(Library *lib, int id);
void returnBook(Library *lib, int id);

#endif
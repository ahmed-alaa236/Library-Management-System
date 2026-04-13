#  Library Management System

> A modular console-based system to manage book borrowing and returns, built using Abstract Data Types (ADTs) in C.

---

## 👥 Team Members

| # | Name | Role |
|---|------|------|
| 1 | **MAHMUT_EBURJELE** | Book ADT |
| 2 | **Person 2**         | Library ADT + Linked List |
| 3 | **AHMED_SULIMAN**     | BorrowManager ADT + Queue |
| 4 | **AHMED_ABDULLAH**      | Integration + Main + Docs |

---

##  Project Structure

```
LibrarySystem/
├── include/
│   ├── Book.h              # MAHMUT_EBURJELE
│   ├── Library.h           # Person 2
│   └── BorrowManager.h     # AHMED_SULIMAN
├── src/
│   ├── Book.c              # MAHMUT_EBURJELE
│   ├── Library.c           # Person 2
│   ├── BorrowManager.c     # AHMED_SULIMAN
│   └── main.c              # AHMED_ABDULLAH
├── tests/
│   ├── test_book.c         # MAHMUT_EBURJELE
│   ├── test_library.c      # Person 2
│   ├── test_borrow.c       # AHMED_SULIMAN
│   └── test_integration.c  # AHMED_ABDULLAH
├── docs/
│   └── report.pdf          # AHMED_ABDULLAH
├── README.md               # AHMED_ABDULLAH
└── Makefile                # AHMED_ABDULLAH
```


##  Big-O Analysis

| Operation | Module | Complexity | Reason |
|-----------|--------|------------|--------|
| `createBook / `freeBook` | Book ADT | `O(1)`         | Single allocation 
| `addBook` | Library ADT | `O(1)`                      | Insert at head of list 
| `removeBook` / `searchBook` | Library ADT | `O(n)`    | Traverse linked list 
| `sortBooks` (bubble) | Library ADT | `O(n²)`          | Nested comparisons 
| `sortBooks` (merge) | Library ADT | `O(n log n)`      | Divide and conquer 
| `borrowBook` / `returnBook` | BorrowManager | `O(1)`  | Queue enqueue/dequeue 
| `getBorrowHistory` | BorrowManager | `O(n)`           | Traverse full queue 

---



## Testing Checklist

- [x] Normal cases — add, search, borrow, return a valid book
- [x] Edge case — operations on empty library / empty queue
- [x] Invalid input — NULL pointers, invalid ISBN
- [x] Duplicate records — adding same ISBN twice
- [x] Integration test — full end-to-end scenario

---

## 📝 Data Structure Justification

- **Linked List** was chosen for the Library because books are frequently added and removed, and a linked list provides `O(1)` insertion without reallocation overhead.
- **Queue** was chosen for BorrowManager because borrowing history follows a FIFO order — the first book borrowed is the first record processed.

---


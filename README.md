# C++ Book Management System (Linked List)

A console-based Book Management System implemented in C++ using a singly linked list data structure.

This project was developed as part of a Data Structures laboratory assignment and demonstrates the implementation of common linked list operations without using STL containers.

---

## Features

### Book Management
- Add a new book at the beginning of the list
- Append a new book at the end of the list
- Insert books in sorted order by publication year
- Display all books
- Find books published in a specific year
- Find the newest book in the collection

### Linked List Operations
- Calculate list length
- Access the Nth element
- Copy an entire list
- Reverse the list
- Split the list into two halves
- Append one list to another
- Delete a specific book by ISBN
- Delete the entire list
- Remove duplicate books using ISBN comparison

### Sorting
- Sort books by publication year

---

## Data Structure

Each node stores information about a book:

```cpp
struct FU_Book {
    char Book_Title[25];
    char Book_SubTitle[35];
    char Book_Authors[40];
    char Book_Editorial[20];
    int Book_Year;
    int Book_ISBN;
    FU_Book* next;
};
```

The project uses a singly linked list where each node points to the next book in the collection.

---

## Implemented Functions

| Function | Description |
|-----------|-------------|
| Cons | Creates an empty list |
| Is_Empty | Checks whether the list is empty |
| Head | Returns the first node |
| Tail | Returns the remaining list |
| First_Insert | Inserts a node at the beginning |
| Sort_year | Sorts books by publication year |
| Sort_Insert | Inserts a node while maintaining sorted order |
| Append | Adds a node at the end |
| Length | Returns the number of nodes |
| Print_List | Displays all books |
| Copy_List | Creates a deep copy of a list |
| Get_Nth | Returns the Nth node |
| Delete_List | Deletes all nodes |
| Delete_Element | Deletes a node by ISBN |
| List_Append | Appends one list to another |
| Split_list | Splits a list into two halves |
| Remove_duplicate | Removes duplicate ISBN entries |
| Reverse | Reverses the list |
| New_book | Finds the newest book |
| Same_year | Displays books from a specific year |

---

## Concepts Demonstrated

- Singly Linked Lists
- Dynamic Memory Allocation
- Pointers
- Node Traversal
- Deep Copying
- Searching Algorithms
- Sorting Algorithms
- Data Structure Manipulation
- Input Validation
- Memory Management

---

## Compilation

Using g++:

```bash
g++ main.cpp -o BookManagement
```

Run:

```bash
./BookManagement
```

---

## Sample Menu

```text
--- BOOK LINKED LIST MENU ---

1. Insert book at beginning
2. Append book at end
3. Print list
4. Sort by year
5. Insert in sorted list
6. Length of list
7. Delete book by ISBN
8. Reverse list
9. Latest book
10. Books of same year
11. Get Nth book
12. Delete entire list
13. Split list
14. Remove duplicates
15. Copy list
16. Append second list
0. Exit
```

---

## Academic Purpose

This project was created to practice linked list implementation and manipulation in C++ without relying on STL containers. The focus is on understanding memory management, pointer operations, and fundamental data structure algorithms.

---

## Author

Shreya Agrawal

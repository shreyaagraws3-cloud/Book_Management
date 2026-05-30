#include <iostream>
#include <cstring>
using namespace std;

struct FU_Book {
    char Book_Title[25];
    char Book_SubTitle[35];
    char Book_Authors[40];
    char Book_Editorial[20];
    int Book_Year;
    int Book_ISBN;
    FU_Book* next;
};

/* 1. Cons */
FU_Book* Cons() {
    return nullptr;
}

/* 2. Is_Empty */
bool Is_Empty(FU_Book* head) {
    return head == nullptr;
}

/* Helper: Create new book */
FU_Book* Create_Book(const char* title, const char* subtitle,
    const char* authors, const char* editorial,
    int year, int isbn) 
{
    FU_Book* b = new FU_Book;
    strcpy(b->Book_Title, title);
    strcpy(b->Book_SubTitle, subtitle);
    strcpy(b->Book_Authors, authors);
    strcpy(b->Book_Editorial, editorial);
    b->Book_Year = year;
    b->Book_ISBN = isbn;
    b->next = nullptr;
    return b;
}

/* 3. Head */
FU_Book* Head(FU_Book* head) {
    return head;
}

/* 4. Tail */
FU_Book* Tail(FU_Book* head) {
    if (!head) return nullptr;
    return head->next;
}

/* 5. First_Insert */
FU_Book* First_Insert(FU_Book* head, FU_Book* newBook) {
    newBook->next = head;
    return newBook;
}

/* 6. Sort_year (Bubble sort by swapping data) */
void Sort_year(FU_Book* head) {
    if (!head) return;

    for (FU_Book* i = head; i->next; i = i->next) {
        for (FU_Book* j = i->next; j; j = j->next) {
            if (i->Book_Year > j->Book_Year) {

                swap(i->Book_Title, j->Book_Title);
                swap(i->Book_SubTitle, j->Book_SubTitle);
                swap(i->Book_Authors, j->Book_Authors);
                swap(i->Book_Editorial, j->Book_Editorial);
                swap(i->Book_Year, j->Book_Year);
                swap(i->Book_ISBN, j->Book_ISBN);
            }
        }
    }
}


/* 7. Sort_Insert */
FU_Book* Sort_Insert(FU_Book* head, FU_Book* newBook) {
    if (!head || newBook->Book_Year < head->Book_Year) {
        newBook->next = head;
        return newBook;
    }
    FU_Book* curr = head;
    while (curr->next && curr->next->Book_Year <= newBook->Book_Year)
        curr = curr->next;
    newBook->next = curr->next;
    curr->next = newBook;
    return head;
}


/* 8. Append */
FU_Book* Append(FU_Book* head, FU_Book* newBook) {
    if (!head) return newBook;
    FU_Book* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newBook;
    return head;
}

/* 9. Length */
int Length(FU_Book* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

/* 10. Print_List */
void Print_List(FU_Book* head) {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    while (head) {
        cout << "-----------------------------\n";
        cout << "Title      : " << head->Book_Title << endl;
        cout << "Subtitle   : " << head->Book_SubTitle << endl;
        cout << "Authors    : " << head->Book_Authors << endl;
        cout << "Editorial  : " << head->Book_Editorial << endl;
        cout << "Year       : " << head->Book_Year << endl;
        cout << "ISBN       : " << head->Book_ISBN << endl;
        head = head->next;
    }
}



/* 11. Copy_List */
FU_Book* Copy_List(FU_Book* head) {
    if (!head) return nullptr;
    FU_Book* newHead = Create_Book(head->Book_Title, head->Book_SubTitle,
        head->Book_Authors, head->Book_Editorial,
        head->Book_Year, head->Book_ISBN);
    FU_Book* currNew = newHead;
    FU_Book* currOld = head->next;
    while (currOld) {
        currNew->next = Create_Book(currOld->Book_Title, currOld->Book_SubTitle,
            currOld->Book_Authors, currOld->Book_Editorial,
            currOld->Book_Year, currOld->Book_ISBN);
        currNew = currNew->next;
        currOld = currOld->next;
    }
    return newHead;
}

/* 12. Get_Nth */
FU_Book* Get_Nth(FU_Book* head, int n) {
    int index = 0;
    while (head) {
        if (index == n) return head;
        index++;
        head = head->next;
    }
    return nullptr;
}

/* 13. Delete_List */
void Delete_List(FU_Book*& head) {
    while (head) {
        FU_Book* temp = head;
        head = head->next;
        delete temp;
    }
}

/* 14. Delete_Element (by ISBN) */
FU_Book* Delete_Element(FU_Book* head, int isbn) {
    if (!head) return nullptr;
    if (head->Book_ISBN == isbn) {
        FU_Book* temp = head->next;
        delete head;
        return temp;
    }
    FU_Book* curr = head;
    while (curr->next && curr->next->Book_ISBN != isbn)
        curr = curr->next;
    if (curr->next) {
        FU_Book* temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
    return head;
}

/* 15. List_Append */
FU_Book* List_Append(FU_Book* a, FU_Book*& b) {
    if (!a) a = b;
    else {
        FU_Book* temp = a;
        while (temp->next)
            temp = temp->next;
        temp->next = b;
    }
    b = nullptr;
    return a;
}

/* 16. Split_list */
void Split_list(FU_Book* source, FU_Book*& front, FU_Book*& back) {
    FU_Book* slow = source;
    FU_Book* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    front = source;
    back = slow->next;
    slow->next = nullptr;
}

/* 17. Remove_duplicate  */
void Remove_duplicate(FU_Book* head) {
    FU_Book* curr = head;

    while (curr) {
        FU_Book* runner = curr;
        while (runner->next) {
            if (runner->next->Book_ISBN == curr->Book_ISBN) {
                FU_Book* dup = runner->next;
                runner->next = runner->next->next;
                delete dup;
            }
            else {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}


/* 18. Reverse (iterative) */
FU_Book* Reverse(FU_Book* head) {
    FU_Book* prev = nullptr, * curr = head;
    while (curr) {
        FU_Book* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

/* 19. New_book */
void New_book(FU_Book* head) {
    if (!head) return;
    FU_Book* latest = head;
    while (head) {
        if (head->Book_Year > latest->Book_Year)
            latest = head;
        head = head->next;
    }
    cout << "Latest book: " << latest->Book_Title
        << " (" << latest->Book_Year << ")" << endl;
}

/* 20. Same_year */
void Same_year(FU_Book* head, int year) {
    while (head) {
        if (head->Book_Year == year)
            cout << head->Book_Title << endl;
        head = head->next;
    }
}

int main() {
    FU_Book* list = Cons();
    FU_Book* list2 = nullptr;   // second list for append & copy
    int choice;

    do {
        cout << "\n--- BOOK LINKED LIST MENU ---\n";
        cout << "1. Insert book at beginning\n";
        cout << "2. Append book at end\n";
        cout << "3. Print list\n";
        cout << "4. Sort by year\n";
        cout << "5. Insert in sorted list (by year)\n";
        cout << "6. Length of list\n";
        cout << "7. Delete book by ISBN\n";
        cout << "8. Reverse list\n";
        cout << "9. Latest book\n";
        cout << "10. Books of same year\n";
        cout << "11. Get Nth book\n";
        cout << "12. Delete entire list\n";
        cout << "13. Split list\n";
        cout << "14. Remove duplicates (by ISBN)\n";
        cout << "15. Copy list\n";
        cout << "16. Append second list to main list\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 5) {
            char title[25], subtitle[35], authors[40], editorial[20];
            int year, isbn;

            cin.ignore();  // clear newline after menu choice

            cout << "Title: ";
            cin.getline(title, 25);

            cout << "Subtitle: ";
            cin.getline(subtitle, 35);

            cout << "Authors: ";
            cin.getline(authors, 40);

            cout << "Editorial: ";
            cin.getline(editorial, 20);

            cout << "Year: ";
            cin >> year;
            while (cin.fail()) {
                cin.clear(); // clear error flag
                cin.ignore(1000, '\n'); // discard invalid input
                cout << "Invalid input. Enter a numeric year: ";
                cin >> year;
            }

            cout << "ISBN: ";
            cin >> isbn;
            while (cin.fail()) {
                cin.clear(); // clear error flag
                cin.ignore(1000, '\n'); // discard invalid input
                cout << "Invalid input. Enter a numeric number: ";
                cin >> isbn;
            }

            FU_Book* b = Create_Book(title, subtitle, authors, editorial, year, isbn);
           
            if (choice == 1)
                list = First_Insert(list, b);
            else if (choice == 2)
                list = Append(list, b);
            else
                list = Sort_Insert(list, b);
        }

        else if (choice == 3)
            Print_List(list);

        else if (choice == 4)
            Sort_year(list);

        else if (choice == 6)
            cout << "Length: " << Length(list) << endl;

        else if (choice == 7) {
            int isbn;
            cout << "Enter ISBN to delete: ";
            cin >> isbn;
            list = Delete_Element(list, isbn);
        }

        else if (choice == 8)
            list = Reverse(list);

        else if (choice == 9)
            New_book(list);

        else if (choice == 10) {
            int year;
            cout << "Enter year: ";
            cin >> year;
            Same_year(list, year);
        }

        else if (choice == 11) 
        {
            int n;
            cout << "Enter position (starting from 0): ";
            cin >> n;

            FU_Book* result = Get_Nth(list, n);
            if (result) {
                cout << "Title: " << result->Book_Title << endl;
                cout << "Year : " << result->Book_Year << endl;
                cout << "ISBN : " << result->Book_ISBN << endl;
            }
            else {
                cout << "Position not found.\n";
            }
        }

        else if (choice == 12) {
            Delete_List(list);
            cout << "List deleted.\n";
        }

        else if (choice == 13) {
            FU_Book* front = nullptr, * back = nullptr;

            if (!list || !list->next) {
                cout << "List too small to split.\n";
            }
            else {
                Split_list(list, front, back);

                cout << "\nFront list:\n";
                Print_List(front);

                cout << "\nBack list:\n";
                Print_List(back);
            }
        }

        else if (choice == 14) {
            Remove_duplicate(list);
            cout << "Duplicates removed.\n";}

        else if (choice == 15) {
            if (!list) {
                cout << "Main list is empty.\n";
            } 
            else {
                list2 = Copy_List(list);
                cout << "List copied successfully.\n";
                cout << "\nCopied list:\n";
                Print_List(list2);
            }}

        else if (choice == 16) {
            if (!list2) {
                cout << "Second list is empty. Copy a list first.\n";
            }
            else {
                list = List_Append(list, list2);
                cout << "Second list appended to main list.\n";
            }}

    } while (choice != 0);

    Delete_List(list);
    return 0;
}

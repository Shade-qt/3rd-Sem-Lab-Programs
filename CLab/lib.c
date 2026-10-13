/*
1. Develop a Program in C for the following:
a. Define a record (structure) titled Book with the following fields:
   Book_ID, Title, Author, Price, Availability Status (Available/Issued).
b. Dynamically allocate memory to store the details of N books, where N is
   entered by the user.
c. Implement the following functions:
   i. create() – To allocate memory and read the details of N books and store
      them in the allocated memory.
   ii. display() – To display the details of all books available in the library.
   iii. search() – To search for a book using Book ID and display the book
      details if found.
   iv. issueBook() – To issue a book by updating its availability status and
      display an appropriate message.
   v. returnBook() – To return an issued book by updating its availability
      status and display an appropriate message.
d. Build a menu-driven interface with the following options:
   i. Add Book Records.
   ii. Display all Book Records.
   iii. Search Book by Book ID.
   iv. Issue a Book.
   v. Return a Book.
   vi. Exit.
VTU/AEC Lab/LAB COURSE (1 Credit)
*/

//Lab batch A1 , dated on 22-09-2026

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    int Book_ID;
    char Title[100];
    char Author[100];
    float Price;
    char Availability_Status[20];
};

struct Book *create(int n);
void display(struct Book *books, int n);
void search(struct Book *books, int n);
void issueBook(struct Book *books, int n);
void returnBook(struct Book *books, int n);

int main()
{
    struct Book *books = NULL;
    int n = 0;
    int choice;

    while (1)
    {
        printf("\n\n========== LIBRARY MANAGEMENT SYSTEM ==========\n");
        printf("1. Add Book Records\n");
        printf("2. Display all Book Records\n");
        printf("3. Search Book by Book ID\n");
        printf("4. Issue a Book\n");
        printf("5. Return a Book\n");
        printf("6. Exit\n");
        printf("===============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (books != NULL)
                {
                    free(books);
                    books = NULL;
                }

                printf("\nEnter the number of books: ");
                scanf("%d", &n);

                if (n <= 0)
                {
                    printf("Invalid number of books!\n");
                    n = 0;
                    break;
                }

                books = create(n);
                break;

            case 2:
                if (books == NULL)
                    printf("\nNo book records available. Please add records first.\n");
                else
                    display(books, n);
                break;

            case 3:
                if (books == NULL)
                    printf("\nNo book records available. Please add records first.\n");
                else
                    search(books, n);
                break;

            case 4:
                if (books == NULL)
                    printf("\nNo book records available. Please add records first.\n");
                else
                    issueBook(books, n);
                break;

            case 5:
                if (books == NULL)
                    printf("\nNo book records available. Please add records first.\n");
                else
                    returnBook(books, n);
                break;

            case 6:
                free(books);
                printf("\nProgram terminated successfully.\n");
                return 0;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
}

struct Book *create(int n)
{
    struct Book *books;
    int i;

    books = (struct Book *)malloc(n * sizeof(struct Book));

    if (books == NULL)
    {
        printf("\nMemory allocation failed!\n");
        exit(1);
    }

    for (i = 0; i < n; i++)
    {
        printf("\n----- Enter details of Book %d -----\n", i + 1);

        printf("Enter Book ID: ");
        scanf("%d", &books[i].Book_ID);

        printf("Enter Title: ");
        scanf(" %99[^\n]", books[i].Title);

        printf("Enter Author: ");
        scanf(" %99[^\n]", books[i].Author);

        printf("Enter Price: ");
        scanf("%f", &books[i].Price);

        strcpy(books[i].Availability_Status, "Available");
    }

    printf("\nBook records added successfully!\n");

    return books;
}

void display(struct Book *books, int n)
{
    int i;

    printf("\n==================== BOOK RECORDS ====================\n");
    printf("%-10s %-25s %-20s %-10s %-15s\n",
           "Book ID", "Title", "Author", "Price", "Status");
    printf("-------------------------------------------------------\n");

    for (i = 0; i < n; i++)
    {
        printf("%-10d %-25s %-20s %-10.2f %-15s\n",
               books[i].Book_ID,
               books[i].Title,
               books[i].Author,
               books[i].Price,
               books[i].Availability_Status);
    }

    printf("=======================================================\n");
}

void search(struct Book *books, int n)
{
    int id, i, found = 0;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (books[i].Book_ID == id)
        {
            printf("\nBook found!\n");
            printf("Book ID       : %d\n", books[i].Book_ID);
            printf("Title         : %s\n", books[i].Title);
            printf("Author        : %s\n", books[i].Author);
            printf("Price         : %.2f\n", books[i].Price);
            printf("Availability  : %s\n", books[i].Availability_Status);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("\nBook with ID %d not found.\n", id);
}

void issueBook(struct Book *books, int n)
{
    int id, i, found = 0;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (books[i].Book_ID == id)
        {
            found = 1;

            if (strcmp(books[i].Availability_Status, "Available") == 0)
            {
                strcpy(books[i].Availability_Status, "Issued");
                printf("\nBook issued successfully!\n");
                printf("Title: %s\n", books[i].Title);
            }
            else
            {
                printf("\nBook is already issued.\n");
            }

            break;
        }
    }

    if (found == 0)
        printf("\nBook with ID %d not found.\n", id);
}

void returnBook(struct Book *books, int n)
{
    int id, i, found = 0;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    for (i = 0; i < n; i++)
    {
        if (books[i].Book_ID == id)
        {
            found = 1;

            if (strcmp(books[i].Availability_Status, "Issued") == 0)
            {
                strcpy(books[i].Availability_Status, "Available");
                printf("\nBook returned successfully!\n");
                printf("Title: %s\n", books[i].Title);
            }
            else
            {
                printf("\nBook is already available in the library.\n");
            }

            break;
        }
    }

    if (found == 0)
        printf("\nBook with ID %d not found.\n", id);
}


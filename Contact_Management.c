#include <stdio.h>
#include <string.h>
#include "contact_func.h"


int main ()
{   
    int menu_select; 
    int a = 0;
    //in ra menu sử dụng while (a) : lặp vô tận
    while (a==0)
    {
        printf ("\nWelcome to the Contact Manager!\n1. Add a new contact\n2. Display all contacts\n3. Search for a contact\n4. Exit\n\n");
        printf ("Enter your choice: ");
        scanf ("%d", &menu_select);
        while ( getchar() != '\n' ); // xóa bộ đệm
        switch (menu_select)
        {

            case 1:
                ADD_NEW_CONTACT ();
                break;
            case 2:
                DISPLAY_ALL ();
                break;
            case 3:
                FIND_CONTACT ();
                break;
            case 4:
                printf ("Goodbye!\n");
                return 0;
            default:
                printf ("Invalid selection! Please enter a valid choice.");
                break;
        }
    }

return 0;

}

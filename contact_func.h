
#include <string.h>
#include <stdio.h>
#ifndef CO_FUNC_1
#define CO_FUNC_1

struct CONTACTS {

    char name[30];
    char phone_number[30];
    char address [30];

};
// hàm nhập thông tin -  ứng với function 1.
void ADD_NEW_CONTACT ()
{
    struct CONTACTS contact;
    // Nhập tông tin cho new contact
    printf ("Enter name: ");
    fgets (contact.name, sizeof(contact.name) , stdin);
    //contact.name [strcspn (contact.name,"\n")] = '\0'; 
    printf ("Enter phone number: ");
    fgets (contact.phone_number, sizeof(contact.phone_number) , stdin);
    //contact.phone_number [strcspn (contact.phone_number,"\n")] = '\0'; 
    printf ("Enter address: ");
    fgets (contact.address, sizeof(contact.address) , stdin);
    //contact.address [strcspn (contact.address,"\n")] = '\0'; 

    // ghi tiếp vào file CONTACT_DATA
    FILE *file = fopen("CONTACT_DATA.txt", "a");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return ;
    }
    // fprintf (file,"Name: %s\nPhone: %s\nAddress: %s\n", contact.name, contact.phone_number, contact.address );
    fprintf (file,"%s\n%s\n%s\n", contact.name, contact.phone_number, contact.address );
    printf ("Contact has been added successfully.\n");
    fclose (file);
}

// in ra tất cả contract từ file
void DISPLAY_ALL ()
{
    int Contact_Count  = 1 ;
    printf ("Contact List:\n################################\n");
    struct CONTACTS contact;
    FILE *file = fopen("CONTACT_DATA.txt", "r");
        if (file == NULL) {
        printf("Cannot open file.\n");
        return ;
    }
    // ghi dữ liệu từ file vào struct
    while (fgets (contact.name, sizeof(contact.name), file) != NULL) {
        fgets (contact.phone_number, sizeof(contact.phone_number), file);
        fgets (contact.address, sizeof(contact.address), file);

        // bỏ ký tự xuống dòng ở
        contact.name[strcspn(contact.name, "\n")] = '\0';
        contact.phone_number[strcspn(contact.phone_number, "\n")] = '\0';
        contact.address[strcspn(contact.address, "\n")] = '\0';

        //in thông tin của contact
        printf("%d\tName: %s\n",Contact_Count, contact.name);
        printf("\tPhone: %s\n", contact.phone_number);
        printf("\tAddress: %s\n", contact.address);
        printf ("\n");
        Contact_Count++; // biến đếm tăng
    }
    fclose(file);
    printf ("\n################################\n");
}
// hàm tìm tên contact
void FIND_CONTACT ()
{
    struct CONTACTS contact;
    char find_contact [30];

    FILE *file = fopen("CONTACT_DATA.txt", "r");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return ;
    }

    printf ("Enter name to search for: ");

    fgets(find_contact, sizeof (find_contact), stdin); // nhập tên để tìm kiếm contact
    find_contact[strcspn(find_contact, "\n")] = '\0';  // xóa ký tự xuống dòng

    while (fgets (contact.name, sizeof(contact.name), file) != NULL) {
        fgets (contact.phone_number, sizeof(contact.phone_number), file);
        fgets (contact.address, sizeof(contact.address), file);


        // loại bỏ ký tự xuống dòng ở cuối
        contact.name[strcspn(contact.name, "\n")] = '\0';
        contact.phone_number[strcspn(contact.phone_number, "\n")] = '\0';
        contact.address[strcspn(contact.address, "\n")] = '\0';

        //tìm tên contact
        if (strcmp (find_contact, contact.name ) == 0 )
        {
            printf ("Contact found:\n");
            printf ("Name: %s\n",contact.name);
            printf ("Phone: %s\n", contact.phone_number);
            printf ("Address: %s\n", contact.address);

        }
    }
}
#endif

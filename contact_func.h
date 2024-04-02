
#include <string.h>
#include <stdio.h>
#ifndef CO_FUNC_1
#define CO_FUNC_1

struct CONTACTS {

    char name[50];
    char phone_number[30];
    char address [50];

};
// hàm nhập thông tin -  ứng với function 1.
void ADD_NEW_CONTACT ()
{
    
    // mở file CONTACT_DATA với lệnh ghi tiếp
    FILE *file = fopen("CONTACT_DATA.txt", "a");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return ;
    }
    struct CONTACTS contact;
    // Nhập tông tin cho new contact
    printf ("Enter name: ");
    fgets (contact.name, sizeof(contact.name) , stdin);
    contact.name [strcspn (contact.name,"\n")] = '\0'; //xóa dấu xuống dòng mỗi lần nhập
    printf ("Enter phone number: ");
    fgets (contact.phone_number, sizeof(contact.phone_number) , stdin);
    contact.phone_number [strcspn (contact.phone_number,"\n")] = '\0'; //xóa dấu xuống dòng mỗi lần nhập
    printf ("Enter address: ");
    fgets (contact.address, sizeof(contact.address) , stdin);
    contact.address [strcspn (contact.address,"\n")] = '\0';  //xóa dấu xuống dòng mỗi lần nhập

    //ghi vào file
    fprintf (file,"%s\n%s\n%s\n", contact.name, contact.phone_number, contact.address );

    // thông báo nhập thông tin hoàn thành.
    printf ("Contact has been added successfully.\n");
    fclose (file);
}

// in ra tất cả contract từ file
void DISPLAY_ALL ()
{   
    // khai báo kiểu dữ liệu CONTRACTS 
    struct CONTACTS contact;
    // mở file
    FILE *file = fopen("CONTACT_DATA.txt", "r");
        if (file == NULL) {
        printf("Cannot open file.\n");
        return ;
    }

    int Contact_Count  = 1 ; // biến đếm để thể hiện thứ tự contact
    printf ("\n######### CONTACT LIST #########\n");
    
    // ghi dữ liệu từ file vào struct
    while (fgets (contact.name, sizeof(contact.name), file) != NULL) {
        fgets (contact.phone_number, sizeof(contact.phone_number), file);
        fgets (contact.address, sizeof(contact.address), file);

        // bỏ ký tự xuống dòng ở cuối mỗi dòng
        contact.name[strcspn(contact.name, "\n")] = '\0';
        contact.phone_number[strcspn(contact.phone_number, "\n")] = '\0';
        contact.address[strcspn(contact.address, "\n")] = '\0';

        //in thông tin của contact
        printf("%d.\tName: %s\n", Contact_Count, contact.name); // in ra số thứ tự của contact
        printf("\tPhone: %s\n", contact.phone_number);
        printf("\tAddress: %s\n", contact.address);
        printf ("\n");

        Contact_Count ++; // biến đếm tăng
    }
    fclose(file);
    printf ("\n################################\n");
}


// hàm tìm tên contact
void FIND_CONTACT ()
{   
    //mở file dưới mode đọc file
    FILE *file = fopen("CONTACT_DATA.txt", "r");
    if (file == NULL) {
        printf("Cannot open file.\n");
        return ;
    }

    struct CONTACTS contact;
    char find_contact [50];

    printf ("Enter name to search for: ");

    fgets(find_contact, sizeof (find_contact), stdin); // nhập tên để tìm kiếm contact
    find_contact[strcspn(find_contact, "\n")] = '\0';  // xóa ký tự xuống dòng

    // tìm kiếm bằng cách diệt file CONTACT_DATA.txt con trỏ lúc này chạy theo fgets.
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

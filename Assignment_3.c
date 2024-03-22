#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <float.h>

// hàm in ra khi nhập tên 1 kiểu dữ liệu
void type_one (const char *type_name, size_t size , double min, double max)
{
    char str_buffer [10]; // tạo biến đệm
    strcpy (str_buffer, (size == 1) ? "byte" : "bytes"); // thay thế byte cho bytes khi size của kiểu dữ liệu lớn = 1 byte
    if ((strcmp (type_name, "double") == 0) || (strcmp (type_name, "float") == 0))
    {
        // biếu diễn dưới dạng %e cho kiểu float và double 
        printf ("%s có %zu %s.\nRange giá trị min: %e giá trị max %e", type_name, size, str_buffer,  min, max);
    }
    else
    {
        // ép kiểu in ra số nguyên so với kiểu dữ liệu double đã khai báo
        printf ("%s có %zu %s.\nRange giá trị min: %d giá trị max %d", type_name, size, str_buffer, (int) min, (int)max);
    }
}
// hàm in ra tất cả các kiểu dữ liệu khi nhập all
void type_all ()
{
    printf ("Tất cả các kiểu dữ liệu:\n");
    printf ("Size of int: %zu bytes\nValue range of int: %d to %d\n", sizeof (int), INT_MIN, INT_MAX);
    printf ("Size of char: %zu bytes\nValue range of char: %d to %d\n", sizeof (char), CHAR_MIN, CHAR_MAX);
    printf ("Size of float: %zu bytes\nValue range of float: %e to %e\n", sizeof (float), FLT_MIN, FLT_MAX);
    printf ("Size of double: %zu bytes\nValue range of double: %e to %e\n", sizeof (double), DBL_MIN, DBL_MAX);

}
int main (int argc, char *argv[])
{
    char input[20];
    /* nếu không có tham số truyền vào từ terminal thì chương trình khởi chạy bình thường
    nếu có giá trị nhập từ termial ct chạy*/
    if (argv [1] == NULL){
    printf ("Enter the data type name (or \"all\" to display all):");
        fgets (input, sizeof (input), stdin);
    }
    else{
        if (argc >= 2){
            strcpy (input, argv[1]);
        }
        else
            printf ("Không có giá trị truyền vào.");
        }   
    input[strcspn(input, "\n")] = '\0'; // xóa ký tự xuống dòng
    
    if (strcmp(input, "all") == 0 ) // nếu nhập all in gọi hàm type_all
    {   
        type_all ();
    }

    else if (strcmp (input, "int") == 0 ){
        type_one ("int", sizeof (int), INT_MIN, INT_MAX );
    }
    else if (strcmp (input, "double") == 0 ){
        type_one ("double", sizeof (double), DBL_MIN, DBL_MAX );
    }
    else if (strcmp (input, "float") == 0 ){
        type_one ("float", sizeof (float), FLT_MIN, FLT_MAX );
    }
     else if (strcmp (input, "char") == 0 ){
        type_one ("char", sizeof (char), CHAR_MIN, CHAR_MAX );
    }
    else
        printf ("Unknow data type!");
    
    return 0;

}
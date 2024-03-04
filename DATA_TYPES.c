#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <float.h>

// Hàm in ra kích thước và khoảng của 1 kiểu dữ liệu
void print_one_type(const char *type_name, size_t size, double min, double max) {
    if (size > 1)
        printf("Size of %s: %zu bytes\n", type_name, size);
    else
        printf("Size of %s: %zu byte\n", type_name, size);
    
    // Kiểm tra nếu là kiểu dữ liệu int hoặc float thì in ra giá trị min và max dưới dạng số nguyên
    if (strcmp(type_name, "int") == 0 || strcmp(type_name, "char") == 0)
        printf("Value range of %s: %d to %d\n", type_name, (int)min, (int)max);
    else
        printf("Value range of %s: %e to %e\n", type_name, min, max);
}


// Hàm in ra kích thước và khoảng của tất cả kiểu dữ liệu khi nhập all
void print_all_types() {
    printf("\nSize of int: Size: %zu bytes\nValue range of int: %d to %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("\nSize of float: %zu bytes\nValue range of float: %e to %e\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("\nSize of char: %zu byte\nValue range of char: %d to %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("\nSize of double: %zu bytes\nValue range of double: %e to %e\n", sizeof(double), DBL_MIN, DBL_MAX);
}

int main() {
    char input[20];

    printf("Enter the data type name (or \"all\" to display all): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; //xóa ký tự xuống dòng

    if (strcmp(input, "all") == 0) {
        print_all_types();
    } else if (strcmp(input, "char") == 0) {
        print_one_type("char", sizeof(char), CHAR_MIN, CHAR_MAX);
    } else if (strcmp(input, "int") == 0) {
        print_one_type("int", sizeof(int), INT_MIN, INT_MAX);
    } else if (strcmp(input, "float") == 0) {
        print_one_type("float", sizeof(float), FLT_MIN, FLT_MAX);
    } else if (strcmp(input, "double") == 0) {
        print_one_type("double", sizeof(double), DBL_MIN, DBL_MAX);
    } else {
        printf("Unknown data type.\n");
    }

    return 0;
}

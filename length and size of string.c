#include <stdio.h>
#include <string.h>

int main() {
    
    char str[] = " ";
    int size = sizeof(str);
    
    // Length of the string excluding the null terminator
    size_t length = strlen(str);
    
    printf("Size of the string (including null terminator): %d\n", size);
    printf("Length of the string (excluding null terminator): %zu\n", length);

    return 0;
}

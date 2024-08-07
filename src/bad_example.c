#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function with buffer overflow vulnerability
void vulnerable_function(const char *input) {
    char buffer[10];
    strcpy(buffer, input); // Unsafe copy, potential overflow
    printf("Buffer: %s\n", buffer);
}

// Function with inefficient loops
void inefficient_function(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", i * j); // Inefficient nested loop
        }
    }
    printf("\n");
}

// Function with improper error handling
void error_handling_function(int *ptr) {
    if (ptr == NULL) {
        printf("Error: Null pointer!\n");
        // Missing proper error handling
    }
    *ptr = 42; // Dereference without checking
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input>\n", argv[0]);
        return 1;
    }
    
    vulnerable_function(argv[1]);
    inefficient_function(100);
    
    int *ptr = NULL;
    error_handling_function(ptr);

    return 0;
}

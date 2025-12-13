#include <stdio.h>
#include <string.h> // Required for strlen()

// Function Prototype
void reverse(char str1[], char str2[]);

int main() {
    char text[50] = "I Love You";
    char out[50];

    // Call the function
    reverse(text, out);

    // Print the result to verify (matches the Output in the image)
    printf("Reversed: %s\n", out);

    return 0;
}

// Function Definition
void reverse(char str1[], char str2[]) {
    int len = strlen(str1); // Find the length of the input string
    int j = 0;

    // Loop starting from the last character of str1 (len - 1) down to 0
    for (int i = len - 1; i >= 0; i--) {
        str2[j] = str1[i]; // Copy character from str1 to str2
        j++;               // Move to the next position in str2
    }

    str2[j] = '\0'; // IMPORTANT: Add the null terminator to mark the end of the string
}
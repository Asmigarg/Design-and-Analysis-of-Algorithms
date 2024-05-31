#include <stdio.h>
#include <string.h>

int StringMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    for (int i=0; i<=n-m; i++) {
        int j = 0;
        while (j < m && text[i + j] == pattern[j]) {
            j++;
        }
        if (j == m) {
            return i; // Pattern found at position i in the text
        }
    }
    return -1; // Pattern not found in the text
}


int main() {
    printf("My name is Asmi Garg\n");
    printf("My SAP ID: 500107577\n");

    char text[100];
    char pattern[100];
    printf("Enter the text: ");
    scanf("%s", text);
    printf("Enter the pattern to search for: ");
    scanf("%s", pattern);
    int position = StringMatch(text, pattern);
    if (position != -1) {
        printf("Pattern found at position %d in the text.\n", position);
    } else {
        printf("Pattern not found in the text.\n");
    }


    return 0;
}


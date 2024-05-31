#include <stdio.h>
#include <math.h>

// Function to generate subsets
void subset(int num, int n, int x[]) {
    int i;
    // Initialize the array with zeros
    for (i = 1; i <= n; i++)
        x[i] = 0;
    
    // Generate binary representation of num
    for (i = n; num != 0; i--) {
        x[i] = num % 2;
        num = num / 2;
    }
}

// Main function
int main() {
    printf("My name is Arshdeep Kaur\n");
    printf("My Sap ID is 500107135\n");

    // Declare arrays and variables
    int a[10];
    int x[10];
    int n, d, sum, present = 0;
    int j;

    // Input the number of elements in the set
    printf("Enter the number of elements of set: ");
    scanf("%d", &n);

    // Input the elements of the set
    printf("Enter the elements of set: ");
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    // Input the positive integer sum
    printf("Enter the positive integer sum: ");
    scanf("%d", &d);

    // Check if a solution is possible
    if (d > 0) {
        // Iterate through all possible subsets
        for (int i = 1; i <= pow(2, n) - 1; i++) {
            // Generate the subset
            subset(i, n, x);
            sum = 0;

            // Calculate the sum of the current subset
            for (j = 1; j <= n; j++)
                if (x[j] == 1)
                    sum = sum + a[j];

            // Check if the sum matches the desired sum
            if (d == sum) {
                printf("Subset={");
                present = 1;
                for (j = 1; j <= n; j++)
                    if (x[j] == 1)
                        printf("%d,", a[j]);
                printf("}=%d\n", d);
            }
        }
    }

    // Print a message if no solution exists
    if (present == 0)
        printf("Solution does not exist\n");

    return 0;
}


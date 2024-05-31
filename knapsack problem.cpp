#include <stdio.h>
#include <math.h>

int main() {
    char obj[10][10];
    float profit[10], weight[10], profitperKG[10], temp[10], addedWeight[10], addedProfit[10];
    float weightofBag;
    int n;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the weight of the bag: ");
    scanf("%f", &weightofBag);

    printf("Enter the objects, their profit & their weight: ");
    for (int i = 0; i < n; i++) {
        scanf("%s%f%f", obj[i], &profit[i], &weight[i]);
    }

    for (int i = 0; i < n; i++) {
        float tempAns = profit[i] / weight[i];
        float ans = floorf(tempAns * 100) / 100.0;  // Corrected usage of floorf
        profitperKG[i] = ans;
        temp[i] = tempAns;
    }

    int i = 0, index = 0;
    while (weightofBag > 0 && i < n) {  // Corrected loop condition
        float max = 0;
        for (int j = 0; j < n; j++) {
            if (temp[j] > max) {
                max = temp[j];
                index = j;
            }
        }

        if (weightofBag >= weight[index]) {
            weightofBag = weightofBag - weight[index];
            addedProfit[i] = profitperKG[index];
            addedWeight[i] = weight[index];
        } else {
            addedWeight[i] = weightofBag;
            addedProfit[i] = profitperKG[index];
            weightofBag = 0.00;
        }
        temp[index] = 0;
        i++;
    }

    printf("Weight/Profit Calculated\n");
    printf("Profit:\t");
    for (int i = 0; i < n; i++) {
        printf("%0.1f\t", profit[i]);
    }
    printf("\n");

    printf("Weight:\t");
    for (int i = 0; i < n; i++) {
        printf("%0.1f\t", weight[i]);
    }
    printf("\n");

    printf("Profit/Weight:\t");
    for (int i = 0; i < n; i++) {
        printf("%0.1f\t", profitperKG[i]);
    }
    printf("\n");

    float profitMade = 0;
    for (int j = 0; j < i; j++) {  // Corrected loop condition
        profitMade = profitMade + (addedProfit[j] * addedWeight[j]);
    }
    printf("The profit made is: %0.2f percent\n", profitMade);

    return 0;
}


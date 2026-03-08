#include <stdio.h>

#define MONTHS 12

int main() {

    FILE *file;
    char filename[100];

    double sales[MONTHS];

    char *months[MONTHS] = {
        "January","February","March","April","May","June",
        "July","August","September","October","November","December"
    };

    // Let the user input the file name
    printf("Enter input file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    // Read sales data
    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%lf", &sales[i]);
    }

    fclose(file);

    // Sales report
    printf("\nMonthly Sales Report for 2024\n");
    printf("Month\t\tSales\n");

    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s\t%.2f\n", months[i], sales[i]);
    }

    // Sales summary report
    double min = sales[0];
    double max = sales[0];
    double sum = 0;

    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 0; i < MONTHS; i++) {
        sum += sales[i];

        if (sales[i] < min) {
            min = sales[i];
            minIndex = i;
        }

        if (sales[i] > max) {
            max = sales[i];
            maxIndex = i;
        }
    }

    double avg = sum / MONTHS;

    printf("\nSales summary report:\n");
    printf("Minimum sales: %.2f (%s)\n", min, months[minIndex]);
    printf("Maximum sales: %.2f (%s)\n", max, months[maxIndex]);
    printf("Average sales: %.2f\n", avg);

    // Six-month moving average report
    printf("\nSix-Month moving average report:\n");

    for (int i = 0; i <= MONTHS - 6; i++) {
        double total = 0;

        for (int j = i; j < i + 6; j++) {
            total += sales[j];
        }

        // Print the average for the six-month period
        printf("%s-%s %.2f\n", months[i], months[i+5], total/6);
    }

    // Sales report sorted from highest to lowest
    double sortedSales[MONTHS];
    char *sortedMonths[MONTHS];

    for (int i = 0; i < MONTHS; i++) {
        sortedSales[i] = sales[i];
        sortedMonths[i] = months[i];
    }

    for (int i = 0; i < MONTHS-1; i++) {
        for (int j = i+1; j < MONTHS; j++) {

            if (sortedSales[j] > sortedSales[i]) {

                double tempSales = sortedSales[i];
                sortedSales[i] = sortedSales[j];
                sortedSales[j] = tempSales;

                char *tempMonth = sortedMonths[i];
                sortedMonths[i] = sortedMonths[j];
                sortedMonths[j] = tempMonth;
            }
        }
    }

    printf("\nSales report (highest to lowest):\n");
    printf("Month\t\tSales\n");

    for (int i = 0; i < MONTHS; i++) {
        printf("%-10s\t%.2f\n", sortedMonths[i], sortedSales[i]);
    }

    return 0;
}
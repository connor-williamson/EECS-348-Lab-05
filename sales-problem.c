#include <stdio.h>

void printSalesReport(float sales[], char *months[], int size) {
    printf("Monthly sales report for 2022:\n\n");
    printf(" %-10s %s\n\n", "Month", "Sales");
    for (int i = 0; i < size; i++) {
        printf(" %-10s $%-8.2f\n", months[i], sales[i]);
    }
}

void printSalesSummary(float sales[], char *months[], int size) {
    float minSales = sales[0];
    float maxSales = sales[0];
    float totalSales = 0;
    int minIndex = 0;
    int maxIndex = 0;

    for (int i = 0; i < size; i++) {
        totalSales += sales[i];

        if (sales[i] < minSales) {
            minSales = sales[i];
            minIndex = i;
        }

        if (sales[i] > maxSales) {
            maxSales = sales[i];
            maxIndex = i;
        }
    }

    float averageSales = totalSales / size;

    printf("\nSales summary:\n\n");
    printf(" Minimum sales: $%.2f (%s)\n", minSales, months[minIndex]);
    printf(" Maximum sales: $%.2f (%s)\n", maxSales, months[maxIndex]);
    printf(" Average sales: $%.2f\n", averageSales);
}

void printSixMonthMovingAverage(float sales[], char *months[], int size) {
    printf("\nSix-Month Moving Average Report:\n\n");
    for (int i = 0; i <= size - 6; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        float average = sum / 6;
        printf(" %-10s - %-10s $%-8.2f\n", months[i], months[i + 5], average);
    }
}

void selectionSort (float sales[], char *months[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (sales[j] > sales[max_idx]) {
                max_idx = j;
            }
        }
        float tempSale = sales[max_idx];
        sales[max_idx] = sales[i];
        sales[i] = tempSale;

        char *tempMonth = months[max_idx];
        months[max_idx] = months[i];
        months[i] = tempMonth;
    }
}

void printSalesReport_HighToLow(float sales[], char *months[], int size) {
    printf("\nSales Report (Highest to Lowest):\n\n");
    printf("   %-10s %s\n", "Month", "Sales");
    for (int i = 0; i < size; i++) {
        printf(" %-10s $%.2f\n", months[i], sales[i]);
    }
}

int main() {
    float sales[] = {
        23458.01, 
        40112.00, 
        56011.85, 
        37820.88, 
        37904.67, 
        60200.22, 
        72400.31, 
        56210.89, 
        67230.84, 
        68233.12, 
        80950.34, 
        95225.22 
    };

    char *months[] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    int arrSize = sizeof(sales) / sizeof(sales[0]);
    
    printSalesReport(sales, months, arrSize);
    printSalesSummary(sales, months, arrSize);
    printSixMonthMovingAverage(sales, months, arrSize);
    selectionSort(sales, months, arrSize);
    printSalesReport_HighToLow(sales, months, arrSize);

    return 0;
}
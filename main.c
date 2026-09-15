#include <stdio.h>
#include <stdlib.h>

int main()
{

    int choice;
    do {
        printf("  *----------------------------------------------------------*\n");
        printf("  |       SMART HOSPITAL RESOURCE ALLOCATION SYSTEM          |\n");
        printf("  *----------------------------------------------------------*\n");
        printf("  |  [1]  Register New Patient Intake                        |\n");
        printf("  |  [2]  View Priority Patient Queue (Sorted)               |\n");
        printf("  |  [3]  Display Analytics & Performance Report             |\n");
        printf("  |  [4]  Save All Records to File                           |\n");
        printf("  |  [5]  Exit System                                        |\n");
        printf("  |__________________________________________________________|\n");
        printf("\n Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {


        }
    } while (choice != 5);

    return 0;
}

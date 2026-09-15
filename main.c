#include <stdio.h>
#include <stdlib.h>

#define PATIENTS 1000
#define SPECIALTIES 4
#define WARD 4


const char SPECIALTY_NAMES[5][30] = {"", "General Practice (OPD)", "Paediatrics", "Cardiology", "Neurology"};
const double BASE_FEES[]          = {0.0, 1500.00, 2500.00, 4500.00, 5000.00};
const int AVG_TIME[]              = {0, 15, 20, 30, 30};

const char WARD_NAMES[5][30]      = {"", "General Ward", "Paediatric Ward", "Surgical Ward", "ICU (Intensive Care Unit)"};
const double WARD_DAILY_RATES[]   = {0.0, 3000.00, 6000.00, 12000.00, 25000.00};
int main()
{
    char patientName[PATIENTS][50];
    int age[PATIENTS];
    int triageLevel[PATIENTS];
    int specialtyID[PATIENTS];
    int isAdmitted[PATIENTS];
    int wardID[PATIENTS];
    int daysAdmitted[PATIENTS];

    double totalAmount[PATIENTS];
    double TotalRevenue = 0.0;
    double TotalDiscounts = 0.0;

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

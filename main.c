#include <stdio.h>
#include <stdlib.h>
#include "hospital.h"

#define PATIENTS 1000
#define SPECIALTIES 4
#define WARD 4



int main()
{
    char patientName[PATIENTS][50];
    int age[PATIENTS];
    int triageLevel[PATIENTS];
    int specialtyID[PATIENTS];
    int isAdmitted[PATIENTS];
    int wardID[PATIENTS];
    int daysAdmitted[PATIENTS];

    double finalAmounts[PATIENTS];

    int totalPatients = 0;
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

        case 1 :{
            int startIdx =totalPatients;

            totalPatients = addingPatients(patientName, age, triageLevel, specialtyID, isAdmitted, wardID, daysAdmitted, totalPatients);

            for (int i = startIdx; i < totalPatients; i++) {

                    double gross = 0;
                    double disc = 0;
                    double finalAmt = 0;

                 calculateAndPrintBill(patientName[i], age[i], triageLevel[i], specialtyID[i], isAdmitted[i], wardID[i], daysAdmitted[i], &gross, &disc, &finalAmt);

                    TotalRevenue += finalAmt;
                    TotalDiscounts += disc;
                    finalAmounts[i] = finalAmt;
                }
                break;
        }


        case 2:
            if (totalPatients == 0) {
                    printf("\n  No patients registered yet!\n");
                } else {
                    sortByPriority(patientName, age, triageLevel, totalPatients);
                }
                break;


           case 3:
                generateAnalyticsReport(triageLevel,wardID, isAdmitted, patientName, finalAmounts, totalPatients, TotalRevenue, TotalDiscounts);
                break;


           case 5:

                printf("\n  Exiting Smart Hospital System. Goodbye!\n");
               break;
            default:
                printf("\n  Invalid choice! Please select an option between 1 and 5.\n");
         }

    } while (choice != 5);

    return 0;
}








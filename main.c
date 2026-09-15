#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        case 5:

                printf("\n  Exiting Smart Hospital System. Goodbye!\n");
               break;
            default:
                printf("\n  Invalid choice! Please select an option between 1 and 5.\n");
         }

    } while (choice != 5);

    return 0;
}


int addingPatients(char patientName[][50], int age[], int triageLevel[], int specialtyID[], int isAdmitted[], int wardID[], int daysAdmitted[], int totalPatients ){
    int idx = totalPatients;
    char nextChoice;
    do {
        printf("\n--- Patient Registration (ID: PAT-%d) ---\n", 1001 + idx);
        printf("Enter Patient Name: ");
        scanf(" %[^\n]s", patientName[idx]);

        printf("Enter Patient Age: ");
        scanf("%d", &age[idx]);

        printf("Enter Triage Level (1 = Normal, 2 = Urgent, 3 = Critical): ");
        scanf("%d", &triageLevel[idx]);

        printf("Enter Specialty ID (1 = OPD, 2 = Paediatrics, 3 = Cardiology, 4 = Neurology): ");
        scanf("%d", &specialtyID[idx]);

        printf("Is Admitted to Ward? (1 = Yes, 0 = No): ");
        scanf("%d", &isAdmitted[idx]);

        if (isAdmitted[idx] == 1) {
            printf("Enter Ward ID (1 = General, 2 = Paediatric, 3 = Surgical, 4 = ICU): ");
            scanf("%d", &wardID[idx]);
            printf("Enter Days Admitted: ");
            scanf("%d", &daysAdmitted[idx]);
        } else {
            wardID[idx] = 0;
            daysAdmitted[idx] = 0;
        }

        idx++;

        printf("Add another patient? (Y/N): ");
        scanf(" %c", &nextChoice);

    } while (nextChoice == 'Y' || nextChoice == 'y');

    return idx;
}
void calculateAndPrintBill(char name[], int age, int triageLevel, int specialtyID, int isAdmitted, int wardID, int daysAdmitted, double *gross, double *disc, double *final) {

    double waitTime = AVG_TIME[specialtyID];
    double baseFee = BASE_FEES[specialtyID];
    double surcharge = 0.0;

    if (triageLevel == 2) {

        surcharge = baseFee * 0.20;

    } else if (triageLevel == 3) {

        surcharge = baseFee * 0.50;
    }

    double wardCost = 0.0;
    if (isAdmitted == 1 && wardID >= 1 && wardID <= 4) {

        wardCost = daysAdmitted * WARD_DAILY_RATES[wardID];

    }

    double SubTotal = baseFee + surcharge + wardCost;

    double discount = 0.0;
    if (age < 5 || age > 65) {
        discount = SubTotal * 0.15;
    }

    double finalBill = SubTotal - discount;

    *gross = SubTotal;
    *disc = discount;
    *final = finalBill;

    printf("\n=========================================\n");
    printf("     SMART HOSPITAL ADMISSION & BILL     \n");
    printf("=========================================\n");
    printf("Patient Name           : %s\n", name);
    printf("Age                    : %d Years %s\n", age, (age < 5 || age > 65) ? "(15%% Subsidy Eligible)" : "");
    printf("Specialty              : %s\n", SPECIALTY_NAMES[specialtyID]);
    printf("Assigned Ward          : %s\n", isAdmitted ? WARD_NAMES[wardID] : "None (Outpatient)");
    printf("Urgency Level          : Level %d (%s)\n", triageLevel, triageLevel == 3 ? "Critical" : (triageLevel == 2 ? "Urgent" : "Normal"));
    printf("Base Consultation Fee  : LKR %.2f\n", baseFee);
    printf("Emergency Surcharge    : LKR %.2f\n", surcharge);
    printf("Ward Stay Cost         : LKR %.2f\n", wardCost);
    printf("Gross Total Bill       : LKR %.2f\n", SubTotal);
    printf("Age Subsidy Discount   : LKR -%.2f\n", discount);
    printf("Final Payable Amount   : LKR %.2f\n", finalBill);
    printf("Estimated Waiting Time : %.2f mins\n", waitTime);
    printf("=========================================\n");

}

void sortByPriority(char name[][50], int age[], int triageLevel[], int count) {
    char tempName[50];
    int tempAge, tempTriage;


    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (triageLevel[j] < triageLevel[j + 1]) {


                tempTriage = triageLevel[j];
                triageLevel[j] = triageLevel[j + 1];
                triageLevel[j + 1] = tempTriage;

                // change Age
                tempAge = age[j];
                age[j] = age[j + 1];
                age[j + 1] = tempAge;

                // change Name
                strcpy(tempName, name[j]);
                strcpy(name[j], name[j + 1]);
                strcpy(name[j + 1], tempName); // Fixed: string copy keyword
            }
        }
    }


    printf("\n--- PRIORITY LIST (Sorted by Urgency) ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s | Age: %d | Priority Level: %d (", i + 1, name[i], age[i], triageLevel[i]);

        if (triageLevel[i] == 3) {
            printf("Critical");
        } else if (triageLevel[i] == 2) {
            printf("Urgent");
        } else {
            printf("Normal");
        }

        printf(")\n");
    }
}

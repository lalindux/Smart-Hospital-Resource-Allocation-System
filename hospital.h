#ifndef HOSPITAL_H_INCLUDED
#define HOSPITAL_H_INCLUDED


#define PATIENTS 1000
#define SPECIALTIES 4
#define WARD 4


const char SPECIALTY_NAMES[5][30];
const double BASE_FEES[5];
const int AVG_TIME[5];

const char WARD_NAMES[5][30];
const double WARD_DAILY_RATES[5];

int addingPatients(char patientName[][50], int age[], int triageLevel[], int specialtyID[], int isAdmitted[], int wardID[], int daysAdmitted[], int totalPatients );
void calculateAndPrintBill(char name[], int age, int triageLevel, int specialtyID, int isAdmitted, int wardID, int daysAdmitted, double *gross, double *disc, double *final);
void sortByPriority(char name[][50], int age[], int triageLevel[], int count);
void generateAnalyticsReport(int triageLevel[],int wardID[],int isAdmitted[],char patientName[][50],double finalAmounts[], int totalPatients, double totalRevenue, double totalDiscounts);



#endif // HOSPITAL_H_INCLUDED

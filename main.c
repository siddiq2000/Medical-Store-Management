#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
#include "customer_Struct.h"
#include "medicinestruct.h"
#include "supplierstruct.h"
#include "billstruct.h"
#include "about.h"
int main()
{   struct customerInfo cu;
    int choice;
//    char storedPassword[100];
//    char enterPassword[100];
//    printf("Enter Passoword\n");
//    scanf
//    if()
    do{
        printf("Enter Choice\n");
        printf("1.Customer Menu \t2.Medicine Menu \t3.Supplier Menu \t4.Billing \t5.About \t6.Exit\n: ");
        scanf("%d",&choice);
        printf("\n******************************************************\n");
        switch(choice){
        case 1:
            customerMenu();
            break;
        case 2:
            medicineMenu();
            break;
        case 3:
            supplierMenu();
            break;
        case 4:
            bill();
            break;
        case 5:
            about();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Invalid Input\n");
        }
    }
    while(choice);
    return 0;
}

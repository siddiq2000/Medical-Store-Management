#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct billing{
    int bill_no;
    char cname[50];
    char mediname[50];
    int medi_qty;
    int medi_rate;
    int total;
};
struct billing b;

struct medicin {
    int med_id;
    char medi_name[50];
    int qty; //Avaiable after sell
    int quantity; //Total quantity while buying //addnew
    int rack;
    int cabinet;
    int sale; // selling quantity
    int total; //qty*buying price
    int unit;  // quantity in package of medicine
    int cost; //Selling price
    int profit;
    int buy; //Buying price
    int bill_no;
    char pur_date[20];
    char exp_date[20];
    char manu_date[20];
    char cmp_name[90];
    char supp_name[90];
};
struct medicin med;

void bill(){
    time_t t = time(NULL);
    struct tm dt = *localtime(&t);
    int total;
    printf("\nEnter Bill no.\n");
    scanf("%d",&b.bill_no);
    printf("Enter Customer name\n");
    scanf("%s",b.cname);
    printf("Enter Medicine Name\n");
    scanf("%s",b.mediname);
    printf("Enter quantity of Medicine\n");
    scanf("%d",&b.medi_qty);
//    printf("Enter Medicine rate\n");
//    scanf("%d",&b.medi_rate);
//    total= b.medi_qty * b.medi_rate;
//    printf("Enter Date\n");
//    scanf("%s",b.date);
    FILE *fptr,*tmpfptr;
    fptr=fopen("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Medicine.txt","r");
    tmpfptr=fopen("temp.txt","w");
    if(fptr==NULL){
        printf("Unable to Open File!!!\n");
        return;
    }
    while(fscanf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",&med.med_id, med.medi_name, &med.quantity, &med.qty, &med.rack, &med.cabinet, &med.sale, &med.unit, &med.cost, &med.buy, &med.bill_no, med.pur_date, med.exp_date, med.manu_date, med.cmp_name, med.supp_name, &med.total, &med.profit)!= EOF){
            if(strcmp(b.mediname,med.medi_name)==0){
                med.sale=med.sale+b.medi_qty;
                med.qty=med.qty-b.medi_qty;
                b.medi_rate=med.cost;
            }
            else{
                printf("\nMedicine not found in inventory.\n");
                return;
            }
    fprintf(tmpfptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",med.med_id, med.medi_name, med.quantity, med.qty, med.rack, med.cabinet, med.sale, med.unit, med.cost, med.buy, med.bill_no, med.pur_date, med.exp_date, med.manu_date, med.cmp_name, med.supp_name, med.total, med.profit);
    }
    fclose(fptr);
    fclose(tmpfptr);
    //Delete Old File and Rename new file
    remove("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Medicine.txt");
    rename("temp.txt","Medicine.txt");


    printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("\nBill no.: %d\n",b.bill_no);
    printf("Customer name: %s\n",b.cname);
    printf("Medicine Name: %s\n",b.mediname);
    printf("Quantity of Medicine: %d\n",b.medi_qty);
    printf("Medicine rate: %d\n",b.medi_rate);
    b.total= b.medi_qty * b.medi_rate;
    printf("Total: %d\n",b.total);
    printf("Date: %02d/%02d/%04d\n", dt.tm_mday, dt.tm_mon + 1, dt.tm_year + 1900);
    FILE *bill1;
    bill1=fopen("Bill.txt","a");
    if(bill1==NULL){
        printf("Error!!!!!!!!!");
    }
        fprintf(bill1,"\nBill no.:%d\nCustomer name: %s\nMedicine Name: %s\nQuantity of Medicine: %d\nMedicine rate: %d\nTotal: %d\nDate: %02d/%02d/%04d\n",b.bill_no,b.cname,b.mediname,b.medi_qty,b.medi_rate,b.total, dt.tm_mday, dt.tm_mon + 1, dt.tm_year + 1900);

    fclose(bill1);
    printf("\n|||Bill Generated|||\n");
    printf("********************************************\n");
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct medicine {
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
struct medicine m;
///////////////////MEDICINE ENTRY/////////////////////////
void medi_entry(struct medicine *m,int n){
    //int t,pft;
    FILE *fptr;
    fptr=fopen("Medicine.txt","a");
    if(fptr==NULL){
        printf("Unable to open file\n");
        return;
    }
    for(int i=0;i<n;i++){
        printf("Enter Medicine ID: ");
        scanf("%d",&m[i].med_id);
        printf("\nEnter Medicine Name: ");
        scanf("%s",m[i].medi_name);
        printf("\nEnter Quantity: ");
        scanf("%d",&m[i].quantity);
        printf("\nEnter Rack number: ");
        scanf("%d",&m[i].rack);
        printf("\nEnter Cabinet: ");
        scanf("%d",&m[i].cabinet);
        printf("\nEnter no. of units in package: ");
        scanf("%d",&m[i].unit);
        printf("\nEnter Selling Price: ");
        scanf("%d",&m[i].cost);
        printf("\nEnter Buying price: ");
        scanf("%d",&m[i].buy);
        printf("\nEnter Bill no.: ");
        scanf("%d",&m[i].bill_no);
        printf("\nEnter Purchase Date: ");
        scanf("%s",m[i].pur_date);
        printf("\nEnter Expiry date: ");
        scanf("%s",m[i].exp_date);
        printf("\nEnter Manufacture Date: ");
        scanf("%s",m[i].manu_date);
        printf("\nEnter Company Name: ");
        scanf("%s",m[i].cmp_name);
        printf("\nEnter Supplier Name: ");
        scanf("%s",m[i].supp_name);
        m[i].qty = m[i].quantity;
        m[i].total = m[i].qty * m[i].buy;
        m[i].sale=0;
        m[i].profit = m[i].cost - m[i].buy;
        fprintf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",m[i].med_id, m[i].medi_name, m[i].quantity ,m[i].qty, m[i].rack, m[i].cabinet, m[i].sale, m[i].unit, m[i].cost, m[i].buy, m[i].bill_no, m[i].pur_date, m[i].exp_date, m[i].manu_date, m[i].cmp_name, m[i].supp_name, m[i].total, m[i].profit);

    }
    fclose(fptr);
}
//////////////////////MEDICINE STOCK//////////////////////////////
void stock() {
    struct medicine m;
    FILE *fptr;
    fptr=fopen("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Medicine.txt","r");
    if(fptr==NULL){
        printf("Unable to Open File!!!\n");
        return;
    printf("File Opened Successfully.\n");
    }
    while(fscanf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",&m.med_id, m.medi_name, &m.quantity, &m.qty, &m.rack, &m.cabinet, &m.sale, &m.unit, &m.cost, &m.buy, &m.bill_no, m.pur_date, m.exp_date, m.manu_date, m.cmp_name, m.supp_name, &m.total, &m.profit)!= EOF){
        printf("Id:%d\nName:%s\nQty:%d\nQuantity after Sale:%d\nRack:%d\nCabinet:%d\nSale:%d\nUnit:%d\nCost:%d\nBuying Price:%d\nBill no:%d\nPurchase Date:%s\nExpiry Date:%s\nManufactured:%s\nCompany:%s\nSupplier:%s\nTotal:%d\nProfit:%d\n\n",m.med_id, m.medi_name, m.quantity, m.qty, m.rack, m.cabinet, m.sale, m.unit, m.cost,m.buy, m.bill_no, m.pur_date, m.exp_date, m.manu_date, m.cmp_name, m.supp_name, m.total, m.profit);
    }
    fclose(fptr);
}
/////////////////////MEDICINE SEARCH//////////////////////////////
void medi_search(int sid){
    struct medicine m;
    FILE *fptr;
    fptr=fopen("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Medicine.txt","r");
    if(fptr == NULL){
        printf("Unable to open file.\n");
        return;
    }
    while(fscanf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",&m.med_id, m.medi_name, &m.quantity,&m.qty, &m.rack, &m.cabinet, &m.sale, &m.unit, &m.cost, &m.buy, &m.bill_no, m.pur_date, m.exp_date, m.manu_date, m.cmp_name, m.supp_name, &m.total, &m.profit)!= EOF){
        if(m.med_id==sid){
            printf("Medicine found\n");
            printf("Id:%d\nName:%s\nQty:%d\nQuantity after Sale:%d\nRack:%d\nCabinet:%d\nSale Price:%d\nUnit:%d\nCost:%d\nBuying Price:%d\nBill no:%d\nPurchase Date:%s\nExpiry Date:%s\nManufactured:%s\nCompany:%s\nSupplier:%s\nTotal:%d\nProfit:%d\n\n",m.med_id, m.medi_name, m.quantity, m.qty, m.rack, m.cabinet, m.sale, m.unit, m.cost,m.buy, m.bill_no, m.pur_date, m.exp_date, m.manu_date, m.cmp_name, m.supp_name, m.total, m.profit);
        }
    }
    fclose(fptr);
}
//////////////////MEDICINE UPDATE//////////////////////////
void update_stock(int uid) {
    struct medicine m;
    FILE *fptr,*tmpfptr;
    fptr=fopen("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Medicine.txt","r");
    tmpfptr=fopen("temp.txt","w");
    if(fptr == NULL){
        printf("Unable to open file.\n");
        return;
    }
    while(fscanf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",&m.med_id, m.medi_name, &m.quantity, &m.qty, &m.rack, &m.cabinet, &m.sale, &m.unit, &m.cost, &m.buy, &m.bill_no, m.pur_date, m.exp_date, m.manu_date, m.cmp_name, m.supp_name, &m.total, &m.profit)!= EOF){
        if(m.med_id==uid){
            printf("***Update Details***\n");
            printf("Enter Medicine ID: ");
            scanf("%d",&m.med_id);
            printf("\nEnter Medicine Name: ");
            scanf("%s",m.medi_name);
            printf("\nEnter Quantity: ");
            scanf("%d",&m.quantity);
            printf("\nEnter Rack number: ");
            scanf("%d",&m.rack);
            printf("\nEnter Cabinet: ");
            scanf("%d",&m.cabinet);
//        printf("\nEnter Sale : ");
//        scanf("%d",&m[i].sale);
            printf("\nEnter no. of units in package: ");
            scanf("%d",&m.unit);
            printf("\nEnter Selling Price: ");
            scanf("%d",&m.cost);
            printf("\nEnter Buying price: ");
            scanf("%d",&m.buy);
            printf("\nEnter Bill no.: ");
            scanf("%d",&m.bill_no);
            printf("\nEnter Purchase Date: ");
            scanf("%s",m.pur_date);
            printf("\nEnter Expiry date: ");
            scanf("%s",m.exp_date);
            printf("\nEnter Manufacture Date: ");
            scanf("%s",m.manu_date);
            printf("\nEnter Company Name: ");
            scanf("%s",m.cmp_name);
            printf("\nEnter Supplier Name: ");
            scanf("%s",m.supp_name);
            m.qty = m.quantity;
            m.total = m.qty * m.buy;
            m.sale=0;
            m.profit = m.cost - m.buy;
        }
        fprintf(tmpfptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",m.med_id, m.medi_name, m.quantity, m.qty, m.rack, m.cabinet, m.sale, m.unit, m.cost, m.buy, m.bill_no, m.pur_date, m.exp_date, m.manu_date, m.cmp_name, m.supp_name, m.total, m.profit);
    }
    fclose(fptr);
    fclose(tmpfptr);
    //Delete Old File and Rename new file
    remove("Medicine.txt");
    rename("temp.txt","Medicine.txt");
}
/////////////////MEDICINE SALE//////////////////////////////
void medi_sale() {
    FILE *fptr;
    fptr=fopen("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Medicine.txt","r");
    if(fptr == NULL){
        printf("Unable to open file.\n");
        return;
    }
    while(fscanf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%s\t%s\t%s\t%s\t%d\t%d\n",&m.med_id, m.medi_name, &m.quantity, &m.qty, &m.rack, &m.cabinet, &m.sale, &m.unit, &m.cost, &m.buy, &m.bill_no, m.pur_date, m.exp_date, m.manu_date, m.cmp_name, m.supp_name, &m.total, &m.profit)!= EOF){
        printf("Quantity after Sale %d of %s \n",m.qty, m.medi_name);
        printf("Sold %d\n",m.sale);
    }
    fclose(fptr);
}
////////////////MEDICINE MENU//////////////////
void medicineMenu() {
    struct medicine *m=NULL;
    int choice,n,sid,uid;
    do{
        printf("Enter Choice\n");
        printf("1.Medicine Entry \t2.Medicine Stock \t3.Medicine Search \t4.Update Stock \t5.Medicine Sale \t6.Back\n");
        scanf("%d",&choice);
        switch(choice) {
            case 1:
                printf("Enter no. of medicine to add\n");
                scanf("%d",&n);
                struct medicine *m=(struct medicine*)malloc(n*sizeof(struct medicine));
                medi_entry(m,n);
                break;
            case 2:
                stock();
                break;
            case 3:
                printf("Enter ID to search medicine\n");
                scanf("%d",&sid);
                medi_search(sid);
                break;
            case 4:
                printf("Enter ID to Update Medicine\n");
                scanf("%d",&uid);
                update_stock(uid);
                break;
            case 5:
                medi_sale();
                break;
        }
    }
    while(choice!=6);
}

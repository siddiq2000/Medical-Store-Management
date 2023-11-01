#include "customer_Struct.h"
#include<stdlib.h>
//////////////////CUSTOMER ENTRY///////////////////////////
void cust_entry(struct customerInfo *cu,int n){
    FILE *fptr;
    fptr=fopen("Customer.txt","a");
    if(fptr==NULL){
        printf("Error!!!!!!!!!");
    }
    for(int i=0;i<n;i++){
        printf("Customer Id \tCustomer Name \tCustomer City \tCustomer Number \tCustomer Email\n:");
        scanf("%d\t%s\t%s\t%lld\t%s",&cu[i].cid,&cu[i].cname,&cu[i].ccity,&cu[i].cmob_no,&cu[i].cemail);
        fprintf(fptr,"%d\t%s\t%s\t%lld\t%s\n",cu[i].cid,cu[i].cname,cu[i].ccity,cu[i].cmob_no,cu[i].cemail);
    }
    fclose(fptr);
    printf("\n|||Data Added Successfully|||\n");
    printf("********************************************\n");
}
////////////////////CUSTOMER SEARCH////////////////////////
void search_cname(char name[]){
    struct customerInfo cu;
    FILE *fptr;
    fptr=fopen("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Customer.txt","r");
    if(fptr == NULL){
        printf("Unable to open file.\n");
        return;
    }
    while(fscanf(fptr,"%d%s%s%lld%s",&cu.cid,cu.cname,cu.ccity,&cu.cmob_no,cu.cemail) != EOF){
        if(strcmp(cu.cname,name)==0){
            printf("Customer found\n");
            printf("%d %s %s %lld %s\n",cu.cid,cu.cname,cu.ccity,cu.cmob_no,cu.cemail);
        }
    }
    fclose(fptr);
}

void search_cid(int cid1) {
    struct customerInfo cu;
    FILE *fptr;
    fptr=fopen("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Customer.txt","r");
    if(fptr == NULL){
        printf("Unable to open file.\n");
        return;
    }
    while(fscanf(fptr,"%d%s%s%lld%s",&cu.cid,cu.cname,cu.ccity,&cu.cmob_no,cu.cemail) != EOF){
        if(cu.cid==cid1){
            printf("Customer found\n");
            printf("%d %s %s %lld %s\n",cu.cid,cu.cname,cu.ccity,cu.cmob_no,cu.cemail);
        }
    }
    fclose(fptr);
}
//////////////////CUSTOMER LIST/////////////////////////
void cust_list(){
    struct customerInfo cu;
    FILE *fptr;
    fptr=fopen("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Customer.txt","r");
    if(fptr==NULL){
        printf("Unable to open file.\n");
        return;
    }
    while(fscanf(fptr,"%d%s%s%lld%s",&cu.cid,cu.cname,cu.ccity,&cu.cmob_no,cu.cemail) != EOF){
        printf("%d %s %s %lld %s\n",cu.cid,cu.cname,cu.ccity,cu.cmob_no,cu.cemail);
    }
    fclose(fptr);
}
/////////////////////CUSTOMER UPDATE///////////////////////
void cust_Update(int up) {
    struct customerInfo cu;
    FILE *fptr, *tmpfptr;
    fptr = fopen("Customer.txt","r");
    tmpfptr = fopen("temp.txt", "w");
    if(fptr == NULL || tmpfptr == NULL){
        printf("Unable to open file.\n");
        return;
    }
    while(fscanf(fptr,"%d%s%s%lld%s",&cu.cid,cu.cname,cu.ccity,&cu.cmob_no,cu.cemail) != EOF){
        if(cu.cid == up){
            printf("***Update Details***\n");
            printf("Customer Id \tCustomer Name \tCustomer City \tCustomer Number \tCustomer Email\n:");
            scanf("%d\t%s\t%s\t%lld\t%s", &cu.cid, cu.cname, cu.ccity, &cu.cmob_no, cu.cemail);
        }
        fprintf(tmpfptr, "%d\t%s\t%s\t%lld\t%s\n", cu.cid, cu.cname, cu.ccity, cu.cmob_no, cu.cemail);
    }
    fclose(fptr);
    fclose(tmpfptr);
    // Delete the old file and rename the new file
    remove("Customer.txt");
    rename("temp.txt", "Customer.txt");
    printf("\n|||Updated Successfully|||\n");
}

////////////////////CUSTOMER MENU///////////////////////
/******************************************/
void customerMenu(){
    int path,cid1; char name[90];
    int choice1,n,up;
    struct customerInfo *cu=NULL;
    do{
        printf("Enter Choice\n");
        printf("1.Customer Entry \t 2.Customer List \t 3.Customer Search \t 4.Customer Update 5.Back\n:");
        scanf("%d",&choice1);
        printf("**************************************************\n");
        switch(choice1){
        case 1:
            printf("Enter number of Customers to add\n:");
            scanf("%d",&n);
            struct customerInfo *cu=(struct customerInfo*)malloc(n*sizeof(struct customerInfo));
            cust_entry(cu,n);
            break;
        case 2:
            cust_list();
            break;
        case 3:

                printf("Search Customer By 1.Name or 2.Customer ID\n");
                scanf("%d",&path);
                switch(path){
                case 1:
                    printf("Enter Customer Name\n:");
                    scanf("%s",name);
                    search_cname(name);
                break;
                case 2:
                    printf("Enter Customer ID\n:");
                    scanf("%d",&cid1);
                    search_cid(cid1);
                break;
                }
            break;
        case 4:
            printf("Enter Customer ID to Update \n");
            scanf("%d",&up);
            cust_Update(up);
            break;
        }
    }
    while(choice1!=5);
}
//printf("Customer Id: %d\nCustomer Name: %s\nCustomer City: %s\nCustomer Number: %ld\nCustomer Email: %s\n",cu[i].cid,cu[i].cname,cu[i].ccity,cu[i].cmob_no,cu[i].cemail);
//142

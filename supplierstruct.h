#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct supplier {
    int sup_id;
    char sup_name[50];
    char sup_city[50];
    long long int mob_no;
    char sup_email[50];
};
struct supplier s;
///////////////////SUPPLIER ENTRY//////////////////////////
void supp_entry(struct supplier *s,int n){
    FILE *fptr;
    fptr=fopen("Supplier.txt","a");
    if(fptr==NULL){
        printf("Error!!!!!!!!!");
    }
    for(int i=0;i<n;i++){
        printf("Supplier Id \tSupplier Name \tSupplier City \tSupplier Number \tSupplier Email\n:");
        scanf("%d\t%s\t%s\t%lld\t%s",&s[i].sup_id, s[i].sup_name, s[i].sup_city, &s[i].mob_no, s[i].sup_email);
        fprintf(fptr,"%d\t%s\t%s\t%lld\t%s\n",s[i].sup_id, s[i].sup_name, s[i].sup_city, s[i].mob_no, s[i].sup_email);
    }
    fclose(fptr);
    printf("\n|||Data Added Successfully|||\n");
    printf("********************************************\n");
}
//////////////////////////SUPPLIER LIST//////////////////////////////////////
void supp_list(){
    struct customerInfo cu;
    FILE *fptr;
    fptr=fopen("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Supplier.txt","r");
    if(fptr==NULL){
        printf("Unable to open file.\n");
        return;
    }
    while(fscanf(fptr,"%d%s%s%lld%s",&s.sup_id, s.sup_name, s.sup_city, &s.mob_no, s.sup_email) != EOF){
        printf("%d %s %s %lld %s\n",s.sup_id, s.sup_name, s.sup_city, s.mob_no, s.sup_email);
    }
    fclose(fptr);
}
////////////////////////SUPPLIER SEARCH/////////////////////////////////
void search_name(char name[]){
    struct supplier s;
    FILE *fptr;
    fptr=fopen("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Supplier.txt","r");
    if(fptr == NULL){
        printf("Unable to open file.\n");
        return;
    }
    while(fscanf(fptr,"%d%s%s%lld%s",&s.sup_id, s.sup_name, s.sup_city, &s.mob_no, s.sup_email) != EOF){
        if(strcmp(s.sup_name,name)==0){
            printf("Customer found\n");
            printf("%d %s %s %lld %s\n", s.sup_id, s.sup_name, s.sup_city, s.mob_no, s.sup_email);
        }
    }
    fclose(fptr);
}
void search_id(int cid1){
    struct supplier s;
    FILE *fptr;
    fptr=fopen("C:\\Users\\siddi\\Documents\\CCPP\\Miniproject\\Medical Store Management\\Supplier.txt","r");
    if(fptr == NULL){
        printf("Unable to open file.\n");
        return;
    }
    while(fscanf(fptr,"%d%s%s%lld%s", &s.sup_id, s.sup_name, s.sup_city, &s.mob_no, s.sup_email) != EOF){
        if(s.sup_id==cid1){
            printf("Customer found\n");
            printf("%d %s %s %lld %s\n", s.sup_id, s.sup_name, s.sup_city, s.mob_no, s.sup_email);
        }
    }
    fclose(fptr);
}
////////////////////////SUPPLIER UPDATE/////////////////////////////////
void supp_update(int up) {
    struct supplier s;
    FILE *fptr, *tmpfptr;
    fptr = fopen("Supplier.txt","r");
    tmpfptr = fopen("temp.txt", "w");
    if(fptr == NULL || tmpfptr == NULL){
        printf("Unable to open file.\n");
        return;
    }
    while(fscanf(fptr,"%d%s%s%lld%s", &s.sup_id, s.sup_name, s.sup_city, &s.mob_no, s.sup_email) != EOF){
        if(s.sup_id == up){
            printf("***Update Details***\n");
            printf("Supplier Id \tSupplier Name \tSupplier City \tSupplier Number \tSupplier Email\n:");
            scanf("%d\t%s\t%s\t%lld\t%s", &s.sup_id, s.sup_name, s.sup_city, &s.mob_no, s.sup_email);
        }
        fprintf(tmpfptr, "%d\t%s\t%s\t%lld\t%s\n", s.sup_id, s.sup_name, s.sup_city, s.mob_no, s.sup_email);
    }
    fclose(fptr);
    fclose(tmpfptr);
    // Delete the old file and rename the new file
    remove("Supplier.txt");
    rename("temp.txt", "Supplier.txt");
    printf("\n|||Updated Successfully|||\n");
}
////////////////////////SUPPLIER MENU///////////////////////////////////
void supplierMenu(){
    int path,cid1; char name[90];
    int choice1,n,up;
    struct supplier *s=NULL;
    do{
        printf("Enter Choice\n");
        printf("1.Supplier Entry \t2.Supplier List \t3.Supplier Search \t4.Supplier Update \t5.Exit\n:");
        scanf("%d",&choice1);
        printf("**************************************************\n");
        switch(choice1){
        case 1:
            printf("Enter number of Supplier/s to add\n:");
            scanf("%d",&n);
            struct supplier *s=(struct supplier*)malloc(n*sizeof(struct supplier));
            if(s==NULL)
                printf("Memory Not allocated!!!!\n");
            supp_entry(s,n);
            break;
        case 2:
            supp_list();
            break;
        case 3:
                printf("Search Supplier By 1.Name or 2.Supplier ID\n");
                scanf("%d",&path);
                switch(path){
                case 1:
                    printf("Enter Supplier Name\n:");
                    scanf("%s",name);
                    search_name(name);
                break;
                case 2:
                    printf("Enter Supplier ID\n:");
                    scanf("%d",&cid1);
                    search_id(cid1);
                break;
                }
            break;
        case 4:
            printf("Enter Supplier ID to Update \n");
            scanf("%d",&up);
            supp_update(up);
            break;
        }
    }
    while(choice1!=5);
}

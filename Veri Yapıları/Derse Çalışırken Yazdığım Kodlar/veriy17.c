# include<stdio.h>
# include <stdlib.h>

struct node{

    int data;
    struct node * next;
    struct node * prev;

};
struct node * next=NULL;
struct node * start=NULL;
struct node * temp=NULL;
struct node * prev=NULL;
struct node * temp2=NULL;


void basaEkle(int sayi){
    struct node * eleman=(struct node*) malloc(sizeof(struct node));
    eleman->prev=NULL;
    eleman->data=sayi;
    if(start==NULL){   
       start=eleman;
       start->next=NULL;
    }
    else{                 
        eleman->next=start;
        start=eleman;
    }
}

void sonaEkle(int sayi){
    struct node * eleman=(struct node*) malloc(sizeof(struct node));
    eleman->data=sayi;
    eleman->next=NULL;
    if(start==NULL){   
       start=eleman;
       start->next=NULL;    // tek elemanli liste
       start->prev=NULL;  
    }
    else{
        if(start->next==NULL){
            start->next=eleman;
            eleman->prev=start;

        }    
        else{
            temp=start;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=eleman;
            eleman->prev=temp;

        }             
        
    }
}

void bastanSil(){
    if(start==NULL){
        printf("Listede silinecek eleman yok!\n");
    }
    else{
        if(start->next==NULL){
            free(start);
            start=NULL;
        }
        else
        {
            temp=start->next;
            free(start);
            temp->prev=NULL;
            start=temp;
        }
        

    }
}

void sondanSil(){
    if(start==NULL){
        printf("Listede silinecek eleman yok!\n");
    }
    else{
        if(start->next==NULL){
            free(start);
            start=NULL;
        }
        else
        {
            temp=start;
            while(temp->next->next!=NULL){
                temp=temp->next;
            }
            temp2=temp;
            free(temp->next);
            temp2->next=NULL;
            
        }
        

    }
}


void listele(){
    if(start==NULL)
       printf("liste bos");
    else{
    temp=start;
    while(temp->next!=NULL){
        printf("  %d  -->",temp->data);
        temp=temp->next;
    }
    printf("  %d \n",temp->data);
}
}

int main(){
    while(1){
    int sayi, secim;
    printf("1- Basa eleman ekle\n");
    printf("2- Sona eleman ekle\n");
    printf("3- Bastan eleman sil\n");
    printf("4- Sondan eleman sil\n");
    printf("5- Eleman sayisi\n");
    printf("6- Elemanlarin toplami\n");
    printf("7- Listele\n");
    printf("Seciminizi yapiniz\n");
    scanf("%d",&secim);
    switch (secim){
        case 1:  printf("Basa eklenecek sayi:\n"); scanf("%d",&sayi);
        basaEkle(sayi);
        break;
        case 2:  printf("Sona eklenecek sayi:\n"); scanf("%d",&sayi);
        sonaEkle(sayi);
        break;

        case 3:  
        bastanSil();
        break;
        
        case 4:  
        bastanSil();
        break;

        case 7: listele();
        break;

            
    }
    





}
}
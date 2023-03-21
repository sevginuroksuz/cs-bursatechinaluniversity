# include<stdio.h>
# include <stdlib.h>

// tek yonlu bagli liste basa ve sona eleman ekleme

struct node{
    int data;
    struct node * next;

};

struct node * head=NULL;
struct node * temp=NULL;

void basaEkle(int num){
    struct node * eleman;
    eleman=(struct node*)malloc(sizeof(struct node));
    eleman->data=num;
    eleman->next=head;
    head=eleman;

}

void sonaEkle(int num){
    struct node * eleman;
    eleman=(struct node *) malloc (sizeof(struct node));
    eleman->data=num;
    eleman->next=NULL;

    if(head==NULL)
          head=eleman;
          else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=eleman;
          }
}

void yazdir(){
    temp=head;
    while(temp->next!=NULL){
        printf(" %d -->",temp->data);
        temp=temp->next;
    }
    printf(" %d ",temp->data);

}

int main(){
    int secim, x, t,sayi;
    printf("Kac elemanli tek yonlu abgli liste olusturmak istiyorsunuz?: \n ");
    scanf("%d",&x);
    while(t!=x){
        t++;
    printf("1- Basa eleman ekleme\n");
    printf("2- Sona eleman ekleme\n");
    printf("Seciminizi yapın:\n");
    scanf("%d",&secim);
    
    switch (secim)
    {
    case 1:
        printf("Sayiyi girin:\n");
        scanf("%d",&sayi);
         basaEkle(sayi);
         yazdir();
     break;
    
    case 2:
       printf("Sayiyi girin:\n");
        scanf("%d",&sayi);
         sonaEkle(sayi);
         yazdir();
    
        break;
    
    default:
        break;
    }
    }
    
}
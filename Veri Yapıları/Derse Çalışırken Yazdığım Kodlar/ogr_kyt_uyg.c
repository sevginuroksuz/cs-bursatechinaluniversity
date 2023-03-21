# include<stdio.h>
# include <stdlib.h>
# include<string.h>

// cift yonlu dogrusal bagli liste uygulamasi (ogrenci kayit)

//node *ogr=(node*) malloc(sizeof(node));

struct ogrenci{

    int No;
    char Ad[20];
    char Soyad[20];
    char Bolum[40];
    int Sinif;
    struct ogrenci * next;
    struct ogrenci * prev;


}; typedef struct ogrenci node;

node *head = NULL;
int cnt = 0;






void Add_Node(int no, char *ad, char *soyad, char *bolum, int sinif ){

    node *ogr=(node*) malloc(sizeof(node));
    ogr->No=no;
    strcpy(ogr->Ad,ad);
    strcpy(ogr->Soyad,soyad);
    strcpy(ogr->Bolum,bolum);
    ogr->Sinif=sinif;

    if(head==NULL)
    {
        head=ogr;
        head->next=head;
        head->prev=head;
        cnt++;
        printf("Listeye %d numarali ilk ogrenci eklendi \n", head->No);
    }
    else{
        node *temp= head;
        while(temp->next != head)  //En son dugum headi gostedigi icin heade kadar giden dongu olusturduk
             temp=temp->next;
  
        ogr->next=head;
        head->prev=ogr;
        head=ogr;        
        temp->next=head;
        head->prev=temp;
        cnt++;
        printf("Listeye %d numarali ogrenci eklendi \n", head->No);


    }
}

   
    void Delete_Node(){
        if(head==NULL)
        printf("Listede kayitli ogrenci yok!\n");
        else{
            int ogrNo;
            printf("Silmek istediginiz ogrenci no: \n");
            scanf("%d",&ogrNo);

            if(cnt==1 && (head->No == ogrNo)){
                
                printf("Listede kalan son ogrenci de silindi.\n");
                free(head);
                head=NULL;
                cnt--;

            }
            else if(cnt!=1 && (head->No == ogrNo)){

                node * temp1= head;
                while (temp1->next!=head)
                {
                    temp1=temp1->next;

                    node * temp2 = head->next;
                    free(head);
                    head=temp2;

                    head->prev=temp1;
                    temp1->next=head;
                    
                }

            }
            else{
                node *p=head;
                node *p2=head;
                node *p3=head;

                while(p->next!=head)
                {
                    if(p->No==ogrNo)
                    {
                        printf("%d numarali ogrenci silindi!",p->No);
                        p3=p->next;
                        free(p);
                        p2->next=p3;
                        p3->prev=p2;
                        cnt--;
                        break;

                    }
                   
                    p2=p;
                    p=p->next;

                }
                 if(p->No==ogrNo)
                    {
                        printf("%d numarali ogrenci silindi!",p->No);
                        free(p);
                        p2->next=head;
                        head->prev=p2;
                        cnt--;

                    }
            }

        }

    }


    void Display_List(){
        system("cls");
        if(head==NULL)
        {
            printf("Liste bos, yazdirilacak ogrenci yok.");
        
        }
        else
        {
            node *p=head;
            while(p->next!=head)
            {
                printf("Ogenci No: %d\nAd: %s\nSoyad: %s\nBolum: %s\nSinif: %d\n",p->No,p->Ad,p->Soyad,p->Bolum,p->Sinif);
                p=p->next;

            }
            printf("Ogenci No: %d\nAd: %s\nSoyad: %s\nBolum: %s\nSinif: %d\n",p->No,p->Ad,p->Soyad,p->Bolum,p->Sinif);
        }
    }
        
    
int main(){
    int secim, no, sinif,anahtar;
    char ad[20];
    char soyad[20];
    char bolum[20];

    while(1){
        printf("OGRENCI BILGI SITEMI\n");
        printf("1- Create link list\n");
        printf("2- Destroy linked list\n");
        printf("3- Add node\n");
        printf("4- Delete node\n");
        printf("5- Search node\n");
        printf("6- Display list (Traverse list)\n");
        printf("7- Exit\n");
        printf("Seciminizi yapin:\n");
        scanf("%d",&secim);
        switch (secim)
        {
        case 1:
            
            break;

            case 2:
              printf("Ogrenci no girin: \n");
              scanf("%d",&anahtar);
              // Destroy(anahtar);
            return 0 ;

            case 3:
            printf("Ogrenci no \n");
            scanf("%d",&no);
            printf("Ogrenci ad \n");
            scanf("%s",ad);
            printf("Ogrenci soyad \n");
            scanf("%s",soyad);
            printf("Ogrenci bolum \n");
            scanf("%s",bolum);
            printf("Ogrenci sinif \n");
            scanf("%d",&sinif);
            Add_Node(no,ad,soyad,bolum,sinif);
            return 0 ;

            case 4:
            Delete_Node();
            break;

            case 5:
            return 0 ;

            case 6:
            Display_List();
            break;

            case 7:
            return 0 ;
            
            
        
        default:  printf("Hatali giris yaptiniz!");
            
        }
      
       



    }



    return 0;
}
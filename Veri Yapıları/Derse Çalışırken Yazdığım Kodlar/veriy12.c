
// Sevgi Nur OKSUZ 
// 21360859073


# include<stdio.h>
# include <stdlib.h>
# include <string.h>

struct ogrenci
{
    int No;
    char Ad[20];
    char Soyad[20];
    char Bolum[40];
    int Sinif;
    struct ogrenci * next;
    struct ogrenci * prev;
}; 

typedef struct ogrenci node;

node *head = NULL;
node *last = NULL;
int cnt = 0;

void createList(int n)
{
    int c=n;
    int secim, no, sinif;
    char ad[20];
    char soyad[20];
    char bolum[20];
    void Add_Iter(int no, char *ad, char *soyad, char *bolum, int sinif ){

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
        c--;
        printf("Listeye %d numarali ilk ogrenci eklendi \n", head->No);
    }
    else{
        node *temp= head;
        while(temp->next!=head)  //En son dugum headi gostedigi icin heade kadar giden dongu olusturduk
             temp=temp->next;
            ogr->next=head;
            head->prev=ogr;
            head=ogr;        
            temp->next=head;
            head->prev=temp;
            c--;
            printf("Listeye %d numarali ogrenci eklendi \n", head->No);


    }
}
    while(c!=0)
    {
        printf("Student number: \n");
            scanf("%d",&no);
            printf("Student name:\n");
            scanf("%s",ad);
            printf("Student surname: \n");
            scanf("%s",soyad);
            printf("Student department: \n");
            scanf("%s",bolum);
            printf("Student grade: \n");
            scanf("%d",&sinif);
            Add_Iter(no,ad,soyad,bolum,sinif);


    }
}
    

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
        printf("The first student with number %d has been added to the list!\n", head->No);
    }
    else{
        node *temp= head;
        while(temp->next!=head)  //En son dugum headi gostedigi icin heade kadar giden dongu olusturduk
             temp=temp->next;

        
        ogr->next=head;
        head->prev=ogr;
        head=ogr;        
        temp->next=head;
        head->prev=temp;
        cnt++;
        printf("Added student number %d to the list!\n", head->No);


    }
}


void deleteList()
{
    if(head==NULL)
        printf("No list to delete!\n");    
    else
    {
            if(cnt==1){
                free(head);
                head=NULL;
                cnt--;
                printf("List is deleted!\n");
            }
            else if(cnt!=1){

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
                printf("List is deleted!\n");
            }            
            }
    }
   

void Delete_Node(){
        if(head==NULL)
        printf("No students registered!\n");
        else{
            int ogrNo;
            printf("Student number you want to delete: \n");
            scanf("%d",&ogrNo);

            if(cnt==1 && (head->No == ogrNo)){
                
                printf("The last student left on the list was also deleted.\n");
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
                        printf("Student number %d has been deleted!",p->No);
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
                        printf("Student number %d has been deleted!",p->No);
                        free(p);
                        p2->next=head;
                        head->prev=p2;
                        cnt--;
                    }
            }
        }
    }


void Display_List(){
        if(head==NULL)
        {
            printf("The list is empty, there are no elements.\n");
        
        }
        else
        {
            node *p=head;
            while(p->next!=head)
            {
                printf("Student number: %d\nName: %s\nSurname: %s\nDepartment: %s\nGrade: %d\n",p->No,p->Ad,p->Soyad,p->Bolum,p->Sinif);
                printf("\n");
                p=p->next;

            }
            printf("\n");
            printf("Student number: %d\nName: %s\nSurname: %s\nDepartment: %s\nGrade: %d\n",p->No,p->Ad,p->Soyad,p->Bolum,p->Sinif);
        }
    }
        

void Search()  
{  
    node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->No == item)  
            {  
                printf("\nItem found at location %d ",i+1);
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}    


int main()
{
    int secim, no, sinif,anahtar,c;
    char ad[20];
    char soyad[20];
    char bolum[20];

    while(1)
    {
        printf("\n*****************************\nSTUDENT INFORMATION SYSTEM\n*****************************\n");
        printf("1- Create link list\n");
        printf("2- Destroy linked list\n");
        printf("3- Add node\n");
        printf("4- Delete node\n");
        printf("5- Search node\n");
        printf("6- Display list (Traverse list)\n");
        printf("7- Exit\n");
        printf("Make your choice:\n");
        scanf("%d",&secim);

        switch (secim)
        {
        case 1:
            printf("How many elements is a list: \n");
            scanf("%d",&c);
            createList(c);
            break;

            case 2:
              deleteList();
            break;

            case 3:
            printf("Student number: \n");
            scanf("%d",&no);
            printf("Student name: \n");
            scanf("%s",ad);
            printf("Student surname: \n");
            scanf("%s",soyad);
            printf("Student department: \n");
            scanf("%s",bolum);
            printf("Ogrenci grade: \n");
            scanf("%d",&sinif);
            Add_Node(no,ad,soyad,bolum,sinif);
            break;

            case 4:
            Delete_Node();
            break;

            case 5:
            Search();
            break;

            case 6:
            Display_List();
            break;

            case 7:
            return 0;
            
        default:  printf("You entered incorrectly!\n");   
        }
      
    }
    return 0;
}
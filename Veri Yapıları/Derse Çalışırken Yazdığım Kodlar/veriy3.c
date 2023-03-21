# include <stdio.h>
# include <stdlib.h>

struct dugum{
    int veri;
    struct dugum * gosterici;

};

   struct dugum * bas=NULL;
   struct dugum *gecici=NULL;

   void basaEkle(int sayi){   // basaEkle fonksiyonu 
    struct dugum * eklenecek;    // dugum olusturduk
    eklenecek=(struct dugum*) malloc (sizeof(struct dugum));
    eklenecek->veri=sayi;
    eklenecek->gosterici=bas;
    bas=eklenecek;   // basa ekledigimiz icin eklenen dugum bas dugum oldu
   }

   void yazdir(){
    gecici=bas;
    
    while(gecici->gosterici!=NULL){
        
        printf(" %d --> ",gecici->veri);
        gecici=gecici->gosterici;

    }
            printf(" %d ",gecici->veri);
   }

 // girilen elemanlarda en son girdigimiz sayi en basa alinacak cunku basa eleman ekleme islemi yapiyoruz.

int main(){
    int sayi,x=0, t;
    printf("Kac elemanli bagli liste olusturacaksiniz?: \n"); 
    scanf("%d",&t);
    while(x!=t){
    printf("Bir sayi giriniz: \n");
    scanf("%d",&sayi);
    basaEkle(sayi);
    x++;

    }
    yazdir();

    return 0;
}
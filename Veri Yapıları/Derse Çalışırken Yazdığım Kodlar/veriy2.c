# include <stdio.h>
# include <stdlib.h>

// Tek yonlu dogrusal bagli liste sona eleman ekleme 

struct dugum{      // struct yapisi

    int veri;
    struct dugum * gosterici;

};

   struct dugum * bas=NULL;      // bas dugum
   struct dugum * gecici=NULL;    // degisikilikleri yapmamizi saglayacak dugum


   void sonaEkle(int sayi){    // dugum eklemeyi saglayacak fonksiyon

    struct dugum * son;                          
    son=(struct dugum*) malloc (sizeof(struct dugum));
    son->veri=sayi;
    son->gosterici=NULL;
    
    if(bas==NULL){    
        bas=son;    // listede dugum yoksa eklenen dugum ilk dugume esittir

    }
    else{
        gecici=bas;    // listede baska elemanlar varsa gecici dugum yardimiyla liste son elemanina gelene kadar sonsuz dongude gezilir.
        while(gecici->gosterici!=NULL){
            gecici=gecici->gosterici;  
        }
        gecici->gosterici=son;  // son dugumu buldugunda eklenecek dugumu gecici dugume isaret ettiriyoruz

    }
   }

    void yazdir(){ // ilk dugumden itibaren son dugumde dahil NULL gorene kadar yazdiran fonksiyonu yazdik
        gecici=bas;       
        while(gecici->gosterici!=NULL){    
        printf(" %d ->", gecici->veri);
        gecici=gecici->gosterici;

        }
        printf(" %d ", gecici->veri);  // son dugum yazdirilmasi icin (son dugum NULL'i isaret ettigi icin while dongusunde yazdirilmaz)
        

    }
  
   
int main(){

    int i=0;
    while(i!=7){  // 7 elemanli tek yonlu dogrusal bagli liste olusturulup yazdirilir
        int Sayi;
        printf("Bir sayi giriniz: \n");
        scanf("%d",&Sayi);
        sonaEkle(Sayi);
        i++;
    }
    
       yazdir();

    return 0;
}
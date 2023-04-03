#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 20

int Oyun()




int main()
{

int k=0,l=0, i;
int T=1;
int K=2;
int M=3;
int bilgisayar;
int secim;
int Oyuncu[N], Bilgisayar[N];
srand(time(0));
printf("Tas=1 , Kagit= 2, ve Makas= 3\n");

for(i=0; i<20; i++){
        bilgisayar=rand()%3+1;
        Bilgisayar[i]=bilgisayar;

        for(i=0; i<20;i++){
        Oyuncu[i]=secim;
        printf("Seciminizi Girin:");
        scanf("%d",&secim);

if(secim==1){
if(bilgisayar==1){

printf("Bilgisayar:%d Oyuncu:%d\n",k,l);
}
if(bilgisayar==2){
     k++;
printf("Bilgisayar:%d Oyuncu:%d\n",k,l);

}
if(bilgisayar==3){
    l++;
printf("Bilgisayar:%d Oyuncu:%d\n",k,l);

}
}
else  if(secim==2){
if(bilgisayar==2){
printf("Bilgisayar:%d Oyuncu:%d\n",k,l);
}
if(bilgisayar==3){
    k++;
printf("Bilgisayar:%d Oyuncu:%d\n",k,l);
}
if(bilgisayar==1){
    l++;
printf("Bilgisayar:%d Oyuncu:%d\n",k,l);

}
}
else if(secim==3){
if(bilgisayar==3){
printf("Bilgisayar:%d Oyuncu:%d\n",k,l);
}
if(bilgisayar==2){
    l++;
printf("Bilgisayar:%d Oyuncu:%d\n",k,l);

}
if(bilgisayar==1){
    k++;
printf("Bilgisayar:%d Oyuncu:%d\n",k,l);

}
}
else{
printf("Hatali Giris Yaptiniz\n");
}


if(k==5 ){
printf("Bilgisayar Kazandi.  Skor:%d-%d\n",k,l);
}
else if(l==5 ){
printf("Oyuncu Kazandi.  Skor:%d-%d\n",l,k);
}
}
}




   return 0;

}

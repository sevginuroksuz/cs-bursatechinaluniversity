# include <stdio.h>
# include <stdlib.h>

/*Girilen sayinin karesini alan fonksiyonu yaziniz.*/

int kareal(int x){
    int kare=x*x;
    return kare;
}

int main(){
    int sayi;

    printf("Karesini almak istediginiz sayiyi giriniz: \n");
    scanf("%d",&sayi);

    printf("Sayinin karesi: %d",kareal(sayi));



    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#define limit 200

typedef struct KUYRUK {
    int sayi;
    struct KUYRUK *sonraki;
} kuyruk;

kuyruk *ilk = NULL, *son, *yeni, *sil;

void menu();
void ekle(int);
void cikar();
void bekle();
void listele();
void ekranTemizle();

int main() {

    while (1) {
        menu();
    }
    return 0;
}

void menu() {
    int sayi;

    printf("******Menu******\n");
    printf("1)Ekle\n");
    printf("2)Cikar\n");
    printf("3)Listele\n");
    printf("4)Cikis\n");
    int secenek;
    printf("Tercih: ");
    scanf("%d", &secenek);
    ekranTemizle();
    switch (secenek) {
        case 1:
            printf("Sayi giriniz: ");
            scanf("%d", &sayi);
            ekle(sayi);
            break;
        case 2:
            cikar();
            break;
        case 3:
            listele();
            break;
        case 4:
            printf("Program Sonlandirildi!\n");
            exit(0);
            break;
        default:
            printf("Hatali Secim!\n");
    }
    bekle();
}

void ekle(int sayi) {
    yeni = (kuyruk*) malloc(sizeof (kuyruk));
    yeni->sayi = sayi;
    yeni->sonraki = NULL;

    if (ilk == NULL) {
        ilk = (kuyruk *) malloc(sizeof (kuyruk));
        ilk = yeni;
        son = ilk;
    } else {
        son->sonraki = yeni;
        son = son->sonraki;
    }

}

void cikar() {
    if (ilk == NULL) {
        printf("Kuyruk bos\n");
    } else {
        sil = (kuyruk*) malloc(sizeof (kuyruk));
        sil = ilk;
        ilk = ilk->sonraki;
        printf("%d Kuyruktan cikarildi\n", sil->sayi);
        free(sil);
    }

}

void bekle() {
    printf("Devam etmek icin Enter'a basiniz!\n");

    //klavyeden okuma atlamasinin onune gecmek icin 2 kere yazildi
    getchar();
    getchar();
    ekranTemizle();

}

void listele() {
    if (ilk == NULL) {
        printf("Kuyruk Bos\n");
    } else {
        kuyruk *gecici = ilk;
        while (gecici != NULL) {
            printf("%d ", gecici->sayi);
            gecici = gecici->sonraki;
        }
        printf("\n");
    }

}

void ekranTemizle() {
    //windows icin
    system("cls");
    //linux icin
    //system("clear");
}

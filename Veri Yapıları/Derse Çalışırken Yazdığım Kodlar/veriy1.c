# include <stdio.h>
# include <stdlib.h>


struct dugum{        // yapi olusturma
    int veri;
    struct dugum * gosterici; 


};

int main(){
    struct dugum * bir;       // dugum olusturduk
    bir = (struct dugum *) malloc (sizeof(struct dugum));   // bellekte yer ayırtma

    struct dugum * iki;
    iki = (struct dugum *) malloc (sizeof(struct dugum));

    struct dugum * uc;
    uc = (struct dugum *) malloc (sizeof(struct dugum));

    struct dugum * dort;    
    dort = (struct dugum *) malloc (sizeof(struct dugum));


    bir -> veri=11;    // veri girisi 
    bir ->gosterici=iki;    // bir sonraki dugumu gosterdik

    iki ->veri=22;
    iki -> gosterici=uc;

    uc->veri=33;
    uc -> gosterici=NULL;

    dort->veri=44;
    dort -> gosterici=NULL;

    printf("%d -> %d -> %d -> %d", bir->veri, iki->veri, uc->veri, dort->veri);   // dogrusal listeyi ekrana yazdirdik
    
    


    return 0;
}

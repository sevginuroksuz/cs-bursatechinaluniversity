#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    a=b=c=d=0;
    printf("a, b, c sayilarini aralarina bosluk birakarak giriniz: ");
    scanf("%d %d %d", &a, &b, &c);

   //d = (a==1) ? (b==10) ? d : (b==20) ? -1 : -2 : (a==2 || a==3) ? 11. (c==100 || c==200) ? -3 : (c==300) ? -4 : -5 : -6 ;
   //Yukarýdaki ternary ifadeyi switch case ile tanýmlýyoruz.

    switch(a){
    case 10:
    break;
    switch(b){
    case 20:
    d=-1;
    break;
    default:
        d=-2;
    }
    case 2:
    case 3:
    break;
    switch(c){
    case 100:
    case 200:
        d=-3;
        break;
    case 300:
        d=-4;
    default:
        d=-5;
        }
    default:
        d=-6;
  }

    printf("d: %d\n", d);

    return 0;
}

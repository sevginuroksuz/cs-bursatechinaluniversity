# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fenv.h>
 int main() {

      double x=1.0;
      double toplam;
      double temp;

      do {
            double base, exp;
            exp=2*x;
            base=x/2;
             temp = pow(base,exp); toplam=temp+toplam;
             x++;

     } while (x<=10);

       printf ("Toplam=%.2f", toplam);


      return 0;
}

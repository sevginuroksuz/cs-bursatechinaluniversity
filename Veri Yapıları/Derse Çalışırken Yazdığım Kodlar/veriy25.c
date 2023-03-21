
/*Sevgi Nur Oksuz   21360859073 */

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <conio.h>
# define size 100

 
 char stack [size];
 int top;

 void push(char data)   //stacke verileri atar
 {
    if(top +1 == size)
       puts("Stack dolu!");
    else
      stack[++top]=data;
 }

 char peek()      // karsilastirma icin kullanicaz
 {
    return stack[top];
 }

 char pop()       // stackten eleman cikartir
 {
    return stack[--top];
 }

 bool isEmpty()
 {
    if(top==0)
        return true;
    else
       return false;
 }

 void Print(char d[], int n)
 {
    for(int j=0; j<n; j++)
      if(d[j] != '\0')
      {
         printf("%c  ",d[j]);
         
      }
       

 }

 bool balanced(const char p[], size_t n)
 {
    int i;
    while(p[i] != '\0')
    {
        char d = p[i];
        if(d == '(' || d == '{' || d == '[')
        {
          push(d);
          printf("Data: %c\n",d);
          printf("Push edildi: %c\n", d);
        }
        else if( d == ')' || d == '}' || d == ']')
        {
            char peekd = peek();

            printf("Data: %c\n",d);
            printf("Peek edildi: %c\n", peekd);

            if(isEmpty() == true)
            {
                puts("Stack bostur.\n");
                return false;
            }
      
            if(d == ')' && peekd == '(' )
                 pop();
                 else if(d == '}' && peekd == '{')
                     pop();
                     else if(d == ']' && peekd =='[')
                       pop();
                       else
                         return false;
                 
        }
       i+=1;   
    }
      return isEmpty();
 }


int main()
{
    char dizi[size];
    printf("***************************************\n");
    printf("PARANTEZ ESLESTİRME\n");
    puts("Karakterleri giriniz: ");
    fgets(dizi,sizeof(dizi),stdin);


    if(balanced(dizi,size)==true)
        puts("\nDogru");
    
    else
         puts("\nYanlis");
         printf("GIRILEN DEGERLER\n");
         Print(dizi, size);

  
    return 0;
}

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <conio.h>
# define boyut 10

 char dizi[boyut];
 char stack [boyut];
 int tepe;

 void push(char data)   //stacke verileri atar
 {
    if(tepe +1 == boyut)
       puts("Stack dolu!");
    else
      stack[++tepe]=data;
 }

 char peek()      // karsilastirma icin kullanicaz
 {
    return stack[tepe];
 }

 char pop()       // stackten eleman cikartir
 {
    return stack[--tepe];
 }

 bool isEmpty()
 {
    if(tepe == 0)
        return true;
    else
       return false;
 }

 void Print()
 {
    for(int j=0; j<tepe; j++)
      printf("Stack: %c\n",stack[j]);

 }

 bool balanced()
 {
    int i;
    while(dizi[i] != '\0')
    {
        char d = dizi[i];
        printf("Data: %c\n",d);

        if(d=='(' || d=='{' || d=='[')
        {
          push(d);
          printf("Push edildi: %c\n", d);
        }
        else if(d==')' || d=='}' || d==']')
        {
            char peekd = peek();
            printf("Peek edildi: %c\n", peekd);
            if(isEmpty()==true)
            {
                puts("Stack bostur.\n");
                return false;
            }
         

            if((d==')' && peekd=='(') || (d=='(' && peekd==')'))
                 pop();
                 else if((d=='}' && peekd=='{') || (d=='{' && peekd=='}'))
                     pop();
                    else if((d==']' && peekd=='[') || (d=='[' && peekd==']'))
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
    
    puts("Karakterleri giriniz: \n");
    fgets(dizi,sizeof(dizi),stdin);

    if(balanced()== true)
        puts("Dogru\n");
    
    else
         puts("Yanlis\n");

  
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define size 100

char stack[size];
int top = -1;  // top başlangıç değeri

void push(char data)   //stacke verileri atar
{
    if(top + 1 == size)
        puts("Stack dolu!");
    else
        stack[++top] = data;
}

char peek()      // karsilastirma icin kullanicaz
{
    return stack[top];
}

char pop()       // stackten eleman cikartir
{
    return stack[top--];
}

bool isEmpty()
{
    return top == -1;
}

void Print(char d[], int n)
{
    for(int j = 0; j < n; j++)
        if(d[j] != '\0')
            printf("%c  ", d[j]);
}

bool balanced(const char p[], size_t n)
{
    int i = 0;  // i değişkenine başlangıç değeri verildi
    while(p[i] != '\0')
    {
        char d = p[i];
        if(d == '(' || d == '{' || d == '[')
        {
            push(d);
            printf("Data: %c\n", d);
            printf("Push edildi: %c\n", d);
        }
        else if(d == ')' || d == '}' || d == ']')
        {
            if(isEmpty())
            {
                puts("Stack bostur.\n");
                return false;
            }

            char peekd = peek();
            printf("Data: %c\n", d);
            printf("Peek edildi: %c\n", peekd);

            if((d == ')' && peekd == '(') || 
               (d == '}' && peekd == '{') || 
               (d == ']' && peekd == '['))
            {
                pop();
            }
            else
            {
                return false;
            }
        }
        i++;
    }
    return isEmpty();
}

int main()
{
    char dizi[size];
    printf("***************************************\n");
    printf("PARANTEZ ESLESTIRME\n");
    puts("Karakterleri giriniz: ");
    fgets(dizi, sizeof(dizi), stdin);

    if(balanced(dizi, size))
        puts("\nDogru");
    else
        puts("\nYanlis");

    printf("GIRILEN DEGERLER\n");
    Print(dizi, size);

    return 0;
}

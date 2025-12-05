#include <stdio.h>

int anahtar, i;
char metin[100];

int main(){
    printf("Metin gir: ");
    fgets(metin, 100, stdin);

    printf("Anahtarı girin: (Kaç harf kaydırılacak?)    ");
    scanf("%d", &anahtar);

    for(i=0; metin[i]!= '\0'; i++){
        if(metin[i]>='A' && metin[i]<='Z'){
            
            metin[i]= ((metin[i] - 65 + anahtar) % 26) + 65;

        } if(metin[i]>= 'a' && metin[i]<= 'z'){
            
            metin[i]= ((metin[i] -97+ anahtar) % 26) + 97;
        }
    }
    printf("Yeni metin: %s", metin);




    return 0;
}
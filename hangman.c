#include <stdio.h>
#include <string.h>

int lng, i, can, dogru, gameOver;

int main(){
    char gizliKelime[]= "BİLGİSAYAR";   
    lng= strlen(gizliKelime);
    int bulunduMu[lng];

    for(i=0; i<lng;i++){
        bulunduMu[i]=0;
        printf("_");
    }
    printf("\n");

    char tahmin;
    can = 5;
    dogru=0;
    gameOver=0;

    while(can>0 && gameOver==0){
        printf("Bir harf gir(büyük harfle): ");
        scanf(" %c", &tahmin);
        
        for(i=0; i<lng;i++){
            if(gizliKelime[i]== tahmin){
                bulunduMu[i]=1;
                dogru=1;
            }
        }
        if(dogru==1){
            printf("Tahmin doğru! \n");
            dogru=0;
        }else{
            can--;
            printf("Yanlış tahmin! Kalan can: %d \n",can);
        }
        gameOver=1;

        for(i=0; i<lng; i++){
            if(bulunduMu[i]==1){
                printf("%c",gizliKelime[i]);
                
            } else {
                printf("_");
                gameOver=0;
            }
        }
        printf("\n");

    }
    if(gameOver==1){
        printf("\nKazandın!");
    }else{
        printf("\nKaybettin! Kelime şuydu: %s", gizliKelime);
    }


    return 0;
}
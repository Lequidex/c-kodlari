#include <stdio.h>
#include <string.h>

int  i, j, ciro, secilenSira, secilenKoltuk;
int salon[7][10];

void biletAl(){
    printf("Önce istediğiniz sırayı ve ardından koltuk numarasını yazınız. ");
            scanf("%d", &secilenSira);
            scanf("%d", &secilenKoltuk);
            i=secilenSira-1;
            j=secilenKoltuk-1;
            
            if (salon[i][j]==0) {
                salon[i][j]=1;
                printf("İşlem Başarılı! ");
            } else {
                printf("Seçtiğiniz koltuk dolu!. \n");
            }
}

void salonGoruntule(){
    printf("------SAHNE------ \n 1  2  3  4  5  6  7  8  9  10 \n");
            for (i=0;i<2;i++){
                for(j=0;j<10;j++){
                    if(salon[i][j]==1){
                        printf("[X]");
                    } else {
                        printf("[ ]");
                    }
                }
                printf(" %d. sıra (VIP) \n",i+1);
            }
            for (i=2;i<7;i++){
                for(j=0;j<10;j++){
                    if(salon[i][j]==1){
                        printf("[X]");
                    } else {
                        printf("[ ]");
                    }
                }
                printf(" %d. sıra \n",i+1);
            }
}

void ciroHesapla(){
    ciro = 0;
            
    for (j=0;j<10;j++){
        for(i=0;i<7;i++){
            if(salon[i][j]==1){
                if(i<2){
                    ciro= ciro+100;
                } else {
                    ciro = ciro+50;
                }
            }
        }
                
    }
    printf("Toplam Ciro: %dTL \n",ciro);

}

void gunuBitirVeKaydet() {
    FILE *dosya;
    dosya = fopen("gun_sonu.txt", "w"); // Dosyayı yazma modunda aç

    if(dosya == NULL) {
        printf("Hata: Dosya olusturulamadi!\n");
        return;
    }

    // 1. Önce Ciroyu Yazalım
    fprintf(dosya, "=============================\n");
    fprintf(dosya, "      GUN SONU RAPORU        \n");
    fprintf(dosya, "=============================\n");
    fprintf(dosya, "TOPLAM CIRO: %d TL\n\n", ciro);

    // 2. Şimdi de Salonun Son Halini Çizelim
    // (Bak burası senin salonGoruntule fonksiyonunun kopyası, sadece fprintf oldu)
    
    fprintf(dosya, "------ SALON DURUMU ------\n");
    
    for (i = 0; i < 7; i++) {       // 7 Satırı gez
        for (j = 0; j < 10; j++) {  // 10 Koltuğu gez
            
            if(salon[i][j] == 1) {
                fprintf(dosya, "[X] "); // Doluysa dosyaya X yaz
            } else {
                fprintf(dosya, "[ ] "); // Boşsa dosyaya kutu yaz
            }
        }
        // Satır bitince dosyanın içinde alt satıra geç
        if(i < 2) 
            fprintf(dosya, " (VIP - Sira %d)\n", i+1);
        else 
            fprintf(dosya, " (Sira %d)\n", i+1);
    }
    
    fprintf(dosya, "=============================\n");

    fclose(dosya); // Dosyayı kapatmayı sakın unutma!
    
    printf("\n>>> Rapor 'gun_sonu.txt' dosyasina kaydedildi. <<<\n");
    printf(">>> Program kapaniyor. Iyi aksamlar! <<<\n");
}

int main(){
    int menu;

    for(i=0; i<7;i++){
        for(j=0;j<10;j++){
            salon[i][j]=0;
        }
    }
    
    
    printf("Sinema Bilet Sistemi: \n 1- Bilet Al   2- Salonu Görüntüle   3- Ciro Hesapla   4- Çıkış ");
    scanf("%d", &menu);

    while (menu!=5){
        if(menu==1){
            biletAl();

        }else if(menu==2){   
            salonGoruntule();

        }else if(menu==3){
            ciroHesapla();

        }else if(menu==4){ 
            gunuBitirVeKaydet();
        }else {
            
            printf("Hatalı işlem!");
        
        }
        
        printf("Yeni işlem? 1- Bilet Al   2- Salonu Görüntüle   3- Ciro Hesapla   4- Çıkış ");
        scanf("%d",&menu);
    }
    
return 0;
}
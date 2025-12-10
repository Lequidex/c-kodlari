#include <stdio.h>

int main() {
    int harfSayisi, i;
    char tarananHarf;
    char metin[1000];

    printf("Metin girin: ");
    fgets(metin, 1000, stdin);

    for (i = 0; metin[i] != '\0'; i++) {
        if (metin[i] >= 'A' && metin[i] <= 'Z') {
            metin[i] = metin[i] + 32;
        }
    }

    for (tarananHarf = 'a'; tarananHarf <= 'z'; tarananHarf++) {
        harfSayisi = 0;

        for (i = 0; metin[i] != '\0'; i++) {
            if (metin[i] == tarananHarf) {
                harfSayisi++;
            }
        }

        if (harfSayisi > 0) {
            printf("%c harfi %d kere kullanılmış.\n", tarananHarf, harfSayisi);
        }
    }

    return 0;
}

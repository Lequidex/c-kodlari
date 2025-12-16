#include <stdio.h>

int main(){
    int charCount, i, j, left, right, isPalindome, bestStart, len, bestLen;
    char text[100];

    printf("Metin girin: ");
    scanf("%s", text);
    
    charCount = 0;

    for(i=0; text[i] != '\0'; i++){
        charCount++;
    }
    
    bestLen=0;
    bestStart=0;

    for(i=0; i<charCount; i++){
        isPalindome=1;
        left= i;
        right= i;

        while(isPalindome==1 && left>=0 && right<=charCount-1){
            if(text[left] == text[right]){
                left--;
                right++;
                len= right - left - 1;
                if(len > bestLen){
                    bestLen= len;
                    bestStart= left+1;
                }
            } else{
                isPalindome=0;
            }
        }
        left= i;
        right= i+1;
        isPalindome=1;

        while(isPalindome==1 && left>=0 && right<=charCount-1){
            if(text[left] == text[right]){
                left--;
                right++;
                len= right - left - 1; 
                if(len > bestLen){
                    bestLen= len;
                    bestStart= left+1;
                }
            } else{
                isPalindome=0;
            }
        }
    }
    for(j=bestStart; j<bestStart+bestLen; j++){
        printf("%c", text[j]);
    }
    



    return 0;
}
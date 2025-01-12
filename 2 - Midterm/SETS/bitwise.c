#include <stdio.h>

void displayBitPattern(int);
int extractNthBit(int x, int pos);

int main(){
    displayBitPattern(78);
    printf("\n");
    displayBitPattern(79);
    printf("\n");
    displayBitPattern(4);
    int val = extractNthBit(79, 4);
    printf("\n");
    printf("The 4th bit of 79 is %d\n", val);
    displayBitPattern(val);
    return 0;
}


void displayBitPattern(int val){
    int bit = (sizeof(val) * 2) - 1;
    unsigned int masked;
    for(masked = 1 << bit; masked > 0; masked >>= 1){
       if((bit + 1) % 4 == 0){
        printf(" ");
       }
        printf("%d", (val & masked) ? 1 : 0);
        bit--;
    }
}


int extractNthBit(int x, int pos){
  return(x & pos);
}

#include <stdio.h>

typedef struct {
    int value; /* 値*/
    int *p_next; /* 配列番号 */
}list;



int main() {
    list data1;
    list data2;
    
    
    data1.value = 1000;
    data2.p_next = &hogeta2.value;
    data2.value = 500;
    printf("value %d\n", data1.value);
    printf("position %d\n", data1.p_next);

 /* ブランチの実験でコメントを追加した。*/


    return 0;
}
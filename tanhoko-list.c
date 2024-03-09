#include <stdio.h>

typedef struct {
    int value; /* 値*/
    int *p_next; /* 配列番号 */
}list;



int main() {
    list data1;
    list data2;
    list data3;
    
    
    data1.value   = 1;
    data1.p_next  = &data2;
    data2.value   = 2;
    data2.p_next  = &data3;
    data3.value   = 3;
    data3.p_next  = NULL; 

    printf("value %d\n", data1.value);
    printf("position %d\n", data1.p_next);


    return 0;
}
#include <stdio.h>

typedef struct {
    int value; /* 値*/
    int *p_position; /* 配列番号 */
}list;

/*gitについも勉強していく*/

int main() {
    list hogeta1;
    list hogeta2;
    hogeta1.value = 1000;
    hogeta1.p_position = &hogeta2.value;
    hogeta2.value = 500;
    printf("value %d\n", hogeta1.value);
    printf("position %d\n", hogeta1.p_position);


    return 0;
}
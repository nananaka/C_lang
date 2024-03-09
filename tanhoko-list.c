#include <stdio.h>

typedef struct {
    int value; /*値*/
    int *p_next; /* 次のデータへのポインタ */
}list;

/*リストの中身をすべて表示する関数*/
void show_all_data(list *p_list_head){

    list *p_list_pointer = p_list_head;
    
    while(p_list_pointer != NULL){
        printf("%d \n",p_list_pointer->value);
        p_list_pointer = p_list_pointer->p_next;
    }
}



int main() {
    list *p_list_head; /*リストの先頭ポインタ*/
    list data1;
    list data2;
    list data3;
    
    
    p_list_head   = &data1;
    data1.value   = 1;
    data1.p_next  = &data2;
    data2.value   = 2;
    data2.p_next  = &data3;
    data3.value   = 3;
    data3.p_next  = NULL; 

    show_all_data(p_list_head);
   

    return 0;
}
// -*- coding: utf-8 -*-

#include <stdio.h>

typedef struct list_ {
    int value; /*値*/
    struct list_ *p_next; /* 次のデータへのポインタ */
}list;

/*リストの中身をすべて表示する関数*/
void show_all_data(list *p_list_head){

    list *p_list_pointer = p_list_head;
    printf("-----------current_list--------------\n");
    while(p_list_pointer != NULL){
        printf("%d",p_list_pointer->value);
        printf("  (address : %d) \n",p_list_pointer); 
        p_list_pointer = p_list_pointer->p_next;
    }
}


/*リストの最後尾にデータを加える*/
void push_data(list *p_list_head, list *p_new_data){


    /*pushする前のリストを表示*/
    show_all_data(p_list_head);

    /*push処理*/
    list *p_list_pointer = p_list_head;

    while(p_list_pointer->p_next != NULL){/*p->nextがリスト最後尾の状態へ*/
         p_list_pointer = p_list_pointer->p_next;  
    }
    
    p_list_pointer->p_next = p_new_data ;/*最後尾の状態となったp->nextにp_new_dataを格納*/
    
    p_new_data->p_next = NULL;
    p_new_data->value = 4;

    /*pushした値を表示*/
    printf("%d",p_new_data->value);
    printf("  (address : %d) <-  NOW PUSHED \n",p_new_data); 

}


/*指定したvalueがリストの何番目にあるかを表示する*/
void reference_data(list *p_list_head, int reference_value){
    list *p_list_pointer = p_list_head;

     int i_element = 0; /*リストの要素の順序*/
     while(p_list_pointer != NULL){
        i_element ++;
        if(p_list_pointer->value == reference_value){
            printf("The value of %d is in  %d place. \n",reference_value, i_element);
        }
        p_list_pointer = p_list_pointer->p_next; 
    }
}

/*要素の順番を指定し、その値を削除する*/
void delete_data(list *p_list_head, int list_order_number){
    list *p_list_pointer = p_list_head;
    int i_element = 1; /*リストの要素の順序*/


    /*削除したいデータの一つ手前までp_list_pointerを移動*/
    while(i_element <= list_order_number - 2){
         i_element ++;
         p_list_pointer = p_list_pointer->p_next;   
    }
    /*whileを抜けた時点でp_list_pointerが削除したいデータの一つ手前をさした状態となる*/

    /*削除したいデータの一つ手前のデータのp_nextを削除したいデータの一つ後につなげる。*/
    p_list_pointer->p_next = (p_list_pointer->p_next)->p_next;
    printf("The %d data has been deleted.\n",list_order_number);

}


int main() {
    list *p_list_head; /*リストの先頭ポインタ*/
    list data1;
    list data2;
    list data3;
    list data4;
    
    p_list_head   = &data1;
    data1.value   = 1;
    data1.p_next  = &data2;
    data2.value   = 2;
    data2.p_next  = &data3;
    data3.value   = 3;
    data3.p_next  = NULL; 



    show_all_data(p_list_head);

    push_data(p_list_head, &data4);
    reference_data(p_list_head, 3);
    /*printf("push完了")；*/
    show_all_data(p_list_head);
    delete_data(p_list_head, 3); /*3番目のデータを削除*/
    show_all_data(p_list_head);

    return 0;
}
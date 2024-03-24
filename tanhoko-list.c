#include <stdio.h>


/*list型の定義*/
typedef struct list_ {
    int value; /*値*/
    struct list_ *p_next; /* 次のデータへのポインタ */
}list;

/*プロトタイプ宣言*/
list *move_pointer(list *p_list_pointer, int list_order_number);

/*リストの中身をすべて表示*/
void show_all_data(list *p_list_head){

    list *p_list_pointer = p_list_head;
    printf("-----------現在のリスト--------------\n");
    printf("値 | アドレス\n");
    while(p_list_pointer != NULL){
        printf("%d",p_list_pointer->value);
        printf("  | %d \n",p_list_pointer); 
        p_list_pointer = p_list_pointer->p_next;
    }
    printf("-------------------------------------\n");
}


/*リストの最後尾にデータを追加*/
void push_data(list *p_list_head, list *p_new_data,int input_value){

    /*push処理*/
    list *p_list_pointer = p_list_head;

    while(p_list_pointer->p_next != NULL){/*p->nextがリスト最後尾の状態へ*/
         p_list_pointer = p_list_pointer->p_next;  
    }
    
    p_list_pointer->p_next = p_new_data ;/*最後尾の状態となったp->nextにp_new_dataを格納*/
    
    p_new_data->p_next = NULL;
    p_new_data->value = input_value;

    printf("\n☆ %dの値をリストの最後尾にデータを追加しました。\n\n",p_new_data->value); 

}


/*指定したvalueがリストの何番目にあるかを表示する*/
void reference_data(list *p_list_head, int reference_value){
    list *p_list_pointer = p_list_head;

     int i_element = 0; /*リストの要素の順序*/
     while(p_list_pointer != NULL){
        i_element ++;
        if(p_list_pointer->value == reference_value){
            printf("\n☆ %dの値は %d 番目の要素にあります。 \n\n",reference_value, i_element);
        }
        p_list_pointer = p_list_pointer->p_next; 
    }
}

/*要素の順番を指定し、その値を削除する*/
void delete_data(list *p_list_head, int list_order_number){
    list *p_list_pointer = p_list_head;
    
    /*削除したいデータの一つ手前の要素へポインタを移動する*/
    p_list_pointer = move_pointer(p_list_pointer,list_order_number -1);


    /*削除したいデータの一つ手前のデータのp_nextを削除したいデータの一つ後につなげる。*/
    p_list_pointer->p_next = (p_list_pointer->p_next)->p_next;
    printf("\n☆ %d番目のデータを削除しました。\n\n",list_order_number);

}

/*要素の順番を指定し、データを挿入する*/
void insert_data(list *p_list_head, int list_order_number, list *p_new_data,int input_value){
    list *p_list_pointer = p_list_head;
    /*int i_element = 1; リストの要素の順序*/
    p_new_data->value = input_value; /*valueに値を追加*/

    /*ポインタを指定した場所の一つ手前まで移動させる*/
    p_list_pointer = move_pointer(p_list_pointer,list_order_number -1);

    
    p_new_data->p_next =  p_list_pointer->p_next;/*新しく追加したデータの先のデータをつなげる*/
    p_list_pointer->p_next = p_new_data;         /*新しく追加したデータの前にデータをつなげる*/  


    printf("\n☆ %d番目に%dを挿入しました。\n\n",list_order_number,input_value);

}

/*指定した要素のポインタを返す*/
list *move_pointer(list *p_list_pointer, int list_order_number){
    int i_element = 1;
    while(i_element <= list_order_number - 1){
         i_element ++;
         p_list_pointer = p_list_pointer->p_next;   
    }
    return p_list_pointer;
}

int main() {

    list *p_list_head; /*リストの先頭ポインタ*/
    list data1,data2,data3,data4,data5;
    
    /*リストを作成*/
    p_list_head   = &data1;
    data1.value   = 1;
    data1.p_next  = &data2;
    data2.value   = 2;
    data2.p_next  = &data3;
    data3.value   = 3;
    data3.p_next  = NULL; 

    
    show_all_data(p_list_head);       /*リストを表示*/
    push_data(p_list_head, &data4,9); /*末尾に9値を追加*/
    show_all_data(p_list_head);       /*リストを表示*/
    delete_data(p_list_head, 3);      /*3番目のデータを削除*/
    show_all_data(p_list_head);       /*リストを表示*/
    reference_data(p_list_head, 2);   /*2の値が格納されている場所を表示*/
    insert_data(p_list_head, 2, &data5,7);/*2番目に7値を格納*/
    show_all_data(p_list_head);       /*リストを表示*/
    return 0;

}
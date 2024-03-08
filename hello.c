#include <stdio.h>
#include <stdarg.h>

void myPrintf( const char *format, ... )
{
    va_list ap;
    //gitを定期的に使いながら作業をする
    // 可変長引数を１個の変数にまとめる
    //apのポインタがformatの0番目を指し示すようになる？
    va_start( ap, format );
    printf("%d\n",*ap);
    // まとめられた変数で処理する
    //vprintf関数では、フォーマットの文字列を認識しながらこのポインタapをさかのぼって数値を表示している。
    vprintf( format, ap );
    printf("arg_1: %d\n", va_arg(ap, int));
    printf("arg_2: %f\n", va_arg(ap, int));
    printf("%d\n",*ap);
    va_end( ap );
    // 戻り値省略
}

int main() {
    printf("Hello, World!\n");
    myPrintf( "%d %f %s\n", 100, 3.14, "piyo" );
    return 0;
}

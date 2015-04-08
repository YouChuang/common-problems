/*
 * 本文件主要用来做各种测试用
 * */
#include <stdio.h>

int main (int argc, char *argv[])
{
    int input_char = 0, input_tmp_char = 0;

    /* 
    *   "nihao" ////   hahahaha 
    * 测试getchar的缓冲区效果 
    * 输入数据如下:Enter "nihao"  p+Enter   Enter
    * 输出结果如下:换行；不动；换行
    * */ 
    input_char = getchar();////   helllo " dd" worl
    putchar(input_char);
    while ((input_tmp_char = getchar()) != '\n' && input_tmp_char != EOF);
    input_char = getchar();
    putchar(input_char);
    printf("///dajiahao   /* nihao */");
    return 0;
}

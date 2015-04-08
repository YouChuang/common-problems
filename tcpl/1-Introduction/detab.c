/*
 * 替换制表符为一定数量的空格，提前设定每隔多少位置出现一个制表符，则每当输入一个制表符，替换 * 为一定数量的空格，使得空格填充到下一个制表符出现的位置
 * 下一个问题有点搞不明白，为什么使用一个空格和制表符都可以到达？ 
* */

#include <stdio.h>

#define TAB_NUM 8

int detab ();//替换制表符为空格

int main (int argc, char *argv[])
{
    detab();
    return 0;
}

int detab ()
{
    int input_char = 0, tab_end = 0, curr_pos = 1;
    while ((input_char = getchar()) != EOF)
    {
        printf("curr_pos=%d\n", curr_pos);
        if (input_char == '\t')
        {    //计算下一个制表符终止的地方
            tab_end = TAB_NUM - (curr_pos - 1) % TAB_NUM;
            //tab_end = ()
            //tab_end = 0;
            while (tab_end != 0)
            {
                printf("tab_end=%d\n", tab_end);
                putchar(' ');
                tab_end--;
                curr_pos++;
                
            }
        }
        else if (input_char == '\n')
        {    
            curr_pos = 1;
            putchar(input_char);
        }
        else
        {
            curr_pos++;
            putchar(input_char);
        }
    }
    return 0;
}

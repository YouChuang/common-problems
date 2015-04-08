/*
 * 把字符串转换成整数
 * 思路：每个字符代表一个整数位，扫描每个字符，前面的字符所代表的整数乘以10
 * 边界异常：
 * 指针指向为NULL
 * 整数字符串包含+-符号
 * 字符串中包含非法字符，即不是数字的字符
 * 整形溢出，字符串中数字可能超出当前机器的界限
 * */
#include <stdio.h>

/* 定义当前编译环境下的int最值 */
#define MAX (int)((unsigned)~0 >> 1)
#define MIN -(int)((unsigned)~0 >> 1) - 1

int strtoint(const char *str);

int main(void)
{
    char *str;
    int ret = 0;
    scanf("%s", str); 
    /* 若为NULL指针则Segmentation fault (core dumped) */
    //str = NULL;
    ret = strtoint(str);
    return ret;
}

int strtoint(const char *str)
{
    int total = 0, chint = 0, tag = 1;
    /* 处理空字符串，正负字符串， */
    if (str == NULL)
    {
        printf("Error.输入字符串为NULL.\n");
        return 1;
    }
    if ((*str == '-') || (*str == '+'))
    {
        if (*str == '-')
            tag = -1;
        str++;
    }
    //if (isspace(*str))
    while (*str != '\0')
    {
        /* 非法字符处理 */
        if (*str > '9' || *str < '0')
        {
            printf("Error data type.\n");
            return 1;
            //break;
            //str++;
            //break;
        }
        chint = *str - '0';
        /* 越过上界 */
        if (tag == 1 && ((total > MAX/10) || ((total == MAX % 10) && (*str > MAX%10))))
        {    
            total = MAX;
            break;
        }
        /* 越过下界 */
        else if (tag == -1 && ((total > (unsigned)MAX/10) || ((total == (unsigned)MIN % 10) && (*str > (unsigned)MIN%10))))
        {    
            total = (unsigned)MIN;
            break;
        }
        total = total * 10 + chint;
        str++;
    }
    printf("%d", total * tag);
    return 0;
}

/*
 * 旋转字符串，指定前面m个字符 移到字符串末尾
 * 要求：长度为n的字符串操作的时间复杂度为O(n)，空间复杂度为O(1)
 * 思路：
 * 最基本思路，字符数组，遍历前m个字符，依次与后面的字符交换
 * 边界、异常：
 * //链表为空
 * 输入的位置越界
 * 等等
 * */

#include <stdio.h>
#include <string.h>

/* 一般方法，冒泡 */
int rotatestr(char *str, int m, int len);
/* 反转一段字符 */
int rotatesubstr(char *str, int beg, int end);
/* 反转法 */
//int rotatestrrev(char *str, int);

int main(void)
{
    char *instr;
    int ret = 0, m = 0, len = 0;
    scanf("%s", instr);
    scanf("%d", &m);
    len = strlen(instr);
    ret = rotatestr(instr, m, len);
    return ret;
}

int rotatestr(char *str, int m, int len)
{
    printf("str = %s, m = %d, len = %d.\n", str, m, len);
    char tmp, *tmpstr = str;
    int i = 0, j = 0;
    if (m < 0 || m > len)
    {
        printf("Error m");
        return 1;
    }
    if (m == 0 || m == len)
        return 0;
    /* 冒泡法 */
/*
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < len-1; j++ )
            rotatesubstr(str, j, j+1);
    }
*/
    /* 反转法 */
    rotatesubstr(str, 0, m-1);
    rotatesubstr(str, m, len-1);
    rotatesubstr(str, 0, len-1);
    
    printf("retote string:%s\n", str);
    return 0;
}

int rotatesubstr(char *str, int beg, int end)
{
    //printf("befor rorate str:%s, beg=%d, end=%d\n", str, beg, end);
    char tmp;
    int i = 0, mid = (beg+end+1)/2 ;
    if ((beg > end) || beg < 0 || end < 0) 
        return 1;
    for (i = beg; i < mid; i++)
    {
        tmp = str[i];
        str[i] = str[beg+end-i];
        str[beg+end-i] = tmp;
    }
    //printf("after rorate str:%s\n", str);
    return 0;
}

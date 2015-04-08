/*
 *读入几行数据，打印出最长的一行
 *
 * */
#include <stdio.h>

#define ARRAY_LENGTH_MAX 11//为'\0'留一个空间
#define ARRAY_LENGTH_THRESHOLD 8 //阈值，超过此长度做某些工作

int get_line(char input_array[], int array_length_max);//获取输入航
int copy_array(char array_max[], char input_array[]);//拷贝字符数组
int handle_array(char input_array[], int array_length);//处理输入的每一行数据
int reverse_array(char input_array[]);//颠倒字符顺序

int main(int argc, char *argv[])
{
    char input_array[ARRAY_LENGTH_MAX];//当前输入的字符数组
    char array_max[ARRAY_LENGTH_MAX];//存储最长的字符数组
    int max_length = 0;//数组的最大长度
    int array_length = 0;//当前输入的数组长度
    //不断的读入数据
    while ((array_length = get_line(input_array, ARRAY_LENGTH_MAX)) > 0 )
    {
        //prinf("");
        printf("刚输入的字符数组长度是:%d, 内容是%s\n", array_length, input_array);
        //处理刚输入的字符串
        array_length = handle_array(input_array, array_length);
        if (array_length == 0)
        {
            printf("处理后字符串长度为0，删除.\n");
            continue;//下面就不再处理
        }
        else
            printf("处理后的字符串长度为:%d，内容是:%s\n", array_length, input_array);
        /* 
         * 判断其长度是否更长，若更长则存储起来，否则继续读入下一行，直到结束
         * 若想打印任意长度的输入行，则需控制判断输入行长度的部分，使用==如何？
        */
        if (array_length > max_length)
        {
            max_length = array_length;//记录最大长度
            copy_array(array_max, input_array);//把当前数组拷贝到存放最大数组的数组中
        }
        if (array_length > ARRAY_LENGTH_THRESHOLD)
            printf("长度超过8的输入行:%s\n", input_array);
        
        //颠倒字符串顺序
        reverse_array(input_array);
        printf("颠倒后的顺序是:%s", input_array);
        printf("目前为止的最大长度是:%d\n", max_length);
    }
   printf("最长的数组是:%s, 长度为%d\n", array_max, max_length);
    return 0;
}

/**/

/* 输入一行数据，需要控制数组长度 能不能简化下? */
int get_line(char input_array[], int array_length_max)
{
    int input_char = 0;
    int input_num = 0;
    while ((input_char = getchar()) != EOF)
    {
        if (input_num < (array_length_max - 1))
        {   
            if (input_char == '\n')//读入换行符，也该结束了，同时说明缓冲区也为空了
            {
                input_array[input_num++] = '\n';
                input_array[input_num] = '\0';
                return input_num;
            }
            input_array[input_num++] = input_char;//正常
        }
        else if (input_num == (array_length_max - 1))//数组达到最大长度，最后一个写入'\0'结尾
        {
            input_array[input_num] = '\0';//会导致最后从缓冲区中读出来的字符input_char被浪费
            /*
             * 判断缓冲区是否还有内容，若有则清空
             * 可以直接通过最后一个字符是不是换行符来判断
             */
            if (input_char != '\n')
            {
                //缓冲区还有数据未读出来，则清空缓冲区
                while ((input_char = getchar()) != '\n' && input_char != EOF);
            }
            return input_num;
        }
        else
            return input_num;
    }
    return input_num;
    
}

/* 把一个数组拷贝到另一个数组中 */
int copy_array(char array_max[], char input_array[])
{
    int i = 0;
    /*
    * TCPL经典写法 while ((to[i] = from[i]) != '\0')
    * */
    while (input_array[i] != '\0')
    {
        array_max[i] = input_array[i];
        i++;
    }
    array_max[i] = '\0';
    return 0;
}

/* 处理字符串，删除末尾的空格制表符，删除完全空格的行 */
int handle_array(char input_array[], int array_length)
{
    int i = 0;
    //这里也可以不要字符串长度的参数，可以先来一次while循环定位'\0'的位置，然后再开始下面
    for (i = (array_length - 1); i >= 0; i-- )
    {
        //若最后的字符为空格或者制表符则删除，即将当前位替换为字符数组结束符'\0'
        if (input_array[i] == ' ' || input_array[i] == '\t')
        { 
            input_array[i] = '\0';
            array_length--;
        }
        else
            break;//若出现字符不是空格或者制表符，则终止循环
    }
     
    return array_length;//返回该字符串处理后的长度
}

/* 颠倒字符串顺序 */
int reverse_array(char input_array[])
{
    int exchange = 0, i = 0, end = 0, begin = 0;
    
    //先定位字符串末尾 '\0'
    for (i = 0; input_array[i] != '\0'; i++);
    end = i - 1;
    
    //再从末尾开始交换  强大的for循环~
    for (begin = 0; begin < end; begin++, end--)
    {
        exchange = input_array[begin];
        input_array[begin] = input_array[end];
        input_array[end] = exchange;
    }

    return 0;
}

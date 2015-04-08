/*
 * 处理注释
 * 删除掉代码中的注释内容  
 * 以/ * * /为对齐标志  
 * //无需判断接下来的字符，直接从下一行开始
 * ""需要判断接下来的字符
 * / * * /  需要判断接下来的字符 
 * 注释删除功能已经实现，还有几个问题
 * 1.如何将函数功能拆分
 * 2.将多余的空格处理掉
 * 3.修改本文件，而不是写入到新文件中
 * 4.功能丰富？
 * */
#include <stdio.h>

#define ARRAY_MAX 101

int main (int argc, char *argv[])
{
    FILE * fp, *newfp;    
    int input_char = 0, pre_input = 0, begin = 0, end = 0, quotation = 0;
    char input_array[ARRAY_MAX];
/*
    if ((input_char = getchar()) == '/')
        printf("输入%c成功!", input_char);
*/
    printf("处理注释\n");
    if (argc != 2)
    {
        printf("%s\n", "参数错误");
    //    exit(1);
        return 1;
    }
    printf("argv[0]=%s, argv[1]=%s\n", argv[0], argv[1]);
    fp = fopen(argv[1], "r");    
    if (fp == NULL)
    {
        printf("打开文件错误\n");
        return 1;
    }
    else
    {
        //fgets(input_array, 100, fp);//读取一行
        /* 开始读取文件内容，一次一个字符，暂时先不判断// 也不判断"" */
        newfp = fopen("new.c", "w");
        if (newfp == NULL)
        {
            printf("%s\n", "打开新文件错误");//
            return 1;
        }
        printf("处理注释开始.\n");
        while ((input_char = fgetc(fp)) != EOF)
        {
            printf("读入字符:%c\n", input_char);
            //  //注释直接在这里截留
            if (begin == 2)
            {
                //直到读入换行符，注释结束
                if (input_char == '\n')
                {
                    printf("读入换行符了~~~~\n");
                    //输出这个换行符，为了美观
                    putc(input_char, newfp);
                    begin = 0;
                }
                continue;
            }
            //暂时先将读取到的数据写入到另一个文件中
            if (input_char == '/')
            {
                //首先判断是否已经进入引号模式，若没有则继续，否则正常输出
                if (quotation == 1)
                {
                    if (pre_input != 0)
                    {
                       putc(pre_input, newfp);
                       pre_input = 0;
                    }
                    putc(input_char, newfp);
                    continue;
                }
                //先判断注释是否开始
                if (begin == 1)
                {
                    /*/fjkjflkdj*/
                    //接着判断前一个字符是不是*，排除注释开始的/*字符（开始后就把pre设置为0）
                    if (pre_input == '*')//这就意味着结束？
                    {
                        //end = 1;
                        begin = 0;
                        pre_input = 0;//失效
                        continue;
                    }
                    else//一切正常，注释内的内容一律不输出
                    {
                    }
                    
                }
                else if (begin == 0)//注释还没开始
                {
                    //若这之前还有类似的字符则先判断若是//则开始新一种注释，否则输出
                    if (pre_input != 0)
                    {       
                        if (pre_input == '/')
                        {
                            begin = 2;//开始新一种注释
                            pre_input = 0;//前一个字符失效
                            continue;
                        }
                        putc(pre_input, newfp);
                    }

                    //接着判断是不是开始注释，即下一个字符是不是*
                    pre_input = input_char;//暂存字符，直接读取下一个字符
                    continue;
                    
                }
            }
            else if (input_char == '*')
            {
            
                //首先判断是否已经进入引号模式，若没有则继续，否则正常输出
                if (quotation == 1)
                {
                    if (pre_input != 0)
                    {   
                        putc(pre_input, newfp);
                        pre_input = 0;
                    }
                    putc(input_char, newfp);
                    continue;
                }
                //先判断注释是否开始
                if (begin == 1)
                {
                    //if (pre_input != 0)
                    //    putc(pre_input, newfp);
                    //则需要判断是不是结束注释，即下一个字符是不是/，而对于上一个字符不考虑
                    pre_input = input_char;
                    continue;
                }
                else if (begin == 0)//注释还没开始
                {
                    //则判断是不是开始注释，即前一个是不是/
                    if (pre_input == '/')
                    {
                        //注释开始，继续下一轮读取
                        begin = 1;
                        pre_input = 0;//把前一个字符处理掉
                        continue;
                    }
                    else//一切正常，不属于注释内的内容，不需要暂存，正常输出
                    {
                        if (pre_input != 0)
                        {
                            putc(pre_input, newfp);
                            pre_input = 0;
                        }
                        putc(input_char, newfp);
                    
                    }

                }
            }
            else//正常字符
            {
                //对于""
                if (input_char == '"')
                {
                    //注释还没开始，那就是进入双引号模式了，双引号内部一切注释失效
                    if (begin == 0)
                    {   
                        //若没开始引号模式，则从此开始，若已经开始，则从此结束
                        if (quotation == 0)
                            quotation = 1;
                        else
                            quotation = 0;
                            
                    }
                }
                
                //若不在注释空间内则输出
                printf("正常字符:%c\n", input_char);
                printf("begin=%d, pre_input=%c\n", begin, pre_input);
                if (begin == 0)
                {
                    if (pre_input != 0)
                    {
                        putc(pre_input, newfp);
                    }
                    putc(input_char, newfp);
                }
                pre_input = 0;
            }
        }
        printf("删除注释成功!\n");
        fclose(newfp);
        fclose(fp);
        //puts(input_array);
        //printf("input_char:%s\n", input_array);
        //putchar(input_char);        
    }
    return 0;
}

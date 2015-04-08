/*
 * 查找C语言程序中的基本语法错误
 * 圆括号、方括号、花括号不匹配
 * 单引号、双引号、转义字符序列、注释
 * 1.处理完基本的括号匹配问题，假设完全无注释
 * 2.只拆分了一下函数结构   先判断是不是注释同时判断双引号单引号问题（参考上一个问题），若不是注释则判断括号问题
 * */

#include <stdio.h>

#define STACK_MAX 1024

int handle_annotation(char input_char);//处理注释错误
int pop_stack(char stack[], int *stack_top);//出栈
void push_stack(char push_char, char stack[], int *stack_top);//入栈
int handle_bracket(char input_char);//处理括号匹配问题

char bracket_stack[STACK_MAX], quotation_stack[STACK_MAX], annotation_stack[STACK_MAX];//括号栈，引号栈，注释栈
int bracket_top = 0, quotation_top = 0, annotation_top = 0;//括号栈顶，引号栈顶
int annotation = 0;//注释，1表示单斜杠加上星号，2表示双斜杠
int quotation = 0;//字符串，1表示单引号，2表示双引号
int ret = 0, line = 1;//函数处理返回值，记录错误所在行

int main(int argc, char *argv[])
{
    printf("hello world\n");
    
    FILE *fp, *newfp;
    int input_char = 0, pop_char = 0;
    //char stack[STACK_MAX];
        
    /* 判断传入参数是否合法 */
    if (argc != 2)
    {
        printf("参数个数不对\n");
        return 1;
    }
    printf("传入的参数分别为argc[0]=%s argv[1]=%s\n", argv[0], argv[1]);

    /* 打开文件处理 */
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("打开文件%s错误\n", argv[1]);
        return 1;
    }

    /* 读文件内容 */
    printf("开始查找程序错误~\n");
    while ((input_char = fgetc(fp)) != EOF)
    {
        /* 特殊字符处理 / * " '  */
        if (input_char == '/')
        {
            ret = handle_annotation(input_char);
            if (ret)
                return 1;
        }
        else if (input_char == '*')
        {
            /* 先判断是否已经在 "" ''内 */
            if (quotation_top == 0)
            {
                //不在引号范围内，跟之前一样处理
                
            } 
            else
            {
                //在引号范围内，则不予处理
                printf("符号在引号范围内，不予处理.\n");
            }
        }
        else if (input_char == '"')
        {
            //先判断是否在注释范围内
            //if ()
        }
        else if (input_char == ' ')
        {
            
        }
        else if (input_char == '{' || input_char == '[' || input_char == '(' || input_char == ')' || input_char == ']' || input_char == '}')
        {
            //先判断是否在引号或者注释范围内
            if (quotation_top == 0 && annotation == 0)
            {
                //处理括号
                ret = handle_bracket(input_char);
                if (ret)//处理失败
                    return ret;
            
            }
            else
            {
                printf("括号在引号或者注释范围内，不予处理.\n");
            }
        }        
        else if(input_char == '\n')
        {
            line++;
        }
    }
    if (bracket_top != 0 || quotation_top != 0)
    {
        printf("栈不为空，括号或者注释匹配不成功!\n");
        return 1;
    }
    else
        printf("括号检查完毕，没有错误~\n");
    
    return 0;
}


/* 入栈 */
//void push_stack(char push_char)
void push_stack(char push_char, char stack[], int *stack_top)
{
    printf("stack_top=%d\n", *stack_top);
    stack[*stack_top] = push_char;
    (*stack_top)++;
    if ((*stack_top) == (STACK_MAX - 1))
        printf("栈已装满.\n");
    printf("stack_top++=%d\n", *stack_top);
    
    //return 0;
}

/* 出栈 */
//int pop_stack()
int pop_stack(char stack[], int *stack_top)
{
    (*stack_top)--;
    if (*stack_top == 0)
        printf("栈已空.\n");
    else if (*stack_top < 0)
        return EOF;
    printf("stack[stack_top]=%c\n", stack[*stack_top]);
    return stack[*stack_top];
}

/* 处理引号问题 */
int handle_bracket(char input_char)
{
    //{ [ ( 处理入栈
    if (input_char == '{' || input_char == '[' || input_char == '(') 
    {
        //push_stack(input_char);
        push_stack(input_char, bracket_stack, &bracket_top);
    }   
    else if (input_char == '}' || input_char == ']' || input_char == ')') 
    {
        if (input_char == '}')
        {
            if (pop_stack(bracket_stack, &bracket_top) != '{')
            {
                printf("括号%c匹配出错!出错的地方在第%d行.\n", input_char, line);
                return 1;
            }
        }
        else if (input_char == ']')
        {
            if (pop_stack(bracket_stack, &bracket_top) != '[')
            {
                printf("括号%c匹配出错!出错的地方在第%d行.\n", input_char, line);
                return 1;
            }
        }
        else if (input_char == ')')
        {
            if (pop_stack(bracket_stack, &bracket_top) != '(')
            {
                printf("括号%c匹配出错!出错的地方在第%d行.\n", input_char, line);
                return 1;
            }
        }
            
    }   

    return 0;
}

/* 处理注释问题 / 和 *都用这个函数 */
int handle_annotation(char input_char)
{
    /* 先判断是否已经在 "" ''内 */
    if (quotation_top == 0)
    {
        //不在引号范围内，判断注释是否开始或者是否结束
        if (annotation == 0)
        {
            //注释还没开始
            if (annotation_top == 0)
            {
                //栈空
                push_stack(input_char, annotation_stack, &annotation_top);
            }
            else
            {
                //栈不为空，则出栈来判断是否开始//注释
                if (pop_stack(annotation_stack, &annotation_top) == input_char)
                {
                    //开始双斜杠的注释
                    annotation = 2;
                }
                else
                {
                    printf("括号%c匹配出错!出错的地方在第%d行.\n", input_char, line);
                    return 1;
                }
            }
            //push_stack(input_char, annotation_stack,  &annotation_top);
        }
        else
        {
            //注释已经开始则判断是否结束
            if (annotation == 2)
            {
                printf("//注释，/不予处理.\n");
            }
            else
            {
                if (annotation_top == 0)
                {
                    //栈空
                    printf("栈为空，则/不入栈也不处理.\n");
                    //push_stack(input_char, annotation_stack, &annotation_top);
                }
                else
                {
                    //栈不为空，则出栈来判断是否结束注释
                    if (pop_stack(annotation_stack, &annotation_top) == '*')
                    {
                        //正好结束注释
                        annotation = 0;
                    }
                    else
                    {
                        printf("括号%c匹配出错!出错的地方在第%d行.\n", input_char, line);
                        return 1;
                    }
                }
                //push_stack(input_char, annotation_stack,  &annotation_top);
            }
        }
    } 
    else
    {
        //在引号范围内，则不予处理
        printf("符号在引号范围内，不予处理.\n");
    }

    return 0;
}


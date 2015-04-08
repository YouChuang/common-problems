/*
 *文件拷贝/字符统计/统计空格、制表符、换行符/
 *getchar、putchar
 *
 * */
#include <stdio.h>

#define COUNT_NUM 10
#define WORD_NUM 100
#define WORD_LENGTH_MAX 100

int word_count(void);//单词计数
//void char_count(void);//对每一个字符计数

int main(int argc, char *argv[])
{
    int input_char, output_char;//输入输出字符，声明为整数，不但可以存放字符，还可以存放EOF
    int input_char_count = 0, input_line_count = 0, input_space_count = 0, input_tab_count = 0, input_linefeed_count = 0;//输入个数，字符，行，空格，制表符，换行， 采用long型甚至double型可以处理更大的数据范围
    int tag = 0;//空格标记
    printf("拷贝数据，统计行数，请输入字符串:\n");
    while ((input_char = getchar()) != EOF) //EOF，End of File，!=的优先级高于=，所以要加括号
    {
        //printf("表达式的值为1");
        //printf("EOF的值为%d", EOF);
        input_char_count++;//字符个数加1
        /* 统计行数 */
        if (input_char == '\n')
            input_line_count++;
        /* 空格统计，连续多个空格转换成一个输出 */
        if (input_char == ' ')
        {
            input_space_count++;
            if (tag == 1)//这个地方可以记录上一个字符来判断是否为空格
                continue;
            else
                tag = 1;
        }
        else
            tag = 0;
        /* 制表符 以显式的方式输出\t*/
        if (input_char == '\t')
        {
            input_tab_count++;
            
            printf("\\t");
            continue;
        }
        /* 换行符 */
        if (input_char == '\n')
            input_linefeed_count++;
        /* 回退符 */
        if (input_char == '\b')
            printf("\\b");
        /* 反斜杠\ */
        if (input_char == '\\')
            printf("\\\\");
        /* 拷贝输出 */
        putchar(input_char);

    }
    printf("EOF的值为%d\n", EOF);
    printf("表达式的值为0\n");
    printf("输入的字符个数:%d，行个数:%d，空格数:%d，制表符:%d，换行数:%d\n", input_char_count, input_line_count, input_space_count, input_tab_count, input_linefeed_count);//每次输入完毕后Enter键有一个换行符
    //printf("hello world!\n");
    printf("单词统计个数:%d\n", word_count());
    return 0;
}

/*
 * 单词计数，并且每一个单词占用一行输出
 * 打印单词长度的直方图，水平，垂直方向
 * */
int word_count()
{
    int word_count = 0, input_char, tag = 0;
    int num_count[COUNT_NUM], upper_count = 0, lower_count = 0, space_count = 0, others_count = 0;//对每一个输入的字符计数
    int i = 0, j = 0, k = 0;//循环计数  
    int word_length[WORD_NUM];//记录单词长度的数组 
    int word_length_max = 0;//输入的单词中最大的长度    

    //初始化计数数组
    for (i = 0; i < COUNT_NUM; i++)
        num_count[i] = 0;
    //初始化单词长度数组
    for (i = 0; i < WORD_NUM; i++)
        word_length[i] = 0;
     
    printf("\n统计单词和字符，请再次输入字符串:\n");
    while ((input_char = getchar()) != EOF)
    {
        if ((input_char != ' ') && (input_char != '\n') && (input_char != '\t')) 
        {
            
            if ((input_char >= 'A') && input_char <= 'Z')//大写字母
                upper_count++;
            else if ((input_char >= 'a') && input_char <= 'z')//小写字母
                lower_count++;
            else if ((input_char >= '0') && input_char <= '9')//数字
                num_count[input_char - '0']++;
            else//其它
                others_count++;

            putchar(input_char);
            if (tag == 0)//新单词开始
                tag = 1;
            word_length[word_count]++;
        }
        else      
        {
            space_count++;//空格
            if (tag == 1)//单词结束
            {
                word_count++;//单词个数加1
                tag = 0;
                printf("\n");//单词结束换行
            }
        }
    }
    for (i = 0; i < COUNT_NUM; i++)
        printf("输入数字%d的个数为%d.\n", i, num_count[i]);
    printf("输入的空格个数为%d, 大写字母个数为%d, 小写字母个数为%d, 其它字符个数为%d.\n", space_count, upper_count, lower_count, others_count);
    printf("\n所输入单词的长度依次为:");
    for (i = 0; i < word_count; i++)
        printf("%d\t", word_length[i]);
    printf("\n");
    /* 输出单词长度水平的直方图 */   
    printf("\n#输出水平的直方图#\n\n");
    for (i = 0; i < word_count; i++)
    {
        //对每一个单词
        for (j = 0; j < word_length[i]; j++)
            printf("* ");
        printf("\n");
        
    }
    /* 
    * 输出单词长度垂直的直方图 
    * */  
    word_length_max = word_length[0]; 
    for (i = 1; i < word_count; i++)//先找出所有输入长度中最长的，作为循环的起点
    {
        if (word_length_max < word_length[i])
            word_length_max = word_length[i];
    }
    printf("\n输入单词中的最大长度为%d.\n", word_length_max);
    printf("\n#输出垂直的直方图#\n\n");
    for (i = word_length_max; i > 0; i--)//自顶向下遍历
    {
        for (j = 0; j < word_count; j++)
        {
            //对每一个单词
            if (word_length[j] == i)//若该单词的长度达到这个高度则输出一个*,并且高度减1
            {
                printf("* ");
                word_length[j]--;
            }
            else//没达到则输出两个空格
                printf("  ");
        }
        printf("\n");
    
    }
     return word_count;
}


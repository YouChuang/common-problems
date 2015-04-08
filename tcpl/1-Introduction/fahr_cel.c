/*
 *打印hello, world信息，并试错
 * 华氏温度fahr与摄氏温度celsius对照表
 * C=(5/9)(F-32)
 * */
#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int celsius_to_fahr(float, float);

//int 

int main(int argc, char *argv[])
{
    printf(" %s\n", "fahr-to-celsius"); 
    //int cel, fahr;//整数版本，不够精确
    float cel, fahr;
    fahr = LOWER;
    while(fahr <= UPPER)
    {
        //cel = (5/9) * (fahr-32);   //采用这种形式计算，结果全部为0
        //cel = 5 * (fahr-32) / 9;//整数版本
        cel = (5.0/9.0) * (fahr-32);
        //printf("%d\t%d\n", fahr, cel);// \t表示制表符空间
        // printf("%3d %6d\n", fahr, cel);// 采用最小总长度的方式，右对齐
        printf("%5.1f %6.1f\n", fahr, cel);// 采用最小总长度的方式，右对齐，小数点后是小数的位数
        fahr = fahr + STEP;
    }
    celsius_to_fahr(cel, fahr);
/*
    printf(" %s\n", "celsius-to-fahr"); 
    cel = LOWER;
    while(cel <= UPPER)
    {
        //cel = (5/9) * (fahr-32);   //采用这种形式计算，结果全部为0
        //cel = 5 * (fahr-32) / 9;//整数版本
        fahr = (9.0/5.0) * cel + 32;
        //printf("%d\t%d\n", fahr, cel);// \t表示制表符空间
        // printf("%3d %6d\n", fahr, cel);// 采用最小总长度的方式，右对齐
        printf("%6.1f %6.1f\n", cel, fahr);// 采用最小总长度的方式，右对齐，小数点后是小数的位数
        cel = cel + STEP;
    }
    
    //倒序
    printf(" %s\n", "celsius-to-fahr"); 
    cel = UPPER;
    while(cel >= LOWER)
    {
        //cel = (5/9) * (fahr-32);   //采用这种形式计算，结果全部为0
        //cel = 5 * (fahr-32) / 9;//整数版本
        fahr = (9.0/5.0) * cel + 32;
        //printf("%d\t%d\n", fahr, cel);// \t表示制表符空间
        // printf("%3d %6d\n", fahr, cel);// 采用最小总长度的方式，右对齐
        printf("%6.1f %6.1f\n", cel, fahr);// 采用最小总长度的方式，右对齐，小数点后是小数的位数
        cel = cel - STEP;
    }
*/
    return 0;
}

int celsius_to_fahr(float cel, float fahr)
{
    printf(" %s\n", "celsius-to-fahr 正序"); 
    cel = LOWER;
    while(cel <= UPPER)
    {
        //cel = (5/9) * (fahr-32);   //采用这种形式计算，结果全部为0
        //cel = 5 * (fahr-32) / 9;//整数版本
        fahr = (9.0/5.0) * cel + 32;
        //printf("%d\t%d\n", fahr, cel);// \t表示制表符空间
        // printf("%3d %6d\n", fahr, cel);// 采用最小总长度的方式，右对齐
        printf("%6.1f %6.1f\n", cel, fahr);// 采用最小总长度的方式，右对齐，小数点后是小数的位数
        cel = cel + STEP;
    }
    
    //倒序
    printf(" %s\n", "celsius-to-fahr 倒序"); 
    cel = UPPER;
    while(cel >= LOWER)
    {
        //cel = (5/9) * (fahr-32);   //采用这种形式计算，结果全部为0
        //cel = 5 * (fahr-32) / 9;//整数版本
        fahr = (9.0/5.0) * cel + 32;
        //printf("%d\t%d\n", fahr, cel);// \t表示制表符空间
        // printf("%3d %6d\n", fahr, cel);// 采用最小总长度的方式，右对齐
        printf("%6.1f %6.1f\n", cel, fahr);// 采用最小总长度的方式，右对齐，小数点后是小数的位数
        cel = cel - STEP;
    }
    return 0;
}



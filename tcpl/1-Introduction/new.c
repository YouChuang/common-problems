
#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

int celsius_to_fahr(float, float);



int main(int argc, char *argv[])
{
    printf(" %s\n", "fahr-to-celsius"); 
    
    float cel, fahr;
    fahr = LOWER;
    while(fahr <= UPPER)
    {
        
        
        cel = (5.0/9.0) * (fahr-32);
        
        
        printf("%5.1f %6.1f\n", fahr, cel);
        fahr = fahr + STEP;
    }
    celsius_to_fahr(cel, fahr);

    return 0;
}

int celsius_to_fahr(float cel, float fahr)
{
    printf(" %s\n", "celsius-to-fahr 正序"); 
    cel = LOWER;
    while(cel <= UPPER)
    {
        
        
        fahr = (9.0/5.0) * cel + 32;
        
        
        printf("%6.1f %6.1f\n", cel, fahr);
        cel = cel + STEP;
    }
    
    
    printf(" %s\n", "celsius-to-fahr 倒序"); 
    cel = UPPER;
    while(cel >= LOWER)
    {
        
        
        fahr = (9.0/5.0) * cel + 32;
        
        
        printf("%6.1f %6.1f\n", cel, fahr);
        cel = cel - STEP;
    }
    return 0;
}



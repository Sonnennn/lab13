# include <stdio.h>

union charByte
{
    unsigned int num;
    struct
    {
        unsigned char b0:1; unsigned char b1:1;
        unsigned char b2:1; unsigned char b3:1;
        unsigned char b4:1; unsigned char b5:1;
        unsigned char b6:1; unsigned char b7:1;
    } b;

}byte[6],result[3];

int main()
{
    unsigned int mask='\xAA';
    printf("Example: fa:36:2a:c6:f8:4f\n");
    printf("Enter MAC-address: ");
    scanf(" %x:%x:%x:%x:%x:%x",&byte[0].num,&byte[1].num,&byte[2].num,&byte[3].num,&byte[4].num,&byte[5].num);
    printf("In mask binary:     ");
    for(int i=0;i<6;i++)
    {
        printf("%d%d%d%d%d%d%d%d ", byte[i].b.b7, byte[i].b.b6, byte[i].b.b5,
                byte[i].b.b4, byte[i].b.b3, byte[i].b.b2, byte[i].b.b1, byte[i].b.b0);
    }
    result[0].num=mask&byte[0].num;
    result[1].num=mask&byte[1].num;
    result[2].num=mask&byte[2].num;
    printf("\nResult of &10101010: ");
    for(int i=0;i<3;i++)
    {
        printf("%d%d%d%d%d%d%d%d ", result[i].b.b7, result[i].b.b6, result[i].b.b5,
               result[i].b.b4, result[i].b.b3, result[i].b.b2, result[i].b.b1, result[i].b.b0);
    }
    result[0].num=mask^byte[0].num;
    result[1].num=mask^byte[1].num;
    result[2].num=mask^byte[2].num;
    printf("\nResult of ^10101010: ");
    for(int i=0;i<3;i++)
    {
        printf("%d%d%d%d%d%d%d%d ", result[i].b.b7, result[i].b.b6, result[i].b.b5,
               result[i].b.b4, result[i].b.b3, result[i].b.b2, result[i].b.b1, result[i].b.b0);
    }
    result[0].num=mask|byte[0].num;
    result[1].num=mask|byte[1].num;
    result[2].num=mask|byte[2].num;
    printf("\nResult of |10101010: ");
    for(int i=0;i<3;i++)
    {
        printf("%d%d%d%d%d%d%d%d ", result[i].b.b7, result[i].b.b6, result[i].b.b5,
               result[i].b.b4, result[i].b.b3, result[i].b.b2, result[i].b.b1, result[i].b.b0);
    }
    return 0;
}

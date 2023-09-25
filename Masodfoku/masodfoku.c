#include <stdio.h>
#include <math.h>
struct mosoddfukostruct
{
    float x1;
    float x2;
};
struct mosoddfukostruct masodfokukiszamitas(int a,int b, int c)
{
struct mosoddfukostruct eredmeny;
    float diszkriminans = b*b-4*c*a;
    if (diszkriminans >0 )
    {
     eredmeny.x1 = ((-b+sqrt(b*b-4*c*a))/(2*a));
    eredmeny.x2 = ((-b-sqrt(b*b-4*c*a))/(2*a));    
    }else{
        printf("Diszkriminán negativ lesz");
    }
    return eredmeny;
    
}
int main(){
    int a,b,c;
    printf("Másodfoku kiszámítása!!\n");
   while (1==1)
   {
    printf("Kérem szépen az 'A' értékét: ");
    scanf("%i",&a);
        if (a!=0)
        {
        break;
        }else
        {
            printf("Az 'A' változó nem lehet nulla");
        }
   }
    printf("Kérem szépen az 'B' értékét: ");
    scanf("%i",&b);
    
   while (1)
   {
    printf("Kérem szépen az 'C' értékét: ");
    scanf("%i",&c);
        if (c>=0)
        {
        break;
        }else
        {
            printf("A 'C' változó pozitivnak vagy nullának kell lennie");
        }
   }
    struct mosoddfukostruct eredmeny = masodfokukiszamitas(a,b,c);
    printf("Megoldások:\n");
    printf("x1 = %f\n", eredmeny.x1);
    printf("x2 = %f\n", eredmeny.x2);

}
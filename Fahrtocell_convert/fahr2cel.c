#include <stdio.h>
float fahrtocel(float fahr)
{
    
float xd = ((fahr-32)*5)/9;
return xd;

}
int main() {
float beker;
printf ("Kérek egy Farhenhaeit értéket:\n");
scanf("%f", &beker);
printf("Eredmény: %f Celsius\n", fahrtocel(beker));

} 
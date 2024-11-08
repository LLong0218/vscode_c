#include<stdio.h>
#include<float.h>


int main(){
    //double双精度
    //float单精度，容易丢失精度

    double num1= 123.32442;
    double num2= 78.2898491;
    double sum=num1+num2;
    double product= num1 *num2;
    double difference=num1-num2;
    double quotient=num1/num2;
    printf("Sum:%lf\n",sum);
    printf("Product:%lf\n",product);
    printf("Difference:%lf\n",difference);
    printf("Quotient:%lf\n",quotient);

    

    //在不提示系统（在小数后加f）的情况下默认为double
    printf("%lf\n",3.14);

    double low= 1.0/3.0;
    float small= 1.0f/3.0f;
    printf("Float precision :%.20f\n",small);//精度在7=24/log10
    printf("Double precision :%.20f\n",low);//精度在16=53/log10


    printf("Defined max precision for float : %d\n",__FLT_DIG__);//6
    printf("Defined max precision for double : %d\n",DBL_DIG);//15










}
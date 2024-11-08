#include<stdio.h>
#include<math.h>
#include<float.h>

int main(){
    float pos_inf = INFINITY;//正无穷大
    float neg_inf = -INFINITY;//负无穷大
    printf("Positive Infinity :%f\n",pos_inf);
    printf("Negative Infinity :%f\n",neg_inf);

    float num=1.0f;
    float inf=num/ 0.0f;
    printf("Infinty:%f\n",inf);//常数除以0.0取得无穷大

    //Nano:表示一个不确定的值——Not a number
    float nan=0.0f/0.0f;
    printf("Nano(0/0): %f\n",nan);

    float number=sqrt(4);
    printf("Sqrted 4 =%f\n",number);
}
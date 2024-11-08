#include<stdio.h>
#include<float.h>
int main(){
    
    float max_float=FLT_MAX;
    float overflow=max_float * 1000.0f;

    float min_float=FLT_MIN;
    float underflow=min_float/1000.0f;
    

    printf("Max num for float is :%e \n",max_float);
    printf("Overflow for float is :%e \n",overflow);
    //INF 上溢，表示infinity

    printf("Minimun num for float :%e \n",min_float);
    printf("Underflow :%e\n",underflow);

    //四舍五入
    //IEEE 754规定
    //最近偶数摄入 round to nearest, ties to even
    //银行家舍入
    float num_up= 3.15f;
    printf("1->%.1f\n",num_up);
    float num_low= 3.245f;
    printf("2->%.2f\n",num_low);

    //3.14159
    float number=3.14159f;
    printf("%.4f\n",number);

    

    return 0;
}
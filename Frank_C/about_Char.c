#include<stdio.h>
#include<stdbool.h>//布尔数包含true,false.

int main(){

    //实际上存储的是字符或者符号的ASCII码
    char mych=',';
    int mychar=98;
    printf("mychar: %c\n",mychar);

    printf ("mych:%c\n", mych);

    //一些常用的转义字符
    printf("123\t 345\n");//n是换行，t是四个空格

    bool  is_game_over=true;
    printf("The result of this game is :%u",is_game_over);
    


    return 0;
}
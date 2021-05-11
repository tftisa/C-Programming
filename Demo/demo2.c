#include<stdio.h>

typedef unsigned float_bits;

float_bits float_abs(float_bits f);
float_bits float_neg(float_bits f);
float_bits float_half(float_bits f);
float_bits float_twice(float_bits f);
float_bits float_i2f(int i);

int main(){
    
    return 0;
}


float_bits float_abs(float_bits f){
    //exp中放入阶码
    float_bits exp = (f >> 23) & 0xFF;

    //frac存放小数域的值
    float_bits frac = f & 0x7FFFFF;

    //f为NaN(阶码全为1，小数域全为0)
    if( !(exp ^ 0xFF) && frac)  return f;

    //将f置为全部位置为0
    f &= 0;
    f = (exp << 23) | frac;
    
    return f;
}

float_bits float_neg(float_bits f){
    float_bits exp = (f >> 23) & 0xFF;
    float_bits frac = f & 0x7FFFFF;
    
    if( !(exp ^ 0xFF) && frac)  return f;

    return f | (1u << 31);
}

float_bits float_half(float_bits f){
    float_bits sign_bits = f >> 31;
    float_bits exp = (f >> 23) & 0xFF;
    float_bits frac = f & 0x7FFFFF;
    
    //特殊值
    if(!(exp ^ 0xFF))  return f;

    if(exp){  //规格化值
        if(exp != 1){
            exp--;
        }else{  //阶码-Bias=1时,考虑舍入
            //如果最后一位是1，并且倒数第二位也是1，那么需要先将
            //小数部分加上一在除以二
            int addition = frac & 0x3;
            frac += addition;
            frac >>= 1;
            exp--;
        }
    }else{  //非规格化值(exp=0)
        int addition = frac & 0x3;
        frac += addition;
        frac >>= 1;
    }
    
    return (sign_bits << 31) | (exp << 23) | frac;
}

float_bits float_twice(float_bits f){
    float_bits sign_bits = f >> 31;
    float_bits exp = (f >> 23) & 0xFF;
    float_bits frac = f & 0x7FFFFF;

    //特殊值
    if(!(exp ^ 0xFF))   return f;

    if(!exp){  //非规格化情况

/**
 * 要考虑是否需要进位，看小数部分第一个数是否为1
 * 但是（如果小数部分第一个数是1）将frac向左移一位的时候，相当于把第24位变成了1
 * 也就是将阶码最低位设置成了1，那么也就不需要对阶码做出改变
 * 所以直接将frac左移一位即可，不需要exp++
 */
        frac <<= 1;
    }else{
        //当exp的二进制表示为1111 1110时，乘以2会得到无穷大
        //也就是将结果中exp设置为0xFF,frac设置为1
        if(!(exp ^ 0xFE)){
            exp++;
            frac = 0;
        }else{
            exp++;
        }
    }

    return (sign_bits << 31) | (exp << 23) | frac;
}

float_bits float_i2f(int i){
    if(!i)  return i;

    float_bits frac = 0;
    float_bits exp = 0;

    //遍历i的每一位
    for(int i = 31; i >= 0; i--){
        //找到第一个值为1的位
        if((1u << i) & i){
            //将第一个值为1后面的位复制到小数域frac中
            for(int j = i - 1; j >= 0; j--){
                exp++;
                frac |= i & (1 << j);
            }
            break;
        }
    }
}
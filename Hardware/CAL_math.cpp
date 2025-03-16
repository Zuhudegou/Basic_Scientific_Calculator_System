#include "OLED_UI_MenuData.h"
#include "stm32f10x.h"
#include "ctype.h"  //检索数字的函数  
#include "cstring"
#include "stdlib.h"
#include "CAL_math.h"
extern float Calfloatnum;
extern int32_t Calintnum;
extern int32_t Calsecintnum;
extern float Calsecfloatnum;

float result;






//分离数字和运算符
void ESCAPE()
{

        float numarray[100] ;
    char s[] = "";
    char* p = s;     
        double temp=0;
    while (*p != '\0') {
        
        if (isdigit(*p) ||*p == '.') {  
            char* end;
            double num = strtod(p, &end);
            printf("Number: %f\n", num); 
numarray[*p]=num;
            p = end;
        }
        else if (strchr("+-*/", *p)) {
                printf("Operator: %c\n", *p);
                if(*p=='+')
                {
temp+=numarray[*p-1];
                }
                if(*p=='-')
                {
temp-=numarray[*p-1];
                }
                if(*p=='*')
                {
temp*=numarray[*p-1];
                }
                if(*p=='/')
                {
temp/=numarray[*p-1];
                }
            p++;
        }

      
        
    }

    
}
     

//通过判断决定对应运算
void CAL_MATH()
{
   

        if (currentOperator == OP_PLUS) {
                // Plus 被选中
                if(Calintnum!=0&&Calsecintnum!=0)

                CAL_intadd(Calintnum,Calsecintnum);
                                else if (Calintnum==0&&Calsecintnum!=0)
                {
                  result=      CAL_floatadd(Calfloatnum,Calsecintnum);

                }else if (Calintnum!=0&&Calsecintnum==0)
                {
                        result=     CAL_floatadd(Calintnum,Calsecfloatnum);
                }else
                {
                        result=    CAL_floatadd(Calfloatnum,Calsecfloatnum);
                }
                
                
            } else if (currentOperator == OP_SUBTRACT) {
                // Subtract 被选中
                if(Calintnum!=0&&Calsecintnum!=0)

                result=     CAL_intsub(Calintnum,Calsecintnum);
                                else if (Calintnum==0&&Calsecintnum!=0)
                {
                        result=          CAL_floatsub(Calfloatnum,Calsecintnum);

                }else if (Calintnum!=0&&Calsecintnum==0)
                {
                        result=        CAL_floatsub(Calintnum,Calsecfloatnum);
                }else
                {
                        result=   CAL_floatsub(Calfloatnum,Calsecfloatnum);
                }
                
                
            }else if (currentOperator == OP_DIVIDE )
            {
                if(Calintnum!=0&&Calsecintnum!=0)

                result=     CAL_intdiv(Calintnum,Calsecintnum);
                                else if (Calintnum==0&&Calsecintnum!=0)
                {
                        result=        CAL_floatdiv(Calfloatnum,Calsecintnum);

                }else if (Calintnum!=0&&Calsecintnum==0)
                {
                        result=            CAL_floatdiv(Calintnum,Calsecfloatnum);
                }else
                {
                        result=              CAL_floatdiv(Calfloatnum,Calsecfloatnum);
                }
                
               
            }else if (currentOperator == OP_MULTIPLY )
            {
                if(Calintnum!=0&&Calsecintnum!=0)

                result=       CAL_intmul(Calintnum,Calsecintnum);
                                else if (Calintnum==0&&Calsecintnum!=0)
                {
                        result=           CAL_floatmul(Calfloatnum,Calsecintnum);
                        
                }else if (Calintnum!=0&&Calsecintnum==0)
                {
                        result=               CAL_floatmul(Calintnum,Calsecfloatnum);
                }else
                {
                        result=                CAL_floatmul(Calfloatnum,Calsecfloatnum);
                }
                
            }
            
            
           
        
        

       
}







float CAL_floatadd(float num1,float num2)
{
        float result;

result=num1+num2;
        return result;
}
float CAL_floatsub(float num1,float num2)
{
        float result;

result=num1-num2;
        return result;
}
float CAL_floatmul(float num1,float num2)
{
        float result;

result=num1*num2;
        return result;
}
float CAL_floatdiv(float num1,float num2)
{
        float result;

result=num1/num2;
        return result;
}
long CAL_intadd(long num1,long num2)
{
        long result;

result=num1+num2;
        return result;
}
long CAL_intsub(long num1,long num2)
{
        long result;

result=num1-num2;
        return result;
}
long CAL_intmul(long num1,long num2)
{
        long result;

result=num1*num2;
        return result;
}
long CAL_intdiv(long num1,long num2)
{
        long result;

result=num1/num2;
        return result;
}

/*
 * No.1009: FatMouse' Trade
 * Problem Description
 * FatMouse prepared M pounds of cat food, ready to trade with the cats guarding the warehouse containing his favorite food, JavaBean.
 * The warehouse has N rooms. The i-th room contains J[i] pounds of JavaBeans and requires F[i] pounds of cat food. FatMouse does not have to trade for all the JavaBeans in the room, instead, he may get J[i]* a% pounds of JavaBeans if he pays F[i]* a% pounds of cat food. Here a is a real number. Now he is assigning this homework to you: tell him the maximum amount of JavaBeans he can obtain.
 

 * Input
 * The input consists of multiple test cases. Each test case begins with a line containing two non-negative integers M and N. Then N lines follow, each contains two non-negative integers J[i] and F[i] respectively. The last test case is followed by two -1's. All integers are not greater than 1000.
 

 * Output
 * For each test case, print in a single line a real number accurate up to 3 decimal places, which is the maximum amount of JavaBeans that FatMouse can obtain.
 

 * Sample Input
 * 5 3
 * 7 2
 * 4 3
 * 5 2
 * 20 3
 * 25 18
 * 24 15
 * 15 10
 * -1 -1
 

 * Sample Output
 * 13.333
 * 31.500
 

 * Author
 * CHEN, Yue
 

 * Source
 * ZJCPC2004

 */


#include<cstdio>  
#include<algorithm>  
using namespace std;  
#define MAX 1001  
struct node  
{  
    double j,f,c;  
}num[MAX];  
int n;  
double m;  
bool cmp(const struct node &a,const struct node &b)  
{  
    return b.c>a.c;  
}  
int main()  
{  
    for(;scanf("%lf%d",&m,&n);)  
    {  
        if(m==-1&&n==-1) break;  
        for(int i=0;i<n;++i)  
        {  
            scanf("%lf%lf",&num[i].j,&num[i].f);  
            num[i].c=num[i].f/num[i].j;  
        }  
        sort(num,num+n,cmp);  
        double summ=0.0;  
        for(int i=0;i<n;++i)  
        {  
            if(m<=0) break;  
            if(m>=num[i].f)  
            {  
                summ+=num[i].j;  
                m-=num[i].f;  
            }  
            else  
            {  
                summ+=(num[i].j*(m/num[i].f));  
                m=0;  
            }  
        }  
        printf("%.3f\n",summ);  
    }  
    return 0;  
}  

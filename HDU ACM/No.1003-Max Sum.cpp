/*
 * No.1003: Max Sum
 * Problem Description
 * Given a sequence a[1],a[2],a[3]......a[n], your job is to calculate the max sum of a sub-sequence. For example, given (6,-1,5,4,-7), the max sum in this sequence is 6 + (-1) + 5 + 4 = 14.
 
 * Input
 * The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line starts with a number N(1<=N<=100000), then N integers followed(all the integers are between -1000 and 1000).
 
 * Output
 * For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line contains three integers, the Max Sum in the sequence, the start position of the sub-sequence, the end position of the sub-sequence. If there are more than one result, output the first one. Output a blank line between two cases.
 
 * Sample Input
 * 2
 * 5 6 -1 5 4 -7
 * 7 0 6 -1 1 -6 7 -5
 
 * Sample Output
 * Case 1:
 * 14 1 4

 * Case 2:
 * 7 1 6
 
 * Author
 * Ignatius.L
 */ 

#include<stdio.h>
#include<string.h>
typedef struct line_doc{
    int value, low, high;
}cdnat; //结构体主要记录两个累加值以及其左右下标 
int main()
{

//    freopen("input.txt", "r", stdin);
    int i, T = 0, t, n, m, temp;
    cdnat x, ans;
    scanf("%d", &T);
    for(t=1; t<=T; ++t)
    {
        scanf("%d", &n);
        scanf("%d", &temp);
        x.value = temp, x.low = x.high = 1;
        ans = x;
        
        for(i=1; i<n; ++i) 
        {
            scanf("%d", &temp);
            if(x.value > 0) 
            {//在累加的缓存值进行判断主要是为了使加上temp的值后可以比temp大，这样才满足找到最大值的情况 
                x.value += temp;
                x.high = i+1;
                if(x.value > ans.value)
                {//如果发现累加后的值比已存储的最大值大，那么就将旗帜赋给它 
                    ans.value = x.value;
                    ans.low = x.low;
                    ans.high = x.high;
                }
            }
            else
            {//如果缓存的值是负数（或者为零）那么这就意味着最大值的下标在改变，尽管替换缓存后信息都没了，但之前
             //有用的最大值的信息都保存在ans中，替换的原因是必须不能让x的值成为“累赘” 
                if(temp > ans.value) 
                {
                    ans.value = temp;
                    if(x.value == 0) ans.low = x.low; // 要对零进行判断的原因是在Sample中 
                    else ans.low = i+1;
                    ans.high = i+1;
                }
                x.value = temp, x.low = x.high = i+1;
            }
        }    
        printf("Case %d:\n%d %d %d\n", t, ans.value, ans.low, ans.high);
        if(t+1 <= T) printf("\n");
    }
    return 0;
}

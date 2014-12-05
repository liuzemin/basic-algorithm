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
}cdnat; //�ṹ����Ҫ��¼�����ۼ�ֵ�Լ��������±� 
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
            {//���ۼӵĻ���ֵ�����ж���Ҫ��Ϊ��ʹ����temp��ֵ����Ա�temp�������������ҵ����ֵ����� 
                x.value += temp;
                x.high = i+1;
                if(x.value > ans.value)
                {//��������ۼӺ��ֵ���Ѵ洢�����ֵ����ô�ͽ����ĸ����� 
                    ans.value = x.value;
                    ans.low = x.low;
                    ans.high = x.high;
                }
            }
            else
            {//��������ֵ�Ǹ���������Ϊ�㣩��ô�����ζ�����ֵ���±��ڸı䣬�����滻�������Ϣ��û�ˣ���֮ǰ
             //���õ����ֵ����Ϣ��������ans�У��滻��ԭ���Ǳ��벻����x��ֵ��Ϊ����׸�� 
                if(temp > ans.value) 
                {
                    ans.value = temp;
                    if(x.value == 0) ans.low = x.low; // Ҫ��������жϵ�ԭ������Sample�� 
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

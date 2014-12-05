/*
 * No.1001: Sum Problem
 
 *  Problem Description
 * Hey, welcome to HDOJ(Hangzhou Dianzi University Online Judge).

 * In this problem, your task is to calculate SUM(n) = 1 + 2 + 3 + ... + n.
 

 * Input
 * The input will consist of a series of integers n, one integer per line.
 

 * Output
 * For each case, output SUM(n) in one line, followed by a blank line. You may assume the result will be in the range of 32-bit signed integer.
 

 * Sample Input
 * 1
 * 100
 

 * Sample Output
 * 1

 * 5050
 

 * Author
 * DOOM III
 */
 
 #include<iostream> 
 using namespace std;

 int main()
 { int a,b,sum=0,i=0,j;
   int c[100]={0};
   while(cin>>a)
   {
     sum=0;
     for(b=1;b<=a;b++)
       sum=sum+b;
       c[i++]=sum;  
   }
   for(j=0;j<i;j++)
   cout<<c[j]<<"\n"<<endl;
   return 0;
 }

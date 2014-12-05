/*
 * No.1010: Tempter of the Bone
 * Problem Description
 * The doggie found a bone in an ancient maze, which fascinated him a lot. However, when he picked it up, the maze began to shake, and the doggie could feel the ground sinking. He realized that the bone was a trap, and he tried desperately to get out of this maze.

 * The maze was a rectangle with sizes N by M. There was a door in the maze. At the beginning, the door was closed and it would open at the T-th second for a short period of time (less than 1 second). Therefore the doggie had to arrive at the door on exactly the T-th second. In every second, he could move one block to one of the upper, lower, left and right neighboring blocks. Once he entered a block, the ground of this block would start to sink and disappear in the next second. He could not stay at one block for more than one second, nor could he move into a visited block. Can the poor doggie survive? Please help him.
 
 * Input
 * The input consists of multiple test cases. The first line of each test case contains three integers N, M, and T (1 < N, M < 7; 0 < T < 50), which denote the sizes of the maze and the time at which the door will open, respectively. The next N lines give the maze layout, with each line containing M characters. A character is one of the following:

 * 'X': a block of wall, which the doggie cannot enter; 
 * 'S': the start point of the doggie; 
 * 'D': the Door; or
 * '.': an empty block.

 * The input is terminated with three 0's. This test case is not to be processed.
 
 * Output
 * For each test case, print in one line "YES" if the doggie can survive, or "NO" otherwise.
 
 * Sample Input
 * 4 4 5
 * S.X.
 * ..X.
 * ..XD
 * ....
 * 3 4 5
 * S.X.
 * ..X.
 * ...D
 * 0 0 0
 
 * Sample Output
 * NO
 * YES
 
 * Author
 * ZHANG, Zheng
 
 * Source
 * ZJCPC2004
 */
 
 #include <iostream>  
using namespace std;  
char map[9][9];        //��ͼ��಻����7��7��,�ִ�(1,1)����,���Կ���9,9  
int n,m,t,di,dj;       //������������,�Լ��յ�λ��  
bool escape;           //��ʶ�����ɹ�  
int dir[4][2]={{0,-1},{0,1},{1,0},{-1,0}};  //�ֱ��ʾ���ҡ��¡����ĸ�����  
void DFS(int si,int sj,int cnt)  
{  
    int i,temp;  
    if (si>n || sj>m || si<=0 || sj<=0)   //Խ���߽�㲻����  
        return;  
    if (si==di && sj==dj && cnt==t)  
    {  
        escape=1;                   //ʱ�����õ�ʱ���������  
        return;  
    }  
    temp=abs(t-cnt)-(abs(di-si)+abs(dj-sj));     //���㵱ǰ���յ�����·�뻹��Ҫ��ʱ���,��С��0��·����֦  
    if (temp<0 || temp&1)           //temp����������Ļ�ҲҪ��֦  
        return;  
    for (i=0;i<4;i++)  
    {  
        if (map[si+dir[i][0]][sj+dir[i][1]]!='X')  
        {  
            map[si+dir[i][0]][sj+dir[i][1]]='X';  //�ѵ�ǰ��ˢΪX  
            DFS(si+dir[i][0],sj+dir[i][1],cnt+1); //�����õ�              
            if (escape)  
                return;  
            map[si+dir[i][0]][sj+dir[i][1]]='.';  //������������˳�����,�����°Ѹõ�ˢΪ'.'  
        }  
    }  
    return ;  
}  
int main()  
{  
    int i,j,si,sj,wall;  
    while (cin>>n>>m>>t)  
    {  
        if (n==0 && m==0 && t==0)  
        {  
            break;  
        }  
        wall=0;  
        for (i=1;i<=n;i++)  
        {  
            for (j=1;j<=m;j++)  
            {  
                cin>>map[i][j];  
                if (map[i][j]=='S')  
                {  
                    si=i,sj=j;  
                }  
                else if (map[i][j]=='D')  
                {  
                    di=i,dj=j;  
                }  
                else if (map[i][j]=='X')  
                {  
                    wall++;  
                }  
            }  
        }  
        if (n*m-wall<=t)      //·����֦,�����겻��ǽ���Թ���������Tʱ�佫��������  
        {  
            cout<<"NO"<<endl;  
            continue;  
        }  
        escape=0;  
        map[si][sj]='X';      //�ǵ�ˢΪ'X'  
        DFS(si,sj,0);  
        if (escape)  
        {  
            cout<<"YES"<<endl;  
        }  
        else  
        {  
            cout<<"NO"<<endl;  
        }  
    }  
    return 0;  
}  

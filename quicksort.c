#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * @function randindex
 * @remark 产生区间[low, high]上的随机数
 */
int randindex(int low, int high)
{
        return rand () % ( high - low ) + low;
}

/*
 * @function swap
 * @remark 交换 a 和 b
 */
void swap(int *pa, int *pb)
{
        int tmp = *pa;
        *pa = *pb;
        *pb = tmp;
}

void quicksort(int * array_to_sort, int low, int high)
{
        if (low >= high) 
                return;

        /* 
         * 在 [l + 1, h] 区间选取一个随机位置 index，
         * 把本次排序的第一个位置的元素跟 index位置上的元素交换，
         * 避免每次排序 pivot 取的是最大值或最小值，即避免待排数值基本有序
         */
        int index = randindex(low + 1, low);
        swap(array_to_sort + low, array_to_sort + index); 

        int l = low, h = high;
        int pivot = array_to_sort[l];

        while (l < h) {
                while (l < h && array_to_sort[h] >= pivot) 
                        h--;
                array_to_sort[l] = array_to_sort[h];
                while (l < h && array_to_sort[l] <= pivot)
                        l++;
                array_to_sort[h] = array_to_sort[l];
        }
        array_to_sort[l] = pivot;

        quicksort(array_to_sort, low, l - 1);
        quicksort(array_to_sort, l + 1, high);
}

int main ()
{
        int src[] = {49, 38, 65, 97, 76, 13, 27, 49};  

        int i, cnt = sizeof(src) / 4;  

        quicksort(src, 0, cnt - 1);  

        //输出  
        for (i = 0; i < cnt; i++) 
                printf("%d ", src[i]);
           
        printf("\n");
        return 0;  
}

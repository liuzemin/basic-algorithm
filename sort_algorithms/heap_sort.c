#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CLK_TCK 18.2

void swap(int matrix[], int i, int j)
{
        int temp;
        temp = matrix[i];
        matrix[i] = matrix[j];
        matrix[j] = temp;
}

void adjust_heap_max(int matrix[], int index, int length)
{
        int left_child = index * 2 + 1;
        int right_child = index * 2 + 2;
        int max = index;

        if (left_child < length && matrix[left_child] > matrix[index]) {
                max = left_child;
        }
        if (right_child < length && matrix[right_child] > matrix[max]) {
                max = right_child;
        }
        if (index != max) {
                swap(matrix, index, max);
                adjust_heap_max(matrix, max, length);
        }
}

void adjust_heap_min(int matrix[], int index, int length)
{
        int left_child = index * 2 + 1;
        int right_child = index * 2 + 2;
        int min = index;

        if (left_child < length && matrix[left_child] < matrix[index]) {
                min = left_child;
        }

        if (right_child < length && matrix[right_child] < matrix[min]) {
                min = right_child;
        }

        if (index != min) {
                swap(matrix, index, min);
                adjust_heap_min(matrix, min, length);
        }
}

void build_heap_max(int matrix[], int length)
{
        int i;
        for (i = length / 2 -1; i >= 0; i--) {
                adjust_heap_max(matrix, i, length);
        }
}

void build_heap_min(int matrix[], int length)
{
        int i;
        for (i = length / 2 - 1; i >= 0; i--) {
                adjust_heap_min(matrix, i, length);
        }
}


void print_heap(const char* strmsg, int array[], int nlength)
{
        int i;
        printf("%s", strmsg);
        for (i = 0; i <nlength; i++) {
                printf(" %-2d ", array[i]);
        }
        printf("\n");
}


void heap_sort_min(int matrix[], int length)
{
        int i;
        int ilength = length;
        print_heap("Before sort:", matrix, length);
        build_heap_min(matrix, length);
        print_heap("Built  heap:", matrix, length);
        for (i = length - 1; i >= 1; i--) {
                swap(matrix, 0, i);
                length--;
                adjust_heap_min(matrix, 0, length);
                print_heap("Sort   heap:", matrix, ilength);
        }
}

void heap_sort_max(int matrix[], int length)
{
        int i;
        int ilength = length;
        print_heap("Before sort:", matrix, length);
        build_heap_max(matrix, length);
        print_heap("Built  heap:", matrix, length);
        for (i = length - 1; i >= 1; i--) {
                swap(matrix, 0, i);
                length--;
                adjust_heap_max(matrix, 0, length);
                print_heap("Sort   heap:", matrix, ilength);
        }
}

void heap_sort_min_with_time_shown(int matrix[], int length) 
{
        double t1, t2;
        int i, j;
        double k;
        t1 = clock();
        /*在下方添加待测试运行时间的代码;*/

        int ilength = length;
        print_heap("Before sort:", matrix, length);
        build_heap_min(matrix, length);
        print_heap("Built  heap:", matrix, length);
        for (i = length - 1; i >= 1; i--) {
                swap(matrix, 0, i);
                length--;
                adjust_heap_min(matrix, 0, length);
                print_heap("Sort   heap:", matrix, ilength);
        }

        for (i = 0; i < 10000; i++)
                for (j = 0; j < 10000; j++)
                        k = 0.123 * j + 3.567 * i;
        t2 = clock();
        printf("It takes %lf \n", (t2 - t1) / CLK_TCK);
}

void heap_sort_max_with_time_shown(int matrix[], int length)
{
        double t1, t2;
        int i, j;
        double k;
        t1 = clock();
        /*在下方添加待测试运行时间的代码;*/

        int ilength = length;
        print_heap("Before sort:", matrix, length);
        build_heap_max(matrix, length);
        print_heap("Built  heap:", matrix, length);
        for (i = length - 1; i >= 1; i--) {
                swap(matrix, 0, i);
                length--;
                adjust_heap_max(matrix, 0, length);
                print_heap("Sort   heap:", matrix, ilength);
        }

        for (i = 0; i < 10000; i++)
                for (j = 0; j < 10000; j++)
                        k = 0.123 * j + 3.567 * i;
        t2 = clock();
        printf("It takes %lf \n", (t2 - t1) / CLK_TCK);
}

int main()
{
        /* 将数组看成完全二叉树的中序遍历结果的线性存储 */
        int data[]={8, 5, 4, 6, 13, 7, 2, 9, 12, 11, 3, 10, 1, 15, 14, 19, 17, 30};
        heap_sort_min_with_time_shown(data, 18);

        printf("\n-----------------------------------\n");

        heap_sort_max_with_time_shown(data, 18);
        return 0;
}

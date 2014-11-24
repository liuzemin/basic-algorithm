insertsort(int a[], int n)                        /* 直接插入排序 */
{
        int i, j;
        for (i = 2; i <= n; i++) {
                a[0] = a[i];
                j = i - 1;
                while (j > 0 && a[0] > a[j])            /* 改变判断条件，实现从大到小地排列 */
                        a[j + 1] = a[j--];
                a[j + 1] = a[0];                        /* 将元素 a[0] 插入指定位置 */
        }
}

void selectsort(int k[], int n)                /* 选择排序 */
{
        int i, j, max;
        for (i = 1; i <= n - 1; i++) {
                max = i;
                for (j = i + 1; j <= n; j++)            /* 在后 n-i+1 个元素中找到最小的元素位置 */
                        if (k[j] > k[max])
                                max = j;                /* 用 min 记录下最小元素的位置 */
                if (max != i) {                         /* 如果最小的元素不位于后 n-i+1 个元素档第 1 个 */
                        k[0] = k[max] ;
                        k[max] = k[i];                  /* 元素的交换 */
                        k[i] = k[0];
                }
        }
}


void bubblesort(int k[], int n)            /* 冒泡排序 */
{
        int i, j, tmp , flag = 1;
        for (i = 1; i <= n - 1 && flag == 1; i++) {                /* 执行 n-1 趟排序 */

                flag = 0;
                for (j = 1; j <= n - i; j++) {
                        if (k[j] < k[j + 1]) {                    /* 数据交换 */
                                tmp = k[j + 1];
                                k[j + 1] = k[j];
                                k[j] = tmp;
                                flag = 1;
                        }
                }
        }
}

void shellsort(int k[], int n)          /* 希尔排序 */
{
        int i, j, flag, gap = n;
        int tmp;
        while (gap > 1) {
                gap = gap / 2;                /* 增量缩小，每次减半 */
                do {                          /* 子序列应用冒泡排序 */
                        flag = 0;
                        for (i = 1; i <= n - gap; i++) {
                                j = i + gap;
                                if (k[i] < k[j]) {
                                        tmp = k[i];
                                        k[i] = k[j];
                                        k[j] = tmp;
                                        flag = 1;
                                }
                        }
                } while (flag != 0);
        }
}

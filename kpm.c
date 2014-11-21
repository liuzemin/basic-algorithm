/*
 * KPM
 *
 */

void next_value(int len,int next[],char a[])
{
        int j = 1;
        int k = 0;
        next[0] = 0;
        int temp = 0;
        while (j < len) {
                k = next[j - 1];
                if (k == 0 && a[k] != a[j]) {
                        next[j] = 0;
                        j++;
                        continue;
                }
                if (a[k] == a[j]) {
                        next[j] = k + 1;
                        j++;
                        continue;
                }
                while (k != 0) {
                        k = next[k];
                        if (k == 0 && a[k] != a[j]) {
                                next[j] = 0;
                                j++;
                                break;
                        }
                        if (a[k] == a[j]) {
                                next[j] = k + 1;
                                j++;
                                break;
                        }
                }
        }
        // The first optimization
        for (j = len - 1; j >= 1; j--) {
                next[j] = next[j - 1];
        }
        next[0] = -1;
        // The second optimization
        for (j = 1; j < len; j++) {
                if (a[j] == a[next[j]]) {
                        next[j] = next[next[j]];
                }
        }
}

int kpm_search(char s[],char p[],int next[])
{
        int i = 0;
        int j = 0;
        int len = strlen(s);
        int plen = strlen(p);
        while (i < len && j < plen) {
                if (j == -1 || s[i] == p[j]) {
                        i++;
                        j++;
                } else
                        j = next[j];
        }
        if (j == plen) {
                return i - j;
        }

        return -1;
}

#include<stdio.h>

/*
void resultC(int *a, int *b, int n)
{
    if(n <= 0)
        return;
    int root = a[n-1];
    int i;
    for(i = 0; i < n; i++)
        if(b[i] == root)
            break;
    printf(" %d", root);
    resultC(a, b, i);
    resultC(a+i, b+i+1, n-i-1);
}

int main()
{
    int n;
    scanf("%d", &n);
    int i;
    int a[30], b[30];
    for(i = 0; i < n; i++)
        scanf("%d", &a[n]);
    for(i = 0; i < n; i++)
        scanf("%d", &b[n]);

    printf("Preorder:");
    resultC(a, b, n);
    return 0;
}
*/
void getpre(int *post, int *in, int n) {
    if(n <= 0) return;
    int root = post[n - 1];
    int i;
    for(i = 0; i < n; i++) {
        if(in[i] == root) {
            break;
        }
    }
    printf(" %d", root);
    getpre(post, in, i);
    getpre(post + i, in + i + 1, n - i - 1);
}
int main() {
    int post[40], in[40];
    int n;
    scanf("%d", &n);
    int i, j;
    for(i = 0; i < n; i++) {
        scanf("%d", &post[i]);
    }
    for(i = 0; i < n; i++) {
        scanf("%d", &in[i]);
    }
    printf("Preorder:");
    getpre(post, in, n);
    printf("\n");
    return 0;
}

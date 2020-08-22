#include<stdio.h>
#define MAX 10000
int a[MAX];
int n;
void input(){
	printf("moi nhap so luong cua day n=");
	scanf("%d",&n);
	printf("moi nhap cac phan tu\n");
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
}	
void BubbleSort()
{
    for (int i = 1; i < n; i++)
    {
        int swapped = 0;
        for (int j = n; j > i; j--)
        {
            if (a[j - 1] > a[j])
            {
                int tmp = a[j-1];
                a[j-1] = a[j];
                a[j] = tmp;
                swapped = 1;
            }

            if (!swapped) return;
        }
    }
}
void printfResult(){
	for(int i=1; i<=n; i++ ){
        printf("%d\t",a[i]);
	}
}
int main(){
	input();
	BubbleSort();
	printfResult();
	}

#include<stdio.h>
#include<conio.h>
#include<math.h>
#define MAX 10000

int a[MAX];
int n;

void input()
{
    printf("moi nhap so luong cac phan tu cua day n= ");
    scanf("%d", &n);
    printf("moi nhap cac phan tu: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
}
void heapify(int a[], int n){
	int gap =n;
	float shrink =1.3;
	bool sorted = false;
	while((gap > 1) || (sorted == false)){
		gap = floor(gap / shrink);
		if(gap < 1) gap = 1;
		int i = 0;
		if (gap == 1) sorted = true;
		while(i + gap <n){
			if( a[i] > a[i+gap]){
				int tmp =a[i];
				a[i] = a[i+gap];
				a[i+gap] = tmp;
				if(gap == 1 ) sorted = false;
			}
		    i=i+1;
		}
	}
}
void printfResult(){
	for(int i=0; i<n; i++) printf("%d ",a[i]); printf("\n");
}
main(){
	input();
	heapify(a , n);
	printfResult();
	}

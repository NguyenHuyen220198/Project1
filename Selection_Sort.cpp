#include<stdio.h>
#define MAX 10000
int a[MAX];
int n;
void input(){
	printf("moi nhap so luong cua day n=");
	scanf("%d",&n);
	printf("moi nhap cac phan tu\n");
	for(int k=1; k<=n; k++){
		scanf("%d", &a[k]);
	}
}	
void SelectionSort(){
	for(int k=1; k<=n; k++){
		int m=k;
		for(int i=k+1; i<=n; i++){
			if(a[m]>a[i]) m=i;
		}
	int tmp=a[k];
	a[k]=a[m];
	a[m]=tmp;
	}
}
void printfResutl(){
	for(int k=1; k<=n; k++) printf("%d\t ",a[k]);
}
int main(){
	
	input();
	SelectionSort();
	printfResutl();
}

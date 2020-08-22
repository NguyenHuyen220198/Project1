#include<stdio.h>
#include<conio.h>
#define MAX 10000
int a[MAX];
int n;
int l = 1;
void input(){
	printf("moi nhap so luong cac phan tu cua day n= ");
	scanf("%d",&n);
	printf("moi nhap cac phan tu: ");
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void BuilHeap(int a[],int l,int n, int i){
	int j = i*2 + 1 - l;
	int e = a[i];
	while(n >= j){
		int k = j+1;
		if(j < n && a[k] > a[j]) j = k;
		if(a[j] < e) break;
		a[i] = a[j];
		i = j;
		j = i*2 + 1- l;
		}
	a[i] = e;
	}
	
void HeapSort(){
	for(int i = (n +l -1)/2; i>l; i--){
		BuilHeap(a,l,n,i);
		while(n>1){
			BuilHeap(a, l, n, l);
			//int x= a[n--], y=a[l];
			int tmp= a[n]; a[n] = a[l] ; a[l]=tmp;
		}
	}
}
	
void printfResult(){
	for(int i=0; i<n; i++) printf("%d ",a[i]); printf("\n");
}
int main(){
	input();
	HeapSort();
	printfResult();
	}

#include<stdio.h>
#define MAX 10000
int a[MAX];
int n;
void input(){
	printf("moi nhap so luong cac phan tu cua day n= ");
	scanf("%d",&n);
	printf("moi nhap cac phan tu: ");
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
}
void swap(){
	int i, int j;
	int tmp= a[i];  a[i]=a[j]; a[j]=tmp;
	
}
int partition( ){
	int L,R,indexPivot;
	int pivot =a[indexPivot];
	swap(indexPivot,R);
	int storeIndex =L;
	for(int i=L; i<=R; i++){
		if (a[i]<pivot){
			swap(storeIndex,i);
			storeIndex++;
		}
	}
	swap(storeIndex, R);
	return storeIndex;
}
void quickSort(int L, int R){
	if(L<R){
		int index =(L+R)/2;
		index= partition(L,R, index);
		if(index>L) quickSort(L,index -1);
		if(index<R) quickSort(index+1, R);
		
	}
}
void printfResult(){
	for(int i=0; i<n; i++) printf("%d ",a[i]); printf("\n");
}
/*void heapify(int i, int N){
	int L=2*i;
	int R=2*i+1;
	int max=i;
	if(L<=N&&a[L]>a[i]) max=L;
	if(R<=N&&a[R]>a[max]) max=R;
	if (max!=i){
		swap(i,max);
		heapify(max, N);
		
	}
}
void builHeap(){
	for(int i=n/2; i>=1;i++)
	heapify(i,n);
}
void heapSort(){
	builHeap();
	for(int i=n; i>1; i--){
		swap(1,i);
		heapify(1, i-1);
	}
}*/
int main()
{
	input();
	swap();
	quickSort(0, n-1);
	//heapSort(0,n-1);
    printfResult();
	return 0;
	}

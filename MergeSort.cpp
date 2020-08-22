#include<stdio.h>
#define MAX 100000
int left, mid, right;a
int n,k;
int A[MAX], B[MAX];

void input()
{
	printf("moi nhap so luong cac phan tu cua day n= ");
	scanf("%d",&n);
	printf("moi nhap cac phan tu: ");
	for(int i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
}

void Merge( int A[],int left,int mid, int right)
{ 
    int i= left;
    int j= mid+1;
	for (k= left; k<=right; k++)
	{
		if(i> mid)
		{
		B[k] = A[i]; 
		j++;
		}
		else if(j> right )
		{
			B[k] = A[i];
			i++;
		}
		else{
			if(A[i] < A[j]) {
			B[k] =A[i];
			i++;
			}
			else{
				B[k] = A[j];
        		j++;
			}
		}
    }
    for(int k = left; k<= right; k++){
    	A[k] = B[k];
	}
}
void MergeSort(int A[], int left, int right){
	if(left<right)
	{
		int mid = (left+right)/2;
		MergeSort(A, left, mid);
		MergeSort(A, mid+1, right);
		Merge(A, left, mid, right);	
	}
}
void printfResult(){
	for(int i=0; i<n; i++) printf("%d ",A[i]); printf("\n");
}
main(){
	input();
    MergeSort( A,0 , n-1 );
    printfResult();
	 
}

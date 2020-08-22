#include<stdio.h>
int top=-1;
bool IsFull(int capacity){
	if(top>=capacity-1) return true;
	else return false;
	}
bool IsEmpty(){
	if(top==-1) return true;
	else return false;
}
void Push(int stack[], int value, int capacity){
	if(IsFull(capacity)==true) printf(" stack day\n");
	else{
		++top;
		stack[top]=value;
	}
}
void Pop(){
	if(IsEmpty()== true) printf("stack rong\n");
	else --top;
	}
int Top(int stack[]){
	return stack[top];
	}
int Size(){
	return top+1;
	}
int main(){
	int capacity= 5;
	int stack[capacity];
	Push(stack,22,capacity);
	printf("kich thuoc cua stack la: %d\n", Size());
	Push(stack,1,capacity);
	Push(stack,98,capacity);
	Push(stack,28,capacity);
	Push(stack,11,capacity);
	printf("kich thuoc cua stack la:%d\n",Size());
	Push(stack,2,capacity);
	printf("kich thuoc cua stack la: %d\n", Size());
	for(int i=0; i<5; i++)
		Pop();
	printf("kich thuoc cua stack la: %d\n", Size());
	Pop();
}
	

			

#include<stdio.h>
void Enqueue(int queue[], int element, int& rear, int arraySize){
	if(rear== arraySize) printf("hang doi day\n");
	else {
		queue[rear]=element;
		rear++;
		}
	}
void Dequeue(int queue[], int& front, int rear){
	if(front==rear) printf("hang doi rong\n");
	else{
		queue[front]=0;
		front++;
	}
}
int Front(int queue[], int front){
	return queue[front];
	}
int Size(int front, int rear){
return(rear- front);
}	
bool IsEmpty(int front, int rear){
	return(front==rear);
	}
int main(){
	int queue[10]= {22, 01, 98, 28,11,20};
	int front=0, rear=6;
	int arraySize=20;
	int N=5;
	char ch;
	for(int i=0; i<N; i++){
		ch= Front(queue, front);
		Enqueue(queue,ch,rear,arraySize);
		Dequeue(queue, front, rear);
		}
	for(int i=front; i<rear; i++)
	  printf("%d", queue[i]);
	printf("\n");
	return 0;
		}
	

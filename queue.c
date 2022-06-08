#define m 4
int front=-1,rear=-1,arr[m];

int isEmpty(){
    if(front==rear)
        return 1;
    return 0;
}

int isFull(){
    if(rear==m-1)
        return 1;
    return 0;
}

void push(int item){
    if(isFull())
        printf("Queue is full!!\n");
    else{
        rear=rear+1;
        arr[rear]=item;
    }
}

int pop(){
    if(isEmpty())
    printf("Empty!!\n");
    else{
        front=front+1;
        return arr[front];
    }
}

void display(){
    if(isEmpty())
    printf("Queue is empty!!\n");
    else{
        for(int i=front+1;i<=rear;i++)
        printf("%d\t",arr[i]);
    }
}
#include <stdio.h>
int stack[100],choice,n,top,x,i;
void push(void);
void pop(void);
void display(void);

int main()
{
	top=-1;
	printf("\nEnter the size of STACK[MAX=100]:");
	scanf("%d",&n);
	printf("\n\tSTACK OPERATIONS USING ARRAY");
	printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.EXIT");
	do
	{
		printf("\nEnter the Choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				push();
				break;
				
			case 2:
				pop();
				break;
				
			case 3:
				display();
				break;
				
			case 4:
				printf("\n\tEXIT POINT");
				break;
			
			default:
				printf("\n\tPlease Enter a Valid Choice[1/2/3/4]");
		}
	}while(choice != 4);
}

void push()
{
	if(top>=n-1)
		printf("\n\tSTACK Overflow");
	else
	{
		printf("Enter a value to be pushed:");
		scanf("%d",&x);
		top++;
		stack[top]=x;
	}
}

void pop()
{
	if(top<=-1)
		printf("\n\tSTACK Underflow");
	else
	{
		printf("\n\tThe popped element is %d", stack[top]);
		top--;
	}
}

void display()
{
	if(top>=0)
	{
		printf("\nThe element in STACK\n");
		for(i=top; i>=0; i--)
			printf("\n%d", stack[i]);
	}
	else
		printf("\nThe STACK is empty");
}

#include <stdio.h>
#define MAX 100

typedef struct{
	int row, col, value;
}term;

int i,j;

void readMatrix(term a[])
{
	int r,c,v,k=1;
	printf("Enter number of rows and columns: ");
	scanf("%d %d", &r, &c);
	printf("Enter the matrix elements (%d x %d):\n",r,c);
	for(i=0; i<r; i++)
		for(j=0; j<c; j++){
			scanf("%d",&v);
			if(v != 0)
			{
				a[k].row = i;
				a[k].col = j;
				a[k].value = v;
				k++;
			}
		}
		a[0].row = r;
		a[0].col = c;
		a[0].value = k-1;
}

void displayTranspose(term a[])
{
	printf("Row Col Val\n");
	for(i=0; i<=a[0].value; i++)
		printf("%3d %3d %3d\n", a[i].row, a[i].col, a[i].value);
}

void addMatrices(term a[], term b[], term c[])
{
	int i=1, j=1, k=1;
	c[0].row = a[0].row;
	c[0].col = a[0].col;
	while(i<=a[0].value && j<=b[0].value)
	{
		int posA = a[i].row * a[0].col + a[i].col;
		int posB = b[j].row * b[0].col + b[j].col;
		if(posA < posB) c[k++] = a[i++];
		else if(posA > posB) c[k++] = b[j++];
		else{
			int sum = a[i].value + b[j].value;
			if(sum != 0)
			{
				c[k] = a[i];
				c[k++].value = sum;
			}
			i++; j++;
		}
	}
	while(i<=a[0].value) c[k++] = a[i++];
	while(j<=b[0].value) c[k++] = b[j++];
	c[0].value = k-1;
}

void fastTranspose(term a[], term b[])
{
	int count[MAX] = {0}, pos[MAX], n=a[0].value, cols=a[0].col;
	b[0].row = cols; b[0].col = a[0].row; b[0].value=n;
	for(int i=1; i<=n; i++) count[a[i].col]++;
	pos[0]=1;
	for(int c=1; c < cols; c++)
		pos[c] = pos[c-1] + count[c-1];
	for(int i=1; i<=n; i++){
		int p = pos[a[i].col]++;
		b[p].row = a[i].col; b[p].col = a[i].row; b[p].value = a[i].value;
	}
}

int main(){
	term A[MAX] = {{0}}, B[MAX] = {{0}}, C[MAX];
	int ch;
	do{
		printf("\n1.Read Matrix A \n2.Read Matrix B \n3.Display Triplet \n4.Add Matrices \n5.Transpose of A \n6.Exit \nEnter your Choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				readMatrix(A);
				break;
				
			case 2:
				readMatrix(B);
				break;
				
			case 3:
				printf("A:\n");
				displayTranspose(A);
				printf("B:\n");
				displayTranspose(B);
				break;
				
			case 4:
				if(A[0].row != B[0].row || A[0].col != B[0].col)
					printf("Addition not possible!\n");
				else{
					addMatrices(A,B,C);
					printf("A + B (Triplet Form):\n");
					displayTranspose(C);
				}
				break;
				
			case 5:
				fastTranspose(A,C);
				printf("Transpose of A (Triplet Form):\n");
				displayTranspose(C);
				break;
				
			case 6: printf("Exiting.....\n"); break;
			default: printf("Invalid Choice!\n");
		}
	}while(ch != 6);
	return 0;
}

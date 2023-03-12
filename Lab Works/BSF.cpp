#include<stdio.h>
int main()
{
	int edge, node, a, b, i, j;
	printf("\nenter num of vertices:\n");
	scanf("%d",&node);
	
	int matrix [node][node];
	for (i=0; i<node; i++)
	{
		for (j=0; j<node; j++)
		{
			matrix[i][j]=0;
			
		}
	}
	
	printf("enter num of edges:\n");
	scanf("%d",&edge);
	printf("enter ur edge:\n");
	for (i=0;i<edge;i++)
	{
		scanf("%d%d",&a,&b);
		matrix[a][b]=1;
		matrix[b][a]=1;
	}
	printf("graph:\n");
	for (i=0;i<node;i++)
	{
		for (j=0;j<node;j++)
		{
			printf("%3d", matrix[i][j]);
		}
		
		printf("\n");
	}
	
	return 0;
}
#include<stdio.h>
int main()
{
	int stock[3][4];
	int i,j;
	
	for(i=0;i<3;i++) {
		for(j=0;j<4;j++) {
			scanf("%d",&stock[i][j]);
    	}
	}
	
	int max_stock=1;
	int empty=0;
	int best_row=1;
	
	printf("\nOriginal stock:\n");
	for(i=0;i<3;i++) {
		int current_row_stock=0;
		printf("Aisle %d: ",i+1);
		for(j=0;j<4;j++) {
			printf("%4d",stock[i][j]);
			current_row_stock+=stock[i][j];
		}
		if(current_row_stock>max_stock) {
			max_stock=current_row_stock;
			best_row=i+1;
		}
		printf("\n");
	}
	printf("\nAisle with most stock: Aisle %d (%d units)\n",best_row,max_stock);
	
	printf("\nLow stock alerts:\n");
	for(i=0;i<3;i++) {
		for(j=0;j<4;j++) {
			if(stock[i][j]<5) {
				printf("Aisle %d, Position %d -> %d units\n",i+1,j+1,stock[i][j]);
			}
			if(stock[i][j]==0) {
				empty++;
			}
		}
	}
	printf("\nEmpty shelves: %d\n",empty);
	
	for(i=0;i<3;i++) {
		for(j=0;j<4;j++) {
			if(stock[i][j]<5)
			{
				stock[i][j]+=10;
			}
		}
	}
	
	int grand_total=0;
	printf("Stock after restocking:\n");
	for(i=0;i<3;i++) {
		printf("Aisle %d:",i+1);
		for(j=0;j<4;j++) {
			printf("%4d",stock[i][j]);
			grand_total+=stock[i][j];
		}
		printf("\n");
	}
	printf("\nNew grand total : %d units",grand_total);
	return 0;
}

#include<stdio.h>
int main()
{
	int seats[5][6]={0};
	int row,col;
	int i,j;
	int booked=0,empty=0;
	do
	{
		printf("Enter Row no. :\n");
		scanf("%d",&row);
		
		if(row==-1){
		break; }
		
		printf("Enter Column no. :\n");
		scanf("%d",&col);
		
		if (row < 1 || row > 5 || col < 1 || col > 6) {
        printf("Error: Invalid row or column!\n");
        continue; 
    	}
		
		if (seats[row - 1][col - 1] == 1) {
		    printf("Error: Seat already booked!\n");
		} else {
		    seats[row - 1][col - 1] = 1;
		    printf("Seat booked successfully.\n");
		}
		
	}
	while(row!=-1);
	
	printf("Seating Chart :\n");
	printf("   1 2 3 4 5 6\n");
	for(i=0;i<5;i++) {
		printf("Row %d ",i+1);
		for(j=0;j<6;j++) {
			if(seats[i][j]==1)
			{
				printf("X ");
				booked++;
			}
			else
			{
				printf("O ");
				empty++;
			}
		}
		printf("\n");
	}
	printf("Total booked seats : %d\n",booked);
	printf("Total empty seats : %d\n",empty);
	
	int best_row=1;
	int max_booked_seats=-1;
	
	for(i=0;i<5;i++) {
		int current_row_booked_seats=0;
		for(j=0;j<6;j++) {
			if(seats[i][j]==1) {
				current_row_booked_seats++; 
			}
	    }
	    if(current_row_booked_seats>max_booked_seats){
				max_booked_seats=current_row_booked_seats;
				best_row=i+1;
		    }
	}
	printf("Row with most bookings : Row %d",best_row);
	return 0;
	
}

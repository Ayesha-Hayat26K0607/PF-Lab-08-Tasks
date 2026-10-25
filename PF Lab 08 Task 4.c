#include<stdio.h>
int main()
{
	int beds[2][3][2]={0}; //2 floor,3 wards,2 beds
	int choice;
	int floor,id;
	int i,j,k;
	do{
		printf("\nSelect an option from menu: \n");
		printf("1-Admit\n2-Discharge\n3-Report\n4-Exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: {
				int admitted=0;
				printf("Enter the floor :");
				scanf("%d",&floor);
				
				if(floor<1 || floor>2){
					printf("Invalid floor\n");
					do{
					printf("Please re-enter the correct floor : \n");
					scanf("%d",&floor);
					}while(floor<1 || floor>2);
				}
				
				
				int floor_index=floor-1;
				
				printf("Enter patient ID :");
				scanf("%d",&id);
				for(j=0;j<3;j++) {
					for(k=0;k<2;k++) {
						if(beds[floor_index][j][k]==0) {
							beds[floor_index][j][k]=id;
							printf("Patient %d admitted: Floor %d, Ward %d, Bed %d",id,floor,j+1,k+1);
							admitted=1;
							break;
						}	
					}
					if(admitted) {
						break;
					}
				}	
				if(!admitted) {
					printf("\nFloor %d is full.",floor);
				}
			break;
			}
			case 2: {
				printf("Enter patient ID :");
				scanf("%d",&id);
				
				int found=0;
				
				for(i=0;i<2;i++) {
					for(j=0;j<3;j++) {
						for(k=0;k<2;k++) {
							if(beds[i][j][k]==id) {
								beds[i][j][k]=0;
								printf("Patient %d discharged from Floor %d, Ward %d, Bed %d\n",id,i+1,j+1,k+1);
								
								found=1;
								break;
							}
						}
					if(found) break;
					}
				if(found) break;
				}
			if(!found) {
				printf("Patient ID %d not found.\n",id);
			}
			break;
			}
			case 3: {
				float highest_occupancy=0;
				int highest_occupancy_floor=0;
				int highest_occupancy_ward=0;
				int max_ward_occupied=0;
				int max_floor_occupied=0;
					
				printf("---Occupancy Report---\n");
				for(i=0;i<2;i++) {
					int floor_occupied=0;
					
					printf("Floor %d\n",i+1);
					for(j=0;j<3;j++) {	
						int ward_occupied=0;
						int ward_vacant=0;					
						for(k=0;k<2;k++) {
							if(beds[i][j][k]==0) {
								ward_vacant++;
							}
							else{
								ward_occupied++;
								floor_occupied++;
							}
						}
						printf("Ward %d: Occupied %d, Vacant %d\n",j+1,ward_occupied,ward_vacant);
						
						
						if(ward_occupied>max_ward_occupied){
							max_ward_occupied=ward_occupied;
							highest_occupancy_ward=j+1;
							highest_occupancy_floor=i+1;
						}
					}
					
					float floor_occupancy=0;

					floor_occupancy=(floor_occupied / 6.0)*100; // 3 wards x 2 beds =6 total beds (on each floor)
					printf("Floor occupancy: %.1f\n",floor_occupancy);
					if(floor_occupancy>highest_occupancy) {
						highest_occupancy=floor_occupancy;
					}
				}
				printf("Highest occupany: Floor %d,Ward %d (%d occupied)",highest_occupancy_floor,highest_occupancy_ward,max_ward_occupied);
				break;
				}
				case 4:
					printf("Exiting...\n");
					break;
		}
	}while(choice!=4);
	return 0;
}

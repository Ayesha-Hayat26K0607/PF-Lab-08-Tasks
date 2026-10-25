#include<stdio.h>
#include<limits.h>
int main()
{
	int marks[4][3];
	int i,j;
	
	for(i=0;i<4;i++) {
		for(j=0;j<3;j++) {
			
			do{
			scanf("%d",&marks[i][j]);
			
				if(marks[i][j]<0 || marks[i][j]>100) { 
					printf("Invalid mark! Enter a value between 0 and 100.\n");
				}
		    } while(marks[i][j] < 0 || marks[i][j] > 100);
    	}
	}
	    printf("\n%-10s %8s %8s %8s %8s %8s %5s\n", "Student", "Prog", "Calc", "Phys", "Total", "Average", "Grade");
    
    for(i = 0; i < 4; i++) {
        int total = 0;   
        for(j = 0; j < 3; j++) {
            total += marks[i][j];
        }
        
        float average = total / 3.0; 
        char grade;
        
       
        if (average >= 80) grade = 'A';
        else if (average >= 65) grade = 'B';
        else if (average >= 50) grade = 'C';
        else grade = 'F';
        
        printf("Student %d  %8d %8d %8d %8d %8.2f %5c\n", 
               i + 1, marks[i][0], marks[i][1], marks[i][2], total, average, grade);
    }

	    printf("\nSubject statistics:\n");
    printf("%-15s %8s %8s %8s\n", "Subject", "Highest", "Lowest", "Average");

    
    char* subject_names[3] = {"Programming", "Calculus", "Physics"};

    for (j = 0; j < 3; j++) {
        int sum = 0;
        int highest = marks[0][j]; 
        int lowest = marks[0][j];  

        for (i = 0; i < 4; i++) {
            sum += marks[i][j];

         
            if (marks[i][j] > highest) {
                highest = marks[i][j];
            }
           
            if (marks[i][j] < lowest) {
                lowest = marks[i][j];
            }
        }

        float subj_avg = sum / 4.0; 

        printf("%-15s %8d %8d %8.2f\n", subject_names[j], highest, lowest, subj_avg);
    }
    return 0;
}


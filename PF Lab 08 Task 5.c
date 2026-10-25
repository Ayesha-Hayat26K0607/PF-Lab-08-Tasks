#include<stdio.h>
int main()
{
	int image[4][4];
	int i,j;
	int brightness,threshold;
	
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			scanf("%d",&image[i][j]);
		}
	}
	
	printf("Enter brightness: ");
	scanf("%d",&brightness);
	printf("\nEnter threshold: ");
	scanf("%d",&threshold);
	
	printf("\nOriginal image: \n");
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			printf("%5d",image[i][j]);
		}
		printf("\n");
	}
	
	printf("Brightness (%+d): \n",brightness);
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			int temp;
			
			temp=image[i][j]+brightness;
			if(temp>255){
				temp=255;
			}
			if(temp<0) {
				temp=0;
			}
			printf("%5d",temp);
		}
		printf("\n");
	}
	
	printf("Black and white (threshold %d): \n",threshold);
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			int temp;
			temp=image[i][j];
			if(temp>=threshold) {
			temp=255;
			}
			else{
				temp=0;
			}
			printf("%5d",temp);
		}
		printf("\n");
	}
	
	printf("\nFlipped horizontally: \n");
	for(i=0;i<4;i++) {
		for(j=3;j>=0;j--) {
			printf("%5d",image[i][j]);
		}
		printf("\n");
	}
	
	int result[4][4];
	int r,c;
	
	for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            result[i][j] = image[i][j];
        }
    }

    // Process only interior pixels (index 1 and 2 for both rows and columns)
    for (i = 1; i < 3; i++) {
        for (j = 1; j < 3; j++) {
            int sum = 0;
            // Loop through the 3x3 neighborhood around the current pixel
            for (r = -1; r <= 1; r++) {
                for (c = -1; c <= 1; c++) {
                    sum += image[i + r][j + c];
                }
            }
            result[i][j] = sum / 9; // Integer division average
        }
    }
    
    printf("Smoothed image:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%5d", result[i][j]);
        }
        printf("\n");
    }
    return 0;
	
	/* 
 * EXPLANATION FOR REQUIREMENT #6:
	  We must use a second array ('result') because if we modify the original 'image' 
	  array directly during the smoothing operation, the newly calculated averages of 
	  early interior pixels (like image[1][1]) would overwrite their original values. 
	  
	  Consequently, when the loop moves to calculate subsequent neighboring pixels 
	  (like image[1][2] or image[2][1]), it would use these already-changed/corrupted 
	  values rather than the pure, original pixel values. This would completely 
	  break the filter's mathematical calculations.
 */

}

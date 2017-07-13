#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
		int num = 1;
		int index = 0;
		int result = 0;

		printf("1--剪刀\n");
		printf("2--石头\n");
		printf("3--布\n");

		srand((unsigned)time(NULL));
		
		printf("Please input a number:");
		scanf("%d",&num);
		while(getchar()!='\n');
		switch(num){
			case 1:
					printf("user choose the 剪刀\n");
					break;
			case 2:
					printf("user choose the 石头\n");
					break;
			case 3:
					printf("user choose the 布\n");
					break;
			default:
					printf("wrong input!\n");
					exit(-1);
		}

		index = rand()%3 + 1;
		switch(index){
			case 1:
					printf("computer choose the 剪刀\n");
					break;
			case 2:
					printf("computer choose the 石头\n");
					break;
			case 3:
					printf("computer choose the 布\n");
					break;
		}


		if(num==index)
		{
				printf("the same!\n");
		}else if((num-index==1)||(1==num&&3==index)){
				printf("user win!\n");
		}else{
				printf("computer win!\n");
		}
		
		

		return 0;
}

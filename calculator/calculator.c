#include <stdio.h>

int main()
{
		float a,b;
		char sym;

		printf("Welcome to calculator\n");
		printf("Please input first number:\n");
		scanf("%f",&a);
		while(getchar()!='\n');
		printf("Please input symbol:\n");
		scanf("%c",&sym);
		while(getchar()!='\n');
		printf("Please input second number:\n");
		scanf("%f",&b);
		while(getchar()!='\n');
		if(sym=='+')
		{
				printf("a+b=%f\n",a+b);
		}else if(sym=='-'){
				printf("a-b=%f\n",a-b);
		}else if(sym=='*'){
				printf("a*b=%f\n",a*b);
		}else if(sym=='/'){
				printf("a/b=%f\n",a/b);
		}else{
				printf("wrong symbol!!!\n");
		}
		return 0;
}

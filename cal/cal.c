#include <stdio.h>

int main()
{
		float a,b;
		char sym;
		
		printf("Welcome to calculator\nplase input:\n");
		scanf("%f%c%f",&a,&sym,&b);
		while(getchar()!='\n');
		if(sym=='+')
		{
				printf("%f+%f=%f\n",a,b,a+b);
		}else if(sym=='-'){
				printf("%f-%f=%f\n",a,b,a-b);
		}else if(sym=='*'){
				printf("%f*%f=%f\n",a,b,a*b);
		}else if(sym=='/'){
				printf("%f/%f=%f\n",a,b,a/b);
		}else{
				printf("wrong symbol!!!\n");
		}

		return 0;
}

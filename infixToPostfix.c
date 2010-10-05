#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//function prototypes
int check_operater(char);
int priority(char optr);

int main()
{
	int i,top=-1,k=0;
	char expr[50],stack[50],ans[50];
	printf("\n Enter the expretion : ");//taking expr
	gets(expr);
	for(i=0;expr[i]!='\0';i++)//traveling expr
	{	
		if(expr[i]=='(')
		{     
                        //checking for validness
			if(i>=0 && i < (strlen(expr)-1))
			{
				if(check_operater(expr[i+1])==1 || expr[i+1]==')')
				{
					printf("\n Invalid Expration\n");
					return 0;	
				}
				
			}
			if(i>0)
			{
				if(check_operater(expr[i-1])==0 && expr[i-1]!='(')
				{
					printf("\n Invalid Expration\n");
					return 0;	
				}
			}
			top=top+1;
			stack[top]=expr[i];//push 
		}
		else if(expr[i]==')')
		{
			   //checking for validness
			if(i>=0 && i < (strlen(expr)-1))
			{
				if(check_operater(expr[i+1])==0 && expr[i+1]!=')')
				{
					printf("\n Invalid Expration\n");
					return 0;	
				}
				
			}
			if(i>0)
			{
				if(check_operater(expr[i-1])==1 || expr[i-1]=='(')
				{
					printf("\n Invalid Expration\n");
					return 0;	
				}
			}
						
			while(stack[top]!='(')	//pop
			{
				printf("%c",stack[top]);
				ans[k]=stack[top];
				k=k+1;
				top--;
			}		
			top--;
			
		}
		else if(check_operater(expr[i])==0)
		{	   
			//checking for validness
			if(i>=0 && i < (strlen(expr)-1))
			{
				if(check_operater(expr[i+1])==0 && expr[i+1]!=')')
				{
					printf("\n Invalid Expration\n");
					return 0;	
				}
				
			}
			if(i>0)
			{
				if(check_operater(expr[i-1])==0 && expr[i-1]!='(')
				{
					printf("\n Invalid Expration\n");
					return 0;	
				}
			}
			printf("%c",expr[i]);
			ans[k]=expr[i];			
			k=k+1;
		}
		else 
		{
			//check priority between current and stack[top] char
			if(priority(expr[i])<=priority(stack[top]))
			{
				printf("%c",stack[top]);//pop
				ans[k]=stack[top];
				k=k+1;
				top--;
			}
			top=top+1;
			stack[top]=expr[i];			
			
		}
	}//end of main for 
	if(top!=-1)//if expr is end
	{
		while(top!=-1)//pop
		{
			printf("%c",stack[top]);
			ans[k]=stack[top];
			k=k+1;
			top--;
		}
	}
	for(i=0;i<k;i++)
	{
		printf("%c",ans[i]);
	}

}//end of main function

int check_operater(char optr)//weather current char is oprater or anything else
{
	switch(optr)
	{
		case '+':
		case '-':
		case '*':
		case '/': return 1;
		default : return 0;			
	}//switch	
 		
}

int priority(char optr) //to check priority of operator
{
	switch(optr)
	{
		case '+':
		case '-':return 1;
		case '*':
		case '/': return 2;
		default : return -1;			
	}//switch	
 	
}

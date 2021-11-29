#include <stdio.h>
#include <stdbool.h>

char state[10][20] = {"AT(robot,c)", "EMPTY(robot)",
	 "ON(box,a)", "TABLE(a)", "TABLE(b)"};

char end_state[5][20] = {"AT(robot,c)", "EMPTY(robot)",
	 "ON(box,b)", "TABLE(a)", "TABLE(b)"};

int state_num = 5;
int number;

bool IsInState(char *S1) 
{
	int i, j;
	bool flag;

	for(i=0;i<state_num;i++)
	{
		j=0;
		flag=true;
		while(S1[j]!='\0')
		{
			if(S1[j] != state[i][j])
			{
				flag = false;
				break;
			}
			j++;
		}
		if(flag && state[i][j]=='\0')
		{
			number=i;
			return true;
		}
	}
	return false;
}

void Delete(int k)
{
	if(k>=state_num)
	{
		printf("The appointed state is not in the state set!");
		return;
	}
	int i,j;
	for(i=k;i<state_num;i++)
	{
		for(j=0;*(state[i+1]+j)!='\0';j++)
			state[i][j]=state[i+1][j];
		state[i][j]='\0';
	}
	state_num--;
}

void Insert(char *S)
{
	if(state_num>=10)
	{
		printf("The state space is overwrited!");
		return;
	}
	int j;
	for(j=0;S[j]!='\0';j++)
		state[state_num][j]=S[j];
	state[state_num][j]='\0';

	state_num++;
}

bool GoTo(char x,char y)
{
	char S1[20]="AT(robot,x)",S2[20]="AT(robot,x)";

	S1[9]=x; S2[9]=y;

	if(IsInState(S1))
	{
		Delete(number);
		Insert(S2);
		return true;
	}
	else
	{
		printf("Cannot go from %c to %c\n",x,y);
		return false;
	}
}

bool PickUp(char x)
{
	char S[5][20]={"ON(box,x)","TABLE(x)","AT(robot,x)","EMPTY(robot)","HOLDS(robot,box)"};
	S[0][7]=x;
	S[1][6]=x;
	S[2][9]=x;
	
	if(IsInState(S[1]) && IsInState(S[2]))
	{
		if(IsInState(S[0]))
			Delete(number);
		else
		{
			printf("Cannot pickup %c",x);
			return false;
		}
		if(IsInState(S[3]))
			Delete(number);
		else
		{
			printf("Cannot pickup %c",x);
			return false;
		}
		Insert(S[4]);
		return true;	
	}
		{
			printf("Cannot pickup %c",x);
			return false;
		}
}

bool SetDown(char x)
{
	char S[5][20]={"AT(robot,x)","TABLE(x)","HOLDS(robot,box)","EMPTY(robot)","ON(box,x)"};
	S[0][9]=x;
	S[1][6]=x;
	S[4][7]=x;

	if(IsInState(S[0]) && IsInState(S[1]))
	{
		if(IsInState(S[2]))
			Delete(number);
		else 
		{
			printf("Cannot set down %c",x);
			return false;
		}
		Insert(S[3]); Insert(S[4]);
		return true;
	}
	return false;
}

void ShowState(char s[10][20],int num)
{
	int i;
	printf("   ");
	for(i=0;i<num;i++)
		printf("%s ",s[i]);
	printf("\n");
}

void main()
{
	printf("the process as follows:\n\nThe start state:\n");
	ShowState(state,state_num);
	printf("(1) Go from c To a:\n");
	if(!GoTo('c','a'))	
		return;
	ShowState(state,state_num);
	printf("(2) PickUp a:\n");
	if(!PickUp('a'))	
		return;
	ShowState(state,state_num);
	printf("(3) Go from a To b:\n");
	if(!GoTo('a','b'))	
		return;
	ShowState(state,state_num);
	printf("(4) SetDown b:\n");
	if(!SetDown('b'))		
		return;
	ShowState(state,state_num);
	printf("(5) Go from b To c:\n");
	if(!GoTo('b','c'))	
		return;
	ShowState(state,state_num);

	printf("Cai Tengfei 201931061305");
}

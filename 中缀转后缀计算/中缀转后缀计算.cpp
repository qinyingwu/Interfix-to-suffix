#include"stdafx.h"

#define MAX 50

#include<stdio.h>
#include <stdlib.h>
struct Stack

{ int data[MAX] ;

  int top ; } S;

void PushStack (Stack *S,  int x)

{ if (S->top<MAX)

    { S->top++; S->data[S->top]=x; }

  else

     printf("ÉÏÒç") ; } 

int PopStack(Stack *S)

{ if(S->top>0)

    { S->top--; return S->data[S->top+1]; }

  else

    { printf("ÏÂÒç"); return 0;}

}

int calculate(int x,int y,char op)

{ int result;

  switch(op)

  {case '+': result=x+y;break;

   case '-': result=x-y;break;

   case '*': result=x*y;break;

   case '/': result=x/y;break;}

  return result; }



int GerPriority(int ch)

{ int priority = -1;

  switch(ch)

  {	case '+':case '-':priority=2;break;

	case '*':case '/':priority=3;break;

	case '(':priority=1;break;

	case '[':priority=0;break;

	case '#':priority=-1;break;  }

  return priority;

}



void main()

{ char midstr[MAX],poststr[MAX];

  int top1,top2,result,top;

  int i=0,j=0;

  S.top = 0 ;

  PushStack(&S,'#');

  gets(midstr);

  while(midstr[i]!=0)

  { if(midstr[i]>='a' && midstr[i]<='z' || midstr[i]>='0' && midstr[i]<='9') poststr[j++]=midstr[i];

  else if(midstr[i]=='(') {poststr[j++]=' ';PushStack(&S,midstr[i]);}

  else if(midstr[i]=='[') {poststr[j++]=' ';PushStack(&S,midstr[i]);}

	else if(midstr[i]==')')

	{ poststr[j++]=' ';

		while(S.data[S.top]!='(')	poststr[j++]=PopStack(&S);

	  PopStack(&S);	}

	else if(midstr[i]==']')

	{ poststr[j++]=' ';

		while(S.data[S.top]!='[')	poststr[j++]=PopStack(&S);

	  PopStack(&S);	}

	else 

	{ poststr[j++]=' ';

	  while(GerPriority(midstr[i])<=GerPriority(S.data[S.top]))

	     poststr[j++]=PopStack(&S);

	  PushStack(&S,midstr[i]);	}

	i++;  }

  poststr[j++]=' ';

  while(S.data[S.top] != '#') poststr[j++]=PopStack(&S);

  poststr[j]=0;

  puts(poststr); 

  PopStack(&S);



  i=0;

  while(poststr[i]!=0)

  { if( poststr[i]>='0' && poststr[i]<='9' ) 

	{

	  top=0;

	  while(poststr[i]!=' ') {top = top*10 + poststr[i] - '0';i++;}



	  PushStack(&S,top);

	}

	else if(poststr[i]==' ') i++;

	else 

	{ 

		top2=PopStack(&S); 

		top1=PopStack(&S); 

		result=calculate(top1,top2,poststr[i]);

	    PushStack(&S,result);

		i++;

	}

  }
  system("pasue");
  printf("%d",result);
}
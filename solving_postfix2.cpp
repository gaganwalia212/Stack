#include <iostream>
#include<cmath>
#include<string>
using namespace std;
/************************************************STACK OF GENERAL TYPE************************************************************************/
template <typename t>
class Stack
{
    int top=-1;
    int size;
    t * s;
public:
    Stack(int=0);
    ~Stack();
    void push(t x);
    t pop();
    t stack_top();
    bool is_empty();
    void display();
};
template <typename t>
void Stack<t>::display()
{
    int x=top;
    while(x>=0)
    {
        cout<<s[x]<<" ";
        x--;
    }
}

template <typename t>
Stack<t>::Stack(int x)
{
    size=x;
    s=new t[size];
}

template <typename t>
Stack<t>::~Stack()
{
    delete []s;
}

template <typename t>
void Stack<t>::push(t x)
{
   if(top==size-1)
   {
       cout<<"stack overflow\n";
       return;
   }
   top++;
   s[top]=x;
}

template <typename t>
t Stack<t>::pop()
{
    if(top==-1)
        return '\0';
    t f=s[top];
    top--;
    return f;
}

template <typename t>
bool Stack<t>::is_empty()
{
    if(top==-1)
        return true ;
    else return false;
}

template <typename t>
t Stack<t>::stack_top()
{
    if(top==-1)
        return '\0';
    return s[top];
}
/**************************************************INFIX TO POSTFIX**********************************************/
bool is_operator(char c)
{
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'||c==')'||c=='('||c=='l'||c=='m')
        return true;
    return false;
}

int in_prec(char c)
{
    switch(c)
    {
    case('+'):
    case('-'): return 2;
    case('*'):
    case('/'):return 4;
    case('^'):return 5;
    case('('):return 0;
    case('l'):return 9;
    case('m'):return 7;
    default:return -1;

    }
}

int out_prec(char c)
{
    switch(c)
    {
    case('+'):
    case('-'): return 1;
    case('*'):
    case('/'):return 3;
    case('^'):return 6;
    case('('):return 11;
    case(')'):return 0;
    case('m'):return 8;
    case('l'):return 10;
    default:return -1;

    }
}

bool is_binary(char c)
{
    if(c=='l'||c=='m')
        return false;
    else return true;
}

string to_postfix(string s)
{
    if(s[0]=='-')
        s[0]='m';
    int position;
    //changing symbols for unary operator so that they are unique and sing character
    //symbol for log is l and for unary minus(negation) is m
    do
    {
        position=s.find("log");
        if(position!=string::npos)
            s.erase(position+1,2);
    }while(position!=string::npos);

     do
    {
        position=s.find("(-");
        if(position!=string::npos)
            s[position+1]='m';
    }while(position!=string::npos);

    Stack<char> st(s.size());
    string postfix;
    int i=0;
    while(s[i]!='\0')
    {
        if(is_operator(s[i]))
        {
            if(s[i]==')')
            {
                while(st.stack_top()!='(')
                        postfix+=st.pop();
                st.pop();
                i++;
            }
            else if(out_prec(s[i])>in_prec(st.stack_top())||st.is_empty())
                st.push(s[i++]);
            else
                postfix=postfix+st.pop();
        }
        else postfix+=s[i++];
    }

    while(!st.is_empty())
        postfix+=st.pop();
    return postfix;
}

/***********************************SOLVING POSTFIX**********************************************************/

/*####NOTE:This method DOES NOT work with double digit numbers###*/
//Here we will be also considering two unary operators-log and negative
float solve_postfix(string s)
{
    Stack<float>st(s.size());
    float x1,x2;
    for(int i=0;s[i]!=0;i++)
    {
        if(is_operator(s[i]))
        {
            //Process for binary operators is same:
            if(is_binary(s[i]))
            {
                x2=st.pop();
                x1=st.pop();
                switch(s[i])
                {
                    case('+'):st.push(x1+x2);break;
                    case('-'):st.push(x1-x2);break;
                    case('*'):st.push(x1*x2);break;
                    case('/'):st.push(x1/x2);break;
                    case('^'):st.push(pow(x1,x2));break;
                }
            }

            else
            {
            //Process for unary operator
                x1=st.pop();
                switch(s[i])
                {
                    case('l'):st.push(log10(x1));break;
                    case('m'):st.push(-x1);break;
                }
            }
        }
        else st.push(s[i]-'0');
    }
    return st.pop();

}
int main()
{
  string s;
  cin>>s;
  cout<<(to_postfix(s))<<endl;
  cout<<solve_postfix(to_postfix(s))<<endl;

    return 0;
}

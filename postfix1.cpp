#include<iostream>
#include<string>
using namespace std;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//We will create a stack of a character
class Stack {
int size;
int top=-1;
char*s;
public:
    Stack(int );
    ~Stack();
    bool is_empty();
    bool is_full();
    void push(char);
    char pop();
    void display();
    char peak(int);
    char stack_top();
    friend string to_postfix(string);
};

Stack::Stack(int x=0):size{x}
{
    s=new char [size];
}

Stack::~Stack()
{
    delete []s;
    cout<<"Stack deleted\n";
}

bool Stack:: is_empty()
{
    if(top==-1)
        return true;
    else return false;
}

bool Stack::is_full()
{
    if(top==size-1)
        return true;
    else return false;
}

void Stack::push(char x)
{
    try
    {
        if(is_full())
            throw string {"Stack Overflow\n"};
        top++;
        s[top]=x;
    }
    catch (string & s)
    {
        cout<<s;
    }

}

char Stack::pop()
{
    char x='\0';
    try
    {
        if(is_empty())
            throw string{"Stack underflow\n"};
            x=s[top];
            top--;
            return x;
    }

    catch(string & s)
    {
        cout<<s;
        return x;
    }
}

void Stack::display()
{
    if(top==-1)
    {
        cout<<"[]\n";
        return;
    }
    int x=top;
    while(x>=0)
    {
        cout<<s[x]<<endl;
        x--;
    }
}

char Stack::peak(int pos)
{
    int i=pos-top+1;
    try
    {
        if(i<0||i>top)
            throw string{"Invalid Position\n"};
            return s[i];
    }
    catch(string & s)
    {
        cout<<s;
        return '\0';
    }
}

char Stack::stack_top()
{
    try
    {
        if(top==-1)
        throw string{"Stack is empty\n"};
        return s[top];
    }
    catch(string & s)
    {

        return '\0';
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//      POSTFIX TO INFIX CONVERSION

//      FUNTION WHICH WILL TELL WHETHER A CHARACTER IS AN OPERATOR OR NOT
//      ONLY CONSIDERING 4 OPERATORS HERE- + - * /
bool is_operator(char c)
{
    if(c=='+'||c=='*'||c=='-'||c=='/')
        return true;
    return false;
}

//      FUNTION TO RETURN PRECEDENCE OF OPERATORS
int prec(int c)
{
    if(c=='+'||c=='-')
        return 1;
    if(c=='*'||c=='/')
        return 2;
    return 0;
}

//      FUNCTION WHICH RETURNS POSTFIX STRING
string to_postfix(string s)
{
    string postfix;
    Stack st(s.size());
    int i=0;
    while(s[i]!='\0')
    {
        if(is_operator(s[i]))
        {
            if(prec(s[i])>prec(st.stack_top())||st.is_empty())
                st.push(s[i++]);
            else
                {
                    postfix=postfix+st.pop();
                }
        }

        else
        {
            postfix=postfix+s[i++];
        }
    }
    while(!st.is_empty())
        postfix=postfix+st.pop();

    return postfix;

}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    cout<<"Enter expression for parenthesis checking-";
    string s;
    cin>>s;
    cout<<to_postfix(s);


    return 0;
}

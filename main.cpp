#include<iostream>
#include<string>
using namespace std;

//We will create a stack of a character since we need to push the '(' character
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
        cout<<s;
        return -1;
    }
}
bool check_paranthesis(string s)
{
    Stack S(s.size());
    for(int i=0;s[i]!=0;i++)
    {
        if(s[i]=='(')
            S.push('(');
        if(s[i]==')')
        {
            if(S.is_empty())
                return false;
            else S.pop();
        }
    }
    return S.is_empty()? true:false;
}

int main()
{
    cout<<"Enter expression for parenthesis checking-";
    string s;
    cin>>s;
    if(check_paranthesis(s))
        cout<<"Parenthesis are matching \n";
    else cout<<"Parenthesis not matching\n";

    return 0;
}

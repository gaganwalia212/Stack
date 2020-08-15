#include<iostream>
using namespace std;

class Stack {
int size;
int top=-1;
int*s;
public:
    Stack(int );
    ~Stack();
    bool is_empty();
    bool is_full();
    void push(int);
    int pop();
    void display();
    int peak(int);
    int stack_top();
};

Stack::Stack(int x=0):size{x}
{
    s=new int [size];
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

void Stack::push(int x)
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

int Stack::pop()
{
    int x=-1;
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

int Stack::peak(int pos)
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
        return -1;
    }
}

int Stack::stack_top()
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


int main()
{
    cout<<"Enter size of stack-";
    int n;
    cin>>n;
    char c{'0'};
    Stack s(n);
    do{
            cout<<"\n\=======================================================\n";
        cout<<"1-Push\n";
        cout<<"2-Pop\n";
        cout<<"3-Peak\n";
        cout<<"4-Stack Top\n";
        cout<<"5-Is stack full?\n";
        cout<<"6-Is stack empty?\n";
        cout<<"7-Display stack\n";
        cout<<"Enter Q to exit\n";
        cout<<"Input-";
        cin>>c;

        switch(c)
        {
            case('1'):
            {
                cout<<"Enter element you want to push-";
                cin>>n;
                s.push(n);
            }
            break;
            case('2'):s.pop();break;
            case('3'):
            {
                cout<<"Enter position-";
                cin>>n;
                if(s.peak(n)!=-1)
                    cout<<s.peak(n);
            }
            break;

            case('4'):
            {
                if(s.stack_top()!=-1)
                    cout<<s.stack_top();
            }
            break;
            case('5'):
            {
                if(s.is_full())
                    cout<<"stack is full";
                else cout<<"stack is not full";
            }
            break;
             case('6'):
            {
                if(s.is_empty())
                    cout<<"stack is empty";
                else cout<<"stack is not empty";
            }
            break;
            case('7'):s.display();break;
            case('q'):
            case('Q'):
            break;
            default:cout<<"Enter valid input";

        }
    }while(c!='q'&&c!='Q');

    return 0;
}

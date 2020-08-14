#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node*next=0;
};

class Stack {
Node*top=0;
public:
    ~Stack();
    bool is_empty();
    bool is_full();
    void push(int);
    void pop();
    void display();
    int peak(int);
    int stack_top();
};



Stack::~Stack()
{
    Node*p=0;
    while(top)
    {
        p=top;
        top=top->next;
        delete p;
    }
    cout<<"Stack deleted\n";
}

bool Stack:: is_empty()
{
 return top?false:true;
}

bool Stack::is_full()
{
    Node*t=new Node;
    return t?false:true;
}

void Stack::push(int x)
{
   Node*t=new Node;
   if(!t)
   {
       cout<<"Stack Overflow\n";
       return;
   }
   t->data=x;
   t->next=top;
   top=t;

}

void Stack::pop()
{
    if(!top)
    {
        cout<<"Stack Underflow\n";

    }
    Node*p{top};
    top=top->next;
    delete p;
}

void Stack::display()
{
    if(top==0)
    {
        cout<<"Stack is empty\n";
        return;
    }
    Node*p=top;
    while(p)
    {
        cout<<"["<<p->data<<"]"<<endl;
        p=p->next;
    }
}

int Stack::peak(int pos)
{
    Node*p=top;
    for(int i=0;i<pos-1&&p;i++)
        p=p->next;
    if(!p||pos<1)
    {
        cout<<"Invalid position\n";
        return -1;
    }
    return p->data;
}

int Stack::stack_top()
{
    if(!top)
    {
        cout<<"Stack underflow\n";
        return -1;
    }

    return top->data;
}


int main()
{
    int n;
    char c{'0'};
    Stack s;

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

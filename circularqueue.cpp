#include <iostream>
using namespace std;

class queue
{
    int r, f;
    int arr[5];

public:
    queue()
    {
        r = -1;
        f = -1;
    }
    void enqueue(int);
    void display();
    void dequeue();
};

void queue::enqueue(int a)
{
    if (r == -1 && f == -1)
    {
        arr[++r] = a;
        f++;
    }
    else
    {
        if ((r + 1) % 5 != f)
        {
            r = (r + 1) % 5;
            arr[r] = a;
        }
        else
        {
            cout << "queue id full\n";
        }
    }
}

void queue::display()
{
    int temp = f;
    if (r == -1 && f == -1)
    {
        cout << "queue is empty\n";
    }
    else
    {
        while (temp != r)
        {
            cout << arr[temp] << "  ";
            temp = (temp + 1) % 5;
        }
    }
    cout << arr[temp] << endl;
}

void queue::dequeue()
{
    if(f==-1 && r==-1){
        cout<<"queue is already empty\n;";
        return;
    }
    cout << "deleted element is " << arr[f] << endl;
    if (f == r)
    {
        cout << "queue is now empty\n";
        f = -1;
        r = -1;
    }
    else
    {
        f = (f + 1) % 5;
    }
}

int main()
{
    queue obj;
    int opt;
    char choice;
    do
    {
        cout << "enter what to do:: 1:add  2:dequeue  3:display\n";
        cin >> opt;
        switch (opt)
        {
        case 1:
            int temp;
            cout << "enter what to enqueue::";
            cin >> temp;
            obj.enqueue(temp);
            break;

        case 2:
            obj.dequeue();
            break;

        case 3:
            obj.display();
            break;

        default:
            cout<<"enter valid option\n";
            break;
        }
        cout << "do you want to continue(y/n)::";
        cin >> choice;
    } while (choice == 'y' || 'Y');
}

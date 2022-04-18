#include <iostream>
using namespace std;
const int QUEUE_CAPACITY = 128;
template <typename QueueElement>
class Queue
{
public:
    Queue();
    bool empty()const;
    void add(QueueElement& value);
    void Remove();
    QueueElement front() const;
    void display()const;
private:
    int myfront;
    int myback;
    QueueElement myarray[QUEUE_CAPACITY];
};
template <typename QueueElement>
Queue<QueueElement>::Queue()
{
    myfront = myback = -1;
}
template <typename QueueElement>
bool Queue<QueueElement>::empty() const
{
    return (myback == -1 && myfront == -1);
}
template <typename QueueElement>
void Queue<QueueElement>::add(QueueElement& value)
{
    if ((myback + 1) % QUEUE_CAPACITY == myfront)
        cout << "Queue is full!" << endl;
    else
    {
        if (myfront == -1)
        {
            myfront = 0;
        }
        myback = (myback + 1) % QUEUE_CAPACITY;
        myarray[myback] = value;
    }
}
template <typename QueueElement>
void Queue<QueueElement>::Remove()
{
    if (empty())
        cout << "Queue is empty!" << endl;
    else
        myfront = (myfront + 1) % QUEUE_CAPACITY;
}
template <typename QueueElement>
QueueElement Queue<QueueElement>::front() const
{
    if (empty())
        cout << "Queue is empty!" << endl;
    else
        return myarray[myfront];
}
template <typename QueueElement>
void Queue<QueueElement>::display()const
{
    if (empty())
        cout << "Queue is empty!" << endl;
    else
    {
        if (myfront < myback)
            for (int i = myfront; i <= myback; i++)
                cout << myarray[i] << endl;
        else
        {
            for (int i = myfront; i <= QUEUE_CAPACITY; i++)
                cout << myarray[i] << endl;
            for (int i = 0; i <= myback; i++)
            {
                cout << myarray[i] << endl;
            }
        }
    }
}

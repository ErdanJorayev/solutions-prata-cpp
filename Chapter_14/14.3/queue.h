#pragma once

template <typename T>
class QueueTP
{
private:
    struct Node{T item; struct Node * next;};
    enum{Q_SIZE = 10};

    Node * front;    // Указатель на начало
    Node * rear;     // Указатель на конец
    int items;       // текущее количество элементов
    const int qsize; // максимальное количество элементов

    QueueTP(const QueueTP & q) : qsize(0) {}
    QueueTP & operator=(const QueueTP & q) { return *this; }
public:
    QueueTP(int qs = Q_SIZE);
    ~QueueTP();

    bool isempty() const;
    bool isfull() const;
    int queuecount() const;
    bool enqueue(const T & item);
    bool dequeue(T & item);

    const T & front_data() {return front->item; }
};

template <typename T>
QueueTP<T>::QueueTP(int qs) : qsize(qs)
{
    front = rear = nullptr;
    items = 0;
}

template <typename T>
QueueTP<T>::~QueueTP()
{
    Node * temp;
    while (front != nullptr)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
}

template <typename T>
bool QueueTP<T>::isempty() const
{
    return items == 0;
}

template <typename T>
bool QueueTP<T>::isfull() const
{
    return items == qsize;
}

template <typename T>
int QueueTP<T>::queuecount() const
{
    return items;
}

template <typename T>
bool QueueTP<T>::enqueue(const T & item)
{
    if (isfull())
        return false;
    Node * add = new Node;

    add->item = item;
    add->next = nullptr;
    items++;

    if (front == nullptr)
        front = add;
    else
        rear->next = add;
    
    rear = add;
    return true;
}

template <typename T>
bool QueueTP<T>::dequeue(T & item)
{
    if (front == nullptr)
        return false;
    
    item = front->item;
    items--;
    Node * temp = front;
    front = front->next;
    delete temp;
    if (items == 0)
        rear = nullptr;
    return true;
}
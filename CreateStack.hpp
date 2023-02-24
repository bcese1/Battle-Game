#ifndef CreateStack_hpp
#define CreateStack_hpp
#define Length 100

class StackEmptyException{};
class StackFullException{};

template <typename T>
class Stack
{
    private:
        T* data;
        int top;
        int maxlength;

    public:
        Stack():maxlength(Length)
        {
            data = new T[maxlength];
            top = -1;
        }
        
        Stack(int len):maxlength(len)
        {
            data = new T[maxlength];
            top = -1;
        }

        void makeempty();
        bool isempty();
        bool isfull();
        void Push(T item);
        T Top();
        void Pop();
};

template <typename T>
void Stack<T>::makeempty()
{
    top = -1;
}

template <typename T>
bool Stack<T>::isempty()
{
    return top == -1;
}

template <typename T>
bool Stack<T>::isfull()
{
    return top == maxlength - 1;
}

template <typename T>
void Stack<T>::Push(T item)
{
    if(isfull()) throw StackFullException();
    data[++top] = item;
}

template <typename T>
T Stack<T>::Top()
{
    if(isempty()) throw StackEmptyException();
    return data[top];
}

template <typename T>
void Stack<T>::Pop()
{
    if(isempty()) throw StackEmptyException();
    top--;
}



#endif	

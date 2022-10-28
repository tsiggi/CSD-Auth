class Stack
{
private:
    int size;
    int telos;//teleutaio stoixeio ths stoibas
    int *s;
public:
    Stack();
    Stack(int);
    Stack(Stack &);
    ~Stack();
    bool isEmpty();
    bool pop(int &);
    bool push(int);
};

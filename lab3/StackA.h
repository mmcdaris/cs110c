#ifndef __StackA__
#define __StackA__

typedef int StackItemType; 

class Stack {
  public:
    /* -=-=-=-=Build-N-Break=-=-=-=- */
    // Default constructor
    Stack();
    // Copy
    // Stack(const Stack& aStack);
    // Destructor.
    ~Stack();

    /* -=-=-=-=Stack-Ops=-=-=-=- */
    bool isEmpty() const;
    void push(const StackItemType& newItem); 
    void pop();
    void pop(StackItemType& stackTop); 
    void getTop(StackItemType& stackTop); 
    void display();
    StackItemType* getArray();

  private:
    StackItemType *array;
    int max;  // max size of array before remake
    int top;  // index of top item
    int size; // number of items in array 
};

#endif

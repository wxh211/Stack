#include <iostream>
#include <stdlib.h>
using namespace std;

class MyStack
{
public:
    MyStack(int size);                        //分配内存初始化栈空间，设定栈容量，栈顶
    ~MyStack();                               //回收栈空间内存
    bool stackEmpty();                        //判定栈是否为空，为空返回true，非空返回false
    bool stackFull();                         //判定栈是否已满，为满返回true，未满返回false
    void clearStack();                        //清空栈
    int stackLength();                        //已有元素个数
    bool push(char elem);                     //元素入栈，栈顶上升
    bool pop(char &elem);                     //元素出栈，栈顶下降
    void stackTraverse(bool isFromButton);    //遍历栈中所有元素
private:
    char *m_pBuffer;                          //栈空间指针
    int m_iSize;                              //栈容量
    int m_iTop;                               //栈顶，栈中元素个数
};

MyStack::MyStack(int size)
{
    m_iSize = size;
    m_pBuffer = new char[size];
    m_iTop = 0;
}

MyStack::~MyStack()
{
    delete []m_pBuffer;
}
bool MyStack::stackEmpty()
{
    if(0 == m_iTop)
    {
        return true;
    }
    return false;
}

bool MyStack::stackFull()
{
    if(m_iTop == m_iSize)
    {
        return true;
    }
    return false;
}

void MyStack::clearStack()
{
    m_iTop = 0;
}

int MyStack::stackLength()
{
    return m_iTop;
}

bool MyStack::push(char elem)
{
    if(stackFull())
    {
        return false;
    }
    m_pBuffer[m_iTop] = elem;
    m_iTop++;
    return true;
}

bool MyStack::pop(char &elem)
{
    if(stackEmpty())
    {
        return false;
    }
    m_iTop--;
    elem = m_pBuffer[m_iTop];
    return true;
}
/*
char MyStack::pop()
{
    if(stackEmpty())
    {
        throw 1;
    }
    else
    {
        m_iTop--;
        return m_pBuffer[m_iTop];
    }
}
*/

void MyStack::stackTraverse(bool isFromButton)
{
    if(isFromButton)
    {
        for(int i = 0; i<m_iTop; i++)
        {
            cout<<m_pBuffer[i]<<" ";
        }
    }
    else
    {
        for(int i=m_iTop-1; i>=0; i--)
        {
            cout<<m_pBuffer[i]<<" ";
        }
    }
}



int main(void)
{
    MyStack *pStack = new MyStack(5);

    pStack->push('h');//栈底
    pStack->push('e');
    pStack->push('l');
    pStack->push('l');
    pStack->push('o');//栈顶

    pStack->stackTraverse(true);

    char elem = 0;
    pStack->pop(elem);

    cout<<endl;

    cout<<elem<<endl;

    //pStack->clearStack();

    pStack->stackTraverse(false);

    cout<<endl;


    cout<<pStack->stackLength()<<endl;

    if(pStack->stackEmpty())
    {
        cout<<"栈为空"<<endl;
    }

    if(pStack->stackFull())
    {
        cout<<"栈为满"<<endl;
    }

    delete pStack;
    pStack = NULL;

    system("pause");
    return 0;
}

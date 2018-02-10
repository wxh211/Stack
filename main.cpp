#include <iostream>
#include <stdlib.h>
using namespace std;

class MyStack
{
public:
    MyStack(int size);                        //�����ڴ��ʼ��ջ�ռ䣬�趨ջ������ջ��
    ~MyStack();                               //����ջ�ռ��ڴ�
    bool stackEmpty();                        //�ж�ջ�Ƿ�Ϊ�գ�Ϊ�շ���true���ǿշ���false
    bool stackFull();                         //�ж�ջ�Ƿ�������Ϊ������true��δ������false
    void clearStack();                        //���ջ
    int stackLength();                        //����Ԫ�ظ���
    bool push(char elem);                     //Ԫ����ջ��ջ������
    bool pop(char &elem);                     //Ԫ�س�ջ��ջ���½�
    void stackTraverse(bool isFromButton);    //����ջ������Ԫ��
private:
    char *m_pBuffer;                          //ջ�ռ�ָ��
    int m_iSize;                              //ջ����
    int m_iTop;                               //ջ����ջ��Ԫ�ظ���
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

    pStack->push('h');//ջ��
    pStack->push('e');
    pStack->push('l');
    pStack->push('l');
    pStack->push('o');//ջ��

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
        cout<<"ջΪ��"<<endl;
    }

    if(pStack->stackFull())
    {
        cout<<"ջΪ��"<<endl;
    }

    delete pStack;
    pStack = NULL;

    system("pause");
    return 0;
}

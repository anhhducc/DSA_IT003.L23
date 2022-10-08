#include <iostream>
#include <cmath>
using namespace std;
struct Node
{
    int Data;
    Node* pNext;
};
struct LinkedNumberList
{
    Node* pHead;
    Node* pTail;
};
void Init_LinkedNumberList(LinkedNumberList& A)
{
    A.pHead = NULL;
    A.pTail = NULL;
}
Node* CreateANode(int Value)
{
    Node* Temp = new Node;
    if (Temp == NULL)
        return NULL;
    else
    {
        Temp->Data = Value;
        Temp->pNext = NULL;
        return Temp;
    }
}
void AddNodeDigital(LinkedNumberList& Snake, int x)
{
    Node* Newbie = CreateANode(x);
    if (Snake.pHead == NULL)
    {
        Snake.pHead = Newbie;
        Snake.pTail = Newbie;
    }
    else
    {
        Snake.pTail->pNext = Newbie;
        Snake.pTail = Newbie;
    }
}
void Number_TurnInto_LinkedList(LinkedNumberList& M, int Number_Separating)
{
    int Remainder;
    while (Number_Separating != 0)
    {
        Remainder = Number_Separating % 10;
        AddNodeDigital(M, Remainder);
        Number_Separating /= 10;
    }
}
void PrintList(LinkedNumberList List)
{
    while (List.pHead != NULL)
    {
        cout << List.pHead->Data << " ";
        List.pHead = List.pHead->pNext;
    }
}
int Number_Digital(int x)
{
    int Count = 0;
    while (x != 0)
    {
        Count++;
        x /= 10;
    }
    return Count;
}

void Calculate_TwoSum(int First_Number, int Second_Number, LinkedNumberList A, LinkedNumberList B)
    {
        int  Sum = 0;
        if (First_Number == Second_Number)
        {
            for (int index = 0; index < First_Number; index++)
            {
                Sum += (A.pHead->Data + B.pHead->Data) * pow(10,index);
                A.pHead = A.pHead->pNext;
                B.pHead = B.pHead->pNext;
            }
        }
        else
        {
            if (First_Number < Second_Number)
            {
                for (int index = 0; index < First_Number; index++)
                {
                    Sum += (A.pHead->Data + B.pHead->Data) * pow(10,index);
                    A.pHead = A.pHead->pNext;
                    B.pHead = B.pHead->pNext;
                }
                for (int mouse = First_Number; mouse < Second_Number; mouse++)
                {
                    Sum += B.pHead->Data * pow(10,mouse);
                    B.pHead = B.pHead->pNext;
                }
            }
            else
            {
                for (int index = 0; index < Second_Number; index++)
                {
                    Sum += (A.pHead->Data + B.pHead->Data) * pow(10,index);
                    A.pHead = A.pHead->pNext;
                    B.pHead = B.pHead->pNext;
                }
                for (int mouse = Second_Number; mouse < First_Number; mouse++)
                {
                    Sum += A.pHead->Data * pow(10,mouse);
                    A.pHead = A.pHead->pNext;
                }
            }
        }

        cout << "Tong la: " << Sum << endl;
    }
    void Multiplication(int Figure1, int Figure2, LinkedNumberList A, LinkedNumberList B)
        {
            long long T = 0;
            Node* Direction;
            for (int index = 0; index < Figure1; index++)
            {
                Direction = B.pHead;
                for (int cursor = 0; cursor < Figure2; cursor++)
                {
                    T += A.pHead->Data * pow(10,index) * Direction->Data * pow(10,cursor);
                    Direction = Direction->pNext;
                }
                A.pHead = A.pHead->pNext;
            }
            cout << "Tich la: " << T;
        }
        int main()
        {
            LinkedNumberList List1, List2;
            int Figure1, Figure2;
            cout << "Nhap vao 2 so tu nhien:" << endl;
            Init_LinkedNumberList(List1);
            Init_LinkedNumberList(List2);
            cin >> Figure1 >> Figure2;
            Number_TurnInto_LinkedList(List1, Figure1);
            Number_TurnInto_LinkedList(List2, Figure2);
            int m1 = Number_Digital(Figure1), m2 = Number_Digital(Figure2);
            Calculate_TwoSum(m1, m2, List1, List2);
            Multiplication(m1, m2, List1, List2);

            return 0;
        }
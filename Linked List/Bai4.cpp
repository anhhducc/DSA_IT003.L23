#include <iostream>
#define MAX 100
using namespace std;
struct Element
{
    int Data;
    int Position;
};
struct Node
{
    Element Temp;
    Node* pNext;
};
struct LinkedList
{
    Node* pHead;
    Node* pTail;
};
void InitializeList(LinkedList& A)
{
    A.pHead = NULL;
    A.pTail = NULL;
}
void CreateMatrix(int Matrix[MAX][MAX], int rows, int columns)
{
    for (int index1 = 0; index1 < rows; index1++)
    {
        for (int index2 = 0; index2 < columns; index2++)
            cin >> Matrix[index1][index2];
    }
}
void Get_OutMatrix(int Matrix[MAX][MAX], int rows, int columns)
{
    for (int index1 = 0; index1 < rows; index1++)
    {
        for (int index2 = 0; index2 < columns; index2++)
        {
            cout << Matrix[index1][index2] << " ";
        }
        cout << endl;
    }

}
Node* CreateNode(Element Bomp)
{
    Node* Newbie = new Node;
    if (Newbie == NULL)
        return NULL;
    else
    {
        Newbie->pNext = NULL;
        Newbie->Temp = Bomp;
        return Newbie;
    }
}
void AddNode(LinkedList& Snake, Element Value)
{
    Node* Crea = CreateNode(Value);
    if (Snake.pHead == NULL)
    {
        Snake.pHead = Crea;
        Snake.pTail = Crea;
    }
    else
    {
        Snake.pTail->pNext = Crea;
        Snake.pTail = Crea;
    }
}
void ChangeMatrix_to_LinkedList(LinkedList& Snake, int Matrix[MAX][MAX], int rows, int columns)
{
    Element Replace;
    int Location = 0;
    for (int index = 0; index < rows; index++)
        for (int cursor = 0; cursor < columns; cursor++)
        {
            if (Matrix[index][cursor] != 0)
            {
                Replace.Data = Matrix[index][cursor];
                Replace.Position = Location;
                AddNode(Snake, Replace);
            }
            Location++;
        }
}
void Sum_Matrix(LinkedList First, LinkedList Second, int rows, int columns) // Plus Two Matrix
{
    int MatrixSUM[MAX][MAX], Detective = 0;
    for (int index = 0; index < rows; index++)
    {
        for (int cursor = 0; cursor < columns; cursor++)
        {
            if (First.pHead != NULL && Second.pHead != NULL)
            {
                if (First.pHead->Temp.Position != Detective && Second.pHead->Temp.Position != Detective)
                {
                    MatrixSUM[index][cursor] = 0;
                    Detective++;
                }
                else
                {
                    if (First.pHead->Temp.Position == Detective && Second.pHead->Temp.Position != Detective)
                    {
                        MatrixSUM[index][cursor] = First.pHead->Temp.Data;
                        First.pHead = First.pHead->pNext;
                        Detective++;
                    }
                    else
                    {
                        if (First.pHead->Temp.Position != Detective && Second.pHead->Temp.Position == Detective)
                        {
                            MatrixSUM[index][cursor] = Second.pHead->Temp.Data;
                            Second.pHead = Second.pHead->pNext;
                            Detective++;
                        }
                        else
                        {
                            MatrixSUM[index][cursor] = Second.pHead->Temp.Data + First.pHead->Temp.Data;
                            First.pHead = First.pHead->pNext;
                            Second.pHead = Second.pHead->pNext;
                            Detective++;
                        }
                    }
                }
            }
            else
            {
                if (First.pHead != NULL && Second.pHead == NULL)
                {
                    if (First.pHead->Temp.Position != Detective)
                        MatrixSUM[index][cursor] = 0;
                    else
                        MatrixSUM[index][cursor] = First.pHead->Temp.Data;
                }
                else
                {
                    if (First.pHead == NULL && Second.pHead != NULL)
                    {
                        if (Second.pHead->Temp.Position != Detective)
                            MatrixSUM[index][cursor] = 0;
                        else
                            MatrixSUM[index][cursor] = Second.pHead->Temp.Data;
                    }
                    else
                        MatrixSUM[index][cursor] = 0;
                }
            }
        }
    }
    Get_OutMatrix(MatrixSUM, rows, columns);
}
void Subtraction_Matrix(LinkedList First, LinkedList Second, int rows, int columns) // Plus Two Matrix
{
    int MatrixSUM[MAX][MAX], Detective = 0;
    for (int index = 0; index < rows; index++)
    {
        for (int cursor = 0; cursor < columns; cursor++)
        {
            if (First.pHead != NULL && Second.pHead != NULL)
            {
                if (First.pHead->Temp.Position != Detective && Second.pHead->Temp.Position != Detective)
                {
                    MatrixSUM[index][cursor] = 0;
                    Detective++;
                }
                else
                {
                    if (First.pHead->Temp.Position == Detective && Second.pHead->Temp.Position != Detective)
                    {
                        MatrixSUM[index][cursor] = First.pHead->Temp.Data;
                        First.pHead = First.pHead->pNext;
                        Detective++;
                    }
                    else
                    {
                        if (First.pHead->Temp.Position != Detective && Second.pHead->Temp.Position == Detective)
                        {
                            MatrixSUM[index][cursor] = -Second.pHead->Temp.Data;
                            Second.pHead = Second.pHead->pNext;
                            Detective++;
                        }
                        else
                        {
                            MatrixSUM[index][cursor] = Second.pHead->Temp.Data - First.pHead->Temp.Data;
                            First.pHead = First.pHead->pNext;
                            Second.pHead = Second.pHead->pNext;
                            Detective++;
                        }
                    }
                }
            }
            else
            {
                if (First.pHead != NULL && Second.pHead == NULL)
                {
                    if (First.pHead->Temp.Position != Detective)
                        MatrixSUM[index][cursor] = 0;
                    else
                        MatrixSUM[index][cursor] = First.pHead->Temp.Data;
                }
                else
                {
                    if (First.pHead == NULL && Second.pHead != NULL)
                    {
                        if (Second.pHead->Temp.Position != Detective)
                            MatrixSUM[index][cursor] = 0;
                        else
                            MatrixSUM[index][cursor] = -Second.pHead->Temp.Data;
                    }
                    else
                        MatrixSUM[index][cursor] = 0;
                }
            }
        }
    }
    Get_OutMatrix(MatrixSUM, rows, columns);
}
void PrintLinkedList(LinkedList Sample)
{
    while (Sample.pHead != NULL)
    {
        cout << Sample.pHead->Temp.Data << " with position " << Sample.pHead->Temp.Position << "  ";
        Sample.pHead = Sample.pHead->pNext;
    }
}
int main()
{
    LinkedList A, B;
    InitializeList(A);
    InitializeList(B);
    int MatrixA[MAX][MAX], MatrixB[MAX][MAX], rows, columns;
    cout << "Nhap so hang: "; cin >> rows;
    cout << "\nNhap so cot: "; cin >> columns;
    CreateMatrix(MatrixA, rows, columns);
    cout << endl;
    CreateMatrix(MatrixB, rows, columns);
    ChangeMatrix_to_LinkedList(A, MatrixA, rows, columns);
    ChangeMatrix_to_LinkedList(B, MatrixB, rows, columns);
    cout << endl;
    Get_OutMatrix(MatrixA, rows, columns);
    cout << "\n";
    Get_OutMatrix(MatrixB, rows, columns);
    cout << "ListA is: \n";
    cout << endl;
    PrintLinkedList(A);
    cout << "\nListB is: \n";
    PrintLinkedList(B);
    cout << endl;
    cout << "\nThe total Sum: " << endl;
    Sum_Matrix(A, B, rows, columns);
    cout << "\n The subtraction of matrix between A and B is: " << endl;
    Subtraction_Matrix(A, B, rows, columns);
    return 0;
}
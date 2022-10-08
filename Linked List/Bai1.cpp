#include <iostream>
using namespace std;
struct Node
{
    int Data;
    Node* pNext;
};
struct LinkedList
{
    Node* pHead;
    Node* pTail;
};
void Initalize_LinkedList(LinkedList& A)
{
    A.pHead = NULL;
    A.pTail = NULL;
}
Node* CreateANode(int Figure)
{
    Node* Replace = new Node;
    if (Replace == NULL)
        return NULL;
    else
    {
        Replace->pNext = NULL;
        Replace->Data = Figure;
        return Replace;
    }
}
void AddNodeTail3(LinkedList& A, int Element)// đây là cách thêm khi đã có linkedlist sẵn 
{
    Node* Last = CreateANode(Element);
    A.pTail->pNext = Last;
    A.pTail = Last;
}
void Add_Node_Tail(LinkedList& B, int Number)
{
    Node* Newbie = CreateANode(Number);
    Node* Detective = B.pHead;
    if (B.pHead == NULL)
    {
        B.pHead = Newbie;
        B.pTail = Newbie;
    }
    else
    {
        B.pTail->pNext = Newbie;
        B.pTail = Newbie;
    }
}
void AddNodeHead(LinkedList& Snake, int Number)
{
    Node* Create = CreateANode(Number);
    if (Snake.pHead == NULL)
    {
        Snake.pHead = Create;
        Snake.pTail = Create;
    }
    else
    {
        Create->pNext = Snake.pHead;
        Snake.pHead = Create;
    }
}
void PrintList(LinkedList Sequence)
{
    while (Sequence.pHead != NULL)
    {
        cout << Sequence.pHead->Data << " ";
        Sequence.pHead = Sequence.pHead->pNext;
    }
}
void CountNode(LinkedList List)// dem so Node
{
    int Count = 0;
    while (List.pHead != NULL)
    {
        Count++;
        List.pHead = List.pHead->pNext;
    }
    cout << "\nNumber of Node " << Count << endl;


}
void FindNodeEqualX(LinkedList List, int& DetectiveX)// tim phan tu co gia tri X
{
    cin >> DetectiveX;
    int Position = 0;
    while (List.pHead != NULL)
    {
        if (List.pHead->Data == DetectiveX)
            cout << Position << " ";
        Position++;
        List.pHead = List.pHead->pNext;
    }
    cout << endl;
}
void DeleteFirstNode(LinkedList& Al)// Xoa phan tu Node dau tien
{
    Al.pHead = Al.pHead->pNext;
}
void DeleteLastNode(LinkedList& Al)// Xoa phan tu Node cuoi cung
{
    Node* Replace = Al.pHead;
    while (Replace->pNext != Al.pTail)
    {
        Replace = Replace->pNext;
    }
    Replace->pNext = NULL;
    Al.pTail = Replace;
}
void Arrange_The_List(LinkedList& A)
{
    for (Node* FirstPointer = A.pHead; FirstPointer != NULL; FirstPointer = FirstPointer->pNext)
    {
        for (Node* SecondPointer = FirstPointer->pNext; SecondPointer != NULL; SecondPointer = SecondPointer->pNext)
        {
            if (FirstPointer->Data > SecondPointer->Data)
                swap(FirstPointer->Data, SecondPointer->Data);
        }
    }
}

void Arrange_The_List_Down(LinkedList& A)
{
    for (Node* FirstPointer = A.pHead; FirstPointer != NULL; FirstPointer = FirstPointer->pNext)
    {
        for (Node* SecondPointer = FirstPointer->pNext; SecondPointer != NULL; SecondPointer = SecondPointer->pNext)
        {
            if (FirstPointer->Data < SecondPointer->Data)
                swap(FirstPointer->Data, SecondPointer->Data);
        }
    }
}

void InsertElement(LinkedList B, int Number_Inserter, int Position)
{
    for (int i = 0; i < Position; i++)
        B.pHead = B.pHead->pNext;
    Node* Bomp = CreateANode(Number_Inserter);
    Bomp->pNext = B.pHead->pNext;
    B.pHead->pNext = Bomp;
}
void InsertAndSort(LinkedList& N, int Number_Insert)
{

    if (Number_Insert <  N.pHead->Data)
    {
        Node* First = CreateANode(Number_Insert);
        First->pNext = N.pHead;
        N.pHead = First;
    }
    else
    {
        if (Number_Insert > N.pTail->Data)
        {
            Node* Last = CreateANode(Number_Insert);
            N.pTail->pNext = Last;
            N.pTail = Last;
        }
        else
        {
            Node* Body = N.pHead;
            int Position = 0;
            while (N.pHead != NULL)
            {
                if (Body->Data > Number_Insert && Body->pNext->Data <= Number_Insert)
                {
                    InsertElement(N, Number_Insert, Position);
                    break;
                }
                else
                {
                    Body = Body->pNext;
                    Position++;
                }
            }
        }
    }
}

int main()
{
    LinkedList Alphabet;
    int Value_Element, NeedFind, NeedInsert, AddNode;
    cout << "Type the numbers of the LinkedList: " << endl;
    Initalize_LinkedList(Alphabet);
    cin >> Value_Element;
    if (Value_Element < 0)
        cout << "No elements in this List, get your input again";
    else
        do
        {
            AddNodeHead(Alphabet, Value_Element);
            cin >> Value_Element;

        } while (Value_Element >= 0);

        PrintList(Alphabet);
        CountNode(Alphabet);
        FindNodeEqualX(Alphabet, NeedFind);
        DeleteFirstNode(Alphabet);
        cout << "The list after delete first element: " << endl;
        PrintList(Alphabet);
        DeleteLastNode(Alphabet);
        cout << "\nThe list after deleting last element: " << endl;
        PrintList(Alphabet);
        Arrange_The_List_Down(Alphabet);
        cout << "The list after being arranged down: " << endl;
        PrintList(Alphabet);
        Arrange_The_List(Alphabet);
        cout << "\nThe list after arranging: " << endl;
        PrintList(Alphabet);
        cout << "\nInserting Element which has data: " << endl;
        cin >> NeedInsert;
        cout << "\nThe list after inserting: " << endl;
        InsertAndSort(Alphabet, NeedInsert);
        PrintList(Alphabet);
        return 0;

}
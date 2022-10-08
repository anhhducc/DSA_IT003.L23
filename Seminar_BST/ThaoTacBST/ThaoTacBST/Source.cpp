#include <iostream>
#include <string>
using namespace std;
struct node
{
    int data;
    node* pLeft;
    node* pRight;
};
void initializeTree(node*& tree)
{
    tree = NULL;
}
node* Create_A_Node(int figure)
{
    node* temp = new node;
    if (temp == NULL)
    {
        cout << "run out memory";
        return NULL;
    }
    temp->data = figure;
    temp->pLeft = NULL;
    temp->pRight = NULL;
    return temp;
}
int ChieuCao(node* T)
{
    if (T == NULL)
        return 0;
    int a = ChieuCao(T->pLeft);
    int b = ChieuCao(T->pRight);
    if (a > b)
        return (a + 1);
    return (b + 1);
}
void FloorK(node* T, int k)
{
    if (T)
    {
        k--;
        if (T->pLeft != NULL)
            FloorK(T->pLeft, k);
        if (k == 0)
        {
            cout << T->data << "\t";
        }
        if (T->pRight != NULL)
            FloorK(T->pRight, k);
    }
}
void add_A_Node(node*& root, int figure)
{

    if (root == NULL)
    {
        root = Create_A_Node(figure);
    }
    else
    {
        if (root->data > figure)
            add_A_Node(root->pLeft, figure);
        if (root->data < figure)
            add_A_Node(root->pRight, figure);
        else
        {
        }
    }

}
void Print_Binary_Searching_Tree(node* tree)
{
    if (tree != NULL)
    {
        Print_Binary_Searching_Tree(tree->pLeft);
        cout << tree->data << " ";
        Print_Binary_Searching_Tree(tree->pRight);
    }

}
void NodeReplace(node*& x, node*& y)
{
    if (y->pLeft != NULL)
        NodeReplace(x, y->pLeft);
    else
    {
        x->data = y->data;
        x = y;
        y = y->pRight;
    }
}
void DeleteNode(node*& tree, int value)
{
    if (tree == NULL)
        return;
    else
    {
        if (value < tree->data)
            DeleteNode(tree->pLeft, value);
        else
        {
            if (value > tree->data)
                DeleteNode(tree->pRight, value);
            else
            {
                node* temp = tree;
                if (tree->pLeft == NULL)
                    tree = tree->pRight;
                else
                {
                    if (tree->pRight == NULL)
                        tree = tree->pLeft;
                    else
                    {
                        NodeReplace(temp, tree->pRight);
                    }
                    delete temp;
                }

            }
        }
    }
}
int main()
{
    int valueElement, giatricanxoa, selection, floor;
    node* tree;
    node* replace;
    initializeTree(tree);
    cout << "INITIALIZE A TREE!";
    cout << "\nNhap vao cac gia tri cua cay(-1 se ket thuc)\n";
    int i = 1;
    cout << "Nhap gia tri thu " << i << " la: ";
    cin >> valueElement;
    do
    {
        i++;
        add_A_Node(tree, valueElement);
        cout << "Nhap gia tri thu " << i << " la: ";
        cin >> valueElement;
    } while (valueElement != -1);
    cout << "Cay co " << i - 1 << " node!\n";
    cout << "Chieu cao cua cay " << ChieuCao(tree);
    cout << endl;

    do
    {
        cout << "\n                                         =========MENU==========\n";
        cout << "1.Duyet cay.";
        cout << "\n2.Xoa node.";
        cout << "\n3.Xuat node tang k";
        cout << "\n4.Thoat chuong trinh";
        cout << "\n \n BAN CHON?    ";
        cin >> selection;
        switch (selection)
        {
        case 1:
        {
            cout << "+* Xuat cay: ";
            Print_Binary_Searching_Tree(tree);
            break;
        }
        case 2:
        {
            replace = tree;
            cout << "+* Gia tri can xoa ";
            cin >> giatricanxoa;
            DeleteNode(replace, giatricanxoa);
            Print_Binary_Searching_Tree(replace);
            break;
        }
        case 3:
        {
            cout << "+* Tang can xuat ";
            cin >> floor;
            FloorK(tree, floor + 1);
        }
        default:
        {
            break;
        }

        }
        if (selection == 4)
            break;
    } while (true);
    return 0;
}
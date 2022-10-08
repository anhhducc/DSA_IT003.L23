#include <iostream>
#include <string>
using namespace std;
struct StuDent
{
    string Name;
    char Code[9];
    float AverageScore;
};
void Get_Student_Into(StuDent* Cursor, int Quantity)
{
    for (int index = 0; index < Quantity; index++)
    {
        cin.ignore();
        cout << "Student's name is: ";
        getline(cin, Cursor[index].Name);
        cout << "MSSV is: ";
        cin.getline(Cursor[index].Code, 9);
        cout << "AverageScore is: ";
        cin >> Cursor[index].AverageScore;
    }
}
void Get_Student_Out(StuDent* Cursor, int Number_Elements)
{
    for (int pos = 0; pos < Number_Elements; pos++)
    {
        cout << Cursor[pos].Name << endl << "Code: " << Cursor[pos].Code;
        cout << endl << "The average score is: " << Cursor[pos].AverageScore << endl;
    }
}
float TheHighestScore(StuDent* Compo, int Number_Elements)
{
    float HighestScore = Compo[0].AverageScore;
    for (int j = 1; j < Number_Elements; j++)
        if (Compo[j].AverageScore > HighestScore)
            HighestScore = Compo[j].AverageScore;
    return HighestScore;
}
void List_Student_Highest(StuDent* Find, int Quantity)
{
    float HighestScore = TheHighestScore(Find, Quantity);
    for (int index = 0; index < Quantity; index++)
        if (Find[index].AverageScore == HighestScore)
            cout << Find[index].Name << " " << endl;
}
void Count_MoreFiv(StuDent* Dective, int Number)
{
    int Count = 0;
    for (int eye = 0; eye < Number; eye++)
        if (Dective[eye].AverageScore >= 5)
            Count++;
    if (Count == 0)
        cout << "Noone";
    else
        cout << "There are " << Count << " Student's AverageScore >= 5" << endl;

}
void Find_Friend(StuDent* Friend, int Many_Friends)
{
    string NameFr;
    cin.ignore();
    cout << "Enter the student's name that needs to find: ";
    getline(cin, NameFr);
    for (int rocket = 0; rocket < Many_Friends; rocket++)
        if (Friend[rocket].Name == NameFr)
        {
            cout<< "MSSV is:" << Friend[rocket].Code << " " << endl;
        }
}
bool Compare(char first[9], char second[9])
{
    for (int i = 0; i < 8; i++)
        if (first[i] != second[i])
            return false;
    return true;
}
void delete_Student(StuDent* Curi, int Number_Students)
{
    bool Had_Found = false;
    int t;
    char needDelete[9];
    cout << "Enter the code's student that needs to remove from the list: ";
    cin.getline(needDelete, 9);
    
    for (int up = 0; up < Number_Students; up++)
        if (Compare(needDelete, Curi[up].Code))
        {
            Had_Found = true;
            t = up;
        }
    if (Had_Found)
    {
        cout << "List after being removed is: " << endl;
        for (int m = 0; m < t; m++)
        {
            cout << Curi[m].Name << endl << "Code: " << Curi[m].Code;
            cout << endl << "The average score is: " << Curi[m].AverageScore << endl;
        }
        for (int n = t + 1; n < Number_Students; n++)
        {
            cout << Curi[n].Name << endl << "Code: " << Curi[n].Code;
            cout << endl << "The average score is: " << Curi[n].AverageScore << endl;
        }

    }
    else
        cout << "No Found";
}
int main()
{
    int Number_Students;
    cout << "Enter the number of students: ";
    cin >> Number_Students;
    StuDent* pointer = new StuDent[Number_Students];
    Get_Student_Into(pointer, Number_Students);
    Get_Student_Out(pointer, Number_Students);
    List_Student_Highest(pointer, Number_Students);
    Count_MoreFiv(pointer, Number_Students);
    Find_Friend(pointer, Number_Students);
    delete_Student(pointer, Number_Students);
    return 0;
}
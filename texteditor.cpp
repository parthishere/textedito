#include <iostream>
#include "curses.h"
#include <fstream>
#include <string>
#include <climits>
using namespace std;

const int N = 255;

void change(string mas[]);
void del(string mas[]);
void insertB(string mas[]);
void insertA(string mas[]);

int main()
{
    int ans;
    ifstream file("F.txt");
    ofstream file2("FF.txt");
    file2 << file.rdbuf();
    file.close();
    file2.close();

    do
    {
        string massive[N];
        string prom;
        ifstream file;
        file.open("FF.txt", ios::in);
        int i = 0;
        while (!file.eof())
        {
            getline(file, prom);
            massive[i] = prom;
            i++;
        }
        cout << "===========MENU===========" << endl;
        cout << "    Make your choise:" << endl;
        cout << "1.Insert text before n-th row." << endl;
        cout << "2.Insert text after n-th row." << endl;
        cout << "3.Change text in the rows from n-th to m-th." << endl;
        cout << "4.Delete the rows from n-th to m-th." << endl;
        cout << "5.End of editing." << endl;

        cin >> ans;
        switch (ans)
        {
        case 1:
            insertB(massive);
            break;
        case 2:
            insertA(massive);
            break;
        case 3:
            change(massive);
            break;
        case 4:
            del(massive);
            break;
        case 5:
            exit(1);
        }
    } while (ans != 5);
}

void change(string mas[])
{
    int n, m;
    cout << "Please enter the rows you want to be changed !" << endl;
    cout << "From :";
    cin >> n;
    n = n - 1;
    cout << endl
         << "To :";
    cin >> m;
    m = m - 1;
    cin.ignore(INT_MAX, '\n');
    for (n; n <= m; n++)
    {
        cout << endl
             << "Enter text for (" << n + 1 << ")row: " << endl;
        getline(cin, mas[n]);
    }
    ofstream file2("FF.txt", ios::in);
    for (int i = 0; i <= N; i++)
    {
        file2 << mas[i] << endl;
    }
}

void del(string mas[])
{
    int n, m;
    cout << "Please enter the rows you want to delete " << endl;
    cout << "From :";
    cin >> n;
    n = n - 1;
    cout << endl
         << "To :";
    cin >> m;
    m = m - 1;
    for (n; n < N - n; n++)
    {
        m++;
        mas[n] = mas[m];
    }
    ofstream file2("FF.txt", ios::in);
    for (int i = 0; i <= N; i++)
    {
        file2 << mas[i] << endl;
    }
}

void insertB(string mas[])
{
    int n;
    string swap[N];
    for (int i = 0; i < N; i++)
    {
        swap[i] = mas[i];
    }
    cout << "Please enter the row you want to add text before!" << endl;
    cin >> n;
    n = n - 1;
    cout << "Enter text for the row : ";
    cin.ignore(INT_MAX, '\n');
    getline(cin, mas[n]);
    for (n; n < N; n++)
    {
        mas[n + 1] = swap[n];
    }
    ofstream file2("FF.txt", ios::in);
    for (int i = 0; i <= N; i++)
    {
        file2 << mas[i] << endl;
    }
}

void insertA(string mas[])
{
    int n;
    string swap[N];
    for (int i = 0; i < N; i++)
    {
        swap[i] = mas[i];
    }
    cout << "Please enter the row you want to add text after!" << endl;
    cin >> n;
    cout << "Enter text for the row : ";
    cin.ignore(INT_MAX, '\n');
    getline(cin, mas[n]);
    for (n; n < N - 1; n++)
    {
        mas[n + 1] = swap[n];
    }
    ofstream file2("FF.txt", ios::in);
    for (int i = 0; i <= N; i++)
    {
        file2 << mas[i] << endl;
    }
}

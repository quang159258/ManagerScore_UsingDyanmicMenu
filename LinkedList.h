#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau

#include <bits/stdc++.h>
#include <ctime>
#include <string>
#include <fstream>
#include "mywindows.h"
#include "windows.h"
#include<map>
using namespace std;
struct Date {
    int day, month, year;
};
struct Subject {
    int Toan, Ly, Hoa, Van, Sinh, GDCD, Su, Dia, TA, CongNghe;
};

struct HS {
    string name;
    Date ngaysinh;
    string mshs;
    string Class;
    int sex;
    Subject s;
    float dtb;

    float Cal(Subject s) {
        float R;
        R = (s.Toan + s.Ly + s.Hoa + s.Van + s.Sinh + s.GDCD + s.Su + s.Dia + s.TA + s.CongNghe * 1.00) / 10;
        return R;
    }
};

struct Node {
    HS Info;
    Node *Next, *Pre;
};
struct LL {
    Node *Tail, *Head;
    int n;
};

Node *createNode(HS Info) {
    Node *p = new Node();
    p->Info = Info;
    p->Next = p->Pre = NULL;
    return p;
}

int initLList(LL &ll) {
    ll.Head = ll.Tail = NULL;
    ll.n = 0;
    return 1;
}

int isEmpty(LL ll) // KT Rỗng
{
    if (ll.Head == NULL || ll.Tail == NULL || ll.n == 0)
        return 1;
    return 0;
}

void insertHead(LL &sl, Node *p) {
    if (p == NULL)
        return;
    else {
        if (sl.Head == NULL)
            sl.Head = sl.Tail = p;
        else {
            p->Next = sl.Head;
            sl.Head->Pre = p;
            sl.Head = p;
            sl.Head->Pre = sl.Tail;
            sl.Tail->Next = sl.Head;
        }
        sl.n++;
    }
}

void insertTail(LL &sl, Node *p) {
    if (p == NULL)
        return;
    else {
        if (sl.Head == NULL)
            sl.Head = sl.Tail = p;
        else {
            sl.Tail->Next = p;
            p->Pre = sl.Tail;
            sl.Tail = p;
            sl.Tail->Next = sl.Head;
            sl.Head->Pre = sl.Tail;
        }
        sl.n++;
    }
}

void DeleteNode(LL &ll, Node *p) {
    if (!ll.Head)
        return;
    Node *q = ll.Head;
    for (int i = 1; i <= ll.n; i++) {
        if (q->Next == p)
            break;
        q = q->Next;
    }
    if (ll.n == 1)

        ll.Head = ll.Tail = NULL;
    else {
        Node *tmp = p->Next;
        q->Next = tmp;
        tmp->Pre = q;
        if (p == ll.Head)
            ll.Head = tmp;
        if (p == ll.Tail)
            ll.Tail = tmp;
    }
    delete p;
    ll.n--;
}

int checkDate(Date a) {
    if (a.day < 1 || a.month < 1 || a.year < 1 || a.month > 12)
        return false;
    int arr[11] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30};
    if (a.year % 400 == 0 || (a.year % 4 == 0 && a.year % 100 != 0))
        arr[1] = 29;
    if (a.day >= 1 && a.day <= arr[a.month - 1])
        return true;
    return false;
}
int checkCLassAmountStudent(map<string,int>NumberOfClass,string Class)
{
    if(NumberOfClass[Class]<=29)
        return false;
    return true;
}
int checkMSHS(LL ll,string mshs)
{
    int R(0);
    Node *tmp=ll.Head;
    while(ll.n!=0)
    {
        if(tmp->Info.mshs==mshs)
            R++;
        tmp=tmp->Next;
        ll.n--;
    }
    return R;
}
void PrintDateNumber(ostream &output, Date a) {
    if (a.day >= 1 && a.day <= 9)
        output << 0;
    output << a.day << "/";
    if (a.month >= 1 && a.month <= 9)
        output << 0;
    output << a.month << "/";
    string tmp;
    tmp = to_string(a.year);
    int n = 4 - tmp.length();
    for (int i = 1; i <= n; i++)
        output << 0;
    output << a.year;
}

void ReadCSV(LL &ll) {
    ifstream input;
    int sl;
    input.open("ListStudent.csv", ios_base::in);
    HS tmp;
    string tm;
    getline(input, tm);
    input >> sl;
    getline(input, tm);
    while (sl != 0) {
        getline(input, tmp.mshs, ',');
        getline(input, tmp.name, ',');
        getline(input, tm, '/');
        tmp.ngaysinh.day = stoi(tm);
        getline(input, tm, '/');
        tmp.ngaysinh.month = stoi(tm);
        getline(input, tm, ',');
        tmp.ngaysinh.year = stoi(tm);
        getline(input, tmp.Class, ',');
        getline(input, tm, ',');
        if (tm == "Nu ")
            tmp.sex = 1;
        else
            tmp.sex = 0;
        getline(input, tm, ',');
        tmp.s.Toan = stoi(tm);
        getline(input, tm, ',');
        tmp.s.Ly = stoi(tm);
        getline(input, tm, ',');
        tmp.s.Hoa = stoi(tm);
        getline(input, tm, ',');
        tmp.s.Van = stoi(tm);
        getline(input, tm, ',');
        tmp.s.Sinh = stoi(tm);
        getline(input, tm, ',');
        tmp.s.GDCD = stoi(tm);
        getline(input, tm, ',');
        tmp.s.Su = stoi(tm);
        getline(input, tm, ',');
        tmp.s.Dia = stoi(tm);
        getline(input, tm, ',');
        tmp.s.TA = stoi(tm);
        getline(input, tm, ',');
        tmp.s.CongNghe = stoi(tm);
        tmp.dtb = tmp.Cal(tmp.s);
        getline(input, tm);
        Node *p = createNode(tmp);
        insertTail(ll, p);
        sl--;
    }
    input.close();
}

void WriteCSV(LL ll) {
    if(ll.n==0)
        return;
    ofstream output;
    output.open("ListStudent.csv", ios_base::out);
    output << "Ma so,Ho va Ten,Ngay sinh,Lop,Gioi tinh,Toan,Ly,Hoa,Van,Sinh,GDCD,Su,Dia,TA,Cong nghe\n";
    output << ll.n << endl;
    string a;
    Node *p = ll.Head;
    for (int i = 0; i < ll.n; i++) {
        a.clear();
        if (p->Info.sex == 1)
            a += "Nu ";
        else
            a += "Nam";
        output<<p->Info.mshs << ","
               << p->Info.name << ",";
        PrintDateNumber(output, p->Info.ngaysinh);
        output << ","
               << p->Info.Class << ","
               << a << ","
               << p->Info.s.Toan << ","
               << p->Info.s.Ly << ","
               << p->Info.s.Hoa << ","
               << p->Info.s.Van << ","
               << p->Info.s.Sinh << ","
               << p->Info.s.GDCD << ","
               << p->Info.s.Su << ","
               << p->Info.s.Dia << ","
               << p->Info.s.TA << ","
               << p->Info.s.CongNghe << ","
               << "\n";
        p = p->Next;
    }
    output.close();
}

void StandardName(string &name) {
    int len = name.length();
    if (name[0] == 32)
        name.erase(0, 1);
    if (name[len - 1] == 32)
        name.erase(len - 1, 1);
    for (int i = 0; i < name.length(); i++) {
        if (name[i] == 32 && name[i + 1] == 32) {
            name.erase(i, 1);
            i--;
        }
    }
    if (name[0] >= 'a' && name[0] <= 'z')
        name[0] -= 32;
    for (int i = 1; i < name.length(); i++) {
        if (name[i - 1] == 32 && name[i] >= 'a' && name[i] <= 'z')
            name[i] -= 32;
        else if (name[i - 1] != 32 && name[i] >= 'A' && name[i] <= 'Z')
            name[i] += 32;
    }
}
void UPCASESTRING(string &a)
{
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>='a'&&a[i]<='z')
            a[i]-=32;
    }
}
int FirstLetterName(string a,string b) {
    int R1=0;
    int R2=0;
    int l1=a.length()-1;
    int l2=b.length()-1;
    for(int i=l1;i>=0;i--)
        {
        if(a[i]==32)
        {R1=i+1;
        break;}
        }
    for(int i=l2;i>=0;i--)
    {
        if(b[i]==32)
        {R2=i+1;
            break;}
    }
    return a[R1]<b[R2];
}

void SortName(LL &ll, int checkSort) {
    for(Node *cur=ll.Head;cur!=ll.Tail;cur=cur->Next)
    {
        Node *min=cur;
        Node *q=cur->Next;
        do
        {
            if((checkSort==1&&FirstLetterName(q->Info.name,min->Info.name)==1)||(checkSort==0&&FirstLetterName(q->Info.name,min->Info.name)==0))
                min=q;
            q=q->Next;
        }while(q!=ll.Head);
        if(min!=cur)
        {
            HS tmp=min->Info;
            min->Info=cur->Info;
            cur->Info=tmp;
        }
    }
}
int CompareClassandName(HS a,HS b)
{
    if(a.Class==b.Class)
        return FirstLetterName(a.name,b.name);
    return a.Class<b.Class;
}
void SortClass(LL &ll,int checkSort)
{
    for(Node *cur=ll.Head;cur!=ll.Tail;cur=cur->Next)
    {
        Node *min=cur;
        Node *q=cur->Next;
        while(q!=ll.Head)
        {
            if((checkSort==1 && CompareClassandName(q->Info,min->Info)==1)||(checkSort==0 && CompareClassandName(q->Info,min->Info)==0))
                min=q;
            q=q->Next;
        }
        if(min!=cur)
        {
            HS tmp=min->Info;
            min->Info=cur->Info;
            cur->Info=tmp;
        }
    }
}
void SortDTB(LL &ll, int checkSort) {
    for(Node *cur=ll.Head;cur!=ll.Tail;cur=cur->Next)
    {
        Node *min=cur;
        Node *q=cur->Next;
        do
        {
            if((checkSort==1&&(q->Info.dtb<min->Info.dtb))||(checkSort==0&&(min->Info.dtb<q->Info.dtb)))
                min=q;
            q=q->Next;
        }while(q!=ll.Head);
        if(min!=cur)
        {
            HS tmp=min->Info;
            min->Info=cur->Info;
            cur->Info=tmp;
        }
    }
}
Node *FindMSHS(LL ll,string mshs)
{
    Node *tmp=ll.Head;
    Node *R=NULL;
    for(int i=0;i<ll.n;i++)
    {
        if(tmp->Info.mshs==mshs)
            R=tmp;
        tmp=tmp->Next;
    }
    return R;
}
map<string,int>CountClassAndStudent(LL ll)
{
    map<string,int>tmp;
    Node *cur=ll.Tail;
    for(int i=0;i<ll.n;i++)
    {
        tmp[cur->Info.Class]++;
        cur=cur->Pre;
    }
    return tmp;
}
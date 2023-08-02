#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include <string>
#include <conio.h>
#include "mywindows.h"
#include "LinkedList.h"
#include "Menu.h"
#include <time.h>
#include <map>
#include <vector>
#include <tuple>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int Confirm_UI_add()
{
    int check = false;
    textcolor(0);
    system("cls");
    Box_E(40, 0, 40, 3, 159, "Xac Nhan Thuc Hien Lua Chon");
    Box_E(43, 5, 7, 2, 159, "Y");
    Box_E(70, 5, 7, 2, 159, "N");
    while (1)
    {
        if (_kbhit())
        {

            char c = _getch();
            if (c == 'y' || c == 'Y')
            {
                Beep(800, 50);
                check = true;
                break;
            }
            else if (c == 'n' || c == 'N')
            {
                Beep(800, 50);
                check = false;
                break;
            }
        }
    }
    return check;
}
void RandomHS(LL &ll,map<string, int> NumberOfClass)
{
    Node *p;
    HS a;
    int grade, clas;
    vector<string> firstNames = {"Tran", "Nguyen", "Le", "Pham", "Hoang", "Vu", "Do", "Dang", "Bui", "Nguyen",
                                 "Cao", "Ho", "Huynh", "Quach", "Duong", "Vo"};
    vector<string> middleNames = {"Van", "Thi", "Dinh", "Ngoc", "Thuy", "Trong", "Thi", "Hai", "Quang", "Minh",
                                  "Chau", "Thanh"};
    vector<string> lastNames = {"Lieu", "Quang", "Dinh", "Tai", "Hoa", "Tu", "Khanh", "Tien", "Hoang", "Tuan", "An",
                                "Dat", "Diem", "Linh", "Nhi", "Xuan", "Quyen", "Thinh", "Thu", "Vy"};
    srand(time(NULL));

    for(int i=0;i<1;i++) {
        gotoXY(5, 1);
        cout << ll.n;

        a.name = firstNames[rand() % firstNames.size()] + " " + middleNames[rand() % middleNames.size()] + " " +
                 lastNames[rand() % lastNames.size()];
        a.ngaysinh.day = rand() % 21 + 1;
        a.ngaysinh.month = rand() % 12 + 1;
        a.ngaysinh.year = rand() % 20 + 1990;
        a.sex = rand() % 2;
        a.s.Toan = rand() % 11;
        a.s.Ly = rand() % 11;
        a.s.Hoa = rand() % 11;
        a.s.Van = rand() % 11;
        a.s.Sinh = rand() % 11;
        a.s.Su = rand() % 11;
        a.s.Dia = rand() % 11;
        a.s.TA = rand() % 11;
        a.s.CongNghe = rand() % 11;
        a.s.GDCD = rand() % 11;
        a.dtb = a.Cal(a.s);

        do {
            grade = rand() % 3 + 10;
            clas = rand() % 10 + 2;
            a.Class = to_string(grade) + "A";
            if (clas <= 9)
                a.Class += "0";
            a.Class += to_string(clas);
        } while (a.Class.length() != 5 || checkCLassAmountStudent(NumberOfClass, a.Class));
        do {
            for (int i = 1; i <= 10; i++) {
                clas = rand() % 10;
                a.mshs += to_string(clas);
            }
        } while (a.mshs.length() != 10 || checkMSHS(ll, a.mshs));
        p = createNode(a);
        insertTail(ll, p);
    }

}
void UI_Add(LL &ll, map<string, int> NumberOfClass)
{
    textcolor(0);
    system("cls");
    ShowCur(1);
    Box_E(40, 0, 40, 2, 159, "Them Hoc Sinh Moi");
    Box(3, 4, 115, 18, 159, " ");
    int xptr = 6, yptr = 5, ytmp;
    HS a;
    gotoXY(xptr, ++yptr);
    do
    {
        ytmp = yptr;
        gotoXY(xptr, ytmp);
        fflush(stdin);
        cout << "Nhap ten hoc sinh: ";
        getline(cin, a.name);
    } while (!a.name.length());
    StandardName(a.name);
    fflush(stdin);
    gotoXY(xptr, ++yptr);
    do
    {
        ytmp = yptr;
        gotoXY(xptr, ytmp);
        clreol();
        cout << "Nhap ngay sinh DD MM YYYY: ";
        cin >> a.ngaysinh.day >> a.ngaysinh.month >> a.ngaysinh.year;
    } while (!checkDate(a.ngaysinh));
    fflush(stdin);
    gotoXY(xptr, ++yptr);
    do
    {
        ytmp = yptr;
        gotoXY(xptr, ytmp);
        clreol();
        cout << "Nhap lop hoc sinh: ";
        getline(cin, a.Class);
        fflush(stdin);
    } while (a.Class.length() != 5 || checkCLassAmountStudent(NumberOfClass, a.Class));
    UPCASESTRING(a.Class);
    gotoXY(xptr, ++yptr);
    do
    {
        ytmp = yptr;
        gotoXY(xptr, ytmp);
        clreol();
        cout << "Nhap ma so hoc sinh: ";
        getline(cin, a.mshs);
        fflush(stdin);
    } while (a.mshs.length() != 10 || checkMSHS(ll, a.mshs));
    UPCASESTRING(a.mshs);
    gotoXY(xptr, ++yptr);
    do
    {
        ytmp = yptr;
        gotoXY(xptr, ytmp);
        clreol();
        cout << "Nhap gioi tinh: 0-Nam  1-Nu: ";
        cin >> a.sex;
    } while (a.sex != 0 && a.sex != 1);
    srand(time(NULL));
    a.s.Toan = rand() % 11;
    a.s.Ly = rand() % 11;
    a.s.Hoa = rand() % 11;
    a.s.Van = rand() % 11;
    a.s.Sinh = rand() % 11;
    a.s.Su = rand() % 11;
    a.s.Dia = rand() % 11;
    a.s.TA = rand() % 11;
    a.s.CongNghe = rand() % 11;
    a.s.GDCD = rand() % 11;
    a.dtb = a.Cal(a.s);
    Node *p = createNode(a);
    insertTail(ll, p);
}
void UI_Sort()
{
    string nd1[5] = {"1.Theo Ten", "2.Theo DTB", "3.Theo Lop", "4.Ngung Sap Xep", "Lua chon: "};
    SetBackGroundRange(7, 5, 24, 115, 5);
    n_Box_Ngang(6, 24, 110 / 5, 3, 159, nd1, 5);
    gotoXY(5 * (110 / 5), 26);
    ShowCur(1);
}
void UI_SubDanhSach(int CurPage,int Page)
{
    string nd2[3] = {"Ctrl + <: Trang truoc","B: Tro ve","Ctrl + >: Trang sau"};
    string nd3[3] = {"Ctrl + <: Trang truoc","B: Tro ve",""};
    string nd1[3] = {"","B: Tro ve","Ctrl + >: Trang sau"};
    string nd0[3] = {"","B: Tro ve",""};
    SetBackGroundRange(7, 5, 24, 115, 5);
    if(Page==0)
        n_Box_Ngang(6, 24, 110 / 3, 3, 159, nd0, 3);
    else if(CurPage==0)
    n_Box_Ngang(6, 24, 110 / 3, 3, 159, nd1, 3);
    else if(CurPage>0&&CurPage<Page)
        n_Box_Ngang(6, 24, 110 / 3, 3, 159, nd2, 3);
    else
        n_Box_Ngang(6, 24, 110 / 3, 3, 159, nd3, 3);
}
int Confirm_UI_Sort()
{
    int check = false;
    textcolor(0);
    system("cls");
    Box_E(40, 0, 40, 3, 159, "Xac Nhan Sap Xep Theo");
    Box_E(35, 5, 15, 2, 159, " Tang Dan - Y");
    Box_E(70, 5, 15, 2, 159, " Giam Dan - N");
    while (1)
    {
        if (_kbhit())
        {

            char c = _getch();
            if (c == 'y' || c == 'Y')
            {
                Beep(800, 50);
                check = true;
                break;
            }
            else if (c == 'n' || c == 'N')
            {
                Beep(800, 50);
                check = false;
                break;
            }
        }
    }
    return check;
}
int MaxLengthString(string nd[], int sl)
{
    int R = nd[0].length();
    for (int i = 1; i < sl; i++)
        R = R <= nd[i].length() ? nd[i].length() : R;
    return R;
}
int MaxLengthString_Vector(vector<HS> nd, int sl)
{
    int R = nd[0].name.length();
    for (int i = 1; i < sl; i++)
        R = R <= nd[i].name.length() ? nd[i].name.length() : R;
    return R;
}
int cal(int y, int xptr, int yptr)
{
    int R = yptr - y;
    if (xptr > 57)
        R += 15;
    return R;
}
tuple<int, int> AddressClass(LL ll, string Class)
{
    tuple<int, int> Address;
    get<0>(Address) = get<1>(Address) = -1;
    Node *q = ll.Head;
    int i = 1;
    while (i <= ll.n)
    {
        if (q->Info.Class == Class && get<0>(Address) == -1)
            get<0>(Address) = i;
        if (q->Info.Class == Class)
            get<1>(Address) = i;
        if(get<0>(Address)!=-1&&get<1>(Address)!=-1&&q->Info.Class != Class)
            break;
        q = q->Next;
        i++;
    }
    return Address;
}
void PrintScrollList(int start,int sl,vector<HS> StudentOfClass)
{
    Box(3, 4, 115, 18, 159, "");
    int x=8,y=5;
    int leng=MaxLengthString_Vector(StudentOfClass,(int)StudentOfClass.size());
    gotoXY(x+2,y);
    cout<<"STT  "<<setw(leng)<<left<<"Ho va Ten"<<setw(14)<<left<<"  Ma so"<<setw(12)<<left<<"Ngay Sinh"<<"Gioi Tinh";
    string tmp;

    gotoXY(x,y+1);
    cout<<">";
    for(int i=start;i<sl+start;i++)
    {
        gotoXY(x+3, ++y);
        if (i + 1 <= 9)
            cout << 0;
        tmp.clear();
        if (StudentOfClass[i].sex == 0)
            tmp += "Nam";
        else
            tmp += "Nu ";
        cout << i + 1 << ". " <<setw(leng)<<left<< StudentOfClass[i].name << "  " << StudentOfClass[i].mshs << "  ";
        PrintDateNumber(cout, StudentOfClass[i].ngaysinh);
        cout<<"  "<< tmp;
    }
}
void InDanhSach(tuple<int, int> Address, LL ll)
{
    Node *q = ll.Head;
    for (int i = 2; i <= get<0>(Address); i++)
        q = q->Next;
    vector<HS> StudentOfClass;
    int sl = (get<1>(Address) - get<0>(Address) + 1);
    for (int i = 0; i < sl; i++)
    {
        StudentOfClass.push_back(q->Info);
        q = q->Next;
    }
    string title = "DANH SACH LOP " + StudentOfClass[0].Class;
    string nd[3] = {"So Hoc Sinh: "+to_string(sl),"B: Tro ve",""};
    n_Box_Ngang(6, 24, 110 / 3, 3, 159, nd, 3);
    string tmp;
    Box_E(35, 0, 50, 2, 159, title);
    Box(3, 4, 115, 18, 159, "");
    int start=0,end=14;
    end=min(end,sl-1);
    int checkluachon=true;
    while(1)
    {
        end=min(end,sl-1);
        if(checkluachon)
        {
            PrintScrollList(start,end-start+1,StudentOfClass);
            checkluachon=false;
        }
        if(_kbhit())
        {
            char c=_getch();
            if(c=='B'||c=='b')
                return;
            if(c==-32)
            {
                c=_getch();
                if(c==80)
                {
                    if(end<sl-1)
                    {
                        start++;
                        end++;
                        checkluachon=true;
                    }
                }
                if(c==72)
                {
                    if(start>0)
                    {
                        start--;
                        end--;
                        checkluachon=true;
                    }
                }
            }
        }
    }

}
void DanhSach(LL &ll, map<string, int> NumberOfClass)
{
    vector<string>nd(NumberOfClass.size());
    int i = 0;
    string tmp;
    for (auto x : NumberOfClass)
    {
        tmp.clear();
        int tm = i++;
        if (tm >= 0 && tm <= 8)
            tmp += "0";
        if(tm>=0&&tm<99)
            tmp+="0";
        tmp += to_string(tm + 1) + ". " + x.first + ": ";
        if (x.second >= 1 && x.second <= 9)
            tmp += "0";
        tmp += to_string(x.second) + " HS";
        nd[tm]=tmp;
    }
l:
    Box_E(35, 0, 50, 2, 159, "DANH SACH LOP HOC");
    int NumberOfPage = (int)i / 30;
    if (i % 30 == 0)
        NumberOfPage -= 1;
    int CurPage = 0;
    int start = CurPage * 30;
    int end;
    end = min(start + 30, (int)NumberOfClass.size());
    n_Box_NoBorder(3, 4, 115, 18, 159, nd, start, end);
    int x = 20, y = 5;
    int xptr = x, yptr = y + 1;
    int checkluachon = true;
    int Nextpage = false;
    int Prepage = false;
    int checkUI=true;
    int xpre = xptr, ypre = yptr;
    tuple<int, int> Address;
    SortClass(ll, 1);
    while (1)
    {
        if(checkUI) {
            UI_SubDanhSach(CurPage,NumberOfPage);
            checkUI=false;
        }
        int sl = end - start;
        if (Nextpage || Prepage)
        {
            xptr = x;
            yptr = y + 1;
            checkluachon = true;
        }
        if (Nextpage)
        {
            CurPage++;
            start = CurPage * 30;
            end = min(start + 30, (int)NumberOfClass.size());
            Nextpage = false;
            checkUI=true;
            n_Box_NoBorder(3, 4, 115, 18, 159, nd, start, end);
        }
        if (Prepage)
        {
            CurPage--;
            start = CurPage * 30;
            end = min(start + 30, (int)NumberOfClass.size());
            Prepage = false;
            checkUI=true;
            n_Box_NoBorder(3, 4, 115, 18, 159, nd, start, end);
        }

        if (checkluachon)
        {
            gotoXY(xpre, ypre);
            cout << " ";
            xpre = xptr;
            ypre = yptr;
            gotoXY(xptr, yptr);
            cout << ">";
            checkluachon = false;
        }
        if (_kbhit())
        {
            char c = _getch();
            if (c == -32)
            {

                c = _getch();
                if (c == 115)
                {
                    if (CurPage > 0)
                        Prepage = true;
                }
                if (c == 116)
                {
                    if (CurPage < NumberOfPage)
                        Nextpage = true;
                }
                if (c == 72)
                {
                    if (sl != 1)
                    {
                        Beep(800, 50);
                        checkluachon = true; // đã bấm
                        if (sl <= 15)
                        {
                            if (yptr != y + 1)
                                yptr -= 1;
                            else
                            {
                                yptr = y + sl;
                            }
                        }
                        else
                        {
                            if (yptr != y + 1)
                            {
                                yptr -= 1;
                            }
                            else
                            {
                                if (xptr > 60)
                                {
                                    xptr -= 60;
                                    yptr = y + 15;
                                }
                                else
                                {
                                    xptr += 60;
                                    yptr = y + (sl - 15);
                                }
                            }
                        }
                    }
                }
                else if (c == 80)
                {
                    if (sl != 1)
                    {
                        Beep(800, 50);
                        checkluachon = true; // đã bấm
                        if (sl <= 15)
                        {
                            if (yptr != y + sl)
                                yptr += 1;
                            else
                            {
                                yptr = y + 1;
                            }
                        }
                        else
                        {
                            if (xptr > 60)
                            {
                                if (yptr != y + (sl - 15))
                                    yptr += 1;
                                else
                                {
                                    xptr -= 60;
                                    yptr = y + 1;
                                }
                            }
                            else
                            {
                                if (yptr != y + 15)
                                    yptr += 1;
                                else
                                {
                                    xptr += 60;
                                    yptr = y + 1;
                                }
                            }
                        }
                    }
                }
                else if (c == 77)
                {
                    if (sl > 15)
                    {
                        Beep(800, 50);
                        checkluachon = true;
                        if (xptr < 60)
                        {
                            xptr += 60;
                            if (yptr > y + sl - 15)
                                yptr = y + sl - 15;
                        }
                        else
                            xptr -= 60;
                    }
                }
                else if (c == 75)
                {
                    if (sl > 15)
                    {
                        Beep(800, 50);
                        checkluachon = true;
                        if (xptr < 60)
                        {
                            xptr += 60;
                            if (yptr > y + sl - 15)
                                yptr = y + sl - 15;
                        }
                        else
                            xptr -= 60;
                    }
                }
            }
            else if(c=='B'||c=='b')
            {
                return;
            }
            else if (c == 13)
            {
                tmp.clear();
                int choice = cal(y + 1, xptr, yptr) + (CurPage) * 30;
                tmp = nd[choice];
                tmp.erase(0, 5);
                tmp.erase(5, 7);
                Address = AddressClass(ll, tmp);
                InDanhSach(Address, ll);
                n_Box_NoBorder(3, 4, 115, 18, 159, nd, start, end);
                Box_E(35, 0, 50, 2, 159, "DANH SACH LOP HOC");
                checkluachon = true;
            }
        }
    }
}
int Cal(int y, int yptr, int h)
{
    int R = (yptr - y) / h;
    return R;
}
void InThongTin(int x, int y, int w, int h, int b_color, Node *p)
{
    if (!p)
    {
        Box_E(x, y, w, h, b_color, "KHONG CO THONG TIN HOC SINH");
        Box_E(x + 41, y, 43, h, b_color, "KHONG CO THONG TIN HOC SINH");
    }
    else
    {
        Box(x, y, w, h, b_color, " ");
        textcolor(b_color);
        gotoXY(x + 2, ++y);
        cout << "Ten hoc sinh: " << p->Info.name;
        gotoXY(x + 2, ++y);
        cout << "Ma so hoc sinh: " << p->Info.mshs;
        gotoXY(x + 2, ++y);
        cout << "Lop: " << p->Info.Class;
        gotoXY(x + 2, ++y);
        cout << "Ngay sinh: ";
        PrintDateNumber(cout, p->Info.ngaysinh);
        gotoXY(x + 2, ++y);
        cout << "Gioi tinh: ";
        if (p->Info.sex == 0)
            cout << "Nam";
        else
            cout << "Nu";
        gotoXY(x + 2, ++y);
        cout << "Diem trung binh: " << p->Info.dtb;
        Box(x + 41, y - 6, 43, h, b_color, " ");
        string mon1[5] = {"Toan", "Vat ly", "Hoa", "Ngu van", "Sinh hoc"};
        string mon2[5] = {"GDCD", "Lich Su", "Dia li", "Cong Nghe", "Tieng Anh"};
        string diem1[5];
        string diem2[5];
        diem1[0] = to_string(p->Info.s.Toan);
        diem1[1] = to_string(p->Info.s.Ly);
        diem1[2] = to_string(p->Info.s.Hoa);
        diem1[3] = to_string(p->Info.s.Van);
        diem1[4] = to_string(p->Info.s.Sinh);
        diem2[0] = to_string(p->Info.s.GDCD);
        diem2[1] = to_string(p->Info.s.Su);
        diem2[2] = to_string(p->Info.s.Dia);
        diem2[3] = to_string(p->Info.s.CongNghe);
        diem2[4] = to_string(p->Info.s.TA);
        n_Box_divide_E(x + 43, y - 5, max(MaxLengthString(mon1, 5), MaxLengthString(mon2, 5)) + 4, 2, b_color, mon1, 5);
        n_Box_divide_E(x + 56, y - 5, MaxLengthString(diem1, 5) + 4, 2, b_color, diem1, 5);
        n_Box_divide_E(x + 64, y - 5, max(MaxLengthString(mon1, 5), MaxLengthString(mon2, 5)) + 4, 2, b_color, mon2, 5);
        n_Box_divide_E(x + 77, y - 5, MaxLengthString(diem2, 5) + 4, 2, b_color, diem2, 5);
    }
}
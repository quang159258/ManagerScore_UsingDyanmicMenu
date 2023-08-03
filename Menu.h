#pragma once // tránh đụng độ thư viện khi gọi chồng file lên nhau
#include <bits/stdc++.h>
#include <string>
#include "windows.h"
#include "LinkedList.h"
#include "UI_Add.h"
#include <map>
using namespace std;
void menudong(LL &ll, string nd[], int sl)
{
    int x = 4, y = 5;
    int w = MaxLengthString(nd, sl) + 2, h = 2;
    int b_color = 159, b_color_bright = 75;
    Node *Find = NULL;
    string find;
    Node *tmp = ll.Head;
    int ix = x + MaxLengthString(nd, sl) + 3, iy = 5;
    int iw = 40, ih = 12;
    int checkReadCSV = false;
    map<string, int> NumberOfClass;
    string title;
    int checkMap=true;
loop:
    if(checkMap)
    {
        NumberOfClass = CountClassAndStudent(ll);
        checkMap=false;
    }
    textcolor(0);
    system("cls");
    int xptr = x, yptr = y;
    int xpre = xptr, ypre = yptr;
    bool checkluachon = true;
    int checkSort = true;
    title.clear();
    title = "So lop: " + to_string(NumberOfClass.size());
    title.append(" (Moi lop toi da 30 hs)\tTong so hoc sinh: " + to_string(ll.n));
    title.append("\tCre: Nguyen Tran Quang - HUIT - 2001113907");
    ShowCur(0);
    SetBackGroundRange(159, 2, 4, 118, 20);
    Box(3, 4, 115, 18, 159, " ");
    Box_E(35, 0, 50, 2, 159, "CHUONG TRINH QUAN LY HOC SINH");
    Box(5, 24, 110, 3, 159, title);

    InThongTin(ix, iy, iw, ih, b_color, tmp);
    // Lua chon
    n_Box_divide(x, y, w, h, b_color, nd, sl);

    while (1)
    {

        if (checkluachon)
        {
            gotoXY(xpre, ypre);
            highlight(xpre, ypre, w, h, b_color, nd[Cal(y, ypre, h)]);
            xpre = xptr;
            ypre = yptr;
            highlight(xptr, yptr, w, h, b_color_bright, nd[Cal(y, yptr, h)]);
            checkluachon = false;
        }
        if (_kbhit())
        {
            char c = _getch();
            if (c == -32)
            {

                c = _getch();
                if (c == 72)
                {
                    Beep(800, 50);
                    checkluachon = true; // đã bấm
                    if (yptr != y)
                        yptr -= h;
                    else
                    {
                        yptr = y + h * (sl - 1);
                    }
                }
                else if (c == 80)
                {
                    Beep(800, 50);
                    checkluachon = true; // đã bấm
                    if (yptr != y + h * (sl - 1))
                        yptr += h;
                    else
                    {
                        yptr = y;
                    }
                }
                else if (c == 77)
                {
                    if (ll.n >= 2)
                    {
                        Beep(800, 50);
                        tmp = tmp->Next;
                        InThongTin(ix, iy, iw, ih, b_color, tmp);
                    }
                }
                else if (c == 75)
                {
                    if (ll.n >= 2)
                    {
                        Beep(800, 50);
                        tmp = tmp->Pre;
                        InThongTin(ix, iy, iw, ih, b_color, tmp);
                    }
                }
            }
            else if (c == 13)
            {
                int choice = Cal(y, yptr, h);
                if (choice >= 0 && choice < sl - 1)
                {
                    Node *q;
                    switch (choice)
                    {
                    case 0:
                        if(Confirm_UI_add())
                        {
                            UI_Add(ll,NumberOfClass);
                            checkMap=true;
                            tmp=ll.Tail;
                        }
                        break;
                    case 1:
                        if (ll.n == 0)
                        {
                            Sleep(200);
                            MessageBeep(MB_HELP);
                            break;
                        }
                        if (Confirm_UI_add())
                        {
                            if (ll.n == 1)
                            {
                                tmp = NULL;
                                DeleteNode(ll, tmp);
                            }
                            else if (ll.n != 0 && ll.n != 1)
                            {
                                q = tmp->Next;
                                DeleteNode(ll, tmp);
                                tmp = q;
                            }
                            checkMap=true;
                        }
                        break;
                    case 2:
                        if (ll.n == 0)
                        {
                            Sleep(200);
                            MessageBeep(MB_HELP);
                            break;
                        }
                        UI_Sort();
                        while (checkSort)
                        {
                            if (_kbhit())
                            {
                                c = _getch();
                                if (c >= '1' && c <= '4')
                                {
                                    checkSort = false;
                                    switch (c)
                                    {
                                    case '1':
                                        SortName(ll, Confirm_UI_Sort());
                                        break;
                                    case '2':
                                        SortDTB(ll, Confirm_UI_Sort());
                                        break;
                                    case '3':
                                        SortClass(ll, Confirm_UI_Sort());
                                        break;
                                    default:
                                        break;
                                    }
                                }
                            }
                        }
                        break;
                    case 3:
                        if (ll.n == 0)
                        {
                            Sleep(200);
                            MessageBeep(MB_HELP);
                            break;
                        }
                    l:
                        Box(ix, iy, iw, ih, b_color, "");
                        if (ll.n != 0)
                            SetBackGroundRange(b_color, ix + 41, iy, 43 + 2, ih + 2);
                        ShowCur(1);
                        find = "1231231321";
                        do
                        {
                            if (find.length() != 10)
                                goto l;
                            gotoXY(ix + 1, iy + 1);
                            cout << "Nhap MSHS: ";
                            gotoXY(ix + 12, iy + 1);
                            getline(cin, find);
                            fflush(stdin);
                        } while (find.length() != 10);
                        Find = FindMSHS(ll, find);
                        ShowCur(0);
                        if (Find)
                            tmp = Find;
                        else
                        {
                            Box_E(ix, iy, iw, ih, b_color, "Khong Tim Thay Thong Tin Hoc Sinh");
                            _getch();
                        }
                        break;
                    case 4:
                        if (ll.n == 0)
                        {
                            Sleep(200);
                            MessageBeep(MB_HELP);
                            break;
                        }
                        DanhSach(ll, NumberOfClass);
                        break;
                    case 5:
                        if (ll.n == 0)
                        {
                            Sleep(200);
                            MessageBeep(MB_HELP);
                            break;
                        }
                        WriteCSV(ll);
                        break;
                    case 6:
                        if (checkReadCSV)
                            break;
                        checkMap=true;
                        checkReadCSV = true;
                        ReadCSV(ll);
                        tmp = ll.Tail;
                        break;
                    default:
                        break;
                    }
                    goto loop;
                }
                else
                {
                    return;
                }
            }
        }
    }
}
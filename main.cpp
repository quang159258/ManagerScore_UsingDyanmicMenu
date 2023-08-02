#pragma once
#include <string>
#include "mywindows.h"
#include "LinkedList.h"
#include "Menu.h"
using namespace std;
int main()
{
    LL ll;
    initLList(ll);
    SetConsoleTitle("QUAN LY HOC SINH");
    SetCenterConsole();
    resizeConsole(120, 40);
    string a[8] = {"1.Them Hoc Sinh", "2.Xoa Hoc Sinh", "3.Sap Xep", "4.Tim Hoc Sinh", "5.Danh Sach Hoc Sinh", "6.Xuat File", "7.Nhap File", "8.Thoat Khoi Chuong Trinh"};
    menudong(ll, a, 8);
    return 0;
}
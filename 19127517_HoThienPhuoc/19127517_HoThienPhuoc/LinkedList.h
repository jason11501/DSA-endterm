//
//  LinkedList.h
//  19127517_HoThienPhuoc
//
//  Created by jason on 29/07/2022.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>

using namespace std;

typedef struct tagSINHVIEN{
    int MSSV;
    char TenSV[100];
    float DTB;
} SINHVIEN, Student;

typedef struct tagNODE{
    SINHVIEN SV;
    struct tagNODE* pNext;
} Node, *PNODE;
PNODE pHead, pTail;


#endif /* LinkedList_h */

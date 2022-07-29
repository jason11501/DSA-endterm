//
//  main.cpp
//  19127517_HoThienPhuoc
//
//  Created by jason on 29/07/2022.
//

#include "LinkedList.h"
#include "BST.h"

Node* GetNode(SINHVIEN e)
{
    Node* newNode = new Node;
    newNode->SV = e;
    newNode->pNext = nullptr;
    return newNode;
}

void AddLast(Node*& head, Student e)
{
    Node* newNode = GetNode(e);
    if (!head)
        head = newNode;
    else
    {
        Node* temp = head;
        while (temp->pNext)
            temp = temp->pNext;
        temp->pNext = newNode;
    }
}

tagSINHVIEN InputStudent()
{
    SINHVIEN e;
    cout << "Nhap MSSV hoc sinh: ";
    cin >> e.MSSV;
    cin.ignore();
    cout << "Nhap ten hoc sinh: ";
    cin >> e.TenSV;
    cout << "Nhap diem: ";
    cin >> e.DTB;
    cin.ignore();

    return e;
}

ostream& operator<<(ostream& out, const Student& e)
{
    out << e.MSSV << ", " << e.TenSV << ", " << e.DTB << '\n';
    return out;
}

void OutputLessThan5(Node* root)
{
    for (Node* node = root; node != nullptr; node = node->pNext)
    {
        if (node->SV.DTB < 5)
            cout << node->SV;
    }
}

bool DeleteNode(Node*& root, int MSSV)
{
    Node* before = nullptr; // = 0 || == false
    for (Node* node = root; node != nullptr; node = node->pNext)
    {
        if (node->SV.MSSV == MSSV)
        {
            //First node
            if (!before)
            {
                root = node->pNext;
                delete node;
            }
            else
            {
                before->pNext = node->pNext;
                delete node;
            }
            return true;
        }

        before = node;
    }
    return false;
}

string Input(){
    string s;
    cout<< "Input: ";
    getline(cin, s);
    return s;
}

void reverseList(Node** head_ref)
{
    Node* prev = NULL;
    Node* current = *head_ref;
    Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->pNext;
  
        // Reverse current node's pointer
        current->pNext = prev;
  
        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void traversal(Node* head){
    for (Node* node = head; node != nullptr; node = node->pNext)
    {
        cout<< node->SV;
    }
}

void Destroy(Node* &root)
{
    while (root)
    {
        Node* temp = root;
        root = root->pNext;
        delete temp;
    }
}

BSTNode* createNODE(int key)
{
    BSTNode* t = new BSTNode;
    t->key = key;
    t->right = NULL;
    t->left = NULL;
    return t;
}

void Insert(BSTNode*&pRoot,int data)
{
  
    if(pRoot==NULL)
    {
      pRoot=createNODE(data);
    }
    else if(pRoot->key>data)
    {
        Insert(pRoot->left,data);
    }
    else if(pRoot->key<data)
    {
        Insert(pRoot->right,data);
    }
}

BSTNode* CreateTree(int a[], int n){
    BSTNode * root = createNODE(a[0]);
    for(int i = 1; i < n; i++){
        Insert(root, a[i]);
    }
    return root;
}

void NLR(BSTNode* &pRoot)
{
    if(pRoot==NULL)
        return;
    else
    {
        cout<<pRoot->key<<" ";
        NLR(pRoot->left);
        NLR(pRoot->right);
    }
}

void LRN(BSTNode* &pRoot)
{
    if(pRoot==NULL)
        return;
    else
    {
        LRN(pRoot->left);
        LRN(pRoot->right);
        cout<<pRoot->key<<" ";
    }
}

void del(BSTNode*& t, BSTNode*& q)
{
    if (t->right)
        del(t->right,q);
    else
    {
        q->key = t->key;
        q = t;
        t = t->left;
    }
}

void removeSearch(BSTNode*& t, int x)
{
    if (t == NULL)
        return;
    else
    {
        if (t->key < x)
            removeSearch(t->right, x);
        else
        {
            if (t->key > x)
                removeSearch(t->left, x);
            else
            {
                BSTNode* q = t;
                if (t->left == NULL)
                    t = t->right;
                else
                {
                    if (t->right == NULL)
                        t = t->left;
                    else
                        del(t->left, q);
                }
                delete q;
            }
        }
    }
}

bool search(BSTNode* t, int key)
{
    if (t == NULL)
        return false;
    if (t->key == key)
        return true;
    else
        if (t->key > key)
            return search(t->left, key);
        else
            return search(t->right, key);
}

void checkSumK(BSTNode* pRoot, BSTNode*& tree, int k, bool &flag){
    if(pRoot==NULL)
        return;
    else
    {
        checkSumK(pRoot->left, tree, k, flag);
        int minus = k-pRoot->key;
        removeSearch(tree, pRoot->key);
        if (search(tree, minus))
        {
            flag  = true;
            return;
        }
        checkSumK(pRoot->right, tree, k, flag);
    }
}

void removeAll(BSTNode*& t)
{
    while (t)
        removeSearch(t, t->key);
}

int main() {
//1
    Node* head;
    //a. Nhập từ bàn phím vào thông tin của 10 sinh viên. Thông tin này được đưa vào DSLK theo phương pháp thêm vào cuối.
    for (int i=0; i<10; i++)
    {
        Student e = InputStudent();
        AddLast(head, e);
    }
    //b. In ra danh sách những sinh viên có ĐTB <5.
    OutputLessThan5(head);
    //c. Xóa một sinh viên dựa vào MSSV
    DeleteNode(head, stoi(Input()));
    //d. In ra danh sách các sinh viên đứng trước một sinh viên cho trước bằng MSSV theo trật tự từ dưới lên và có độ phức tạp là O(n).
    reverseList(&head);
    traversal(head);
    //e. Giải phóng danh sách liên kết.
    Destroy(head);
    
//2
    //a) Viết hàm thêm lần lượt các nút có giá trị sau: 25, 32, 14, 21, 19, 17, 23 vào cây trên.
    int a[] = { 25, 32, 14, 21, 19, 17, 23};
    int n =  sizeof(a)/sizeof(a[0]);
    BSTNode * root = CreateTree(a, n);
    //b) Viết hàm duyệt cây theo thứ tự Left – Right – Node (LRN) và Node – Left – Right (NLR), các giá trị xuất ra màn hình.
    cout<< "\nNLR\n";
    NLR(root);
    cout<< "\nLRN\n";
    LRN(root);
    cout<<endl;
    //c) Viết hàm xóa một nút có giá trị h cho trước (h được nhập từ bàn phím). Nếu không có trả về False hoặc -1.
    removeSearch(root, stoi(Input()));
    //d) Cho trước một giá trị k, viết hàm kiểm tra xem có tồn tại 2 nút nào đó trong cây sao cho tổng giá trị bằng k không? Nếu có trả về True, không trả về False.
    bool flag = false;
    int k= stoi(Input());
    checkSumK(root, root, k, flag);
    (flag)
        ? cout<< "True\n"
        : cout<< "False\n";
    
    removeAll(root);
    return 0;
}

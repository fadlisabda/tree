#include <iostream>
using namespace std;

class tree //class tree sebagai penyimpan nilai pada node yang dibuat
{
    public:
        int value;//untuk menyimpan nilai pada node yang bersangkutan
        tree *left;//membuat child node pada bagian kiri akar
        tree *right;//membuat child node pada bagian kanan akar
        tree *parent;//membuat induk node pada akar
    tree(int v){//untuk membentuk objek dari class tree
        value=v;
        left=NULL;
        right=NULL;
    } 
    tree(){

    };
};

tree *root;//membuat node root yang bersifat global

class BST{//class untuk menyimpan fungsi prototype untuk membuat binarysearchtree
    public://fungsi bersifat public
        BST(){
            root=NULL;
        }
        void cekroot();
        int isempty();
        void insert(int i);
        void searching(int i);
        void deletion(int i);
        void findmin();
        void findmax();
        void urut();
        void display(tree *val,int i);
    private://fungsi bersifat private
        void insertx(int i,tree *temp);
        void uruttree(tree *n);
        void transplanted(tree *del,tree*reply);
        void minvalue(tree *n);
};

int main(){
    
    return 0;
}
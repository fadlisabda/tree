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

int BST::isempty(){//mengecek jika binarysearchtree kosong mengembalikan nilai 1 jika berisi mengembalikan nilai 0
    if(root==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void BST::findmin(){//fungsi untuk mencari nilai terkecil didalam binarysearchtree
    tree *temp;
    temp=root;//duplikasi dari root
    if (isempty()==1)//jika binarysearchtree kosong 
    {
        cout<<"No Data"<<endl;//menampilkan pesan No Data
    }
    else{//jika binarysearchtree berisi menjalankan else
        while (temp->left!=NULL)//jika tidak sama dengan NULL false jadi true
        {
            temp=temp->left;//menelusuri node sebelah kiri sampai ditemukan NULL
        }
        cout<<"Nilai terkecil adalah : "<<temp->value<<endl;//menampilkan nilai terkecil
        cout<<endl;
    }
}

void BST::findmax(){
    tree *temp;
    temp=root;
    if(isempty()==1){
        cout<<"No Data"<<endl;
    }
    else{
        while (temp->right!=NULL)
        {
            temp=temp->right;
        }
        cout<<"Nilai terbesar adalah : "<<temp->value<<endl;
        cout<<endl;
    }
}

int main(){
    
    return 0;
}
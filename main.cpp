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
        while (temp->left!=NULL)
        {
            temp=temp->left;//menelusuri node sebelah kiri sampai ditemukan NULL
        }
        cout<<"Nilai terkecil adalah : "<<temp->value<<endl;//menampilkan nilai terkecil
        cout<<endl;
    }
}

void BST::findmax(){//fungsi untuk mencari nilai terbesar didalam binarysearchtree
    tree *temp;
    temp=root;//duplikasi dari root
    if(isempty()==1){//jika binarysearchtree kosong 
        cout<<"No Data"<<endl;//menampilkan pesan No Data
    }
    else{//jika binarysearchtree berisi menjalankan else
        while (temp->right!=NULL)
        {
            temp=temp->right;//penelusuran ke node sebelah kanan sampai ditemukan null
        }
        cout<<"Nilai terbesar adalah : "<<temp->value<<endl;//menampilkan nilai terbesar
        cout<<endl;
    }
}

void BST::searching(int i){//fungsi untuk mencari nilai node
    tree *temp;
    temp=root;//duplikasi dari root
    int n=0;//untuk penanda nilai node ditemukan atau tidak
    while (temp!=NULL)
    {
        if(temp->value==i){//jika nilai node binarysearchtree sama dengan nilainode yang dicari 
        //maka n=1 dan break
            n=1;
            break;
        }
        if(i<(temp->value)){//jika nilainode yang dicari kecil dari nilai node binarysearchtree 
        //maka proses pencarian dilakukan pada bagian node kiri
            temp=temp->left;
        }
        else{//jika nilainode yang dicari besar dari nilai node binarysearchtree 
        //maka proses pencarian dilakukan pada bagian node kanan
            temp=temp->right;
        }
    }
        if(n==1){//jika n==1 data ditemukan
            cout<<"data ditemukan"<<endl;
        }
        else{//jika n tidak sama dengan 1 data tidak ditemukan
            cout<<"data tidak ditemukan"<<endl;
        }
}

void BST::urut(){//fungsi untuk menjadikan temp root dan memanggil fungsi uruttree
    tree *temp;
    temp=root;//penugasan variabel temp sebagai root
    uruttree(temp);//pemanggilan fungsi utama untuk pengurutan
}

void BST::uruttree(tree *temp){//fungsi untuk menelusuri tree nilai kecil sampai nilai besar
    if(temp!=NULL){
        uruttree(temp->left);//rekursif dengan argument temp->left
        cout<<"value :"<<temp->value<<endl;
        uruttree(temp->right);//rekursif dengan argument temp->right
    }
}

int main(){
    
    return 0;
}
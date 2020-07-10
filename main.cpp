#include <iostream>
using namespace std;

class tree //class tree sebagai penyimpan nilai pada node yang dibuat
{
    public:
        int value;//untuk menyimpan nilai pada node yang bersangkutan
        tree *left;//menunjuk alamat ke left child
        tree *right;//menunjuk alamat ke right child
        tree *parent;//menunjuk alamat ke parent
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
        if(temp->value==i){//jika nilai node binarysearchtree yang ada sama dengan nilainode yang dicari 
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

void BST::insert(int i){//fungsi untuk mengawali proses penginputan data
    tree *temp=new tree();
    temp=root;//objek temp adalah root
    if(root==NULL){//jika root null nilai yang diinputkan akan menjadi root
        root=new tree(i);
        cout<<"nilai "<<i<<" menjadi root"<<endl;
    }else{//jika tidak akan memanggil fungsi insertx
        insertx(i,temp);
    }
}

void BST::insertx(int i,tree *temp){//fungsi untuk melanjutkan proses penginputan data jika kondisi BST telah terisi sebelumnya
    tree *kiri=new tree();//membuat objek kiri
    tree *kanan=new tree();//membuat objek kanan
    if(i<=(temp->value)){//jika nilai yang diinputkan kecil dari nilai node yang dibandingkan
        kiri=temp;
        if(kiri->left!=NULL){//jika node left child tidak sama dengan NULL
            insertx(i,kiri->left);//node pindah
        }
        else{//jika nilai node telah berisi
            kiri->left=new tree(i);//nilai diletakkan pada node left child
            cout<<"nilai "<<i<<" masuk sebelah kiri "<<(kiri->value)<<endl;
            kiri->left->left=NULL;
            kiri->left->right=NULL;
        }
    }else{//jika nilai yang diinputkan besar dari nilai node yang dibandingkan
        kanan=temp;
        if(kanan->right!=NULL){//jika node right child tidak sama dengan NULL
            insertx(i,kanan->right);//node pindah
        }
        else{
            kanan->right=new tree(i);//nilai diletakkan pada node right child
            cout<<"nilai "<<i<<" masuk sebelah kanan "<<(kanan->value)<<endl;
            kanan->right->left=NULL;
            kanan->right->right=NULL;
        }
    }
}

void BST::minvalue(tree*temp){//mencari nilai terkecil dari node tertentu
    while (temp->left!=NULL)//melakukan penelusuran nilai node dikiri sampai ditemukannya node leaf(daun)
    {
        temp=temp->left;
    }
}

void BST::transplanted(tree *del,tree *reply){//fungsi untuk menghapus node parent menggantikannya dengan node child
    //tree *del node yang akan dihapus
    //tree *reply node child pengganti dari node yang akan dihapus
    if(del->parent==NULL){//jika node parent yang akan dihapus null
        root=reply;//node pengganti akan menjadi root
    }else if(del==del->parent->left){//jika node yang akan dihapus left child dari parentnya
        del->parent->left=reply;//node parent dihapus diganti dengan left child
    }else{//jika node yang akan dihapus right child dari parentnya
        del->parent->right=reply;//node parent dihapus diganti dengan right child
    }
    if(reply!=NULL){//jika node child pengganti dari node yang akan dihapus tidak sama dengan null
        reply->parent=del->parent;//menghapus node parent
    }
}

void BST::deletion(int i){
    //successor = nilai node paling kecil
    tree *y=NULL;//menyimpan nilai parent dari node tree *x
    tree *x;
    x=root;//sebagai root untuk mencari node yang akan dihapus
    //pencarian posisi nilai yang akan dihapus
    while ((x!=NULL)&&(x->value!=i)){//jika nilai tidak ditemukan diberi nilai null
    //jika node yang akan dihapus ditemukan perintah berikutnya akan dijalankan
        y=x;
        if(i<x->value){ 
            x=x->left;
        }
        else{
            x=x->right;
        }
    }
    if(x==NULL){
        cout<<"Nilai yang akan dihapus tidak ditemukan"<<endl;
    }else{
        x->parent=y;
        //pengecekan posisi node tersebut terhadap parent dan childnya
    if(x->left==NULL){//jika left child bernilai null,akan digantikan dengan node right childnya
        //right child akan menggantikan dan menghapus posisi dari node tree *x
        transplanted(x,x->right);//kondisi 2
    }else if(x->right==NULL){//jika right child bernilai null maka node tree*x,akan digantikan dengan node left childnya
        //dengan melakukan proses yang sama akan dipanggil method transplanted
        transplanted(x,x->left);//kondisi 2
    }else{
        //jika node yang akan dihapus memiliki left child dan right child
        tree *min=x->right;//menyimpan nilai successor dari method minvalue(x->right)
        //successor diambil dari hierarki node sebelah kanan dari node tree*x
        min->parent=x;

        tree *coba;
        while (min->left!=NULL)
        {
            coba=min;
            min=min->left;
        }
        tree *temp=min;
        temp->parent=coba;
        if(x->right!=min){//jika node successornya tidak berada disebelah kanan right child
            transplanted(min,min->right);//kondisi 2.2 //menjadikan successor sebagai parent
            temp->right=x->right;//dari right child
            temp->right->parent=temp;
        }
        //jika node successor tepat berada sebelah kanan node yang akan dihapus
        //langsung menggantikan node yang dihapus dengan node successornya 
        transplanted(x,temp);//kondisi 2.1 //mengganti node yang akan dihapus
        temp->left=x->left;//dengan node successor
        temp->left->parent=temp;
    }
}
}

//menampilkan keseluruhan dari node yang terdapat dalam BST secara lebih visual
void BST::display(tree *disp,int i){
    int k;
    if(disp!=NULL){
        display(disp->right,i+1);
        cout<<endl;

    if(disp==root){
        cout<<"root->: ";
    }
    else{
        for (k=0; k < i; k++){
                cout<<"     ";
            }
        }
        cout<<disp->value;
        display(disp->left,i+1);
    }
}

int main(){
    BST *st;//memanggil fungsi-fungsi yang terdapat didalam class BST
    st=new BST();
    int n;
    char pilih;
    cout<<"Operasi BST "<<endl;
    cout<<"1. Input data"<<endl;
    cout<<"2. cari data"<<endl;
    cout<<"3. nilai terkecil"<<endl;
    cout<<"4. nilai terbesar"<<endl;
    cout<<"5. Urut Tree"<<endl;
    cout<<"6. Hapus Node"<<endl;
    cout<<"7. Display"<<endl;
    cout<<"8. Exit"<<endl;
    //dowhile dan switch agar dapat menggunakan fungsi yang ada di dalam class BST secara berulang
    do
    {
        cout<<"Pilihan :";
        cin>>pilih;
        switch (pilih)
        {
        case '1':
            cout<<"Masukkan angka : ";
            cin>>n;
            st->insert(n);
            break;
        case '2':
            cout<<"Masukkan angka : ";
            cin>>n;
            st->searching(n);
            break;
        case '3':
            st->findmin();
            break;
        case '4':
            st->findmax();
            break;
        case '5':
            st->urut();
            break;
        case '6':
            cout<<"Masukkan angka :";
            cin>>n;
            st->deletion(n);
            break;
        case '7':
            cout<<"Display BST :"<<endl;
            st->display(root,1);
            cout<<endl;
            break;
        default:
            cout<<"salah pilih atau keluar";
            break;
        }
    } while (pilih!='8');
    return 0;
}
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

int main(){
    
    return 0;
}
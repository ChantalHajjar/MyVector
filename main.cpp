#include <iostream>

typedef int type;

using namespace std;

//header file
class MyVector{
  public:
    MyVector(int = 1);
    MyVector(type*, int);
    MyVector(const MyVector&);
    ~MyVector();
    MyVector& operator=(const MyVector&);
    const type operator[]  (int i) const;
    type& operator[] (int i);
    MyVector& operator+=(const MyVector&);
    
    void push_back(type);
    type pop_back();
  private:
    int size; // nb of elements
    int capacity; //nb of allocated bytes
    type* ptr; //pointer to the array base
    friend ostream& operator<< (ostream&, const MyVector&);

};

const MyVector operator+(MyVector v1, const MyVector& v2);

// implementation

MyVector::MyVector(int c)
:capacity(c), size(0), ptr(new type[capacity])
{
  for (int i = 0; i < c ;++i){
    ptr[i] = 0;
  }
} 
MyVector::MyVector(type* p, int n)
: capacity(n), size(n), ptr( new type [capacity])
{

//    for (int i = 0; i < size; ++i){
//     ptr[i] = p[i];
//    }
   memcpy(ptr,p,size*sizeof(type));
}

MyVector::~MyVector(){
    delete[] ptr;
    ptr = nullptr;
}
ostream& operator<< (ostream& os, const MyVector& v){
  os << "{" ;
  int i;
  for (i = 0; i < v.size-1; ++i){
    os << v.ptr[i] << ",";
  }
  os << v.ptr[i] << "}";
  return os;
}
void MyVector::push_back(type a){
    if (size == capacity){
        type* old = ptr;
        ptr = new type [capacity*2];
        memcpy(ptr,old,size*sizeof(type));
        delete[] old;
        capacity *= 2;
        for (int i=size; i < capacity; ++i){
            ptr[i] = 0;
        }
    }
    ptr[size] = a;
    size++;
}
//driver program
int main(){
    type tab [] = {1,2,3,4,5};
    MyVector v1(tab,5);
    MyVector v2;
    v2.push_back(8);
    v2.push_back(9);
    cout << "v2 = " << v2 << endl;
    cout << "v1 = " << v1 << endl;
    v1.push_back(6);
    cout << "v1=" << v1 << endl;
    return 0;
}
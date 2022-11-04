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
int main(){
    return 0;
}
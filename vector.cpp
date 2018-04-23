#include <iostream>
#include <assert.h>
using namespace std;
template <typename T>
class Vector
{
public:
    //构造函数
    Vector(int number,T fillnumber);
    //析构函数
    ~Vector();

    //编写函数实现size、empty、resize、push_back的功能
    int size();
    int empty();
    void resize(int renumber);
    void resize(int renumber,T refillnumber);
    void reserve(int recapacity);
    void push_back(T backfill);
    void insert(int posotion,T content);

    T &operator [](int);

    void show();
private:
    int vsize;
    int vcapacity;
    T *V;

};

template <typename T>
Vector<T>::Vector(int number,T fillnumber)
{
    vsize=number;
    vcapacity=number;
    V=new T[vcapacity];
    assert(V!=NULL);
    for(int i=0;i<number;i++){
        V[i]=fillnumber;
    }
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] V;
}

template <typename T>
int Vector<T>::empty()
{
    vsize=0;
    return vsize;
}

template <typename T>
int Vector<T>::size()
{
    return vsize;
}

template <typename T>
void Vector<T>::reserve(int recapacity)
{
    if(recapacity<=vcapacity){
        T *newV;
        newV=new T[recapacity];
        assert(newV!=NULL);
        for(int i=0;i<recapacity;i++){
            newV[i]=V[i];
        }
        delete[] V;
        V=newV;
        vcapacity=recapacity;
    }
    else{
        T *newV;
        newV=new T[recapacity];
        assert(newV!=NULL);
        for(int i=0;i<vcapacity;i++){
            newV[i]=V[i];
        }
        delete[] V;
        V=new T[recapacity];
        assert(V!=NULL);
        V=newV;
        vcapacity=recapacity;
    }
}

template <typename T>
void Vector<T>::resize(int renumber)
{
    if(renumber<=vsize){
        T *newV;
        newV=new T[renumber];
        assert(newV!=NULL);
        for(int i=0;i<renumber;i++){
            newV[i]=V[i];
        }
        delete[] V;
        V=newV;
    }
    else{
        T *newV;
        newV=new T[renumber];
        assert(newV!=NULL);
        for(int i=0;i<renumber;i++){
            newV[i]=0;
        }
        for(int i=0;i<vsize;i++){
            newV[i]=V[i];
        }
        delete[] V;
        V=new T[renumber];
        assert(V!=NULL);
        V=newV;
    }
}

template <typename T>
void Vector<T>::resize(int renumber,T refillnumber)
{
    if(renumber<=vsize){
        T *newV;
        newV=new T[renumber];
        assert(newV!=NULL);
        for(int i=0;i<renumber;i++){
            newV[i]=V[i];
        }
        delete[] V;
        V=newV;
    }
    else{
        T *newV;
        newV=new T[renumber];
        assert(newV!=NULL);
        for(int i=0;i<renumber;i++){
            newV[i]=refillnumber;
        }
        for(int i=0;i<vsize;i++){
            newV[i]=V[i];
        }
        delete[] V;
        V=new T[renumber];
        assert(V!=NULL);
        V=newV;
    }
}

template <typename T>
void Vector<T>::push_back(T backfill)
{
    reserve(vcapacity++);
    V[vsize++]=backfill;
    vsize++;
    vcapacity++;
}

template <typename T>
void Vector<T>::insert(int position,T content)
{
    T *newV;
    newV=new T[vcapacity++];
    assert(newV!=NULL);
    newV[position]=content;
    for(int i=0,j=0;i<vsize;i++){
	if(j=posotion){
	    j++;
	}
	newV[j]=V[i];
    }
    vsize++;
    delete[] V;
    V=new T[vcapacity++];
    assert(V!=NULL);
    V=newV;
}

template <typename T>
T &Vector<T>::operator[](int i)
{
    if(i>=vsize)
    {
        cout<<"index out of bounds";
    }
    return V[i];
}

template <typename T>
void Vector<T>::show()
{
    for(int i=0;i<vsize;i++){
        if(i!=vsize-1) cout<<V[i]<<",";
        else cout<<V[i]<<endl;
    }
}
int main()
{
    int t;
    Vector<int> v(5,9);
    cout<<"number one:";
    v.show();
    v.push_back(1);
    cout<<"number two:";
    v.show();
    v.resize(8);
    cout<<"number three:";
    v.show();
    v.resize(4);
    cout<<"number four:";
    v.show();
    v.empty();
    cout<<"number five:";
    v.show();
    v.resize(6,1);
    cout<<"number six:";
    v.show();
    v.insert(2,1);
    cout<<"number seven:";
    v.show();
    cout<<v.size()<<endl;
    return 0
}

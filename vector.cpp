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

    T &operator [](int);
    Vector<T> &operator=(const Vector& rhs);

    void show();
private:
    //区分开size和capacity两个不同的概念
    int vsize;
    int vcapacity;
    T *V;

};

    //构造函数，用于初始化vector，这里我只实现了一种操作
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

    //析构函数
template <typename T>
Vector<T>::~Vector()
{
    delete[] V;
}

    //empty函数
template <typename T>
int Vector<T>::empty()
{
    if(vsize==0) return 1;
    else return 0;
}

    //size函数
template <typename T>
int Vector<T>::size()
{
    return vsize;
}

    //reserve：用于改变vector的容量，原本不打算写这个函数，但后来发现resize和push_back都要改变vector的容量大小，就写上去了。每一次变换都要更新原本的capacity，体现在①处
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
    }
    vcapacity=recapacity;	    //①
}

    //下面两个都是resize函数，两种使用方法
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
    vsize=renumber;
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
    vsize=renumber;
}

    //push_back函数
template <typename T>
void Vector<T>::push_back(T backfill)
{
    reserve(vcapacity++);
    V[vsize++]=backfill;
}

    //[]重载（我目前对[]的重载了解的不是很清楚，还不是很明白这样一个重载会起到什么作用，c++ plus的书上也没怎么介绍，于是就上网搜了一下，大部分体现的判断是否越界的一个作用，就照本宣科了一下。。。
template <typename T>
T &Vector<T>::operator[](int i)
{
    if(i>=vsize)
    {
        cout<<"index out of bounds";
    }
    return V[i];
}

    //=重载，因为之前有好多地方都要进行vector更新的步骤，就写了个赋值运算符的重载，并且参考了一下这个教程：https://www.cnblogs.com/zpcdbky/p/5027481.html
template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &rhs)
{
    if(this !=&rhs){
	delete [] V;
	vsize=rhs.vsize;
	vcapacity=rhs.vcapacity;
	V=new T[vcapacity];
	assert(V!=NULL);
	for(int i=0;i<vsize;i++){
	    V[i]=rhs.V[i];
	}
    }
    return *this;
}

    //一个输出函数（单纯为了方便）
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
    cout<<v.size()<<endl;
    return 0;
}

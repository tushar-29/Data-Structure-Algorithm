#include<iostream>
using namespace std;

template <class type>
class Arithametic
{
    private:
    type a, b;
    public:

    Arithametic(){a = b = 0;}
    Arithametic(type a, type b);
    type add();
    type subtract();
};

template<class type>
Arithametic<type> :: Arithametic(type a, type b)
{
    this->a = a;
    this->b = b;
}

template<class type>
type Arithametic<type> :: add()
{
    return (a + b);
}

template <class type>
type Arithametic<type> :: subtract()
{
    return (a - b);
}

int main()
{
    Arithametic<int> ar={80, 5};
    cout<<"sum = "<<ar.add()<<endl;
    cout<<"difference = "<<ar.subtract()<<endl;
    Arithametic <float> ar2={5.578, 2.5678};
    cout<<"sum = "<<ar2.add()<<endl;
    cout<<"difference = "<<ar2.subtract()<<endl;
    return 0;
}
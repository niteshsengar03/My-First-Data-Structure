#include<stdio.h>
#include<iostream>
using namespace  std;
// ARRAAY DATA STRUCTURE 
class Array  // this is abstract data type
{
    private:
        int capacity;
        int lstIndex;
       // int a[100];  // esse banana kuy glt ha?   kuy ki jruri nhi ha ki array humesa 100 size ka hi ho
       int *ptr;
    public:
        Array();
        void createArray(int);
        //pass size of array
        //cappacity= size;
        //lastIndex=-1;
        //aur ptr mein jo address create kroge new ke help se uska address
        void insert(int,int); // index, value
        void append(int); // joe last indexplus one pe data rhak degi just pass data
        int getItem(int); // pass index and it will give value
        bool isEmpty(); // return true or false
        bool isFull();
        void del(int); // give index
        void edit(int,int); //index,new value
        int count(); //kitne values ha ye return karega
        int getCapacity(); //

};
int Array::getCapacity()
{
    return capacity;
}
Array::Array()
{
    ptr=NULL;
}
void Array:: createArray(int size)
{
    capacity=size;
    lstIndex=-1;
    if(ptr!=NULL)
        delete []ptr;
    ptr=new int[size];
}
void Array:: insert(int index, int value)
{
    if(index<0 || index>lstIndex+1)
        cout<<"Invalid Index";
    else if(isFull())
        cout<<"overflow";
    else
    {
        for(int i=lstIndex;i>=index;i--)
            ptr[i+1]=ptr[i];
        ptr[index]=value;
        lstIndex++;
    }
}
 void Array:: append(int value)
 {
    if(!isFull())
    {
        lstIndex++;
        ptr[lstIndex]=value;
    }
    else    
        cout<<"Overflow: append not performed";
 }
 int Array::getItem(int index)
 {
    if(index<0 || index>lstIndex)
        cout<<"Invalid index or Array is empty";
    else
        return ptr[index];
 }
bool Array::isEmpty()
{
    if (lstIndex==-1)
        return true;
    else 
        return false;
}
bool Array::isFull()
{
    if (lstIndex==capacity-1)
        return 1;
    else
        return 0;
}

void Array::del(int index)
{
    if(index<0 || index>lstIndex)
        cout<<"Invalid index or Array is empty";
    else   
    {
        for(int i=index;i<lstIndex;i++)
            ptr[i]=ptr[i+1];
        lstIndex--;
    }
}

void Array::edit(int index,int value)
{
    if(index<0 || index>lstIndex)
        cout<<"Invalid index";
    else
        ptr[index]=value;
}

int Array::count()
{
    return lstIndex+1;
}

int main()
{
    Array a1;
    a1.createArray(5);
    cout<<a1.isEmpty()<<endl;
    a1.append(1);
    a1.append(2);
    a1.append(3);
    cout<<a1.getItem(2);
    a1.insert(1,9);
    a1.del(1);
    return 0;
}
#include<iostream>
#include <vector>
using namespace std;


void Insertion(vector<int>& arr)
{ 
    // SWAPING METHOD
    int size=arr.size();
    cout<<endl<<"SWAPING METHOD"<<endl;
    cout << "Array before Insertion: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;

    int z ; 
    arr.resize(size+1);
    size++;

    cout<<"Enter value to insert : ";
    cin>>z;
    
    for (int i = 0; i < size; i++)
    {
        swap(z, arr[i]); 
    }
    
     cout << "Updated Array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" " ;
    }
    cout<<endl;
 
    //Original move placement method
    
    cout<<endl<<"ORIGINAL METHOD "<<endl;
    cout << "Array before Insertion: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    int zz = 0; 
    cout<<"Enter value to insert : ";
    cin>>zz;

    arr.resize(size + 1);

    for(int i = size-1; i > 0; i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=zz;
    cout <<endl<< "Updated Array:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] <<" ";
    }
    cout<<endl;
  
}   

void Deletion(vector<int>& arr)
{
    int size=arr.size(),index;
    
    cout <<endl<< "Array before deletion: "<<endl;
    cout<<"Enter value to delete : ";
    cin>>index;
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    for(int i=index;i<size-1;i++)
    {
        arr[i]=arr[1+i];
    }
    size--;
    cout <<endl<< "Array after deletion: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}   
    
void search(vector<int>& arr,int n)
{
    int LB=0,UB=n-1,data;
    cout<<"Enter data for search : ";
    cin>>data;
    int mid;
    mid=(LB+UB)/2;

    while(LB<=UB && arr[mid]!=data)
    {
        if(data<arr[mid])
        UB=mid-1;
        else
        LB=mid+1;
        mid=(LB+UB)/2;
    }
        if(arr[mid]==data)
        cout<<"Data found at index "<<mid<<endl;
        else
        cout<<"Data not found";
}

int main()
{
    int n=4;
    vector<int> arr(n);
    cout<<"Enter 4 values : ";
    for(int i=0;i<4;i++)
    {
        cin>>arr[i];
    }
    Insertion(arr);
    Deletion(arr);
    search(arr,arr.size());

}
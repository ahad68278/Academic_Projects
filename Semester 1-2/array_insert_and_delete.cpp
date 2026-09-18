#include<iostream>
#include<vector>
using namespace std;

void Insertion(vector<int>& arr)
{
    // SWAPING METHOD
    cout<<endl<<"SWAPING METHOD"<<endl;
    int a[10] = {2, 3, 4, 5, 6, 7, 8, 9, 11};
    int z = 1; 
    for (int i = 0; i < 10; i++)
    {
        swap(z, a[i]); 
    }
cout <<endl<< "Updated Array:" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] <<" " ;
    }
    cout<<endl;
{
    //Original move placement method
    cout<<endl<<"Original move placement method"<<endl;
    int aa[10] = {2, 3, 4, 5, 6, 7, 8, 9, 11};
    int zz;
    cout<<"Enter : ";
    cin>>zz;

    for(int i = 9; i > 0; i--)
    {
        aa[i]=aa[i-1];
    }
    aa[0]=zz;
    cout <<endl<< "Updated Array:" << endl;
     for (int i = 0; i < 10; i++)
    {
        cout << aa[i] <<" ";
    }
    cout<<endl;
}
}

void Deletion(vector<int>& arr)
{
    int size=5,index=2;

    cout << "Array before deletion: ";
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

void search(vector <int> & a,int &n)
{
    int la=0,ua=n-1,mid,data;
    mid=(ua-la)/2;

    cout<<"Enter the index to be searched : ";
    cin>>data;
    while(la<=ua && a[mid]!=data)
    {
        if(data < a[mid])
        ua=mid-1;
        else
        la=mid+1;
        mid=(ua-la)/2;
    }
    if(a[mid]==data)
    cout<<"Data found "<<a[mid]<<endl;
    else
    cout<<"Data not found";
};

int main()
{
    int n,m;
    cout<<"Enter the number of array U want : ";
    cin>>n;
    
    vector <int> arr(n);

    cout<<"Enter the "<<n<<" number of array data : "<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"Enter "<<endl<<"1 for Insertion"<<endl<<"2 for Deletion"<<endl<< "3 for Search" <<endl;
    cin>>m;

    if(m==1)
    Insertion(arr);
    else if(m==2)
    Deletion(arr);
    else
    search(arr,n);
}
#include<iostream>
#include<conio.h>
using namespace std;
#define clrscr();

//merge function to merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r)	
{
    //create L-A[p..q] and M-a[q+1..r]
	int n1 = q-p+1;
	int n2 = r-q;
	int L[n1], M[n2];
for(int i=0; i<n1; i++)
	    L[i]=arr[p+i];
	for(int j=0; j<n2; j++)
	    M[j]=arr[q+1+j];

    //maintain current index of sub arrays and main array
	int k;
int i=0;
	int j=0;
	k=p;

    /*until we reach either end of either L or M, pick larger among elements L and M and place them into correct position at A[p..r]*/
	while(i<n1 && j<n2)
	{
	    if(L[i]<=M[j])
	    {
		arr[k]=L[i];
		i++;
	    }else
	    {
arr[k]=M[j];
	    j++;
	}
	k++;
	}

while(i<n1)	
	{
	    arr[k]=L[i];
	    i++;
	    k++;
	}
	while(j<n2)
	{
	    arr[k]=M[j];
	    j++;
	    k++;
	}
}
void mergeSort(int arr[], int l, int r)
{
   if(l<r)
   {	
int m=l+(r-1)/2;
mergeSort(arr, l, m);
      mergeSort(arr, m+1, r);

     //merge the sorted subarrays
      merge(arr, l, m, r);
   }
}

//print the array
void printArray(int arr[], int size)
{
    for(int i=0; i<size; i++)
       cout<<arr[i]<<" ";
       cout<<endl;
}

//main function
int main()
{
    int n, i, a[20];
    clrscr();
cout<<"\nEnter total number of elements in array(<=20) : ";
    cin>>n;
    cout<<"Input array elements to be sorted\n";
    for(i=0; i<n; i++)
    {
	cout<<"Enter element a["<<i<<"] ";
	cin>>a[i];
    }
    cout<<"\nArray element before sorting are \n";
    printArray(a,n);                                   //calling function
    mergeSort(a,0,n-1);                                //calling function
    cout<<"\nArray element after sorting are \n";
    printArray(a,n);                                   //calling function
    cout<<endl;
getch();
    return 0;
}
#include <iostream>
#include <math.h>
#include <random>
#include <time.h>
using namespace std;
long int ss,is, ms, qs1,qs2,qs3=0;

void randompermutationarray(int A[],int N) {
    srand ( (unsigned) time (NULL) );
    for(int i=0;i<N;i++)
    {
        A[i]=0;
    }

    int m;
    for(int i=0;i<N;i++)
    {
        A[i]=i;
    }
    for(int i=2;i<N;i++)
    {
            m = 1+rand()%i;
            swap ( A[i], A[m]);
    }
}
void selectsort (int a[ ], int n) //selection sort
{
    int i , j , m;
    for (i = 0; i < n-1; i++) {
        m = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[m]) { m = j; }
            ss++;
    }
        swap (a[i] , a[m]);

    }
}
void insertion(int A[], int N) {
    int i, j,v;
    for(int i = 1; i<N; i++) {
        v= A[i];
        j = i;
        while(j > 0 && A[j-1]>v) {
            A[j] = A[j-1];
            j--;
            is++;
        }
        A[j] = v;
        is++;
    }

}
void Merge(int A[],int p, int q,int r)
{

    int n1,n2,i,j,k;
    //size of left array=n1
    //size of right array=n2
    n1=q-p+1;
    n2=r-q;
    int L[n1],R[n2];
    //initializing the value of Left part to L[]
    for(i=0;i<n1;i++)
    {
        L[i]=A[p+i];

    }
    //initializing the value of Right Part to R[]
    for(j=0;j<n2;j++)
    {
        R[j]=A[q+j+1];
    }
    i=0,j=0;
    //Comparing and merging them
    //into new array in sorted order
    for(k=p;i<n1&&j<n2;k++)
    {
        if(L[i]<R[j])
        {    ms++;
            A[k]=L[i++];
        }
        else
        { ms++;
            A[k]=R[j++];
        }
    }
    //If Left Array L[] has more elements than Right Array R[]
    //then it will put all the
    // reamining elements of L[] into A[]
    while(i<n1)
    {
        A[k++]=L[i++];
    }
    //If Right Array R[] has more elements than Left Array L[]
    //then it will put all the
    // reamining elements of L[] into A[]
    while(j<n2)
    {
        A[k++]=R[j++];
    }
}
//This is Divide Part
//This part will Divide the array into
//Sub array and then will Merge them
//by calling Merge()
void MergeSort(int A[],int p,int r)
{
    int q;
    if(p<r)
    {
        ms++;
        q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        Merge(A,p,q,r);
    }
}

int partition (int A[], int p, int r){
// Partition sub-array A[p..r] around pivot
int pivot, i, j;
pivot = A[p]; // pivot is chosen as the first element
i = p; j = r;
do
{
do { i++;qs1++; } while (A[i] < pivot);
do { j--;qs1++; } while (A[j] > pivot);
if (i < j) swap (A[i] , A[j]);
} while (i < j);
A[p] = A[j]; A[j] = pivot;
return j; // j is the final location of the pivot
}
int partition2 (int A[], int p, int r)
{
// Partition sub-array A[p..r] around pivot
    int pivot, i, j;
    pivot = A[(p+r)/2]; // pivot is chosen as the first element
    i = p; j = r;
    do
    {
        do { i++;qs2++; } while (A[i] < pivot);
        do { j--;qs2++; } while (A[j] > pivot);
        if (i < j) swap (A[i] , A[j]);
    } while (i < j);
    A[p] = A[j]; A[j] = pivot;
    return j; // j is the final location of the pivot
}



int partition3 (int A[], int p, int r)
{
    srand ( (unsigned) time (NULL) );
// Partition sub-array A[p..r] around pivot
    int pivot, i, j;
    pivot = p+rand()%(r-p);; // pivot is chosen as the first element
    i = p; j = r;
    do
    {
        do { i++;qs3++; } while (A[i] < pivot);
        do { j--;qs3++; } while (A[j] > pivot);
        if (i < j) swap (A[i] , A[j]);
    } while (i < j);
    A[p] = A[j]; A[j] = pivot;
    return j; // j is the final location of the pivot
}

void QuickSort (int A[], int p, int r) {
// QuickSort using partitioning
// Sorts the elements A[p],..., A[r] in the array A[1:N] into ascending order
// A[N+1] is considered to be defined and must be >= all the elements in A[1..N]
// To sort the whole array, call as QuickSort (A, 1, N)
qs1++;

        if (p >= r)
            return;
        if (p < r) {
            // If there are more than one element
            int q = partition(A, p, r + 1); // partition around Pivot
// q is the position of the pivot
            QuickSort(A, p, q - 1); // Sort left sub-array
            QuickSort(A, q + 1, r); // Sort Right sub-array
        }

}
void QuickSort2 (int A[], int p, int r) {
    // QuickSort using partitioning
// Sorts the elements A[p],..., A[r] in the array A[1:N] into ascending order
// A[N+1] is considered to be defined and must be >= all the elements in A[1..N]
// To sort the whole array, call as QuickSort (A, 1, N)
qs2++;
    if (p >= r)
        return;

        if (p < r) { // If there are more than one element
            int q = partition2(A, p, r + 1); // partition around Pivot
// q is the position of the pivot
            QuickSort2(A, p, q - 1); // Sort left sub-array
            QuickSort2(A, q + 1, r); // Sort Right sub-array
        }
    }

void QuickSort3 (int A[], int p, int r) {
    // QuickSort using partitioning
// Sorts the elements A[p],..., A[r] in the array A[1:N] into ascending order
// A[N+1] is considered to be defined and must be >= all the elements in A[1..N]
// To sort the whole array, call as QuickSort (A, 1, N)

qs3++;
    if (p >= r)
        return;
    {
        if (p < r) { // If there are more than one element
            int q = partition3(A, p, r + 1); // partition around Pivot
// q is the position of the pivot
            QuickSort3(A, p, q - 1); // Sort left sub-array
            QuickSort3(A, q + 1, r); // Sort Right sub-array
        }
    }
}

int main() {
    int N;
    int *A=new int[10000];
    int values[6]={1000,2000,3000,5000,7000,10000};

    for(int i=0;i<6;i++) {

        N=values[i];
        randompermutationarray(A, N);
        QuickSort(A, 0, N);
        randompermutationarray(A, N);
        QuickSort2(A, 0, N);
        randompermutationarray(A, N);
        QuickSort3(A, 0, N);
        randompermutationarray(A, N);
        MergeSort(A, 0, N);
        randompermutationarray(A, N);
        insertion(A, N);
        randompermutationarray(A, N);
        selectsort(A, N);
cout<<"at number of elements = "<<N<<endl;
        cout << "Number of comparisons for selection sort is " << ss << endl;
        cout << "Number of comparisons for insertion sort is " << is << endl;
        cout << "Number of comparisons for merge sort is " << ms << endl;
        cout << "Number of comparisons for quick sort 1 is " << qs1 << endl;
        cout << "Number of comparisons for quick sort 2 is " << qs2 << endl;
        cout << "Number of comparisons for quick sort 3 is " << qs3 << endl;
        ss = 0;
        is = 0;
        ms = 0;
        qs1 = 0;
        qs1 = 0;
        qs2 = 0;
        qs3 = 0;
    }
    return 0;
}


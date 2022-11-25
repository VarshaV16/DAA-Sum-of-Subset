#include <bits/stdc++.h>
using namespace std;

static int total_nodes;
 
void printsortedarray(int s[],int n){ 
    cout<<"The entered array in sorted form is: \nArray P = ";
    for (int i = 0; i < n; i++)
    {       
        cout<<s[i]<<"  ";
    }
cout<<"\n";
cout<<"Array Q = \n";
}

// prints subset 2Darray solution
void printSubset(int A[], int size,int v[],int j)
{
    int i=0,k=0;
    
    while( k<size){
    for(int i = 0; i < j; i++)
    {
        // cout<<"V[i]= "<<v[i]<<", A[k]= "<<A[k]<<"\n";
        if (v[i]==A[k])
        {
            cout<<1<<" ";
            k++;
        }
        else cout<<0<<" ";
    }
    cout<<"\n";
}
}
 
// qsort compare function
int comparator(const void *pLhs, const void *pRhs)
{
    int *lhs = (int *)pLhs;
    int *rhs = (int *)pRhs;
    return *lhs > *rhs;
}

void subset_sum(int s[], int t[],
                int s_size, int t_size,
                int sum, int ite,
                int const target_sum)
{
    total_nodes++;
 
    if( target_sum == sum )
    {
        //prints subset arrays
        printSubset(t, t_size,s,s_size);
 
        // constraint check
        if( ite + 1 < s_size && sum - s[ite] + s[ite + 1] <= target_sum )
        {
            // Exclude previous added item and consider next candidate
            subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
        }
        return;
    }
    else
    {
       
        // constraint check
        if( ite < s_size && sum + s[ite] <= target_sum )
        {
           
            // generate nodes along the breadth
            for( int i = ite; i < s_size; i++ )
            {
                t[t_size] = s[i];
                if( sum + s[i] <= target_sum )
                {
                   
                    // consider next level node (along depth)
                    subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
                }
            }
        }
    }
}
 
// To print subsets that sum to target_sum
void generateSubsets(int s[], int size, int target_sum)
{
    int *tuplet_vector = (int *)malloc(size * sizeof(int));
    int total = 0;
 
    // sort the set
    qsort(s, size, sizeof(int), &comparator);
    printsortedarray(s,size);
    for( int i = 0; i < size; i++ )
    {
        total += s[i];
    }
    if( s[0] <= target_sum && total >= target_sum )
    {
        subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
    }
    free(tuplet_vector);
}
 
// Driver code
int main()
{
    int n,target;
    cout<<"Enter number of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : \n";
    for (int i = 0; i < n; i++)
    {
      cin>>arr[i];
    }
    cout<<"Enter target sum : ";
    cin>>target;
    
    generateSubsets(arr, n, target);
    return 0;
}


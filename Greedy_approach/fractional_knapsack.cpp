// An efficient solution is to use Greedy approach. The basic idea of the greedy approach is to calculate the ratio value/weight for each item and sort the item on basis of this ratio. Then take the item with the highest ratio and add them until we can’t add the next item as a whole and at the end add the next item as much as we can. Which will always be the optimal solution to this problem.


// A simple code with our own comparison function can be written as follows, please see sort function more closely, the third argument to sort function is our comparison function which sorts the item according to value/weight ratio in non-decreasing order. 


// After sorting we need to loop over these items and add them in our knapsack satisfying above-mentioned criteria.

#include<bits/stdc++.h>
using namespace std;
class item{
    public:
    int value,weight;

    item(int value, int weight)
    {
        this->value= value;
        this->weight = weight;
    } 

};
bool compare(item a, item b)
{
    double r1 = (double)a.value/ (double)a.weight;
    double r2= (double) b.value/ (double)b.weight;
    return r1> r2;
}
double fractionalk(int w,item arr[], int n)
{
    sort(arr,arr+n, compare);
    int currentweight = 0; // current weight of knapsack
    double finalvalue=0.0; // result
    for(int i=0;i<n;i++)
    {
        if(currentweight + arr[i].weight <=w)
        {
            // adding item wont overflow so add it whole
             currentweight+= arr[i].weight;
             finalvalue+= arr[i].value;
        }else{
            // if cant add it whole add it fractional
            int remain = w - currentweight;
            finalvalue += (arr[i].value)*(double(remain)/ (double)arr[i].weight);
            break;
        }
    }

return finalvalue;


}
int main()
{
    int w=50; // knapsack weight
    // value, weight pairs
   item arr[]={{60,10},{100,20},{120,30}}; 
   int n = sizeof(arr)/sizeof(arr[0]);

   cout<<" Maximum value obtained is = "<<fractionalk(w,arr,n);
   return 0;
}
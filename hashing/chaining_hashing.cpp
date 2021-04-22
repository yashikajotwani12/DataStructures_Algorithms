#include<iostream>
#include<list>
using namespace std;
class Hash{
    int bucket;   //no of buckets
    list <int> *table;  //pointer to an array containing buckets
 public:
       Hash(int v) {
            this->bucket= v;
            table=new list<int>[bucket];
       }
       void insertitem(int x);
       void deleteitem(int key);

 //hash function to map values to the key
 int hashfunction(int x)
 {
     return (x % bucket);
 }
 void displayhash();


};
void Hash::insertitem(int key)
{
    int index=hashfunction(key);
    table[index].push_back(key);

}
void Hash::deleteitem(int x)
{
    int index=hashfunction(x);//hash index

    list<int>::iterator i;
    for(i=table[index].begin();i!=table[index].end();i++)
    {
        if(*i==x)
        break;
    }
    

    //key is found then erase it 
    if(i!=table[index].end())
    {
        table[index].erase(i);

    }


}
void Hash::displayhash()
{
    for(int i=0;i<bucket;i++)
    {
        cout<<i;
        for(auto x:table[i])
        cout<<"-->"<<x;
        cout<<endl;
    }
}
int main() 
{ 
  // array that contains keys to be mapped 
  int a[] = {15, 11, 27, 8, 12}; 
  int n = sizeof(a)/sizeof(a[0]); 
  
  // insert the keys into the hash table 
  Hash h(7);   // 7 is count of buckets in 
               // hash table 
  for (int i = 0; i < n; i++)  
    h.insertitem(a[i]);   
  
  // delete 12 from hash table 
  h.deleteitem(12); 
  
  // display the Hash table 
  h.displayhash(); 
  
  return 0; 
} 

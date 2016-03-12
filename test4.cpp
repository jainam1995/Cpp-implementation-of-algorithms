/*   AUTHOR : AVANEESH KUMAR2014 ,BIET JHANSI, prmrs111@live.com       */
#include<iostream>
#include<vector>
 
using namespace std;
 
/*-----------------------------------------------*/
 
void getMax(vector<int>& input, int k, vector<int>& maxi){
 if (k == 0) {
  int flag=0;
  for(int i=0;i<input.size();i++)
  {
   if(input[i]<maxi[i])
   {
    flag=0;break;
   }
   else if(input[i]>maxi[i])
   {
    flag=1; break;
   }
  }
  if(flag)
  { 
   for (int i = 0; i < input.size(); i ++) {
    maxi[i]=input[i];
   }
  }
  return;
 }
 
 for (int i = 0; i < input.size() - 1; i ++) {
  for (int j = i + 1; j < input.size(); j ++) {
   swap(input[i], input[j]);
   getMax(input, k - 1, maxi);
   swap(input[i], input[j]);
  }
 }
 return;
}
 
void swap2max(vector<int> input, int k) {
 if (input.size() < 2) {
  cout << "invalid input" << endl;
 }  
 vector<int> maxi;
 maxi = input;
 for (int i = 0; i < input.size(); i ++) {
  maxi[i]=0;
 }
 //getMax(input, k, maxi);
 
 cout << "---> ";
 for (int i = 0; i < maxi.size(); i ++) {
  cout << maxi[i] << " ";
 }
 cout<<endl;
 cout << "---> ";
 for (int i = 0; i < input.size(); i ++) {
  cout << input[i] << " ";
 }
 cout<<endl;
 return;
}
 
int main()
{
 
 vector<int> input1 ;
//(34299273,3)
 input1.push_back(1);
 input1.push_back(9);
 input1.push_back(2);
 input1.push_back(8);
 input1.push_back(8);
 input1.push_back(8);    
 input1.push_back(8);
 swap2max(input1, 3);
 
 input1.clear();
// (8799,2)
 input1.push_back(8);
 input1.push_back(7);
 input1.push_back(9);
 input1.push_back(9);
 
 swap2max(input1, 2);
 
 
 input1.clear();
// (132,2)
 input1.push_back(1);
 input1.push_back(3);
 input1.push_back(2);
 swap2max(input1, 2);
 
 return 0;
}
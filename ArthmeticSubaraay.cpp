 #include<iostream>
 using namespace std;
 
 int main(){
     
     int n;
     cout<<"Enter the size of an array"<<endl;
     cin>>n;

     int a[n];
     cout<<"Enter the elements of an array"<<endl;
     for(int i=0;i<n;i++){
         cin>>a[i];
     }

     int pd,current,ans,j;
     pd=a[1]-a[0];
     ans = 2;
     j=2;
     current = 2;

     while(j<n){

        if(pd == a[j]-a[j-1]){
            current++;
        }
          
        else{

            pd = a[j]-a[j-1];   
            current = 2;
         }

      ans = max(ans,current);
      j++;
     
     }

 cout<<ans<<endl;

 
 return 0;


 }
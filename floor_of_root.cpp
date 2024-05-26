#include<iostream>


using namespace std;


int main()
{

    int n,s,e,mid,root;
    s=1;
    cout<<"Enter number."<<endl;
    cin>>n;
    e=n;
    root=0;
    
    while(s<=e){

        mid = s+(e-s)/2;

        if(mid*mid == n){
            root = mid;
            break;
        }
        else if(mid*mid > n){
            e = mid-1;
        }
        else{
            root = mid;
            s = mid+1;
        }
    }
    cout<<"Floor of root of "<<n<<" is "<<root<<endl;

    return 0;
}
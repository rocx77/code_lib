#include<iostream>
#include<cstdlib>
#include<cmath>


using namespace std;


    unsigned int floor_root(int n){

        long int s,e,mid,root;
        s=1;
        e=n;
        while(s<=e){

            mid = s+(e-s)/2;

            if(pow(mid,2) == n){
                root = mid;
                break;
            }
            else if(pow(mid,2) > n){
                e = mid-1;
            }
            else{
                root = mid;
                s = mid+1;
            }
        }
        return root;
    }



float root(int n){

    float f = floor_root(n);
    float a = 0.1;
    float root;

   while(a > 0.000001){

        f = f + a;

        if( pow(f,2) <= n){
            root = f;
        }
        else{
            a = a/10;
            f = root;
        }
   }
   return root;
}



int main()
{
    int x;
    cout<<"Enter number."<<endl;
    cin>>x;
    cout<< "Root: "<<root(x)<<endl;

    return 0;
}
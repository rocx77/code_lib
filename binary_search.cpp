#include<iostream>
#include<cstdlib>
#include<cmath>


using namespace std;


int main()
{
    int s=0,e=10,mid=0,k;
    k = 12;
    int arr[e] = {12,13,16,91,298,1001,2012,3213,10002,23456};

    while(s<e){
        mid = s+(e-s)/2;
        if(arr[mid] == k){
            cout<<"index of key is "<<mid<<endl;
            k = -1;
        }
        else if(arr[mid] > k){
            e = mid-1;
        }
        else if(arr[mid] < k){
            s = mid+1;
        }
    }
    if(k != -1){
        cout<<"key not found.";
    }
    return 0;
}
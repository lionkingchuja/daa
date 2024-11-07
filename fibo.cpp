#include<bits/stdc++.h>
using namespace std;

int fibo(int n){
    if(n <=0) return 0;
    else if(n==1) return 1;
    else return fibo(n-1)+fibo(n-2);
}
int iter(int n){
    int a=0;
    int b=1;
    int result=0;
    for(int i=2;i<=n;i++){
        result=a+b;
        a=b;
        b=result;
    }
    return b;
}
int main(){
    int x=fibo(5);
    cout<<x<<endl;

    int y=iter(5);
    cout<<y<<endl;
    return 0;
}
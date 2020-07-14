//
//  main.cpp
//  test2
//
//  Created by 홍유진 on 2020/07/14.
//  Copyright © 2020 홍유진. All rights reserved.
//

#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>

using namespace std;

const int NUM=123456;
int arr[250005];
int sosuNum[250005];
//에라토스테네스의 체

void eratos(){
    for(int i=2;i<=2*NUM;i++){
        arr[i]=i;
    }
    for(int i=2;i<=2*NUM;i++){
        if(arr[i]==0) continue;
        for(int j=2*i;j<=2*NUM;j+=i){
            arr[j]=0;
        }
    }
}

void countSosu(){
    for(int i=2;i<=2*NUM;i++){
        if(arr[i]!=0) sosuNum[i]=sosuNum[i-1]+1;
        else{
            sosuNum[i]=sosuNum[i-1];
        }
    }
}
int main(){
    eratos();
    countSosu();
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0) break;
        printf("%d\n",sosuNum[2*n]-sosuNum[n]);
    }
}

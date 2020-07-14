//
//  main.cpp
//  Test
//
//  Created by 홍유진 on 2020/07/04.
//  Copyright © 2020 홍유진. All rights reserved.
//

#include <iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string.h>
#include<string>

int arr[105];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int maxnum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int num=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                num=arr[i]+arr[j]+arr[k];
                if(num>m) continue;
                if(maxnum<num) maxnum=num;
            }
        }
    }
    printf("%d\n",maxnum);
    
}

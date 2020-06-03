#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int arr[105][105];
map<int,int> m;
int main(){
    int r,c,k;
    scanf("%d%d%d",&r,&c,&k);
    int row=3, col=3;
    for(int i=1;i<=3;i++){
      for(int j=1;j<=3;j++){
        scanf("%d",&arr[i][j]);
      }
    }
    int ans=0;
    while(arr[r][c]!=k){
    //  cout<<"row : "<<row<<" col : "<<col<<endl;
      ans++;
      if(ans>100){printf("-1"); return 0;}
      if(row>=col){//row
        int maxcol=0;
        for(int i=1;i<=row;i++){
          for(int j=1;j<=col;j++){
            if(arr[i][j]==0) continue;
            m[arr[i][j]]+=1;
          }
          priority_queue<pair<int, int> >pq;
          for(auto i:m){
            //cout<<i.first<<" "<<i.second<<endl;
            pq.push({-i.second,-i.first});
          }
          int k=1;
          while(!pq.empty()){
            //cout<<-pq.top().second<<" "<<-pq.top().first<<endl;
            if(k%2!=0){
              arr[i][k]=-pq.top().second;
            }else{
              arr[i][k]=-pq.top().first;
              pq.pop();
            }
            k++;
          }
          maxcol=max(maxcol,k-1);
          if(k-1<col){
            for(int j=k;j<=col;j++){
              arr[i][j]=0;
            }
          }
          m.clear();
        }
        col=maxcol;
      }else{//col
        int maxrow=0;
        for(int i=1;i<=col;i++){
          for(int j=1;j<=row;j++){
            if(arr[j][i]==0) continue;
            m[arr[j][i]]+=1;
          }
          priority_queue<pair<int, int> >pq;
          int cnt=0;
          for(auto i:m){
            pq.push({-i.second,-i.first});
          }
          int k=1;
          while(!pq.empty()){
            if(k%2!=0){
              arr[k][i]=-pq.top().second;
            }else{
              arr[k][i]=-pq.top().first;
              pq.pop();
            }
            k++;
          }
          maxrow=max(maxrow,k-1);
          if(k-1<row){
            for(int j=k;j<=row;j++){
              arr[j][i]=0;
            }
          }
          m.clear();
      }
      row=maxrow;
    }
/*    for(int l=1;l<=row;l++){
      for(int o=1;o<=col;o++){
        printf("%d ",arr[l][o]);
      }
      cout<<endl;
    }*/
  }
  printf("%d",ans);
}

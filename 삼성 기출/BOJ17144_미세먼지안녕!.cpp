#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<vector>
using namespace std;
pair<int, int> arr[55][55];
int dr[]={0,0,-1,1};
int dc[]={-1,1,0,0};
int temp[55][55];
vector<pair<int, int >> ac;

void print(int r, int c){
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        printf("%d ",arr[i][j].second);
      }cout<<endl;
    }
    cout<<endl;
}

void print2(int r, int c){
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        printf("%d ",arr[i][j].first);
      }cout<<endl;
    }
    cout<<endl;
}


void airUp(int r, int c){
  int ai=ac[0].first;
  int aj=ac[0].second;
  if(ai==0){
      for(int j=aj;j<c-1;j++){
        temp[ai][j+1]=arr[ai][j].second;
      }
      return;
  }

  for(int j=0;j<c-1;j++){
    if(j+1==aj) continue;
    temp[ai][j+1]=arr[ai][j].second;
  }
  for(int i=ai;i-1>=0;i--){
    temp[i-1][c-1]=arr[i][c-1].second;
  }
  for(int j=c-1;j>=0;j--){
    temp[0][j-1]=arr[0][j].second;
  }
  for(int i=0;i<=ai;i++){
    if(i+1==ai) continue;
    temp[i+1][0]=arr[i][0].second;
  }

}

void airDown(int r, int c){
  int ai=ac[1].first;
  int aj=ac[1].second;
  if(ai==r-1){
    for(int j=aj;j<c-1;j++){
      temp[ai][j+1]=arr[ai][j].second;
    }
    return;
  }
  for(int j=0;j<c-1;j++){
    if(j+1==aj) continue;
    temp[ai][j+1]=arr[ai][j].second;
  }
  for(int i=ai;i+1<r;i++){
    temp[i+1][c-1]=arr[i][c-1].second;
  }
  for(int j=c-1;j>=0;j--){
    temp[r-1][j-1]=arr[r-1][j].second;
  }
  for(int i=r-1;i>=ai;i--){
    if(i-1==ai) {continue;}
    temp[i-1][0]=arr[i][0].second;
  }
}

void paste(int r,int c){
  for(int j=0;j<c;j++){
    arr[0][j].second=temp[0][j];
    arr[r-1][j].second=temp[r-1][j];
    arr[ac[0].first][j].second=temp[ac[0].first][j];
    arr[ac[1].first][j].second=temp[ac[1].first][j];
  }
  for(int i=0;i<r;i++){
    arr[i][0].second=temp[i][0];
    arr[i][c-1].second=temp[i][c-1];
  }
  arr[ac[0].first][ac[0].second].second=0;
  arr[ac[1].first][ac[1].second].second=0;
}

void arrPaste(int r, int c){
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      arr[i][j].first=arr[i][j].second;
      arr[i][j].second=0;
    }
  }
}


int sum(int r, int c){
  int ans=0;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      ans+=arr[i][j].first;
      //cout<<ans<<endl;
    }
  }
  return ans;
}

int main(){
  int r,c,t;
  scanf("%d%d%d",&r,&c,&t);

  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      int tmp;
      scanf("%d",&tmp);
      arr[i][j].first=tmp;
      arr[i][j].second=0;
      if(tmp==-1) ac.push_back({i,j});
    }
  }

  for(int T=0;T<t;T++){
    for(int i=0;i<r;i++){
      for(int j=0;j<c;j++){
        if(arr[i][j].first==-1) continue;
        int dif = arr[i][j].first/5;
        int cnt=0;
        for(int k=0;k<4;k++){
          int nr=i+dr[k];
          int nc=j+dc[k];
          if(nr<0||nc<0||nr>=r||nc>=c) continue;
          if(arr[nr][nc].first==-1) continue;
          cnt++;
          arr[nr][nc].second+=dif;
        }
        arr[i][j].second+=(arr[i][j].first-(dif*cnt));
      }
      arr[ac[0].first][ac[0].second].second=0;
      arr[ac[1].first][ac[1].second].second=0;
    }
    //cout<<endl;
    //print2(r,c);
    //print(r,c);
    //cout<<"after"<<endl;
    airUp(r,c);
    airDown(r,c);
    paste(r,c);
    memset(temp,0,sizeof(temp));
    arrPaste(r,c);
    //print2(r,c);
    //print(r,c);
  }
  printf("%d",sum(r,c));

}

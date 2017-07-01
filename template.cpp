#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
std::vector<int> *v;
std::vector<int> *revv;
int *visited;
int ctr=1;
int dfs(int start){
    visited[start]=1;
  //  std::cout << "dfs with start=" <<start <<'\n';
    for (int i = 0; i < v[start].size() ; i++) {
      if(visited[v[start][i]]==0)
          ctr=1+dfs(v[start][i]);
      /* code */
    }
//    std::cout << "returning ctr with start " <<start<<" "<<ctr<< '\n';
    return ctr;


}
int dfsr(int start){
    visited[start]=1;
//std::cout << "dfs with start=" <<start <<'\n';
    for (int i = 0; i < revv[start].size() ; i++) {
      if(visited[revv[start][i]]==0)
          ctr=1+dfsr(revv[start][i]);
      /* code */
    }
//  std::cout << "returning ctr with start " <<start<<" "<<ctr<< '\n';
    return ctr;


}


int main() {
  ios::sync_with_stdio(false);
  int n;
  std::cin >> n;
  v=new vector<int>[n+1];
  revv=new vector<int>[n+1];
  visited=new int[n+1];
  for (size_t i = 0; i < n+1 ; i++) {
    visited[i]=0;
    /* code */
  }
  for (size_t i = 1; i < n; i++) {
    int x;
    std::cin >> x;
    if(x)
    v[i].push_back(i+1);
    else
      v[i+1].push_back(i);

    /* code */
  }
  for (size_t i = 1; i <= n; i++) {
    for (size_t j = 0; j < v[i].size(); j++) {
      int val=v[i][j];
      revv[val].push_back(i);
      /* code */
    }
    /* code */
  }
  /*for (size_t i = 1; i <=n; i++) {
    for (size_t j = 0; j <revv[i].size(); j++) {
      cout<<revv[i][j]<<" ";

    }
    std::cout  << '\n';

  }*/
  int lookup[n+1]={0},lookupr[n+1]={0};

  //std::cout << "now doing the dfs stuff" << '\n';
  for (size_t i = 1; i <=n; i++) {
        for (size_t j = 0; j <=n; j++) {
          visited[j]=0;
          /* code */
        }
      ctr=1;
      lookup[i]=dfs(i);

    /* code */
  }
  for (size_t i = 1; i <=n; i++) {
      for (size_t j = 0; j <=n; j++) {
        visited[j]=0;
        /* code */
      }
      ctr=1;
    //  std::cout << "looking up for i=" <<i<<'\n';
      lookupr[i]=dfsr(i);
    //  std::cout << "lookupr " <<i<<" "<<lookupr[i] <<'\n';

    /* code */
  }
  int q;
  int door=0;
  std::cin >> q;
/*for (size_t i = 1; i <=n; i++) {
  std::cout << lookup[i] << "and rev as  "<<lookupr[i]<<'\n';

}*/

  while (q--) {
    char ch;  int x;
    std::cin >> ch;
    if(ch=='U'){
      door++;
      continue;
    }
    std::cin >> x;
    if(door%2)
      std::cout << lookupr[x] << '\n';
      else
      std::cout << lookup[x] << '\n';

    /* code */
  }



  return 0;
}

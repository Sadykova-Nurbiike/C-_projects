#include <iostream>

using namespace std;

int main()
{

    const int maxM=100;
    const int maxN=100;
    int N,M;
    int minPoints[maxM];
    int Points[maxM][maxN];
    cin>>N>>M;

    for(int i=0;i<M;i++){
        cin>>minPoints[i];
    }

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
        cin>>Points[i][j];
       }
        }

    // calculation
    int sums[maxN];

    for(int i=0;i<N;i++){
        int sum=0;
        int j=0;
        while( j<M && Points[j][i]>=minPoints[j]){
            sum=sum+Points[j][i];
            j++;
            }
            if(j<M){
                sum=-1;
            }
            sums[i]=sum;
    }

    int Max=0;

    for(int i=1;i<N;i++){
        if(sums[Max]<sums[i]){
            Max=i;
        }
    }

    int cnt=0;
    int winners[maxN];
    if(sums[Max]!=-1){
    for(int i=0;i<N;i++){
        if(sums[i]==sums[Max]){
            winners[cnt]=i;
            cnt++;
        }}}



   cout<<cnt<<endl;
   for(int i=0;i<cnt;i++){
   cout<<winners[i]+1<<" ";
   }
   if (cnt==0){cout << endl;}

    return 0;
}

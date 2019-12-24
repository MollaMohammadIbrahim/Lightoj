#include<bits/stdc++.h>
#define mx 5000007
#define ll unsigned long long int
#define ms(a,b) memset(a,b,sizeof(a))
#define fr(i,a,b) for(ll i =a;i<b;i++)
#define print(test) cout<<"Case "<<test<<": "

void totient();
ll phi[mx+10];
bool mark[mx+10];


using namespace std;
int main(){
    totient();
    int test;
    cin>>test;

    for(int i=1;i<=test;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        

        printf("Case %d: ",i);
        printf("%llu\n",phi[b]-phi[a-1]);

    }
    return 0;
}

void totient(){
    fr(i,0,mx)phi[i]=i;

    ms(mark,true);

    for(ll i=2;i<mx;i++){
        if(mark[i]==true){
            for(ll j=i;j<mx;j+=i){
                mark[j]=false;
                phi[j] = phi[j]/i*(i-1);
            }
        }
    }

    fr(i,1,mx){
        phi[i]*=phi[i];
        phi[i]+=phi[i-1];
    }
}
#include<cstdio>
#define N 6000005
#define J t[u][bit(x,i)]
int q,x,tot;
char a[2];
int s[N],t[N][2];
bool bit(int x,int i){
    return x&1<<i;
}
void add(int x,int k){
    int u=0;
    for(int i=29;~i;--i)
        s[u=J=J?
        J:++tot]+=k;
}
int query(int x){
    int u=0,v=0;
    for(int i=29;~i;--i){
        int j=bit(x,i);
        if(s[t[u][j]]){
            v|=1<<i;
            u=t[u][j];
        }else u=t[u][j^1];
    }
    return v;
}
int main(){
    freopen("multiset.in", "r", stdin);
    freopen("multiset.out", "w", stdout);
    scanf("%d",&q);
    add(0,1);
    while(q--){
        scanf("%s%d",a,&x);
        if(*a=='\?')
            printf("%d\n",
            query(~x));
        else
            add(x,*a^'-'?1:-1);
    }
}
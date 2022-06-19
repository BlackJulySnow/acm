#include <bits/stdc++.h>
using namespace std;
int n,ok,speed,ans,s;
stack<int>q;
int main()
{
    cin >> n;
    int limit=1e9,no_allow=0;//表示一开始无速度限制
    cin >> ok >> speed;//直接读取掉初始速度
    for(int i=1;i<n;i++)
    {
        cin >> ok;
        if(ok==1)
        {
            cin >> s;
            while(!q.empty()&&s>limit)
            {
                q.pop(),ans++;
                if( q.empty() )	limit=1e9;//无视了所有限速牌
                else limit=q.top();
            }
            speed=s;
        }
        else if(ok==2)
        {
            ans+=no_allow,no_allow=0;//无视掉前面的超车
        }
        else if(ok==3)
        {
            cin >> s;
            if(speed>s)	ans++;//当前车速已经很快,直接无视
            else limit=s,q.push(s);//暂时不无视,把限速的放进栈里面
        }
        else if(ok==4)	no_allow=0;//允许超车了
        else if(ok==5)
        {
            limit=1e9;
            while(!q.empty())	q.pop();
        }
        else	no_allow++;//不允许超车牌子数目
    }
    cout<<ans;
}

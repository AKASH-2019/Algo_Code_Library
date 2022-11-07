#include<bits/stdc++.h>
using namespace std;
vector<pair<pair<int,int>,int>>v;
int par[1500];

void path(int x)
{
	if(x==-1) return;
	path(par[x]);
	printf("%d\n",v[x].second);
}
/*void path(int end) {
    if(end > -1) {
        path(par[end]);
        printf("%d\n", v[end].second);
    }
}*/

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int a,b;
	int n=1;
	while(1)
	{
		if(scanf("%d%d",&a,&b)==2)
		{
			v.push_back(make_pair(make_pair(a,b),n));
			n++;
		}  
		else break;
	}
	sort(v.begin(),v.end());
	int l[n+1],mx_length=0,ind;
	par[0]=-1;l[0]=1;
	for(int i=1;i<v.size();i++)
	{
		l[i]=1;
		int vv=-1;
		for(int j=0;j<i;j++)
		{
			if(v[i].first.second<v[j].first.second && v[i].first.first>v[j].first.first && l[i]<l[j]+1)
			{
				l[i]=l[j]+1;
				vv=j;
			}
		}
		par[i]=vv;
		if(l[i]>mx_length)
		{
			mx_length=l[i];
			ind=i;
		}
	}
	cout<<mx_length<<endl;
	path(ind);
	/*while(ind!=-1)
	{
		cout<<v[ind].second<<endl;
		ind=par[ind];
	}*/
	
	return 0;
}

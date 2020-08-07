#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int>a,pair<int,int>b)
{
	return a.second<b.second;
}

int main()
{
    vector< pair <int,int> > vect;
    int n,x,y;
    cin>>n;

    for (int i=0; i<n; i++)
    {
        cin>>x>>y;
        vect.push_back( make_pair(x,y) );
    }
    
    sort(vect.begin(),vect.end(),compare);
    
    for(int i=0;i<n;i++)
    {
		cout<<vect[i].first<<" "<<vect[i].second<<endl;
    }
 

    return 0;
}

/**
 4
 1 10
 2 8
 3 5
 4 1
 */

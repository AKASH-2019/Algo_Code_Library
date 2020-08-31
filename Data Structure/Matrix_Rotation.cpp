/// source -->    https://medium.com/%E0%A6%AA%E0%A7%8D%E0%A6%B0%E0%A7%8B%E0%A6%97%E0%A7%8D%E0%A6%B0%E0%A6%BE%E0%A6%AE%E0%A6%BF%E0%A6%82-%E0%A6%AA%E0%A6%BE%E0%A6%A4%E0%A6%BE/matrix-rotation-9c709740f57e

#include<bits/stdc++.h>
#define ll long long
#define FastRead ios_base::sync_with_stdio(false);cin.tie(NULL);

using namespace std;

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    //setting up the matrix
    int matrix[4][4]={
        1,2,3,4,
        5,6,7,8,
        9,10,11,12,
        13,14,15,16
    };

    //length of the matrix
    int n = 4;

    //traversing through the layers
    for(int layer=0; layer<n/2; layer++)
    {
        int first = layer;
        int last = n-layer-1;
        //cout<<"first :"<<first<<" last :"<<last<<endl;
        //traverse through start to end
        
        for(int i=first; i<last; i++)
        {
            //creating the offset
            int offset = i - first;
            //cout<<"ofset :"<<offset<<endl;

            //storing the top value
            int top = matrix[first][i];

            //store left in top
            matrix[first][i] = matrix[last-offset][first];
            //cout<<first<<" "<<i<<"   "<<last-offset<<" "<<first<<endl;
            
            //store bottom in left
            matrix[last-offset][first] = matrix[last][last-offset];
            //cout<<last-offset<<" "<<first<<"   "<<last<<" "<<last-offset<<endl;
            
            //store right in bottom
            matrix[last][last-offset] = matrix[i][last];
            //cout<<last<<" "<<last-offset<<"    "<<i<<" "<<last<<endl;
            
            //store top in right
            matrix[i][last] = top;
            //cout<<i<<" "<<last<<"   "<<first<<" "<<i<<endl;
        }
    }

    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}

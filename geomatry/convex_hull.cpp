/** source--->  https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain#C++ */
/** source--->  https://www.youtube.com/watch?v=ItyXA784p0Q */

/**
                ................upper and lower hull explanation...........................

https://medium.com/@harshitsikchi/convex-hulls-explained-baab662c4e94
https://en.wikibooks.org/wiki/Algorithm_Implementation/Geometry/Convex_hull/Monotone_chain


*/
/**
        light oj---1203
*/

#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x, y;
    bool operator <(const Point &p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
};


double triangle_area(Point O, Point A, Point B)
{
    return O.x*(A.y-B.y) + A.x*(B.y-O.y) + B.x*(O.y-A.y);  ///triangle area check (if neg. than create angle more than 180 )

}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.

//vector<Point> convex_hull(vector<Point> P)
void convex_hull(vector<Point> P)
{
    int n = P.size(), k = 0;
    //if (n <= 3) return P;
    vector<Point> H(2*n);

    sort(P.begin(), P.end());


    // Build lower hull
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && triangle_area(H[k-2], H[k-1], P[i]) <= 0) k--;
        H[k++] = P[i];
    }

    // Build upper hull
    for (int i = n-1, t = k+1; i > 0; --i)
    {
        while (k >= t && triangle_area(H[k-2], H[k-1], P[i-1]) <= 0) k--;
        H[k++] = P[i-1];
    }

    H.resize(k-1);
    //return H;
    cout<<"output..."<<endl;
    for(int i=0; i<H.size(); i++)
        cout<<H[i].x<<" "<<H[i].y<<endl;
}

int main()
{
    int np,nc;
    cout<<"enter the number of point"<<endl;
    cin>>np;

    Point get;
    vector<Point>e;
    int x,y;

    for(int i=0; i<np; i++)
    {
        cin>>x>>y;
        get.x=x;
        get.y=y;
        e.push_back(get);
    }

    convex_hull(e);

    return 0;
}

/**
1 1
2 2
1 0
0 10
10 10
3 3

*/

/**

28

0 0
0 1
0 2
0 3
1 0
1 1
1 2
1 3
2 0
2 1
2 2
2 3
2 4
2 5
2 6
2 7
2 8
2 9
3 0
3 1
3 2
3 3
4 0
4 1
4 2
4 3
4 4
5 1

 When run on the above collection of points the output will be
   [[0 0] [0 3] [2 9] [4 4] [5 1] [4 0]]

*/

/***  ............................USING VECTOR...................................*/


/**typedef pair<double,double>point;
vector<point>e;

/**  TRIANGLE AREA

          (a.x(b.y-c.y)+b.x(c.y-a.y)+c.x(a.y-b.y))/2
    */

/**double triangle_area(point O,point A,point B)
{
    return O.first*(A.second-B.second) + A.first*(B.second-O.second) + B.first*(O.second-A.second);

}

void convex()
{
    int n=e.size(),k=0;
    vector<point>h(2*n);
    sort(e.begin(),e.end());

    for(int i=0;i<n;i++)
    {
        while(k>=2 && triangle_area(h[k-2],h[k-1],e[i])<=0)
            k--;
        h[k++]=e[i];
    }
    for(int i=n-1,t=k+1 ;i>0; i--)
    {
        while(k>=t && triangle_area(h[k-2],h[k-1],e[i-1])<=0)
            k--;

        h[k++]=e[i-1];
    }
    h.resize(k-1);
    cout<<"output..."<<endl;
    for(int i=0; i<h.size(); i++)
        cout<<h[i].first<<" "<<h[i].second<<endl;
}

int main()
{
    int np,nc;
    cout<<"enter the number of point ";
    cin>>np;

    for(int i=0;i<np;i++)
    {
        double x,y;
        cin>>x>>y;
        e.push_back(make_pair(x,y));
    }
    convex();

    return 0;
}*/


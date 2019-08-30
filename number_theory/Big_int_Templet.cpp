/**

source->http://lightoj.com/article_show.php?article=1004&language=english&type=pdf&fbclid=IwAR3y64C6bHLDFrJWDZOoqVdwHhv8MXkXMe24bJZDzGdfOAEfVZ9GlmVFlbA
*/
///jan lightoj(code)

#include<bits/stdc++.h>
using namespace std;

struct Bigint
{
    string a;
    int sign;

    Bigint() {};
    Bigint(string b)
    {
        (*this)=b;
    }

    int size()
    {
        return a.size();
    }

    Bigint inverseSign() //change sign
    {
        sign*=-1;
        return (*this);
    }
    Bigint normalize(int newSign)//remove leading 0,fixes sign
    {
        for(int i=a.size()-1; i>0 && a[i]=='0'; i--)
            a.erase(a.begin()+1);
        sign= (a.size()==1 && a[0]=='0') ? 1 : newSign;
        return(*this);
    }
    //assignment operator
    void operator = (string b)// assigns a string to bigint
    {
        a= b[0]=='-'? b.substr(1) : b;
        reverse(a.begin(),a.end());
        this->normalize(b[0]=='-' ? -1: 1);
    }
    //conditional operators
    bool operator < (const Bigint &b) const
    {
        if(sign!=b.sign) return sign<b.sign;
        if(a.size()!=b.a.size())
            return sign==1 ? a.size() < b.a.size() : a.size()>b.a.size();
        for(int i=a.size()-1; i>=0; i--) if(a[i]!=b.a[i])
                return sign==1 ? a[i]<b.a[i] : a[i]>b.a[i];
        return false;
    }
    bool operator == (const Bigint &b)const //ope. for equality
    {
        return a==b.a && sign==b.sign;
    }
    Bigint operator + (Bigint b) //addition op overloading
    {
        if(sign != b.sign) return (*this)-b.inverseSign();
        Bigint c;
        for(int i=0,carry=0; i<a.size()||i<b.size()||carry; i++)
        {
            carry+=(i<a.size() ? a[i]-48:0)+(i<b.a.size()?b.a[i]-48:0);
            c.a+=(carry%10+48);
            carry/=10;
        }
        return c.normalize(sign);
    }
    Bigint operator - ( Bigint b )   // subtraction operator overloading
    {
        if( sign != b.sign ) return (*this) + b.inverseSign();
        int s = sign;
        sign = b.sign = 1;
        if( (*this) < b ) return ((b - (*this)).inverseSign()).normalize(-s);
        Bigint c;
        for( int i = 0, borrow = 0; i < a.size(); i++ )
        {
            borrow = a[i] - borrow - (i < b.size() ? b.a[i] : 48);
            c.a += borrow >= 0 ? borrow + 48 : borrow + 58;
            borrow = borrow >= 0 ? 0 : 1;
        }
        return c.normalize(s);
    }
    Bigint operator * ( Bigint b )   // multiplication operator overloading
    {
        Bigint c("0");
        for( int i = 0, k = a[i] - 48; i < a.size(); i++, k = a[i] - 48 )
        {
            while(k--) c = c + b; // ith digit is k, so, we add k times
            b.a.insert(b.a.begin(), '0'); // multiplied by 10
        }
        return c.normalize(sign * b.sign);
    }

    Bigint operator / ( Bigint b )   // division operator overloading
    {
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0"), d;
        for( int j = 0; j < a.size(); j++ ) d.a += "0";
        int dSign = sign * b.sign;
        b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- )
        {
            c.a.insert( c.a.begin(), '0');
            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b, d.a[i]++;
        }
        return d.normalize(dSign);
    }

    Bigint operator % ( Bigint b )   // modulo operator overloading
    {
        if( b.size() == 1 && b.a[0] == '0' ) b.a[0] /= ( b.a[0] - 48 );
        Bigint c("0");
        b.sign = 1;
        for( int i = a.size() - 1; i >= 0; i-- )
        {
            c.a.insert( c.a.begin(), '0');
            c = c + a.substr( i, 1 );
            while( !( c < b ) ) c = c - b;
        }
        return c.normalize(sign);
    }
    void print()
    {
        if( sign == -1 ) putchar('-');
        //reverse( a.begin(), a.end() );
        //cout << a << endl;
        //reverse( a.begin(), a.end() );
        for( int i = a.size() - 1; i >= 0; i-- ) putchar(a[i]);
        puts("");
    }

};

int main()
{
    Bigint a, b, c; // declared some Bigint variables
    string input;

    cin >> input;
    a = input;
    cin >> input;
    b = input;

    c=a+b;
    //cout<<c<<endl;
    c.print();
    cout<<endl;

    c=a-b;
    //cout<<c<<endl;
    c.print();
    cout<<endl;

    c=a*b;
    //cout<<c<<endl;
    c.print();
    cout<<endl;

    c=a/b;
    //cout<<c<<endl;
    c.print()+1;
    cout<<endl;

    c=a%b;
    //cout<<c<<endl;
    c.print();
    cout<<endl;


    if( a == b ) puts("equal");
    else puts("not equal");

    if( a < b ) puts("a is smaller than b");
}

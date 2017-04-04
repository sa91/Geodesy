//Kyokai no Kanata //
#ifndef DISTANCE_HPP
#define  DISTANCE_HPP
#include<bits/stdc++.h>
//#include<cmath>
//#include<iostream>
template <typename type >

// It is my template . I will remove it after testing //
typedef pair<int,int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector< VI > VVI;
typedef long long int LL;

#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define ALL(a) a.begin(),a.end()
#define SET(a,b) memset(a,b,sizeof(a))

#define si(n) scanf("%d",&n)
#define dout(n) printf("%d\n",n)
#define sll(n) scanf("%lld",&n)
#define lldout(n) printf("%lld\n",n)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr<<name<<" : "<<arg1<<endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
  const char* comma=strchr(names+1,',');
  cerr.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}
#else
#define trace(...)
#endif
namespace Geometry
{
  class Point{
    public:
      type lattitude,longitude;
      Point(type lat,type lon):lattitude(lat*M_PI/180.0),longitude(lon*M_PI/180.0){};
  }
  temp BasicDistance(const Point &X,const Point &Y,temp Radius=1)
  {
    //abs always returns double (if not used with int).
    double  Dlong = std::abs(X.longitude - Y.longitude);
    //Source of formula :: Wikipedia
    double num = std::sqrt(std::pow((std::cos(Y.latitude)*std::sin(Dlong)),2) + std::pow((std::cos(X.latitude)*std::sin(Y.latitude)-std::sin(X.latitude)*std::cos(Y.latitude)*std::cos(Dlond)),2));
    double denom = std::sin(X.latitude)*std::sin(Y.latitude) + std::cos(X.latitude)*std::cos(Y.latitude)*std::cos(Dlong);
    double sigma = atan2(denom,num);
    return (sigma*radius)   //bydefault radius is 1.
  }
  // under construction :P
  temp Distance(const Point&X, const Point &Y,temp Radius,double major,double minor)
  {
    double f = (major - minor)/major;
    double  Dlong = Y.longitude - X.longitude,PDlong = -2*M_PI;
    const double eps=(1e-9);
    while(abs(Dlong-PDlong)<eps)
    {
      Point XX = new Point(atan2(std::cos(X.latitude),(1-f)*std::sin(X.latitude)),X.longitude);
      Point YY = new Point(atan2(std::cos(Y.latitude),(1-f)*std::sin(Y.latitude)),X.longitude + Dlong);
      double sigma = BasicDistance(XX,YY);
      double alpha = std::asin(std::cos(XX.latitude)*std::cos(YY.latitude)*std::sin(Dlong)/std::sin(sigma));


    }

    while()
  }
    
}

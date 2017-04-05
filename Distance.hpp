//Kyokai no Kanata //
#ifndef DISTANCE_HPP
#define  DISTANCE_HPP
#include<bits/stdc++.h>
//#include<cmath>
//#include<iostream>
using namespace std;
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
      double latitude,longitude;
      Point(double lat,double lon):latitude(lat*M_PI/180.0),longitude(lon*M_PI/180.0){};
  };
  double squarev(double x) 
  {
    return x*x;
  }
  double BasicDistance(const Point &X,const Point &Y,double radius=1)
  {
    //abs always returns double (if not used with int).
    double  Dlong = std::abs(X.longitude - Y.longitude);
    //Source of formula :: Wikipedia
    double num = std::sqrt(squarev(std::cos(Y.latitude)*std::sin(Dlong)) + squarev((std::cos(X.latitude)*std::sin(Y.latitude)-std::sin(X.latitude)*std::cos(Y.latitude)*std::cos(Dlong))));
    double denom = std::sin(X.latitude)*std::sin(Y.latitude) + std::cos(X.latitude)*std::cos(Y.latitude)*std::cos(Dlong);
    double sigma = atan2(denom,num);
    return (sigma*radius);   //bydefault radius is 1.
  }
  // under construction :P
  double Distance(const Point&X, const Point &Y,double Radius,double major,double minor)
  {
    double f = (major - minor)/major;
    double  Dlong = Y.longitude - X.longitude,PDlong = -2*M_PI;
    const double eps=(1e-9);
    double sigma,sigmam,alpha;
    while(abs(Dlong-PDlong)<eps)
    {
      Point XX(atan2(std::cos(X.latitude),(1-f)*std::sin(X.latitude)),X.longitude);
      Point YY(atan2(std::cos(Y.latitude),(1-f)*std::sin(Y.latitude)),X.longitude + Dlong);
      sigma = BasicDistance(XX,YY);
      alpha = std::asin(std::cos(XX.latitude)*std::cos(YY.latitude)*std::sin(Dlong)/std::sin(sigma));
      sigmam = 0.5*std::acos(std::cos(sigma)-(2*std::sin(XX.latitude)*std::sin(XX.latitude)/squarev(std::cos(alpha)))); 
      double C = (f/16)*squarev(std::cos(alpha))*(4+(f*(4-3*squarev(std::cos(alpha)))));
      PDlong = Dlong;
      Dlong -=(1-C)*f*std::sin(alpha)*(sigma+(C*std::sin(sigma)*(std::cos(2*sigmam)-(C*std::cos(sigma)*std::cos(4*sigmam)))));
    }
    double u2 = squarev(std::cos(alpha))*(squarev(major)-squarev(minor))/squarev(major);
    double A = 1 + (u2/16384)*(4096 + u2*(-768 + u2*(320-(175*u2))));
    double B = (u2/1024)*(256 + u2*(-128+ u2*(74-(47*u2))));
    double delsigma = B*(std::sin(sigma))*(std::cos(2*sigmam)+((-0.25*B*(std::cos(sigma)*std::cos(4*sigmam)))- ((1/6)*B*std::cos(2*sigmam)*(-3 + 4*squarev(std::sin(sigma)))*(-3+ 4*squarev(std::cos(2*sigmam))))));
    return minor*A*(sigma-delsigma);
  }    
}
#endif

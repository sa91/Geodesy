//Kyokai no Kanata//
#include<cmath>
#include<iostream>
#include "distance.hpp"
namespace Geometry
{
  double squarev(double x) {
    return x*x;
  }
  double BasicDistance(const Point &X,const Point &Y,double radius=1.0)
  {
    double  Dlong = std::abs(X.longitude - Y.longitude);
    //Source of formula :: Wikipedia
    double num = std::sqrt(squarev(std::cos(Y.latitude)*std::sin(Dlong)) + squarev((std::cos(X.latitude)*std::sin(Y.latitude)-std::sin(X.latitude)*std::cos(Y.latitude)*std::cos(Dlong))));
    double denom = std::sin(X.latitude)*std::sin(Y.latitude) + std::cos(X.latitude)*std::cos(Y.latitude)*std::cos(Dlong);
    double sigma = atan2(denom,num);
    //bydefault radius is 1.
    return (sigma*radius);   
  }
 
  double Distance(const Point&X, const Point &Y,double Radius,double major,double minor)
  {
    double f = (major - minor)/major;
    double  Dlong = Y.longitude - X.longitude,PDlong = -2*M_PI;
    const double eps=(1e-9);
    double sigma,sigmam,alpha;
    while(std::abs(Dlong-PDlong)<eps)
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

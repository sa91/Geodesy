//Kyokai no Kanata //
#ifndef DISTANCE_HPP
#define  DISTANCE_HPP
#include<cmath>
#include<iostream>
namespace Geometry
{
  class Point{
    public:
      double latitude,longitude;
      Point(double lat,double lon):latitude(lat*M_PI/180.0),longitude(lon*M_PI/180.0){};
  };
  double squarev(double x);
  double BasicDistance(const Point &X,const Point &Y,double radius);
  double Distance(const Point&X, const Point &Y,double Radius,double major,double minor);
}
#endif

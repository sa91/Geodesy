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
      Point(double lat,double lon):latitude(lat*M_PI/180.0),longitude(lon*M_PI/180.0){
        while(longitude<0) longitude+=M_PI;
        while(latitude<0) latitude+=M_PI;
        while(longitude>M_PI) longitude-=M_PI;
        while(latitude>M_PI) latitude-=M_PI;
      };
  };
  double squarev(double x);
  double BasicDistance(const Point &X,const Point &Y,double radius);
  double Distance(const Point&X, const Point &Y,double major,double minor);
}
#endif

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
        longitude -=(longitude/std::abs(longitude))*std::floor(longitude/(2*M_PI))*2*M_PI;
        latitude -=(latitude/std::abs(latitude))*std::floor(latitude/(2*M_PI))*2*M_PI;
        if(latitude<0) latitude=-latitude; if(latitude>M_PI) latitude= 2*M_PI - latitude;
        if(longitude<0) longitude=-longitude; if(longitude>M_PI) longitude= 2*M_PI - longitude;
      };
  };
  double squarev(double x);
  double BasicDistance(const Point &X,const Point &Y,double radius);
  double Distance(Point X, Point Y,double major,double minor);
}
#endif

#ifndef __CORE__H__
#define __CORE__H__

#include "../Types/types.h"

struct PointComparator {
  bool operator() (const Point_2& a, const Point_2& b) const {
    if(a.y() == b.y()){
      return a.x() > b.x();
    }else{
      return b.y() > a.y();
    }
  }
};

namespace Core {
  enum PointType {
    SPLIT,
    MERGE,
    START,
    END,
    REGULAR
  };

  bool isLineInsidePolygon( const Segment_2& segment , const Polygon_2& polygon );
  template< class Point >
  std::pair< Point , Core::PointType > classifySingleVertex( const Point prev , const Point curr , const Point next );
  template< class VertexIt , class MapInserter >
  void classifyVertices( const VertexIt start , const VertexIt end , MapInserter inserter );
  template< class BackInserter >
  void getYMonotonePolygons( const Polygon& polygon ,  BackInserter inserter );
  template< class BackInserter >
  void triangulateMonotone( const Polygon_2& , BackInserter inserter );
} /* Core */

#include "Core.cxx"

#endif

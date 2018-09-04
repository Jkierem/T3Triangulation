bool Core::isLineInsidePolygon( const Segment_2& segment , const Polygon_2& polygon ){
  SegmentVector segs;
  EdgeIter curr_edge = polygon.edges_begin();
  EdgeIter end_edge  = polygon.edges_end();
  for( ; curr_edge != end_edge ; curr_edge++ ){
    segs.push_back( *curr_edge );
  }
  segs.push_back( segment );

  PointList inter, realInter, midpoints;
  CGAL::compute_intersection_points( segs.begin() , segs.end() , std::back_inserter(inter) );
  int numberOfInters = inter.size();
  if( numberOfInters == 0 ){
    CGAL::Bounded_side pos = CGAL::bounded_side_2( polygon.vertices_begin() , polygon.vertices_end() , CGAL::midpoint( segment.source() , segment.target() ));
    if( pos == CGAL::ON_UNBOUNDED_SIDE ){
      return false;
    }
    return true;
  }else{
    inter.push_front( segment.source() );
    inter.push_back( segment.target() );

    PointListIter curr_point = inter.begin();
    PointListIter next_point = curr_point; next_point++;
    PointListIter end_point  = inter.end();
    for( ; next_point != end_point ; curr_point++, next_point++ ){
      midpoints.push_back( CGAL::midpoint( *curr_point , *next_point ) );
    }

    bool areAllInside = true;
    curr_point = midpoints.begin();
    end_point  = midpoints.end();
    for( ; curr_point != end_point && areAllInside ; curr_point++ ) {
      CGAL::Bounded_side position = CGAL::bounded_side_2( polygon.vertices_begin() , polygon.vertices_end() , *curr_point);
      if( position == CGAL::ON_UNBOUNDED_SIDE ){
        areAllInside = false;
      }
    }

    return areAllInside;
  }
}

template< class Point >
std::pair< Point , Core::PointType > Core::classifySingleVertex( const Point prev_point , const Point curr_point , const Point next_point ){
  if ( prev_point.y() <= curr_point.y() && next_point.y() <= curr_point.y() ) {
    if( prev_point.x() >= curr_point.x() ){
      return std::make_pair(curr_point,Core::START);
    }else{
      return std::make_pair(curr_point,Core::SPLIT);
    }
  }else if( prev_point.y() >= curr_point.y() && next_point.y() >= curr_point.y() ){
    if( prev_point.x() > curr_point.x() ){
      return std::make_pair(curr_point,Core::MERGE);
    }else{
      return std::make_pair(curr_point,Core::END);
    }
  }else{
    return std::make_pair(curr_point,Core::REGULAR);
  }
}

template< class VertexIt , class MapInserter>
void Core::classifyVertices( const VertexIt start , const VertexIt end , MapInserter inserter ){
  VertexIt prev = start;
  VertexIt curr = prev; curr++;
  VertexIt next = curr; next++;
  for ( ; next != end ; prev++, curr++, next++ ) {
    inserter = classifySingleVertex( *prev , *curr , *next );
  }
  inserter = classifySingleVertex( *prev , *curr , *start );
  prev = curr;
  curr = start;
  next = curr; next++;
  inserter = classifySingleVertex( *prev , *curr , *next );
}

template< class BackInserter >
void getYMonotonePolygons( const Polygon& polygon ,  BackInserter inserter ){
  std::map<Segment_2, Point_2> helpers;
  std::map<Point_2, Core::PointType> types;
  Core::classifyVertices(
    polygon.vertices_begin() ,
    polygon.vertices_end() ,
    std::inserter( types , types.end() )
  );
  std::set< Point_2 , PointComparator > sweep_line;
  sweep.assign( polygon.container().begin() , polygon.container().end() );

  typedef std::set< Point_2 , PointComparator >::iterator SetIter;
  SetIter curr_event = sweep_line.begin();
  SetIter end_event  = sweep_line.end();
}

template< class BackInserter>
void Core::triangulateMonotone( const Polygon& polygon , BackInserter inserter ){

}

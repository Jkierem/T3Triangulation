#ifndef __TYPES__HXX__
#define __TYPES__HXX__

#include <CGAL/Simple_cartesian.h>
#include <CGAL/Surface_sweep_2_algorithms.h>
#include <CGAL/squared_distance_2.h>
#include <CGAL/Polygon_2.h>
#include <CGAL/enum.h>

#include <utility>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <map>

typedef CGAL::Simple_cartesian<float> Kernel;
typedef CGAL::Polygon_2<Kernel> Polygon_2;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Segment_2 Segment_2;

typedef std::vector<Segment_2> SegmentVector;
typedef std::vector<Point_2> PointVector;
typedef std::list<Point_2> PointList;
typedef std::set<Point_2> PointSet;

typedef PointVector::const_iterator PointVectorIter;
typedef PointList::const_iterator PointListIter;
typedef Polygon_2::Edge_const_iterator EdgeIter;
typedef Polygon_2::Vertex_const_iterator VertexIter;

#endif

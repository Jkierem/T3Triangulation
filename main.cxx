#include <iostream>
#include <string>
#include "./src/Core/Core.hxx"

template< class NameType , class T >
void my_assert( NameType test , T value , T expected ){
  std::string result = value == expected ? "passed" : "not passed";
  std::cout << "-  Test name " << test <<": Expected " << expected << ", Received " << value <<" ->  " << result << std::endl;
}

void lineInsidePolygonTests(Polygon_2 poly){
  std::cout << "isLineInsidePolygon:" << std::endl;
  my_assert(1,Core::isLineInsidePolygon(Segment_2(Point_2(1,1),Point_2(7,4)), poly),true);
  my_assert(2,Core::isLineInsidePolygon(Segment_2(Point_2(1,4),Point_2(9,7)), poly),false);
  my_assert(3,Core::isLineInsidePolygon(Segment_2(Point_2(2,7),Point_2(6,7)), poly),false);
  my_assert(4,Core::isLineInsidePolygon(Segment_2(Point_2(4,4),Point_2(9,7)), poly),false);
  my_assert(5,Core::isLineInsidePolygon(Segment_2(Point_2(2,6),Point_2(7,4)), poly),false);
  my_assert(6,Core::isLineInsidePolygon(Segment_2(Point_2(1,4),Point_2(7,4)), poly),true);
}

std::string typeToString( Core::PointType t ){
  switch (t) {
    case Core::START :
      return "START";
    case Core::END :
      return "END";
    case Core::MERGE :
      return "MERGE";
    case Core::SPLIT :
      return "SPLIT";
    case Core::REGULAR :
      return "REGULAR";
  }
}

void classifyVerticesTest(Polygon_2 poly , std::map<Point_2, Core::PointType> expected){
  std::cout << "classifyVertices:" << std::endl;
  std::map<Point_2, Core::PointType> types;
  Core::classifyVertices( poly.vertices_begin() , poly.vertices_end() , std::inserter(types, types.end()) );
  for( Point_2 p : poly.container() ){
    my_assert( p , typeToString(types.at(p)) , typeToString(expected.at(p)) );
  }
}

int main(int argc , char* argv[]){
  Point_2 points[] = {
    Point_2(1,1),
    Point_2(9,1),
    Point_2(9,7),
    Point_2(7,4),
    Point_2(6,7),
    Point_2(4,4),
    Point_2(2,7),
    Point_2(2,6),
    Point_2(1,4)
  };
  Polygon_2 poly(points , points+9);
  std::map<Point_2, Core::PointType> expected;
  expected.emplace( Point_2(1,1) , Core::END );
  expected.emplace( Point_2(9,1) , Core::END );
  expected.emplace( Point_2(9,7) , Core::START );
  expected.emplace( Point_2(7,4) , Core::MERGE );
  expected.emplace( Point_2(6,7) , Core::START );
  expected.emplace( Point_2(4,4) , Core::MERGE );
  expected.emplace( Point_2(2,7) , Core::START );
  expected.emplace( Point_2(2,6) , Core::REGULAR );
  expected.emplace( Point_2(1,4) , Core::REGULAR );

	return 0;
}

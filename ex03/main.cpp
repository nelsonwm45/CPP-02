#include "Fixed.hpp"
#include "Point.hpp"

static void print_test(std::string name, bool results)
{
	std::cout << BLUE << name << ": " << RESET;
	if (results == true)
		std::cout << GREEN << "The point is INSIDE triangle" << RESET << std::endl;
	else
		std::cout << RED << "The point is OUTSIDE triangle" << RESET << std::endl;
}

/*
	didn't handle much precision test, as float conversion will cause precision loss
	if points at edge/ near edge consider outside of triangle
	super large triangle also cannot, as i'm storing number using int
*/
int main(void)
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);
	Point inside(2, 2);
	Point outside(20, 20);
	Point on_edge(5, 0);
	Point on_vertex(0, 0);

	print_test("normal inside", bsp(a, b, c, inside)); // inside
	print_test("normal outside", bsp(a, b, c, outside)); // outside
	print_test("on_edge", bsp(a, b, c, on_edge)); // outside
	print_test("on_vertex", bsp(a, b, c, on_vertex)); // outside

	// Collinear points (Degenerate Triangle): Outside
	Point d(0, 0);
	Point e(5, 5);
	Point f(10, 10);
	Point point(2, 2);
	print_test("Degenerate Triangle", bsp(d, e, f, point));

	// Point Near the edge (Precision test): Inside
	Point j(0, 0);
	Point k(10, 0);
	Point l(0, 10);
	Point near_edge(5, 0.01);
	print_test("Point Near Edge", bsp(j, k, l, near_edge));

	// Negative Coordinates : Inside
	Point m(-10, -10);
	Point n(-20, -10);
	Point o(-15, -20);
	Point inside_2(-15, -15);
	print_test("Negative Coordinates", bsp(m, n, o, inside_2));

	// Point exactly at center : Inside
	Point p(0, 0);
	Point q(6, 0);
	Point r(3, 6);
	Point centroid(3, 2); // Centroid of the triangle
	print_test("Point at center", bsp(p, q, r, centroid));

	// Floating-Point Precision Test : Inside
	Point s(0.1f, 0.1f);
	Point t(10.1f, 0.1f);
	Point u(0.1f, 10.1f);
	Point inside_3(3.0f, 3.0f);
	print_test("Floating Point Preicion Test", bsp(s, t, u, inside_3));

	return 0;
}

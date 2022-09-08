#include "vector2d.h"
#include <stdio.h>
void display_vector(const vec2d v) {
	printf("(%.2f, %.2f)", v.x, v.y);
}

double magnitude(const vec2d v) {
	return (v.x * v.x) + (v.y * v.y);
}

vec2d add(const vec2d v1, const vec2d v2) {
	vec2d v3;
	v3.x = (v1.x + v2.x);
	v3.y = (v1.y + v2.y);
	return v3;
}

vec2d scale(const vec2d v, const double factor) {
	vec2d v2;
	v2.x = v.x * factor;
	v2.y = v.y * factor;
	return v2;
}

double dot_product(const vec2d v1, const vec2d v2) {
	return (v1.x * v2.x) + (v1.y * v2.y);
}

#pragma once

struct vector3d {
	double x;
	double y;
	double z;
};

struct point3d {
	double x;
	double y;
	double z;
};

double scalar_vector_adds(vector3d a, vector3d b);
point3d vector_point(vector3d a, point3d e);
vector3d vector_sum(vector3d a, vector3d b);
vector3d vector_dif(vector3d a, vector3d b);
vector3d vector_add_const(vector3d a, double constanta);
vector3d vector_dev_const(vector3d a, double constanta);
vector3d vector_adds_vector(vector3d a, vector3d b);
vector3d two_point_vector(point3d d, point3d e);
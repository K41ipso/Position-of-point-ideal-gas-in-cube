#pragma once
#include "func.h"

class inters_help {
public:
	double time;
	int c_side;
	char f;
	char s;
	char t;
};

double reload_time(double T, double time);
double repair_time(double T, double time);
bool point_not_in_cube(point3d A, double T);
bool have_next_pointB(double time_now, double T);
point3d last_point_in_cube(point3d A, vector3d V, double T);
point3d next_point(double time, point3d A, vector3d V);
vector3d normals_sum(char inters_resC);
vector3d next_vector(vector3d V, inters_help inters_result);
inters_help check_min_time(point3d A, vector3d V);
inters_help fill_cells_the_side(inters_help inters_prom, bool equals, char symbol);
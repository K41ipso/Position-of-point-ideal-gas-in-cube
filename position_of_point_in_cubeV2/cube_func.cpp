#include "cube_func.h"
#include "func.h"
#include <string>
#include <iostream>

using namespace std;

double reload_time(double T, double time) {
	T = T - time;
	return T;
}
double repair_time(double T, double time) {
	T = time + T;
	return T;
}
bool point_not_in_cube(point3d A, double T) {
	if ((A.x > 1) || (A.y > 1) || (A.z > 1) || (A.x < 0) || (A.y < 0) || (A.z < 0) || (T <= 0))
		return true;
	return false;
}
bool have_next_pointB(double time_now, double T) {
	if (time_now <= T)
		return true;
	return false;
}
point3d last_point_in_cube(point3d A, vector3d V, double T) {
	inters_help result_check;
	double last_T = 0.0;
	while (T >= 0.0) {
		result_check = check_min_time(A, V);
		T = reload_time(T, result_check.time);
		if (T >= 0) {
			A = next_point(result_check.time, A, V);
			V = next_vector(V, result_check);
		}
		else {
			last_T = repair_time(T, result_check.time);
			A = next_point(last_T, A, V);
		}
		//cout << "\n (" << A.x << ", " << A.y << ", " << A.z << ") (" << V.x << ", " << V.y << ", " << V.z << ") time now:" << T << " last_T: " << last_T << " min_time: " << result_check.time << endl;
	}
	return A;
}
point3d next_point(double time, point3d A, vector3d V) {
	point3d result;
	result.x = A.x + time * V.x;
	result.y = A.y + time * V.y;
	result.z = A.z + time * V.z;
	return result;
}
vector3d normals_sum(char inters_resC) {
	vector3d result;
	switch (inters_resC)
	{
	case 'A':
		result.x = 0;
		result.y = 0;
		result.z = 1;
		break;
	case 'B':
		result.x = -1;
		result.y = 0;
		result.z = 0;
		break;
	case 'C':
		result.x = 0;
		result.y = 0;
		result.z = -1;
		break;
	case 'D':
		result.x = 1;
		result.y = 0;
		result.z = 0;
		break;
	case 'E':
		result.x = 0;
		result.y = -1;
		result.z = 0;
		break;
	case 'F':
		result.x = 0;
		result.y = 1;
		result.z = 0;
		break;
	default:
		result.x = 0;
		result.y = 0;
		result.z = 0;
	}
	return result;
}
vector3d next_vector(vector3d V, inters_help inters_result) {
	vector3d result;
	vector3d normal = vector_sum(vector_sum(normals_sum(inters_result.f), normals_sum(inters_result.s)), normals_sum(inters_result.t));
	vector3d normalized_n = vector_dev_const(normal, sqrt(normal.x * normal.x + normal.y * normal.y + normal.z * normal.z));
	//vector3d normalized_V = vector_dev_const(V, sqrt(V.x * V.x + V.y * V.y + V.z * V.z));
	result = vector_dif(V, vector_add_const(normalized_n, (2.0 * scalar_vector_adds(V, normalized_n))));
	return result;
}
inters_help check_min_time(point3d A, vector3d V) {
	inters_help result;
	result.f = 'n';
	result.s = 'n';
	result.t = 'n';
	result.time = 1;
	result.c_side = 0;
	bool equals = false;
	if (V.x != 0.0 && ((-(A.x) / V.x) > 0)) {
		result.time = (-(A.x) / V.x);
		result = fill_cells_the_side(result, false, 'D');
	}
	if (V.y != 0.0 && ((-(A.y) / V.y) > 0) && ((-(A.y) / V.y) <= result.time)) {
		result.time = (-(A.y) / V.y);
		if ((-(A.y) / V.y) == result.time) {
			equals = true;
		}
		result = fill_cells_the_side(result, equals, 'F');
	}
	if (V.z != 0.0 && ((-(A.z) / V.z) > 0) && ((-(A.z) / V.z) <= result.time)) {
		result.time = (-(A.z) / V.z);
		if ((-(A.z) / V.z) < result.time) {
			equals = false;
		}
		else {
			equals = true;
		}
		result = fill_cells_the_side(result, equals, 'A');
	}
	if (V.x != 0.0 && (((-(A.x) + 1) / V.x) > 0) && (((-(A.x) + 1) / V.x) <= result.time)) {
		result.time = ((-(A.x) + 1) / V.x);
		if (((-(A.x) + 1) / V.x) < result.time) {
			equals = false;
		}
		else {
			equals = true;
		}
		result = fill_cells_the_side(result, equals, 'B');
	}
	if (V.y != 0.0 && (((-(A.y) + 1) / V.y) > 0) && (((-(A.y) + 1) / V.y) <= result.time)) {
		result.time = ((-(A.y) + 1) / V.y);
		if (((-(A.y) + 1) / V.y) < result.time) {
			equals = false;
		}
		else {
			equals = true;
		}
		result = fill_cells_the_side(result, equals, 'E');
	}
	if (V.z != 0.0 && (((-(A.z) + 1) / V.z) > 0) && (((-(A.z) + 1) / V.z) <= result.time)) {
		result.time = ((-(A.z) + 1) / V.z);
		if (((-(A.z) + 1) / V.z) < result.time) {
			equals = false;
		}
		else {
			equals = true;
		}
		result = fill_cells_the_side(result, equals, 'C');
	}
	return result;
}
inters_help fill_cells_the_side(inters_help inters_prom, bool equals, char symbol) {
	if (equals) {
		if (inters_prom.f == 'n') {
			inters_prom.f = symbol;
		}
		else {
			if (inters_prom.s == 'n') {
				inters_prom.s = symbol;
			}
			else {
				inters_prom.t = symbol;
			}
		}
	}
	else {
		inters_prom.f = symbol;
		inters_prom.s = 'n';
		inters_prom.t = 'n';
	}
	inters_prom.c_side++;
	return inters_prom;
}
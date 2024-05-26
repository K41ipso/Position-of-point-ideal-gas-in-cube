#include "func.h"

vector3d vector_sum(vector3d a, vector3d b) {
    vector3d result;
    result.x = a.x + b.x;
    result.y = a.y + b.y;
    result.z = a.z + b.z;
    return result;
}
vector3d vector_dif(vector3d a, vector3d b) {
    vector3d result;
    result.x = a.x - b.x;
    result.y = a.y - b.y;
    result.z = a.z - b.z;
    return result;
}
vector3d vector_add_const(vector3d a, double constanta) {
    vector3d result;
    result.x = a.x * constanta;
    result.y = a.y * constanta;
    result.z = a.z * constanta;
    return result;
}
vector3d vector_dev_const(vector3d a, double constanta) {
    vector3d result;
    result.x = a.x / constanta;
    result.y = a.y / constanta;
    result.z = a.z / constanta;
    return result;
}
double scalar_vector_adds(vector3d a, vector3d b) {
    vector3d result;
    result.x = a.x * b.x;
    result.y = a.y * b.y;
    result.z = a.z * b.z;
    return (result.x + result.y + result.z);
}
vector3d vector_adds_vector(vector3d a, vector3d b) {
    vector3d result;
    result.x = a.y * b.z - a.z * b.y;
    result.y = (a.x * b.z - b.x * a.z) * -1;
    result.z = a.x * b.y - a.y * b.x;
    return result;
}
vector3d two_point_vector(point3d d, point3d e) {
    vector3d result;
    result.x = e.x - d.x;
    result.y = e.y - d.y;
    result.z = e.z - d.z;
    return result;
}
point3d vector_point(vector3d a, point3d e) {
    point3d result;
    result.x = e.x - a.x;
    result.y = e.y - a.y;
    result.z = e.z - a.z;
    return result;
}

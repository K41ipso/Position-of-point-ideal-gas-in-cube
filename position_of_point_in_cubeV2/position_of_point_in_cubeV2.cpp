#include <iostream>
#include <string>
#include "func.h"
#include "cube_func.h"

using namespace std;

int main()
{
	vector3d V;
	point3d A, res;
	double T;

	cout << "Enter your directing vector, null point and time (sec):" << endl;
	cin >> V.x >> V.y >> V.z >> A.x >> A.y >> A.z >> T;
	if (point_not_in_cube(A, T)) {
		cout << "This point (" << A.x << ", " << A.y << ", " << A.z << ") ont inhere unit cube or input time = 0 sec.\nPlease, try again!" << endl;
		return 0;
	}
	res = last_point_in_cube(A, V, T);
	cout << "Calculations completed successfully...\nIn the next string you will see the result -->" << endl;
	cout << "(" << res.x << ", " << res.y << ", " << res.z << ")" << endl;
	return 1;
}
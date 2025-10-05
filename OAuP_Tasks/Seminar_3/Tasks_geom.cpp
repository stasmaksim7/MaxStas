// Задачи 2 по ОАиП

// Геометрические задачи презентация

// Задача 1

//#include <iostream>
//using namespace std;
//int main() {
//	const int Len = 6;
//	int Ls[Len];
//	int k = 1;
//	for (int i = 0; i < 6; i += 2) {
//		cout << "Введите " << k << "-й X:";
//		cin >> Ls[i];
//		cout << "Введите " << k << "-й Y:";
//		cin >> Ls[i+1];
//		k += 1;
//	}
//	float S = 0.5*(Ls[1]*(Ls[4]-Ls[6]) + Ls[3]*(Ls[6]-Ls[2]) + Ls[5]*(Ls[2]-Ls[4]));
//	cout << "Площадь треугольника:" << S;
//
//	return 0;
//}

// Задача 2
//#include <iostream>
//using namespace std;
//#include <cmath>
//int main(){
//	const int Len = 8;
//	int Ls[Len];
//	int k = 1;
//	for (int i = 0; i < Len; i += 2) {
//		cout << "Введите координату Х у " << k << "-й вершины:";
//		cin >> Ls[i];
//		cout << "Введите координату Y у " << k << "-й вершины:";
//		cin >> Ls[i+1];
//		k += 1;
//	}
//	double S = 0;
//	for (int i = 0; i < Len-2; i += 2) {
//		double X = pow((Ls[i+2]-Ls[i]),2);
//		double Y = pow((Ls[i+3]-Ls[i+1]),2);
//		double d = pow((X + Y),0.5) ;
//		S += d;
//	}
//	double X = pow((Ls[0]-Ls[6]),2);
//	double Y = pow((Ls[1]-Ls[7]),2);
//	double d = pow((X + Y),0.5);
//	S += d;
//	cout << "Площадь многоугольника:" << S;
//	return 0;
//}

// Задача 3
//#include <iostream>
//using namespace std;
//int main() {
//	const int Len = 6;
//	float Ls[Len];
//	int k = 1;
//	for (int i = 0; i < Len;i += 2){
//		cout << "Введите координату X у " << k << "-й вершины:";
//		cin >> Ls[i];
//		cout << "Введите координату Y у " << k << "-й вершины:";
//		cin >> Ls[i+1];
//		k += 1;
//	}
//	float Cx = (Ls[0] + Ls[2] + Ls[4])/ 3;
//	float Cy = (Ls[1] + Ls[3] + Ls[5])/ 3;
//	cout << "X:" << Cx << " Y:" << Cy;
//	return 0;
//}

// Задача 4

//#include <iostream>
//using namespace std;
//#include <cmath>
//int main() {
//	const int Len = 8;
//	double Ls[Len];
//	int k = 1;
//	for (int i = 0; i < Len; i += 2) {
//		cout << "Введите координату X у " << k << "-й вершины:";
//		cin >> Ls[i];
//		cout << "ведите координату Y у " << k << "-й вершины:";
//		cin >> Ls[i+1];
//		k += 1;
//	}
//	double MaxS = -99999999999999;
//	double MinS = 99999999999999;
//	double Xmax = 0;
//	double Ymax = 0;
//	double Xmin = 0;
//	double Ymin = 0;
//	for (int i = 0; i < Len; i += 2) {
//		if (MaxS < (Ls[i] + Ls[i+1])) {
//			MaxS = Ls[i] + Ls[i+1];
//			Xmax = Ls[i];
//			Ymax = Ls[i+1];
//		}
//		if (MinS > (Ls[i] + Ls[i+1])) {
//			MinS = Ls[i] + Ls[i+1];
//			Xmin = Ls[i];
//			Ymin = Ls[i+1];
//		}
//	}
//	double X = pow(Xmax-Xmin,2);
//	double Y = pow(Ymax-Ymin,2);
//	double d = pow(X+Y,0.5);
//	cout << "Диагональ:" <<d;
//	return 0;
//}

// Задача 5
// #include <iostream>
// using namespace std;

// int main(){
// 	const int Len = 6;
// 	double Ls[Len];
// 	int k = 1;
// 	for (int i = 0; i < Len; i+= 2) {
// 		cout << "Введите координату X у " << k << "-ой точки:";
// 		cin >> Ls[i];
// 		cout << "Введите координату Y у " << k << "-ой точки:";
// 		cin >> Ls[i+1];
// 		k += 1;
// 	}
// 	double X1 = (Ls[2]-Ls[0]);
// 	double Y1 = (Ls[3]-Ls[1]);
// 	double X2 = (Ls[4]-Ls[0]);
// 	double Y2 = (Ls[5]-Ls[1]);
// 	if (X1*Y2 - X2*Y1 == 0){
// 		cout << "Точки лежат на одной прямой";
// 	}
// 	else {
// 		cout << "Точки не лежат на одной прямой";
// 	}
// 	return 0;
// }

// Задача 6
// #include <iostream>
// using namespace std;
// int Vp(int x1, int y1, int x2, int y2){
//     int Product = x1*y2 - x2*y1;
//     if (Product > 0) {
//         return 1;
//     }
//     return 0;
// }
// int main() {
//     int Ls[2][4];
//     char k = 65;
//     for (int i = 0; i < 4; i++) {
//         for (int j = 0; j < 2; j++) {
//             if (j == 0){
//                 cout << "Введите координату X точки " << k << ":"; 
//             }
//             else {
//                 cout << "Введите координату Y точки " << k << ":";
//                 k++;
//             }
//             cin >> Ls[j][i];
//         }
//     }
//     int Ax = Ls[0][0];
//     int Ay = Ls[1][0];
//     int ABx = Ls[0][1] - Ax;
//     int ABy = Ls[1][1] - Ay;
//     int ACx = Ls[0][2] - Ax;
//     int ACy = Ls[1][2] - Ay;
//     int ADx = Ls[0][3] - Ax;
//     int ADy = Ls[1][3] - Ay;
//     if (Vp(ABx,ABy,ACx,ACy) + Vp(ABx,ABy,ADx,ADy) == 1) {
//         cout << "Отрезки пересекаются";
//     }
//     else {
//         cout << "Отрезки не пересекаются";
//     }
// 	return 0;
// }


// Задание 8
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int Ls[2][2];
    char k = 65;
    for (int i = 0; i < 2;i++){
        for (int j = 0; j < 2;j++) {
            if (j == 0){
                cout << "Введите координаты X точки " << k <<":";
            }
            else{
                cout << "Введите координаты Y точки " << k << ":";
                k++;
            }
            cin >> Ls[i][j];
        }
    }
    cout << pow((pow(Ls[1][0]-Ls[0][0],2) + pow(Ls[1][1]-Ls[0][1],2)),0.5);
    return 0;
} 

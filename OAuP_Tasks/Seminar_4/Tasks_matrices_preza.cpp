// Задание 1

// #include <iostream>
// using namespace std;
// int Pr(int Ls[3][3]){
//     return Ls[0][0]*Ls[1][1]*Ls[2][2] + Ls[1][0]*Ls[2][1]*Ls[0][2] + Ls[0][1]*Ls[1][2]*Ls[2][0] \
//      - Ls[2][0]*Ls[1][1]*Ls[0][2] - Ls[0][1]*Ls[1][0]*Ls[2][2] - Ls[0][0]*Ls[1][2]*Ls[2][1];
// }
// int main(){
//     int Ls[3][3];
//     Ls[0][2] = 1;
//     Ls[1][2] = 1;
//     Ls[2][2] = 1;
//     for (int y = 0; y < 3; y++){
//         for (int x = 0; x < 2; x++){
//             cin >> Ls[y][x];
//         }
//     }
//     int S = 0.5 * (Pr(Ls));
//     cout << S;
//     return 0;
// }

// Задание 2

// #include <iostream>
// #include <cmath>

// using namespace std;

// int main(){
//     float a;
//     cout << "Введите угол:";
//     cin >> a;
//     a = a * (M_PI / 180.0);
//     int x1,y1,x,y,Ls[2][2] = {
//         {cos(a),sin(a)},
//         {-sin(a),cos(a)}
//     };
//     cout << "Введите координату X точки А:";
//     cin >> x;
//     cout << "Введите координату Y точки A:";
//     cin >> y;
//     x1 = x * Ls[0][0] - y * Ls[0][1];
//     y1 = x * Ls[1][0] - y * Ls[1][1];
//     cout << "x1:" << x1 << " y1:" << y1;
//     return 0;
// }


// Задание 3

// #include <iostream>
// using namespace std;
// int Pr(int Ls[3][3]){
//     return Ls[0][0]*Ls[1][1]*Ls[2][2] + Ls[1][0]*Ls[2][1]*Ls[0][2] + Ls[0][1]*Ls[1][2]*Ls[2][0] \
//      - Ls[2][0]*Ls[1][1]*Ls[0][2] - Ls[0][1]*Ls[1][0]*Ls[2][2] - Ls[0][0]*Ls[1][2]*Ls[2][1];
// }
// int main(){
//     int Ls[3][3];
//     Ls[0][2] = 1;
//     Ls[1][2] = 1;
//     Ls[2][2] = 1;
//     for (int y = 0; y < 3; y++){
//         for (int x = 0; x < 2; x++){
//             cin >> Ls[y][x];
//         }
//     }
//     int S =  Pr(Ls);
//     if (S == 0){
//         cout << "Вектора коллинеарны";
//     }
//     else{
//         cout << "Вектора неколлинеарны";
//     }
//     return 0;
// }

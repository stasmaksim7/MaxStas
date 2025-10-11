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

// Задание 4
// #include <iostream>
// #include <cmath>
// using namespace std;
// int Pr(int m[4][4]) {
//    return m[0][0] * (m[1][1] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) + m[1][3] * (m[2][1] * m[3][2] - m[2][2] * m[3][1])) -
//         m[0][1] * (m[1][0] * (m[2][2] * m[3][3] - m[2][3] * m[3][2]) - m[1][2] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][2] - m[2][2] * m[3][0])) +
//         m[0][2] * (m[1][0] * (m[2][1] * m[3][3] - m[2][3] * m[3][1]) - m[1][1] * (m[2][0] * m[3][3] - m[2][3] * m[3][0]) + m[1][3] * (m[2][0] * m[3][1] - m[2][1] * m[3][0])) -
//         m[0][3] * (m[1][0] * (m[2][1] * m[3][2] - m[2][2] * m[3][1]) - m[1][1] * (m[2][0] * m[3][2] - m[2][2] * m[3][0]) + m[1][2] * (m[2][0] * m[3][1] - m[2][1] * m[3][0]));
// }
// int main(){
//     int LsA[3],LsB[3],LsC[3],LsD[3],t1,t2,t3,t4;
//     cout << "Введите координаты точки А:";
//     for (int i = 0;i < 3;i++)
//         cin >> LsA[i];
//     cout << "Введите координаты точки B:";
//     for (int i = 0;i < 3;i++)
//         cin >> LsB[i];
//     cout << "Введите координаты точки C:";
//     for (int i = 0;i < 3;i++)
//         cin >> LsC[i];
//     cout << "Введите координаты точки D:";
//     for (int i = 0;i < 3;i++)
//         cin >> LsD[i];
//     int Ls[4][4] = {
//         {LsA[0],LsA[1],LsA[2],1},
//         {LsB[0],LsB[1],LsB[2],1},
//         {LsC[0],LsC[1],LsC[2],1},
//         {LsD[0],LsD[1],LsD[2],1}};
//     t1 = -(LsA[0]*LsA[0] + LsA[1]*LsA[1] + LsA[2]*LsA[2]);
//     t2 = -(LsB[0]*LsB[0] + LsB[1]*LsB[1] + LsB[2]*LsB[2]);
//     t3 = -(LsC[0]*LsC[0] + LsC[1]*LsC[1] + LsC[2]*LsC[2]);
//     t4 = -(LsD[0]*LsD[0] + LsD[1]*LsD[1] + LsD[2]*LsD[2]);
//     int LsAd[4][4] = {{t1,LsA[1],LsA[2],1},{t2,LsB[1],LsB[2],1},{t3,LsC[1],LsC[2],1},{t4,LsD[1],LsD[2],1}};
//     int LsBd[4][4] = {{LsA[0],t1,LsA[2],1},{LsB[0],t2,LsB[2],1},{LsC[0],t3,LsC[2],1},{LsD[0],t4,LsD[2],1}};
//     int LsCd[4][4] = {{LsA[0],LsA[1],t1,1},{LsB[0],LsB[1],t2,1},{LsC[0],LsC[1],t3,1},{LsD[0],LsD[1],t4,1}};
//     int LsDd[4][4] = {{LsA[0],LsA[1],LsA[2],t1},{LsB[0],LsB[1],LsB[2],t2},{LsC[0],LsC[1],LsC[2],t3},{LsD[0],LsD[1],LsD[2],t4}};
//     int d,dA,dB,dC,dD;
//     float A,B,C,D,x0,y0,z0,r;
//     d = Pr(Ls);
//     dA = Pr(LsAd);
//     dB = Pr(LsBd);
//     dC = Pr(LsCd);
//     dD = Pr(LsDd);
//     A = dA/d;
//     B = dB/d;
//     C = dC/d;
//     D = dD/d;
//     x0 = -(A/2);
//     y0 = -(B/2);
//     z0 = -(C/2);
//     r = x0*x0 + y0*y0 + z0*z0 - D;
//     cout << "Уравнение сферы: (x - " << x0 << ")**2 + (y - " << y0 << ")**2 + (z - " << z0 << ")**2 = " << r; 
//     return 0;
// }
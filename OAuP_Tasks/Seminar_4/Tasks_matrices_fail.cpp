
// Задача 1

// #include <iostream>
// using namespace std;
// int main(){
//     int N;
//     cout << "Введите длинну матрицы:";
//     cin >> N;
//     int Ls[N][N];
//     int Ls1[N][N];
//     int Ls2[N][N];
//     int Ls3[N][N];
//     int Ls4[N][N];
//     for (int i = 0; i < N ; i++){
//         for (int j = 0; j < N;j++){
//             cin >> Ls[i][j];
//         }
//     }
//     cout << "Отражение относительно главной:"<< endl;
//     for (int i = 0; i < N ; i++){
//         for (int j = 0; j < N;j++){
//             Ls1[i][j] = Ls[j][i];
//         }
//     }
//     for (int i = 0; i < N ; i++){
//         for (int j = 0; j < N;j++){
//             cout << Ls1[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "Отражение относительно побочной:" << endl;
//     for (int i = 0; i < N ; i++){
//         for (int j = 0; j < N;j++){
//             Ls2[i][j] = Ls[N-j-1][N-i-1];
//         }
//     }
//     for (int i = 0; i < N ; i++){
//         for (int j = 0; j < N;j++){
//             cout << Ls2[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "Отражение относительно центра вертикали:"<< endl;
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < N;j++){
//             Ls3[i][j] = Ls[i][N-1-j];
//         }
//     }
//     for (int i = 0; i < N ; i++){
//         for (int j = 0; j < N;j++){
//             cout << Ls3[i][j] << " ";
//         }
//         cout << endl;
//     }
//     cout << "Отражение относительно центра горизантали:"<< endl;
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < N;j++){
//             Ls4[i][j] = Ls[N-i-1][j];
//         }
//     }

//     for (int i = 0; i < N ; i++){
//         for (int j = 0; j < N;j++){
//             cout << Ls4[i][j] << " ";
//         }
//         cout << endl;
//     }
//     int flag = 1;
//     for (int i = 0; i< N;i++){
//         if (flag == 0){
//             break;
//         }
//         for (int j = 0; j < N;j++){
//             if (Ls1[i][j] != Ls2[i][j]){
//                 flag = 0;
//                 break;
//             }


//         }
//     }
//     if (flag == 1){
//         cout << "Первый массив совпадает со вторым" << endl;
//     }
//     else{
//         flag = 1;
//     }
//     for (int i = 0; i< N;i++){
//         if (flag == 0){
//             break;
//         }
//         for (int j = 0; j < N;j++){
//             if (Ls1[i][j] != Ls3[i][j]){
//                 flag = 0;
//                 break;
//             }


//         }
//     }
//     if (flag == 1){
//         cout << "Первый массив совпадает с третим" << endl;
//     }
//     else{
//         flag = 1;
//     }
//     for (int i = 0; i< N;i++){
//         if (flag == 0){
//             break;
//         }
//         for (int j = 0; j < N;j++){
//             if (Ls1[i][j] != Ls4[i][j]){
//                 flag = 0;
//                 break;
//             }


//         }
//     }
//     if (flag == 1){
//         cout << "Первый массив совпадает со четвертым" << endl;
//     }
//     else{
//         flag = 1;
//     }
//     for (int i = 0; i< N;i++){
//         if (flag == 0){
//             break;
//         }
//         for (int j = 0; j < N;j++){
//             if (Ls2[i][j] != Ls3[i][j]){
//                 flag = 0;
//                 break;
//             }


//         }
//     }
//     if (flag == 1){
//         cout << "Второй массив совпадает с третим" << endl;
//     }
//     else{
//         flag = 1;
//     }
//     for (int i = 0; i< N;i++){
//         if (flag == 0){
//             break;
//         }
//         for (int j = 0; j < N;j++){
//             if (Ls2[i][j] != Ls4[i][j]){
//                 flag = 0;
//                 break;
//             }


//         }
//     }
//     if (flag == 1){
//         cout << "Второй масив совпадает с четвертым" << endl;
//     }
//     else{
//         flag = 1;
//     }
//         for (int i = 0; i< N;i++){
//         if (flag == 0){
//             break;
//         }
//         for (int j = 0; j < N;j++){
//             if (Ls3[i][j] != Ls4[i][j]){
//                 flag = 0;
//                 break;
//             }


//         }
//     }
//     if (flag == 1){
//         cout << "Третий массив совпадает с четвертым";
//     }
//     else{
//         flag = 1;
//     }






//     return 0;
// }

//Задание 2

// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     int N;
//     cout << "Введите N:";
//     cin >> N;
//     int Ls[N][N];
//     vector<int> Ve;
//     for (int i = 0; i < N ; i++){
//         for (int j = 0; j < N;j++){
//             cin >> Ls[i][j];
//         }
//     }
//     int S = 0;
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < N; j++){
//             if (i == j){
//                 S += Ls[i][j];
//             }
//         }
//     }
//     Ve.push_back(S);
//     S = 0;
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < N; j++){
//             if ((i + j) == (N - 1)){
//                 S += Ls[i][j];
//             }
//         }
//     }
//     Ve.push_back(S);
//     S = 0;
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < N; j++){
//             S += Ls[i][j];
//         }
//         Ve.push_back(S);
//         S = 0;
//     }
//     S = 0;
//     for (int i = 0; i < N; i++){
//         for (int j = 0; j < N; j++){
//             S += Ls[j][i];
//         }
//         Ve.push_back(S);
//         S = 0;
//     }
//     int flag = 1;
//     for (int i = 0; i < N-1; i++){
//         if (Ve[i] != Ve[i+1]){
//             flag = 0;
//             break;
//         }
//     }
//     if (flag == 1){
//         cout << "Yes - " << Ve[0];
//     }
//     else{
//         cout << "No";
//     }
//     return 0;
// }
// Задание 3
// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     int N,M;
//     cin >> N >> M;
//     // N - Высота(кол-во строк)
//     // M - Длинна(кол-во столбв)
//     int LsN[N][2];
//     int LsM[2][M];
//     int Ls[N][M];
//     for (int i = 0; i < N; i++){
//         for (int j = 0;j < M; j++ ){
//             cin >> Ls[i][j];
//         }
//     }
//     // Вертикальна нумерация
//     for (int i = 0; i < N; i++){
//         int Max = -9999999;
//         int Min = 9999999999;
//         for (int j = 0;j < M; j++ ){
//             if (Ls[i][j] > Max){
//                 Max = Ls[i][j];
//             }
//             if (Ls[i][j] < Min){
//                 Min = Ls[i][j];
//             }
//         LsN[i][0] = Max;
//         LsN[i][1] = Min;

//         }
//     }
//     // Горизонтальная нумирация
//     for (int i = 0; i < M; i++){
//         int Max = -9999999;
//         int Min = 9999999999;
//         for (int j = 0;j < N; j++ ){
//             if (Ls[j][i] > Max){
//                 Max = Ls[j][i];
//             }
//             if (Ls[j][i] < Min){
//                 Min = Ls[j][i];
//             }
//         LsM[0][i] = Max;
//         LsM[1][i] = Min;

//         }
//     }
//     for (int i = 0; i < N; i++){
//         for (int j = 0;j < M; j++ ){
//             if ((Ls[i][j] == LsN[i][1]) && (Ls[i][j] == LsM[0][i])){
//                 cout << "Тип данных А, индексы" << i << " " << j << ". Значение:" << Ls[i][j] << endl;
//             }
//             else{
//                 cout << "None" << endl;
//             }
//         }
//     }
//     for (int i = 0; i < M; i++){
//         for (int j = 0;j < N; j++ ){
//             if ((Ls[i][j] == LsN[i][0]) && (Ls[i][j] == LsM[1][i])){
//                 cout << "Тип данных В, индексы - " << i << " и " << j << ". Значение:" << Ls[i][j] << endl;
//             }
//             else{
//                 cout << "None" << endl;
//             }
//         }
//     }
// }
// Задание 4
// #include <iostream>
// using namespace std;
// int main(){
//     int N;
//     cin >> N;
//     int Ls[N][N];
//     int c = 1;
//     int start = 0;
//     int n;
//     while (start < (N / 2)){
//         n = N - (start * 2) - 1;
//         for (int x = 0; x < n ; x++){
//             Ls[start][start+x] = c;
//             c += 1;
//         }
//         for (int y = 0; y < n; y++){
//             Ls[start + y][N - 1 - start] = c;
//             c += 1;
//         }
//         for (int x = 0; x < n; x++){
//             Ls[N - 1 - start][N - 1 - start - x] = c;
//             c += 1;
//         }
//         for (int y =0; y < n; y++) {
//             Ls[N-1- start - y][start] = c;
//             c +=1;
//         }
//         start += 1;
//     }
//     if (N % 2 == 1){
//         Ls[start][start] = c;
//     }
//     for (int i = 0; i < N ; i++){
//         for (int j = 0; j < N;j++){
//             cout << Ls[i][j] << " ";
//         }
//         cout << endl;
//     }


//     return 0;
// }


// Задание 5
// #include <iostream>
// using namespace std;
// int main(){
//     int N,M;
//     cin >> N >> M;
//     int Ls[M][N];
//     for (int y = 0; y < M; y++){
//         for (int x = 0; x < N; x++){
//             cin >> Ls[y][x];
//         }
//     }
//     int k = 0;
//     int start = 0;
//     int n,m;
//     while (k < N*M){
//         n = N - (start * 2) - 1;
//         m = M - (start * 2) - 1;
//         if (n <= 0 && m <= 0) {
//             cout << Ls[M/2][N/2];
//             break;
//         }
//         for (int x = 0; x < n; x++){
//             cout << Ls[start][x+start];
//             k++;
//         }
//         for (int y = 0; y < m; y++){
//             cout << Ls[y+start][N-1-start];
//             k++;
//         }
//         for (int x = 0; x < n; x++){
//             cout << Ls[M-1-start][N-1-x-start];
//             k++;
//         }
//         for (int y = 0; y < m; y++){
//             cout << Ls[M-1-y-start][start];
//             k++;
//         }
//         start += 1;
//     }   
//     return 0;
// }

// Задание 6
// #include <iostream>
// using namespace std;
// int Pr(int Ls[2][2]){
//     return Ls[0][0]*Ls[1][1] - Ls[1][0]*Ls[0][1];
// }
// int main(){
//     int Ls[2][2] = {
//         {2,3},
//         {5,-1}};
//     int t1,t2;
//     t1 = 13;
//     t2 = 9;
//     int Ls1[2][2] = {
//         {2,t1},
//         {5,t2}};
//     int Ls2[2][2] = {
//         {t1, 3},
//         {t2,-1}};
//     float d = Pr(Ls);
//     float dx = Pr(Ls2);
//     float dy = Pr(Ls1);
//     float x = dx/d;
//     float y = dy/d;
//     cout << x << " " << y;
//     return 0;
// }

// Задание 7 и 8
// #include <iostream>
// using namespace std;
// int Pr(int Ls[3][3]){
//     return Ls[0][0]*Ls[1][1]*Ls[2][2] + Ls[1][0]*Ls[2][1]*Ls[0][2] + Ls[0][1]*Ls[1][2]*Ls[2][0] \
//      - Ls[2][0]*Ls[1][1]*Ls[0][2] - Ls[0][1]*Ls[1][0]*Ls[2][2] - Ls[0][0]*Ls[1][2]*Ls[2][1];
// }
// Задание 7
// int main(){
//     int Ls[3][3] = {
//         {1,1,1},
//         {2,-1,3},
//         {-1,4,-1}
//     };
//     int t1,t2,t3;
//     t1 = 6;
//     t2 = 14;
//     t3 = 2;
//     int Lsx[3][3] = {{t1,1,1},{t2,-1,3},{t3,4,-1}};
//     int Lsy[3][3] = {{1,t1,1},{2,t2,3},{-1,t3,-1}};
//     int Lsz[3][3] = {{1,1,t1},{2,-1,t2},{-1,4,t3}};
//     float d = Pr(Ls);
//     float dx = Pr(Lsx);
//     float dy = Pr(Lsy);
//     float dz = Pr(Lsz);
//     float x = dx/d;
//     float y = dy/d;
//     float z = dz/d;
//     cout << x << " " << y << " " << z;
//     return 0;
// }
// Задание 8
// int main(){
//     int Ls[3][3] = {
//         {3,-1,2},
//         {2,4,-1},
//         {1,-3,1}
//     };
//     int t1,t2,t3;
//     t1 = 5;
//     t2 = 6;
//     t3 = 4;
//     int Lsx[3][3] = {{t1,-1,2},{t2,4,-1},{t3,-3,1}};
//     int Lsy[3][3] = {{3,t1,2},{2,t2,-1},{1,t3,1}};
//     int Lsz[3][3] = {{3,-1,t1},{2,4,t2},{1,-3,t3}};
//     float d = Pr(Ls);
//     float dx = Pr(Lsx);
//     float dy = Pr(Lsy);
//     float dz = Pr(Lsz);
//     float x = dx/d;
//     float y = dy/d;
//     float z = dz/d;
//     cout << x << " " << y << " " << z;
//     return 0;

// }





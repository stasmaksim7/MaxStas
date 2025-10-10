
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
#include <iostream>
using namespace std;
int main(){
    int Ls[2][2] = {
        {2,3},
        {5,-1}
    };
    cout << Ls[0][0]*Ls[1][1] - Ls[0][1] * Ls[1][0];
    return 0;
}

    





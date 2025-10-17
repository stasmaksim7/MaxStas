


// Задание 1

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main(){
//     vector<int> Num(10);
//     for (int i = 0; i < 10; ++i){
//         Num[i] = i + 1;
//     }

//     for_each(Num.begin(), Num.end(), [](int num) {
//         cout << num << " ";
//     });

//     return 0;
// }



// Задание 2

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main(){
//     vector<int> Num(10);
//     for (int i = 0; i < 10; i++)
//         cin >> Num[i];
//     for_each(Num.begin() ,Num.end(), [](int num){
//         cout << num*num << " ";
//     });
//     return 0;
// }



// Задание 3

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main(){
//     vector<int> Num(20);
//     for (int i = 0; i < 20; i++)
//         cin >> Num[i];
//     vector<int>::iterator it = max_element(Num.begin() ,Num.end());

//     cout << *it;
//     return 0;
// }


 
// Задание 4

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int main(){
//     vector<int> Num(10);
//     for (int i = 0; i < 10; i++){
//         cin >> Num[i];
//     }
//     auto New = remove_if(Num.begin(),Num.end(),[](int n){
//         return n < 0;
//     });
//     for_each(Num.begin(),Num.end(), [](int n){
//         cout << n << " ";
//     });
//     return 0;
// }



// Задание 5

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <numeric> // для accumulate
// #include<functional> // для sort
// using namespace std;
// int main(){
//     vector<float> Ve(20);
//     for (int i = 0; i < 20;i++)
//         cin >> Ve[i];
//     auto F = minmax_element(Ve.begin(),Ve.end());
//     cout << "Мин:" << *F.first << endl;
//     cout << "Макс:" << *F.second << endl;
//     float sum = accumulate(Ve.begin(),Ve.end(),0);
//     cout << "Ср. знач:" << sum/20 << endl;

//     // Сортировка функцией
//     // sort(begin(Ve),end(Ve),[](int a, int b) {
//     //     return a < b;
//     // });
//     // Сортировка пузырьком

//     int R;
//     for (int i = 0; i < 20; i++){
//         for (int j = 0; j < 20-1; j++){
//             R = Ve[j];
//             if (Ve[j] > Ve[j+1]){ R = Ve[j+1]; Ve[j+1] = Ve[j]; Ve[j] = R; }
//         }
//     }

//     for_each(Ve.begin(),Ve.end(),[](int n){
//         cout << n << " ";
//     });

//     cout << "Медиана:" << (Ve[9] + Ve[10])/2;
//     return 0;
// };



// Задание 6

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <functional> // для sort
// using namespace std;
// int main(){
//     vector<int> Ve(20);
//     for (int i = 0; i < 20; i++) cin >> Ve[i];
//     auto itFind = find(Ve.begin(), Ve.end(), 7);
//     if (*itFind == 7) cout << "Число 7 есть в векторе." << endl;
//     sort(begin(Ve),end(Ve),[](int a, int b){return a < b;});
//     Ve.erase(unique(Ve.begin(),Ve.end()),Ve.end());
//     for_each(Ve.begin(),Ve.end(),[](int n){cout << n << " ";});
//     return 0;
// }



// Задание 7

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <functional>
// using namespace std;
// int main(){
//     vector<double> Ve =\
//     {10.24,35.46,43.45,436.9,0.12,-35.67,-51.3,56.8,32.0,12.43,45.3,56.3,45.2};
//     int N = 13,Sr;
//     auto itFind = remove_if(Ve.begin(), Ve.end(),[](double a){
//         return -50.0 < a < 50.0;});
//     for_each(Ve.begin(),Ve.end(),[](double n){cout << n << " ";}); cout << endl;
//     // auto itMin = min_element(Ve.begin(),Ve.end()); cout << *itMin << endl;
//     // auto itMax = max_element(Ve.begin(),Ve.end()); cout << *itMax << endl;
//     auto itMinMax = minmax_element(Ve.begin(),Ve.end());
//     cout << "Макс:" <<*itMinMax.first << "\n" << "Мин:" << *itMinMax.second << endl;
//     sort(begin(Ve),end(Ve),[](int a, int b){return a < b;});
//     if (Ve.size() / 2 == 0) Sr = (Ve[N/2] + Ve[(N/2)-1])/2;
//     else Sr = (Ve[N/2]); cout << "Ср. знач:" << Sr << endl;
//     auto it = find_if(Ve.begin(),Ve.end(),[](int a){return a < -10;});
//     if (*it > -100000) cout << "Нет элментов меньше -10"; 
//     return 0;
// }



// Задание 8

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <numeric>
// using namespace std;
// int main(){
//     srand(static_cast<unsigned int>(time(0)));
//     int N = rand() % 100; vector<int> Ve(N);
//     for(int i=0; i<N; i++) {Ve[i] = rand() % 100;}
//     for_each(Ve.begin(),Ve.end(),[](int n){cout << n << " ";}); cout << endl;
//     auto it = remove_if(Ve.begin(),Ve.end(),[](int a){return a < 120;});
//     float Sum = accumulate(Ve.begin(),Ve.end(),0); cout << "Ср. скорость:"<< Sum/N << endl; 
//     auto itFind = find(Ve.begin(),Ve.end(),0); 
//     if (*itFind == 0) cout << "Автомобиль останавливался" << endl;
//     sort(begin(Ve),end(Ve),[](int a,int b) {return a > b;});
//     Ve.erase(unique(Ve.begin(),Ve.end()),Ve.end());
//     cout << "Вывод 10 наибольших отсортированных элементов: ";
//     for (int i = 0; i < 10; i++) cout << Ve[i] << " ";
//     return 0;
// }



// Задание 9

// #include <iostream>
// #include <vector>
// #include <random>
// #include <algorithm>

// using namespace std;
// int main(){
//     int N = 20,Sr; vector<int> Ve;
//     random_device rd; 
//     mt19937 gen(rd()); 
//     uniform_int_distribution<int> dist(-10,100);
//     for (int i = 0; i < N; i++){Ve.push_back(dist(gen));}
//     for_each(Ve.begin(),Ve.end(),[](int a){cout << a << " ";}); cout << endl;
//     Ve.erase(remove_if(Ve.begin(),Ve.end(),[](int a){return a < 0;}), Ve.end()); 
//     for_each(Ve.begin(),Ve.end(),[](int a){cout << a << " ";});
//     auto MinMaxit = minmax_element(Ve.begin(),Ve.end());
//     cout << "Макс:" << *MinMaxit.first << "\n" << "Мин:" << *MinMaxit.second << endl;
//     auto Find = find_if(Ve.begin(),Ve.end(),[](int a){return 10 > a || a > 90 ;});
//     if (*Find < -1000) cout << "Двигатель всегда работает в пределах от 10 до 90 кВт";
//     sort(Ve.begin(),Ve.end(),[](int a, int b){return a < b;});
//     for_each(Ve.begin(),Ve.end(),[](int a){cout << a << " ";});
//     N = Ve.size();
//     if (N % 2 == 1) cout << "Медиана:" << Ve[N/2];
//     else cout << "Медиана:" << (double(Ve[(N/2)-1] + Ve[N/2])/2);
//     return 0;
// }

// Задание 10

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <random>
// using namespace std;
// int main(){
//     int N = 30; vector<int> Ve;
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<int> dist(1,100);
//     for (int i = 0; i < N; i++){Ve.push_back(dist(gen));}
//     for_each(Ve.begin(),Ve.end(),[](int a){cout << a << " ";});cout << endl;
//     double Sum = accumulate(Ve.begin(),Ve.end(),0); 
//     cout << "Сумма:"<< Sum << "\nСреднесуточное:" << Sum/N << endl;
//     auto MinMaxit = minmax_element(Ve.begin(),Ve.end());
//     cout << "Мин:" << *MinMaxit.first << "\n" << "Макс:" << *MinMaxit.second << endl;
//     Ve.erase(remove_if(Ve.begin(),Ve.end(),[Sum](int a){return ((a-Sum / Sum) * 100) ;}));
//     for_each(Ve.begin(),Ve.end(),[](int a){cout << a << " ";});cout << endl;
//     return 0;
// }



// Задание 13

// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <random>
// using namespace std;
// int main(){
//     int N = 30; vector<int> Ve(N);
//     random_device rd;
//     mt19937 gen(rd());
//     uniform_int_distribution<int> dist(-5,15);
//     for (int i = 0; i < N; i++){Ve.push_back(dist(gen));}
//     for(int i=0; i<N; i++) {Ve[i] = rand() % 100;}
//     for_each(Ve.begin(),Ve.end(),[](int a){cout << a << " ";}); cout << endl;
//     Ve.erase(remove_if(Ve.begin(),Ve.end(),[](int a){return a <= 0 || a >= 12;}), Ve.end()); 
//     double Sum = accumulate(Ve.begin(),Ve.end(),0); 
//     cout << "Среднее значение:" << Sum/N << endl;
//     auto MinMaxit = minmax_element(Ve.begin(),Ve.end());
//     cout << "Мин:" << *MinMaxit.first << "\nМакс:" << *MinMaxit.second << endl;
//     for_each(Ve.begin(),Ve.end(),[](int a){if (a > 8) cout << a << " ";});
//     return 0;
// }


// Задание 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;

int main()
{
    int n=24, Len;
    vector <double> num; vector <double> Ve; vector <int> Ve1;
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(100.0, 500.0);  
    cout << "Изначальный массив: " << endl;
    for (int i = 0; i < n; ++i) {
        num.push_back(dist(gen));
        Ve.push_back(dist(gen));
        Ve1.push_back(i);
    }
    for (double el : num) {cout << el << " ";} cout << endl;
    double sum = accumulate(num.begin(), num.end(), 0); 
    double Sr = sum/(num.size());
    cout << "Суммарное потребление: " << sum << endl;
    cout << "Среднее потребление: " << Sr << endl;
    transform(num.begin(),num.end(),num.begin(),[Sr](double x){return abs(Sr-x);});
    for_each(num.begin(),num.end(),[](double a){cout << a << " ";});    
    Len = Ve.size();
    for (int i = 0; i < Len; i++){
        
    } 
    return 0;
}

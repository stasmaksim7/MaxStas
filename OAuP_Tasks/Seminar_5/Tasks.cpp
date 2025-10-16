


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
//     auto itUnique = unique(Ve.begin(),Ve.end());
//     for_each(Ve.begin(),Ve.end(),[](int n){cout << n << " ";});
//     return 0;
// }

// Задание 7 - недоделано

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<double> Ve =\
    {10.24,35.46,43.45,436.9,0.12,-35.67,-51.3,56.8,32.0,12.43};
    auto itFind = remove_if(Ve.begin(), Ve.end(),[](double a){
        return -50.0 < a < 50.0;});
    for_each(Ve.begin(),Ve.end(),[](double n){cout << n << " ";}); cout << endl;
    // auto itMin = min_element(Ve.begin(),Ve.end()); cout << *itMin << endl;
    // auto itMax = max_element(Ve.begin(),Ve.end()); cout << *itMax << endl;
    auto itMinMax = minmax_element(Ve.begin(),Ve.end());
    cout << *itMinMax.first << "\n" << *itMinMax.second << endl;

    return 0;
}
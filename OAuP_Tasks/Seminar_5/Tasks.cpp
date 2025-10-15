
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
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int> Ve(20);
    for (int i = 0; i < 20;i++){
        cin >> Ve[i];
    }
    auto F1 = minmax_element(Ve.begin(),Ve.end(),[](int n){
        cout << *F1.first << endl;
    });
    return 0;
}
// #include <iostream>
// #include <cstring>
// #include <vector>
// using namespace std;
// int main(){
//     string s,sr;
//     vector<string> Ve;
//     cout << "Введите строку:";
//     getline(cin,s);
//     s = s + " ";
//     int k = 0;
//     for (int i = 0; i < s.size()-1;i++){
//         if (s[i] != ' '){  
//             sr = sr + s[i];
//         }
//         else if ((s[i] == ' ') && (s[i+1] != ' ')){
//                 Ve.push_back(sr);
//                 sr = "";
//         }
//     }
//     Ve.push_back(sr);
//     // for (int i = 0; i < Ve.size();i++){
//     //     cout << Ve[i] << " ";
//     // }
//     for (int i = 0; i < Ve.size();i++){
//         if (Ve[i][0] == 'b'){
//                 k += 1;
//         }
//     }
//     cout << "Кол-во слов начинающихся на букву b:" << k << endl;
//     int n,Max = -99999999999999;
//     for (int i = 0; i < Ve.size();i++){
//         n = Ve[i].size();
//         if (n > Max){
//                 Max = n;
//         }
//     }
//     cout << "Максимальное слово длинной:" << Max << endl;
//     string Wp = Ve[Ve.size()-1];
//     k = 0;
//     for (int i = 0; i < Wp.size();i++){
//         if (Wp[i] == 'd'){
//             k += 1;
//         }
//     }
//     cout << "Кол-во букв d в последнем слове:" << k;
//     string Wbig = "qwertyuiopasdfghjklzxcvbnm";
//     // for (int i = 0; i < s.size();i++){
//     //     for (int j = 0; j < Wbig.size();j++){
//     //         if (Wbig.find(s[i]) != string::npos){
                
//     //         }
//     //     }
//     // }

//     return 0;
// }

//Задание 1
// #include <iostream>
// #include <cstring>
// #include <cctype>
// using namespace std;
// bool isPalindrome(const char* str) {
//     int length = strlen(str); 
//     for (int i = 0; i < length / 2; ++i) { 
//     if (tolower(str[i]) != tolower(str[length - i - 1])) {return false;}
//     else{return true;}
//     }
// }
// int main() {
//     char str[100]; 
//         cout << "Введите строку: "; 
//         cin.getline(str, 100); 
//     if (isPalindrome(str)) { 
//         cout << "Это палиндром." << std::endl; 
//     } else {
//         cout << "Это не палиндром." << std::endl; 
//     }
//     return 0; 
// }
// Задание 2
// #include <iostream> 
// #include <cstring> 
// #include <cctype> 
// #include <string>
// #include <set>
// using namespace std;
// int main(){
//         string s;
//         cout << "Введите строку: ";
//         getline(cin, s);

//         set<char> unique(s.begin(), s.end());

//         cout << "Не повторяются " << unique.size() << " символа: ";
//         auto it = unique.begin();
//         if (it != unique.end()) {
//             cout << *it;
//             while (++it != unique.end()) {
//                 cout << " " << *it;
//             }
//         }
//         return 0;
// }
// Задание 3
// #include <iostream>
// #include <string>

// using namespace std;

// int main() {
//     string s;
//     cout << "Введите строку: ";
//     getline(cin, s);
//     string result = "";
//         for (char c : s) 
//         {
//         if (!isdigit(c)) {
//             result += c;
//         }
//     }
    
//     cout << "Результат: " << result << endl;
    
//     return 0;
// }

//Задание 4

// #include <iostream>
// #include <string>
// #include <cstring>
// using namespace std;

// int main() { 
//     int c = 0;
//     string s1;
//     cout << "Введите строку 1:";
//     getline(cin, s1);
//     string s2;
//     cout << "Введите строку 2:";
//     getline(cin, s2);
//     int flag = 1;
//     for(int i = 0; i < s1.length() ; i++){
//         for(int j = 0; j < s2.length(); j++){
//             if(s1[i] == s2[j]) {
//                 c += 1;
//             } else { 
//                 continue;
//             }
//         }
//         if(c >= 1){
//             c = 0;
//             continue;
//         } else {
//             cout << "Буквы: " << s1[i] << " нет";
//             flag = 0;
//             break;
//         }
//     }
//     if (flag == 1){
//         cout << "Да";
//     }
// }

// Задание 5
// #include <iostream>
// #include <cctype>
// #include <cstring>
// using namespace std;

// int main(){
//     char str[50] , gn[] = "EYUIOA";
//     cout << "Введите строку: ";
//     cin.getline(str, 50);
//     int g = 0, s = 0;
//     for(int i = 0; i < strlen(str); i++) {
//         char c = toupper(str[i]);
//         if(isalpha(c)){
//             int flag = 0;
//             for(int j = 0; j < strlen(gn); j++) {
//                 if(c == gn[j]) {
//                     flag = 1;
//                     break;
//                 }
//             }
//             if(flag) {g++;} 
//             else {s++;}
//         }
//     }
//     cout << "Гл:" << g << endl;
//     cout << "Сог:" << s;
//     return 0;
// }

// Задание 6
// #include <iostream>
// #include <cctype>
// #include <cstring>
// using namespace std;
// int main(){
//     char Ls[50];
//     int s;
//     cout << "Введите строку:";
//     cin.getline(Ls, 50);
//     cout << "Введите число:";
//     cin >> s;
//     for(int i = 0; i < strlen(Ls); i++) {
//         if(isupper(Ls[i])) { Ls[i] = (Ls[i] - 'A' + s) % 26 + 'A' ;} 
//         else if(islower(Ls[i])) { Ls[i] = (Ls[i] - 'a' + s) % 26 + 'a' ;}
//     }
//     cout << Ls << endl;
//     return 0;
// }


// Задание 7
// #include <iostream>
// #include <cctype>
// #include <cstring>
// using namespace std;

// int main(){
//     char s[50];
//     cout << "Введите строку: ";
//     cin.getline(s, 50);
//     int Len = strlen(s);
//     for(int i = 0; i < Len; ++i) {
//         char c = s[i];
//         int k = 1;
//         while(i + 1 < Len && s[i + 1] == c) { k++; i++;}
//         cout << c << k;
//     }
//     return 0;
// }


// Задание 8
// #include <iostream>
// #include <cctype>
// #include <cstring>
// using namespace std;

// int main(){
//     char s[50];
//     cout << "Введите строку: ";
//     cin.getline(s, 50);
//     int flag = 1; 
//     for(int i = 0; i < strlen(s); i++) {
//         if(flag && isalpha(s[i])) { 
//             s[i] = toupper(s[i]); 
//             flag = 0;
//         } else if(isalpha(s[i])) { s[i] = tolower(s[i]); }
//         if(s[i] == '.' ||  s[i] == '!' ||  s[i] == '?') { flag = 1;}
//     }
//     cout << s << endl;
//     return 0;
// }

//Задание 9
// #include <iostream>
// #include <cctype>
// #include <cstring>
// using namespace std;

// int main(){
//     char s1[50], s2[50];
//     cout << "Введите первую строку: ";
//     cin.getline(s1,50);
//     cout << "Введите вторую строку: ";
//     cin.getline(s2,50);
//     char Ls[50] = "";
//     size_t Max = 0;
//     for (size_t i = 0; i < strlen(s2); i++){
//         for (size_t j = 1; j <= strlen(s2) - i; j++){
//         char Ls2[50] = "";
//         strncpy(Ls2, s2 + i, j);
//         Ls2[j] = '\0';
//         if (strstr(s1, Ls2) != nullptr){
//             if (j > Max){
//             Max = j;
//             strcpy(Ls, Ls2);
//             }
//         }
//         else {break;}
//         }
//     }
//     cout << Ls;
//     return 0;
// }

// Задание 10
// #include <iostream>
// #include <cctype>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// int main(){
//     char s[50];
//     cout << "Введите строку: ";
//     cin.getline(s, 50);
//     int n = 0;
//     for(int i = 0; i <= strlen(s); i++) {
//         if(s[i] == ' ' || s[i] == '\0') {
//             reverse(s + n, s + i);
//             n = i + 1;
//         }
//     }
//     cout << s;
//     return 0;
// }

// Задание 11
// #include <iostream>
// #include <cctype>
// #include <cstring>
// #include <algorithm>
// using namespace std;

// int main(){
//     int k = 0;
//     char Ls[50] =  "";
//     char s[50];
//     cout << "Введите k:";
//     cin >> k;
//     cin.ignore();
//     cout << "Строка: ";
//     cin.getline(s, 50);
//     for (size_t i = 0; i <= strlen(s) - k; i++){
//         char Ls2[50] = "";
//         strncpy(Ls2, s + i, k);
//         Ls2[k] = '\0';
//         int flag = 1;
//         for(int j = 0; j < k; j++){
//         for(int g = j + 1; g < k; g++){
//             if (Ls2[j] == Ls2[g]){flag = 0;break;}
//         }
//         }
//         if(flag && (strstr(Ls, Ls2) == nullptr)) cout << Ls << endl;
//         strcat(Ls, Ls2);
//     }
//     return 0;
// }











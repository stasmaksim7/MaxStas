// Задание 1
// #include <iostream>
// #include <vector>
// using namespace std;
// int myStrLen(const char* str){
//     const char *str1 = str;
//     while (*str1 != '\0'){str1++;}
//     return str1 - str;}


// int main(){
//     const char str[] = "dgdsfg";
//     cout << "Длина:" << myStrLen(str);
//     return 0;}


// Задание 2
// #include <iostream>
// using namespace std;
// void myStrCopy(char* dest, const char* src){
//     while (*src != '\0'){
//         *dest = *src;
//         dest++;
//         src++;
//     }
//     *dest = '\0';
// }
// int main(){
//     char str1[] = "hgfghn rd j";
//     char str2[] = "";
//     myStrCopy(str2,str1);
//     cout << str2;
//     return 0;     
// }

// Задание 3
// #include <iostream>
// using namespace std;
// void myStrCat(char* dest,const char* src){
//     while (*dest != '\0'){dest++;}
//     while (*src != '\0'){
//         *dest = *src;
//         dest++;
//         src++;
//     }
//     *dest = '\0';
// }

// int main(){
//     char src[] = "shfdh";
//     char dest[] = "1122233";
//     myStrCat(dest,src);
//     cout << dest;
//     return 0;
// }

// Задание 4
// #include <iostream>
// using namespace std;
// int main(){
//     char N, str[50]; int k = 0;
//     cout << "Введите строку:";
//     cin.getline(str, 50);
//     cout << "Введите символ:";
//     cin >> N;;
//     char *i = str;
//     while ( *i != '\0'){
//         if (*i == N){k++;}
//         i++;
//     }
//     cout << "Символ " << N \
//     << " встречается в строке " << k << " раз.";
// }

// Задание 5
// #include <iostream>
// using namespace std;
// int main(){
//     char str[50];
//     cout << "Введите строку:";
//     cin.getline(str,50);
//     char *i = str;
//     while ( *i != '\0'){
//         if (*i == ' '){
//             *i = '_';
//         }
//         i++;
//     }
//     cout << str;
//     return 0;
// }

// Задание 6
// #include <iostream>
// using namespace std;
// void reverse(char* str){
//     char *str1 = str;
//     while (*str1 != '\0'){str1++;}
//     str1--;
//     while (str < str1){
//         char strR = *str;
//         *str = *str1;
//         *str1 = strR;
//         str++;
//         str1--;
//     }
// }
// int main(){
//     char str[50];
//     cout << "Введите строку:";
//     cin.getline(str,50);
//     reverse(str);
//     cout << str;
//     return 0;
// }

// Задание 7
// #include <iostream>
// using namespace std;
// bool isPalindrome(const char* str){
//     const char *str1 = str;
//     while (*str1 != '\0'){str1++;}
//     str1--;
//     while (str < str1){
//         if (*str != *str1){
//             return false;
//         }
//         str++;
//         str1--;
//     }
//     return true;
// }
// int main(){
//     char str[50];
//     cout << "Введите строку:";
//     cin.getline(str,50);
//     cout << isPalindrome(str);
//     return 0;
// }


// Задание 8
// #include <iostream>
// using namespace std;
// const char* findSubstring(const char* text, const char* word){
//     if (!text || !word) return nullptr;
//     for (const char* i = text; *i != '\0'; i++){
//         const char* lstr = i;
//         const char* str = word;
//         while (*lstr != '\0' and *str != '\0' \
//         and *lstr == *str){
//             str++;
//             lstr++;
//         }
//         if (*str == '\0') return i;
//     }
//     return nullptr; 
// }
// int main(){
//     char str[50];
//     cout << "Введите строку:";
//     cin.getline(str,50);
//     char str2[10];
//     cout << "Введите подстроку:";
//     cin.getline(str2,10);
//     const char* R = findSubstring(str,str2);
//     cout << R;
//     return 0;
// }


// Задание 9
// #include <iostream>
// using namespace std;
// int main(){
//     char str[50];
//     cout << "Введите строку:";
//     cin.getline(str,50);
//     char str1[50];
//     char* i1 = str1;
//     for (const char* i = str; *i != '\0'; i++){
//         if (*i != ' '){
//             *i1 = *i;
//             i1++;
//         }
//     }
//     *i1 = '\0';
//     cout << str1;
//     return 0;
// }


// Задание 10
// #include <iostream>
// using namespace std;
// int myStrCmp(const char* s1, const char* s2){
//     while (*s1 == *s2 and *s1 != '\0' and *s2 != '\0')
//     {s1++; s2++;}
//     return *s1 - *s2;
// }
// int main(){
//     char str1[50];
//     cout << "Введите первую строку:";
//     cin.getline(str1,50);
//     char str2[50];
//     cout << "Введите вторую строку:";
//     cin.getline(str2,50);
//     char* i1 = str1; char* i2 = str2;
//     cout << myStrCmp(str1,str2);
//     return 0;
// }


// Задание 11
// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     srand(static_cast<unsigned int>(time(0)));
//     int N = rand() % 100; vector<int> Ve(N);
//     for(int i=0; i<N; i++) Ve[i] = rand() % 100;
//     // for (int i = 0; i < N; i++){
//     //     cout << Ve[i] << " ";
//     // }
//     cout << endl;
//     int sum = 0;
//     int* n = &Ve[0];
//     for (int i = 0; i < N; ++i) sum += *(n + i);
//     cout << sum;
//     return 0;
// }


// Задание 12
// #include <iostream>
// #include <vector>
// using namespace std;
// int main(){
//     srand(static_cast<unsigned int>(time(0)));
//     int N = rand() % 100; vector<int> Ve(N);
//     for(int i=0; i<N; i++) Ve[i] = rand() % 100;
//     // for (int i : Ve){
//     //     cout << Ve[i] << " ";
//     // }
//     //cout << endl;

//     int* n = Ve.data();
//     for (int i = 0; i < N; ++i) *(n + i) += 10;

//     // for (int i : Ve){
//     //     cout << Ve[i] << " ";
//     // }
//     // cout << endl;
//     return 0;
// }


// Задание 13
// #include <iostream>
// using namespace std;
// void parseTelemetry(const char* data){
//     const char* str = data;
//     while (*str != '\0'){
//         while (*str != ':'){
//             if (*str == 'T' && *(str+1) == 'E') cout << "Temperature:";
//             else if (*str == 'P' && *(str+1) == 'R') cout << "Pressure:";
//             else if (*str == 'H' && *(str+1) == 'U') cout << "Humidity:";
//             str++;}
//         str++;
//         while (*str != ';' && *str != '\0') {
//             cout << *str; 
//             str++;
//         }
//         cout << endl;
//         if (*str == ';') str++; 
//    }
// }
// int main() {
//     const char* data = "TEMP:24.5;PRESS:101.3;HUM:55.2";
//     parseTelemetry(data);
//     return 0;
// }
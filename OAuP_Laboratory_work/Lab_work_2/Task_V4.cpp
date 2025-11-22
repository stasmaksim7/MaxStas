// #include <iostream>
// #include <cstring>
// #include <vector>
// #include <algorithm>
// using namespace std;
// string sVM(string s1, string s2){
//     string Maxs = "";
//     for (int i = 0; i < s1.size(); i++) {
//         for (int j = 0; j < s2.size(); j++) {
//             if (s1[i] == s2[j] && i != j) {
//                 string word = "";
//                 int x = i, y = j;
//                 while (x < s1.size() && y < s2.size() && s1[x] == s2[y]) {
//                     word += s1[x];
//                     x++;
//                     y++;
//                 }
//                 if (word.size() > Maxs.size()) {
//                     Maxs = word;
//                 }
//             }
//         }
//     }
//     return Maxs;
// }


// int main(){
//     string s,sr;
//     vector<string> Ve;
//     cout << "Введите строку:";
//     getline(cin,s);
//     s = s + " ";
//     int* k = new int(0);
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
//     for (int i = 0; i < Ve.size();i++){
//         if (Ve[i][0] == 'b'){
//                 *k += 1;
//         }
//     }
//     cout << "Кол-во слов начинающихся на букву b:" << *k << endl;


    
//     int n;
//     int* Max = new int(-99999);
//     for (int i = 0; i < Ve.size();i++){
//         n = Ve[i].size();
//         if (n > *Max){
//                 *Max = n;
//         }
//     }
//     cout << "Максимальное слово длинной:" << *Max << endl;



//     string *Wp = new string(Ve[Ve.size()-1]);
//     *k = 0;
//     for (int i = 0; i < (*Wp).size();i++){
//         if ((*Wp)[i] == 'd'){
//             *k += 1;
//         }
//     }
//     cout << "Кол-во букв d в последнем слове:" << *k << endl;



//     for (int i = 0; i < s.size();i++){
//         if (islower(s[i])){
//             s[i] = toupper(s[i]);
//         }
//     }
//     cout << "Предложение с заглавными буквами:";
//     for (int i = 0; i < s.size();i++){
//         cout << s[i] << "";
//     }
//     cout << endl;



//     vector<string> Ve2;
//     for (int i = 0; i < Ve.size(); i++){
//         for (int j = 0; j < Ve.size(); j++){
//             if ((Ve[i][1] == Ve[j][Ve[j].size()-2]) and (find(Ve2.begin(),Ve2.end(), Ve[i]) == Ve2.end()) \
//             and (find(Ve2.begin(),Ve2.end(),Ve[j]) == Ve2.end())){
//                 if (find(Ve2.begin(),Ve2.end(), Ve[i]) == Ve2.end()){
//                     Ve2.push_back(Ve[i]);
//                 }
//                 if (find(Ve2.begin(),Ve2.end(),Ve[j]) == Ve2.end()){
//                     Ve2.push_back(Ve[j]);
//                 }
//             }
//         }
//     }
//     cout << "Слова которые соответствуют условию(5):";
//     for (int i = 0; i < Ve2.size();i++){
//         cout << Ve2[i] << " ";
//     }
//     cout << endl;



//     string Maxs;
//     for (int i = 0; i < Ve.size(); i++){
//         for (int j = 0; j < Ve.size(); j++){
//             string word = sVM(Ve[i],Ve[j]);
//             if (word.size() > Maxs.size()){
//                 Maxs = word;
//             }
//         }
//     }
//     cout << "Самое большая повтор. посл:" << Maxs;

//     return 0;
// }

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void readDataFromFile(vector<string>& names, vector<string>& types, vector<double>& prices) {
    ifstream inFile("menu.txt");
    if (!inFile.is_open()) return;
    
    string name, type;
    double price;
    while (inFile >> name >> type >> price) {
        names.push_back(name);
        types.push_back(type);
        prices.push_back(price);
    }
    inFile.close();
}

void writeDataToFile(const vector<string>& names, const vector<string>& types, const vector<double>& prices) {
    ofstream outFile("menu.txt");
    for (size_t i = 0; i < names.size(); i++) {
        outFile << names[i] << " " << types[i] << " " << prices[i] << endl;
    }
    outFile.close();
}

void saveToOutput(const string& result) {
    ofstream outFile("output.txt", ios::app);
    outFile << result << endl;
    outFile.close();
}

void addDish(vector<string>& names, vector<string>& types, vector<double>& prices) {
    string name, type, priceStr;
    double price;
    
    cout << "Введите название блюда (пустая строка для завершения): ";
    getline(cin, name);
    if (name.empty()) return;
    
    cout << "Введите тип блюда: ";
    getline(cin, type);
    
    cout << "Введите цену: ";
    getline(cin, priceStr);
    price = stod(priceStr);
    
    names.push_back(name);
    types.push_back(type);
    prices.push_back(price);
    
    ofstream menuFile("menu.txt", ios::app);
    menuFile << name << " " << type << " " << price << endl;
    menuFile.close();
    
    saveToOutput("Добавлено: " + name + " " + type + " " + to_string(price));
}

void searchDish(const vector<string>& names, const vector<string>& types, const vector<double>& prices) {
    string searchName;
    cout << "Введите название блюда для поиска: ";
    getline(cin, searchName);
    
    string result = "Результаты поиска '" + searchName + "':\n";
    bool found = false;
    
    for (size_t i = 0; i < names.size(); i++) {
        if (names[i] == searchName) {
            result += names[i] + " " + types[i] + " " + to_string(prices[i]) + "\n";
            found = true;
        }
    }
    
    if (!found) {
        result += "Блюдо не найдено\n";
    }
    
    cout << result;
    saveToOutput(result);
}

void sortDishes(vector<string>& names, vector<string>& types, vector<double>& prices) {
    string choiceStr;
    cout << "Сортировка по: 1 - типу, 2 - цене: ";
    getline(cin, choiceStr);
    int choice = stoi(choiceStr);
    
    for (size_t i = 0; i < names.size() - 1; i++) {
        for (size_t j = 0; j < names.size() - i - 1; j++) {
            bool needSwap = false;
            if (choice == 1 && types[j] > types[j + 1]) {
                needSwap = true;
            } else if (choice == 2 && prices[j] > prices[j + 1]) {
                needSwap = true;
            }
            
            if (needSwap) {
                swap(names[j], names[j + 1]);
                swap(types[j], types[j + 1]);
                swap(prices[j], prices[j + 1]);
            }
        }
    }
    
    writeDataToFile(names, types, prices);
    
    string result = "Сортировка завершена. Критерий: " + to_string(choice) + "\n";
    cout << result;
    saveToOutput(result);
}

void outputByPrice(const vector<string>& names, const vector<string>& types, const vector<double>& prices) {
    string priceStr;
    cout << "Введите максимальную цену: ";
    getline(cin, priceStr);
    double maxPrice = stod(priceStr);
    
    string result = "Блюда с ценой до " + to_string(maxPrice) + ":\n";
    bool found = false;
    
    for (size_t i = 0; i < names.size(); i++) {
        if (prices[i] <= maxPrice) {
            result += names[i] + " " + types[i] + " " + to_string(prices[i]) + "\n";
            found = true;
        }
    }
    
    if (!found) {
        result += "Блюда не найдены\n";
    }
    
    cout << result;
    saveToOutput(result);
}

int main() {
    vector<string> names, types;
    vector<double> prices;
    
    readDataFromFile(names, types, prices);
    
    string choiceStr;
    int choice;
    
    do {
        cout << "\n1. Добавить блюдо\n";
        cout << "2. Поиск блюда\n";
        cout << "3. Сортировка блюд\n";
        cout << "4. Вывод по цене\n";
        cout << "0. Выход\n";
        cout << "Выбор: ";
        getline(cin, choiceStr);
        choice = stoi(choiceStr);
        
        switch (choice) {
            case 1: addDish(names, types, prices); break;
            case 2: searchDish(names, types, prices); break;
            case 3: sortDishes(names, types, prices); break;
            case 4: outputByPrice(names, types, prices); break;
            case 0: cout << "Выход\n"; break;
            default: cout << "Неверный выбор\n";
        }
    } while (choice != 0);
    
    return 0;
}


//Задание

// #include <iostream>
// using namespace std;
// int main() {
// 	const int Len = 10;
// 	int Ls[Len];
// 	for (int i = 0; i < Len; i++) {
// 		cout << "Введите число " << i+1 << ": ";
// 		cin >> Ls[i];
// 	}
// 	cout << "Массив:";
// 	for (int i = 0; i < Len;i++){
// 		cout << Ls[i] << " ";
// 	}
// 	cout << endl;
// 	double Sum = 0;
// 	for (int i = 0; i < Len; i++) {
// 		Sum += Ls[i];
// 	}
// 	cout << "Сумма чисел массива:" << Sum << endl;
// 	double Min = 99999999999999999;
// 	for (int i = 0; i < Len; i++) {
// 		if (Ls[i] < Min) {
// 			Min = Ls[i];
// 		}
// 	}
// 	cout << "Минимальное число массива:" << Min << endl;
// 	for (int i = 0; i < Len; i++) {
// 		for (int j = 0; j < Len-1;j++){
// 			if (Ls[j] > Ls[j+1]){
// 				int R = Ls[j];
// 				Ls[j] = Ls[j+1];
// 				Ls[j+1] = R;
// 			}
// 		}
// 	}
// 	cout << "Сортированный массив:";
// 	for (int i = 0; i < Len;i++) {
// 		cout << Ls[i] << " ";
// 	}
// }
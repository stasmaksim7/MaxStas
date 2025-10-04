// Задачи 2 по ОАиП

// Задание 1
// #include <iostream>
// using namespace std;
// #include <cmath>
// int main(){
// 	int Len = 0;
// 	cout << "Введите n:";
// 	cin >> Len;
// 	int Ls[Len];
// 	int m = 1;
// 	for (int i = 0; i < Len; i++) {
// 		cout << "Введите " << m << "-ое число:";
// 		cin >> Ls[i];
// 		m++;
// 	}

// 	int k = 0;
// 	cout << "Введите k:";
// 	cin >> k;
// 	int kolvo = 0;
// 	for (int i = 0; i < Len; i++) {
// 		if (Ls[i] > pow(2,k)){
// 			kolvo++;
// 		}
// 	}
// 	cout << "Кол-во уникальных элементов:" << kolvo;
// 	return 0;
// }

// Задание 2
//#include <iostream>
//using namespace std;
//#include <cmath>
//int main() {
//	int Len = 0;
//	cout << "Введите n:";
//	cin >> Len;
//	int Ls[Len];
//	int m = 1;
//	for (int i = 0; i < Len; i++) {
//		cout << "Введите " << m << "-ое число:";
//		cin >> Ls[i];
//		m++;
//	}
//	int Max = 0;
//	int k = 0;
//	for (int i = 0; i < Len; i++) {
//		if (Ls[i] % 2 == 0){
//			k++;
//		}
//		else {
//			if (Ls[i] > Max) {
//				Max = Ls[i];
//			}
//		}
//	}
//	cout << "Кол-во четных:" << k << endl;
//	cout << "Максимальное нечетное:" << Max;
//}

// Задание 3
//#include <iostream>
//using namespace std;
//int main() {
//	int Len = 15;
//	float Ls[Len];
//	float Max = -9999999999999;
//	float Min = 99999999999;
//	int k = 1;
//	for (int i = 0;i < Len;i++){
//		cout << "Введите " << k << "-ое число:" ;
//		cin >> Ls[i];
//		k++;
//	}
//	int nMax = 0;
//	int nMin = 0;
//	for (int i = 0; i < Len;i++) {
//		if (Ls[i] > Max) {
//			Max = Ls[i];
//			nMax = i;
//		}
//		if (Ls[i] < Min) {
//			Min = Ls[i];
//			nMin = i;
//		}
//	}
//	float R1;
//	float R2;
//	R1 = Ls[0];
//	R2 = Ls[14];
//	Ls[0] = Min;
//	Ls[14] = Max;
//	Ls[nMin] = R1;
//	Ls[nMax] = R2;
//	for (int i = 0; i < Len;i++) {
//		cout << Ls[i] << " ";
//	}
//	return 0;
//}

// Задание 4

//#include <iostream>
//using namespace std;
//int main(){
//	int Len = 15;
//	float Ls[Len];
//	int k = 1;
//	for (int i = 0; i < Len;i++) {
//		cout << "Введите " << k << "-ое число:";
//		cin >> Ls[i];
//		k++;
//	}
//	float Max = -999999999999;
//	float Min = 99999999999;
//	int nMax;
//	int nMin;
//	for (int i = 0; i < Len;i++) {
//		if (Ls[i] > Max){
//			Max = Ls[i];
//			nMax = i;
//		}
//		if (Ls[i] < Min) {
//			Min = Ls[i];
//			nMin = i;
//		}
//	}
//	if (nMax < nMin) {
//		cout << "Произведение максимального и минимального числа:" << Min*Max;
//	}
//	else {
//		cout << "Макс. и Мин. не удовлетворяют условию";
//	return 0;
//}

// Задание 5

//#include <iostream>
//using namespace std;
//int main(){
//	int Len = 10;
//	int Ls[Len];
//	int k = 1;
//	for (int i = 0; i < Len;i++) {
//		cout << "Введите " << k << "-ое число:";
//		cin >> Ls[i];
//		k++;
//	}
//	int Max = -99999999999999;
//	int Min = 999999999999;
//	int nMax;
//	int nMin;
//	for (int i = 0; i < Len;i++) {
//		if (Ls[i] > Max) {
//			Max = Ls[i];
//			nMax = i;
//		}
//		if (Ls[i] < Min) {
//			Min = Ls[i];
//			nMin = i;
//		}
//	}
//	if ((nMin == 4) && (nMax == 9)) {
//		cout << "Среднее арифиметическое мин. и макс. :"<<(Max+Min)/2;
//	}
//	else {
//		cout << "Макс. и мин. не удовлетворяют условию";
//	}
//	return 0;
//}

// Задание 6

//#include <iostream>
//using namespace std;
//int main(){
//	int Len = 15;
//	float Ls[Len];
//	int k = 1;
//	for (int i = 0; i < Len;i++){
//		cout << "Введите " << k << "-ое число:";
//		cin >> Ls[i];
//		k++;
//	}
//	float Min = 9999999999;
//	float Max = -9999999999;
//	int nMax;
//	int nMin;
//	for (int i = 0; i < Len;i++) {
//		if (Ls[i] > Max) {
//			Max = Ls[i];
//			nMax = i;
//		}
//		if (Ls[i] < Min) {
//			Min = Ls[i];
//			nMin = i;
//		}
//	}
//	if ((nMin == 1) && (nMax == 0)) {
//		for (int i = 0; i < Len;i++) {
//			Ls[i] = Ls[i]/2;
//		}
//	}
//	else {
//		cout << "Условие не выполняется";
//	}
//	for (int i = 0; i < Len;i++) {
//		cout << Ls[i] << endl;
//	}
//	return 0;
//}

// Задание 7

//#include <iostream>
//using namespace std;
//int main(){
//	int Len = 15;
//	int Ls[Len];
//	int k = 1;
//	for (int i = 0; i < Len;i++) {
//		cout << "Введите " << k << "-ое число:";
//		cin >> Ls[i];
//		k++;
//	}
//	int Max = -9999999;
//	int Min = 9999999;
//	int nMin;
//	int nMax;
//	for (int i = 0; i < Len;i++) {
//		if (Ls[i] > Max){
//			Max = Ls[i];
//			nMax = i;
//		}
//		if (Ls[i] < Min) {
//			Min = Ls[i];
//			nMin = i;
//		}
//	}
//	if ((Max == 0) || (Min == 0)) {
//		for (int  i = 0; i < Len;i++){
//			if (i < nMin){
//				Ls[i] = 0;
//			}
//		}
//		for (int i = 0; i < Len;i++) {
//			cout << Ls[i] << " ";
//		}
//	}
//	else {
//		cout << "Макс. и Мин. не удовл. усл.";
//	}
//	return 0;
//}

// Задание 8
//#include <iostream>
//using namespace std;
//int main(){
//	int Len = 10;
//	int Ls[Len];
//	int k = 1;
//	for (int i = 0; i < Len; i++) {
//		cout << "Введите " << k << "-ое число:";
//		cin >> Ls[i];
//		k++;
//	}
//	int Max = 0;
//	int Min = 999999999;
//	for (int i = 0; i < Len;i++) {
//		if (Ls[i] > Max) {
//			Max = Ls[i];
//		}
//		if (Ls[i] < Min) {
//			Min = Ls[i];
//		}
//	}
//	if ((Ls[1] == Max) && (Ls[4] == Min)){
//		for (int i = 5 ; i < Len; i++) {
//				Ls[i] = Max;
//		}
//		for (int i = 0; i < Len; i++){
//			cout << Ls[i] << " ";
//		}
//	}
//	else {
//		cout << "Макс. и Мин. не удовлетворяют условию";
//	}
//	return 0;
//}
// Задание 9
//#include <iostream>
//using namespace std;
//int main() {
//	int n;
//	cout << "Введите кол-во элементов:";
//	cin >> n;
//	int S = 0;
//	for (int i = 1; i < (n+1); i++) {
//		if ((i % 2 == 0) && (i % 5 == 0)) {
//			S += i;
//		}
//		else if (i % 2 == 0){
//			S += i;
//		}
//		else if (i % 5 == 0){
//			S += i;
//		}
//	}
//	cout << "Сумма всех элементов:" << S;
//	return 0;
//}

// Задание 10
//#include <iostream>
//using namespace std;
//int main(){
//	int a;
//	cout << "Введите число:";
//	cin >> a;
//	if (a == 0) {
//		cout << "Равно нулю";
//	}
//	else if (a > 0){
//		cout << "Полож";
//	}
//	else if (a < 0){
//		cout << "Отриц";
//	}
//	return 0;
//}

// Задание 11
// #include <iostream>
// using namespace std;
// int main() {
// 	int k = 32;
// 	for (char i = ' '; i <= '~';i++) {
// 		cout << k << "-й элемент: "<< i << endl;
// 		k++;
// 	}
// 	return 0;
// }
#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

int rollDice() {
return rand() % 6 + 1;
}

void displayRules() {
cout << "Правила гри \"Кістки\":" << endl;
cout << "1. Гравець називає будь-яке число від 2 до 12 та ставку, яку він робить у цей хід." << endl;
cout << "2. Програма генерує два випадкові кидки кубика та обчислює їх суму." << endl;
cout << "3. Якщо сума чисел менше 7 і гравець задумав число менше 7, він виграє зроблену ставку." << endl;
cout << "4. Якщо сума чисел більше 7 і гравець задумав число більше 7, він також виграє зроблену ставку." << endl;
cout << "5. Якщо гравець вгадав суму чисел, він отримує вчетверо більше очок, ніж зроблена ставка." << endl;
cout << "6. Ставка програна, якщо немає жодної з описаних ситуацій." << endl;
}

void displayStatistics(const vector<string>& players, const vector<int>& scores) {
cout << "Статистика результатів:" << endl;
for (int i = 0; i < players.size(); i++) {
cout << players[i] << ": " << scores[i] << " очок" << endl;
}
}

void saveResults(const vector<string>& players, const vector<int>& scores) {
// Реалізуйте код для збереження результатів гравців у файл
cout << "Результати були збережені." << endl;
}

int main() {
srand(static_cast<unsigned int>(time(0)));

vector<string> players;
vector<int> scores;

int currentPlayer = 0;
int totalPoints = 100;

int choice;
do {
cout << "Меню:" << endl;
cout << "1. Додати гравця" << endl;
cout << "2. Почати гру" << endl;
cout << "3. Переглянути правила гри" << endl;
cout << "4. Переглянути статистику" << endl;
cout << "5. Зберегти результати" << endl;
cout << "6. Вихід" << endl;
cout << "Виберіть опцію: ";
cin >> choice;

switch (choice) {
case 1: {
string playerName;
cout << "Введіть ім'я гравця: ";
cin >> playerName;
players.push_back(playerName);
scores.push_back(totalPoints);
cout << "Гравець " << playerName << " був успішно доданий." << endl;
break;
}
case 2: {
if (players.empty()) {
cout << "Додайте гравця перед початком гри." << endl;
break;
}

int bet;
int targetNumber;
cout << "Введіть вашу ставку: ";
cin >> bet;
cout << "Введіть число, від 2 до 12, яке ви задумали: ";
cin >> targetNumber;

int dice1 = rollDice();
int dice2 = rollDice();
int sum = dice1 + dice2;

cout << "Кидок кубиків: " << dice1 << " + " << dice2 << " = " << sum << endl;

if ((sum < 7 && targetNumber < 7) || (sum > 7 && targetNumber > 7)) {
cout << "Ви виграли ставку!" << endl;
int pointsEarned = bet;
if (sum == targetNumber) {
pointsEarned *= 4;
cout << "Ви вгадали суму чисел! Ви отримуєте " << pointsEarned << " очок!" << endl;
}
scores[currentPlayer] += pointsEarned;
} else {
cout << "Ви програли ставку." << endl;
scores[currentPlayer] -= bet;
}
currentPlayer = (currentPlayer + 1) % players.size();
break;
}
case 3: {
displayRules();
break;
}
case 4: {
displayStatistics(players, scores);
break;
}
case 5: {
saveResults(players, scores);
break;
}
case 6: {
cout << "Дякую за гру! До побачення!" << endl;
break;
}
default:
cout << "Невірний вибір. Спробуйте ще раз." << endl;
}

cout << endl;
} while (choice != 6);

return 0;
}

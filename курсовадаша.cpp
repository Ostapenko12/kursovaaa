#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <locale.h>
using namespace std;

int rollDice() {
    return rand() % 6 + 1;
}

void displayRules() {
    cout << "������� ��� \"ʳ����\":" << endl;
    cout << "1. ������� ������ ����-��� ����� �� 2 �� 12 �� ������, ��� �� ������ � ��� ���." << endl;
    cout << "2. �������� ������ ��� �������� ����� ������ �� �������� �� ����." << endl;
    cout << "3. ���� ���� ����� ����� 7 � ������� ������� ����� ����� 7, �� ����� �������� ������." << endl;
    cout << "4. ���� ���� ����� ����� 7 � ������� ������� ����� ����� 7, �� ����� ����� �������� ������." << endl;
    cout << "5. ���� ������� ������ ���� �����, �� ������ �������� ����� ����, �� �������� ������." << endl;
    cout << "6. ������ ��������, ���� ���� ����� � �������� ��������." << endl;
}

void displayStatistics(const vector<string>& players, const vector<int>& scores) {
    cout << "���������� ����������:" << endl;
    for (int i = 0; i < players.size(); i++) {
        cout << players[i] << ": " << scores[i] << " ����" << endl;
    }
}

void saveResults(const vector<string>& players, const vector<int>& scores) {
    // ��������� ��� ��� ���������� ���������� ������� � ����
    cout << "���������� ���� ��������." << endl;
}

int main() {
	setlocale(LC_CTYPE, "ukr");
    srand(static_cast<unsigned int>(time(0)));

    vector<string> players;
    vector<int> scores;

    int currentPlayer = 0;
    int totalPoints = 100;

    int choice;
    do {
        cout << "����:" << endl;
        cout << "1. ������ ������" << endl;
        cout << "2. ������ ���" << endl;
        cout << "3. ����������� ������� ���" << endl;
        cout << "4. ����������� ����������" << endl;
        cout << "5. �������� ����������" << endl;
        cout << "6. �����" << endl;
        cout << "������� �����: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string playerName;
                cout << "������ ��'� ������: ";
                cin >> playerName;
                players.push_back(playerName);
                scores.push_back(totalPoints);
                cout << "������� " << playerName << " ��� ������ �������." << endl;
                break;
            }
            case 2: {
                if (players.empty()) {
                    cout << "������� ������ ����� �������� ���." << endl;
                    break;
                }

                int bet;
                int targetNumber;
                cout << "������ ���� ������: ";
                cin >> bet;
                cout << "������ �����, �� 2 �� 12, ��� �� ��������: ";
                cin >> targetNumber;

                int dice1 = rollDice();
                int dice2 = rollDice();
                int sum = dice1 + dice2;

                cout << "����� ������: " << dice1 << " + " << dice2 << " = " << sum << endl;

                if ((sum < 7 && targetNumber < 7) || (sum > 7 && targetNumber > 7)) {
                    cout << "�� ������� ������!" << endl;
                    int pointsEarned = bet;
                    if (sum == targetNumber) {
                        pointsEarned *= 4;
                        cout << "�� ������� ���� �����! �� �������� " << pointsEarned << " ����!" << endl;
                    }
                    scores[currentPlayer] += pointsEarned;
                } else {
                    cout << "�� �������� ������." << endl;
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
                cout << "����� �� ���! �� ���������!" << endl;
                break;
            }
            default:
                cout << "������� ����. ��������� �� ���." << endl;
        }

        cout << endl;
    } while (choice != 6);

    return 0;
}

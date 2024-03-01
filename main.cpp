#include <iostream>
#include <algorithm>
#include <random>
#include <unordered_set>

using namespace std;

void reverseWord(string word) {
    reverse(word.begin(), word.end());
    cout << "Слово задом наперед: " << word << endl;
}

void removeVowels(string word) {
    vector<char> vowels = {'a', 'e', 'i', 'o', 'u',
                           'A', 'E', 'I', 'O', 'U'};

    for (int i = 0; i < word.length(); i++)
    {
        if (find(vowels.begin(), vowels.end(),
                 word[i]) != vowels.end())
        {
            word = word.replace(i, 1, "");
            i -= 1;
        }
    }
    cout << "Слово без гласных: " << word << endl;
}

void removeConsonants(string word) {
    vector<char> vowels = { 'a', 'e', 'i', 'o', 'u',
                            'A', 'E', 'I', 'O', 'U' };

    unordered_set<char> set;

    set.insert(vowels.begin(), vowels.end());

    for (int i = 0; i < word.length(); i++) {

        if (set.find(word[i]) == set.end()) {
            word.replace(i, 1, "");
            i--;
        }
    }
    cout << "Слово без согласных: " << word << endl;
}

void shuffleWord(string word) {
    shuffle(word.begin(), word.end(), mt19937(random_device()()));
    cout << "Рандомно раскиданные буквы: " << word << endl;
}

int main() {
    system("chcp 65001");

    int choice;
    char word[37];
    cout << "Напишите слово (на Английском!):" << endl;
    cin.getline(word, 37);

    while(true){
        cout << "Выберите операцию:\n"
                "\t1. Слово выводится задом наперед\n"
                "\t2. Вывести слово без гласных\n"
                "\t3. Вывести слово без согласных\n"
                "\t4. Рандомно раскидывать буквы заданного слова\n"
                "\tЕсли вы хотите выйти нажмите - \"5\"\n"
                "Операция: " << endl;
        cin >> choice;

        switch(choice) {
            case 1:
                reverseWord(word);
                break;
            case 2:
                removeVowels(word);
                break;
            case 3:
                removeConsonants(word);
                break;
            case 4:
                shuffleWord(word);
                break;
            case 5:
                exit(0);
            default:
                cout << "Такого выбора не существует..." << endl;
                break;
        }
    }
}
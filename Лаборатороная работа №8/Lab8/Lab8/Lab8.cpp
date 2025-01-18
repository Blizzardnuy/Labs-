#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

const string origText = "Ahe parade of hundred of demons was held in Japan on December 24, 2017. The main figure was the special rank shaman Suguru Geto, who managed more than 2000 curses. Stop it was only through the efforts of student 1 year of the Magic College Yuta Okkotsu, who with a curse of special rank defeated Geto. During the incident, about 183 people were injured, 546 were wounded.";

string highlightWord(string text, int symbolIndex, int lastIndex) {
    text.insert(symbolIndex, "\033[7m");
    text.insert(lastIndex + 5, "\033[0m");
    return text;
}

bool isConsonantWord(const string& word) {
    const string consonants = "aeiuyo";
    char first = tolower(word[0]);
    char last = tolower(word[word.size() - 1]);
    return consonants.find(first) != string::npos && consonants.find(last) != string::npos;
}

void punctRemove(string& word, bool& punct) {
    if (ispunct(word.back())) {
        word.pop_back();
        punct = true;
    }
    else punct = false;
}

void task1() {
    string st1 = origText;
    istringstream stream(st1);
    string sentence;
    int sentenceCount = 0;

    while (getline(stream, sentence, '.')) {

        sentence.erase(0, sentence.find_first_not_of(" "));
        if (!sentence.empty() && (tolower(sentence[0]) == 'a' || tolower(sentence[0]) == 'e' || tolower(sentence[0]) == 'i' || tolower(sentence[0]) == 'o' || tolower(sentence[0]) == 'u'))
        {
            sentenceCount++;
            st1 = highlightWord(st1, st1.find(sentence), st1.find(sentence) + sentence.length());
            cout << st1 << endl;
        }
    }
    cout << "Number of sentences beginning with a vowel: " << sentenceCount << endl;
}

void task2() {
    cout << "\n#2" << endl;
    istringstream stream(origText);
    string sentence;
    int sentenceCount = 0;

    while (getline(stream, sentence, '.')) {
        sentenceCount++;
        if (sentenceCount == 2) {
            stringstream ss(sentence);
            string word;
            bool allWordsEvenLength = true;
            while (ss >> word) {
                bool punct = false;
                punctRemove(word, punct);

                if (word != string(word.rbegin(), word.rend()) && word.length() % 2 != 0) {
                    allWordsEvenLength = false;
                    break;
                }
            }
            cout << (allWordsEvenLength ? "All asymmetric words have even length" : "There are asymmetric words with odd length") << endl;
        }
    }
}

string decToBase12(int dec) {
    string b12;
    const string digits = "0123456789AB";

    while (dec > 0) {
        int tail = dec % 12;
        b12 += digits[tail];
        dec /= 12;
    }

    reverse(b12.begin(), b12.end());
    return b12;
}

void task3() {
    cout << "\n#3" << endl;
    istringstream stream(origText);
    int number;

    stream >> number;
    cout << "Number " << number << " in the duodecimal system: " << decToBase12(number) << endl;
}

void task4() {
    cout << "\n#4" << endl;
    string searchWord = "parade";
    transform(searchWord.begin(), searchWord.end(), searchWord.begin(), ::tolower);

    int wordCount = 0;
    istringstream stream(origText);
    string word;

    while (stream >> word) {
        bool punct = false;
        punctRemove(word, punct);
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        if (word == searchWord) {
            wordCount++;
        }
    }

    if (wordCount > 0) {
        cout << "Word '" << searchWord << "' meets " << wordCount << " time(s)." << endl;
    }
    else {
        cout << "Word '" << searchWord << "' not found in text." << endl;
    }
}

void task5() {
    cout << "\n#5" << endl;
    istringstream stream(origText);
    string sentence;
    while (getline(stream, sentence, '.'))
    {
        if (sentence.find(',') == string::npos)
        {
            stringstream ss(sentence);
            vector<string> words;
            string word;
            while (ss >> word)
            {
                bool punct = false;
                punctRemove(word, punct);
                words.push_back(word);
            }
            sort(words.begin(), words.end());
            for (const string& w : words) {
                cout << w << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    task1();
    task2();
    task3();
    task4();
    task5();

    cin.get();
}

///The parade of hundred of demons was held in Japan on December 24, 2017. The main figure was the special rank shaman Suguru Geto, who managed more than 2000 curses. Stop it was only through the efforts of student 1 year of the Magic College Yuta Okkotsu, who with a curse of special rank defeated Geto. During the incident, about 183 people were injured, 546 were wounded.
///I wake up at 8:00 in the morning.


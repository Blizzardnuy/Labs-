#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Book {
    string author;    
    string title;     
    string publisher;  
    int year;          
    int pages;        
};

void inputBook(Book& b) {
    setlocale(0, "");
    cout << "Введите Ф.И.О. автора: ";
    getline(cin, b.author);  

    cout << "Введите название книги: ";
    getline(cin, b.title);  

    cout << "Введите издательство: ";
    getline(cin, b.publisher); 

    cout << "Введите год издания: ";
    cin >> b.year;  
    cin.ignore();   

    cout << "Введите количество страниц: ";
    cin >> b.pages; 
    cin.ignore();   
}

void printBook(const Book& b) {
    setlocale(0, "");
    cout << "Автор: " << b.author << endl;
    cout << "Название: " << b.title << endl;
    cout << "Издательство: " << b.publisher << endl;
    cout << "Год издания: " << b.year << endl;
    cout << "Количество страниц: " << b.pages << endl;
}

void saveBooksToFile(const string& filename, const Book* books, int count) {
    setlocale(0, "");
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Ошибка при открытии файла для записи!" << endl;
        return;
    }
    outFile.write(reinterpret_cast<const char*>(&count), sizeof(count)); 
    outFile.write(reinterpret_cast<const char*>(books), sizeof(Book) * count);
    outFile.close();
}

Book* loadBooksFromFile(const string& filename, int& count) {
    setlocale(0, "");
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        cerr << "Ошибка при открытии файла для чтения!" << endl;
        return nullptr;
    }
    inFile.read(reinterpret_cast<char*>(&count), sizeof(count)); 
    Book* books = new Book[count]; 
    inFile.read(reinterpret_cast<char*>(books), sizeof(Book) * count); 
    inFile.close();
    return books;
}

int main() {
    int n;
    setlocale(0, "");
    cout << "Сколько книг вы хотите ввести? ";
    cin >> n;
    cin.ignore();

    Book* books = new Book[n];

    for (int i = 0; i < n; ++i) {
        cout << "\nВведите данные для книги " << i + 1 << ":\n";
        inputBook(books[i]);
    }

   
    string filename = "books.dat";
    saveBooksToFile(filename, books, n);
    cout << "\nДанные сохранены в файл \"" << filename << "\".\n";

    
    int loadedCount = 0;
    Book* loadedBooks = loadBooksFromFile(filename, loadedCount);

    if (loadedBooks != nullptr) {
        cout << "\nЗагруженные книги:\n";
        for (int i = 0; i < loadedCount; ++i) {
            cout << "\nКнига " << i + 1 << ":\n";
            printBook(loadedBooks[i]);
        }

        delete[] loadedBooks;
    }

    delete[] books; 

    return 0;
}


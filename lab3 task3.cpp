
#include <iostream>
using namespace std;

class LibraryItem {
public:
    virtual void display() = 0;
    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
    char title[100];
    char author[100];
    int pages;

public:
    Book() {
        title[0] = '\0';
        author[0] = '\0';
        pages = 0;
    }

    Book(const char t[], const char a[], int p) {
        int i = 0;

        while (t[i] != '\0' && i < 99) {
            title[i] = t[i];
            i++;
        }
        title[i] = '\0';

        i = 0;
        while (a[i] != '\0' && i < 99) {
            author[i] = a[i];
            i++;
        }
        author[i] = '\0';

        pages = p;
    }

    void display() override {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Pages: " << pages << endl;
    }

    int getPages() const {
        return pages;
    }

    const char* getTitle() const {
        return title;
    }
};

class Newspaper : public LibraryItem {
    char name[100];
    char date[20];
    char edition[50];

public:
    Newspaper() {
        name[0] = '\0';
        date[0] = '\0';
        edition[0] = '\0';
    }

    Newspaper(const char n[], const char d[], const char e[]) {
        int i = 0;

        while (n[i] != '\0' && i < 99) {
            name[i] = n[i];
            i++;
        }
        name[i] = '\0';

        i = 0;
        while (d[i] != '\0' && i < 19) {
            date[i] = d[i];
            i++;
        }
        date[i] = '\0';

        i = 0;
        while (e[i] != '\0' && i < 49) {
            edition[i] = e[i];
            i++;
        }
        edition[i] = '\0';
    }

    void display() override {
        cout << "Newspaper: " << name << endl;
        cout << "Date: " << date << endl;
        cout << "Edition: " << edition << endl;
    }

    const char* getName() const {
        return name;
    }

    const char* getEdition() const {
        return edition;
    }
};

template <class T>
void linearSearch(T arr[], int size, const char key[],
    const char* (T::* getValue)() const) {
    for (int i = 0; i < size; i++) {
        const char* value = (arr[i].*getValue)();
        int j = 0;

        while (value[j] == key[j] && value[j] != '\0') {
            j++;
        }

        if (value[j] == '\0' && key[j] == '\0') {
            arr[i].display();
            return;
        }
    }

    cout << "Item not found." << endl;
}

template <class T>
void binarySearch(T arr[], int size, const char key[],
    const char* (T::* getValue)() const) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        const char* value = (arr[mid].*getValue)();

        int i = 0;
        while (value[i] == key[i] && value[i] != '\0') {
            i++;
        }

        if (value[i] == '\0' && key[i] == '\0') {
            arr[mid].display();
            return;
        }

        if (value[i] < key[i]) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    cout << "Item not found." << endl;
}

class Library {
    Book books[100];
    Newspaper newspapers[100];
    int bookCount;
    int newspaperCount;

public:
    Library() {
        bookCount = 0;
        newspaperCount = 0;
    }

    void addBook(const Book& book) {
        if (bookCount < 100) {
            books[bookCount++] = book;
        }
    }

    void addNewspaper(const Newspaper& newspaper) {
        if (newspaperCount < 100) {
            newspapers[newspaperCount++] = newspaper;
        }
    }

    void displayCollection() {
        cout << "\nBooks:\n";

        for (int i = 0; i < bookCount; i++) {
            books[i].display();
            cout << endl;
        }

        cout << "Newspapers:\n";

        for (int i = 0; i < newspaperCount; i++) {
            newspapers[i].display();
            cout << endl;
        }
    }

    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++) {
            for (int j = 0; j < bookCount - i - 1; j++) {
                if (books[j].getPages() > books[j + 1].getPages()) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++) {
            for (int j = 0; j < newspaperCount - i - 1; j++) {
                const char* a = newspapers[j].getEdition();
                const char* b = newspapers[j + 1].getEdition();
                int k = 0;

                while (a[k] == b[k] && a[k] != '\0') {
                    k++;
                }

                if (a[k] > b[k]) {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
            }
        }
    }

    Book* searchBookByTitle(const char title[]) {
        for (int i = 0; i < bookCount; i++) {
            const char* value = books[i].getTitle();
            int j = 0;

            while (value[j] == title[j] && value[j] != '\0') {
                j++;
            }

            if (value[j] == '\0' && title[j] == '\0') {
                return &books[i];
            }
        }

        return nullptr;
    }

    Newspaper* searchNewspaperByName(const char name[]) {
        for (int i = 0; i < newspaperCount; i++) {
            const char* value = newspapers[i].getName();
            int j = 0;

            while (value[j] == name[j] && value[j] != '\0') {
                j++;
            }

            if (value[j] == '\0' && name[j] == '\0') {
                return &newspapers[i];
            }
        }

        return nullptr;
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook != nullptr) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");

    if (foundNewspaper != nullptr) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    cout << "\nTemplate Linear Search - Book:\n";
    linearSearch(books_placeholder, 0, "", &Book::getTitle);

    return 0;
}

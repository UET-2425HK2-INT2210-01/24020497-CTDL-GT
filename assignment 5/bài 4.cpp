#include <iostream>

using namespace std;
struct Student {
    int ID;
    string Name;
    string Class;
    Student* next;
};
class Hash {
public:
    int number_student=0;
    Student* table[773];
    int hash_function(int ID) {
        return ID % 773;
    }
    Hash() {
        for (int i = 0; i < 773; i++) {
            table[i] = nullptr;
        }
    }
    void Insert(int ID,string Name ,string Class) {
        int index = hash_function(ID);
        Student* newStudent = new Student{ ID, Name, Class, table[index] };
        table[index] = newStudent;
        number_student++;
    }
    void Delete(int ID) {
        int index = hash_function(ID);
        Student* current = table[index];
        while (current->next != nullptr) {
            if (current->ID == ID) {
                table[index]=current->next;
                delete current;
                return;
            }
            current = current->next;
        }
        number_student--;
    }
    void Infor(int ID) {
        int index = hash_function(ID);
        Student* wanted = table[index];
        while (wanted != nullptr) {
            if (wanted->ID == ID) {
                cout << wanted->Name << " " << wanted->Class;
            }
            wanted = wanted->next;
        }
        cout << "N/A" << " " << "N/A";
    }
};
int main() {
    Hash school;
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s == "Insert(") {
            int ID;
            string Name;
            string Class;
            cin >> ID >> Name >> Class;
            school.Insert(ID, Name, Class);
        }
        else if (s == "Delete(") {
            int ID;
            cin >> ID ;
            school.Delete(ID);
        }
        else if (s == "Infor(") {
            int ID;
            cin >> ID;
            school.Infor(ID);
        }
    }
}

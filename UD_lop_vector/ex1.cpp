
#include <bits/stdc++.h>

using namespace std;

class Contact{
    string name, tel, mail;
public:
    Contact();
    Contact(string name, string tel, string mail){
        this->name = name; this->tel = tel; this->mail = mail;
    }
    void show_contact(){
        cout << "Name: " << name << ", tel: " << tel << ", mail: "  << mail << ".\n";
    }
    string get_name(){return name;}
    string get_tel(){return tel;}
    string get_mail(){return mail;}
};

class AddressBook{
    vector<Contact> contacts;
public:
    void addContact(Contact& contact) {
        contacts.push_back(contact);
    }
    void deleteContact(string tel){
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].get_tel() == tel) {
                contacts.erase(contacts.begin() + i);
                break;
            }
        }
    }  
    void searchContact(string tel) {
        for (int i = 0; i < contacts.size(); i++) {
            if (contacts[i].get_tel() == tel) {
                contacts[i].show_contact();
            }
        }
    }
    void displayAllContacts() {
        for (int i = 0; i < contacts.size(); i++) {
                contacts[i].show_contact();
        }
    }
};

int main(){

    AddressBook addressBook;

    while (true) {
        cout << "1. Thêm liên hệ mới" << endl;
        cout << "2. Xóa liên hệ" << endl;
        cout << "3. Tìm kiếm liên hệ" << endl;
        cout << "4. Hiển thị danh sách liên hệ" << endl;
        cout << "5. Thoát" << endl;

        int choice;
        cout << "Chọn tùy chọn: ";
        cin >> choice;

        if (choice == 1) {
            string name, phone, email;
            cin.ignore(); // Để xóa ký tự Enter còn lại sau khi nhập lựa chọn
            cout << "Nhập tên: ";
            getline (cin, name);
            cout << "Nhập số điện thoại: ";
            getline (cin, phone);
            cout << "Nhập email: ";
            getline (cin, email);

            Contact contact(name, phone, email);
            addressBook.addContact(contact);
        } else if (choice == 2) {
            string phone;
            cout << "Nhập số điện thoại của liên hệ cần xóa: ";
            cin >> phone;
            addressBook.deleteContact(phone);
        } else if (choice == 3) {
            string phone;
            cout << "Nhập số điện thoại của liên hệ cần tìm: ";
            cin >> phone;
            addressBook.searchContact(phone);
        } else if (choice == 4) {
            addressBook.displayAllContacts();
        } else if (choice == 5) {
            break;
        } else {
            cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." <<  endl;
        }
    }

    return 0;
}
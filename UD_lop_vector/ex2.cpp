
#include<bits/stdc++.h>

using namespace std;

class Document{
    string ten_tai_lieu, mo_ta, ten_tac_gia, dinh_dang_tai_lieu;
    int nam_san_xuat;
public:
    Document(){}
    Document(string ten_tai_lieu,string mo_ta,string ten_tac_gia,string dinh_dang_tai_lieu, int nam_san_xuat){
        this->ten_tac_gia = ten_tac_gia; this->ten_tai_lieu = ten_tai_lieu; this->mo_ta = mo_ta; this->dinh_dang_tai_lieu = dinh_dang_tai_lieu; this->nam_san_xuat = nam_san_xuat;
    }
    void show_document(){
        cout << "Ten tai lieu: " << ten_tai_lieu << ", mo ta tai lieu: " << mo_ta << ", ten tac gia: " << ten_tac_gia << ", dinh dang: " << dinh_dang_tai_lieu << ", nam san xuat: " << nam_san_xuat << ".\n";
    }
    string get_ten_tai_lieu(){
        return ten_tai_lieu;
    }
};  
class Folder{
    string ten_thu_muc;
    vector<Document> documents;
public: 
    Folder(){}
    Folder(string t){
        ten_thu_muc = t;
    }
    void set_name(string name){
        ten_thu_muc = name;
    }
    void add_Document(Document d){
        documents.push_back(d);
    }
    void del_Document(string ten_tai_lieu){
        for (int i = 0; i < documents.size(); i++){
            if (documents[i].get_ten_tai_lieu() == ten_tai_lieu){
                documents.erase(documents.begin() + i);
                break;
            }
        }
    }
    void show_Folder(){
        for (int i = 0; i < documents.size(); i++){
            documents[i].show_document();
        }
    }
    string get_ten_thu_muc(){
        return ten_thu_muc;
    }
};  
class User{
    string name_user;
    vector<Folder> users;
public:
    void set_name(string name){
        name_user = name;
    }
    void add_Folder(Folder f){
        users.push_back(f);
    }
    void del_Folder(string ten_tai_lieu){
        for (int i = 0; i < users.size(); i++){
            if (users[i].get_ten_thu_muc() == ten_tai_lieu){
                users.erase(users.begin() + i);
                break;
            }
        }
    }
    void show_User(){
        for (int i = 0; i < users.size(); i++){
            users[i].show_Folder();
        }
    }
};  

void menu(){
    while(true){
        Folder f;
        User u;
        cout << "--------------------------------\n";
        cout << "1. Thêm thư mục mới vào danh sách thư mục của người dùng" << endl;
        cout << "2. Thêm tài liệu mới vào một thư mục của người dùng" << endl;
        cout << "3. Xóa thư mục khỏi danh sách thư mục của người dùng" << endl;
        cout << "4. Xóa tài liệu khỏi thư mục của người dùng" << endl;
        cout << "5. Hiển thị danh sách thư mục của người dùng" << endl;
        cout << "6. Hiển thị danh sách tài liệu trong thư mục của người dùng" << endl;
        cout << "7. Thoát" << endl;
        cout << "--------------------------------\n";

        int choice;
        cout << "Chọn tùy chọn: ";
        cin >> choice;
        
        if (choice == 1) {
            string ten_thu_muc;

            cout << "Nhập tên thư mục: ";
            getline(cin, ten_thu_muc);
            cin.ignore();

            f.set_name(ten_thu_muc);
        } else if (choice == 2) {
            string ten_tai_lieu, mo_ta, ten_tac_gia, dinh_dang_tai_lieu;
            int nam_san_xuat;
            cin.ignore(); 
            cout << "Nhập tên tài liệu: ";
            getline (cin, ten_tai_lieu);
            cin.ignore(); 

            cout << "Nhập mô tả tài liệu: ";
            getline (cin, mo_ta);
            cin.ignore(); 
            
            cout << "Nhập tên tác giả: ";
            getline (cin, ten_tac_gia);
            cin.ignore();

            cout << "Nhập định dạng tài liệu: ";
            getline (cin, dinh_dang_tai_lieu);
            cin.ignore();
            
            cout << "Nhập năm xuất bản: ";
            cin >> nam_san_xuat;
            cin.ignore(); 
            Document dcm(ten_tai_lieu, mo_ta, ten_tac_gia, dinh_dang_tai_lieu, nam_san_xuat);
            f.add_Document(dcm);
        } else if (choice == 3) {
            string t;
            cout << "Nhập tên thư mục cần xoá: ";
            cin.ignore();
            getline(cin, t);
            u.del_Folder(t);
        } else if (choice == 4){
            string t;
            cout << "Nhập tên tài liệu cần xoá: ";
            cin.ignore();
            getline(cin, t);
            f.del_Document(t);
        } else if (choice == 5){
            u.show_User();
        } else if (choice == 6){
            f.show_Folder();
        } else if (choice == 7){
            break;
        } else {
            cout << "Vui lòng nhập lại yêu cầu !!!" << endl;
        }
    }
}

Folder f();
User u;

int main(){

    menu();

    return 0;
}
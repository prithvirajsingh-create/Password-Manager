#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Contact{
    string app;
    string username;
    string password;
public:
    void addPass(){
        cout<<"Enter App name: ";
        cin>>app;
        cout<<"Enter Username: ";
        cin>>username;
        cout<<"Enter Password: ";
        cin>>password;
    }

    void showApp(){
        cout<<"App: "<<app<<endl;
        cout<<"Username: "<<username<<endl;
        cout<<"Password: "<<password<<endl;
    }

    string getName(){ return app; }
    string getPhone(){ return username; }
    string getEmail(){ return password; }

    void saveToFile(){
        ofstream file;
        file.open("Passwords.txt", ios::app);
        file<<app<<" "<<username<<" "<<password<<"\n";
        file.close();
    }
};

void showAllPasswords(){
    ifstream file("Passwords.txt");
    if(!file){
        cout<<"No Passwords found!\n";
        return;
    }
    string app,username,password;
    while(file>>app>>username>>password){
        cout<<"----------------------\n";
        cout<<"App name: "<<app<<"\n";
        cout<<"Username: "<<username<<"\n";
        cout<<"Passwords: "<<password<<"\n";
    }
    file.close();
}

void searchPass(){
    string search;
    cout<<"Enter app to search: ";
    cin>>search;
    ifstream file("Passwords.txt");
    if(!file){
        cout<<"No file found!\n";
        return;
    }
    string app,username,password;
    int found=0;
    while(file>>app>>username>>password){
        if(app==search){
            cout<<"Pass Found!\n";
            cout<<"App name: "<<app<<"\n";
            cout<<"Username: "<<username<<"\n";
            cout<<"Password: "<<password<<"\n";
            found=1;
        }
    }
    if(found==0){
        cout<<"No app found with that name!\n";
    }
    file.close();
}

void deletePass(){
    string search;
    cout<<"Enter app to delete: ";
    cin>>search;
    ifstream file("Passwords.txt");
    ofstream temp("temp.txt");
    string name,phone,email;
    int found=0;
    while(file>>name>>phone>>email){
        if(name!=search){
            temp<<name<<" "<<phone<<" "<<email<<"\n";
        } else {
            found=1;
        }
    }
    file.close();
    temp.close();
    remove("Passwords.txt");
    rename("temp.txt","passwords.txt");
    if(found)
        cout<<"Pass Deleted Successfully!\n";
    else
        cout<<"No app Found!\n";
}

int main(){
    int choice;
    while(true){
        cout<<"\n====== Password Management System ======\n";
        cout<<"1. Add Password\n";
        cout<<"2. View All Passwords\n";
        cout<<"3. Search Password\n";
        cout<<"4. Delete Password\n";
        cout<<"5. Exit\n";
        cout<<"Enter choice: ";
        cin>>choice;

        if(choice==1){
            Contact c;
            c.addPass();
            c.saveToFile();
            cout<<"Password Saved!\n";
        }
        else if(choice==2){
            showAllPasswords();
        }
        else if(choice==3){
            searchPass();
        }
        else if(choice==4){
            deletePass();
        }
        else if(choice==5){
            cout<<"Exiting...\n";
            break;
        }
        else{
            cout<<"Invalid Option!\n";
        }
    }
    return 0;
}

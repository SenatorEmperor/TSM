#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <limits>
using namespace std;

void show(){
    cout<<"\n[ Shortcuts ]:\n";
    int i=1;
    string lineName, lineLink;
    ifstream names("names.txt");
    ifstream links("links.txt");
    while(getline(names, lineName), getline(links, lineLink)){
        cout<<i<<'.'<<lineName<<" - "<<lineLink<<endl;
        i++;
    }
    names.close();
}

void del(){
    show();
    int number, i=1;
    char choice;
    string line1, line2, newName, newLink, filename1, filename2;
    filename1 = "names.txt";
    filename2 = "links.txt";

    cout<<"Enter the number of shortcut that you want to delete: ";
    cin>>number;

    ifstream file1("names.txt");
    ofstream f1Temp("f1Temp.txt", ios::app);
    ifstream file2("links.txt");
    ofstream f2Temp("f2Temp.txt", ios::app);
    while(getline(file1, line1), getline(file2, line2)){
        if(i==number){
            i++;//added
            continue;
        }
        else{
            f1Temp<<line1<<endl;
            f2Temp<<line2<<endl;
            i++;
        }
    }

    file1.close();
    f1Temp.close();
    remove(filename1.c_str());
    rename("f1Temp.txt", filename1.c_str());
    file2.close();
    f2Temp.close();
    remove(filename2.c_str());
    rename("f2Temp.txt", filename2.c_str());
}

void edit(){
    show();
    int number, i=1;
    char choice;
    string line1, line2, newName, newLink, filename1, filename2;
    filename1 = "names.txt";
    filename2 = "links.txt";

    cout<<"Enter the number of shortcut that you want to edit: ";
    cin>>number;
    cout<<"[*] To edit name, type 'n'.\n";
    cout<<"[*] To edit link, type 'l'.\n";

    while(true){
        cout<<"[ Your choice (edit)]: ";
        cin>>choice;

        if(choice=='n'){
            ifstream file1("names.txt");
            ofstream f1Temp("f1Temp.txt", ios::app);
            while(getline(file1, line1)){
                if(i==number){
                    cout<<"Enter new name: ";
                    cin.ignore();
                    getline(cin, newName);
                    f1Temp<<newName<<endl;
                    i++;
                    continue;
                }
                    f1Temp<<line1<<endl;
                    i++;
            }
            i=1;
            file1.close();
            f1Temp.close();
            remove(filename1.c_str());
            rename("f1Temp.txt", filename1.c_str());
            break;
        }
        else if(choice=='l'){
            ifstream file2("links.txt");
            ofstream f2Temp("f2Temp.txt", ios::app);
            while(getline(file2, line2)){
                if(i==number){
                    cout<<"Enter new link: ";
                    cin.ignore();
                    getline(cin, newLink);
                    f2Temp<<newLink<<endl;
                    i++;
                    continue;
                }
                
                    f2Temp<<line2<<endl;
                    i++;
                
            }
            i=1;
            file2.close();
            f2Temp.close();
            remove(filename2.c_str());
            rename("f2Temp.txt", filename2.c_str());
            break;
        }
        else{
            cout<<"Invalid choice, try again.\n";
        }
    }
}

void add(){
    string sname, slink;//shortcut name, shortcut link;
    cout<<"Enter new shortcut's name: ";
    cin.ignore();//
    getline(cin, sname);
    cout<<"Enter new shortcut's link: ";
    cin>>slink;

    ofstream name("names.txt", ios::app);
    ofstream link("links.txt", ios::app);

    name<<sname<<endl;
    link<<slink<<endl;

    name.close();
    link.close();
}

void menu(){
    char choice;
    cout<<"\nMenu:\n";
    cout<<"[*] To add a new shortcut, type 'a'.\n";
    cout<<"[*] To edit an existing shortcut, type 'e'.\n";
    cout<<"[*] To delete an existing shortcut, type 'd'.\n";
    cout<<"[*] To close the menu, type 'c'.\n";
    while(true){
        cout<<"[ Your choice (menu) ]: ";
        cin>>choice;
        if(choice=='a'){
            choice='\0';
            add();
        }
        else if(choice=='e'){
            choice='\0';
            edit();
        }
        else if(choice=='d'){
            choice='\0';
            del();
        }
        else if(choice=='c'){
            choice='\0';
            return;
        }
        else{
            choice='\0';
            cout<<"Invalid choice, try again.\n";
        }
    }
}

int main(){
    string delf1 = "f1Temp.txt", delf2 = "f2Temp.txt";
    remove(delf1.c_str());
    remove(delf2.c_str());

    cout<<"=>This is a Terminal-Shortcut-Maker by [firex].\n";
    cout<<"You can add, edit and delete shortcuts from menu.\n";
    int number, j=1;
    string url, command;

    while(true){
        show();
        cout<<"\nNumber of shortcut that you want to open(type '0' if you want to open menu): ";

        while (!(cin>>number)) {// Check if there's an error(like user didn't input a number);
            cout << "Invalid input. Please enter a number: ";
            cin.clear(); // Clear the error flag;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the input;
        }

        if(number==0){
            menu();
        }
        else if(number<0){
            number = '\0';
            cout<<"Invalid number try again.\n";
        }
        else{
            ifstream links("links.txt");
            while(getline(links, url)){
                if(number==j){
                    command = "start "+url;
                    system(command.c_str());
                    j=1;
                    break;
                }
                else{
                    j++;
                }
            }
        }
    }


    return 0;
}
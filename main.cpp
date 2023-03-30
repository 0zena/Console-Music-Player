#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

template<typename T>

class Playlist
{
private:
    vector<T> queue;

public:
    void Add(T t) {
        queue.push_back(t);
    }

    void AddReverse(T t) {
        queue.insert(queue.begin(), t);
    }

    void GetPlaylist() {
        int j = 0;
        for (auto i = queue.begin(); i != queue.end(); i++) {
            if (j == 0) { cout << "Now playing: " << *i << endl; ++j; }
            else { cout << ++j << ". Next: " << *i << endl; }
        }
    }

    void Insert() {
        int tmp = 0;
        string name, str_tmp;
        cout << "Please enter amount of Soundtracks:" << endl;
        cin >> tmp;
        cout << "Do you want to add it in front of queue? (y/n)" << endl;
        cin >> str_tmp;
        if (str_tmp == "y") {
            for (int i = 1; i <= tmp; i++) {
                cout << "Please enter name of " << i << " Soundtrack(w/ .wav at the end)" << endl;
                cin >> name;
                AddReverse(name);
            }
        }
        else if (str_tmp == "n") {
            for (int i = 1; i <= tmp; i++) {
                cout << "Please enter name of " << i << " Soundtrack(w/ .wav at the end)" << endl;
                cin >> name;
                Add(name);
            }
        }
        else {
            cout << "Incorrect input" << endl;
        }
    }

    void Menu() {
        cout << "Press 1 to play music" << endl;
        cout << "Press 2 to skip music" << endl;
        cout << "Press 3 to exit program" << endl;
    }

    void Control() {
        int tmp;

        do {
            Menu();
            cout << "Enter your choise" << endl;
            cin >> tmp;
            switch (tmp) {
            case 1: // play 
                Play();
                cout << "" << endl;
                break;
            case 2: //skip 
                system("pause>>nul");
                PlaySoundA(NULL, NULL, 0);
                cout << "" << endl;
                break;
            case 3: cout << "Exit" << endl;// Escape 
                exit(EXIT_SUCCESS);
                break;
            default: cout << "Invalid choice" << endl;
            }
        } while (tmp != 3);
    }

    void Play() {
        while (!queue.empty()) {
            string Path = queue.front();
            GetPlaylist();
            PlaySoundA(Path.c_str(), NULL, SND_ASYNC);
            queue.erase(queue.begin());
            Control();
            cout << "" << endl;
            //system("pause>>nul");
            //PlaySoundA(NULL, NULL, 0);
            system("cls");
        }
    }

    void ClearPlaylist() {
        char answer;
        cout << "Clear your queue y/n?\n-> ";
        cin >> answer;

        if (answer == 'y') {
            queue.clear();
            cout << "Queue cleared!" << endl;
        }
        else {
            cout << "Canceled clear!" << endl;
        }
    }
};


int main() {
    Playlist<string> str_queue;

    str_queue.Add("lol.wav");
    //str_queue.Add("");
    //str_queue.Add("");
    //str_queue.Add("");
    //str_queue.Add("");
    str_queue.Insert();
    str_queue.Control();
    //str_queue.Play();
}

/*
Names: Tyler Zhang + Andrew Sinha
Program Name: Playlist Simulator 
Date: 1/29/25
Extra: 
*/
#include <iostream>
#include <vector>
#include <string>
#include <Windows.h> 
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;
int main() {
    vector<string> song = {"Call Me Maybe", "Fix You", "I Want It That Way", "Heavy is the Crown"};
    vector<string> artist = {"Carly Rae Jepsen", "Coldplay", "Backstreet Boys", "Linkin Park"};
    string songchoice;
    char resp;
    bool run = true;
    int posit = 0;
    string newSong;
    string newArtist;
    do {
        cout << "What would you like to do?" << endl;
        cout << "A) Select a song\nB) Add a song\nC) Play the songs\nD) Play the songs in shuffle mode\nE) Leave" << endl;
        cin >> resp;
        switch (resp) {
            case 'A': {
                cout << "These are the song options currently: " << endl;
                for(string songs : song){
                    cout << songs << endl;
                }

                cout << "What song would you like to play?" << endl;
                cin.ignore();
                getline(cin, songchoice);
                for(string songs: song){
                    if(songs == songchoice){

                        cout << "Now playing: " << songchoice << "\nby: " << artist[posit] << endl;

                    }
                    posit += 1;
                }
                break;
            }
            case 'B': {
                cout << "What song would you like to add to the playlist?" << endl;
                cin.ignore();
                getline(cin, newSong);
                cout << "Who is the artist?" << endl;
                getline(cin, newArtist);
                song.push_back(newSong);
                artist.push_back(newArtist);
                cout << newSong << " by " << newArtist << " has been added to the playlist." << endl;
                break;
            }
            case 'C': {
                PlaySound(TEXT("C:\\Users\\Compsci\\Downloads\\cmm.wav"), NULL, SND_FILENAME | SND_ASYNC);
                break;
            }
            case 'D': {
                break;
            }
            case 'E': {
                run = false;
                break;
            }
            default: {
                // error trap if they don't enter a valid option
                cout << "Invalid choice" << endl;
                break;
            }
        }
    } while (run);
    return 0;
}
/*
Names: Tyler Zhang + Andrew Sinha
Program Name: Playlist Simulator 
Date: 1/29/25
Extra: Find minimum element in vector
*/
#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <ctime>
#include <algorithm>
using namespace std;
int main() {
    srand(time(nullptr));
    vector<string> song = {"Call Me Maybe", "Fix You", "I Want It That Way", "Car Crash"};
    vector<string> artist = {"Carly Rae Jepsen", "Coldplay", "Backstreet Boys", "eaJ"};
    string songchoice;
    char resp;
    bool run = true;
    int posit = 0;
    string newSong;
    string newArtist;
    do {
        cout << "What would you like to do?" << endl;
        cout << "A) Select a song\nB) Add a song\nC) Play the songs\nD) Play the songs in shuffle mode\nE) Find the lexicographically smallest song\nF) Leave" << endl;
        cin >> resp;
        switch (resp) {
            case 'A': {
                cout << "These are the song options currently: " << endl;
                //iterate through the vector and print each of the song titles
                for(string songs : song){
                    cout << songs << endl;
                }

                cout << "What song would you like to play?" << endl;
                cin.ignore();
                //take the song; getline in case it is multiple words/has spaces
                getline(cin, songchoice);
                for(string songs: song){
                    if(songs == songchoice){
                        cout << "Now playing: " << songchoice << "\nby: " << artist[posit] << endl;
                    }
                    //helps to iterate through the artist vector
                    posit += 1;
                }
                break;
            }
            case 'B': {
                cout << "What song would you like to add to the playlist?" << endl;
                //ignore the newline character
                cin.ignore();
                //get song and artist
                getline(cin, newSong);
                cout << "Who is the artist?" << endl;
                getline(cin, newArtist);
                //add the two to the respective vectors
                song.push_back(newSong);
                artist.push_back(newArtist);
                cout << newSong << " by " << newArtist << " has been added to the playlist." << endl;
                break;
            }
            case 'C': {
                //iterate through the songs
                for (int i = 0; i < song.size(); i++) {
                    cout << "Now playing: " << song[i] << "\nby: " << artist[i] << endl; 
                    // 10 second time delay
                    this_thread::sleep_for(chrono::seconds(10));
                    cout << "\n";
                }
                break;
            }
            case 'D': {
                vector<int> randomOrder;
                // keeps adding numbers until every song is added to the shuffle list
                while (randomOrder.size() != song.size()) {
                    int num = rand() % song.size();
                    bool bad = false;
                    //sets the boolean bad to true if the new song is in the random order
                    for (int numb: randomOrder) {
                        bad |= (numb == num);
                    }
                    //add a new song instead
                    if (!bad) {
                        randomOrder.push_back(num);
                    }
                }
                cout << "Playing in shuffle order." << endl;
                //now play the random order
                for (int songNum: randomOrder) {
                    cout << "Now playing: " << song[songNum] << "\nby: " << artist[songNum] << endl; 
                    this_thread::sleep_for(chrono::seconds(10));
                    cout << "\n";
                }
                break;
            }
            case 'E': {
                // extra: song with title that is the alphabetically lowest
                string small = *min_element(song.begin(), song.end());
                cout << "The lexicographically smallest song is " << small << "." << endl;
                break;
            }
            case 'F': {
                //stop the loop
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

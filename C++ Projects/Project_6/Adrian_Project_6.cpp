#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(int argc, char* argv[]){
    
    int error = 0;
    
    bool go = true;
    bool encrypt = false;
    bool decrypt = false;
    bool key = false;
    bool in = false;
    bool out = false;
    
    string text;
    
for(int i = 0; i < argc; i++){
    if (argv[i][0] == '-'){
        
        if (argv[i][1] == 'e'){
            encrypt = true;
        }
        else if (argv[i][1] == 'd'){
            decrypt = true;
        }
        else if (argv[i][1] == 'k'){
            key = true;
        }
        else if (argv[i][1] == 'i'){
            in = true;
        }
        else if (argv[i][1] == 'o'){
            out = true;
        }
    }
    else if(argv[i][0] != '-'){
        error = error + 1;
    }
}


//This counts how many times it doesn't read a "-"
//It is already three with input.txt, output.txt, and the integer after k
//If it is more than 3 there is no dash on one of the input parameters
if (error > 4){
    cout << "You incorrectly inputted a input parameter! Exiting..." << endl;
    exit(0);
}

if (in){
        ifstream filestream;
        filestream.open("input.txt");
    
        if (encrypt){
        cout << "Encrypting..." << endl;
        
        if (key = true){
        
            getline(filestream, text);
            
            cout << "Original text: " << text << endl;
            
            for(int i = 0; i < argc - 1; i++){
                stringstream string;
                string << argv[i+1][0];
                int kv;
                string >> kv;
                
                int letter;
                
                for(int i = 0; i < text.size() ; i++){
                    
                    if (int(text.at(i)) == 32){
                        letter = int(text.at(i));
                        
                        text.at(i) = letter;
                    }
                    else{
                        letter = int(text.at(i)) + kv;
                        
                        text.at(i) = letter;
                    }
                }
                }
            }
        }
        else if (decrypt){
        cout << "Decrypting..." << endl;
        
        if (key = true){
        
            getline(filestream, text);
            
            cout << "Original text: " << text << endl;
            
            for(int i = 0; i < argc - 1; i++){
                stringstream string;
                string << argv[i+1][0];
                int kv;
                string >> kv;
                
                int letter;
                
                for(int i = 0; i < text.size() ; i++){
                   
                    if (int(text.at(i)) == 32){
                        letter = int(text.at(i));
                        
                        text.at(i) = letter;
                    }
                    else{
                        letter = int(text.at(i)) - kv;
                        
                        text.at(i) = letter;
                    }
                }
            }
        }
        }
    }
if (out){
        ofstream oFile;
        oFile.open("output.txt");
        oFile << text << "\n";
        cout << "New text: " << text << endl;
    }

    return 0;
}
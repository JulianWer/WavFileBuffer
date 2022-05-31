#include <iostream>
#include <string>
#include <fstream>
#include "DynamicArray.cpp"

// Julian Wernz 2123602

using namespace std;
using std::string;
using std::fstream;

class WAV {
public:

    char buffer[8000]; // buffer array


    Container<char> read(char *filePath, Container<char> waveArray) {
        ifstream waveFile;
        waveFile.open(filePath, ios::binary); // open stream in binary
        int counter = 0; // init counter
        char c; // temporary char
        while (waveFile) {
            c = waveFile.get(); // saves file char into c
            waveArray[counter++] = c; //saves c into the dynamic array
        }
        waveFile.close(); // closes the opened file

        return waveArray; // returns the array
    }

    void BuffertoFile(Container<char> waveArray, Container<char> outarray, char *path) {
        ofstream file;
        file.open(path, ios::out);
        for (char &i: this->buffer) {
            i = 0; // write 0 into the buffer
        }
        int index = 0;
        int len = waveArray.length() + 8000; // length of
        for (int i = 0; i < 44; ++i) {// adds header to the dynamic array
            cout << waveArray[i] << " "; // print out
            outarray[i] = waveArray[i]; // new dynamic array for the fileoutput
        }
        for (int i = 44; i < len; ++i) { // samples
            outarray[i] = buffer[index];
            buffer[index] = buffer[index] + waveArray[i]; // adds wavarray input to the buffer for the eco
            cout << buffer[index] << " ";
            index = (index + 1) % 8000; // for stop of the buffer
        }
        for (int i = 0; i < outarray.length(); ++i) {
            file << outarray[i]; // write into file
        }
        file.close();
    }

    int sizeFile(char *filepath) {
        FILE *file;
        file = fopen(filepath, "rb"); // opens file
        fseek(file, 0, SEEK_END); // goes to the file end
        int size = ftell(file); // init size with ftell
        fclose(file);
        return size; // return size
    }
};

// Function prototypes

int main(int argc, char *argv[]) {
    WAV head;
    char *path;
    path = R"(C:\Users\julia\Documents\TEI2\C\AufgabenBlatt2\Natur4.wav)";
    Container<char> waveArray(head.sizeFile(path)); // init container
    Container<char> arrayout(head.sizeFile(path));

    waveArray = head.read(path, waveArray);
    path = R"(C:\Users\julia\Documents\TEI2\C\AufgabenBlatt3\hallo.wav)";
    head.BuffertoFile(waveArray, arrayout, path);


    return 0;
}
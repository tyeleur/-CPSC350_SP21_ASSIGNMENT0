#include "FileProcessor.h"

using namespace std;

//default constructor
FileProcessor::FileProcessor(){}

//default destructor
FileProcessor::~FileProcessor(){}

//public method, takes file named to read/write and calls necessary classes to translate one to another
void FileProcessor::processFile(string input, string output){

  //open file streams to read/write
  ifstream inFS;
  ofstream outFS;

  //Open files and check whether they successfully opened
  cout << "Opening files..." << input << endl;
  inFS.open(input);
  outFS.open(output);

  if (!inFS.is_open()){
    cout << "Could not open read file." << endl;
    return;
  }if (!outFS.is_open()){
    cout << "Could not open write file." << endl;
    return;
  }

  //Notify user that the program is running properly
  cout << "Translating and writing to file " << output << endl;

  /*Create instance of translator and use to translate file line by line 
  ReadString place holder variable for current line being translated
  End while loop when no more lines in file */
  Translator* tranny = new Translator();
  string readString = "";
  while(1){
    getline(inFS, readString);
    if(inFS.eof()){
      break;
    }
    outFS << tranny->translateEnglishSentence(readString) << endl;
  }

  //Close input/output filestreams, along with instance of Translator used to translate
  outFS.close();
  inFS.close();
  tranny->~Translator();

  //Exit
  return;
}

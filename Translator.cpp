#include "Translator.h"

using namespace std;

//default constructor
Translator::Translator(){}

//default destructor
Translator::~Translator(){}

//public method, calls Model class to translate word character by character
string Translator::translateEnglishWord(string s){

  //create instance of model
  Model* mod = new Model();
  string ret = "";

  //itterate through input word letter by letter
  for(int i=0;i<s.size();++i){
    if(tolower(s[i])==tolower(s[i+1])){
      ret+= mod ->translateDoubleCharacter(s[i]);
    }else{
      ret+= mod ->translateSingleCharacter(s[i]);
    }
  }

  //destruct model instance
  mod->~Model();

  //return translated word
  return ret;
}

//public method, break sentence into words and translate separately. Stitch words back together to return full sentence
string Translator::translateEnglishSentence(string s){
  string ret = "";
  string placeholder= "";

  //itterate through letters to separate words and append string ret for translated sentence
  for (int i = 0;i<s.size();++i){
    if(int(s[i])>=65&&int(s[i])<=90){
      placeholder += s[i];
    }else if(int(s[i])>=97&&int(s[i])<=122){
      placeholder += s[i];
    }else{
      ret += translateEnglishWord(placeholder);
      ret += s[i];
      placeholder = "";
    }
  }

  //Catch any word left behind in string placeholder
  ret += translateEnglishWord(placeholder);

  //return translated sentence
  return ret;
}

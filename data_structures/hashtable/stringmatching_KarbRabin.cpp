#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int GetHash(string &input, int &ilen, int base) {
  int rhash = static_cast<int>(input[ilen - 1]);
  int power = 1;
  int it = ilen - 2;
  while(it >= 0)
  {
    rhash = rhash + (pow(base, power) * static_cast<int>(input[it]));
    power++;
    it--;
  }
  return rhash;
}

int RollingHash(int startindex, int dhash, string &dataset, int inputlen, int base) {
  int newhash = ((dhash - (static_cast<int>(dataset[startindex]) * pow(base, inputlen - 1))) * base) + static_cast<int>(dataset[startindex + inputlen]);
  return newhash;
}

int findstring(string &input, string &dataset) {
  int ilen = input.length();
  int ihash = GetHash(input, ilen, 5);
  int dlen = dataset.length();
  string dstr = dataset.substr(0, ilen);
  int dhash = GetHash(dstr, ilen, 5);

  int d = 0;
  while(d < dlen - 3) {
    if(ihash == dhash) {
      return d;
    }
    else {
      dhash = RollingHash(d, dhash, dataset, ilen, 5);
      d++;
    }
  }
}

int main() {
  string input = "sunil";
  string dataset = "dvksunildjvladjvldjbldfjbldfjbpodfjkgdgmldfmnbldjbodfkjbldfjmgldfnbGlbnzdgbkmzdfknbladoijbhiodhgbskbgkljsdhvbliusfhyvkDSFhvngksdbvjhbdsvjsdhvikdshvSDnfvgsKdbggvlkjsdhvsdkhgfihjhnsrlthjogfijhnskdgsergknsdkghaeirngaerkgbkjghyieurythweairgpoaergtaregjsebgdfgbldfkhypaeroighlkaerjgbajkbgkjadfyghearsunligndlkgbsfdkjhvbdfilhbadglignaekrngknbsipbroityirysurehgbvzdfvbmdfnzvbjhergysetrfywergffjbosiyhfuweygrfbjhwebfgjksdnv";
  int result = findstring(input, dataset);
  if(result == -1) {
    cout<<"Not found";
  }
  else {
    cout<<"Found at index"<<result<<endl;
  }
}

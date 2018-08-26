#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <stack>
#include <cstring>

#include <sys/stat.h> //To get status of the file
#include <fcntl.h> //To use some enums for file read like isreadonly O_RDONLY
#include <unistd.h> //To actually read the file
#include <dirent.h> //To do anything with directories

using namespace std;

template < typename T >
struct hash_fnc_using_template
{
    std::size_t operator() ( const T& seq ) const
    { return std::hash<std::string>() ( std::string( seq.begin(), seq.end() ) ) ; }
};

struct hash_fnc
{
  std::size_t operator()(const vector<char>& seq) const
  {
    return std::hash<string>() ( std::string( seq.begin(), seq.end() ) ) ;
  }
};

class FileInfo
{
  public:
    string filename;
    int lastaccesstime;

    FileInfo(string _filename, int _lastaccesstime) : filename(_filename), lastaccesstime(_lastaccesstime)
    {

    }
};

void ReadDirectory(const string &directoryPath, stack<string> &stk_files)
{
  DIR* dir_ = opendir(directoryPath.c_str());
  if(dir_)
  {
      struct dirent* entry;
      while((entry = readdir(dir_)) != nullptr)
      {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0)
         {
            string path = directoryPath + '/' + entry->d_name;
            stk_files.push(path);
         }
      }
  }
}

size_t readfile(const string &filepath, const size_t &size)
{
  //open file
  size_t hashvalue = -1;
  int fd = open(filepath.c_str(), O_RDONLY);
  if(fd != -1)
  {
      vector<char> filecontent(size);
      int actuallyread = read(fd, &filecontent[0], size);
      close(fd);
      if(actuallyread == size)
      {
        return std::hash<string>() ( std::string( filecontent.begin(), filecontent.end() ) ) ;
      }
      else
      {
        return hashvalue;
      }
  }
  else
  {
    throw invalid_argument("Invalid file");
  }
  return hashvalue;
}

vector<string> FindDuplicates(const string &dirpath)
{
    //Check if this directory is valid
    //Hashmap to keep track of files
    vector<string> duplicates;
    //if used a seperate hash function
    //unordered_map<string, FileInfo, hash_fnc_using_template<vector<char>>> hmap;
    //unordered_map<string, FileInfo, hash_fnc_using_template<vector<char>>>::iterator it;

    unordered_map<size_t, FileInfo> hmap;
    unordered_map<size_t, FileInfo>::iterator it;

    //To keep track of all files
    stack<string> stk_files;
    stk_files.push(dirpath);

    while(!stk_files.empty())
    {
      string top_str = stk_files.top();
      stk_files.pop();

      struct stat st;
      int sret = 0;
      if((sret = stat(top_str.c_str(), &st)) < 0)
      {
        cout<<"Invalidfile "<<sret<<endl;
        return vector<string>();
      }
      //cout<<"File/Dir is good "<<sret<<endl;

      //if is dir
      if(S_ISDIR(st.st_mode))
      {
          //cout<<"Reading directory "<<top_str<<endl;
          ReadDirectory(top_str, stk_files);
      }
      else if(S_ISREG(st.st_mode))
      {
        //is file st_atime
        //cout<<"Analysing file "<<top_str<<endl;
        size_t filehash = readfile(top_str, st.st_size);
        if((it = hmap.find(filehash)) == hmap.end())
        {
          //Not in map. Add to map
          FileInfo fileinfo(top_str, st.st_atime);
          hmap.insert(make_pair(filehash, fileinfo));
        }
        else
        {
          //Same content file found
          //check which has a latest edit time
          cout<<"Found duplicate "<<it->second.lastaccesstime<<"  "<<st.st_atime<<endl;
          if(it->second.lastaccesstime < st.st_atime)
          {
            duplicates.push_back(top_str);
          }
          else
          {
            duplicates.push_back(it->second.filename);
          }
        }
      }
    }
    return duplicates;
}

int main()
{
  string str = "C:\\coderunner\\data_structures\\hashtable";
  vector<string> res = FindDuplicates(str);
  for(int i = 0; i < res.size(); i++)
  {
    cout<<res[i]<<endl;
  }
}

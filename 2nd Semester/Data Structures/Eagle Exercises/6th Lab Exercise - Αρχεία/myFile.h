#ifndef myfile_h
#define myfile_h
#include <cstring>
class myFile
{
    private:
        char *name;    
    public:
        myFile(){name=nullptr;};
        myFile(char*s){name=new char[strlen(s)+1];memcpy(name,s,strlen(s)+1);};
        void SetName(char*s){delete name;name=new char[strlen(s)+1];memcpy(name,s,strlen(s)+1);};
        char* GetName();
        bool exists();
        int countLines();
        int countChars();
        void operator =(myFile &);
};
bool operator ==(myFile&,myFile &); 
void operator +=(myFile&,myFile &);
#endif //myfile_h
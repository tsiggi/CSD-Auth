#include <iostream>
#include <cstring>
#include <fstream>
int main() 
{
    char k,*temp,*fn,read;
    int count=0;

    fn=new char[51];
    
    std::cin>>k>>fn;
    
    temp=new char[strlen(fn)+1];
    memcpy(temp,fn,sizeof(char)*(strlen(fn)+1));
    delete []fn;
    fn=temp;
    
    std::ifstream ifs;
    ifs.open(fn);
    if(!ifs.is_open())
    {
        std::cout<<"File error"<<std::endl;
        return 1;
    }
    while(ifs>>read)
    {
        if(read==k)
            count++;
    }
    std::cout<<count<<std::endl;
    return 0;
}
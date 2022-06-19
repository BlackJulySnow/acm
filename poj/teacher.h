#include<string>
using namespace std;
class Teacher{
    public:
        string name;
        string id;
        string yuan;
};
ostream & operator<<( ostream & os,const Teacher & t)
{
    os << t.name << " " << t.yuan << " " << t.id;
    return os;
}
istream & operator>>( istream & is,Teacher & t)
{

    is >> t.name >> t.yuan >> t.id;
    return is;
}
bool operator < (const Teacher & a,const Teacher & b){
    if(a.yuan == b.yuan)
        return a.name < b.name;
    else
        return a.yuan < b.yuan;
}
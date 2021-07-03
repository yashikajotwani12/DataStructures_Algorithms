#include<bits/stdc++.h>
using namespace std;

class student{
    public:
    string firstname;
    string lastname;
    string rollno;


    student(string f, string l, string no)
    {
        firstname=f;
        lastname=l;
        rollno=no;


    }
    bool operator ==(const student &s)
    const{
       return rollno == s.rollno?true:false;
    }
};

class hashfunc{
    public:

    size_t operator()(const student &s) const{
        return s.firstname.length() + s.lastname.length();

    }

};
int main()
{
    unordered_map<student,int,hashfunc> student_map;
    student s1("yashika","jotwani","010");
    student s2("justin","jain","023");
    student s3("yashika","jotwani","030");
    student s4("rahul","kumar","129");
    // add student and their mark
    student_map[s1]=100;
    student_map[s2]=120;
    student_map[s3]=11;
    student_map[s4]=45;


    for(auto s:student_map)
    {
        cout<<s.first.firstname<<" "<<s.first.rollno<<" marks "<<s.second<<endl;
    }


    return 0;
}
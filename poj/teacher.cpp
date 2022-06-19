#include<algorithm>
#include<iostream>
#include<vector>
#include "teacher.h"
int main(){
    vector<Teacher> teachers;
    for(int i = 0;i < 3;i++){
        Teacher teacher;
        cin >> teacher;
        teachers.push_back(teacher);
    }
    sort(teachers.begin(),teachers.end());
    for(int i = 0;i < 3;i++){
        cout << teachers[i] << endl;
    }
    return 0;
}
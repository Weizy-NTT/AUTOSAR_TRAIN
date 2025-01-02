#include "School.h"

School::~School(){cout<<"Delete School obj";};
School::School(){};

void School::add_student(unique_ptr<Student> ptr){
    school_list.push_back( std::move(ptr));
}

void School::show_student_20_old(){
    int check = 0;
    for( auto &it : school_list){
        if (it->get_age() == 20){
            it->showinf();
            check ++;
        }
    }
    if(check ==0 ){
        cout<<"This school dont have student like you mention!!!"<<endl;
    }
}

void School::show_number(){
    int count = 0;
    for( auto &it : school_list){
        if (it->get_age() == 23 && it->get_hometown() == "Da Nang"){
            count ++;
        }
    }
    cout<< "School got :"<<count<<" Student"<<endl;
}
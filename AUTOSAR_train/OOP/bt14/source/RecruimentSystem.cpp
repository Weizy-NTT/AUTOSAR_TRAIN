#include "RecruimentSystem.h"



void RecruitmentSystem::addStudent(Student *student){
    students.push_back(student);
}

void RecruitmentSystem::showAllStudents() const{
    for (auto &it : students){
        it->ShowMyInfor();
    }
}

void RecruitmentSystem::recruitCandidates(size_t numOfRecruitments){
    int goodStudentNumber;
    std::vector<GoodStudent*>  goodStudentList;
    std::vector<NormalStudent*>  normalStudentList;
    if (numOfRecruitments < 11 || numOfRecruitments > 15) {
        std::cerr << "Number of recruits must be between 11 and 15.\n";
        return;
    }
    for (auto &it :students){
        if(auto goodstudent =  dynamic_cast<GoodStudent*>(it)){
            goodStudentNumber++;
            goodStudentList.push_back(goodstudent);
        }
        else if(auto normalstudent =  dynamic_cast<NormalStudent*>(it)){
            normalStudentList.push_back(normalstudent);
        }
    }
    std::sort(goodStudentList.begin(), goodStudentList.end(), [](GoodStudent* a, GoodStudent* b) {
        if (a->getGpa() != b->getGpa()) {
            return a->getGpa() > b->getGpa();
        }
        return a->getFullName() < b->getFullName();
    });

    std::sort(normalStudentList.begin(), normalStudentList.end(), [](NormalStudent* a, NormalStudent* b) {
        if (a->getEntryTestScore() != b->getEntryTestScore()) {
            return a->getEntryTestScore() > b->getEntryTestScore();
        }
        if (a->getEnglishScore() != b->getEnglishScore()) {
            return a->getEnglishScore() > b->getEnglishScore();
        }
        return a->getFullName() < b->getFullName();
    });

    std::vector<Student*> recruitedCandidates;

    // Lấy GoodStudent trước
    for (GoodStudent* goodStudent : goodStudentList) {
        if (recruitedCandidates.size() < numOfRecruitments) {
            recruitedCandidates.push_back(goodStudent);
        }
    }

    // Nếu chưa đủ, lấy thêm NormalStudent
    for (NormalStudent* normalStudent : normalStudentList) {
        if (recruitedCandidates.size() < numOfRecruitments) {
            recruitedCandidates.push_back(normalStudent);
        }
    }

    // Hiển thị danh sách ứng viên được tuyển dụng
    std::cout << "Recruited Candidates:\n";
    for (const auto& candidate : recruitedCandidates) {
        candidate->ShowMyInfor();
        std::cout << "---------------------\n";
    }

    if (recruitedCandidates.size() < numOfRecruitments) {
        std::cout << "Note: Only " << recruitedCandidates.size() << " candidates were available for recruitment.\n";
    }
    
}

RecruitmentSystem::~RecruitmentSystem(){}


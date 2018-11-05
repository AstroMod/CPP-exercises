#include <iostream>
#include <string>
#include <vector>

int id = 1;

struct Student {
    std::string first_name;
    std::string surname;
    int s_id = id;

    void print (const Student& s) const {
        std::cout << s.s_id << " - " << s.first_name << " " << s.surname;
    }
};

std::vector<Student> list_of_student_in_uni = {};

bool check_new (std::string s) {
    bool x = 1;
    for (Student member : list_of_student_in_uni) {
        if (member.surname == s) {
            x = 0;
        }
        else continue;
    }
    return x;
}

void add_student(std::string fn, std::string s) {
    if (check_new(s)) {
        Student st = {fn, s};
        list_of_student_in_uni.push_back(st);
        id += 1;
    } else {
        std::cout << "Student exists already! " << std::endl;
    }
}

void print (std::vector<Student> list) {
    for (Student member : list) {
        member.print(member);
        std::cout << std::endl;
    }
}

struct ModuleRecord {
    int id;
    int grade = 0;
};

struct Module {
    std::string title;
    std::vector<ModuleRecord> list_of_grades_per_student = {};

    void add_record (int id, int grade) {
        ModuleRecord pair_student_grade = {id, grade};
        list_of_grades_per_student.push_back(pair_student_grade);
    }

    void print (const Module& m) {
        std::cout << m.title << std::endl;
        for (ModuleRecord element : list_of_grades_per_student) {
            element.my_student.print(element.my_student);
            std::cout << " " << element.grade << std::endl;
        }
    }
};

int main() {
    Uni u = {"CPP London Uni"};
    std::string fn = "Barbara";
    std::string s = "L'Episcopo";
    u.add_student(fn, s);
    u.print(u);
    std::cout << std::endl;
    std::string fn2 = "Fabio";
    std::string s2 = "Platania";
    u.add_student(fn2, s2);
    u.print(u);
    std::cout << std::endl;
    std::string fn3 = "Giulia";
    std::string s3 = "Platania";
    u.add_student(fn3, s3);
    u.print(u);

    return 0;
}
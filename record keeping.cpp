#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int id = 1;

struct Student {
    std::string first_name = "unkown";
    std::string surname = "unknown";
    int s_id = ++id;

    void print () const {
        std::cout << s_id << " - " << first_name << " " << surname;
    }
};

struct ModuleRecord {
    Student my_student;
    int grade = 0;
};

bool sortByGrade(const ModuleRecord &lhs, const ModuleRecord &rhs) {
    return lhs.grade > rhs.grade;
}

struct Module {
    std::string title;
    std::vector<ModuleRecord> list_of_grades_per_student = {};

    void add_record (const Student& name, const int& grade) {
        ModuleRecord pair_student_grade = {name, grade};
        list_of_grades_per_student.push_back(pair_student_grade);
    }

    void print (const Module& m) {
        std::cout << m.title << std::endl;
        std::sort(list_of_grades_per_student.begin(), list_of_grades_per_student.end(), sortByGrade);
        for (ModuleRecord element : list_of_grades_per_student) {
            element.my_student.print();
            std::cout << " " << element.grade << std::endl;
        }
    }
};



int main() {

    Module m1 {"ICT"};
    m1.add_record ({"Mickey", "Mouse"}, 9);
    m1.add_record({"Donald", "Duck"}, 7);
    m1.add_record({"Minnie", "Mouse"}, 7);
    m1.add_record({"Uncle", "Goofy"}, 8);
    m1.print(m1);

    Module m2 {"Maths"};
    m2.add_record ({"Donald", "Trump"}, 9);
    m2.add_record({"George W.", "Bush"}, 7);
    m2.add_record({"Bill", "Clinton"}, 5);
    m2.add_record({"Richard", "Nixon"}, 5);
    m2.print(m2);


    return 0;
}

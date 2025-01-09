#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>

struct Student {
    std::string name = " ";
    std::string last_name = " ";
    struct birth_date {
        int16_t day = 0;
        int16_t month = 0;
        int16_t year = 0;
        } birth_date;
};

void SortStudents(std::vector<Student>& students, const std::string& sort_kind) {
    if (sort_kind == "Date") {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return std::tie(a.birth_date.year, a.birth_date.month, a.birth_date.day, a.last_name, a.name) <
            std::tie(b.birth_date.year, b.birth_date.month, b.birth_date.day, b.last_name, b.name);
        });
    } else if (sort_kind == "Name") {
        std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
            return std::tie(a.last_name, a.name, a.birth_date.year, a.birth_date.month, a.birth_date.day) <
            std::tie(b.last_name, b.name, b.birth_date.year, b.birth_date.month, b.birth_date.day);
        });
    };
}

void PrintStudent (const Student& student) {
    std::cout << student.name << ' ' << student.last_name << ' '
    << (student.birth_date.day < 10 ? "0" : "") << student.birth_date.day << '.'
    << (student.birth_date.month < 10 ? "0" : "") << student.birth_date.month << '.'
    << student.birth_date.year;
}

int main() {
    std::int32_t count_students = 0;
    std::cin >> count_students;

    std::vector<Student> students(count_students);
    for (size_t index_student = 0; index_student < count_students; ++index_student) {
        std::cin >> students[index_student].name >> students[index_student].last_name
        >> students[index_student].birth_date.day >> students[index_student].birth_date.month
        >> students[index_student].birth_date.year;
    }

    std::string sort_kind = " ";
    std::cin >> sort_kind;

    SortStudents(students, sort_kind);

    for (auto& student : students) {
        PrintStudent(student);
        std::cout << std::endl;
    }

    return 0;
}
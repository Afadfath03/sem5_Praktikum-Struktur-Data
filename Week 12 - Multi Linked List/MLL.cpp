#include <iostream>
#include <string>
using namespace std;
 
// Struktur untuk mata kuliah
struct Course {
    string courseName;
    Course* nextCourse;
};
 
// Struktur untuk mahasiswa
struct Student {
    string studentName;
    Course* courseList;
    Student* nextStudent;
};
 
// Fungsi untuk menambahkan mahasiswa baru
Student* addStudent(Student* head, string name) {
    Student* newStudent = new Student{name, nullptr, head};
    return newStudent;
}
 
// Fungsi untuk menambahkan mata kuliah ke mahasiswa
void addCourseToStudent(Student* student, string courseName) {
    Course* newCourse = new Course{courseName, student->courseList};
    student->courseList = newCourse;
}
 
// Fungsi untuk menampilkan daftar mahasiswa dan mata kuliah yang diambil
void displayStudents(Student* head) {
    while (head) {
        cout << "Student: " << head->studentName << endl;
        cout << "  Courses: ";
        Course* course = head->courseList;
        while (course) {
            cout << course->courseName << " ";
            course = course->nextCourse;
        }
        cout << endl;
        head = head->nextStudent;
    }
}
 
int main() {
    // Membuat daftar mahasiswa
    Student* students = nullptr;
 
    // Menambahkan mahasiswa
    students = addStudent(students, "Alice");
    students = addStudent(students, "Bob");
 
    // Menambahkan mata kuliah untuk mahasiswa
    addCourseToStudent(students, "Mathematics"); // Bob
    addCourseToStudent(students, "Physics");    // Bob
 
    addCourseToStudent(students->nextStudent, "Programming"); // Alice
    addCourseToStudent(students->nextStudent, "English");     // Alice
 
    // Menampilkan data mahasiswa
    displayStudents(students);
 
    return 0;
}
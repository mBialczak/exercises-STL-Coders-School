#include <cstring>
#include <exception>
#include <fstream>
#include <iostream>
#include <memory>
class Student {
public:
    void setName(std::string name) { strncpy(name_, name.data(), 15); }
    void setIndex(size_t index) { index_ = index; }
    void setAverage(double average) { average_ = average; }
    std::string getName() const { return name_; }
    size_t getIndex() const { return index_; }
    double getAverage() const { return average_; }

private:
    char name_[15];
    size_t index_;
    double average_;
};

void writePod()
{
    Student mateusz;
    mateusz.setName("Mateusz");
    mateusz.setIndex(123456);
    mateusz.setAverage(5.0);
    std::fstream student("Student.txt", student.binary | student.out);
    if (student.is_open()) {
        student.write(reinterpret_cast<char*>(&mateusz), sizeof(Student));
    }
}

void readPod()
{
    std::fstream student("Student.txt", student.binary | student.in);
    Student mateusz_read;
    if (student.is_open()) {
        student.read(reinterpret_cast<char*>(&mateusz_read), sizeof(Student));
    }
    std::cout << "Name: " << mateusz_read.getName() << '\n';
    std::cout << "Index: " << mateusz_read.getIndex() << '\n';
    std::cout << "Average: " << mateusz_read.getAverage() << '\n';
}
int main()
{
    writePod();
    readPod();
}
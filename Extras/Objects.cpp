#include <iostream>
using namespace std;

class Student {
private:
    int *scores; // Instance variable to hold a student's exam scores
    static const int numScores = 5; // Default number of scores
public:
    // Constructor to initialize the number of scores and allocate memory for the scores array
    Student() {
        scores = new int[numScores];
    }

    // Destructor to free dynamically allocated memory
    ~Student() {
        delete[] scores;
    }

    // Function to read numScores scores from stdin and save them to scores instance variable
    void input() {
        for (int i = 0; i < numScores; ++i) {
            cin >> scores[i]; // Read scores from stdin
        }
    }

    // Function to calculate and return the total sum of the student's scores
    int calculateTotalScore() const {
        int totalScore = 0;
        for (int i = 0; i < numScores; ++i) {
            totalScore += scores[i];
        }
        return totalScore;
    }
};

int main() {
    int numStudents;
    cin >> numStudents;

    // Create an array of Student objects
    Student *students = new Student[numStudents];

    // Prompt the user to enter each student's exam grades
    for (int i = 0; i < numStudents; ++i) {
        students[i].input();
    }

    // Calculate the total score for Kristen
    int kristen = students[0].calculateTotalScore();

    // Compare the total score of each student with Kristen's score
    int count = 0;
    for (int i = 1; i < numStudents; ++i) {
        int totalScore = students[i].calculateTotalScore();
        if (totalScore > kristen) {
            count++;
        }
    }

    cout << count << endl;

    // Free dynamically allocated memory
    delete[] students;

    return 0;
}

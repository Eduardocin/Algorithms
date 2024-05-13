#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    int age;
    int standard;
    string first_name;
    string last_name;

public:
    // Constructor
    Student() : age(0), standard(0), first_name(""), last_name("") {}

    // Setter methods
    void set_age(int a) { age = a; }
    void set_standard(int s) { standard = s; }
    void set_first_name(const string& first) { first_name = first; }
    void set_last_name(const string& last) { last_name = last; }

    // Getter methods
    int get_age() const { return age; }
    int get_standard() const { return standard; }
    const string& get_first_name() const { return first_name; }
    const string& get_last_name() const { return last_name; }

    // stringify method
    string stringify() const {
        return std::to_string(age) + "," + first_name + "," + last_name + "," + std::to_string(standard);
    }
};

int main() {
    int age, standard;
    string first_name, last_name;

    cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    
    cout << st.stringify();

    return 0;
}


#include <iostream>

using namespace std;


class Base {
    string s;

    public:
    Base() : s("기반") { cout << "기반 클래스" << endl; }

    void what() { cout << s << endl; }
};
class Derived : public Base {
    string s;

    public:
    Derived() : s("파생"), Base() { cout << "파생 클래스" << endl; }

    void what() { cout << s << endl; }
};

class Employee {
    protected:
    string name;
    int age;

    string position;
    int rank;

    public:
    Employee(string name, int age, string position, int rank)
    : name(name), age(age), position(position), rank(rank) {}

    // 복사 생성자
    Employee(const Employee& employee) {
        name = employee.name;
        age = employee.age;
        position = employee.position;
        rank = employee.rank;
    }

    // 디폴트 생성자
    Employee() {}
    
    // TODO: virtual 키워드가 붙으므로 기반,파생 클래스중 어떤 함수를 호출할지 런타임에 결정하게 됨. 다형성을 구현
    virtual void print_info() { 
        cout << name << " (" << position << " , " << age << ") ==> "
        << calculate_pay() << "만원" << endl;
    }
    virtual int calculate_pay() { return 200 + rank * 50; }
};

class Manager : public Employee {
    int year_of_service;

    public:
    Manager(string name, int age, string position, int rank, int year_of_service)
    : year_of_service(year_of_service), Employee(name, age, position, rank) {}

    // 복사 생성자 
    Manager(const Manager& manager)
    : Employee(manager.name, manager.age, manager.position, manager.rank) {
        year_of_service = manager.year_of_service;
    }

    // 디폴트 생성자
    Manager() : Employee() {}

    int calculate_pay() { return 200 + rank * 50 + 5 * year_of_service; }
    void print_info() {
        cout << name << " (" << position << " , " << age << ", "
        << year_of_service << "년차) ==> " << calculate_pay() << "만원"
        << endl;
    }
};
class EmployeeList {
    int alloc_employee;
    int current_employee;
    Employee** employee_list;

    public:
    EmployeeList(int alloc_employee) : alloc_employee(alloc_employee) {
        employee_list = new Employee*[alloc_employee];

        current_employee = 0;
    }
    void add_employee(Employee* employee) {
        employee_list[current_employee] = employee;
        current_employee++;
    }
    int current_employee_num() { return current_employee; }

    void print_employee_info() {
        int total_pay = 0;
        for (int i = 0; i < current_employee; i++) {
            employee_list[i]->print_info();
            total_pay += employee_list[i]->calculate_pay();
        }
        cout << "총 비용 : " << total_pay << "만원 " << endl;
    }
    ~EmployeeList() {
        for (int i = 0; i < current_employee; i++) {
            delete employee_list[i];
        }
        delete[] employee_list;
    }
};


class Case2 {

    public: 
    void execute() {
        // Base p;
        // Derived c;

        // cout << "=== 포인터 버전 ===" << endl;
        // Base* p_p = &c; // 업케스팅

        // Derived* p_c = dynamic_cast<Derived*>(p_p); // 강제 타입변환 가능.
        // p_c->what();

        // Derived* p_p = &p; // 다운케스팅 -> 실패
        // p_p->what();

        EmployeeList emp_list(10);
        emp_list.add_employee(new Employee("노홍철", 34, "평사원", 1));
        emp_list.add_employee(new Employee("하하", 34, "평사원", 1));
        emp_list.add_employee(new Manager("유재석", 41, "부장", 7, 12));
        emp_list.add_employee(new Manager("정준하", 43, "과장", 4, 15));
        emp_list.add_employee(new Manager("박명수", 43, "차장", 5, 13));
        emp_list.add_employee(new Employee("정형돈", 36, "대리", 2));
        emp_list.add_employee(new Employee("길", 36, "인턴", -2));
        emp_list.print_employee_info();
    }
};
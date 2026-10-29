#pragma once
#include<iostream>

namespace Seoyeowon2649020{

    const int daysInMonth[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};    
    class dayOfYear
    {
        int month; 
        int day;  
        void testMonth() 
        {
            if (month < 1 || month > 12)
            {
                std::cout << "Invalid month\n";
                std::exit(1);
            }
        }
        void testDay()
        {
            if (day < 1 || day > daysInMonth[month])
            {
                std::cout << "Invalid day\n";
                std::exit(1);
            }
        }
        // 1-3. updateDay함수는 한달안의 day만 고려하고 있습니다. 만약 100일 등 한달보다 큰 day일 경우도 이 함수를 사용할 수 있게 수정해보세요.
        void updateDay()
        {
            int maxDay{daysInMonth[month]};
            if (day > maxDay)
            {
                int a{day / maxDay};
                day -= (a*maxDay); month += a;
                if (month > 12){
                    int b{month - 12};
                    month = b;
                }
            }
        }
    public:
        dayOfYear(int m = 1, int d = 1):month{m}, day{d} 
        {
            testMonth();
            testDay();
        }
        void input()
        {
            std::cout << "Enter month: ";
            std::cin >> month; testMonth();
            std::cout << "Enter day: ";
            std::cin >> day; testDay();
        }
        friend std::istream& operator>>(std::istream& is, dayOfYear& d)
        {
            std::cout << "Enter month: ";
            is >> d.month; d.testMonth();
            std::cout << "Enter day: ";
            is >> d.day; d.testDay();
            return is;            
        }
        void setMonth(int m) {month = m; testMonth();}
        void setDay(int d) {day = d; testDay();}
        void print() const
        {
            switch(month)
            {
            case 1: std::cout << "Jan. "; break;
            case 2: std::cout << "Feb. "; break;
            case 3: std::cout << "Mar. "; break;
            case 4: std::cout << "Apr. "; break;
            case 5: std::cout << "May. "; break;
            case 6: std::cout << "Jun. "; break;
            case 7: std::cout << "Jul. "; break;
            case 8: std::cout << "Aug. "; break;
            case 9: std::cout << "Sep. "; break;
            case 10: std::cout << "Oct. "; break;
            case 11: std::cout << "Nov. "; break;
            case 12: std::cout << "Dec. "; break;
            } 
            std::cout << day << "\n";
        }
        friend std::ostream& operator<<(std::ostream& os, const dayOfYear& d)
        {
            switch(d.month)
            {
            case 1: os << "Jan. "; break;
            case 2: os << "Feb. "; break;
            case 3: os << "Mar. "; break;
            case 4: os << "Apr. "; break;
            case 5: os << "May. "; break;
            case 6: os << "Jun. "; break;
            case 7: os << "Jul. "; break;
            case 8: os << "Aug. "; break;
            case 9: os << "Sep. "; break;
            case 10: os << "Oct. "; break;
            case 11: os << "Nov. "; break;
            case 12: os << "Dec. "; break;
            } 
            os << d.day << "\n";
            return os;
        }
        int getMonth() const {return month;}
        int getDay() const {return day;}
        // 1-4. 전위증가연산자, 후위증가연산자를 this를 이용해서 구현하세요. 리턴형식도 참조가 필요하면 참조로 리턴하게 변경하세요. 
        dayOfYear operator++() 
        {
            ++day;
            updateDay();            
            return *this;
        }
        dayOfYear operator++(int)
        {   
            dayOfYear temp{month, day};
            ++(*this);
            updateDay();   
            return temp;
        }
        friend bool operator==(const dayOfYear& d1, const dayOfYear& d2)
        {
            return d1.month == d2.month && d1.day == d2.day;
        }
        // 1-5. 복합할당연산자 +=를 구현하세요. 매개변수는 int, day에 매개변수를 더해줍니다. this를 이용하세요.  
        friend dayOfYear operator+=(int a){
            return (*this{day} + a);
        }
        // 1-6. 프렌드함수로 구현되어 있는 이항연산자 +는 날짜계산이 아니라 있는 그대로를 더했는데 이를 삭제하고 멤버함수로 이항연산자 +를 구현해봅시다. 매개변수는 int, 1-5에서 구현한 복합할당연산자+=와 this를 이용하세요. 
        dayOfYear operator+(const dayOfYear& d1, int m, int d)
        {
            return dayOfYear{this{month}+=m, d1{day}+=d};
        }
        
    };
}

// 1. dayOfYear.h파일에 dayOfYear class를 인라인으로 구현하려고 합니다. 다음을 확인하여 위 코드를 변경하여 dayOfYear.h파일을 완성해보세요. 
// 1-1. 헤더가드, 전처리지시자를 넣으세요.
// 1-2. 본인이름학번의 네임스페이스안에 dayOfYear class를 정의하세요.
// 1-3. updateDay함수는 한달안의 day만 고려하고 있습니다. 만약 100일 등 한달보다 큰 day일 경우도 이 함수를 사용할 수 있게 수정해보세요. 
// 1-4. 전위증가연산자, 후위증가연산자를 this를 이용해서 구현하세요. 리턴형식도 참조가 필요하면 참조로 리턴하게 변경하세요. 
// 1-5. 복합할당연산자 +=를 구현하세요. 매개변수는 int, day에 매개변수를 더해줍니다. this를 이용하세요.  
// 1-6. 프렌드함수로 구현되어 있는 이항연산자 +는 날짜계산이 아니라 있는 그대로를 더했는데 이를 삭제하고 멤버함수로 이항연산자 +를 구현해봅시다. 매개변수는 int, 1-5에서 구현한 복합할당연산자+=와 this를 이용하세요. 
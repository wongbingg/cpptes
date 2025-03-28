
#include <iostream>
#include <vector>

using namespace std;

class Case1 {
    public: 
    void execute() {
    //벡터 선언
     vector<int> vec;
 
     // 요소 추가
     vec.push_back(10);
     vec.push_back(20);
     vec.push_back(30);
 
     //요소 접근 (인덱스를 이용한 접근)
     cout << "첫 번째 요소: " << vec[0] << endl;
     cout << "두 번째 요소: " << vec.at(1) << endl;
 
     //벡터 크기
     cout << "벡터의 크기: " << vec.size() << endl;
 
     //벡터 끝에서 요소 삭제 
     vec.pop_back();
 
     //벡터 크기 업데이트
     cout << "벡터의 크기(삭제후): " << vec.size() << endl;
 
     //벡터의 모든 요소 출력
     for (int i = 0; i < vec.size(); ++i) {
         cout << "요소 " << i + 1 << ": " << vec[i] << endl;
     }
 
    }
};
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    ll sum = 0;
    ll sum1 = 0;
    ll sum2 = 0;
    int size1 = queue1.size();
    int size2 = queue2.size();
    for (int t : queue1) {
        sum += t;
        sum1 += t;
    }
    
    for (int t : queue2) {
        sum += t;
        sum2 += t;
    }
    
    
    int answer = 0;
    
    int idx1 = 0;
    int idx2 = 0;
    for (int i=0; i<1200000; i++) {
        if (sum1 == sum2) return answer;
        else if (sum1 > sum2) {
            // sum1꺼를 sum2로
            if (idx1 < size1) {
                sum1 -= queue1[idx1];
                sum2 += queue1[idx1];
            } else {
                sum1 -= queue2[idx1%size1];
                sum2 += queue2[idx1%size1];
            }
            idx1++;
            if (idx1 == size1 + size2) idx1 %= (size1 + size2);
        } else {
            if (idx2 < size2) {
                sum1 += queue2[idx2];
                sum2 -= queue2[idx2]; 
            } else {
                sum1 += queue1[idx2%size2];
                sum2 -= queue1[idx2%size2]; 
            }
            idx2++;
            if (idx2 == size1 + size2) idx2 %= (size1 + size2);
        }
        answer++;
    }
    
    
    return -1;
}
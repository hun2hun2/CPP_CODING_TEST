#include <iostream>

using namespace std;

int solution(int n, int a, int b) {
    if (a > b) b = a, a = b;

    int result = 1;
    while ((a+1) != b) {
        // if (a % 2 == 0) a /= 2;
        // else a = a / 2 + 1;
        // if (b % 2 == 0) b /= 2;
        // else b = b / 2 + 1;
        a = (a + 1) / 2;
        b = (b + 1) / 2;

        result++;
    }

    return result;
}

int main()
{
    cout << solution(8, 4, 7) << endl; //출력값 : 3
    return 0;
}

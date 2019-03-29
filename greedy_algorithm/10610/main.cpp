#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/* 정렬 함수를 내림차순으로 실행해줄 함수 정의 */
bool desc(int a, int b) { return a > b; }

int main() {
	/* 문자열의 모든 숫자를 더해줄 변수 초기화 */
	int res = 0;		
	/* 순서를 변경할 숫자 변수 선은 */
	string str;			
	/* 입력된 숫자의 순서를 변경해 30의 배수로 바꿀 수 있는 지 참 거짓 */
	bool isT = false;	
	cin.tie(0);
	ios::sync_with_stdio(false);

	/* 순서를 변경할 숫자 입력 */
	cin >> str;

	/* 
		입력된 문자열을 내림 차순으로 정렬
		정렬은 문자열에 포함된 각 문자에 대해서 정렬함
	*/
	sort(str.begin(), str.end(), desc);
	
	/* 만일 정렬된 문자열의 마지막 숫자가 0일 경우 */
	if (str.back() == '0') {
		/* 
			문자열의 각 숫자들을 전부 더해줌 
			이 과정은 문자 '0'이 나올 때까지 반복함
		*/
		for (int i = 0; str[i] != '0'; i++)
			res += (str[i] - '0');
		/* 문자열의 숫자를 모두 더한 값이 3일 경우 참 */
		if (res % 3 == 0) isT = true;
	}

	/* 
		앞에서 문자열 내의 모든 숫자 합이 3의 배수고 
		문자열 내에 0이 포함되어 있을 경우 정렬된 문자열 출력
	*/
	if (isT) cout << str;
	/* 그렇지 않을 경우 -1을 출력 */
	else cout << -1;

	return 0;
}
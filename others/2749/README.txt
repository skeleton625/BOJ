백준 알고리즘 2749 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

해당 문제는 기존의 피보나치 수열의 방식으로 접근할 경우 시간 초과가 생길 수 있습니다.

그러므로 추가적으로 다른 방법이 필요합니다.

문제에서 서술한 대로 문제의 답은 항상 1000000으로 나눈 나머지를 출력하게 되어 있습니다.

그렇기 때문에 수열의 경우 주기가 생기기 마련입니다. 이 때 사용할 방식은 피사노 주기입니다.

피사노 주기는 피보나치 수열을 정수 p로 나눌 경우 일정 주기가 생긴다는 법칙입니다.

이 법칙에서 주기의 길이는 10^k로 피보나치 수열을 나눈 나머지를 구할 경우, 15*10^k-1이 됩니다.

그러므로 해당 문제에서 피사노 주기의 길이는 1500000 가 됩니다.

결과적으로 입력값 n을 1500000으로 나눈 나머지 번째 피보나치 수열 값과 n번째 피보나치 수열 값은 같다는 것을

알 수 있습니다.

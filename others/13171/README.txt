백준 알고리즘 13171 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

해당 문제는 비트연산자를 사용해 문제를 풀이했습니다.

A를 X번 곱하는 과정은 A^1 * A^2 * A^4 * A^8 ... * A^m 로 진행되고 곱해야하는 순간은 X를 비트로 나타냈을 떄 

X의 특정 비트 칸 번호를 n이라 했을 때 n번째 비트가 1이 되었을 때 해 당 A^m을 결과값에 곱해주는 방법을

반복해주면 됩니다.

여기서 A^m이나 곱해준 결과값, 혹은 A(1~10^18)의 값이 1000000007보다 커질 수 있기 때문에 각각 연산을

할 때 1000000007로 나눈 나머지 값을 입력해줘야 합니다. (A는 초기에 1000000007로 나눈 나머지를 값으로

시작해야 합니다.)

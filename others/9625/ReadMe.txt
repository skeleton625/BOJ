백준 9625 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

해당 문제에서 k번 버튼을 누를 때 A, B의 개수는 k-1번 버튼을 누를 때의 A, B의 개수와 k-2번 버튼을 누를 때의 A, B의 개수를 더한

값과 같습니다.

예를 들어

0번 버튼(버튼을 누르기 전)은 A로 A 1 B 0, 

1번 버튼은 B로 A 0 B 1, 

2번 버튼은 BA로 A 1 B 1

3번 버튼은 BAB로 A 1 B 2

4번 버튼은 BABBA로 A 2 B 3

5번 버튼은 BABBABAB로 A 3 B 5 입니다.

또한 해당 문제에서 보면 A는 B로 바뀌고, B는 BA로 바뀌는 것을 보아 버튼을 누를 때 마다 B의 개수는 기존 B의 개수에 A의 개수를 더해준 값이고, 

A의 개수는 원래 B의 개수임을 알 수 있습니다.

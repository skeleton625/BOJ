백준 알고리즘 12015 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

해당 코드는 이분 탐색을 이용한 LIS 알고리즘을 사용해 문제를 풀이했습니다.

LIS 알고리즘은 최장 증가 수열 알고리즘으로 전체 수열에서 증가하는 가장 긴 부분 수열을 구하는 알고리즘 입니다.

LIS 알고리즘은 다음과 같습니다.

1. LIS 배열을 INF(무한 값)로 초기화 해줍니다. 현재 상태는 아무런 값도 들어가지 않은 상태입니다.

2. LIS 배열에 아무 값이 없다면 조사하는 배열 Array의 첫 번째 값을 넣어줍니다.

3. Array 배열을 순회합니다.

4. 순회하면서 현재 배열 위치 값이 LIS 배열의 가장 큰 값보다 클 경우 현재 배열 위치 값을 LIS 배열에 추가해 줍니다.

5. 그렇지 않을 경우 LIS 배열의 내에서 현재 위치 값보다 작거나 같은 위치에 현재 배열 값을 넣어줍니다.

(여기서 "작거나 같은"은 현재 위치 배열 값보다 큰 가장 작은 LIS 배열 값 전 위치를 말합니다.)

이 알고리즘 과정에서 2, 3, 4, 5 과정을 이분 탐색 Lower_Bound를 통해서 실행시켜줄 수 있습니다.

코드에 대한 자세한 내용은 주석으로 추가했습니다.

백준 알고리즘 1932 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

해당 코드는 다이나믹 프로그래밍을 통해 문제를 풀이했습니다.

먼저 삼각형의 꼭대기로 삼각형의 꼭대기 최대값을 초기화 해줍니다.

그 다음 입력받는 줄에 데에서 그 줄의 최대값을 계산해 주는데 이 때, 이전 줄의 최대값을 사용해 최대값을 계산해 줍니다.

이전 줄의 최대값들을 기준으로 현재 줄의 최대값을 계산하는데 기준이 되는 점의 왼쪽, 오른쪽 대각선의 입력값을 가지고 각 위치의 최대값을

계산해 줍니다.

여기서 왼쪽, 오른족 대각선의 최대값을 계산시, 같은 위치에서 계산이 중복될 수 있기 때문에 최대값이 저장될 수 있도록 구현해야 합니다.

이 과정을 마지막 줄까지 반복한 다음, 정렬하면 최대값을 찾을 수 있습니다.

(정렬 이외에 마지막 줄에서 힙을 사용하는 방법도 존재할 수 있습니다.)

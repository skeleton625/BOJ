백준 알고리즘 2667 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

해당 코드는 BFS 알고리즘을 사용해 문제를 풀이했습니다.

입력된 배열에서 1이 시작되는 부분을 찾아 0이 테두리로된 1들의 집합을 모든 칸을 방문할 때까지 BFS 를 실행해 줍니다.

칸을 방문할 때마다 개수를 세면 해당 집합의 집 개수를 파악할 수 있습니다.

이러한 과정을 다른 집합들에도 적용해 단지의 개수와 단지 내의 집 수를 파악할 수 있습니다.

문제에서 이동할 수 있는 모든 경우의 수를 따져야 하기 때문에 DFS 을 사용하는 것 보다 BFS가 더 효율적입니다.

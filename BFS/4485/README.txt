백준 알고리즘 4485 문제 풀이  중입니다.

문제 풀이를 완료했습니다.

해당 코드는 다익스트라 알고리즘고 BFS 알고리즘을 혼합해 문제를 풀이했습니다.

먼저 BFS 알고리즘을 통해 현재 위치에서 이동할 수 있는 4개의 방향으로 이동합니다.

여기서 BFS에서 방문한 원소에 대해서 방문하지 않는다는 조건은 제외시켜줘야 합니다.

( BFS 알고리즘에선 그래프 경로 비용이 1로 통일되어 있지만 다익스트라의 경우 비용이 여러개기 때문에 다른 방향으로

들어온 비용이 더 낮을 수 있기 때문)

그 다음, 다익스트라 알고리즘을 사용해 이동한 위치에서 완선된 비용이 현재 위치의 최소 비용보다 작을 경우 갱신해주고 우선순위 큐에

입력한 다음, 다시 우선순위 큐에서 최소 비용 위치를 뽑아 위의 알고리즘을 반복해 줍니다.

이를 통해서 출구에 도착할 때 소비해야 될 최소 루피 값을 얻어낼 수 있습니다.

백준 알고리즘 2178 번 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

해당 코드는 BFS 알고리즘을 사용해 문제를 풀이했습니다.

BFS 알고리즘을 통해 시작 점부터 한 칸씩 이동하면서 모든 점을 방문하는 시도를 합니다.

다만 여기서 방문한 점의 값이 '0'이거나 이미 방문했던 점일 경우 방문을 하지 않습니다.

(값이 '0'일 경우, 방문이 불가능한 점이고 방문했던 점을 반문할 경우 여러번 이동할 수 있기 때문)

또한 이 과정에서 방문하지 않은 점을 방문하면서 방문했던 점들의 개수를 파악해 줍니다.

이를 통해서 최종 목적지 점에 도착했을 때 BFS 알고리즘에 의해 가장 단거리의 점이 먼저 도착하므로 그 때의

횟수가 최단 횟수가 됩니다.

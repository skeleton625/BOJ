백준 알고리즘 6593 번 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

해당 문제는 BFS 알고리즘을 통해 문제를 풀이했습니다.

BFS 알고리즘을 통해 입력된 그래프에서 상하 전후 좌후, 즉 x, y, z 축으로 각각 -1, 1을 더해 순회를 합니다.

순회를 하는 과정에서 '#'을 만나거나 그래프 이외의 범위인 경우 이동할 수 없으므로 이 경우엔 이동하지 않습니다.

또한 이동한 점에서 먼저 방문했던 점을 다시 방문하지 않도록 방문했다는 표시를 남겨주고, 방문했던 점 또한 다시

방문하지 않도록 합니다.

이렇게 해서 최종 목적지에 도착할 경우, 걸린 시간을 출력하고, 마지막까지 최종 목적지에 도착하지 못할 경우,

방문이 불가능 하다는 것을 출력합니다.

코드에 대한 자세한 내용은 주석으로 추가했습니다.

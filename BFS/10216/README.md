# 백준 10216 번 문제 풀이

해당 문제는 너비 우선 탐색(BFS) 알고리즘을 사용해 문제를 풀이했습니다.

먼저 각 점들에 대해 그룹에 속해 있는지, 속해 있지 않은지를 파악합니다.

이는 너비 우선 탐색을 통해 한 점을 기준으로 인접한 다른 점들이 있는지 파악합니다.

여기서 파악된 점들은 그룹에 속한 점들이며, 이 점들과 인접한 점들 또한 이 그룹에 속한 점들로 인식됩니다.

이렇게 방문한 점들은 이후 연산에서 다시 비교하지 않도록 그룹에 속해 있다는 표시를 정의해 줍니다.

이렇게 한 그룹에 속한 모든 점들을 찾을 수 있으며, 그 이외의 점들은 이 그룹과 인접하지 않다는 것을 의미합니다.

이러한 과정을 그룹이 존재하지 않는 점들에 대해 진행할 경우, 입력된 점들의 최소 그룹 개수를 파악할 수 있습니다.

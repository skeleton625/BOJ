# 백준 2261 번 문제풀이

해당 문제는 분할 정복 알고리즘을 사용해 문제를 풀이했습니다.

먼저 전체 점들에 대해 **x축의 중앙**을 기준으로 왼쪽, 오른쪽 집단으로 나눌 수 있습니다.

이러한 방법으로 **집단을 계속 분할해** 점 개수가 2, 3개만 남는 최소 규모의 집단들을 구할 수 있고 각 집단의 최단 거리를 구하고 **모든 집단의 최단 거리를 비교해** 전체 최단 거리를 구할 수 있게 됩니다.

하지만 분할을 할 때, **중앙을 사이에 둔 두 점**의 최단 거리가 **더 짧을 수 있기 때문에** 각 집단의 **중앙을 사이에 둔 두 점의 최단 거리**를 비교하는 과정을 거쳐야 합니다.

위의 집단을 구성할 때, 모든 점들을 비교할 필요는 없으므로 왼쪽, 오른쪽 집단에서 얻은 최단 거리(d)를 사용해 **x축 중앙을 기준으로 최단 거리(d) 내에 있는 점들**로 집단을 구성합니다.

하지만 **x축 기준으로만 생성된 집단이기 때문에** 왼쪽, 오른쪽 최소 집단보다 **비교할 점의 개수가 많을 수** 있습니다.

그렇기에 여기서 구한 점들은 각 점에 대해 **y축을 기준으로 최단 거리(d) 보다 멀리 떨어져 있는 점들**은 **비교에서 제외** 시킵니다. (여기서 y 값으로 최단 거리(d) 보다 멀면 두 점 사이의 거리는 최단 거리(d) 보다 크게 측정됩니다.)

이렇게 중앙을 사이에 둔 점 집단에 대한 최단 거리를 구할 수 있게 됩니다.

이러한 과정 (왼쪽, 중앙, 오른쪽 집단 분할) 거치게 되면 구할 수 있는 모든 집단에 대한 최단 거리를 구할 수 있게 되며, 각 집단의 최단 거리를 비교해 전체 점들에 대한 두 점의 최단 거리를 구할 수 있게 됩니다.
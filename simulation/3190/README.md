백준 알고리즘 3190 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

해당 코드는 시뮬레이션을 통해 문제를 풀이했습니다.

처음으로 주의해아할 점은 뱀의 처음 위치입니다. 

문제 내용에서 게임을 시작할 때 뱀의 머리가 맨위 맨좌측으로 이동하기 때문에, 게임이 시작하기 전 뱀의 위치는

1행 1열이 아닌 1행 0열이 됩니다.

두 번째로 주의해야할 점은 시작 시간입니다.

위에서 얘기한 것처럼 뱀의 처음 위치는 1행 0열이고 시작한 뒤 1행 1열로 이동하기 때문에 이동하면서 시간이 증가하므로

시간 변수는 0이 아닌 1로 초기화해줘야 합니다.

뱀의 몸통의 경우, 뱀의 머리가 이동한 위치를 표시해 주면서 사과를 먹을 경우, 길이가 늘어났으므로 그대로 두고 사과를

먹지 않았을 경우, 길이가 늘어나지 않기 때문에 현재 꼬리의 위치의 표시를 지워주는 식으로 진행할 경우, 보드 내에서

뱀의 위치를 표시할 수 있게 됩니다.
백준 알고리즘 11286 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

해당 코드는 우선순위 큐 자료형을 통해 문제를 풀이했습니다.

먼저 pair 자료형으로 우선순위 큐에 입력할 때, pair의 첫 번째 값으로 입력 값읠 절대값, 두 번째 값으로는 입력 값을

입력합니다. ( 해당 문제에서 정렬의 기준은 입력 값읠 절대값이므로)

우선순위 큐에 자료를 입력할 때 pair 자료형을 입력하는데 이 때, 최소값이 top으로 올라올 수 있도록 절대값을 음수로 만들어

입력해 줍니다.

또한 절대값이 같을 때도 더 작은 입력 값이 먼저 출력될 수 있도록 두 번째 값을 

뒤집어(양수는 음수, 음수는 양수) 입력해 줍니다.

나중에 0이 입력되어 출력할 때는 입력할 때 음수화 해줬기 때문에 원래 값으로 돌려주기 위해 다시 뒤집어 출력해 줍니다. 

백준 알고리즘 4195 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

해당 코드는 Union Find, Map을 활용해 문제를 풀이했습니다.

기존에 있던 Union Find 알고리즘에서 사용했던 배열을 Map 자료구조로 변경해 집합의 형식을 문자열 형식으로 변경했습니다.

( Union Find에서 집합을 합하거나 찾을 때, 문자열을 통해서 찾을 수 있도록 하기 위함 )

그 다음, 네트워크내의 노드 개수를 파악할 수 있도록 집합을 합할 때, 그 집합의 노드 개수도 합할 수 있도록 합병 함수를

수정했습니다.

코드에 대한 자세한 내용은 주석으로 추가했습니다.

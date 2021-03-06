# 백준 14500 번 문제 풀이

	해당 문제는 DFS 알고리즘을 사용해 문제를 풀이했습니다.

	문제에서 주어진 폴리오미노 도형들을 살펴볼 경우, 폴리오미노가 회전 및 대칭한 상태들을 포함해
	
	모두 한 점에서 상, 하, 좌, 우로 4번 이동하면 만들 수 있음을 알 수 있습니다.

	그러므로 해당 문제는 한 점에 대해 최대 4칸만 이동하도록 조건을 부여한 뒤, 각 점에 대한 모든 
	
	값을 더하면 각 점 위치에 대한 모든 폴리오미노 값을 구할 수 있게 됩니다.

	이 과정을 DFS, 또는 BFS로 구현한 뒤, 한 점에 대한 폴리오미노 최대값을 구하여 모든 점에 되한

	최대값을 비교하면 해당 문제를 해결할 수 있습니다.

	하지만 BFS의 경우, 한 점에 대해 폴리오미노 최대값을 찾을 때마다 방문 배열을 완전 초기화해줘야

	하기 때문에, 속도상에서 문제가 생기게 됩니다.

	그렇기 때문에 방문 배열의 부분 초기화가 가능한 DFS 알고리즘을 사용해 문제를 해결했습니다.

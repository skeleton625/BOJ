## 백준 알고리즘 1912번 문제 풀이

	해당 문제는 캐시와 다이나믹 프로그래밍을 사용해 문제를 풀이했습니다.

	문제는 주어진 숫자열들의 연속된 숫자들에 합 중, 최대가 되는 연속합을 구하는 것입니다.

	먼저 연속합은 입력 숫자들의 각 자리까지의 합을 통해 구할 수 있습니다.

	하지만 구해진 연속합이 음수가 되거나 주어진 숫자보다 작을 경우, 계속해서 이전의 연속

	합을 사용할 필요가 없게 됩니다.

	즉, 현재 주어진 숫자와 지금까지의 연속합을 비교해 최대가 되는 값을 현재의 연속합으로

	설정해줘야 합니다.

	점화식으로 표현하면 다음과 같습니다.

	D(x) = MAX( D(x-1) + N(x), N(x) )

		D(x) 현재 연속 합, N(x) 현재 주어진 숫자

	이를 통해 각 자리까지 최대가되는 연속합을 구할 수 있고, 그 값 중 최대가 되는 연속합을

	구할 수 있게 됩니다.

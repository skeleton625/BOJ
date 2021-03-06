백준 알고리즘 14848 문제 풀이를 완료했습니다.

해당 코드는 비트 연산자와 유클리드 호제법을 사용해 문제를 풀이했습니다.

문제는 1부터 입력된 숫자 n까지의 자연수에서 입력된 배열 A의 값들에 배수들을 제거하고 남은

숫자들의 개수를 출력하는 것입니다.

여기서 이 코드의 경우 전채 숫자 개수 n에서 제거할 숫자들의 개수를 파악하는 식으로 구현했습니다.

삭제하는 숫자들의 개수는 전체 숫자 n 내에 존재하는 배열 A 값의 배수들에 숫자를 통해서 구할 수 있습니다.

하지만 제외하는 과정에서 이미 제외한 배수를 중복으로 제외하는 경우가 발생할 수 있습니다.

그렇기 때문에 각 숫자들에 대한 최소공배수를 파악해 중복되는 경우를 제거해 줘야 합니다.

또한 중복되는 경우를 제거하는 과정에서 중복을 여러번 제거할 수도 있습니다.

그러므로 중복을 여러번 제거하는 경우에 대해서는 제거한 개수를 삭제할 숫자 개수에 추가해줘야 합니다.

위의 두 예외사항을 판별하는 방법은 최소공배수를 파악할 때, 선택된 숫자의 개수를 통해서 알 수 있습니다.

최소공배수를 구할 숫자의 개수가 짝수일 경우, 삭제할 숫자의 개수가 중복으로 입력된 경우이기 때문에

한 번은 제거해야 합니다.

반대로 숫자의 개수가 홀수일 경우, 여러번 중복을 제거한 숫자들이기 때문에 해당 숫자들에 대해선 삭제할

숫자에 추가를 해줘야 합니다.

이 모든 과정을 거치면 배열 A 값들의 배수에 개수를 제외한 나머지 숫자 개수를 구할 수 있게 됩니다.

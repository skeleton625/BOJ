백준 알고리즘 1062번 문제 풀이를 완료했습니다.

해당 코드는 백트래킹 알고리즘을 사용해 문제를 풀이했습니다.

문제는 입력된 개수의 알파벳만을 사용해 입력된 단어 중, 최대 몇 개를 만들 수 있는지 파악하는 것입니다.

입력에서 주어지는 모든 단어는 기본적으로 앞의 4 자리, 뒤의 4자리 즉, 기본적으로 

'a', 'c', 'i', 't', 'n' 의 알파벳이 필요합니다. 

그렇기 때문에 주어지는 알파벳 숫자의 개수가 5개를 넘지 못하는 경우 어떤 단어도 만들 수가 없습니다.

그 다음, 우리가 얻고자 하는 최대값은 주어진 알파벳 개수를 통해 만들 수 있는 단어의 최대 개수입니다.

그렇기 때문에 특정 알파벳의 순서가 아닌 포함 여부만을 판단하는 방식으로 백트래킹을 진행해 주면 됩니다.

그렇게 할 경우 시간 내에 해당 문제를 해결할 수 있게 됩니다.

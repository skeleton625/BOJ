백준 10420 문제 풀이 중입니다.

문제 풀이를 완료했습니다.

먼저 i1이 현재 달보다 클 때 동안 반복문을 실행합니다. 

실행하는 반복문 내에선 해당 달의 크기만큼 i1에서 빼주는 과정을 반복하면서 m을 1씩 증가시켜 줍니다.

만일 m이 13이 되버릴 경우 ( 달력의 달을 넘어버릴 경우 ) 1로 초기화 시켜주고 y를 1 증가시켜 줍니다.

y를 증가시켜주면서 해당 년의 2월달이 윤년인지 파악한 다음 그에 대한 작업을 2월 달에 처리해 줍니다.

마지막에 i1이 해당 달보다 작아질 경우 d와 i1을 더해준 다음, 해당 달이 d 보다 작을 경우 해당 달에서

d를 빼즈고 m을 1 증가시켜 줍니다. ( 다음 달로 이동 )

여기서 또한 m이 13이 되버릴 경우 위와 같이 m을 1로 초기화 시켜주고 y를 1 증가시켜 줍니다.

기준 날짜를 4월 1일로 결정한 이유는 4월 2일부터 커플이 된 날로 1일에 해당하기 때문에 계산하기 편하도록 기준 날짜를

4월 1일로 설정했습니다.

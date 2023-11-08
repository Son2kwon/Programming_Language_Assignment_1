# Programming_Language_Assignment_1
Recursive-Descent Parsing

Approach
1. txt파일 open
2. 문장을 읽어와 ';'까지 저장. txt파일의 cursor는 ';' 바로 뒤로 설정.
3. 공백을 기준으로 구분(Lexeme 생성)
4. look_ahead으로 correct RHS를 찾음
     <statements>는 look_ahead로 <semi_colon>을 찾음
     <term_tail>, <factor_tail>, <factor>는 바로 다음 token 확인
6. Parsing
7. Parsing 중에 Error가 생긴다면, Error 메세지 출력
    각 상황에 맞는 Error 메세지 출력
8. terminal에 도착하면 identifier, operation, constant의 개수 +1
9. 다음 문장 똑같이 진행.
10. 마지막에는 연산 결과를 보여줌.

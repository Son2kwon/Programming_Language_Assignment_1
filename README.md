# Programming_Language_Assignment_1
Recursive-Descent Parsing

Approach
1. txt파일 open
2. ';'을 기준으로 getline
3. lexeme으로 나눔
4. look_ahead으로 correct RHS를 찾음
5. Parsing
6. Parsing 하다가 문제 생기면 warning 후, 고친 후 parsing 계속
7. terminal에 도착하면 identifier, operation, constant의 개수 +1
8. 맨 마지막 결과로 warning 및 <ident>의 개수를 출력

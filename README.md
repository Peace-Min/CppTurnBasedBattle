# C++ Turn-Based Battle

C# 개발자가 C++의 객체 수명, 소유권, 다형성, STL, GoogleTest를 연습하기 위한 작은 콘솔 프로젝트입니다.

## 목표

- 플레이어와 무기를 헤더/소스 파일로 분리한다.
- `std::unique_ptr`와 `std::vector`로 객체 소유권을 표현한다.
- 인터페이스와 가상 함수로 다형성을 구현한다.
- 기능을 GoogleTest로 검증한다.
- 실행 프로젝트와 테스트 프로젝트를 분리한다.

## 시작 순서

1. [설계서](docs/design.md)를 읽습니다.
2. [작업지시서](docs/tasks.md)의 T01부터 순서대로 구현합니다.
3. 각 작업의 완료조건을 확인하고, 막히는 코드는 질문합니다.

## 권장 솔루션 구조

```text
BattleCore       게임 규칙과 도메인 클래스
BattleApp        콘솔 실행 프로그램
BattleTests      GoogleTest 테스트 프로젝트
```

현재 저장소에는 문서만 있으며, 코드는 작업지시서에 따라 직접 추가합니다.

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

## 솔루션 구조

```text
CppTurnBasedBattle.sln
├── BattleCore    정적 라이브러리 프로젝트
├── BattleApp     콘솔 실행 프로그램 프로젝트
└── BattleTests   테스트 실행 프로젝트
```

## Visual Studio에서 빌드와 실행

Visual Studio 2022와 C++ 데스크톱 개발 도구가 필요합니다. 프로젝트는 C++20을 사용합니다.

1. `CppTurnBasedBattle.sln`을 엽니다.
2. 구성에서 `Debug`와 `x64`를 선택합니다.
3. 솔루션을 빌드합니다.
4. `BattleApp`을 시작 프로젝트로 선택하고 실행합니다.

`BattleApp`과 `BattleTests`는 프로젝트 참조를 통해 `BattleCore`를 사용합니다.

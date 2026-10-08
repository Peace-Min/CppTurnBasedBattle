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

## 빌드와 실행

Visual Studio 2022, CMake 3.20 이상, C++17 컴파일러가 필요합니다. GoogleTest는 CMake가 첫 구성 단계에서 내려받습니다.

```powershell
cmake -S . -B build
cmake --build build --config Debug
ctest --test-dir build -C Debug --output-on-failure
.\build\Debug\BattleApp.exe
```

Visual Studio에서는 `CMakeLists.txt`가 있는 폴더를 열면 됩니다. `BattleCore`는 정적 라이브러리이고, `BattleApp`과 `BattleTests`가 이를 사용합니다.

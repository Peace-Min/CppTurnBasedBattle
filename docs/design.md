# 설계서

## 1. 범위

두 명의 플레이어가 번갈아 공격하는 콘솔 기반 턴제 전투를 만든다.

이번 연습에서는 GUI, 네트워크, 데이터베이스, 저장 기능을 만들지 않는다.

## 2. 핵심 규칙

- 플레이어는 이름, 체력, 무기를 가진다.
- 무기는 이름과 공격력을 가진다.
- 공격 시 대상의 체력이 공격력만큼 감소한다.
- 체력은 0 아래로 내려가지 않는다.
- 체력이 0이면 사망 상태다.
- 살아 있는 플레이어만 공격할 수 있다.
- 한 턴에는 한 번만 공격한다.
- 한 명이 사망하면 전투가 끝난다.

## 3. 권장 클래스 구조

### `Weapon`

값 타입으로 사용한다. 플레이어가 무기를 소유하는 경우에는 값 멤버로 두고, 외부 무기를 빌려 쓰는 경우에는 참조를 사용한다.

```cpp
class Weapon {
public:
    Weapon(std::string name, int damage);
    const std::string& name() const;
    int damage() const;
};
```

### `IPlayer`

다형성의 기준이 되는 인터페이스다.

```cpp
class IPlayer {
public:
    virtual ~IPlayer() = default;
    virtual void attack(IPlayer& target) = 0;
    virtual bool is_alive() const = 0;
};
```

### `Player`

공통 상태와 공통 동작을 보관하는 기본 클래스다. `Archer`와 `Warrior`가 중복 코드를 갖기 시작할 때 도입한다.

```text
IPlayer
   ↑
 Player
  ↙  ↘
Archer Warrior
```

처음부터 능력치 시스템, 이벤트 버스, 팩토리 패턴을 추가하지 않는다.

## 4. 소유권 규칙

- `Battle`은 플레이어를 소유한다. `std::vector<std::unique_ptr<IPlayer>>`를 사용한다.
- `Player`는 자신의 무기를 값으로 소유하거나 `std::unique_ptr<Weapon>`으로 소유한다.
- 소유하지 않는 객체를 잠시 사용할 때만 `T&` 또는 `const T&`를 사용한다.
- `std::shared_ptr`는 실제 공동 소유가 필요할 때까지 사용하지 않는다.
- 소유하지 않는 raw pointer는 이번 프로젝트에서 사용하지 않는다.

## 5. 테스트 기준

각 기능은 먼저 실패하는 테스트를 작성하고 구현한다.

최소 테스트 목록:

- 무기 이름과 공격력이 저장된다.
- 공격하면 대상 체력이 감소한다.
- 체력이 0 아래로 내려가지 않는다.
- 체력이 0인 플레이어는 사망 상태다.
- 사망한 플레이어는 공격할 수 없다.
- 궁수와 전사는 같은 인터페이스로 호출된다.

## 6. 완료 상태

콘솔에서 두 플레이어가 번갈아 공격하고 승자가 출력된다. `BattleTests`의 모든 테스트가 통과해야 한다.

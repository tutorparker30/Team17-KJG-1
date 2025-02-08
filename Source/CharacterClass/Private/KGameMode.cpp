#include "KGameMode.h"
#include "KCharacter.h"

AKGameMode::AKGameMode()
{
	DefaultPawnClass = AKCharacter::StaticClass(); // 게임 실행 시 캐릭터가 월드에 자동 스폰 됨.(기본 폰클래스 설정.)
}

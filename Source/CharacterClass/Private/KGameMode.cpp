#include "KGameMode.h"
#include "KCharacter.h"
#include "KPlayerController.h"

AKGameMode::AKGameMode()
{
	DefaultPawnClass = AKCharacter::StaticClass(); //게임 실행 시 캐릭터가 월드에 자동 스폰 됨.(기본 폰클래스 설정.)
	PlayerControllerClass = AKPlayerController::StaticClass(); //게임 모드에 플레이어 컨트롤러 설정.
}

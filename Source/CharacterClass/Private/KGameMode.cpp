#include "KGameMode.h"
#include "KCharacter.h"
#include "KPlayerController.h"

AKGameMode::AKGameMode()
{
	DefaultPawnClass = AKCharacter::StaticClass(); //���� ���� �� ĳ���Ͱ� ���忡 �ڵ� ���� ��.(�⺻ ��Ŭ���� ����.)
	PlayerControllerClass = AKPlayerController::StaticClass(); //���� ��忡 �÷��̾� ��Ʈ�ѷ� ����.
}

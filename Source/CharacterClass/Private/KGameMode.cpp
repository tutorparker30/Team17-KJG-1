#include "KGameMode.h"
#include "KCharacter.h"

AKGameMode::AKGameMode()
{
	DefaultPawnClass = AKCharacter::StaticClass(); // ���� ���� �� ĳ���Ͱ� ���忡 �ڵ� ���� ��.(�⺻ ��Ŭ���� ����.)
}

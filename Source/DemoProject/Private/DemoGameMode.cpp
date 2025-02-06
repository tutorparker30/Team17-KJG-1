#include "DemoGameMode.h"
#include "DemoCharacter.h"
#include "DemoPlayerController.h"

ADemoGameMode::ADemoGameMode()
{
	DefaultPawnClass = ADemoCharacter::StaticClass();
	PlayerControllerClass = ADemoPlayerController::StaticClass();
}

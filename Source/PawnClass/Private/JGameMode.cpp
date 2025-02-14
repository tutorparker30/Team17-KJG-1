#include "JGameMode.h"
#include "JPawn.h"
#include "JPlayerController.h"
#include "JGameState.h"

AJGameMode::AJGameMode()
{
	DefaultPawnClass = AJPawn::StaticClass();
	PlayerControllerClass = AJPlayerController::StaticClass();
	GameStateClass = AJGameState::StaticClass();
}


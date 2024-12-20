#include "../../header/Player/PlayerService.h"
#include "../../header/Player/PlayerController.h"

namespace Player
{
	PlayerService::PlayerService()
	{
		player_controller = new PlayerController();
	}

	PlayerService::~PlayerService()
	{
		Destroy();
	}

	void PlayerService::Initialize()
	{
		player_controller->Initialize();
	}

	void PlayerService::Update()
	{
		player_controller->Update();
	}

	void PlayerService::Render()
	{
		player_controller->Render();
	}
	
	void PlayerService::Destroy()
	{
		delete(player_controller);
	}

	void PlayerService::takeDamage()
	{
		player_controller->takeDamage();
	}

	void PlayerService::levelComplete()
	{
		player_controller->reset();
	}
}
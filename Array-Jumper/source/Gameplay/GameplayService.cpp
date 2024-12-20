#include "../../header/Gameplay/GameplayService.h"

namespace Gameplay
{
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}

	GameplayService::~GameplayService()
	{

	}

	void GameplayService::initialize()
	{
		gameplay_controller->initialize();
	}

	void GameplayService::render()
	{
		gameplay_controller->render();
	}

	void GameplayService::update()
	{
		gameplay_controller->update();
	}

	void GameplayService::destroy()
	{
		delete(gameplay_controller);
	}

	void GameplayService::onPositionChanged(int position)
	{
		gameplay_controller->onPositionChanged(position);
	}
}
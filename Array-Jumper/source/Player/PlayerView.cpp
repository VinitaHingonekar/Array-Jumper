#include "../../header/Player/PlayerView.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

using namespace UI::UIElement;
using namespace Global;

namespace Player
{
	PlayerView::PlayerView()
	{
		game_window = nullptr;
		player_image = new ImageView();
	}

	PlayerView::~PlayerView() {}

	void PlayerView::initialize()
	{
	
	}

	void PlayerView::update()
	{
	
	}

	void PlayerView::render()
	{
	
	}

	//Inititailize

	void PlayerView::CalculatePlayerDimensions()
	{
		player_width = 1000.f;
		player_height = 1000.f;
	}

	void PlayerView::InitializePlayerImage()
	{
		player_image->initialize(Config::character_texture_path,
								 player_width,
								 player_height,
								 sf::Vector2f(0,0)
								); 
	}

	void PlayerView::LoadPlayer()
	{
		CalculatePlayerDimensions();
		InitializePlayerImage();
	}

	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		LoadPlayer();

	}

	// Update

	sf::Vector2f PlayerView::CalulcatePlayerPosition()
	{
		return sf::Vector2f(0, 0);
	}

	void PlayerView::UpdatePlayerPosition()
	{
		player_image->setPosition(CalulcatePlayerPosition());
	}

	// Render

	void PlayerView::DrawPlayer()
	{
		player_image->render();
	}


}
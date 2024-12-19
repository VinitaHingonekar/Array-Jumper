#include "../../header/Player/PlayerView.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerController.h"
#include "../../header/Global/Config.h"
#include "../../header/Global/ServiceLocator.h"

using namespace UI::UIElement;
using namespace Global;

namespace Player
{
	PlayerView::PlayerView(PlayerController* controller)
	{
		player_controller = controller;
		player_image = new ImageView();
		game_window = nullptr;
	}

	PlayerView::~PlayerView() {}

	void PlayerView::initialize()
	{
		game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
		LoadPlayer();
	}

	void PlayerView::update()
	{
		updatePlayerPosition();
	}

	void PlayerView::render()
	{
		switch (player_controller->GetPlayerState())
		{
			case PlayerState::ALIVE:
				DrawPlayer();
				break;

		}
	}

	//Inititailize

	void PlayerView::CalculatePlayerDimensions()
	{
		current_box_dimensions = ServiceLocator::getInstance()->getLevelService()->getBoxDimensions();
		player_height = current_box_dimensions.box_height;
		player_width = current_box_dimensions.box_width;
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

	// Update

	sf::Vector2f PlayerView::CalulcatePlayerPosition()
	{
		float xPosition = current_box_dimensions.box_spacing + static_cast<float>(player_controller->getCurrentPosition()) * (current_box_dimensions.box_width + current_box_dimensions.box_spacing);
		float yPosition = static_cast<float>(game_window->getSize().y) - current_box_dimensions.box_height - current_box_dimensions.bottom_offset - player_height;
		return sf::Vector2f(xPosition, yPosition);
	}

	void PlayerView::updatePlayerPosition()
	{
		player_image->setPosition(CalulcatePlayerPosition());
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
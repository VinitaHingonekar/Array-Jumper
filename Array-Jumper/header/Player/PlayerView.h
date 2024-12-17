#pragma once
#include "../../header/UI/UIElement/ImageView.h"

namespace Player
{
	class PlayerController;

	class PlayerView
	{
	private:
		sf::RenderWindow* game_window;
		UI::UIElement::ImageView* player_image;

		PlayerController* player_controller;

		float player_height;
		float player_width;

		void InitializePlayerImage();
		void DrawPlayer();
		void LoadPlayer();
		void CalculatePlayerDimensions();
		void UpdatePlayerPosition();
		sf::Vector2f CalulcatePlayerPosition();

	public:
		PlayerView(PlayerController* player_controller);
		~PlayerView();

		void initialize();
		void update();
		void render();
	};
}
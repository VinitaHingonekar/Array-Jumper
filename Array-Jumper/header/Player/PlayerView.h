#pragma once
#include "../../header/UI/UIElement/ImageView.h"

namespace Player
{
	class PlayerView
	{
	private:
		sf::RenderWindow* game_window;
		UI::UIElement::ImageView* player_image;

		float player_height;
		float player_width;

		void InitializePlayerImage();
		void DrawPlayer();
		void LoadPlayer();
		void CalculatePlayerDimensions();
		void UpdatePlayerPosition();
		sf::Vector2f CalulcatePlayerPosition();

	public:
		PlayerView();
		~PlayerView();

		void initialize();
		void update();
		void render();
	};
}
#pragma once


namespace Player
{
	class PlayerController;

	class PlayerService
	{
	private:
		PlayerController *player_controller;

		void Destroy();

	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		void Render();

		void takeDamage();
		void levelComplete();

		int getCurrentLives();
	};
}
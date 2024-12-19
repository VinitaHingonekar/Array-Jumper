#pragma once

namespace Player
{
	class PlayerModel;
	class PlayerView;
	enum class PlayerState;

	class PlayerController
	{
	private:
		PlayerModel* player_model;
		PlayerView* player_view;

		void Destroy();

	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		void Render();

		PlayerState GetPlayerState() const;
		void SetPlayerState(PlayerState new_state);

		int getCurrentPosition();
	};
}
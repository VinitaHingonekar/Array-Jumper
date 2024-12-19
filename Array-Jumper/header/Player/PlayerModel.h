#pragma once
namespace Player
{
	enum class PlayerState
	{
		ALIVE,
		DEAD
	};

	class PlayerModel
	{
	private:
		PlayerState player_state;
		int current_position;

	public:
		void initialize();
		PlayerState GetPlayerState() const;
		void SetPlayerState(PlayerState new_state);

		int GetCurrentPosition();
		void SetCurrentPosition(int pos);
	};
}
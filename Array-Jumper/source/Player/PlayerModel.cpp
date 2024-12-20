#include "../../header/Player/PlayerModel.h"

namespace Player
{
		void Player::PlayerModel::initialize()
		{
			//Yet to implement
		}

		PlayerState PlayerModel::GetPlayerState() const
		{
			return player_state;
		}

		void PlayerModel::SetPlayerState(PlayerState new_state)
		{
			player_state = new_state;
		}

		int PlayerModel::GetCurrentPosition()
		{
			return current_position;
		}

		void PlayerModel::SetCurrentPosition(int new_position)
		{
			current_position = new_position;
		}

		void PlayerModel::resetPlayer()
		{
			current_position = 0;
			player_state = PlayerState::ALIVE;
			current_lives = max_lives;
		}

		int PlayerModel::getCurrentLives()
		{
			return current_lives;
		}

		void PlayerModel::decrementLife() 
		{ 
			current_lives--; 
		}

		void PlayerModel::resetPosition()
		{
			current_position = 0;
		}
}
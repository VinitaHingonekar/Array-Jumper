#include "../../header/Player/PlayerModel.h"

namespace Player
{
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
}
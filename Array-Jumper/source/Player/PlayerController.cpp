#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"

namespace Player
{

	PlayerController::PlayerController()
	{
		player_model = new PlayerModel();
		player_view = new PlayerView(this);
	}

	PlayerController::~PlayerController()
	{
		Destroy();
	}

	void PlayerController::Initialize()
	{
		player_model->initialize();
		player_view->initialize();
	}

	void PlayerController::Update()
	{
		player_view->update();
	}

	void PlayerController::Render()
	{
		player_view->render();
	}

	void PlayerController::Destroy()
	{
		delete(player_model);
		delete(player_view);
	}

	PlayerState PlayerController::GetPlayerState() const
	{
		return player_model->GetPlayerState();
	}

	void PlayerController::SetPlayerState(PlayerState new_state)
	{
		player_model->SetPlayerState(new_state);
	}

	int PlayerController::getCurrentPosition()
	{
		return player_model->GetCurrentPosition();
	}
}
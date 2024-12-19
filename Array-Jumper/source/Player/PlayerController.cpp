#include "../../header/Player/PlayerController.h"
#include "../../header/Player/PlayerModel.h"
#include "../../header/Player/PlayerView.h"
#include "../../header/Player/MovementDirection.h"
#include "../../header/Global/ServiceLocator.h"
#include "../../header/Sound/SoundService.h"

using namespace Global;
using namespace Sound;


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

		event_service = ServiceLocator::getInstance()->getEventService();
	}

	void PlayerController::Update()
	{
		player_view->update();
		readInput();
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

	void PlayerController::move(MovementDirection direction)
	{
		int steps, targetPosition;
		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = 1;
			break;
		case MovementDirection::BACKWARD:
			steps = -1;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = player_model->GetCurrentPosition() + steps;

		if (!isPositionInBound(targetPosition))
			return;

		player_model->SetCurrentPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::MOVE);
	}

	bool PlayerController::isPositionInBound(int targetPosition)
	{
		if (targetPosition >= 0 && targetPosition < LevelData::NUMBER_OF_BOXES)
			return true;
		return false;
	}

	void PlayerController::readInput()
	{
		if (event_service->pressedRightArrowKey() || event_service->pressedDKey())
		{
			if (event_service->heldSpaceKey())
				jump(MovementDirection::FORWARD);
			else
				move(MovementDirection::FORWARD);
		}
		if (event_service->pressedLeftArrowKey() || event_service->pressedAKey())
		{
			if (event_service->heldSpaceKey())
				jump(MovementDirection::BACKWARD);
			else
				move(MovementDirection::BACKWARD);
		}
	}

	/*BlockType PlayerController::getCurrentBoxValue(int currentPosition)
	{
		return current_level_data.level_boxes[currentPosition];
	}*/

	void PlayerController::jump(MovementDirection direction)
	{
		int current_position = player_model->GetCurrentPosition();
		BlockType box_value = ServiceLocator::getInstance()->getLevelService()->getCurrentBoxValue(current_position);
		int steps, targetPosition;

		switch (direction)
		{
		case MovementDirection::FORWARD:
			steps = box_value;
			break;
		case MovementDirection::BACKWARD:
			steps = -box_value;
			break;
		default:
			steps = 0;
			break;
		}

		targetPosition = current_position + steps;

		if (!isPositionInBound(targetPosition))
			return;

		player_model->SetCurrentPosition(targetPosition);
		ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::JUMP);
	}
}
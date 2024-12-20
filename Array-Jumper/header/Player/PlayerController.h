#pragma once
#include "../Event/EventService.h"
#include "../Gameplay/GameplayService.h"
#include "MovementDirection.h"
#include "../../header/Level/BlockType.h"

using namespace Event;
using namespace Level;
using namespace Gameplay;

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

		void move(MovementDirection direction);
		bool isPositionInBound(int targetPosition);

		PlayerState GetPlayerState() const;
		void SetPlayerState(PlayerState new_state);

		int getCurrentPosition();

		EventService* event_service;
		GameplayService* gameplay_service;

		void readInput();
		//BlockType getCurrentBoxValue(int currentPosition);
		Level::BlockType getCurrentBoxValue(int currentPosition);
		void jump(MovementDirection direction);

		void takeDamage();
	};
}
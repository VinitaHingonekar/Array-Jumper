#pragma once
#include "../Event/EventService.h"
#include "MovementDirection.h"

using namespace Event;
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
		void readInput();
	};
}
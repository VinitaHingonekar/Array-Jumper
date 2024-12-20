#pragma once
#include "../../header/Level/BlockType.h"

namespace Gameplay
{
	enum BlockType;

	class GameplayController
	{
	private:


	public:
		GameplayController();
		~GameplayController();

		void initialize();
		void render();
		void update();

		void processObstacle();
		bool isObstacle(Level::BlockType value);
		void onPositionChanged(int position);
		bool isEndBlock(Level::BlockType value);

		void processEndBlock();
	};
}
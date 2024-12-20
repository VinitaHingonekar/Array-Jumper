#pragma once
#include "LevelModel.h"

namespace Level
{
	class LevelView;
	class LevelModel;

	class LevelController
	{
	private:
		LevelModel* level_model;
		LevelView* level_view;

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

		BlockType getCurrentBoxValue(int currentPosition);
		BoxDimensions getBoxDimensions();

		bool isLastLevel();
		void loadNextLevel();
		int getCurrentLevelNumber();

		void resetLevels();
	};
}
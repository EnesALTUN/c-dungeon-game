#pragma once
class Game
{
	int _totalScore;
	int _hiScore;
	int _readHiScore;

public:
	Game(int totalScore, int hiScore, int readHiScore)
	{
		this->_totalScore = totalScore;
		this->_hiScore = hiScore;
		this->_readHiScore = readHiScore;
	}

	#pragma region Getter Setter
	void setFullVariable(int totalScore, int hiScore)
	{
		this->_totalScore = totalScore;
		this->_hiScore = hiScore;
	}

	void setTotalScore(int totalScore) {
		this->_totalScore = totalScore;
	}

	int getTotalScore() {
		return _totalScore;
	}

	void setHiScore(int hiScore) {
		this->_hiScore = hiScore;
	}

	int getHiScore() {
		return _hiScore;
	}

	void setReadHiScore(int readHiScore) {
		this->_readHiScore = readHiScore;
	}

	int getReadHiScore() {
		return _readHiScore;
	}
	#pragma endregion
};


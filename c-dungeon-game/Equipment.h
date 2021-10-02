#pragma once
class Equipment
{
	int _effect;
	int _count;
	int _cost;

public:
	Equipment(int effect, int count, int cost)
	{
		this->_effect = effect;
		this->_count = count;
		this->_cost = cost;
	}

	#pragma region Getter Setter
	void setFullVariable(int effect, int count)
	{
		this->_effect = effect;
		this->_count = count;
	}

	void setEffect(int effect) {
		this->_effect = effect;
	}

	int getEffect() {
		return _effect;
	}

	void setCount(int count) {
		this->_count = count;
	}

	int getCount() {
		return _count;
	}

	void setCost(int cost) {
		this->_cost = cost;
	}

	int getCost() {
		return _cost;
	}
	#pragma endregion
};


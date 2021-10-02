#pragma once
class Mob
{
	int _healt;
	int _maxHealt;
	int _attack;
	int _experience;
	
public:
	Mob(int healt, int maxHealt, int attack, int experience)
	{
		this->_healt = healt;
		this->_maxHealt = maxHealt;
		this->_attack = attack;
		this->_experience = experience;
	}

	#pragma region Getter Setter
	void setHealt(int healt) {
		this->_healt = healt;
	}

	int getHealt() {
		return _healt;
	}

	void setMaxHealt(int maxHealt) {
		this->_maxHealt = maxHealt;
	}

	int getMaxHealt() {
		return _maxHealt;
	}

	void setAttack(int attack) {
		this->_attack = attack;
	}

	int getAttack() {
		return _attack;
	}

	void setExperience(int experience) {
		this->_experience = experience;
	}

	int getExperience() {
		return _experience;
	}
	#pragma endregion
};


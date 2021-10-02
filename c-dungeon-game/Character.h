#pragma once
class Character
{
	int _healt;
	int _maxHealt;
	int _attack;
	int _gold;
	int _level;
	int _experience;
	int _statusScore;
	int _criticalChance;
	int _extraExperience;
	int _dodgeChance;
	double _debt;
	
public:
	Character(int healt, int maxHealt, int attack, int gold, int level, int experience, int statusScore, int criticalChance, int extraExperience, int dodgeChance, double debt)
	{
		this->_healt = healt;
		this->_maxHealt = maxHealt;
		this->_attack = attack;
		this->_gold = gold;
		this->_level = level;
		this->_experience = experience;
		this->_statusScore = statusScore;
		this->_criticalChance = criticalChance;
		this->_extraExperience = extraExperience;
		this->_dodgeChance = dodgeChance;
		this->_debt = debt;
	}

	#pragma region Getter Setter
	void setFullVariable(int healt, int maxHealt, int attack, int gold, int level, int experience, int statusScore, int criticalChance, int extraExperience, int dodgeChance, double debt) {
		this->_healt = healt;
		this->_maxHealt = maxHealt;
		this->_attack = attack;
		this->_gold = gold;
		this->_level = level;
		this->_experience = experience;
		this->_statusScore = statusScore;
		this->_criticalChance = criticalChance;
		this->_extraExperience = extraExperience;
		this->_dodgeChance = dodgeChance;
		this->_debt = debt;
	}

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

	void setGold(int gold) {
		this->_gold = gold;
	}

	int getGold() {
		return _gold;
	}

	void setLevel(int level) {
		this->_level = level;
	}

	int getLevel() {
		return _level;
	}

	void setExperience(int experience) {
		this->_experience = experience;
	}

	int getExperience() {
		return _experience;
	}

	void setStatusScore(int statusScore) {
		this->_statusScore = statusScore;
	}

	int getStatusScore() {
		return _statusScore;
	}

	void setCriticalChance(int criticalChance) {
		this->_criticalChance = criticalChance;
	}

	int getCriticalChance() {
		return _criticalChance;
	}

	void setExtraExperience(int extraExperience) {
		this->_extraExperience = extraExperience;
	}

	int getExtraExperience() {
		return _extraExperience;
	}

	void setDodgeChance(int dodgeChance) {
		this->_dodgeChance = dodgeChance;
	}

	int getDodgeChance() {
		return _dodgeChance;
	}

	void setDebt(int debt) {
		this->_debt = debt;
	}

	double getDebt() {
		return _debt;
	}
	#pragma endregion
};
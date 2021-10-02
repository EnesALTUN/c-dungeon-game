#pragma once
class Pet
{
	int _level;
	int _experience;
	int _petReturn;

public:
	Pet(int level, int experience, int petReturn)
	{
		this->_level = level;
		this->_experience = experience;
		this->_petReturn = petReturn;
	}

	#pragma region Getter Setter
	void setFullVariable(int level, int experience)
	{
		this->_level = level;
		this->_experience = experience;
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

	void setPetReturn(int petReturn) {
		this->_petReturn = petReturn;
	}

	int getPetReturn() {
		return _petReturn;
	}
	#pragma endregion
};


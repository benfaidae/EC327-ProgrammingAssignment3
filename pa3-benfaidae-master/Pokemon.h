#ifndef POKEMON_H
#define POKEMON_H

#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include <string>
#include <iostream>



class Pokemon: public GameObject {

enum PokemonStates {
	STOPPED = 0,
	MOVING = 1,
	EXHAUSTED = 2,
	IN_GYM = 3,
	IN_CENTER = 4,
	MOVING_TO_GYM = 5,
	MOVING_TO_CENTER = 6,
	TRAINING_IN_GYM = 7,
	RECOVERING_STAMINA = 8
};

public:
	Pokemon();
	Pokemon(char in_code);
	Pokemon(std::string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc);

	void StartMoving(Point2D dest);
	void StartMovingToCenter(PokemonCenter* center);
	void StartMovingToGym(PokemonGym* gym);
	void StartTraining(unsigned int num_training_units);
	void StartRecoveringStamina(unsigned int num_stamina_points);
	void Stop();
	bool IsExhausted();
	bool ShouldBeVisible();
	void ShowStatus();
	bool Update();

protected:
	bool UpdateLocation();
	void SetupDestination(Point2D dest);

private:
	double speed;
	bool is_in_gym; 
	bool is_in_center; 
	unsigned int stamina; 
	unsigned int pokemon_dollars; 
	unsigned int training_units_to_buy;
	unsigned int stamina_points_to_buy;
	std::string name;

	PokemonCenter* current_center;
	PokemonGym* current_gym;
	Point2D destination;
	Vector2D delta;

};

double GetRandomAmountOfPokemonDollars(); 

#endif
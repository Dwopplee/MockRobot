/*
 * main.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: CPark
 */


#include "RobotMock.hpp"
#include "Timer.hpp"

enum class State {
	idle,
	opening,
	dropping,
	closing,
	lifting
    // Define state names here
};

int main() {
    RobotMock robot;
    State state = State::idle;   // Assign the initial state here
    Timer timer;

    while (1) {
    	// State machine logic goes here. Recommend switch-case structure.
    	switch(state){
    	case State::idle:
    		std::cout<<"entered idle state";
    		robot.SetSetpoint(2);
    		while(robot.GetPressed() == false){


    		}
    		while(robot.AtSetpoint() == false){

    		}
    		state State::idle;
    		break;
    	case State::opening:
    		std::cout<<"entered opening state";
    		robot.SetClaw(false);
    		while(robot.SetClaw == true){

    		}
    		state = State::dropping;
    		break;
    	case State::dropping:
    		std::cout<<"entered dropping state";
    		robot.SetSetpoint(1);
    		while(robot.AtSetpoint() == false){

    		}
    		state = State::closing;
    		break;
    	case State::closing:
    		std::cout<<"entered closing state";
    		robot.SetClaw(true);
    		while(robot.GetClaw() == false){

    		}
    		state = State::lifting;
    		break;
    	case State::lifting:
    		std::cout<<"entered lifting state";
    		robot.SetSetpoint(2);
    		while(robot.AtSetpoint() == false){

    		}
    		state = State::idle;
    		break;
    	}
    }
}

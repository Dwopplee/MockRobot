/*
 * main.cpp
 *
 *  Created on: Jan 12, 2017
 *      Author: CPark
 */


#include "RobotMock.hpp"
#include "Timer.hpp"

#include <iostream>

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
    		std::cout<<"entered idle state \n";
    		robot.SetSetpoint(28.8);
    		if(robot.GetPressed() == true){
    			if(robot.AtSetpoint() == true){
    				state = State::idle;
    			}
    		}
    		break;
    	case State::opening:
    		std::cout<<"entered opening state \n";
    		robot.SetClaw(false);
    		if(robot.GetClaw() == false){
    			state = State::dropping;
    		}
    		break;
    	case State::dropping:
    		std::cout<<"entered dropping state \n";
    		robot.SetSetpoint(14.4);
    		if(robot.AtSetpoint() == true){
    			state = State::closing;
    		}
    		break;
    	case State::closing:
    		    		std::cout<<"entered closing state \n";
    		robot.SetClaw(true);
    		if(robot.GetClaw() == true){
    			state = State::lifting;
    		}
    		break;
    	case State::lifting:
    		std::cout<<"entered lifting state \n";
    		robot.SetSetpoint(28.8);
    		if(robot.AtSetpoint() == true){
    			state = State::idle;
    		}
    		break;
    	}
    }
}

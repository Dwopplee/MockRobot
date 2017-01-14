/*
 * Timer.hpp
 *
 *  Created on: Jan 12, 2017
 *      Author: CPark
 */

#ifndef TIMER_HPP_
#define TIMER_HPP_

#pragma once

#include <mutex>

/**
 * Timer objects measure accumulated time in seconds.
 * The timer object functions like a stopwatch. It can be started, stopped, and
 * cleared. When the timer is running its value counts up in seconds. When
 * stopped, the timer holds the current value. The implementation simply records
 * the time when started and subtracts the current time whenever the value is
 * requested.
 */
class Timer {
public:
    Timer();
    virtual ~Timer() = default;

    Timer(const Timer&) = delete;
    Timer& operator=(const Timer&) = delete;

    double Get() const;
    void Reset();
    void Start();
    void Stop();
    bool HasPeriodPassed(double period);

private:
    double m_startTime = 0.0;
    double m_accumulatedTime = 0.0;
    bool m_running = false;
    mutable std::mutex m_mutex;
};



#endif /* TIMER_HPP_ */

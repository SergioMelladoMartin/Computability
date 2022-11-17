#include "../lib/state.h"

/**
 * @brief Construct a new State:: State object
 * 
 * @param id 
 * @param isFinal 
 */
State::State(int id, bool isFinal) {
    this->id = id;
    this->isFinal = isFinal;
}

/**
 * @brief Get the Id object
 * 
 * @return int 
 */
int State::getId() const {
    return id;
}

/**
 * @brief Get the Is Final State object
 * 
 * @return true 
 * @return false 
 */
bool State::isFinalState() const {
    return isFinal;
}

/**
 * @brief Overload the < operator
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool State::operator<(const State& other) const {
    return this->id < other.id;
}


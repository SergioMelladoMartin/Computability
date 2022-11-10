#pragma once

/**
 * @brief State class
 * 
 */
class State {
  public:
    State(int, bool);
    int getId() const;
    bool isFinalState() const;

    bool operator< (const State&) const;
  
  private:
    int id;
    bool isFinal; 
};

/**
 * @brief Class that represents a coin
 * 
 */
class Coin {
  public:
    Coin(int value);
    
    int getValue() const;

  private:
    int value;
};
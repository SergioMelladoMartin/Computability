# Change Coins Problem
This repository contains a solution to the change coins problem using a greedy algorithm. The problem is as follows: given a target amount of money, find the minimum number of coins needed to make the exact amount of money using the coins and tickets   available in Euro currency.

## Execution
To run the program, follow these steps:

Open a terminal and navigate to the directory where the program is located.
Type make to build the program.
To run the program, type ./main <Amount> <Flags>.
The <Amount> parameter specifies the target amount of money, and the <Flags> parameter is optional. The following flags are available:

-b: Allow the program to use tickets, not only coins.
-e: Use an efficient algorithm.
-c: Print the results in a more readable format.

For example, to solve the change coins problem for an amount of 10.50 euros, using tickets, using the efficient algorithm and with a readable output, you would type ./main 10.50 -b -e -c. This would produce the following output:

```
Excuting the efficient algorithm O(m)...
Solution Set = { 10.00€ x 1  0.50€ x 1  }
Coins number = 2
```
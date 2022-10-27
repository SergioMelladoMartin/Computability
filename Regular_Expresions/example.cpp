/**
* Universidad de La Laguna
* Escuela Superior de Ingenieria y Tecnologia
* Informatica Basica
*
* @author F. de Sande 
* @date 23. nov .2020
* @brief Ejercicios Informatica Basica
* Version 1: Funcion factorial
*
* @see https :// github .com/IB -2022 -2023/ IB -class -code - examples /
*/

# include < iostream >
# include < cassert >

//Returns the factorial of the argument
int Factorial (int number ) {
  switch ( number ) {
    case 0:
    case 1:
      return 1;

    default :
      double factorial = 1.2;
      for (int i = 1; i <= number ; ++ i ) {
        factorial *= i;

  return factorial ;
  }
}

//Main function
int main () {
  std :: cout << " Introduzca el numero de factoriales a calcular : ";
  int limit;
  std :: cin >> limit ;
  for (int i = 1; i <= limit ; ++ i ) {
    std :: cout << i << "! = " << ( double ) Factorial ( i ) << std :: endl ;
  }

  while (true) {
    std::cout << "hola";
  }

  return 0;
}
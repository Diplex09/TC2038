README, by Aldo Degollado & Diego Velázquez

This activity solves the coin change problem with a greedy algorithm and the dynamic algorithm.


Caso de prueba 1, el algoritmo no debe de aceptar números de monedas negativos.
	Input Cuantas monedas: -2
	Output:Sorry, you inputed a invalid amount of coins, try again.


Caso de prueba 2, el algoritmo ávaro no debe de arrojar la mejor solución.
	Input Cuantas monedas: 4
	Input valores de monedas: 1, 3, 4, 5
	Input precio: 7
	Input cantidad a pagar: 14
	Output:
	~~~~~~~~~~~~~~~~~~~~~~~~~ DYNAMIC PROGRAMMING ALGORITHM ~~~~~~~~~~~~~~~~~~~~~~~~~

	The minimum amount of coins to give are 2.
	Given coins:
	4
	3

	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GREEDY ALGORITHM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	The amount of coins to give are 3.
	Given coins:
	5
	1
	1

Caso de prueba 3, caso promedio donde es posible devolver cambio.
	Input Cuantas monedas: 4
	Input valores de monedas: 1, 2, 5, 10
	Input precio: 42
	Input cantidad a pagar: 50
	Output:
	~~~~~~~~~~~~~~~~~~~~~~~~~ DYNAMIC PROGRAMMING ALGORITHM ~~~~~~~~~~~~~~~~~~~~~~~~~

	The minimum amount of coins to give are 3.
	Given coins:
	5
	2
	1

	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ GREEDY ALGORITHM ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	The amount of coins to give are 3.
	Given coins:
	5
	2
	1

Caso de prueba 4, el algoritmo no siempre podrá devolver el cambio exacto con las monedas dadas.
	Input Cuantas monedas: 3
	Input valores de monedas: 78, 25, 4
	Input precio: 300
	Input cantidad a pagar: 600
	Output:
	There is no possible combination of the given coins that can be given as change.

Caso de prueba 5, el algoritmo no debe de permitir pagar con una cantidad menor al costo.
	Input Cuantas monedas: 3
	Input valores de monedas: 1, 5, 10
	Input precio: 100
	Input cantidad a pagar: 50
	Output:
	There is not enough money, please add : 50$
README, by Aldo Degollado & Diego Velázquez

This activity solves the maze problem with backtracking and branch and bound

Backtracking = O(3^(m x n ))
Branchbound =  O(m x n)

Caso de prueba 1, Crea y muestra el maze de un 2X2.
	Input Type row and columns: 2 2 
	1 1
	1 1
	Output:
	1 1
	0 1

Caso de prueba 2, Crea y muestra el maze de un 2X2 pero sin solución.
	Input Type row and columns: 2 2 
	1 1
	1 0
	Output: No hay Solución


Caso de prueba 3, Crea y muestra el maze de un 4X4 pero con solución.
	Input Type row and columns: 4 4 
	1 1 0 1
	0 1 0 1
	1 1 1 1
	1 1 1 1
	Output: 
	1 1 0 0 
	0 1 0 0 
	0 1 1 1 
	0 0 0 1 

Caso de prueba 4 ,Crea y muestra el maze de un 4X5 pero con solución siendo diferentes los tamaños.
	Input Type row and columns: 4 5
	1 0 0 0 0 
	1 0 0 0 0 
	1 1 1 1 0 
	0 0 0 1 1 
	No hay solución
 

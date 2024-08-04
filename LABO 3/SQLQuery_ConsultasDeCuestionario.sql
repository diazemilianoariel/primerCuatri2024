--¿Cuál es el nombre del usuario más antiguo en el sistema que posea un libro en su biblioteca en formato RTF?
SELECT * from Autores where id in (select Nombres from Libros where = 'RTF') order by FechaNac limit 1

--¿Qué autores ingleses escribieron libros en un idioma distinto al inglés?
--¿Qué libros fueron escritos por autores franceses luego del año 1990?
--¿Cuál es la editorial que tiene el libro más viejo en inglés?
--¿Cuál es el formato que no tiene ningún libro asociado?
--¿Cuál de los siguientes libros en idioma inglés fueron agregados a bibliotecas por usuarios de sexo femenino?
--¿En qué formato tienen en sus bibliotecas los usuarios de tipo 'Free' los libros escritos de Jordan Mechner?
--¿Qué autores leyó el usuario con apellido Roccia? Es decir, posee libros en la biblioteca y finalizó la lectura de ellos.
--¿Cuál de las siguientes consultas trae los nombres de los libros y el nombre de la/s biblioteca/s a la que fueron añadidos pero trae además los nombres de los libros que no hayan sido añadidos nunca a una biblioteca?
--3) Listado con nombre, costo de inscripción (costo de curso), 
--costo de certificación y fecha de estreno de todos los cursos.
SELECT nombre, CostoCurso, costoCertificacion, fechaEstreno from Cursos;

-- 4) Listado con ID, nombre, costo de inscripción y ID de nivel de todos los cursos
--cuyo costo de certificación sea menor a $5000.
SELECT id, nombre, CostoCurso, idNivel, CostoCertificacion from Cursos where costoCertificacion < 5000;

--5 Listado con ID, nombre, costo de inscripción y ID de nivel de todos los cursos
--cuyo costo de certificación sea mayor a $1200.
SELECT id, nombre,CostoCertificacion ,idNivel from Cursos where costoCertificacion > 1200;

--6 Listado con nombre, número y duración de todas las clases del curso con ID número 6
SELECT nombre, numero, duracion, IDCurso from Clases where idCurso = 6;

--7 Listado con nombre, número y duración de todas las clases del curso con ID número 10.
-- me traje la columna ID para saber si esta bien hecha la consulta
SELECT nombre, numero, duracion, ID from Clases WHERE ID = 10

--8 Listado con nombre y duración de todas las clases del curso con ID número 4. Ordenado por 
--duración de mayor a menor.
 SELECT Nombre, Duracion, IDCurso
 FROM Clases
 WHERE IDCurso = 4
 ORDER by Duracion DESC

--9 Listado de cursos con nombre, fecha de estreno, costo del curso, costo de
--certificación ordenados por fecha de estreno de manera creciente
SELECT Nombre, FechaEstreno, CostoCurso, CostoCertificacion
from Cursos
ORDER by FechaEstreno ASC

--10). Listado con nombre, fecha de estreno y costo del curso de todos aquellos cuyo ID de nivel sea 
--1, 5, 9 o 10.
SELECT Nombre, FechaEstreno, CostoCurso, IDNivel
FROM Cursos
WHERE IDNivel in (1,5,9,10)

--11 Listado con nombre, fecha de estreno y costo de cursado de los tres cursos más caros de certificar.
SELECT top 3 Nombre,FechaEstreno,CostoCurso, CostoCertificacion
from Cursos
ORDER by costoCertificacion DESC;

--12 Listado con nombre, duración y número de todas las clases de los cursos con ID 2, 5 y 7. 
--Ordenados por ID de Curso ascendente y luego por número de clase ascendente.
SELECT Nombre, Duracion, Numero, IDCurso 
from Clases
WHERE IDCurso in (2,5,7)
ORDER by IDCurso ASC, numero desc

--13 Listado con nombre y fecha de estreno de todos los cursos cuya fecha de estreno 
--haya sido en el primer semestre del año 2019.

SELECT Nombre, FechaEstreno
from Cursos
WHERE DATEPART(YEAR, FechaEstreno) = 2019
AND datepart(MONTH, FechaEstreno) = 10


-- 14) Listado de cursos cuya fecha de estreno haya sido en el año 2020.
SELECT * FROM Cursos
WHERE DATEPART(YEAR,FechaEstreno) = 2020 

--15 Listado de cursos cuyo mes de estreno haya sido entre el 1 y el 4.
SELECT * 
from Cursos
WHERE   DATEPART(MONTH, FechaEstreno) BETWEEN 1 and 4

--16 Listado de clases cuya duración se encuentre entre 15 y 90 minutos.
SELECT *
from Clases
WHERE Duracion > 15 AND Duracion < 30 


--17 Listado de contenidos cuyo tamaño supere los 5000MB y sean de tipo 4 o sean menores a 400MB y sean de tipo 1.
    SELECT *
    from Contenidos
    WHERE (Tamaño > 5000 AND IDTipoContenido = 4) OR (Tamaño < 400  AND IDTipoContenido = 1)


--18 Listado de cursos que no posean ID de nivel.
SELECT *
from Cursos
WHERE IDNivel IS NULL; 



--19 Listado de cursos cuyo costo de certificación corresponda al 20% o más del costo del curso.
SELECT *
from Cursos
WHERE CostoCertificacion >= CostoCurso * 0.2;


--20 Listado de costos de cursado de todos los cursos sin repetir y ordenados de mayor a menor
 SELECT DISTINCT CostoCurso
FROM cursos
ORDER BY CostoCurso DESC;

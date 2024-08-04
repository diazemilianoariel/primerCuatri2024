-- la suma de los minutos de laerta meteorologixa de julio 2024 del pais argentina 
SELECT SUM(DuracionMinutosEstimada) from AlertasMeteorologicos
INNER JOIN Mediciones M on IDMedicion = M.ID
Inner join ciudades C ON C.IDciudad = M.IDCiudad
Inner JOIN Paises P ON C.IDPais = C.IDPais
WHERE year(FechaHora) = 2022 And month(FechaHora) = 9 And P.Nombre = 'Argentina'


-- group by , permite que se agrupen la informacion resumida por un campo en comun
--cout  cuenta el numero de registros
--sum suma los valores de una columna
--min devuelve el valor minimo de una columna
--avg devuelve el promedio de los valores de una columna
-- having, permite filtrar los resultados de un grupo
--as permite renombrar una columna



--cantidad de ALertasMeteorologicas por pais. debe mostrar nombre del pais y cantidad de alertas
SELECT PA.Nombre, C.nombre, COUNT(M.ID) as CantAlertas from Paises PA
inner join Ciudades C ON C.IDPais = PA.IDPais
 -- venezuela no tiene  mediciones , como hago para agregarlos
left outer JOIN Mediciones M ON M.IDCiudad = C.IDCiudad
--inner JOIN Mediciones M ON M.IDCiudad = C.IDCiudad
inner join AlertasMeteorologicos A on A.IDMedicion = M.ID
group by PA.Nombre, C.Nombre
ORDER by PA.Nombre, C.Nombre


-- por cada pais, la cantidad de ciudades distintas en las que llovio en el 2023
SELECT PA.Nombre, COUNT(distinct C.IDciudad) as CantCiudades 
from Paises PA
inner join Ciudades C  on PA.IDPais = C.IDCiudad
inner join Mediciones M on M.IDCiudad = C.IDCiudad
WHERE M.Lluvia > 0 AND year(FechaHora) = 2023
group by PA.Nombre
ORDER by PA.Nombre asc 


-- los nombre de ciudades que hayan registrado  mas de 25°C en promedio en el 2023
SELECT C.Nombre, AVG(M.Temperatura) as Promedio from Ciudades C  -- selecciono la tabla ciudades
inner join Mediciones M on M.IDCiudad = C.IDCiudad -- relaciono con mediciones
WHERE year(FechaHora) = 2023 -- filtro por año
GROUP by C.Nombre -- agrupo por nombre de ciudad
HAVING AVG(M.Temperatura) > 25 -- filtro por promedio mayor a 25
-- resumen de la consulta:
-- selecciono las ciudades y el promedio de temperatura de las mediciones de cada ciudad en el 2023
-- agrupo por ciudad y filtro por promedio mayor a 25
-- muestro el nombre de la ciudad y el promedio de temperatura

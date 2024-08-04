--ciudad y TempProm
SELECT C.nombre, AVG(M.temperatura) AS TempProm
FROM Ciudades c
INNER join Mediciones M ON M.IDCiudad = C.IDCiudad
GROUP BY C.IDCiudad,c.nombre

--promedio temperatura general
SELECT AVG(temperatura) AS PromGeneral
FROM Mediciones

-- ls mediciones en las que se haya registrado una temperatura mayor a la de cualquier ciudad de Italia

--Las temeperaturas de Italia - ordenadas de mayor a menor
SELECT M.temperatura from Mediciones M
INNER JOIN Ciudades C ON M.IDCiudad = C.IDCiudad
INNER JOIN Paises P ON C.IDPais = P.IDPais
WHERE P.Nombre = 'Italia'
ORDER BY M.temperatura DESC

--esta consulta devuelve las mediciones con temperaturas mayores a la mayor temperatura de Italia
SELECT * from Mediciones WHERE Temperatura > ALL ( --Todas las temperaturas de Italia
    select M.temperatura from Mediciones M --Temperaturas de Italia
    inner join Ciudades C ON M.IDCiudad = C.IDCiudad --Ciudades de Italia
    inner join Paises P ON C.IDPais = P.IDPais 
    WHERE P.Nombre = 'Italia' AND M.Temperatura is not null --Temperaturas de Italia
)

--las mediciones en las que se haya registrado una temperatura mayor a la de alguna ciudad de Argentina
SELECT * from Mediciones WHERE Temperatura > ANY (
    select M.temperatura from Mediciones M 
    inner join Ciudades C ON M.IDCiudad = C.IDCiudad 
    inner join Paises P ON C.IDPais = P.IDPais 
    WHERE P.Nombre = 'Argentina' AND M.Temperatura is not null 
)


--por cada pais , su nombre y los promedios de temperatura de los años 2022, 2023, 2024
select P.IDPais, P.Nombre,
(
  select AVG(M.temperatura) from Mediciones M
  inner join Ciudades C ON M.IDCiudad = C.IDCiudad
  where C.IDPais = P.IDPais AND YEAR(M.FechaHora) = 2022
) AS prom2022,
(
  select AVG(M.temperatura) from Mediciones M
  inner join Ciudades C ON M.IDCiudad = C.IDCiudad
  where C.IDPais = P.IDPais AND YEAR(M.FechaHora) = 2023
) AS prom2023,
(
  select AVG(M.temperatura) from Mediciones M
  inner join Ciudades C ON M.IDCiudad = C.IDCiudad
  where C.IDPais = P.IDPais AND YEAR(M.FechaHora) = 2024
) AS prom2024 
FROM Paises P 


-- listar las ciudades que hayan registrado en total mas 
--de 10mm de lluvia por la mañana o por la noche, 0mm por la tarde

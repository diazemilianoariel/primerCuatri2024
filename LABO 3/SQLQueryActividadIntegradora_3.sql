--1¿Cuál es el apellido del médico (sexo masculino) con más antigüedad de la clínica?
SELECT NOMBRE,APELLIDO, FECHAINGRESO, SEXO from MEDICOS
WHERE SEXO = 'M'
ORDER by FECHAINGRESO ASC
--¿Cuál es la cantidad de pacientes que no se atendieron en el año 2019?
SELECT COUNT(*)
FROM PACIENTES
LEFT JOIN TURNOS ON PACIENTES.IDPACIENTE = TURNOS.IDPACIENTE
WHERE YEAR(TURNOS.FECHAHORA) != 2019 OR TURNOS.FECHAHORA IS NULL;


--¿Cuál es el costo de la consulta promedio de los/as especialistas en "Oftalmología"?
SELECT AVG(MEDICOS.COSTO_CONSULTA)
FROM MEDICOS
INNER JOIN ESPECIALIDADES ON MEDICOS.IDESPECIALIDAD = ESPECIALIDADES.IDESPECIALIDAD
WHERE ESPECIALIDADES.NOMBRE = 'Oftalmología';



--¿Cuántas médicas cobran sus honorarios de consulta un costo mayor a $1000?
SELECT COUNT(*)
FROM MEDICOS
WHERE SEXO = 'F' AND COSTO_CONSULTA > 1000;
--¿Cuántos turnos fueron atendidos por la doctora Flavia Rice?
SELECT COUNT(*)
FROM TURNOS
INNER JOIN MEDICOS ON TURNOS.IDMEDICO = MEDICOS.IDMEDICO
WHERE MEDICOS.NOMBRE = 'Flavia' AND MEDICOS.APELLIDO = 'Rice';
--¿Cuántos médicos tienen la especialidad "Gastroenterología" ó "Pediatría"?
SELECT COUNT(*)
FROM MEDICOS
INNER JOIN ESPECIALIDADES ON MEDICOS.IDESPECIALIDAD = ESPECIALIDADES.IDESPECIALIDAD
WHERE ESPECIALIDADES.NOMBRE = 'Gastroenterología' OR ESPECIALIDADES.NOMBRE = 'Pediatría';
--¿Cuánto tuvo que pagar la consulta el paciente con el turno nro 146?
--Teniendo en cuenta que el paciente debe pagar el costo de la consulta del médico menos lo que cubre la cobertura de la obra social. La cobertura de la obra social está expresado en un valor decimal entre 0 y 1. Siendo 0 el 0% de cobertura y 1 el 100% de la cobertura.

--Si la cobertura de la obra social es 0.2, entonces el paciente debe pagar el 80% de la consulta.
SELECT (MEDICOS.COSTO_CONSULTA - (MEDICOS.COSTO_CONSULTA * TURNOS.DURACION)) AS 'COSTO CONSULTA'
FROM TURNOS
INNER JOIN MEDICOS ON TURNOS.IDMEDICO = MEDICOS.IDMEDICO
WHERE TURNOS.IDTURNO = 146;


--¿Qué Obras Sociales cubren a pacientes que se hayan atendido en algún turno con algún médico de especialidad 'Odontología'?
SELECT DISTINCT 
FROM OBRASOCIAL
INNER JOIN PACIENTES ON OBRASOCIAL.IDOBRASOCIAL = PACIENTES.IDOBRASOCIAL
INNER JOIN TURNOS ON PACIENTES.IDPACIENTE = TURNOS.IDPACIENTE
INNER JOIN MEDICOS ON TURNOS.IDMEDICO = MEDICOS.IDMEDICO
INNER JOIN ESPECIALIDADES ON MEDICOS.IDESPECIALIDAD = ESPECIALIDADES.IDESPECIALIDAD
WHERE ESPECIALIDADES.NOMBRE = 'Odontología';

--¿Cuáles son el/los paciente/s que se atendieron más veces? (indistintamente del sexo del paciente)
SELECT PACIENTES.NOMBRE, PACIENTES.APELLIDO, COUNT(*) AS 'CANTIDAD DE TURNOS'
FROM PACIENTES
INNER JOIN TURNOS ON PACIENTES.IDPACIENTE = TURNOS.IDPACIENTE
GROUP BY PACIENTES.NOMBRE, PACIENTES.APELLIDO
ORDER BY COUNT(*) DESC
LIMIT 1



--¿Cuántos pacientes distintos se atendieron en turnos que duraron más que la duración promedio?
SELECT COUNT(DISTINCT TURNOS.IDPACIENTE) AS Total_Pacientes_Atendidos
FROM TURNOS
WHERE TURNOS.DURACION > (
    SELECT AVG(DURACION) FROM TURNOS
)



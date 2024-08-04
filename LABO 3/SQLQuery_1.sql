CREATE DATABASE Clase01_20241C
GO
USE Clase01_20241C
GO
CREATE TABLE Areas(
    ID int not null primary key,
    Nombre varchar(50) not null,
    Presupuesto money not null check (Presupuesto > 0),
    Mail varchar(100) not null unique 
)


GO


CREATE TABLE Empleados(
    Legajo int not null primary key identity (1000, 1),
    IDArea int not null foreign key references Areas(ID),
    Apellido varchar(50) not null,
    Nombre varchar(50) not null,
    Nacimiento date null,
)



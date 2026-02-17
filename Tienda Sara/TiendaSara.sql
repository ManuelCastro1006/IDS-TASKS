/*Creacion de la base de datos
CREATE DATABASE TiendaSara;
GO

USE TiendaSara;
GO

CREATE TABLE Categorias(
    Id INT PRIMARY KEY IDENTITY(1,1),
    Descripcion VARCHAR(100) NOT NULL
);

CREATE TABLE Marcas(
    Id INT PRIMARY KEY IDENTITY(1,1),
    Descripcion VARCHAR(100) NOT NULL
);

CREATE TABLE Productos(
    Id INT PRIMARY KEY IDENTITY(1,1),
    Descripcion VARCHAR(150) NOT NULL,
    Precio DECIMAL(10,2) NOT NULL CHECK (Precio > 0),
    Cantidad INT NOT NULL CHECK (Cantidad >= 0),
    IdCategoria INT NOT NULL,
    IdMarca INT NOT NULL,
    FOREIGN KEY (IdCategoria) REFERENCES Categorias(Id),
    FOREIGN KEY (IdMarca) REFERENCES Marcas(Id)
);

CREATE TABLE Carrito(
    Id INT PRIMARY KEY IDENTITY(1,1),
    FolioVenta VARCHAR(50) NOT NULL UNIQUE,
    TotalCompra DECIMAL(10,2) DEFAULT 0,
    Estatus VARCHAR(30) DEFAULT 'Pendiente',
    Fecha DATETIME DEFAULT GETDATE()
);

CREATE TABLE CarritoDetalle(
    Id INT PRIMARY KEY IDENTITY(1,1),
    IdCarrito INT NOT NULL,
    IdProducto INT NOT NULL,
    Cantidad INT NOT NULL CHECK (Cantidad > 0),
    Subtotal DECIMAL(10,2) NOT NULL,
    FOREIGN KEY (IdCarrito) REFERENCES Carrito(Id),
    FOREIGN KEY (IdProducto) REFERENCES Productos(Id)
);*/

/*Insercion de filas
INSERT INTO Categorias (Descripcion) VALUES
('Electrónica'), ('Ropa'), ('Hogar'), ('Muebles'), ('Deportes');

INSERT INTO Marcas (Descripcion) VALUES
('Sony'), ('Samsung'), ('Nike'), ('Adidas'), ('LG');

INSERT INTO Productos (Descripcion, Precio, Cantidad, IdCategoria, IdMarca) VALUES
('Televisión 50', 12000, 5, 1, 1),
('Refrigerador', 18000, 3, 3, 5),
('Tenis deportivos', 2500, 10, 2, 3),
('Sofá', 9000, 2, 4, 2),
('Bicicleta', 7000, 4, 5, 4);

INSERT INTO Carrito (FolioVenta) VALUES
('FV001'), ('FV002'), ('FV003'), ('FV004'), ('FV005');

INSERT INTO CarritoDetalle (IdCarrito, IdProducto, Cantidad, Subtotal) VALUES
(1,1,1,12000),
(1,3,2,5000),
(2,2,1,18000),
(3,5,1,7000),
(4,4,1,9000);*/

/*Consulta 1
SELECT p.Descripcion, p.Precio, c.Descripcion AS Categoria, m.Descripcion AS Marca
FROM Productos p
INNER JOIN Categorias c ON p.IdCategoria = c.Id
INNER JOIN Marcas m ON p.IdMarca = m.Id;*/

/*Consulta 2
SELECT ca.FolioVenta, p.Descripcion, cd.Cantidad, cd.Subtotal
FROM Carrito ca
INNER JOIN CarritoDetalle cd ON ca.Id = cd.IdCarrito
INNER JOIN Productos p ON cd.IdProducto = p.Id;*/

/*Consulta 3
SELECT ca.FolioVenta, p.Descripcion, m.Descripcion AS Marca,
       c.Descripcion AS Categoria, cd.Cantidad, cd.Subtotal
FROM Carrito ca
INNER JOIN CarritoDetalle cd ON ca.Id = cd.IdCarrito
INNER JOIN Productos p ON cd.IdProducto = p.Id
INNER JOIN Marcas m ON p.IdMarca = m.Id
INNER JOIN Categorias c ON p.IdCategoria = c.Id;*/
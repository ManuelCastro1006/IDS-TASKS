import Foundation


struct Producto {
    let nombre: String
    var cantidad: Int
}

var inventario: [Producto] = []

func leerOpcion() -> Int? {
    guard let entrada = readLine(),
          let numero = Int(entrada.trimmingCharacters(in: .whitespacesAndNewlines)) else {
        return nil
    }
    return numero
}

func mostrarMenu() {
    print("""

    ====================================
             INVENTARIO DE TIENDA
    ====================================
    1. Registrar un artículo
    2. Ver la lista de artículos
    3. Consultar artículos en existencia
    4. Salir
    ====================================
    Selecciona una opción:
    """)
}

func registrarArticulos() {
    print("\n--- REGISTRAR ARTÍCULOS ---")

    print("¿Cuántos artículos deseas registrar?")
    guard let cantidadArticulos = leerOpcion(), cantidadArticulos > 0 else {
        print("Ingresa una cantidad válida mayor que cero.")
        return
    }

    for numero in 1...cantidadArticulos {
        print("\nArtículo \(numero) de \(cantidadArticulos)")
        print("Nombre del producto:")

        guard let nombreIngresado = readLine() else {
            print("No se pudo leer el nombre. Se omitirá este artículo.")
            continue
        }

        let nombre = nombreIngresado.trimmingCharacters(in: .whitespacesAndNewlines)

        guard !nombre.isEmpty else {
            print("El nombre no puede estar vacío. Se omitirá este artículo.")
            continue
        }

        print("Cantidad en existencia:")
        guard let cantidad = leerOpcion(), cantidad >= 0 else {
            print("Ingresa una cantidad válida (cero o mayor). Se omitirá este artículo.")
            continue
        }

        inventario.append(Producto(nombre: nombre, cantidad: cantidad))
        print("Artículo '\(nombre)' registrado correctamente.")
    }

    print("\nRegistro finalizado. Presiona Enter para volver al menú.")
    _ = readLine()
}

func mostrarArticulos() {
    print("\n--- LISTA DE ARTÍCULOS ---")

    if inventario.isEmpty {
        print("Todavía no hay artículos registrados.")
    } else {
        for (indice, producto) in inventario.enumerated() {
            print("\(indice + 1). \(producto.nombre) - Cantidad: \(producto.cantidad)")
        }
    }

    print("\nPresiona Enter para volver al menú.")
    _ = readLine()
}

func consultarExistencias() {
    print("\n--- ARTÍCULOS EN EXISTENCIA ---")

    let productosDisponibles = inventario.filter { $0.cantidad > 0 }

    if productosDisponibles.isEmpty {
        print("No hay artículos con existencias disponibles.")
    } else {
        for producto in productosDisponibles {
            print("Producto: \(producto.nombre) | Existencias: \(producto.cantidad)")
        }
    }

    print("\nPresiona Enter para volver al menú.")
    _ = readLine()
}

var continuar = true

while continuar {
    mostrarMenu()

    guard let opcion = leerOpcion() else {
        print("Opción no válida. Escribe un número del 1 al 4.")
        continue
    }

    switch opcion {
    case 1:
        registrarArticulos()
    case 2:
        mostrarArticulos()
    case 3:
        consultarExistencias()
    case 4:
        continuar = false
        print("\nAplicación finalizada. ¡Hasta pronto!")
    default:
        print("Opción no válida. Selecciona una opción del 1 al 4.")
    }
}

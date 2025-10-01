<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Captura de datos</title>
  <script src="https://kit.fontawesome.com/a71707a89a.js" crossorigin="anonymous"></script>
  <link rel="stylesheet" href="css/style.css">
</head>
<body>
  <div class="dive">
    <h1>Captura de datos personales</h1>
  <br>
  <h2>Ingresa los datos que se te piden</h2>
  <br>
  <p>Mi primera encuesta:</p>
  <hr>
  <form action="resultados.php" method="post">
    <label for="name">Nombre:</label>
    <input type="text" id="name" name="name" value="Ingresa tu nombre"><hr>
    <label for="age">edad:</label>
    <input type="number" id="age" name="age" value="Ingresa tu edad"><hr>
    <label for="city">Ciudad:</label>
    <input type="text" id="city" name="city" value="Ingresa tu ciudad"><hr>
    <label for="BDdate">Fecha de nacimiento:</label>
    <input type="date" id="BDdate" name="BDdate"><hr>
    <label for="hobby">Pasatiempo:</label>
    <input type="text" id="hobby" name="hobby" value="Ingresa tu pasatiempo favorito"><hr>
      <button type="submit">¡Ingresamos datos!</button>
    </a>
  </form>
  </div>
</body>
</html>
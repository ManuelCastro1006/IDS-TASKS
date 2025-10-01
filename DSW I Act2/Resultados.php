<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>¡Resiltados de datos!</title>
    <link rel="stylesheet" href="css/style.css">
    <script src="https://kit.fontawesome.com/a71707a89a.js" crossorigin="anonymous"></script>
</head>
<body>
    <div class="dive2">
        <h1>Resultados</h1>
    <center><img src="img/img1.jpg" width="400" height="400" alt="secure">
</center>
    <h2>¡Bien Hecho!</h2>
    <?php
    $name = $_POST['name'];
    $age = $_POST['age'];
    $city = $_POST['city'];
    $BDdate = $_POST['BDdate'];
    $hobby = $_POST['hobby'];

    echo'<p><b>Nombre:</b> '.$name.'</p>';
    echo'<p><b>Edad:</b> '.$age.'</p>';
    echo'<p><b>Ciudad:</b> '.$city.'</p>';
    echo'<p><b>Fecha de nacimiento:</b> '.$BDdate.'</p>';
    echo'<p><b>Pasatiempo:</b> '.$hobby.'</p>';

    ?>
    <div id="popUpOverlay"></div>
    <div id="popUpBox">
        <div id="box">
            <i class="fas fa-question-circle sa-5x"></i>
            <hi>Volver a ingresar datos?</hi>
            <div id="closeModal"></div>
        </div>
    </div>
    <button onclick="Alert.render('you look very nice today')" class="btn">Volver a ingresar!</button>
    <script src="js/app.js"></script>
    </div>
</body>
</html>
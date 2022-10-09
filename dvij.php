<?php
print "<strong>Движение точки  в пространстве и отрисовка объекта при попадании на него луча</strong>.
Чёрная точка - двигающийся объект, например, человек. Серая точка показывает направление взгляда.
Если координаты серой точки совпадают с объектом, то объект выводится на экран. Синяя точка - стена.
Матрица вращения состоит из восьми возможных направлений взгляда. Посчитана заранее и хранится в массивах.
Для реализации карты и движения по ней можно создать массивы  позиций (их координаты) объектов, при движении или
повороте проверять совпадения с направлением взгляда и рисовать стены.  ";

//Матрица вращения. Направление взгляда. Только 8 позиций.
$direction_x=array(0,10,10,10,0,-10,-10,-10);
$direction_y=array(10,10,0,-10,-10,-10,0,10);

if (!isset($a) && !isset($b) ) {
$a=0;
$b=0;
}

if (!isset($x) && !isset($y) ) {
$x=0;
$y=10;
$i=-1;
}


//Вращение
$i=$_GET['i'];

if (isset($_GET['rotate_clockwise'])) {
	if ($i==7) $i=-1;
	$i++;
	$x=$direction_x[$i];
	$y=$direction_y[$i];
}

if (isset($_GET['rotate_counter_clockwise'])) {
	if ($i==0) $i=8;
	$i--;
	$x=$direction_x[$i];
	$y=$direction_y[$i];
}



//Управление движением
if (isset($_GET['forward'])) {
	$x=$_GET['x'];
	$y=$_GET['y'];

	$a=$_GET['a']+($direction_x[$i]);
	$b=$_GET['b']+($direction_y[$i]);

} else {

$a=$_GET['a'];
$b=$_GET['b'];
}


//Натыкаемся на стену
if (250==$x+210+$a && 300 ==$y+310+$b ) {
 echo '<div id="wall_real"></div>';
}
?>
<style>
			#point_of_view {
			position: absolute;
			top:  <?=$x+210+$a?>px;
			left: <?=$y+310+$b?>px;
			background-color: #999;
			width: 5px;
			height: 5px;
			}

			#point_zero {
			position: absolute;
			top:  <?=$a+210?>px;
			left: <?=$b+310?>px;
			background-color: #333;
			width: 5px;
			height: 5px;
			}
			#wall {
			position: absolute;
			top:  250px;
			left: 300px;
			background-color: blue;
			width: 5px;
			height: 5px;
			}
			#wall_real {
			position: absolute;
			top:  150px;
			left: 300px;
			background-color: blue;
			width: 50px;
			height: 50px;
			}
</style>
<div id="wall">
</div>
<div id="point_of_view">
</div>
<div id="point_zero">
</div>


<br><br><br><br><br>
<form  method="GET" align="left">
<input type="submit" name="rotate_clockwise"  value="По часовой ->">
<input type="hidden" name="x" value="<?=$x?>">
<input type="hidden" name="y" value="<?=$y?>">
<input type="hidden" name="i" value="<?=$i?>">
<input type="hidden" name="a" value="<?=$a?>">
<input type="hidden" name="b" value="<?=$b?>">
</form>
<form  method="GET" align="left">
<input type="submit" name="rotate_counter_clockwise"  value="<- Против часовой">
<input type="hidden" name="x" value="<?=$x?>">
<input type="hidden" name="y" value="<?=$y?>">
<input type="hidden" name="i" value="<?=$i?>">
<input type="hidden" name="a" value="<?=$a?>">
<input type="hidden" name="b" value="<?=$b?>">
</form>

<form  method="GET" >
<input type="submit" name="forward" value="Вперёд"><br/>
Координаты:
<br/>
<input type="text" name="a" value="<?=$a?>">
<input type="text" name="b" value="<?=$b?>">
<br/>
Значения направления:
<br/>
<input type="text" name="x" value="<?=$x?>">
<input type="text" name="y" value="<?=$y?>">
<br/>
Переменная для цикла вращения
(по ней можно определять направление):
<br/>
<input type="htext" name="i" value="<?=$i?>">

</form>


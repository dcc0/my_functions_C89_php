<?php
error_reporting(0);

//Массивы ребер. В этой матрице предствлен граф с 6 вершинами
//Название массива - вершина, элементы - точки, в которые можно попасть из вершины
$a=array('b','c','d');
$b=array('d','e','f');
$c=array('d','e','f');
$d=array('e', 'f');
$e=array('f');
$f=array();

//Расстояния на рёбрах графа
$way=array('ab' => '5', 'ac' => '6',  'ad' => '3',  'bd' => '5', 'be' => '6',  'bf' => '3',
 'cd' => '2', 'ce' => '11',  'cf' => '3',
 'de' => '2',  'df' => '3',
 'ef'=>'2');

$all_ways=array();
//Первый путь
$x='abdef';
print $x;
//Добавим в массив
$all_ways_names[]=$x;
//Найдем расстояние первого пути
$p=0;
$result=0;
while ($p != strlen($x)-1) {
  $y=$x[$p].$x[$p+1];
  $result+=$way[$y];
  $p++;
}
//Печатаем результат
print $result;
//Добавим результат в массив, чтобы потом найти кратчайший путь
$all_ways[]=$result;
print "\n";

//Найдем все пути, используя "переменные переменных"
$j=strlen($x);
while($j !=0) {

//ищем новый элемент
	$key = array_search($x[$j], ${$x[$j-1]});

//Если нашли, уберем правую часть и заменим элемент
if (${$x[$j-1]}[$key+1] != '') {
	$x=substr($x, 0, $j);
	$x.= ${$x[$j-1]}[$key+1];
	$z=$x[strlen($x)-1];
	$z=${$z}[0];

	//Собираем новый путь х c помощью нулевых индексов
while (1) {
//Если последний элемент равен f, то выйдем из цикла
	if ($x[strlen($x)-1]=='f') {$x.=$z;  break ;}
	$x.=$z;
	$z=${$z}[0];
	}
//Напечатаем
	$j=strlen($x);
	echo $x;
  //Соберём в массив имена всех путей
	$all_ways_names[]=$x;

//Найдем расстояние  пути
$p=0;
$result=0;
while ($p != strlen($x)-1) {
  $y=$x[$p].$x[$p+1];
  $result+=$way[$y];
  $p++;
}
print $result;
//Добавим результат в массив, чтобы потом найти кратчайший путь
$all_ways[]=$result;

	echo "\n";
		}
$j--;
}

//Напечатаем массив с расстояниями
print_r($all_ways);

//Создадим сортированный массив на основе существуюшего
$sorted_ways=$all_ways;

//Найдём кратчайший путь, осортировав массив по возрастанию.
//Первое значение массива и будет кратчайший путь
sort($sorted_ways);
print " Кратчайший путь: " . $sorted_ways[0]  . "\n";

//Или так: напечатаем массив со всемми путями
print_r($all_ways_names);
//Найдем ключ кратчайшего пути в несортированном массиве с расстояниями
$key=array_search($sorted_ways[0], $all_ways);
//По ключу выведем имя пути и расстояние из двух массивов (массива расстояний и массива имён путей)
print "Имя кратчайшего пути и расстояние: " . $all_ways_names[$key] . ' ' . ' '  . $all_ways[$key];
?>

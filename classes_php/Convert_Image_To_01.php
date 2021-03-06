<?php
	

	/*Класс преобразует изображение в матрицу  вида 01 и транспонирует.
	 * 0 - соответствует фону, 1 - чёрному цвету. Следует использовать
	 * черно-белые изображения формата png, с объектами чёрного цвета.
	 * Возвращает контур изображения. This class transforms balck-white (png) image to a binary like 01.*/


	class Convert_Image_To_01 {
		
	/*Координаты пикселей*/
		
		public $x = 0;
		public $y = 0;	
		public $arr=array();	

			
	/*Метод преобразует изображение в матрицу 01
	 *Возвращает массив */
	 
	public function imgToBin($resource) 
		
	
		{
			

		/*Координаты каждого пикселя*/	
		$width = imagesx($resource);
		$height = imagesy($resource);	

		/*Читаем цвета каждого пикселя функцией imagecolorart*/
		for($x = 0; $x < $width; $x++) {
		for($y = 0; $y < $height; $y++) {
			
		// pixel color at (x, y)	
		/*Определение фона не требуется в данном случае*/
		$color = imagecolorat($resource, $x, $y);
			//print $color . ' ';
		   
		/*Если не чёрный, то пишем в массив 0*/
		if ($color!="0")  {
		$arr[] = '0';     
		print '0';
			}
	        /*Если чёрный, то пишем  1*/
		if ($color=="0")  {
		$arr[] = '1';
		print '1';
			}
		 
		}
		/*Новая строка, чтобы отобразить прямоугольную матрицу*/
		print '<br/>';
	}

		print '<br/>';
		
		$this->x=$x; 	/*ширина массива*/
		$this->y=$y  	/*Высота массива*/;
		$this->arr=$arr; /*Сам массив*/
		
		return $arr;    /*Вернём массив*/
}




	/*Метод транспонирует матрицу
	 * Возвращает массив*/
	 
	public function transformMatrix()
	
	 {
		
		 
	if ($this->y > $this->x) {
	$all_string_count = $this->y;
	}
		if ($this->y < $this->x) {
	$all_string_count = $this->x;
	}
	
	if ($this->y == $this->x) {
	$all_string_count = $this->x;
	}

	/*Транспонируем матрицу*/
	for ($j=0; $j < $all_string_count; $j++) {
	
	/*Помножим высоту на себя, чтобы найти все символы в столбце*/
	for ( $i=0; $i < $all_string_count*$all_string_count; $i++ ) {
	
	/*Использует деление по модулю*/	
	if ($i%$this->y==$j) {
			
	$this->result[]=$this->arr[$i];
	print  $this->arr[$i];
		
		}
	}
	print '<br/>';
}
		
	return $this->result;

		}

}

?>

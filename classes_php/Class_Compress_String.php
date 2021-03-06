<?php


	/*Класс для сокращения строки.
	 * Основан на том, что маленькие (в нижнем регистре) 
	 * буквы английского алфавита, начиная с d,
	 * имеет коды в ASCII выше 100
	 * This class reduces a string. It uses an idea
	 * that codes of the small letters after d are  100+
	 * in a range of ASCII*/
	 
	class Compress_String 
	
	{ 
	 
		
		public $compressed_string=array();
		public $decompressed_string=array();	
		public $decompressed_string_letters=array();
		
	/*Метод сокращает строку, вычитая из ASSCI кодов число 100*/	
	public function compressString($string) 
	
		{
		
			for ($i = 0; $i < strlen($string); $i++) 
			{
			$this->compressed_string[]=ord($string[$i]) - 100; 
			}	
	
	
		return $this->compressed_string;
}


	/*Метод восстанавливает строку в ASSCI*/
	public function decompressStringAssci($string) 
	
		{
			$this->compressed_string=$string;
		
			for ($i = 0; $i < count($this->compressed_string); $i++) 
			{	
			$this->decompressed_string[]=$this->compressed_string[$i]+100; 
			}
	
	
		return $this->decompressed_string;
}



	/*Метод восстанавливает строку, преобразует в текст*/
	public function decompressStringLetters($string) 
	
		{
			$this->compressed_string=$string;
		
			for ($i = 0; $i < count($this->compressed_string); $i++) 
			{	
			$this->decompressed_string_letters[]=chr($this->compressed_string[$i]+100); 
			}
	
	
		return $this->decompressed_string_letters;
}

}




	$string="Hello world! I am a string.";	
	$compressed_string= new Compress_String;
	$array_string=$compressed_string->compressString($string);
	
	print '<br/>Сжатая строка <br/>';
	foreach($array_string as $value)
	print $value;
	
	$new_array=$compressed_string->decompressStringAssci($array_string);	
	
	print '<br/>Исходная строка в ASSCI<br/>';
	foreach($new_array as $value)
	print $value;	

	$new_text=$compressed_string->decompressStringLetters($array_string);	
	
	print '<br/>Исходная строка  - текст <br/>';
	foreach($new_text as $value)
	print $value;	
	
?>

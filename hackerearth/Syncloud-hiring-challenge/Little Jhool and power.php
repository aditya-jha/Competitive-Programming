<?php

fscanf(STDIN, "%s\n", $name);
$first = "000000";
$second = "111111";

function preprocessMorrisPratt($pattern, &$nextTable)
{
	$i = 0;
	$j = $nextTable[0] = -1;
	$len = strlen($pattern);
 
	while ($i < $len) {
		while ($j > -1 && $pattern[$i] != $pattern[$j]) {
			$j = $nextTable[$j];
		}
 
		$nextTable[++$i] = ++$j;
	}
}
 
function MorrisPratt($text, $pattern)
{

	$n = strlen($text);
	$m = strlen($pattern);
	$nextTable = array();
 
	preprocessMorrisPratt($pattern, $nextTable);
 
	$i = $j = 0;
	while ($j < $n) {
		while ($i > -1 && $pattern[$i] != $text[$j]) {
			$i = $nextTable[$i];
		}
		$i++;
		$j++;
		if ($i >= $m) {
			return $j - $i;
		}
	}
	return -1;
}



if(MorrisPratt($name,$first) != -1) {
	echo "Sorry, sorry!";
}
else if(MorrisPratt($name,$second) != -1) {
	echo "Sorry, sorry!";
}
else echo "Good luck!";


?>

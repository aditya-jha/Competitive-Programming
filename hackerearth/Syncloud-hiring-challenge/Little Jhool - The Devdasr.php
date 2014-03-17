<?php

fscanf(STDIN, "%d", $name);

$sum = 0;


$input = trim(fgets(STDIN));
$petals = explode(" ",$input);

for($i=0;$i<$name;$i++) {
	$sum += intval($petals[$i]);
}

if($sum % 2 == 1) {
	echo $sum;
}
else {
	$min = 2147483647;
	for($i=0;$i<$name;$i++) {
		if(((int)$petals[$i])%2 == 1) {
			if($min > ((int)$petals[$i])) {
				$min = ((int)$petals[$i]);
			}
		}
	}
	
	
	if($min != 2147483647) $sum = $sum - $min;
	if($sum % 2 == 1) {
		echo $sum;
	}
	else {
		echo ":(";
	}
	//echo $min;
}



?>

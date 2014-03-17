<?php


fscanf(STDIN, "%s\n", $name);

$love = "love";
$it = 0;
$len = strlen($name);

for($i=0; $i<$len && $it<4; $i++) {
	if($name[$i] == $love[$it]) $it++;
}

if($it == 4) echo "I love you, too!";
else echo "Let us breakup!";


?>
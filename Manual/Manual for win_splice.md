# Manual for win_splice

## NAME

​	win_splice	- to splice the sequence window by window

## SYNOPSIS

​	win_splice [input FILE] [output FILE] [options]

## DESCRIPTION

​	win_splice is a function used for splicing the sequence from Second Generation Sequencing. It adapts the window-by-window way to score every base and decide whether to save it. Users can set some arguments involved, such as the threshold of quality(Q), the trimming depth(s), the step length per window(w).

## OPTIONS

​	-Q[value]: to set the value of quality threshold. If this option isn't enabled, the default threshold would be __20__.

​	-s[value]: to set the value of trimming depth, which means once there are several bases higher than the threshold Q in a row and the total number is over [value], the process of window-splice would stop. If this option isn't enabled, the default depth would be __20__.

​	+s: If this option is enabled, the trimming depth would be "infinite", which is in fact 100. That keeps the process going continuously until the whole sequence is done.

​	-w[value]: to set the step length per window. If this option isn't enabled, the default step length would be __5__.

## AUTHOR

Yang Fu \<chronatos@sjtu.edu.cn>

## UPDATE

updated on 2022.6.16

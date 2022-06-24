% TRIM_PERSON(1) trim_person 1.0.0

%June 2022

## NAME
non-ATGC_processing	- set the maximum number or ratio of N, and trim the non-ATGC in the sequence

short_empty	- Filter out sequences that are too short

trim_ends	- Excise the specified number of bases at one end of the sequence



## SYNOPSIS

non-ATGC_processing [input file] [max N num or rate] [output file]

short_empty [input file] [minlength] [output file]

trim_ends [input file] [the num of basepairs] [output file]



## DESCRIPTION

non-ATGC_processing：There are non-ATGC bases in many reads, which are uniformly represented by N. Because these bases do not have much value or their contribution to the entire sequence cannot be identified temporarily. Such reads can be further processed to bring the non-ATGC content within acceptable limits.

short_empty ：Set a minimum length, and when the length of reads reaches an unacceptable level, these sequences that are too short and lose their value are filtered.

trim_ends：Optionally trim a specified number of bases from either the 5' and 3' ends of the reads



## OPTIONS

`-N`：Enter a DNA sequence with options followed by the number of Ns retained in the DNA sequence

`-Nr`：Enter a DNA sequence with options followed by the maximum proportion of N retained in the DNA sequence

`-ds`：Remove short sequences, followed by the maximum length to remove short sequences

`-n`：Trim a specified number of bases in a DNA sequence followed by the specified number of bases



## AUTHOR

Ying Liang   <LiangYing@sjtu.edu.cn>














% EXTRACT_TRANS.H(OP) extract_trans.h 1.0.0
% Wang Xinjie

# Manual for project.sh

## USAGE

./project.sh [options] ...

## FUNCTION

You can choose to modify the fastq file to remove low-quality sequences or bases, remove linker sequences in sequences, remove primer sequences, remove poly-A tails, filter short sequences, etc.  You can also choose to operate on a segment of bases, removing a specified number or proportion of N.

## OPTIONS

--Window：Sliding window clips lower quality sequences

-w[n]：The sliding window clipping window size is set to n

--base-threshold：Cut lower quality sequences base by base

-Q[n]：The quality threshold is set to n

-s[n]：The clipping depth is set to n

+s：The cutting depth is set to "infinity", that is, the entire sequence is always cut

-a：Followed by a single-end adapter sequence or paired-end sequencing of one of the adapter sequences

-A：followed by paired-end sequencing of another adaptor sequence

-e：The degree of mismatches allowed when the linker matches the base sequence, followed by the degree of mismatch

-poly：Remove the poly-A tail of the sequence

-i：The number of insertions allowed when the splice matches the base sequence, followed by the number of insertions allowed in the base sequence

-d：The number of deletions allowed when the splice matches the base sequence, followed by the number of deletions allowed in the base sequence

-p：Followed by single ended primer sequence or one of the primer sequences of double ended sequencing

-P：Heel double ended sequencing another primer sequence

-l：The minimum number of matches between the splice and the base sequence, followed by the specified minimum number of matches

-N：Input a DNA sequence, followed by the number of N retained in the DNA sequence

-Nr：Input a DNA sequence, followed by the maximum proportion of N retained in the DNA sequence

-ds：Remove the short sequence, followed by the maximum length of the short sequence

-n：Prune a specified number of bases in a DNA sequence, followed by a specified base number

## AUTHOR

Xinjie Wang<<distancewxj@sjtu.edu.cn>>

## LAST CHANGE TIME

2022/6/18
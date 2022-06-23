% EXTRACT_TRANS.H(OP) extract_trans.h 1.0.0
% Wang Xinjie
% 2022/6

# NAME

aAe_main  -   Remove the linker in the base sequence, allowing a certain degree of mismatch

d_main   -    Remove the linker part of the base sequence, allowing a certain degree of deletion

i_main  -   Remove the linker part of the base sequence, allowing a certain degree of insertion

pP_main  -  Remove the primer part from the base sequence

poly_main  -  Removing the poly-A tail from the base sequence

# SYNOPSIS

aAe_main [Mismatch degree] [adapter] [Minimum number of matches] [input file]

d_main [Mismatch degree] [Allowable missing number] [adapter] [input file] [Minimum number of matches]

i_main [Mismatch degree] [Number of inserts allowed] [adapter] [input file] [Minimum number of matches]

poly_main [input file]

pP_main [input file] [primer] [Minimum number of matches]

# DESCRIPTION

aAe_main：Input the fastq file and joint sequence to be trimmed, and specify the corresponding mismatch degree and the minimum matching number. The fastq file with trimmed joints will be returned, and the results can be saved by redirecting to the corresponding file

d_main：Input the fastq file and joint sequence to be trimmed, and specify the corresponding mismatch degree, allowable missing number and minimum matching number. The fastq file with trimmed joints will be returned, and the results can be saved by redirecting to the corresponding file

i_main：Input the fastq file and connector sequence to be trimmed, and specify the corresponding mismatch degree, allowable number of inserts and minimum number of matches. The fastq file with trimmed connectors will be returned, and the results can be saved by redirecting to the corresponding file

poly_main：Input the fastq file to be pruned, and you can return the fastq file with the poly-A tail removed. The results can be saved in the corresponding file by redirecting

pP_main：Input the fastq file and primer sequence to be pruned, and specify the minimum number of matches. The fastq file with pruned primers removed will be returned, and the results can be saved in the corresponding file by redirection

# OPTIONS

-a：Followed by single ended splice sequence or double ended sequencing of one of the splice sequences

-A：Followed by two terminal sequencing another splice sequence

-e：The allowable mismatch degree when the splice matches the base sequence, followed by the mismatch degree

-poly：Remove the poly-A tail of the sequence

-i：The number of insertions allowed when the splice matches the base sequence, followed by the number of insertions allowed in the base sequence

-d：The number of deletions allowed when the splice matches the base sequence, followed by the number of deletions allowed in the base sequence

-p：Followed by single ended primer sequence or one of the primer sequences of double ended sequencing

-P：Heel double ended sequencing another primer sequence

-l：The minimum number of matches between the splice and the base sequence, followed by the specified minimum number of matches

# AUTHOR

Xinjie Wang<<distancewxj@sjtu.edu.cn>>

# UPDATE

updated on 2022.6.19
%BASE_TRIME base_trim

%Ruoyin Zhou

%June 2022

## NAME

base_trim  -  trim sequences in the input fastq file base by base, and store the preserved bases in the fastq format, while store the serial number in a txt file.

## SYNOPSIS

<base_trim>  \<the fastqfile to trim>  \<file storing outcome>  \<file storing the serial number of bases be cut>  [options]

## DESCRIPTION

Processing a fastQ file, the lib is to removing the low-quality segments **base by base** , storing the information to preserve  in a **fastQ format file** (If the user does not specify the file, store it in **output.fastq**) and store the serial number of the clipped bases in each sequence in a **txt format file** ( If the user does not specify the file, store it in **error.txt**) . The trim mode should be entered on the command line, otherwise this function  won't be executed . The quality of the threshold(Q), the stop pattern(+s or -s[value]) should input from the command line, while if there isn't input of these arguments, the function will use  default values.

## OPTIONS

\<base_trim> :   the path of base_trim.c. It must be input in the command line.

\<the fastqfile to trim> :   the path of the fastqfile to trim. It must be input in the command line.

 \<fastQ format  file storing outcome> :   the path of the file storing outcome.  If the user does not enter the path of fastQ format  file, save the outcome in **outcome.fastq**.

\<txt format file storing the serial number of bases be cut>  :    the path of the file storing the serial number of bases be cut. If the user does not enter the path of txt format file, save the outcome in **error.txt**.

--base-threshold:  When this option is input in command line, this function will execute.

-s  :    Cut every base which is below the quality of the threshold given by users. If there isn't "-s" or "+s", use "-s" pattern. 

+s[value]  :   When the continuous number of qualified bases was less than the givengiven stopping step, the base whose quality was lower than the quality threshold were removed. Otherwise leave the base unclilpped. If there isn't "-s" or "+s", use "-s" pattern. 

-Q[value] :   To define the quality of the threshold. If there isn't  the quality of the threshold, use the default value 20.

## EXAMPLES

```
~/swjs/pro6/base_trim ~/swjs/pro6/test.fa a.fastq b.txt --base-threshold -s20 -Q19
```

```
./base_trim ~/swjs/pro6/test.fa --base-threshold
```

## EXIT VALUES

**int if_files_opened_correctly(FILE *fp)**

-1:  The file isn't opened correctly .

0:   The file is opened correctly .

**int main()**

0:   The program runs smoothly.

-2:   There isn't "--base-threshold" in the command line.

**int if_cut(char q,int phred_value,int threshold)**

1:  The base should be cut, whose quality is below standard.

0:  The base shouldn't be cut, whose quality is above standard.



## Author

Ruoyin Zhou<zhouruoyin@sjtu.edu.cn>

## UPDATE

2022.6.18


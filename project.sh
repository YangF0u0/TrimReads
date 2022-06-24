#!/bin/bash
# Author: Wang xinjie
        least=4
        for ((i=1;i<=15;i++))
        do
                touch tmp$i.fastq
        done
        e=0.1
read -p "which one do you want to choose? 1(fastq) 2(sequence): " choose
case $choose in
        1) read -p "Please input the name of the file: " file
        ;;
        2) read -p "Please input the base sequence: " sequence
        ;;
        *) echo "please choose 1 or 2"
                exit 1
        ;;
esac


for ((i=1;i<=$#;i++))
   do
        j=$(($i+1))
        option=${!i}
                case $option in
                        -a) adapt1=${!j}
                        ;;
                        -A) adapt2=${!j}
                        ;;
                        -e)  e=${!j}
                        ;;
                        -poly) flag=1
                        ;;
                        -i) in=${!j}
                        ;;
                        -d) del=${!j}
                        ;;
                        -p) primer1=${!j}
                        ;;
                        -P) primer2=${!j}
                        ;;
                        -l) least=${!j}
                        ;;
                        -Q*) Q=$option
                        ;;
                       -s*) s=$option
                        ;;
                        +s) S=$option
                        ;;
                        -w*)  w=$option
                        ;;
                        --Window) W=$option
                        ;;
                        --base-threshold) b=$option
                        ;;
                        -N) N=${!j}
                        ;;
                        -rate) r=${!j}
                        ;;
                        -n) n=${!j}
                        ;;
                        -ds) ds=${!j}
                        ;;
                        [ATGC]*|[0-9]*) continue
                        ;;
                        -N) N=${!j}
                        ;;
                        -Nr)  rate=${!j}
                        ;;
                        *) cat project.man
                        ;;
                esac
   done

if [[ $file ]]; then
        if [[ $W ]]; then
                if [[ $Q ]]; then
                        if [[ $s ]]; then
                                if [[ $w ]]; then
                                        if [[ -z $S ]]; then
                                                ./win_splice $file tmp1.fastq $Q $s $w
                                        fi
                                        if [[ $S ]]; then
                                                cat project.man
                                        fi
                                fi
                              if [[ -z $w ]]; then
                                        if [[ -z $S ]]; then
                                                ./win_splice $file tmp1.fastq $Q $s
                                        fi
                                        if [[ $S ]]; then
                                                cat project.man
                                        fi
                                fi
                        fi
                        if [[ -z $s ]]; then
                                if [[ $w ]]; then
                                        if [[ -z $S ]]; then
                                                ./win_splice $file tmp1.fastq $Q $w
                                        fi
                                        if [[ $S ]]; then
                                                ./win_splice $file tmp1.fastq $Q $w $S
                                        fi
                                fi
                                if [[ -z $w ]]; then
                                        if [[ -z $S ]]; then
                                                ./win_splice $file tmp1.fastq $Q
                                        fi
                                        if [[ $S ]]; then
                                                ./win_splice $file tmp1.fastq $Q $S
                                        fi
                                fi
                        fi
                fi

                if [[ -z $Q ]]; then
                        if [[ $s ]]; then
                                if [[ $w ]]; then
                                        if [[ -z $S ]]; then
                                                ./win_splice $file tmp1.fastq $s $w
                                        fi
                                        if [[ $S ]]; then
                                                cat project.man
                                        fi
                                fi
                                if [[ -z $w ]]; then
                                        if [[ -z $S ]]; then
                                                ./win_splice $file tmp1.fastq $s
                                        fi
                                      if [[ $S ]]; then
                                                cat project.man
                                        fi
                                fi
                        fi
                        if [[ -z $s ]]; then
                                if [[ $w ]]; then
                                        if [[ -z $S ]]; then
                                                ./win_splice $file tmp1.fastq $w
                                        fi
                                        if [[ $S ]]; then
                                                ./win_splice $file tmp1.fastq $w $S
                                        fi
                                fi
                                if [[ -z $w ]]; then
                                        if [[ -z $S ]]; then
                                                ./win_splice $file tmp1.fastq
                                        fi
                                        if [[ $S ]]; then
                                                ./win_splice $file tmp1.fastq $S
                                        fi
                                fi
                        fi
                fi
                file="tmp1.fastq"
    fi

        error_file="error.txt"

        if [[ $b ]]; then
                if [[ $Q ]]; then
                        if [[ $s ]]; then
                                if [[ -z $S ]]; then
                                        ./base_trim $file tmp2.fastq $error_file $b $Q $s
                                fi
                                if [[ $S ]]; then
                                        cat project.man
                                fi
                        fi
                        if [[ -z $s ]]; then
                                if [[ -z $S ]]; then
                                        ./base_trim $file tmp2.fastq $error_file $b $Q
                                fi
                                if [[ $S ]]; then
                                       ./base_trim $file tmp2.fastq $error_file $b $Q $S
                                fi
                        fi
                fi

                if [[ -z $Q ]]; then
                        if [[ $s ]]; then
                                        if [[ -z $S ]]; then
                                                ./base_trim $file tmp2.fastq $error_file $b $s
                                        fi
                                        if [[ $S ]]; then
                                                cat project.man
                                        fi
                        fi
                        if [[ -z $s ]]; then
                                if [[ -z $S ]]; then
                                        ./base_trim $file tmp2.fastq $error_file $b
                                fi
                                if [[ $S ]]; then
                                        ./base_trim $file tmp2.fastq $error_file $b $S
                                fi
                        fi
                fi
                file="tmp2.fastq"
    fi


        if [[ flag -eq 1 ]]; then
                  ./poly_main $file > tmp3.fastq
                file="tmp3.fastq"
        fi
    if [[ $adapt1 ]]; then
        if [[ -z $adapt2 ]]; then
                if [[ $in ]]; then
                        if [[ -z $del ]]; then
                         ./i_main $e $in $adapt1 $file $least > tmp4.fastq
                        fi
                        if [[ $del ]]; then
                        echo "warning! \"-d\" , \"-i\", you'd better choose one of them, or your result will likely be inaccurate."
                        fi
                fi
              if [[ -z $in ]]; then
                        if [[ -z $del ]]; then
                        ./aAe_main $e $adapt1 $least $file > tmp4.fastq
                        fi
                        if [[ $del ]]; then
                        ./d_main $e $del $adapt1 $file $least > tmp4.fastq
                        fi
                fi
                file="tmp4.fastq"

        fi
        if [[ $adapt2 ]]; then
                if [[ $in ]]; then
                        if [[ -z $del ]]; then
                        ./i_main $e $in $adapt1 $file $least > tmp5.fastq
                        file="tmp5.fastq"
                        ./i_main $e $in $adapt2 $file $least > tmp6.fastq
                        file="tmp6.fastq"
                        fi
                        if [[ $del ]]; then
                        echo "warning! \"-d\" , \"-i\", you'd better choose one of them, or your result will likely be inaccurate."
                        fi
                fi
                if [[ -z $in ]]; then
                        if [[ $del ]]; then
                        ./d_main $e $del $adapt1 $file $least > tmp5.fastq
                        file="tmp5.fastq"
                        ./d_main $e $del $adapt2 $file $least > tmp6.fastq
                        file="tmp6.fastq"
                        fi
                        if [[ -z $del ]]; then
                        ./aAe_main $e $adapt1 $least $file > tmp5.fastq
                        file="tmp5.fastq"
                        ./aAe_main $e $adapt2 $least $file > tmp6.fastq
                        file="tmp6.fastq"
                        fi
                fi
        fi
   fi
       if [[ $primer1 ]]; then
                if [[ -z $primer2 ]]; then
                ./pP_main $file $primer1 $least > tmp7.fastq
                file="tmp7.fastq"
                fi

                if [[ $primer2 ]]; then
                ./pP_main $file $primer1 $least > tmp7.fastq
                file="tmp7.fastq"
                ./pP_main $file $primer2 $least > tmp8.fastq
                file="tmp8.fastq"
                fi
        fi


        if [[ $ds ]]; then
                ./main_short_empty $file $ds tmp9.fastq
                file="tmp9.fastq"
        fi
        if [[ $n ]]; then
                ./main_clip $file $n tmp10.fastq
                file="tmp10.fastq"
        fi
fi

if [[ $sequence ]]; then
        if [[ $N ]]; then
                ./main_Nmax_num $sequence $N
                exit 0
        fi
        if [[ $rate ]]; then
                ./main_Nmax_rate $sequence $rate
                exit 0
        fi
fi

cat $file > output.fastq
rm -rf tmp*.fastq
exit 0


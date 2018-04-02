#!/bin/bash

#testing |(piping )


echo "testing '|' -commands "
zeo="cat < hel.txt | tr A-Z a-z | tee newOutputFile1 | tr a-z A-Z > newOutputFile2"


fir="ls -a | tr a-z A-Z" # ls to a new file
sec="cat < hel.txt | tr a-z A-Z" # moves content of hel.txt to new.txt
thi="echo end >> new.txt | tr a-z A-Z" #append end to the new.txt
fou="cat main.cpp >> new.txt" 
fif=">> hello.txt" # nothing happens
six="cat < hel.txt | tr a-z A-Z"
sev="ls > hel.txt | tr a-z A-Z" 
eig=" ls -a | echo 8 && echo when"
nin="ls -a; echo 9 | echo 9.9"
ten="cat < hel.txt | tr A-Z a-z"
ele="cat < hel.txt | tr a-z A-Z && cat < hel.txt | tr a-z A-Z" 
twl="echo hello | echo fail"
thr="s  echo true | ls"
a="echo a | echo b | echo d"
b="ls | tr a-z A-Z | echo bye"
c="cat main.cpp | tr a-z A-Z | tee file.txt "
d="echo main.cpp | tr a-z A-Z"
e="echo a | ls | ls"
f=" echo bash | ls | tr A-Z a-z"
t= "cat main.cpp | tr A-Z a-z "
q= "echo and | ls;"
u= "echo and | echo no | te data.txt" 


    echo $zeo
    eval $zeo 
    
    echo $fir
    eval $fir
    
    echo $sec
    eval $sec
    
    echo $thi
    eval $thi
    
    echo $fou
    eval $fou
    
    echo $fif
    eval $fif

    echo $six
    eval $six
    
    echo $sev
    eval $sev
    
    echo $eig
    eval $eig
    
    echo $nin
    eval $nin
    
    echo $ten
    eval $ten

    echo $ele
    eval $ele
    
    echo $twl
    eval $twl
    
    echo $thr
    eval $thr
    
    echo $a
    eval $a
    
    echo $b
    eval $b
    
    echo $c
    eval $c
    
    echo $e
    eval $e 
    
    echo $f
    eval $f
    
    echo $t
    eval $t
    
    echo $q
    eval $q
    
    echo $u
    eval $u
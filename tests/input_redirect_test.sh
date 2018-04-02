#!/bin/bash

#testing <(input redirect)


echo "testing '<' -commands "
zeo="cat < hel.txt" # ls to an existing file
fir=" < new.txt" # ls to a new file
sec="sort < file_list.txt" # moves content of hel.txt to new.txt
thi="echo < new.txt" #nothing happens
fou="cat main.cpp < new.txt" 
fif="" # nothing happens
six="cat < hel.txt #test"
sev="## cat < hel.txt # nothing happens" 
eig="cat < hel.txt && cat << hel2.txt" #executes both
nin="cat < hel.txt || cat < hel2.txt" # executes only one of them
ten="cat < hel.txt && cat < he2.txt || cat < hel.txt"
ele="cat < hel.txt#&& cat < he2.txt || cat < hel.txt" 
twl="echo bye || cat < hel.txt"
thr="echo begun || cat < hel.txt && echo end"
a="; echo begun || cat < hel.txt && echo end"
b=": cat < hel.txt || echo failed && echo pass"
c="; cat < hel.txt && cat < hel2.txt || echo fail && echo pass"
d="ls && ls && ls && ls && echo end"
# e="echo being; ls && ls && ls || ls && echo end; ls || ls || echo end"
# f= "ls; ls; echo hello && echo bye; echo be || echo end"
# t= "echo got phone ? || echo no ; echo yes ; echo ls; echo or;"
# q= "echo and ; echo or; echo ;"
# u= "echo and || echo no" 


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
    
    echo $d
    eval $d 
    
    
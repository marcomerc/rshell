#!/bin/bash

#testing >(output redirection)


echo "testing '>' -commands "
zeo="ls > hel.txt" # ls to an existing file
fir="ls > hel.txt" # deletes content of hel.txt and add ls
sec="hel.txt > new.txt" # moves content of hel.txt to new.txt
thi="echo end > new.txt" #append end to the new.txt
fou="cat main.cpp > new.txt" 
fif="cat hello > hello.txt" # deletes everything in hello.txt/ or create new file
six="echo b > hel.txt"
sev="ls -a > hel.txt" 
eig="echo end of story > he.txt"
nin="echo 1 2 3 4 > coun.txt"
ten="cat main.cpp > data.txt"
ele="cat file.txt > copy.txt" 
twl="echo main.cpp > data.txt"
thr="echo filename > fileNames.txt"
a=" echo bitcho  > b.txt"



# b="ls && echo hello; echo end && ls -a; echo bye"
# c="ls || ls || ls || ls || ls || ls && echo end"
# d="ls && ls && ls && ls && echon end"
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
    
    # echo $b
    # eval $b
    
    # echo $c
    # eval $c
    
    # echo $e
    # eval $e 
    
    # echo $f
    # eval $f
    
    # echo $t
    # eval $t
    
    # echo $q
    # eval $q
    
    # echo $u
    # eval $u
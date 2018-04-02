#!/bin/bash

#testing >>(appending a file or command to  another file)


echo "testing '>>' -commands "
zeo="ls >> hel.txt" # ls to an existing file
fir="ls >> new.txt" # ls to a new file
sec="hel.txt >> new.txt" # moves content of hel.txt to new.txt
thi="echo end >> new.txt" #append end to the new.txt
fou="cat main.cpp >> new.txt" 
fif=">> hello.txt" # nothing happens
six="ls >> hell.txt # wow"
sev="cat marco >> hel.txt #&& echo hello"
eig="echo hello >> data.txt"
nin="echo '1919' >> data.txt # comment" 
ten="echo i >> da.txt"
ele="cat main.cpp >> file.txt"
twl="ls >> file.txt && echo hello"
thr="ls >> main.txt > "
a="echo a >> hel.txt && echo end || echo st"
b="echo >> hel.txt"

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
    
    echo $b
    eval $b
    
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
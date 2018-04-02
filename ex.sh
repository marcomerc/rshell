#!/bin/bash

# This the bash script 

thevar="$*" ##this stores the command line arguemnt into a string 

##these are flags to check which version of the test command to use
flage="false"
flagd="false"
flagf="false"

## this tokenizes the argument being pass into the script
set -- $thevar

## this is the variable to hold the pathname
path="tops"

  
  

  
i=0  # this check the number of flags pass in

#this iterates through the command line argument and increment i
#for each flag found and sets the pathname to path
for thevar in "$@"
do

    if [ $thevar = "-e" ] ; then
      
        
        i=$((i+1))
      flage="true"      #sets the flag for the flag -e for true
    fi
    if [ $thevar = "-d" ] ; then
      
        i=$((i+1))
      flagd="true"      #sets the flag for the flag -d for true
    fi
    if [ $thevar = "-f" ] ; then  
      i=$((i+1))
      
      flagf="true"      #sets the flag for the flag -f for true
    fi
    if [ "$thevar" != "]" ] ; then
      path=$thevar # rewrites the path for the actual pathname
    fi
    
done

###check  if here is more than 1 flag or if there is none
  ##if there are no flags then the default flag 
  if [ "$i" -eq 0 ];then
    flage="true"
    
  fi
  
  ##if there are more than one flag then output too many argument
  if [ "$i" -gt 1 ]; then
    echo "test: too many arguemnts"
    exit 0
  fi
  
  #exectutes if the flag is -e
  if [[ $flage == "true" ]]; then 
    if [ -e $path ]; then 
      echo "(True)"     #return true if the path exists
      exit 1
    else
      echo "(False)"    #return false if the path does not exists
      exit 0
    fi
  fi
    


  #execute if the flag is -f
if [[ $flagf == "true" ]]; then
  if [ -f $path ]; then 
    echo "(True)"
    exit 1
  else
    echo "(False)"
    exit 0
  fi
fi


  #execute if the flag is -d
if [[ $flagd == "true" ]]; then
    if test -d $path ; then 
      echo "(True)"     #return true if the path exits
      exit 1
    else
      echo "(False)"    #return false if the path does not exist
      exit 0
    fi
  fi


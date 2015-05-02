#! /bin/sh

cd $(dirname $0)
declare -a term=($(<term))
for ((i=0; i<${#term[@]}; i++)); do
  TERM=${term[i]}
  ./Words
  #../Ncurses/Ncurses
  #vim /main.c
  echo -e "\e[0m\e[2J\e[1;1H${term[i]}"
  read -sn 3
done


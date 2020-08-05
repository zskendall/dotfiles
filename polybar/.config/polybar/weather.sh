#!/bin/bash

ASCII_WEATHER="$(curl -s 'wttr.in?TQu0')"
SUN=`curl -s wttr.in?format=j1 | jq .weather[0].astronomy[0]`
SUNRISE=`date --date="$(echo "$SUN" | jq .sunrise | tr -d '"')" +%s`
SUNSET=`date --date="$(echo "$SUN" | jq .sunset | tr -d '"')" +%s`
[ $SUNSET -lt $(date +%s) ] || [ $SUNRISE -gt $(date +%s) ] && NIGHT=1

if grep -iq "storm" <<< "$ASCII_WEATHER"; then
  CONDITION="%{T6}%{T-}"
elif grep -iq "rain\|shower" <<< "$ASCII_WEATHER"; then
  if grep -iq "light\|patchy" <<< "$ASCII_WEATHER"; then
    [ ! -z $NIGHT ] && CONDITION="%{T6}%{T-}" || CONDITION="%{T6}%{T-}"
  else CONDITION="%{T6}%{T-}"
  fi
elif grep -iq "snow" <<< "$ASCII_WEATHER"; then
  CONDITION="%{T2}%{T-}"
elif grep -iq "cloudy\|overcast" <<< "$ASCII_WEATHER"; then
  if grep -iq "partly" <<< "$ASCII_WEATHER"; then
    [ ! -z $NIGHT ] && CONDITION="%{T6}%{T-}" || CONDITION="%{T6}%{T-}"
  else CONDITION="%{T2}%{T-}"
  fi
elif grep -iq "haze\|hazy\|mist\|fog" <<< "$ASCII_WEATHER"; then
  CONDITION="%{T2}%{T-}"
elif grep -iq "smoke" <<< "$ASCII_WEATHER"; then
  CONDITION="%{T2}%{T-}"
elif grep -iq "Sunny\|clear" <<< "$ASCII_WEATHER"; then
  [ ! -z $NIGHT ] && CONDITION="%{T6}%{T-}" || CONDITION="%{T2}%{T-}"
else
  CONDITION="%{T7}$(curl -s wttr.in?format='%c+%t' | awk -F'[[:space:]]*+' '{print $1}')"
fi

TEMP=$(echo $ASCII_WEATHER | grep -m 1 -Eo -e '-?[[:digit:]].*°F')

re='(-?[[:digit:]]+)((.*-|..)(-?[[:digit:]]+))?'
[[ $TEMP =~ $re ]]
lower=${BASH_REMATCH[1]}
upper=${BASH_REMATCH[4]}
[ ! -z $upper ] && TEMP="$(( (lower + upper) / 2 ))" || TEMP=$lower

if [ -z "$TEMP" ]
then
  echo "$CONDITION"
elif [ $TEMP -le 32 ]
then
  COLOR="#e6f2ff" # pale blue
elif [ $TEMP -le 45 ]
then
  COLOR="#66ff66" # green
elif [ $TEMP -le 70 ]
then
  COLOR="#bfff00" # light green / chartruese
elif [ $TEMP -le 75 ]
then
  COLOR="#ffff00" # yellow
elif [ $TEMP -le 80 ]
then
  COLOR="#ffcc00" # gold
elif [ $TEMP -ge 100 ]
then
  COLOR="#ff0000" # pure red
else
  COLOR="#ff6600" # orange
fi

echo "$CONDITION%{T4}%{F$COLOR} $TEMP%{F-}°F%{T-}"

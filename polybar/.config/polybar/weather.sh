#!/bin/bash

JSON_WEATHER=`curl -s wttr.in?format=j1`
CURRENT=`echo $JSON_WEATHER | jq .current_condition[0]`
TEMP=`echo $CURRENT | jq .temp_F | tr -d '"'`
WEATHER=`echo $CURRENT | jq .weatherDesc[0].value`
SUN=`echo $JSON_WEATHER | jq .weather[0].astronomy[0]`
SUNRISE=`date --date="$(echo "$SUN" | jq .sunrise | tr -d '"')" +%s`
SUNSET=`date --date="$(echo "$SUN" | jq .sunset | tr -d '"')" +%s`
[ $SUNSET -lt $(date +%s) ] || [ $SUNRISE -gt $(date +%s) ] && NIGHT=1

if grep -iq "storm" <<< "$WEATHER"; then
  CONDITION="%{T6}%{T-}"
elif grep -iq "rain\|shower\|drizzle" <<< "$WEATHER"; then
  if grep -iq "light\|patchy\|drizzle" <<< "$WEATHER"; then
    [ ! -z $NIGHT ] && CONDITION="%{T6}%{T-}" || CONDITION="%{T6}%{T-}"
  else CONDITION="%{T6}%{T-}"
  fi
elif grep -iq "snow" <<< "$WEATHER"; then
  CONDITION="%{T2}%{T-}"
elif grep -iq "cloudy\|overcast" <<< "$WEATHER"; then
  if grep -iq "partly" <<< "$WEATHER"; then
    [ ! -z $NIGHT ] && CONDITION="%{T6}%{T-}" || CONDITION="%{T6}%{T-}"
  else CONDITION="%{T2}%{T-}"
  fi
elif grep -iq "haze\|hazy\|mist\|fog" <<< "$WEATHER"; then
  CONDITION="%{T2}%{T-}"
elif grep -iq "smoke" <<< "$WEATHER"; then
  CONDITION="%{T2}%{T-}"
elif grep -iq "Sunny\|clear" <<< "$WEATHER"; then
  [ ! -z $NIGHT ] && CONDITION="%{T6}%{T-}" || CONDITION="%{T2}%{T-}"
else
  CONDITION="%{T7}$(curl -s wttr.in?format='%c+%t' | awk -F'[[:space:]]*+' '{print $1}')"
fi

if [ -z "$TEMP" ]; then
  echo "$CONDITION"
elif [ $TEMP -le 32 ]; then
  COLOR="#e6f2ff" # pale blue
elif [ $TEMP -le 45 ]; then
  COLOR="#66ff66" # green
elif [ $TEMP -le 70 ]; then
  COLOR="#bfff00" # light green / chartruese
elif [ $TEMP -le 75 ]; then
  COLOR="#ffff00" # yellow
elif [ $TEMP -le 80 ]; then
  COLOR="#ffcc00" # gold
elif [ $TEMP -ge 100 ]; then
  COLOR="#ff0000" # pure red
else
  COLOR="#ff6600" # orange
fi

echo "$CONDITION%{T4}%{F$COLOR} $TEMP%{F-}°F%{T-}"

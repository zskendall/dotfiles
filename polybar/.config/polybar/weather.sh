#!/bin/bash

ASCII_WEATHER="$(curl -s 'wttr.in/?TQu0')"
CONDITION="STRUGGLES"

if grep -iq "Sunny\|clear" <<< "$ASCII_WEATHER"
then
  CONDITION="%{T2}%{T-}"
elif grep -iq "cloudy\|overcast" <<< "$ASCII_WEATHER"
then
  CONDITION="%{T2}%{T-}"
elif grep -iq "haze\|hazy\|mist" <<< "$ASCII_WEATHER"
then
  CONDITION="%{T2}%{T-}"
fi

TEMP=$(echo $ASCII_WEATHER | grep -m 1 -Eo -e '-?[[:digit:]].*°F')
TEMP=${TEMP%$' °F'}

if [[ $TEMP == *-* ]]
then
  # Use regex to extract temperature values
  re='(-?[[:digit:]]+).*-(-?[[:digit:]]+)'
  [[ $TEMP =~ $re ]]
  lower=${BASH_REMATCH[1]}
  upper=${BASH_REMATCH[2]}

  # Calculate average truncated to integer
  TEMP="$(( (lower + upper) / 2 ))"
fi

COLOR='#ffffff'
if [ -z "$TEMP" ]
then
  TEMP=$TEMP
elif [ $TEMP -le 32 ]
then
  TEMP="%{T2}%{T-}"
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
  TEMP="%{T2}%{T-}"
  COLOR="#ff0000" # pure red
else
  COLOR="#ff6600" # orange
fi

echo $CONDITION "|" %{F$COLOR}$TEMP%{F-} "°F"

#!/bin/bash
##-----------------------------LICENSE NOTICE------------------------------------
##  This file is part of CPCtelera: An Amstrad CPC Game Engine 
##  Copyright (C) 2015 ronaldo / Fremos / Cheesetea / ByteRealms (@FranGallegoBR)
##
##  This program is free software: you can redistribute it and/or modify
##  it under the terms of the GNU General Public License as published by
##  the Free Software Foundation, either version 3 of the License, or
##  (at your option) any later version.
##
##  This program is distributed in the hope that it will be useful,
##  but WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU General Public License for more details.
##
##  You should have received a copy of the GNU General Public License
##  along with this program.  If not, see <http://www.gnu.org/licenses/>.
##------------------------------------------------------------------------------

###########################################################################
##                        CPCTELERA ENGINE                               ##
##               Bash function library for scripting                     ##
##-----------------------------------------------------------------------##
## This file is intended to be used as a repository of bash functions to ##
## be used in CPCtelera's bash scripts.                                  ##
###########################################################################

## Colors for ANSI terminal
COLOR_LIGHT_RED=$'\033[1;31;49m'
COLOR_LIGHT_GREEN=$'\033[1;32;49m'
COLOR_LIGHT_YELLOW=$'\033[1;33;49m'
COLOR_LIGHT_BLUE=$'\033[1;34;49m'
COLOR_LIGHT_MAGENTA=$'\033[1;35;49m'
COLOR_LIGHT_CYAN=$'\033[1;36;49m'
COLOR_LIGHT_WHITE=$'\033[1;37;49m'
COLOR_INVERTED_LIGHT_RED=$'\033[1;39;41m'
COLOR_INVERTED_LIGHT_GREEN=$'\033[1;39;42m'
COLOR_INVERTED_GREEN=$'\033[0;39;42m'
COLOR_INVERTED_CYAN=$'\033[0;39;46m'
COLOR_INVERTED_WHITE=$'\033[0;39;47m'
COLOR_GREEN=$'\033[0;32;49m'
COLOR_MAGENTA=$'\033[0;35;49m'
COLOR_CYAN=$'\033[0;36;49m'
COLOR_NORMAL=$'\033[0;39;49m'

## $1: Error Message
## $2: Number of error that will be returned to shell
function Error {
   echo
   echo ${COLOR_LIGHT_RED}
   echo "#########################"
   echo "## UNRECOVERABLE ERROR ##"
   echo "#########################"
   echo "##> ${COLOR_LIGHT_YELLOW}${1}${COLOR_NORMAL}"
   echo
   exit $2
}

## $1: Stage
## $2: Message
function stageMessage {
   echo ${COLOR_LIGHT_BLUE}
   echo "====================================================="
   echo "== ${COLOR_LIGHT_MAGENTA}${1}: ${COLOR_MAGENTA}${2}${COLOR_LIGHT_BLUE}"
   echo "====================================================="${COLOR_NORMAL}
}

## Clears the screen
function clearScreen {
   echo -e "\033[H\033[J"
}

## $1: Seconds between characters
## $2: Message to write
function machineEcho {
   local i
   for i in $(seq 0 ${#2}); do
      echo -n "${2:${i}:1}"
      sleep "$1"
   done
}

## $1: Color ANSI sequence
## $2: Seconds between characters
## $3: Message to write
function coloredMachineEcho {
   echo -n "$1"
   machineEcho $2 "$3"
}

## Welcome to CPCtelera
##
function welcomeMessage {
   local DLY_T1=0.04
   local DLY_3D=0.002
   local DLY_T2=0.01

   echo -n "${COLOR_LIGHT_BLUE}"
   machineEcho $DLY_T1 "Welcome to..."$'\n'
   sleep 0.4
   echo -n "${COLOR_LIGHT_YELLOW}"
   machineEcho $DLY_3D " ____     ____     ____     __            ___"$'\n'
   machineEcho $DLY_3D "/\\  _\`\\  /\\  _\`\\  /\\  _\`\\  /\\ \\__        /\\_ \\"$'\n'
   machineEcho $DLY_3D "\\ \\ \\/\\_\\\\ \\ \\L\\ \\\\ \\ \\/\\_\\\\ \\ ,_\\     __\\//\\ \\       __   _ __    __"$'\n'
   machineEcho $DLY_3D " \\ \\ \\/_/_\\ \\ ,__/ \\ \\ \\/_/_\\ \\ \\/   /'__\`\\\\ \\ \\    /'__\`\\/\\\`'__\\/'__\`\\"$'\n'
   machineEcho $DLY_3D "  \\ \\ \\L\\ \\\\ \\ \\/   \\ \\ \\L\\ \\\\ \\ \\_ /\\  __/ \\_\\ \\_ /\\  __/\\ \\ \\//\\ \\L\\.\\_"$'\n'
   machineEcho $DLY_3D "   \\ \\____/ \\ \\_\\    \\ \\____/ \\ \\__\\\\ \\____\\/\\____\\\\ \\____\\\\ \\_\\\\ \\__/.\\_\\"$'\n'
   machineEcho $DLY_3D "    \\/___/   \\/_/     \\/___/   \\/__/ \\/____/\\/____/ \\/____/ \\/_/ \\/__/\\/_/"$'\n'
   echo ${COLOR_LIGHT_BLUE}
   machineEcho $DLY_T2 "This setup script will help you configure CPCtelera in your system."
   echo
}

## $1: Type of file (file, directory)
## $2: File/Directory to check for existance
function EnsureExists {
   local MOD
   case "$1" in
      file)  
         MOD="-f";;
      directory) 
         MOD="-d" ;;
      *)
         Error "Filetype '$1' unrecognized while testing file '$2'."
   esac
   if [ ! $MOD "$2" ]; then
      Error "$1 '$2' does not exist, and it is required for CPCTelera framework to work propperly."
   elif [ ! -r "$2" ]; then
      Error "$1 '$2' is not readable (check for permissions)."
   fi
}

## $1: X
## $2: Y
##
function setCursorXY {
   echo $'\033[${2};${1}H'
}

## Saves Cursor Position
function saveCursorPos {
   echo -n $'\033[s'
}

## Restores Cursor Position
function restoreCursorPos {
   echo -n $'\033[u'
}

## $1: Number of characters to move cursor left
##
function cursorLeft {
   for i in $(seq 1 ${1}); do
      echo -n $'\033[D'
   done
}

## $1: PID of the process
## Returns 0 if running, error otherwise
function processRunning {
   kill -s 0 "$1" &> /dev/null
   return $?
}


## $1: Size (in characters, without brackets)
## $2: Percentage
## $3: ANSI color sequence for BARS
## $4: ANSI color sequence for Spaces
##
function drawProgressBar {
   local PCT
   if (( $2 > 100 )); then
      PCT=100
   elif (( $2 < 0 )); then
      PCT=0
   else
      PCT=$2
   fi
   local NUMBARS=$(($1 * PCT / 100))
   if (( NUMBARS > $1 )); then
      NUMBARS=$1
   fi
   local NUMSPACES=$(($1 - NUMBARS))
   echo -n ${3}
   if ((NUMBARS > 0)); then
      printf ' %.0s' $(seq 1 ${NUMBARS})
   fi
   if ((NUMSPACES > 0)); then
      echo -n ${4}
      printf ' %.0s' $(seq 1 ${NUMSPACES})
   fi
   echo -n ${COLOR_NORMAL} ${PCT}%
}

## $1: Command to check for in the system
##
function EnsureCommandAvailable {
   if ! command -v "$1" >/dev/null 2>&1; then
      Error "'$1' is required to build CPCtelera, but it's not installed. Please, install it in your system and launch setup again."
   fi
}

## $1: header file name
##
function EnsureCPPHeaderAvailable {
   local ERRTMP=$(mktemp).err
   local OUTTMP=$(mktemp).out
   local SRCTMP=$(mktemp).cpp
   echo "#include <${1}>" > "$SRCTMP"
   echo "int main(void) { return 0; }" >> "$SRCTMP"
   g++ -o "$OUTTMP" -c "$SRCTMP" 2> "$ERRTMP"
   if [ -s "$ERRTMP" ]; then
      Error "Header file '$1' is not found in the system, and it is required for building CPCTelera tools. Please, install it and launch setup again."
   fi 
}

## $1: PID of the process to monitor
## $2: Logfile generated by the process
## $3: Total Size for the logfile at the end of the process
## $4: Size of the progressBar
## $5: Sleep interval (between checks)
function superviseBackgroundProcess {
   # Go checking the build process until it finishes
   local PROCPID=$1
   local LOGFILE=$2
   local MAXBYTES=$3
   local BARSIZE=$4
   local SLEEPTIME=$5
   local BYTES
   local PCT
   local EXIT_STATUS
   while processRunning "$PROCPID"; do
      BYTES=$(wc -c ${LOGFILE} | sed -r 's/([^0-9]*)//g')
      PCT=$((BYTES * 100 / MAXBYTES))
      saveCursorPos
      drawProgressBar "${BARSIZE}" "${PCT}" ${COLOR_INVERTED_GREEN} ${COLOR_INVERTED_WHITE}
      sleep ${SLEEPTIME}
      restoreCursorPos
   done
   wait "$PROCPID" && EXIT_STATUS=$?
   if [[ "$EXIT_STATUS" == 0 ]]; then
      drawProgressBar "${BARSIZE}" 100 ${COLOR_INVERTED_LIGHT_GREEN} ${COLOR_INVERTED_WHITE}
   else
      drawProgressBar "${BARSIZE}" "${PCT}" ${COLOR_INVERTED_LIGHT_RED} ${COLOR_INVERTED_WHITE}
   fi
   return $EXIT_STATUS
}
#!/bin/env bash


echo -e " OpenADS storage configuration tool \n"

# check if the passed arguments are at least one
if [ "$#" -ne 1 ];
then
  echo -e "  [ERROR] :: Passed in improper amount of arguments\n"
fi


while getopts u:p flag
do
  case "${flag}" in
    u) DRIVENAME=${OPTARG};;
    p) PASSPHRASE=${OPTARG};;
    *) ASS=${OPTARG};;
  esac
done


echo "  [INFO] :: Setting username to ${DRIVENAME}"
echo "  [INFO] :: Using password to ${PASSPHRASE}"

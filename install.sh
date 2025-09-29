#!/bin/bash

export current=$PWD
#######################################
#	moulinette (correction exercices)
cd ~
git clone https://github.com/khairulhaaziq/mini-moulinette.git
echo "alias mini='~/mini-moulinette/mini-moul.sh'" >> ~/.bashrc && source ~/.bashrc
#	use --> cd C02 && mini C02

########################################
#	norminette (facultatif)

pipxInstall() {
	sudo apt update
	sudo apt install python3-setuptools
	sudo apt install pipx
	pipx install norminette
	pipx ensurepath

	hash -r
}

echo Do you have python3 ? y/n
read -e response
case $response in
	"y") python3 -m pip install -U norminette ;;
	"n") pipxInstall ;;
	*) echo something went wrong ;;
esac

echo Instalation complete !
cd $current

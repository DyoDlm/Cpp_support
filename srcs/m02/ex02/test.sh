name=surcharge

echo $name

if [ -f $name ];
then echo "executable present";
else
	make;
fi

if [ -f MyOutPut ];
then rm MyOutPut;
fi

./$name > MyOutPut

diff MyOutPut OfficialOutPut


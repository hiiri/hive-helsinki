i=0
while [ $i -lt 26 ]
do
	echo "$i"
	echo "$(./fillit "test_errors/error_$i")"
	i=$[$i+1]
done

i=0
number=20

while [ "$i " -le "$number" ]; do
	if [ "$i" -le 9 ]; then
		./puzzle GreedyBFS in0"$i".txt>> outMain05.csv
	else
		./puzzle GreedyBFS in"$i".txt>> outMain05.csv
	fi

	i=$(($i + 1))
done
#usage for test:
#./ex2.sh & ./ex2.sh

if ln test test.lock &> /dev/null; then
	echo $(($(tail -n 1 test) + 1)) >> test
	rm test.lock
else
	echo "Something already uses file 'test'"
fi


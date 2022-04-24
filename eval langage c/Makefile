test: eval
	./eval "NONA" "0=>(NON(1+0).1)"  "1.1+0.1" "(1+0))" "1.(NON0.1)"
	
eval: eval.o Operation.o 
	gcc -Wall -o eval eval.o Operation.o 

eval.o: eval.h eval.c
	gcc -Wall -c eval.c

Operation.o: eval.h Operation.c
	gcc -Wall -c Operation.c

clean: 
	rm -f eval.o
	rm -f eval
	rm -f Operation.o
	rm -f Operation
	ls -l

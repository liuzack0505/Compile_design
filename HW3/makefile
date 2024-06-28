make:
	$(MAKE) clean
	$(MAKE) build

build:
	flex scanner.l
	byacc -vd parser.y 
	gcc -o mycodegen lex.yy.c y.tab.c util.c -lfl
clean:
	rm -f lex.yy.c mycodegen y.output y.tab.c y.tab.h
compile: file?=
compile:
	./mycodegen < ${file}
	riscv32-unknown-elf-gcc main.c codegen.S
	qemu-riscv32 a.out
bonus: file?=
bonus:
	./mycodegen < ${file}
	

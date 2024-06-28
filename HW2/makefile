MAKEFLAGS += --no-print-directory

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m # No Color

make:
	flex scanner.l
	byacc -d parser.y 
	gcc -o parser lex.yy.c y.tab.c -lfl
clean:
	rm -f lex.yy.c parser y.output y.tab.c y.tab.h

compare: FILE1 ?=

compare: 
	@if [ -z "$(FILE1)" ]; then \
		echo "Usage: make compare FILE1=<file1>"; \
		exit 1; \
	fi
	@dos2unix ${FILE1} > /dev/null 2>&1
	@./parser < ${FILE1} --> ./output/my_parser.txt 
	@./golden_parser < ${FILE1} --> ./output/golden_parser.txt
	@diff ./output/my_parser.txt ./output/golden_parser.txt

compare-all: FOLDER ?=

compare-all: 
	@if [ -z "$(FOLDER)" ]; then \
		echo "Usage: make compare FOLDER=<folder>"; \
		exit 1; \
	fi
	@for file in $(FOLDER)/*; do \
		echo "Comparing $$file"; \
		if $(MAKE) compare FILE1=$$file; then \
			echo -e "$(GREEN)CORRECT in $$file$(NC)"; \
		else \
			echo -e "$(RED)ERROR in $$file$(RC)"; \
		fi \
	done

	

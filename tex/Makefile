.PHONY: all clean

TEXFILES = $(shell echo *.tex)
LATEX = pdflatex -halt-on-error -file-line-error

pf2022.pdf: $(TEXFILES)
	echo '\input{introduction.tex}' > contents.tex
	echo '\input{basics.tex}' >> contents.tex
	$(LATEX) pf2022
	$(LATEX) pf2022
	rm contents.tex

introduction.pdf: pf2022.tex frontmatter.tex introduction.tex
	echo '\input{introduction.tex}' > contents.tex
	$(LATEX) -jobname=introduction pf2022
	$(LATEX) -jobname=introduction pf2022
	rm contents.tex

basics.pdf: pf2022.tex frontmatter.tex basics.tex
	echo '\input{basics.tex}' > contents.tex
	$(LATEX) -jobname=basics pf2022
	$(LATEX) -jobname=basics pf2022
	rm contents.tex

clean:
	rm -f *.out *.aux *.nav *.toc *.vrb *.log *.snm

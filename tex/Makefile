.PHONY: all clean

TEXFILES = $(shell echo *.tex)
LATEX = pdflatex -halt-on-error -file-line-error
TRANS = "\PassOptionsToClass{trans}{beamer}\input{pf2022}"

pf2022.pdf: $(TEXFILES)
	echo '\input{introduction.tex}' > contents.tex
	echo '\input{basics.tex}' >> contents.tex
	$(LATEX) pf2022
	$(LATEX) pf2022
	rm contents.tex

introduction.pdf: pf2022.tex frontmatter.tex introduction.tex
	echo '\input{introduction.tex}' > contents.tex
	$(LATEX) -jobname=introduction $(TRANS)
	$(LATEX) -jobname=introduction $(TRANS)
	rm contents.tex

basics.pdf: pf2022.tex frontmatter.tex basics.tex
	echo '\input{basics.tex}' > contents.tex
	$(LATEX) -jobname=basics $(TRANS)
	$(LATEX) -jobname=basics $(TRANS)
	rm contents.tex

clean:
	rm -f *.out *.aux *.nav *.toc *.vrb *.log *.snm

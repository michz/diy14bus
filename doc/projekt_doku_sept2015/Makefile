BIN_PDFLATEX 	= pdflatex
BIN_BIBTEX 		= bibtex
BIN_VIEW 		= xdg-open
CP = cp
RM = rm -rf

-include config.mk

TEX_FILES = $(wildcard *.tex)
PDF_FILES = $(TEX_FILES:.tex=.pdf)


.PHONY: all clean clean-latex clean-bibtex clean-all dist-clean view preview


all: $(PDF_FILES)

%.pdf: %.tex %.bib
	$(BIN_PDFLATEX) $< && \
		$(BIN_BIBTEX) $(<:.tex=) && \
		$(BIN_PDFLATEX) $< && \
		$(BIN_PDFLATEX) $<




#####################################################################
###                 viewing/presenting targets                    ###
#####################################################################

view: view-$(PDF_FILES)

view-%.pdf: %.pdf
	$(BIN_VIEW) $<


preview: preview-$(PDF_FILES)

preview-%.pdf: %.tex
	latexmk -pdf -pvc $<


#####################################################################
###                     cleaning targets                          ###
#####################################################################

clean: clean-latex clean-bibtex

clean-latex:
	$(RM) *.aux *.d *.dvi *.log *.nav *.out *.snm *.toc *.tdo *.fls *.fdb_latexmk

clean-bibtex:
	$(RM) *.bbl *.blg

clean-all: clean
	$(RM) $(PDF_FILES)

dist-clean: clean-all

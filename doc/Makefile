BIN_PDFLATEX = pdflatex
BIN_BIBTEX = bibtex
BIN_VIEW = xdg-open 
BIN_PRESENT = pdf-presenter-console
CP = cp
RM = rm -rf

DURATION = 30
WARN_END = 5

-include config.mk

TEX_FILES = $(wildcard *.tex)
PDF_FILES = $(TEX_FILES:.tex=.pdf)


.PHONY: all clean clean-latex clean-bibtex clean-all dist-clean 
.PHONY: view view-presentation view-handout view-% 
#present present-% 
.PHONY: preview-handout preview-presentation handout presentation


#all: $(PDF_FILES)
all: presentation handout Ausarbeitung

%.pdf: %.tex %.bib
	$(BIN_PDFLATEX) $< && \
		$(BIN_BIBTEX) $(<:.tex=) && \
		$(BIN_PDFLATEX) $< && \
		$(BIN_PDFLATEX) $<




#####################################################################
###                        presentation                           ###
#####################################################################

presentation: presentation.$(PDF_FILES)
	@echo "Cleaning up temporary files..."
	make clean-presentation


# create temporary source file for handout customizations
presentation.%.tex: %.tex
	$(CP) $< presentation.$<
	#sed 's/\\documentclass\[presentation\]{beamer}/\\documentclass[handout]{beamer}/' \
	#	< $< > handout.$<

presentation.%.bib: %.bib
	$(CP) $< presentation.$<



#####################################################################
###                           handout                             ###
#####################################################################

handout: handout.$(PDF_FILES)
	@echo "Cleaning up temporary files..."
	make clean-handout


# create temporary source file for handout customizations
handout.%.tex: %.tex
	sed 's/\\documentclass\[presentation\]{beamer}/\\documentclass[handout]{beamer}/' \
		< $< > handout.$<

handout.%.bib: %.bib
	$(CP) $< handout.$<



#####################################################################
###                 viewing/presenting targets                    ###
#####################################################################

view: view-$(PDF_FILES)
view-handout: view-handout.$(PDF_FILES)
view-presentation: view-presentation.$(PDF_FILES)
view-Ausarbeitung: view-Ausarbeitung.$(PDF_FILES)

present: present-presentation.$(PDF_FILES)


view-%.pdf: %.pdf
	$(BIN_VIEW) $<

present-%.pdf: %.pdf
	$(BIN_PRESENT) -d $(DURATION) -l $(WARN_END) -u 60 $<



#####################################################################
###                        Ausarbeitung                           ###
#####################################################################

Ausarbeitung: Ausarbeitung.$(PDF_FILES)


Ausarbeitung.%.bib: %.bib
	$(CP) -v $< Ausarbeitung.$<


#####################################################################
###                     cleaning targets                          ###
#####################################################################

clean: clean-latex clean-bibtex clean-handout clean-presentation clean-Ausarbeitung

clean-latex:
	$(RM) *.aux
	$(RM) *.d
	$(RM) *.dvi
	$(RM) *.log
	$(RM) *.nav
	$(RM) *.out
	$(RM) *.snm
	$(RM) *.toc

clean-bibtex:
	$(RM) *.bbl
	$(RM) *.blg

clean-handout:
	$(RM) handout.*.tex
	$(RM) handout.*.bib
	$(RM) handout.*.aux
	$(RM) handout.*.bbl
	$(RM) handout.*.blg
	$(RM) handout.*.log
	$(RM) handout.*.nav
	$(RM) handout.*.out
	$(RM) handout.*.snm
	$(RM) handout.*.toc
	$(RM) handout.*.lof
	$(RM) handout.*.lot
	$(RM) handout.*.tdo
	
clean-presentation:
	$(RM) presentation.*.tex
	$(RM) presentation.*.bib
	$(RM) presentation.*.aux
	$(RM) presentation.*.bbl
	$(RM) presentation.*.blg
	$(RM) presentation.*.log
	$(RM) presentation.*.nav
	$(RM) presentation.*.out
	$(RM) presentation.*.snm
	$(RM) presentation.*.toc
	$(RM) presentation.*.lof
	$(RM) presentation.*.lot
	$(RM) presentation.*.tdo
	
clean-Ausarbeitung:
	$(RM) Ausarbeitung.*.bib
	$(RM) Ausarbeitung.*.aux
	$(RM) Ausarbeitung.*.bbl
	$(RM) Ausarbeitung.*.blg
	$(RM) Ausarbeitung.*.log
	$(RM) Ausarbeitung.*.nav
	$(RM) Ausarbeitung.*.out
	$(RM) Ausarbeitung.*.snm
	$(RM) Ausarbeitung.*.toc
	$(RM) Ausarbeitung.*.lof
	$(RM) Ausarbeitung.*.lot
	$(RM) Ausarbeitung.*.tdo

clean-all: clean
	$(RM) $(PDF_FILES)
	$(RM) handout.$(PDF_FILES)
	$(RM) presentation.$(PDF_FILES)
	$(RM) Ausarbeitung.$(PDF_FILES)

dist-clean: clean-all

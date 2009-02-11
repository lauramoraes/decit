CC = gcc
CFLAGS = -Wall -c

LD = gcc
LFLAGS = -Wall -o

LIBCGIDIR = libs/
LIBCGIFLAGS = -L$(LIBCGIDIR) -lcgi

LIBXMLFLAGS = `xml2-config --cflags`
LIBXMLLIBS  = `xml2-config --libs`


CGIBIN = ../../public_html/decit/cgi-bin/

ADDPATIENTOBJS = addPatient.o
SEARCHPATIENTOBJS = searchPatient.o
BACKUPOBJS = backup.o
STROBJS = testeStr.o
LOGIN_OBJS = functions.o login.o

HTML_PRINCIPAL_OBJS = principal.o
HTML_BUSCA_OBJS = busca.o
HTML_FORMULARIO_OBJS = formulario.o
HTML_EXIBIR_PACIENTES_OBJS = exibirPacientes.o
HTML_EXIBIR_RECUSA_OJBS = exibirRecusa.o
HTML_IMPRIMIR_OBJS = imprimir.o
HTML_REMOVER_OBJS = remover.o
HTML_REMOVERXML_OBJS = removerXML.o
HTML_EDITAR_OBJS = editar.o
HTML_DOEDIT_OBJS = ntbFunctions.o doEdit.o

EXECSCGI =  addPatient.cgi searchPatient.cgi backup.cgi principal.cgi login.cgi busca.cgi formulario.cgi exibirPacientes.cgi exibirRecusa.cgi imprimir.cgi remover.cgi editar.cgi removerXML.cgi doEdit.cgi
EXECSC = addPatient searchPatient backup

.c.o:
	$(CC) $(CFLAGS) $< $(LIBXMLFLAGS)

all: $(EXECSCGI) clean final

addPatient.cgi: $(ADDPATIENTOBJS)
	$(LD) $(LFLAGS) $@ $(ADDPATIENTOBJS)
	mv $@ $(CGIBIN)

backup.cgi: $(BACKUPOBJS)
	$(LD) $(LFLAGS) $@ $(BACKUPOBJS)
	mv $@ $(CGIBIN)

searchPatient.cgi: $(SEARCHPATIENTOBJS)
	$(LD) $(LFLAGS) $@ $(SEARCHPATIENTOBJS)
	mv $@ $(CGIBIN)

principal.cgi: $(HTML_PRINCIPAL_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_PRINCIPAL_OBJS) $(LIBCGIFLAGS)
	mv $@ $(CGIBIN)

login.cgi: $(LOGIN_OBJS)
	$(LD) $(LFLAGS) $@ $(LOGIN_OBJS) $(LIBCGIFLAGS)
	mv $@ $(CGIBIN)

busca.cgi: $(HTML_BUSCA_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_BUSCA_OBJS) $(LIBCGIFLAGS)
	mv $@ $(CGIBIN)

formulario.cgi: $(HTML_FORMULARIO_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_FORMULARIO_OBJS) $(LIBCGIFLAGS)
	mv $@ $(CGIBIN)

exibirPacientes.cgi: $(HTML_EXIBIR_PACIENTES_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_EXIBIR_PACIENTES_OBJS) $(LIBCGIFLAGS)
	mv $@ $(CGIBIN)

exibirRecusa.cgi: $(HTML_EXIBIR_RECUSA_OJBS)
	$(LD) $(LFLAGS) $@ $(HTML_EXIBIR_RECUSA_OJBS) $(LIBCGIFLAGS)
	mv $@ $(CGIBIN)

imprimir.cgi: $(HTML_IMPRIMIR_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_IMPRIMIR_OBJS) $(LIBCGIFLAGS)
	mv $@ $(CGIBIN)

remover.cgi: $(HTML_REMOVER_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_REMOVER_OBJS) $(LIBCGIFLAGS)
	mv $@ $(CGIBIN)
	
removerXML.cgi: $(HTML_REMOVERXML_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_REMOVERXML_OBJS) $(LIBXMLLIBS) $(LIBCGIFLAGS)
	mv $@ $(CGIBIN)

editar.cgi: $(HTML_EDITAR_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_EDITAR_OBJS) $(LIBXMLLIBS) $(LIBCGIFLAGS)
	mv $@ $(CGIBIN)
	
doEdit.cgi: $(HTML_DOEDIT_OBJS)
	$(LD) $(LFLAGS) $@ $(HTML_DOEDIT_OBJS) $(LIBXMLLIBS) $(LIBCGIFLAGS)
	mv $@ $(CGIBIN)
	
final:
	@echo 
	@echo All the .cgi files are compiled! Good luck!
	@echo 


executaveis: $(EXECSC)

addPatient: $(ADDPATIENTOBJS)
	$(LD) $(LFLAGS) $@ $(ADDPATIENTOBJS)

searchPatient: $(SEARCHPATIENTOBJS)
	$(LD) $(LFLAGS) $@ $(SEARCHPATIENTOBJS)


backup: $(BACKUPOBJS)
	$(LD) $(LFLAGS) $@ $(BACKUPOBJS)

str: $(STROBJS)
	$(LD) $(LFLAGS) $@ $(STROBJS)


	@echo
	@echo All the .c files are compiled! Good luck!
	@echo 

clean: 
	rm -f *.o

	@echo
	@echo All the .o files were erased!
	@echo 

cleanAll:
	rm -f *.o $(CGIBIN)/*.cgi

	@echo
	@echo All the .cgi and .o files were erased!
	@echo 

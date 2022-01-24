DIR = `basename $(CURDIR)`

# Rdzenie nazw plikow
ZAD1 = main
ZAD2 = poly_m
ZAD3 = poly_test

# Programy wykonawcze
EXEC1 = $(ZAD1).exe


# Pliki typu object
OBJZAD1 = $(ZAD1).o
OBJZAD2 = $(ZAD2).o
OBJZAD3 = $(ZAD3).o

# Pliki nagłówkowe
HEAD1 = $(ZAD2).h
HEAD2 = $(ZAD3).h
HEADS = $(HEAD1) $(HEAD2)

# Opcje kompilatora i linkera
CFLAGS = -Wall -std=c99 -pedantic

# Kompilator
CO = g++
LD = $(CO)

# Reguly zaleznosci
%.o: %.c %.h
	$(CO) $(CFLAGS) -c $<
%.o: %.c
	$(CO) $(CFLAGS) -c $<
	 
.PHONY: all
all: clean $(EXEC1)

# Tworzenie plikow wykonywalnych
$(EXEC1): $(OBJZAD1) $(OBJZAD2) $(OBJZAD3)
	@$(CO) $(CFLAGS) $^ -o $@

#Sekcja uruchamiania pojedynczych plikow wykonywalnych	
.PHONY: run
run: clean $(EXEC1)
	@echo Uruchamiam program projektu
	@./$(EXEC1)

#Usuniecie wszystkich plikow wykonywalnych i typu object
.PHONY: clean
clean:
	@echo "Czyszczenie plikow poprzedniej kompilacji."
	@rm -f *.o *.a *.so *.exe;


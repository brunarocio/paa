# GNU Makefile
# Revisão: nov/2019
# Projeto: CryptoRSA

CC = gcc
CCFLAGS = #-Wall -O3 
LDFLAGS = -lm -lstdc++
TARGET = cryptoRSA help

all: $(TARGET)

%.o: %.c
	$(CC) $(CCFLAGS) -c $<

%: %.o
	$(CC) $(LDFLAGS) $^ -o $@

cryptoRSA: main_crypto.cpp encrypt.o decrypt.o tools.o
			$(CC) $(CCFLAGS) encrypt.o decrypt.o tools.o main_crypto.cpp -o $@ $(LDFLAGS)


help:
	@echo
	@echo
	@echo "####### Exemplo de Execução #######"
	@echo "./cryptoRSA <parametro c = criptografar, d = descriptografar> <arquivo a criptografar ou descriptografar>"

clean:
	rm -f *.o *~ $(TARGET)

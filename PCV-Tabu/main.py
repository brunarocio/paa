#Dados de entrada:
#Função de avaliação
#lista Tabu
#Soluções vizinhas
#Definir critério de parada
#1-Definir lista inicial tabu e outros parametros
maxIteracoes = 10 #definir tempo?
tamanhoLista = 3
listaTabu = [tamanhoLista]
melhorSolucao = []
#Critério de aspiração (burlar lista)
vizinhosAvaliados = 3
#valorFuncaoAvalicao
matrizBusca = []
linhaBusca = []
#novo
import random
#definir quantidade de cidades
qtdeCidades = 5
#criar uma solução inicial aleatória
for i in range(0, qtdeCidades): 
	cidade = random.randrange(2) # gera números de 0 (inclusive) a 1 (inclusive)
	melhorSolucao.append(cidade) # adiciona o bit na lista

print(melhorSolucao)
#print('Solução inicial: {0}, Avaliação: {1}'.format(melhor_solucao, obter_avaliacao(melhor_solucao, mochila, capacidade_maxima)))

#2-Efetuar perturbações e avalia
def main():
    #3-Encongrar a melhor solução daquela vizinhança
    #4-Atualziar dados
    print('Teste')

def obterDistancia(origem,destino):
    return 


main()
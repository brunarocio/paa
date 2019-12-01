import random

#lista de caminhos Tabu
listaTabu = []
#definicao da matriz de cidades
# Jlle | Ara | Jgua | Fpol | Ctba
matrizDistancias = [[0,40,55,190,130],
[45,0,20,160,140],
[50,30,0,150,145],
[185,160,150,0,300],
[120,135,140,312,0]]
#Qtde de cidades
cidades = len(matrizDistancias)
maxIteracoes = cidades/2
maxVizinhos = cidades/2
melhorSolucao = []


def main():
    #1-criar solucao inicial
    #testes distancias
    #print('Distancias ',matrizDistancias[0][1])
    melhorSolucao = definirSolucao0(5)
    print('Solucao 0: ',melhorSolucao)
    distanciaSolucao = calcularFuncaoObjetiva(melhorSolucao)
    print('Para esta solução, o tamanho da rota é ',distanciaSolucao)
    return 1

def definirSolucao0(qtde):
    solucao = []
    while len(solucao)!=qtde:
        s = random.randint(0,qtde-1)
        if s not in solucao:
            solucao.append(s)
    return solucao

def calcularFuncaoObjetiva(solucao):
    distanciaTotal = 0
    for i in range (len(solucao)):
        #print('Adicionado...',solucao[i])
        
        if (i<(len(solucao)-1)):
            #print('Origem -> destino,i',solucao[i],'->',solucao[i+1],i)
            distanciaTotal += matrizDistancias[solucao[i]][solucao[i+1]]
            #print('Total já acumulado: ',distanciaTotal)
        else:
            distanciaTotal += matrizDistancias[solucao[i]][solucao[0]]
            #print('Total já acumulado: ',distanciaTotal)

    return distanciaTotal

def obterDistancia(origem,destino):
    origem-=1
    destino-=1
    return matrizDistancias[origem][destino]

def gerarVizinhanca(melhorSolucao,maxVizinhos):
    vizinhos = []
    pos = 0
    for i in range(0, maxVizinhos):
        vizinho = []
        for j in range(0, len(melhorSolucao)):
            if  j == pos:
                if melhorSolucao[j] == 0:
                    vizinho.append(1)
                else:
                    vizinho.append(0)
            else:
                vizinho.append(melhorSolucao[j])
        vizinhos.append(vizinho)
        pos += 1
        return vizinhos

main()
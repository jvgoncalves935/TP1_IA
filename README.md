TP1

João Vitor, Millas, Paulo, Welton

Para compilar: make
Para executar: ./tp1

Implementamos três buscas: Aprofundamento Iterativo (versão iterativa e recursiva) e Busca Bi-Direcional.
A saída mostra o caminho, um estado por linha. Cada estado é representado da seguinte maneira:
	[ME,CE] - [MD,CD], onde ME representa a quantidade de Missionários do lado Esquerdo, CD representa a quantidade de Canibais do lado Direito.
Além disso, um símbolo no meio (< ou >) indica o lado em que a canoa está. Se o símbolo > estiver do lado esquerdo, então a canoa está no lado esquerdo e irá para o direito.
Analogamente, se o símbolo < estiver do lado direito, então a cano está no lado direito e irá para o lado esquerdo.

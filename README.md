# ProjetoSO

O programa aborda a condição de corrida utilizando a biblioteca pthread no ambiente de um caixa de supermercado.
O programa foi realizado no Fedora 25 utilizando o terminal do próprio sistema.
Passo para serem seguidos:
•	Baixar o arquivo: projeto_so.c;
• Para abrir use o comando nano projeto_so.c;
•	Compilar o programa: gcc projeto_so.c -o projeto_so.bin –lpthread;
•	Executar: ./projeto_so.bin.
O resultado será que todos os clientes chegarão juntos, mas cada um será atendido um de cada vez, quem fará a organização de quem será atendido será a pthread, se o caixa estiver livre entra um cliente ao qual será atendido e fecha o semáforo, depois de ser atendido o caixa e o semáforo são liberados para que outro cliente possa ser atendido, caso não tenha clientes na fila a pessoa no caixa olha o whatsapp.

Aline Sayuri Hashimura
Igor Gomes Sarmento
Felipe Matheus de Siqueira Jesus

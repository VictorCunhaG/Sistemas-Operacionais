								Projeto 02


Grupo:

	Nome: João Pedro Rodrigues Alves		- TIA: 42083605

	Nome: Pedro Henrique Carvalho 			- TIA: 41910974

	Nome: Victor Cunha Leite Goulart de Araujo	- TIA: 42031729



Output do Código

![execucao](https://i.imgur.com/pbojQHH.png)
	

	1. A conta to pode receber mais de uma transferência simultânea;

	2. A conta from pode enviar mais de uma transferência simultânea;
    
![pidwait](https://i.imgur.com/3BvXSpM.png)
	
     Com essa maneira de criar as threads e esperar que todas elas tenham feito
     o seu trabalho para criar a proxima nós garantimos essas duas condições pois os processos 
     chegam ao mesmo tempo, mas serão processados de acordo com a pilha.
    

	3. A conta from não pode enviar dinheiro se não tiver mais saldo;
    
![ifmaiorigualvalor](https://i.imgur.com/meUmlez.png)

     Aqui temos a condição que não permite a conta enviar se tiver menos dinheiro do que o valor que será transferido.

	4. A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode
	receber e a conta que recebia pode enviar;
    
![from no lugar do to](https://i.imgur.com/LjDA4Vj.png)

    Vemos que mesmo mudando a posição do from e do to temos o mesmo resultado, 
    as contas continuam fazendo oq deveriam fazer

	5. Poderão ser realizadas até 100 transações simultâneas de transferência.
	
![100threads](https://i.imgur.com/FhorKoa.png)

    Aqui podemos verificar que foram criadas 100 threads para executar o processo.
    
    
	
	OBS: O código foi executado através do Repl.it usando o GCC, se necessario executar por lá o código.
	
	

	Bibliografia:
	https://www.baeldung.com/cs/race-conditions#:~:text=To%20avoid%20race%20conditions%2C%20any,exclusive%20parts%20of%20the%20program.
	https://stackoverflow.com/questions/34524/what-is-a-mutex
    https://pubs.opengroup.org/onlinepubs/7908799/xsh/semaphore.h.html
	https://stackoverflow.com/questions/20596922/how-to-wait-for-threads-to-finish-their-work-where-threads-created-by-clone-in

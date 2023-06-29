#include <iostream>
#include <locale.h>
#include <string.h>
using namespace std;
//struct
struct cliente
{
	char nome[50]; //guarda o nome do cliente
	double numero; //guarda o n�mero de telefone do cliente
	int idade; //guarda a idade do cliente
	int tipo; //guarda o tipo de plano do cliente
	int plano; //guarda o plano do cliente
	int gigas; //guarda as gigas adicionais usadas pelo cliente
	int adicionais; //guarda o pre�o dos adicionais
	double valor; //guarda o valor da fatura do cliente
} dados[200];

void prepago (int &plano, double &valor); //fun��o que calcula o valor do plano pr�-pago
void pospago (int &plano, double &valor); //fun��o que calcula o valor do plano p�s-pago
void trocaplano (int &tipo, int &plano, double &valor); //fun��o que troca o plano
double adicionais (int &tipo, int &plano); //fun��o que calcula o pre�o dos adicionais

int main ()
{
    setlocale(LC_ALL,"Portuguese");
    int opcao, indice = 0, fim = 0,i; //contadores
    int quantpre = 0, quantpos = 0; //contadores
    double numero_cliente, encontrado = 0; //auxiliares
    cout << "--- Sistema de Bilhetagem ---\n" << endl;
    do
    {
        cout << endl;
        cout << "Selecione a op��o desejada" << endl;
        cout << "(1) Cadastrar um cliente" << endl;
        cout << "(2) Mostrar dados de um cliente" << endl;
        cout << "(3) Lista de clientes (pr�-pago)" << endl;
        cout << "(4) Lista de clientes (p�s-pago)" << endl;
        cout << "(5) Troca de plano" << endl;
        cout << "(6) Adicionar benef�cios" << endl;
        cout << "(0) Sair" << endl;
        cout << "Op��o: ";
        cin >> opcao; //guarda a op��o selecionada
        
        //op��es do programa
        
        //cadastro do cliente
        if (opcao == 1)
        {
          cout << endl;
          cout << " --- CADASTRO DE CLIENTE --- " << endl << endl;
          cout << "Digite o nome do cliente (digite sair para finalizar): ";
        	cin.ignore();
        	cin.getline(dados[indice].nome,50); //recebe o nome do cliente
        	while(strcmp(dados[indice].nome,"sair") != 0) //enquanto o nome do cliente for diferente de "sair"
        	{
        	    cout << "Digite o n�mero de telefone do cliente: ";
        	    cin >> dados[indice].numero; //recebe o telefone do cliente
        	    do
        	    {
        	        cout << "Digite a idade do cliente: ";
        	        cin >> dados[indice].idade; //recebe a idade do cliente
        	        if (dados[indice].idade < 18)
        	        {
        	            cout << "Apenas maiores de idade podem ser cadastrados" << endl;
        	        }
        	    } while (dados[indice].idade < 18);
							//o loop ocorre caso a idade for menor que 18
        	    cout << "Digite o tipo de plano:" << endl;
        	    do
        	    {
	        		    cout << "1 - Pr�-pago" << endl;
        	        cout << "2 - P�s-pago" << endl;
        	        cout << "Op��o: ";
        	        cin >> dados[indice].tipo; //recebe o tipo de plano do cliente
        	        if (dados[indice].tipo < 1 || dados[indice].tipo > 2)
        	        {
        	            cout << "Op��o inv�lida" << endl;
        	        }
        	    } while (dados[indice].tipo < 1 || dados[indice].tipo > 2);
							//o loop ocorre caso o n�mero seja diferente de 1 ou 2
        	    cout << "Digite o plano do cliente" << endl;
        	    if (dados[indice].tipo == 1) //se o plano for do tipo pr�-pago
        	    {
        	        quantpre++; //quantidade de pessoas com plano pr�-pago
        	        do
        	        {
        	            cout << "(1) 15 GB" << endl;
        	            cout << "(2) 30 GB" << endl;
        	            cout << "Op��o: ";
        	            cin >> dados[indice].plano; //recebe o plano do cliente
        	            if (dados[indice].plano < 1 || dados[indice].plano > 2)
        	            {
        	                cout << "Op��o inv�lida" << endl;
        	            }
        	        } while (dados[indice].plano < 1 || dados[indice].plano > 2);
									//o loop ocorre caso o plano seja diferente de 1 ou 2
                  prepago(dados[indice].plano,dados[indice].valor);
									//entra na fun��o que calcula o pre�o do plano
        	    }
        	    else if (dados[indice].tipo == 2) //se o plano for do tipo p�s-pago
                {
                    quantpos++; //quantidade de pessoas com plano p�s-pago
                    do
	        	        {    
                      cout << "(1) 50 GB" << endl;
        	            cout << "(2) 80 GB" << endl;
        	            cout << "(3) 220 GB" << endl;
        	            cout << "Op��o: ";
        	            cin >> dados[indice].plano; //recebe o plano do cliente
        	            if (dados[indice].plano < 1 || dados[indice].plano > 3)
        	            {
        	                cout << "Op��o inv�lida" << endl;
        	            }
        	        } while (dados[indice].plano < 1 || dados[indice].plano > 3);
									//o loop ocorre caso o plano seja diferente de 1 ou 3
        	        pospago(dados[indice].plano,dados[indice].valor);
		        	    //entra na fun��o que calcula o pre�o do plano
        	    }
        	    cout << "Gigas adicionais usados pelo cliente: ";
        	    cin >> dados[indice].gigas; //recebe a quantidade de gigas adicionais
        	    cout << endl;
        	    cin.ignore();
        	    indice++; //incrementa o �ndice
        	    cout << "Digite o nome do cliente (digite sair para finalizar): ";
	    		    cin.getline(dados[indice].nome,50); //recebe o nome do cliente
	        }
        }
        
        //dados de um cliente espec�fico
        else if (opcao == 2)
        {
            cout << endl;
            cout << " --- DADOS DO CLIENTE --- " << endl << endl;
            if (indice == 0) //caso nenhum cliente tenha sido cadastrado
            {
            	cout << "Nenhum cliente cadastrado" << endl;
            }
            else //caso pelo menos um cliente tenha sido cadastrado
            {
            	cout << "Digite o n�mero de telefone do cliente: ";
            	cin >> numero_cliente; //auxiliar recebe o n�mero do cliente
            	for (i = 0; i < indice; i++) //passa por todos os clientes cadastrados
            	{
            		if (dados[i].numero == numero_cliente) //se o n�mero da auxiliar for igual ao
								//de algum cliente
            		{
            			encontrado = 1; //mostra que o cliente foi encontrado
            			//mostra os dados do cliente
									cout << "Dados do cliente" << endl;
            			cout << "Nome: " << dados[i].nome << endl;
            			cout << "Telefone: " << dados[i].numero << endl;
            			cout << "Idade: " << dados[i].idade << endl;
            			cout << "Tipo de plano: ";
            			if (dados[i].tipo == 1) //se for o prepago
            			{
            				cout << "Pr�-pago, plano ";
            				if (dados[i].plano == 1) //se for o plano 1
            				{
            					cout << "15 GB" << endl;
            				}
            				else //se for o plano 2
            				{
            					cout << "30 GB" << endl;
            				}
            				cout << "Valor � pagar: " << dados[i].valor + dados[i].adicionais + (dados[i].gigas * 2.5) << endl;
										//2.5 � o valor de cada gb adicional
            			}
            			else if (dados[i].tipo == 2) //se for pos pago
            			{
            				cout << "P�s-pago, plano ";
            				if (dados[i].plano == 1) //se for o plano 1
            				{
            					cout << "50 GB" << endl;
            				}
            				else if (dados[i].plano == 1)  //se for o plano 2
            				{
            					cout << "80 GB" << endl;
            				}
            				else //se for o plano 3
            				{
            					cout << "220 GB" << endl;
            				}
            				cout << "Valor � pagar: R$" << dados[i].valor + dados[i].adicionais + (dados[i].gigas * 2.5) << endl;
            			}
            		}
            	}
            	if (encontrado == 0) //caso o cliente n�o tenha sido encontrado
            	{
            		cout << "Cliente n�o encontrado" << endl;
            	}
            }
        }
        
        //lista de clientes prepago
        else if (opcao == 3)
        {
            cout << endl;
            cout << " --- LISTA (pr�-pago) --- " << endl << endl;
            if (indice == 0) //caso nenhum cliente tenha sido cadastrado
            {
            	cout << "Nenhum cliente cadastrado" << endl;
            }
            else if (quantpre == 0) //caso n�o houver nenhum cliente do tipo pr�-pago
						//mas houver clientes cadastrados
            {
                cout << "Nenhum cliente cadastrado nesta categoria" << endl;
            }
            else //caso tenha clientes do tipo pr�-pago
            {
            	for (i = 0; i < indice; i++)
            	{
            		if (dados[i].tipo == 1) //se for pr�-pago
            		{
            			cout << "Cliente" << endl;
            			cout << "Nome: " << dados[i].nome << endl;
            			cout << "Telefone: " << dados[i].numero << endl;
            			cout << "Idade: " << dados[i].idade << endl;
            			cout << "Plano: ";
            			if (dados[i].plano == 1) //se for o plano 1
            			{
            				cout << "15 GB" << endl;
            			}
            			else //se for o plano 2
            			{
            			    cout << "30 GB" << endl;
            			}
            			cout << "Valor � pagar: R$" << dados[i].valor + dados[i].adicionais + (dados[i].gigas * 2.5) << endl;
            		}
            	}
            }
        }
        
        //lista de clientes pospago
        else if (opcao == 4)
        {
            cout << endl;
            cout << " --- LISTA (p�s-pago) --- " << endl << endl;
            if (indice == 0) //caso nenhum cliente tenha sido cadastrado
            {
            	cout << "Nenhum cliente cadastrado" << endl;
            }
            else if (quantpos == 0) //caso n�o houver nenhum cliente do tipo p�s-pago
						//mas houver clientes cadastrados
            {
                cout << "Nenhum cliente cadastrado nesta categoria" << endl;
            }
            else //caso tenha clientes p�s-pago
            {
            	for (i = 0; i < indice; i++)
            	{
            		if (dados[i].tipo == 2) //se for p�s-pago
            		{
            			cout << "Cliente" << endl;
            			cout << "Nome: " << dados[i].nome << endl;
            			cout << "Telefone: " << dados[i].numero << endl;
            			cout << "Idade: " << dados[i].idade << endl;
            			cout << "Plano: ";
            			if (dados[i].plano == 1) //se for o plano 1
            			{
            				cout << "50 GB" << endl;
            			}
            			else if (dados[i].plano == 2) //se for o plano 2
            			{
            			    cout << "80 GB" << endl;
            			}
            			else //se for o plano 3
            			{
            			    cout << "220 GB" << endl;
            			}
            			cout << "Valor � pagar: R$" << dados[i].valor + dados[i].adicionais + (dados[i].gigas * 2.5) << endl;
            		}
            	}
            }
        }
        
        //troca de plano
        else if (opcao == 5)
        {
            cout << endl;
            cout << " --- TROCA DE PLANO --- " << endl << endl;
            if (indice == 0) //caso nenhum cliente tenha sido cadastrado
            {
            	cout << "Nenhum cliente cadastrado" << endl;
            }
            else //caso algum cliente tenha sido cadastrado
            {
            	cout << "Digite o n�mero de telefone do cliente: ";
            	cin >> numero_cliente; //guarda o numero do cliente para verifica��o
            	for (i = 0; i < indice; i++) //passa por todos os clientes
            	{
            		if (numero_cliente == dados[i].numero)
            		{
            			encontrado = 1; //mostra que o cliente for encontrado
            			trocaplano(dados[i].tipo,dados[i].plano,dados[i].valor);
									//entra na fun��o que troca o plano do cliente
            		}
            	}
            	if (encontrado == 0) //caso o cliente n�o tenha sido encontrado
            	{
            		cout << "Cliente n�o encontrado" << endl;
            	} 
            }
        }
        
        //adicionais
        else if (opcao == 6)
        {
            cout << endl;
            cout << " --- INCLUS�O DE ADICIONAIS --- " << endl << endl;
            if (indice == 0) //caso nenhum cliente tenha sido cadastrado
            {
            	cout << "Nenhum cliente cadastrado" << endl;
            }
            else //caso algum cliente tenha sido cadastrado
            {
                
              cout << "Digite o n�mero de telefone do cliente: ";
            	cin >> numero_cliente; //guarda o numero do cliente para verifica��o
            	for (i = 0; i < indice; i++) //passa por todos os clientes
            	{
            		if (numero_cliente == dados[i].numero)
            		{
            			encontrado = 1; //mostra que o cliente foi encontrado
            			cout << "Lista de adicionais" << endl;
            			dados[i].adicionais = adicionais(dados[i].tipo,dados[i].plano);
            		}
            	}
            	if (encontrado == 0) //caso o cliente n�o tenha sido encontrado
            	{
            		cout << "Cliente n�o encontrado" << endl;
            	}
            }
        }
        
				//finalizar o programa
        else if (opcao == 0)
        {
            cout << endl;
            fim = 1; //contador se torna 1
            cout << "Obrigado por utilizar o programa!" << endl;
        }
        
        else //caso a op��o n�o esteja listada
        {
            cout << "Op��o inv�lida" << endl;
        }
				encontrado = 0; //zera o auxiliar
    } while (fim != 1);

	return 0;
}

void prepago (int &plano, double &valor) //calcula o valor do plano pr�-pago
{
	if (plano == 1) //se o plano for o de 15 gb
	{
		valor = 39.99;
	}
	else //se o plano for o de 30 gb
	{
		valor = 69.99;
	}
}

void pospago (int &plano, double &valor) //calcula o valor do plano p�s-pago
{
	if (plano == 1) //se o plano for o de 50 gb
	{
		valor = 119,99;
	}
	else if (plano == 2) //se o plano for o de 80 gb
	{
		valor = 179.99;
	}
	else //se o plano for o de 220 gb
	{
		valor = 399.99;
	}
}

void trocaplano (int &tipo, int &plano, double &valor)
{
  int opcao,novo;
  //op��o guarda se quer ou n�o trocar de plano
  //novo guarda o novo plano do cliente
	cout << " --- Troca de plano ---" << endl;
	//caso o plano seja pr�-pago
	if (tipo == 1)
	{
		cout << "Deseja trocar o tipo de plano?" << endl;
		cout << "Tipo atual: pr�-pago" << endl;
		cout << "1 para sim, 2 para n�o" << endl;
		cout << "Op��o: ";
		do
		{
			cin >> opcao;
			if (opcao < 1 || opcao > 2)
			{
				cout << "Op��o inv�lida, por favor, tente novamente" << endl;
				cout << "Op��o: ";
			}
		} while (opcao < 1 || opcao > 2);
		//o loop ocorre se a op��o n�o for 1 ou 2
		if (opcao == 1)
		{
		    tipo = 2; //muda para o p�s pago
    	  cout << "Selecione o novo plano do cliente" << endl;
    		cout << "(1) Plano 50 GB - R$119,99" << endl;
    		cout << "(2) Plano 80 GB - R$169,99" << endl;
    		cout << "(3) Plano 220 GB - R$399,99" << endl;
    		cout << "Op��o: ";
			do
			{
    			cin >> novo;
    			if (novo < 1 || novo > 3)
				{
					cout << "Op��o inv�lida, por favor, tente novamente" << endl;
					cout << "Op��o: ";
				}
			} while (novo < 1 || novo > 3);
			//o loop ocorre se a op��o n�o for 1 ou 3
			if (novo == 1)
			{
			  plano = 1;
				valor = 119.99;
			}
			else if (novo = 2)
			{
			  plano = 2;
				valor = 169.99;
			}
			else
			{
			  plano = 3;
				valor = 399.99;
			}
		}
		else
		{
			//continua pr�pago
			cout << "Selecione o novo plano do cliente" << endl;
			cout << "(1) Plano 15 GB - R$39,99" << endl;
			cout << "(2) Plano 30 GB - R$69,99" << endl;
			cout << "Op��o: ";
			do
			{
				cin >> novo;
				if (novo < 1 || novo > 2)
				{
					cout << "Op��o inv�lida, por favor, tente novamente" << endl;
					cout << "Op��o: ";
				}
				else if (novo == plano)
				{
				  cout << "O plano escolhido � igual ao do cliente" << endl;
					cout << "Op��o: ";
				}
			} while (novo < 1 || novo > 2 || novo == plano);
			if (novo == 1)
			{
			  plano = 1;
				valor = 39.99;
			}
			else if (novo = 2)
			{
				plano = 2;
				valor = 69.99;
			}
		}
	}
	//caso seja p�s-pago
	else if (tipo == 2)
	{
		cout << "Deseja trocar o tipo de plano?" << endl;
		cout << "Tipo atual: p�s-pago" << endl;
		cout << "1 para sim, 2 para n�o" << endl;
		cout << "Op��o: ";
		do
		{
		    cin >> opcao;
		    if (opcao < 1 || opcao > 2)
			{
				cout << "Op��o inv�lida, por favor, tente novamente" << endl;
				cout << "Op��o: ";
			}
		} while (opcao < 1 || opcao > 2);
		if (opcao == 1)
		{
			tipo = 1; //muda para o pr� pago
			cout << "Selecione o novo plano do cliente" << endl;
			cout << "(1) Plano 15 GB - R$39,99" << endl;
			cout << "(2) Plano 30 GB - R$69,99" << endl;
			cout << "Op��o: ";
			do
			{
				cin >> novo;
				if (novo < 1 || novo > 2)
				{
					cout << "Op��o inv�lida, por favor, tente novamente" << endl;
					cout << "Op��o: ";
				}
				else if (novo == plano)
				{
				    cout << "O plano escolhido � igual ao do cliente" << endl;
					cout << "Op��o: ";
				}
			} while (novo < 1 || novo > 2 || novo == plano);
			if (novo == 1)
			{
			    plano = 1;
				valor = 39.99;
			}
			else if (novo = 2)
			{
			    plano = 2;
				valor = 69.99;
			}
		}
		else if (opcao == 2)
		{
			//continua p�spago
			cout << "Selecione o novo plano do cliente" << endl;
			cout << "(1) Plano 50 GB - R$ 119,99" << endl;
			cout << "(2) Plano 80 GB - R$ 169,99" << endl;
			cout << "(3) Plano 220 GB - R$ 399,99" << endl;
			cout << "Op��o: ";
			do
			{
			    cin >> novo;
				if (novo < 1 || novo > 3)
				{
					cout << "Op��o inv�lida, por favor, tente novamente" << endl;
					cout << "Op��o: ";
				}
			} while (novo < 1 || novo > 3);
			if (novo == 1)
			{
			    plano = 1;
				valor = 119.99;
			}
			else if (novo == 2)
			{
			    plano = 2;
				valor = 169.99;
			}
			else
			{
			    plano = 3;
				valor = 399.99;
			}
		}
	}
}

double adicionais(int &tipo, int &plano)
{
  int a[11], soma = 0, cont = 0, i = 0;
  cout << "Selecione os benef�cios" << endl;
  cout << "1 - Extraplay: 1,00        " << "\t" << "2 - Discovery+: 2,00        " << "\t" << "3 - Netflix: 3,00" << endl;
	cout << "4 - NOW: 4,00              " << "\t" << "5 - CONMEBOL TV: 5,00       " << "\t" << "6 - Pluto TV: 6,00" << endl;
	cout << "7 - Twitter ilimitado: 7,00" << "\t" << "8 - Facebook ilimitado: 7,00" << "\t" << "9 - Instagram ilimitado: 7,00" << endl;
	cout << "10 - Waze ilimitado: 7,00" << endl;
	cout << "Op��es (utilize espa�o entre cada op��o e digite 0 para finalizar): ";
	do
	{
	    cin >> a[cont]; //vetor que armazena os adicionais escolhidos
	    cont++;
	} while (a[cont-1] != 0); //faz as contas enquanto o valor no vetor n�o for 0
	for (i = 0; i < cont; i++)
	{
			//os ifs de soma se baseiam nas op��es que est�o presentes em cada plano
			//se o adicional j� estiver presente no plano, n�o ser�o cobrados valores adicionais
	    if (tipo == 1)
	    {
	        if (plano == 1)
	        {
	            if (a[i] == 1)
	            {
	                soma = soma + 1;
	            }
	            else if (a[i] == 2)
	            {
	                soma = soma + 2;
	            }
	            if (a[i] == 3)
	            {
	                soma = soma + 3;
	            }
	            else if (a[i] == 4)
	            {
	                soma = soma + 4;
	            }
	            else if (a[i] == 5)
	            {
	                soma = soma + 5;
	            }
	            else if (a[i] == 6)
	            {
	                soma = soma + 6;
	            }
	            else if (a[i] >= 8 && a[i] <= 10)
	            {
	                soma = soma + 7;
	            }
	            else
	            {
	                soma = soma + 0;
	            }
	        }
	        else
	        {
	            soma = soma + 0;
	        }
	    }
	    else
	    {
	        if (plano == 1)
	        {
	            if (a[i] == 1)
	            {
	                soma = soma + 1;
	            }
	            else if (a[i] == 2)
	            {
	                soma = soma + 2;
	            }
	            if (a[i] == 3)
	            {
	                soma = soma + 3;
	            }
	            else if (a[i] == 4)
	            {
	                soma = soma + 4;
	            }
	            else if (a[i] == 5)
	            {
	                soma = soma + 5;
	            }
	            else if (a[i] == 6)
	            {
	                soma = soma + 6;
	            }
	            else if (a[i] >= 7 && a[i] <= 10)
	            {
	                soma = soma + 7;
	            }
	            else
	            {
	                soma = soma + 0;
	            }
	        }
	        else if (plano == 2)
	        {
	            if (a[i] >= 8 && a[i] <= 10)
	            {
	                soma = soma + 7;
	            }
	            else
	            {
	                soma = soma + 0;
	            }
	        }
	        else
	        {
	            soma = soma + 0;
	        }
	    }
	}
	cout << "valor de soma: " << soma << endl;
	return soma;
}
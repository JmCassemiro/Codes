#include <iostream>
#include <locale.h>
#include <string.h>
using namespace std;
//struct
struct cliente
{
	char nome[50]; //guarda o nome do cliente
	double numero; //guarda o número de telefone do cliente
	int idade; //guarda a idade do cliente
	int tipo; //guarda o tipo de plano do cliente
	int plano; //guarda o plano do cliente
	int gigas; //guarda as gigas adicionais usadas pelo cliente
	int adicionais; //guarda o preço dos adicionais
	double valor; //guarda o valor da fatura do cliente
} dados[200];

void prepago (int &plano, double &valor); //função que calcula o valor do plano pré-pago
void pospago (int &plano, double &valor); //função que calcula o valor do plano pós-pago
void trocaplano (int &tipo, int &plano, double &valor); //função que troca o plano
double adicionais (int &tipo, int &plano); //função que calcula o preço dos adicionais

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
        cout << "Selecione a opção desejada" << endl;
        cout << "(1) Cadastrar um cliente" << endl;
        cout << "(2) Mostrar dados de um cliente" << endl;
        cout << "(3) Lista de clientes (pré-pago)" << endl;
        cout << "(4) Lista de clientes (pós-pago)" << endl;
        cout << "(5) Troca de plano" << endl;
        cout << "(6) Adicionar benefícios" << endl;
        cout << "(0) Sair" << endl;
        cout << "Opção: ";
        cin >> opcao; //guarda a opção selecionada
        
        //opções do programa
        
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
        	    cout << "Digite o número de telefone do cliente: ";
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
	        		    cout << "1 - Pré-pago" << endl;
        	        cout << "2 - Pós-pago" << endl;
        	        cout << "Opção: ";
        	        cin >> dados[indice].tipo; //recebe o tipo de plano do cliente
        	        if (dados[indice].tipo < 1 || dados[indice].tipo > 2)
        	        {
        	            cout << "Opção inválida" << endl;
        	        }
        	    } while (dados[indice].tipo < 1 || dados[indice].tipo > 2);
							//o loop ocorre caso o número seja diferente de 1 ou 2
        	    cout << "Digite o plano do cliente" << endl;
        	    if (dados[indice].tipo == 1) //se o plano for do tipo pré-pago
        	    {
        	        quantpre++; //quantidade de pessoas com plano pré-pago
        	        do
        	        {
        	            cout << "(1) 15 GB" << endl;
        	            cout << "(2) 30 GB" << endl;
        	            cout << "Opção: ";
        	            cin >> dados[indice].plano; //recebe o plano do cliente
        	            if (dados[indice].plano < 1 || dados[indice].plano > 2)
        	            {
        	                cout << "Opção inválida" << endl;
        	            }
        	        } while (dados[indice].plano < 1 || dados[indice].plano > 2);
									//o loop ocorre caso o plano seja diferente de 1 ou 2
                  prepago(dados[indice].plano,dados[indice].valor);
									//entra na função que calcula o preço do plano
        	    }
        	    else if (dados[indice].tipo == 2) //se o plano for do tipo pós-pago
                {
                    quantpos++; //quantidade de pessoas com plano pós-pago
                    do
	        	        {    
                      cout << "(1) 50 GB" << endl;
        	            cout << "(2) 80 GB" << endl;
        	            cout << "(3) 220 GB" << endl;
        	            cout << "Opção: ";
        	            cin >> dados[indice].plano; //recebe o plano do cliente
        	            if (dados[indice].plano < 1 || dados[indice].plano > 3)
        	            {
        	                cout << "Opção inválida" << endl;
        	            }
        	        } while (dados[indice].plano < 1 || dados[indice].plano > 3);
									//o loop ocorre caso o plano seja diferente de 1 ou 3
        	        pospago(dados[indice].plano,dados[indice].valor);
		        	    //entra na função que calcula o preço do plano
        	    }
        	    cout << "Gigas adicionais usados pelo cliente: ";
        	    cin >> dados[indice].gigas; //recebe a quantidade de gigas adicionais
        	    cout << endl;
        	    cin.ignore();
        	    indice++; //incrementa o índice
        	    cout << "Digite o nome do cliente (digite sair para finalizar): ";
	    		    cin.getline(dados[indice].nome,50); //recebe o nome do cliente
	        }
        }
        
        //dados de um cliente específico
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
            	cout << "Digite o número de telefone do cliente: ";
            	cin >> numero_cliente; //auxiliar recebe o número do cliente
            	for (i = 0; i < indice; i++) //passa por todos os clientes cadastrados
            	{
            		if (dados[i].numero == numero_cliente) //se o número da auxiliar for igual ao
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
            				cout << "Pré-pago, plano ";
            				if (dados[i].plano == 1) //se for o plano 1
            				{
            					cout << "15 GB" << endl;
            				}
            				else //se for o plano 2
            				{
            					cout << "30 GB" << endl;
            				}
            				cout << "Valor à pagar: " << dados[i].valor + dados[i].adicionais + (dados[i].gigas * 2.5) << endl;
										//2.5 é o valor de cada gb adicional
            			}
            			else if (dados[i].tipo == 2) //se for pos pago
            			{
            				cout << "Pós-pago, plano ";
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
            				cout << "Valor à pagar: R$" << dados[i].valor + dados[i].adicionais + (dados[i].gigas * 2.5) << endl;
            			}
            		}
            	}
            	if (encontrado == 0) //caso o cliente não tenha sido encontrado
            	{
            		cout << "Cliente não encontrado" << endl;
            	}
            }
        }
        
        //lista de clientes prepago
        else if (opcao == 3)
        {
            cout << endl;
            cout << " --- LISTA (pré-pago) --- " << endl << endl;
            if (indice == 0) //caso nenhum cliente tenha sido cadastrado
            {
            	cout << "Nenhum cliente cadastrado" << endl;
            }
            else if (quantpre == 0) //caso não houver nenhum cliente do tipo pré-pago
						//mas houver clientes cadastrados
            {
                cout << "Nenhum cliente cadastrado nesta categoria" << endl;
            }
            else //caso tenha clientes do tipo pré-pago
            {
            	for (i = 0; i < indice; i++)
            	{
            		if (dados[i].tipo == 1) //se for pré-pago
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
            			cout << "Valor à pagar: R$" << dados[i].valor + dados[i].adicionais + (dados[i].gigas * 2.5) << endl;
            		}
            	}
            }
        }
        
        //lista de clientes pospago
        else if (opcao == 4)
        {
            cout << endl;
            cout << " --- LISTA (pós-pago) --- " << endl << endl;
            if (indice == 0) //caso nenhum cliente tenha sido cadastrado
            {
            	cout << "Nenhum cliente cadastrado" << endl;
            }
            else if (quantpos == 0) //caso não houver nenhum cliente do tipo pós-pago
						//mas houver clientes cadastrados
            {
                cout << "Nenhum cliente cadastrado nesta categoria" << endl;
            }
            else //caso tenha clientes pós-pago
            {
            	for (i = 0; i < indice; i++)
            	{
            		if (dados[i].tipo == 2) //se for pós-pago
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
            			cout << "Valor à pagar: R$" << dados[i].valor + dados[i].adicionais + (dados[i].gigas * 2.5) << endl;
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
            	cout << "Digite o número de telefone do cliente: ";
            	cin >> numero_cliente; //guarda o numero do cliente para verificação
            	for (i = 0; i < indice; i++) //passa por todos os clientes
            	{
            		if (numero_cliente == dados[i].numero)
            		{
            			encontrado = 1; //mostra que o cliente for encontrado
            			trocaplano(dados[i].tipo,dados[i].plano,dados[i].valor);
									//entra na função que troca o plano do cliente
            		}
            	}
            	if (encontrado == 0) //caso o cliente não tenha sido encontrado
            	{
            		cout << "Cliente não encontrado" << endl;
            	} 
            }
        }
        
        //adicionais
        else if (opcao == 6)
        {
            cout << endl;
            cout << " --- INCLUSÃO DE ADICIONAIS --- " << endl << endl;
            if (indice == 0) //caso nenhum cliente tenha sido cadastrado
            {
            	cout << "Nenhum cliente cadastrado" << endl;
            }
            else //caso algum cliente tenha sido cadastrado
            {
                
              cout << "Digite o número de telefone do cliente: ";
            	cin >> numero_cliente; //guarda o numero do cliente para verificação
            	for (i = 0; i < indice; i++) //passa por todos os clientes
            	{
            		if (numero_cliente == dados[i].numero)
            		{
            			encontrado = 1; //mostra que o cliente foi encontrado
            			cout << "Lista de adicionais" << endl;
            			dados[i].adicionais = adicionais(dados[i].tipo,dados[i].plano);
            		}
            	}
            	if (encontrado == 0) //caso o cliente não tenha sido encontrado
            	{
            		cout << "Cliente não encontrado" << endl;
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
        
        else //caso a opção não esteja listada
        {
            cout << "Opção inválida" << endl;
        }
				encontrado = 0; //zera o auxiliar
    } while (fim != 1);

	return 0;
}

void prepago (int &plano, double &valor) //calcula o valor do plano pré-pago
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

void pospago (int &plano, double &valor) //calcula o valor do plano pós-pago
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
  //opção guarda se quer ou não trocar de plano
  //novo guarda o novo plano do cliente
	cout << " --- Troca de plano ---" << endl;
	//caso o plano seja pré-pago
	if (tipo == 1)
	{
		cout << "Deseja trocar o tipo de plano?" << endl;
		cout << "Tipo atual: pré-pago" << endl;
		cout << "1 para sim, 2 para não" << endl;
		cout << "Opção: ";
		do
		{
			cin >> opcao;
			if (opcao < 1 || opcao > 2)
			{
				cout << "Opção inválida, por favor, tente novamente" << endl;
				cout << "Opção: ";
			}
		} while (opcao < 1 || opcao > 2);
		//o loop ocorre se a opção não for 1 ou 2
		if (opcao == 1)
		{
		    tipo = 2; //muda para o pós pago
    	  cout << "Selecione o novo plano do cliente" << endl;
    		cout << "(1) Plano 50 GB - R$119,99" << endl;
    		cout << "(2) Plano 80 GB - R$169,99" << endl;
    		cout << "(3) Plano 220 GB - R$399,99" << endl;
    		cout << "Opção: ";
			do
			{
    			cin >> novo;
    			if (novo < 1 || novo > 3)
				{
					cout << "Opção inválida, por favor, tente novamente" << endl;
					cout << "Opção: ";
				}
			} while (novo < 1 || novo > 3);
			//o loop ocorre se a opção não for 1 ou 3
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
			//continua prépago
			cout << "Selecione o novo plano do cliente" << endl;
			cout << "(1) Plano 15 GB - R$39,99" << endl;
			cout << "(2) Plano 30 GB - R$69,99" << endl;
			cout << "Opção: ";
			do
			{
				cin >> novo;
				if (novo < 1 || novo > 2)
				{
					cout << "Opção inválida, por favor, tente novamente" << endl;
					cout << "Opção: ";
				}
				else if (novo == plano)
				{
				  cout << "O plano escolhido é igual ao do cliente" << endl;
					cout << "Opção: ";
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
	//caso seja pós-pago
	else if (tipo == 2)
	{
		cout << "Deseja trocar o tipo de plano?" << endl;
		cout << "Tipo atual: pós-pago" << endl;
		cout << "1 para sim, 2 para não" << endl;
		cout << "Opção: ";
		do
		{
		    cin >> opcao;
		    if (opcao < 1 || opcao > 2)
			{
				cout << "Opção inválida, por favor, tente novamente" << endl;
				cout << "Opção: ";
			}
		} while (opcao < 1 || opcao > 2);
		if (opcao == 1)
		{
			tipo = 1; //muda para o pré pago
			cout << "Selecione o novo plano do cliente" << endl;
			cout << "(1) Plano 15 GB - R$39,99" << endl;
			cout << "(2) Plano 30 GB - R$69,99" << endl;
			cout << "Opção: ";
			do
			{
				cin >> novo;
				if (novo < 1 || novo > 2)
				{
					cout << "Opção inválida, por favor, tente novamente" << endl;
					cout << "Opção: ";
				}
				else if (novo == plano)
				{
				    cout << "O plano escolhido é igual ao do cliente" << endl;
					cout << "Opção: ";
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
			//continua póspago
			cout << "Selecione o novo plano do cliente" << endl;
			cout << "(1) Plano 50 GB - R$ 119,99" << endl;
			cout << "(2) Plano 80 GB - R$ 169,99" << endl;
			cout << "(3) Plano 220 GB - R$ 399,99" << endl;
			cout << "Opção: ";
			do
			{
			    cin >> novo;
				if (novo < 1 || novo > 3)
				{
					cout << "Opção inválida, por favor, tente novamente" << endl;
					cout << "Opção: ";
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
  cout << "Selecione os benefícios" << endl;
  cout << "1 - Extraplay: 1,00        " << "\t" << "2 - Discovery+: 2,00        " << "\t" << "3 - Netflix: 3,00" << endl;
	cout << "4 - NOW: 4,00              " << "\t" << "5 - CONMEBOL TV: 5,00       " << "\t" << "6 - Pluto TV: 6,00" << endl;
	cout << "7 - Twitter ilimitado: 7,00" << "\t" << "8 - Facebook ilimitado: 7,00" << "\t" << "9 - Instagram ilimitado: 7,00" << endl;
	cout << "10 - Waze ilimitado: 7,00" << endl;
	cout << "Opções (utilize espaço entre cada opção e digite 0 para finalizar): ";
	do
	{
	    cin >> a[cont]; //vetor que armazena os adicionais escolhidos
	    cont++;
	} while (a[cont-1] != 0); //faz as contas enquanto o valor no vetor não for 0
	for (i = 0; i < cont; i++)
	{
			//os ifs de soma se baseiam nas opções que estão presentes em cada plano
			//se o adicional já estiver presente no plano, não serão cobrados valores adicionais
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

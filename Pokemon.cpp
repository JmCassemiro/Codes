#include <iostream>
#include <cstring>

struct Pokemon
{
    char name[50]; // nome do Pokémon
    int id;        // número de identificação do Pokémon
    int status;    // 0: vazio, 1: ocupado, 2: removido
};

class Pokedex
{
private:
    int size;     // tamanho da tabela
    Pokemon *table; // tabela hash

    int hashFunction(int id, int i)
    {
        int hash1 = id % size;
        int hash2 = 1 + (id % (size - 1));
        return (hash1 + i * hash2) % size;
    }

public:
    Pokedex(int m)
    {
        size = m;
        table = new Pokemon[size];
        for (int i = 0; i < size; i++)
        {
            table[i].status = 0; // marca todas as posições como vazias
        }
    }

    ~Pokedex()
    {
        delete[] table;
    }

    void insert(const char *name, int id)
    {
        int i = 0;
        int hash = hashFunction(id, i);

        while (table[hash].status == 1)
        {
            i++;
            hash = hashFunction(id, i);
        }

        strncpy(table[hash].name, name, sizeof(table[hash].name));
        table[hash].id = id;
        table[hash].status = 1; // marca a posição como ocupada
    }

    Pokemon* search(int id)
    {
        int i = 0;
        int hash = hashFunction(id, i);

        while (table[hash].status != 0 && table[hash].status != 2)
        {
            if (table[hash].status == 1 && table[hash].id == id)
            {
                return &table[hash]; // retorna o ponteiro para o Pokémon encontrado
            }

            i++;
            hash = hashFunction(id, i);
        }

        return 0; // Pokémon não encontrado
    }

    void remove(int id)
    {
        Pokemon* pokemon = search(id);
        if (pokemon != 0)
        {
            pokemon->status = 2; // marca a posição como removida
        }
    }

    void printPokedex()
    {
        for (int i = 0; i < size; i++)
        {
            if (table[i].status == 1)
            {
                std::cout << "ID: " << table[i].id << " | Name: " << table[i].name << std::endl;
            }
            else
            {
                std::cout << "vazio" << std::endl;
            }
        }
    }

    Pokemon* getTable() // Função para obter o ponteiro table
    {
        return table;
    }
};

int main()
{
    int m;
    std::cout << "Digite o tamanho da Pokedex: ";
    std::cin >> m;

    Pokedex pokedex(m);

    int option;
    while (true)
    {
        std::cout << "\nMenu:\n";
        std::cout << "1 - Inserir Pokemon\n";
        std::cout << "2 - Pesquisar Pokemon\n";
        std::cout << "3 - Remover Pokemon\n";
        std::cout << "4 - Listar Pokedex\n";
        std::cout << "5 - Sair\n";
        std::cout << "Escolha uma opcao: ";
        std::cin >> option;

        if (option == 1)
        {
            char name[50];
            int id;
            std::cout << "Digite o nome do Pokemon: ";
            std::cin.ignore(); // Ignora a quebra de linha pendente no buffer
            std::cin.getline(name, sizeof(name));
            std::cout << "Digite o ID do Pokemon: ";
            std::cin >> id;
            pokedex.insert(name, id);
            std::cout << "Pokemon inserido na Pokedex!\n";
        }
        else if (option == 2)
        {
            int id;
            std::cout << "Digite o ID do Pokemon a ser pesquisado: ";
            std::cin >> id;
            Pokemon* pokemon = pokedex.search(id);
            if (pokemon != 0)
            {
                std::cout << "Pokemon encontrado na posicao " << (pokemon - pokedex.getTable()) << std::endl;
                std::cout << "Nome do Pokemon: " << pokemon->name << std::endl;
            }
            else
            {
                std::cout << "Pokemon nao encontrado" << std::endl;
            }
        }
        else if (option == 3)
        {
            int id;
            std::cout << "Digite o ID do Pokemon a ser removido: ";
            std::cin >> id;
            Pokemon* pokemon = pokedex.search(id);
			pokedex.remove(id);
            std::cout << "Pokemon" << pokemon->name << " removido da Pokedex!\n";
        }
        else if (option == 4)
        {
            std::cout << "\nPokedex:\n";
            pokedex.printPokedex();
        }
        else if (option == 5)
        {
            break;
        }
        else
        {
            std::cout << "Opcao invalida! Tente novamente.\n";
        }
    }

    return 0;
}

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

// Estrutura do funcionário
struct Funcionario {
    int prontuario;
    string nome;
    double salario;
    Funcionario* prox;
};

Funcionario* incluir(Funcionario* lista) {
    Funcionario* novo = new Funcionario();

    cout << "Digite o prontuario: ";
    cin >> novo->prontuario;

    // Verifica duplicidade
    Funcionario* aux = lista;
    while (aux != NULL) {
        if (aux->prontuario == novo->prontuario) {
            cout << "Prontuario ja cadastrado!" << endl;
            delete novo;
            return lista;
        }
        aux = aux->prox;
    }

    cin.ignore(); // limpa o buffer
    cout << "Digite o nome: ";
    getline(cin, novo->nome);

    cout << "Digite o salario: ";
    cin >> novo->salario;

    novo->prox = lista;
    cout << "Funcionario inserido com sucesso!" << endl;
    return novo;
}

Funcionario* excluir(Funcionario* lista) {
    int pront;
    cout << "Digite o prontuario a excluir: ";
    cin >> pront;

    Funcionario* atual = lista;
    Funcionario* anterior = NULL;

    while (atual != NULL && atual->prontuario != pront) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        cout << "Funcionario nao encontrado!" << endl;
        return lista;
    }

    if (anterior == NULL) {
        lista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    delete atual;
    cout << "Funcionario excluido com sucesso!" << endl;
    return lista;
}

void pesquisar(Funcionario* lista) {
    int pront;
    cout << "Digite o prontuario a pesquisar: ";
    cin >> pront;

    Funcionario* aux = lista;
    while (aux != NULL) {
        if (aux->prontuario == pront) {
            cout << "Nome: " << aux->nome << endl;
            cout << "Salario: R$ " << aux->salario << endl;
            return;
        }
        aux = aux->prox;
    }

    cout << "Funcionario nao encontrado!" << endl;
}

void listar(Funcionario* lista) {
    Funcionario* aux = lista;
    double totalSalarios = 0.0;

    if (aux == NULL) {
        cout << "Lista vazia!" << endl;
        return;
    }

    cout << "---------------------------" << endl;
    while (aux != NULL) {
        cout << "Prontuario: " << aux->prontuario << endl;
        cout << "Nome: " << aux->nome << endl;
        cout << "Salario: R$ " << aux->salario << endl;
        cout << "---------------------------" << endl;
        totalSalarios += aux->salario;
        aux = aux->prox;
    }

    cout << "Total de salarios: R$ " << totalSalarios << endl;
}

void liberar(Funcionario* lista) {
    Funcionario* aux;
    while (lista != NULL) {
        aux = lista;
        lista = lista->prox;
        delete aux;
    }
}

int main() {
    Funcionario* lista = NULL;
    int opcao;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "0. Sair" << endl;
        cout << "1. Incluir" << endl;
        cout << "2. Excluir" << endl;
        cout << "3. Pesquisar" << endl;
        cout << "4. Listar" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {
            case 0:
                cout << "Saindo..." << endl;
                break;
            case 1:
                lista = incluir(lista);
                break;
            case 2:
                lista = excluir(lista);
                break;
            case 3:
                pesquisar(lista);
                break;
            case 4:
                listar(lista);
                break;
            default:
                cout << "Opcao invalida!" << endl;
        }

    } while (opcao != 0);

    liberar(lista);
    return 0;
}

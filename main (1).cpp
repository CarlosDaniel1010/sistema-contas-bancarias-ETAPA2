 
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

int main() {

    const int MAX_CONTAS = 100;
    const int MAX_MOVIMENTACOES = 500;

    // Dados das contas
    int numeroConta[MAX_CONTAS];
    string nomeCliente[MAX_CONTAS];
    string cpf[MAX_CONTAS];
    int tipoConta[MAX_CONTAS];
    double saldo[MAX_CONTAS];
    bool contaAtiva[MAX_CONTAS];

    int quantidadeContas = 0;

    // Historico de movimentacoes
    int contaMovimentacao[MAX_MOVIMENTACOES];
    char tipoMovimentacao[MAX_MOVIMENTACOES];
    double valorMovimentacao[MAX_MOVIMENTACOES];

    int quantidadeMovimentacoes = 0;

    int opcao;

    do {

        cout << "\n===== SISTEMA BANCARIO DO CARLOS  =====" << endl;
        cout << "1 - Cadastrar conta" << endl;
        cout << "2 - Listar contas" << endl;
        cout << "3 - Consultar conta" << endl;
        cout << "4 - Depositar" << endl;
        cout << "5 - Sacar" << endl;
        cout << "6 - Transferir" << endl;
        cout << "7 - Extrato" << endl;
        cout << "0 - Sair" << endl;

        cout << "\nEscolha uma opcao: ";
        cin >> opcao;

        switch (opcao) {

            // CADASTRAR CONTA
            case 1: {

                if (quantidadeContas < MAX_CONTAS) {

                    cout << "\nNumero da conta: ";
                    cin >> numeroConta[quantidadeContas];

                    bool existe = false;

                    for (int i = 0; i < quantidadeContas; i++) {
                        if (numeroConta[i] == numeroConta[quantidadeContas]) {
                            existe = true;
                        }
                    }

                    if (existe) {
                        cout << "Essa conta ja existe!" << endl;
                    }
                    else {

                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        cout << "Nome do cliente: ";
                        getline(cin, nomeCliente[quantidadeContas]);

                        cout << "CPF: ";
                        getline(cin, cpf[quantidadeContas]);

                        cout << "Tipo da conta (1 - Corrente / 2 - Poupanca): ";
                        cin >> tipoConta[quantidadeContas];

                        cout << "Saldo inicial: R$ ";
                        cin >> saldo[quantidadeContas];

                        contaAtiva[quantidadeContas] = true;

                        quantidadeContas++;

                        cout << "\nConta cadastrada com sucesso!" << endl;
                    }

                }
                else {
                    cout << "Limite de contas atingido!" << endl;
                }

                break;
            }

            // LISTAR CONTAS
            case 2: {

                if (quantidadeContas == 0) {
                    cout << "\nNenhuma conta cadastrada!" << endl;
                }
                else {

                    cout << "\n===== CONTAS CADASTRADAS =====" << endl;

                    for (int i = 0; i < quantidadeContas; i++) {

                        cout << "\nNumero: " << numeroConta[i] << endl;
                        cout << "Cliente: " << nomeCliente[i] << endl;
                        cout << "CPF: " << cpf[i] << endl;
                        cout << "Tipo: " << tipoConta[i] << endl;
                        cout << "Saldo: R$ " << fixed << setprecision(2) << saldo[i] << endl;

                        if (contaAtiva[i]) {
                            cout << "Situacao: Ativa" << endl;
                        }
                        else {
                            cout << "Situacao: Inativa" << endl;
                        }
                    }
                }

                break;
            }

            // CONSULTAR CONTA
            case 3: {

                int numero;
                int indice = -1;

                cout << "\nDigite o numero da conta: ";
                cin >> numero;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada!" << endl;
                }
                else {

                    cout << "\n===== DADOS DA CONTA =====" << endl;
                    cout << "Numero: " << numeroConta[indice] << endl;
                    cout << "Cliente: " << nomeCliente[indice] << endl;
                    cout << "CPF: " << cpf[indice] << endl;
                    cout << "Tipo: " << tipoConta[indice] << endl;
                    cout << "Saldo: R$ " << fixed << setprecision(2) << saldo[indice] << endl;

                    if (contaAtiva[indice]) {
                        cout << "Situacao: Ativa" << endl;
                    }
                    else {
                        cout << "Situacao: Inativa" << endl;
                    }
                }

                break;
            }

            // DEPOSITO
            case 4: {

                int numero;
                double valor;
                int indice = -1;

                cout << "\nNumero da conta: ";
                cin >> numero;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                    }
                }

                if (indice == -1 || !contaAtiva[indice]) {
                    cout << "Conta nao encontrada ou inativa!" << endl;
                }
                else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Historico de movimentacoes cheio!" << endl;
                }
                else {

                    cout << "Valor do deposito: R$ ";
                    cin >> valor;

                    if (valor > 0) {

                        saldo[indice] = saldo[indice] + valor;

                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;

                        quantidadeMovimentacoes++;

                        cout << "Deposito realizado com sucesso!" << endl;
                    }
                    else {
                        cout << "Valor invalido!" << endl;
                    }
                }

                break;
            }

            // SAQUE
            case 5: {

                int numero;
                double valor;
                int indice = -1;

                cout << "\nNumero da conta: ";
                cin >> numero;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                    }
                }

                if (indice == -1 || !contaAtiva[indice]) {
                    cout << "Conta nao encontrada ou inativa!" << endl;
                }
                else if (quantidadeMovimentacoes >= MAX_MOVIMENTACOES) {
                    cout << "Historico de movimentacoes cheio!" << endl;
                }
                else {

                    cout << "Valor do saque: R$ ";
                    cin >> valor;

                    if (valor <= 0) {
                        cout << "Valor invalido!" << endl;
                    }
                    else if (saldo[indice] < valor) {
                        cout << "Saldo insuficiente!" << endl;
                    }
                    else {

                        saldo[indice] = saldo[indice] - valor;

                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indice];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;

                        quantidadeMovimentacoes++;

                        cout << "Saque realizado com sucesso!" << endl;
                    }
                }

                break;
            }

            // TRANSFERENCIA
            case 6: {

                int origem, destino;
                int indiceOrigem = -1;
                int indiceDestino = -1;
                double valor;

                cout << "\nConta de origem: ";
                cin >> origem;

                cout << "Conta de destino: ";
                cin >> destino;

                for (int i = 0; i < quantidadeContas; i++) {

                    if (numeroConta[i] == origem) {
                        indiceOrigem = i;
                    }

                    if (numeroConta[i] == destino) {
                        indiceDestino = i;
                    }
                }

                if (indiceOrigem == -1 || indiceDestino == -1) {
                    cout << "Uma das contas nao foi encontrada!" << endl;
                }
                else if (!contaAtiva[indiceOrigem] || !contaAtiva[indiceDestino]) {
                    cout << "Uma das contas esta inativa!" << endl;
                }
                else if (indiceOrigem == indiceDestino) {
                    cout << "Nao e possivel transferir para a mesma conta!" << endl;
                }
                else {

                    cout << "Valor da transferencia: R$ ";
                    cin >> valor;

                    if (valor <= 0) {
                        cout << "Valor invalido!" << endl;
                    }
                    else if (saldo[indiceOrigem] < valor) {
                        cout << "Saldo insuficiente!" << endl;
                    }
                    else if (quantidadeMovimentacoes + 2 > MAX_MOVIMENTACOES) {
                        cout << "Nao ha espaco no historico!" << endl;
                    }
                    else {

                        saldo[indiceOrigem] = saldo[indiceOrigem] - valor;
                        saldo[indiceDestino] = saldo[indiceDestino] + valor;

                        // Registro da saida
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceOrigem];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'S';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;

                        quantidadeMovimentacoes++;

                        // Registro da entrada
                        contaMovimentacao[quantidadeMovimentacoes] = numeroConta[indiceDestino];
                        tipoMovimentacao[quantidadeMovimentacoes] = 'D';
                        valorMovimentacao[quantidadeMovimentacoes] = valor;

                        quantidadeMovimentacoes++;

                        cout << "Transferencia realizada com sucesso!" << endl;
                    }
                }

                break;
            }

            // EXTRATO
            case 7: {

                int numero;
                int indice = -1;

                cout << "\nNumero da conta: ";
                cin >> numero;

                for (int i = 0; i < quantidadeContas; i++) {
                    if (numeroConta[i] == numero) {
                        indice = i;
                    }
                }

                if (indice == -1) {
                    cout << "Conta nao encontrada!" << endl;
                }
                else {

                    cout << "\n===== EXTRATO DA CONTA =====" << endl;
                    cout << "Cliente: " << nomeCliente[indice] << endl;
                    cout << "Conta: " << numeroConta[indice] << endl;

                    bool encontrou = false;

                    for (int i = 0; i < quantidadeMovimentacoes; i++) {

                        if (contaMovimentacao[i] == numero) {

                            encontrou = true;

                            if (tipoMovimentacao[i] == 'D') {
                                cout << "Deposito: R$ ";
                            }
                            else if (tipoMovimentacao[i] == 'S') {
                                cout << "Saque: R$ ";
                            }

                            cout << fixed << setprecision(2) << valorMovimentacao[i] << endl;
                        }
                    }

                    if (!encontrou) {
                        cout << "Nenhuma movimentacao encontrada!" << endl;
                    }

                    cout << "Saldo atual: R$ " << fixed << setprecision(2) << saldo[indice] << endl;
                }

                break;
            }

            case 0:
                cout << "\nEncerrando o sistema..." << endl;
                break;

            default:
                cout << "\nOpcao invalida!" << endl;
        }

    } while (opcao != 0);

    return 0;
}

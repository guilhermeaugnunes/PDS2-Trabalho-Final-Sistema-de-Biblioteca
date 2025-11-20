#include <iostream>
#include <string>
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Biblioteca.hpp"

int main () {
    //MAIN DE TESTE APENAS PARA A CLASSE USUARIO E SUBCLASSES
    Biblioteca biblio;

    /*Usuario* u1 = new Aluno ("Guilherme Augusto Nunes", 2024017015, "guilhermeaugnunes@ufmg.br");
    Usuario* u2 = new Professor ("Vangellis Oliveira", 2025912079, "vangellis@ufmg.br");
    Usuario* u3 = new Aluno ("Gabriel dos Reis", 2024589325, "greis@ufmg.br");

    std::cout << "--- Teste de Cadastro ---" << std::endl;
    biblio.cadastrarUsuario(u1);
    biblio.cadastrarUsuario(u2);
    biblio.cadastrarUsuario(u3);

    std::cout << "\n--- Teste de Duplicidade ---" << std::endl;
    biblio.cadastrarUsuario(u2); //tem que dar erro

    std::cout << "\n--- Teste de Listagem ---" << std::endl;
    biblio.listarUsuarios();
    
    std::cout << "\n--- Teste de Busca ---" << std::endl;
    Usuario* u = biblio.buscarUsuario(2024017015);
    if (u != nullptr) {
        std::cout << "Encontrado! " << u->getNome() << std::endl;
    }
    else {
        std::cout << "Usuario nao encontrado. " << std::endl;
    }

    std::cout << "\n--- Teste de Remocao ---" << std::endl;
    biblio.removerUsuario(2025912079);

    std::cout << "\n--- Listagem apos Remocao ---" << std::endl;
    biblio.listarUsuarios();*/

    // 1. Tenta carregar do disco (na primeira vez vai falhar, normal)
    biblio.carregarUsuariosDoArquivo("banco_usuarios.txt");

    // 2. Se o banco estava vazio, vamos popular para testar
    // (Você pode comentar isso depois de rodar a primeira vez!)
    if (biblio.buscarUsuario(2024017015) == nullptr) {
        std::cout << "Cadastrando usuarios iniciais..." << std::endl;
        biblio.cadastrarUsuario(new Aluno("Guilherme Augusto", 2024017015, "guilhermeaugnunes@ufmg.br"));
        biblio.cadastrarUsuario(new Professor("Vangellis Sagnori", 2025912079, "vangellis@ufmg.br"));
        biblio.cadastrarUsuario(new Aluno("Vitor Alencar", 2025911083, "vitoralencar@ufmg.br"));
    }

    std::cout << "\n--- Listagem Atual ---" << std::endl;
    biblio.listarUsuarios();

    // 3. Salva tudo no disco antes de sair
    biblio.salvarUsuariosEmArquivo("banco_usuarios.txt");

    return 0;
}
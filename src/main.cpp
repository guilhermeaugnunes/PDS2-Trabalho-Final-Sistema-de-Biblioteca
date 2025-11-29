#include <iostream>
#include <string>
#include "Biblioteca.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Livro.hpp"

void exibirMenu() {
    std::cout << "\n--- Sistema de Biblioteca ---" << std::endl;
    std::cout << "1. Cadastrar Aluno" << std::endl;
    std::cout << "2. Cadastrar Professor" << std::endl;
    std::cout << "3. Cadastrar Livro" << std::endl;
    std::cout << "4. Listar Usuarios" << std::endl;
    std::cout << "5. Listar Livros" << std::endl;
    std::cout << "6. Realizar Emprestimo" << std::endl;
    std::cout << "7. Realizar Devolucao" << std::endl;
    std::cout << "0. Sair" << std::endl;
    std::cout << "Escolha uma opcao: ";
}

int main() {
    Biblioteca biblio;
    
    // Carrega dados iniciais se houver
    biblio.carregarUsuariosDoArquivo("usuarios.txt");

    int opcao;
    do {
        exibirMenu();
        std::cin >> opcao;
        std::cin.ignore(); // Limpar buffer do enter

        switch (opcao) {
            case 1: {
                std::string nome, email;
                int matricula;
                std::cout << "Nome: "; std::getline(std::cin, nome);
                std::cout << "Matricula: "; std::cin >> matricula;
                std::cout << "Email: "; std::cin >> email;
                biblio.cadastrarUsuario(new Aluno(nome, matricula, email));
                break;
            }
            case 2: {
                std::string nome, email;
                int matricula;
                std::cout << "Nome: "; std::getline(std::cin, nome);
                std::cout << "Matricula: "; std::cin >> matricula;
                std::cout << "Email: "; std::cin >> email;
                biblio.cadastrarUsuario(new Professor(nome, matricula, email));
                break;
            }
            case 3: {
                std::string titulo, autor, isbn;
                int qtd;
                std::cout << "Titulo: "; std::getline(std::cin, titulo);
                std::cout << "Autor: "; std::getline(std::cin, autor);
                std::cout << "ISBN: "; std::cin >> isbn;
                std::cout << "Quantidade: "; std::cin >> qtd;
                biblio.cadastrarLivro(new Livro(titulo, autor, isbn, qtd));
                break;
            }
            case 4:
                biblio.listarUsuarios();
                break;
            case 5:
                biblio.listarLivros();
                break;
            case 6: {
                int matricula;
                std::string isbn;
                std::cout << "Matricula do Usuario: "; std::cin >> matricula;
                std::cout << "ISBN do Livro: "; std::cin >> isbn;
                biblio.realizarEmprestimo(matricula, isbn);
                break;
            }
            case 7: {
                int matricula;
                std::string isbn;
                std::cout << "Matricula do Usuario: "; std::cin >> matricula;
                std::cout << "ISBN do Livro: "; std::cin >> isbn;
                biblio.registrarDevolucao(matricula, isbn);
                break;
            }
            case 0:
                std::cout << "Saindo e salvando dados..." << std::endl;
                biblio.salvarUsuariosEmArquivo("usuarios.txt");
                break;
            default:
                std::cout << "Opcao invalida!" << std::endl;
        }
    } while (opcao != 0);

    return 0;
}
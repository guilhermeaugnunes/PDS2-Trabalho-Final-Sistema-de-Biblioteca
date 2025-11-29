#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Usuario.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include "Livro.hpp"
#include "Emprestimo.hpp"
#include "SistemaNotificacao.hpp"

#include <map>
#include <string>
#include <vector>

class Biblioteca {
private:
    // Mapeia matrícula -> Usuario*
    std::map<int, Usuario*> _usuarios;
    // Mapeia ISBN -> Livro*
    std::map<std::string, Livro*> _acervo;
    
    std::vector<Emprestimo*> _emprestimos;
    SistemaNotificacao _notificador;

public:
    Biblioteca();
    ~Biblioteca();

    // Gerenciamento de Usuários
    void cadastrarUsuario(Usuario* usuario);
    void removerUsuario(int matricula); // Removendo const do parametro se houver
    Usuario* buscarUsuario(int matricula);
    void listarUsuarios() const;

    // Gerenciamento de Livros
    void cadastrarLivro(Livro* livro);
    Livro* buscarLivro(const std::string& isbn);
    void listarLivros() const;

    // Operações
    void realizarEmprestimo(int matricula, const std::string& isbn);
    void registrarDevolucao(int matricula, const std::string& isbn);

    // Persistência (Simplificada para Usuarios conforme seu codigo original)
    void salvarUsuariosEmArquivo(const std::string& nomeArquivo);
    void carregarUsuariosDoArquivo(const std::string& nomeArquivo);
};

#endif
#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP

#include "Aluno.hpp"
#include "Emprestimo.hpp"
#include "Livro.hpp"
#include "Professor.hpp"
#include "Reserva.hpp"
#include "SistemaNotificacao.hpp"
#include "Usuario.hpp"

#include <map>
#include <string>
#include <iostream>

class Biblioteca {
    private:
    std::map<int, Usuario*> _usuarios;
    // (Futuramente haverá _livros, _emprestimos, etc.)

    public:
    Biblioteca();
    ~Biblioteca();

    void cadastrarUsuario(Usuario* usuario);
    void removerUsuario (int matricula);
    Usuario* buscarUsuario (int matricula);
    void listarUsuarios() const;

};

#endif
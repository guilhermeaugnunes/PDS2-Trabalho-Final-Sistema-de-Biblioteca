#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include <string>
#include "Usuario.hpp"
#include "Livro.hpp"
#include "SistemaNotificacao.hpp"

class Emprestimo {
private:
    Usuario* usuario;
    Livro* livro;
    std::string dataEmprestimo;
    std::string dataPrevistaDevolucao;
    std::string dataDevolucaoReal;
    int numeroRenovacoes;
    std::string status;
    std::string calcularDataDevolucao(std::string dataBase);

public:
    Emprestimo(Usuario* u, Livro* l, SistemaNotificacao* notificador);
    void renovar(SistemaNotificacao* notificador);
    void registrarDevolucao(SistemaNotificacao* notificador);
    bool estaAtrasado();
    Usuario* getUsuario() const;
    Livro* getLivro() const;
    std::string getDataPrevistaDevolucao() const;
    bool isAtivo() const;
};

#endif
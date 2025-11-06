#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Usuario.hpp"

class Aluno : public Usuario {
public:
    Aluno(const std::string& nome, int matricula, const std::string& email);
    int limiteEmprestimo() const override;
    std::string getTipo() const override;
};

#endif
#ifndef ALUNO_HPP
#define ALUNO_HPP

#include "Usuario.hpp"

class Aluno : public Usuario {
public:
    Aluno(const std::string& nome, int matricula, const std::string& email, const std::string& tipo);
    int limiteEmprestimo() const override;
};

#endif
#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Usuario.hpp"

class Professor : public Usuario {
public:
    Professor(const std::string& nome, int matricula, const std::string& email);
    int limiteEmprestimo() const override;
    std::string getTipo() const override;   
};

#endif
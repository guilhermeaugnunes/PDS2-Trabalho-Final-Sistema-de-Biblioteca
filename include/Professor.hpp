#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Usuario.hpp"

class Professor : public Usuario {
public:
    Professor(const std::string& nome, int matricula, const std::string& email, const std::string& tipo);
    int limiteEmprestimo() const override;
};


#endif
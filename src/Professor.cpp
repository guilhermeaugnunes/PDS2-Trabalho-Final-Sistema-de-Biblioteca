#include "Professor.hpp"

Professor::Professor(const std::string& nome, int matricula, const std::string& email, const std::string& tipo) 
    : Usuario (nome, matricula, email, tipo) {}

int Professor::limiteEmprestimo() const {
    return 5;
}
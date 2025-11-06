#include "Professor.hpp"

Professor::Professor(const std::string& nome, int matricula, const std::string& email) 
    : Usuario (nome, matricula, email) {}

int Professor::limiteEmprestimo() const {
    return 5;
}

std::string Professor::getTipo() const {
    return "Professor";
};   

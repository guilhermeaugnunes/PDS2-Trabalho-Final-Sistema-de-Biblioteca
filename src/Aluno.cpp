#include "Aluno.hpp"

Aluno::Aluno(const std::string& nome, int matricula, const std::string& email) 
    : Usuario (nome, matricula, email) {}

int Aluno::limiteEmprestimo() const {
    return 3;
}

std::string Aluno::getTipo() const {
    return "Aluno";
};   
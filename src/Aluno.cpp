#include "Aluno.hpp"

Aluno::Aluno(const std::string& nome, int matricula, const std::string& email, const std::string& tipo) 
    : Usuario (nome, matricula, email, tipo) {}

int Aluno::limiteEmprestimo() const {
    return 3;
}
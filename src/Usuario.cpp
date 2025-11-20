#include "Usuario.hpp"
#include <string>
//#include <vector>

Usuario::Usuario(const std::string& nome, int matricula, const std::string& email)
    : _nome(nome), _matricula(matricula), _email(email) {}

Usuario::~Usuario() {}
    
std::string Usuario::getNome() const {
    return this->_nome;
}

int Usuario::getMatricula() const {
    return this->_matricula;
}

std::string Usuario::getEmail() const {
    return this->_email;
}

//metodos dependentes de outras classes (que não estão prontas)
void Usuario::adicionaEmprestimo(Emprestimo* emprestimo) {
    //sem classe necessária ainda (Emprestimo.hpp)
}
//alterei e adicionei aqui - bebel
void Usuario::adicionaNotificacao(const std::string& mensagem) {
    this->_notificacoes.push_back(mensagem);
}

const std::vector<std::string>& Usuario::getNotificacoes() const {
    return this->_notificacoes;
}
void Usuario::adicionaReserva(Reserva* reserva) {
    //sem classe necessária ainda (Reserva.hpp)
}

bool Usuario::verificaPendencias() const {
    return false;
}

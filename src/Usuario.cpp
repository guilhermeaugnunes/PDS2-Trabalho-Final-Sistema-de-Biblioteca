#include "Usuario.hpp"
#include <string>
//#include <vector>

Usuario::Usuario(const std::string& nome, int matricula, const std::string& email, const std::string& tipo)
    : _nome(nome), _matricula(matricula), _email(email), _tipo(tipo) {}

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

std::string Usuario::getTipo() const {
    return this->_tipo;
}

//metodos dependentes de outras classes (que não estão prontas)
void Usuario::adicionaEmprestimo(Emprestimo* emprestimo) {
    //sem classe necessária ainda (Emprestimo.hpp)
}
void Usuario::adicionaNotificacao(SistemaNotificacao* notificacao) {
    //sem classe necessária ainda (SistemaNotificacao.hpp)
}
void Usuario::adicionaReserva(Reserva* reserva) {
    //sem classe necessária ainda (Reserva.hpp)
}

bool Usuario::verificaPendencias() const {
    return false;
}

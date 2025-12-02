#include "Usuario.hpp"
#include "Emprestimo.hpp"
#include "Reserva.hpp"

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

void Usuario::adicionaEmprestimo(Emprestimo* emprestimo) {
    this->_historicoEmprestimos.push_back(emprestimo);
}

void Usuario::adicionaNotificacao(const std::string& mensagem) {
    this->_notificacoes.push_back(mensagem);
}

const std::vector<std::string>& Usuario::getNotificacoes() const {
    return this->_notificacoes;
}

void Usuario::limparNotificacoes() {
    this->_notificacoes.clear();
}

void Usuario::adicionaReserva(Reserva* reserva) {
    this->_reservas.push_back(reserva);
}

bool Usuario::verificaPendencias() const {
    // Lógica simplificada: se tiver notificação de atraso, tem pendência.
    // Você pode expandir isso verificando multas reais depois.
    return false; 
}

bool Usuario::atingiuLimiteEmprestimos() const {
    // Verifica quantos empréstimos estão ATIVOS
    int ativos = 0;
    for (auto* emp : _historicoEmprestimos) {
        if (emp->isAtivo()) {
            ativos++;
        }
    }
    return ativos >= this->limiteEmprestimo();
}
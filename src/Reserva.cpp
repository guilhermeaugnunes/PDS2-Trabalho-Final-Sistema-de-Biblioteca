#include "Reserva.hpp"
#include "Usuario.hpp"
#include "Livro.hpp"
#include <iostream>

Reserva::Reserva(Usuario* u, Livro* l) 
    : usuario(u), livro(l), status(StatusReserva::ATIVA) {
}
Reserva::~Reserva() {
    
}
Usuario* Reserva::getUsuario() const {
    return usuario;
}
Livro* Reserva::getLivro() const {
    return livro;
}
Reserva::StatusReserva Reserva::getStatus() const {
    return status;
}
void Reserva::concluirReserva() {
    if (status == StatusReserva::ATIVA) {
        status = StatusReserva::CONCLUIDA;
    }
}

void Reserva::cancelarReserva(bool porPrazo) {
    if (status == StatusReserva::ATIVA) {
        if (porPrazo) {
            status = StatusReserva::CANCELADA_PRAZO;
            std::string msg = "Sua reserva para o livro foi cancelada pois o prazo expirou.";
            usuario->adicionaNotificacao(msg);
        } else {
            status = StatusReserva::CANCELADA_USUARIO;
        }
    }
}
void Reserva::notificarDisponibilidade() {
    if (status == StatusReserva::ATIVA && usuario != nullptr) {
        std::string titulo = (livro != nullptr) ? "o livro solicitado" : "um livro";
        
        std::string mensagem = "O livro reservado esta disponivel para retirada.";
        usuario->adicionaNotificacao(mensagem); 
    }
}
bool Reserva::isAtiva() const {
    return status == StatusReserva::ATIVA;
}

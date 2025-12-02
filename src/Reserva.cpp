#include "Reserva.hpp"

Reserva::Reserva(Usuario* usuario, Livro* livro) 
    : _usuario(usuario), _livro(livro), _ativa(true) {
    _dataReserva = "HOJE"; // Em um sistema real, use ctime
}

Reserva::~Reserva() {}

Usuario* Reserva::getUsuario() const {
    return _usuario;
}

Livro* Reserva::getLivro() const {
    return _livro;
}

bool Reserva::isAtiva() const {
    return _ativa;
}

void Reserva::cancelar() {
    _ativa = false;
}
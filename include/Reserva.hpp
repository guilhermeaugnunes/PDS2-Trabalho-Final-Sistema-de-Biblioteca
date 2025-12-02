#ifndef RESERVA_HPP
#define RESERVA_HPP

#include "Usuario.hpp"
#include "Livro.hpp"
#include <string>

class Reserva {
private:
    Usuario* _usuario;
    Livro* _livro;
    std::string _dataReserva;
    bool _ativa;

public:
    Reserva(Usuario* usuario, Livro* livro);
    ~Reserva();

    Usuario* getUsuario() const;
    Livro* getLivro() const;
    bool isAtiva() const;
    void cancelar(); // Desativa a reserva
};

#endif
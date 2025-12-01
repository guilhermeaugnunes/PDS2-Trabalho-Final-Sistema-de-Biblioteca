#ifndef RESERVA_HPP
#define RESERVA_HPP

#include <string>

class Usuario;
class Livro;

class Reserva {
public:
    enum class StatusReserva {
        ATIVA,
        CONCLUIDA,
        CANCELADA_USUARIO,
        CANCELADA_PRAZO 
    };

private:
    Usuario* usuario;
    Livro* livro;
    StatusReserva status;

public:

    Reserva(Usuario* usuario, Livro* livro);
    virtual ~Reserva();
    Usuario* getUsuario() const;
    Livro* getLivro() const;
    StatusReserva getStatus() const;
    void concluirReserva();
    void cancelarReserva(bool porPrazo = false); 
        void notificarDisponibilidade();
    bool isAtiva() const;
};

#endif
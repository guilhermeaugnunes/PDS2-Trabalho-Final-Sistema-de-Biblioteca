#ifndef SISTEMANOTIFICACAO_HPP
#define SISTEMANOTIFICACAO_HPP

#include <string>

class Notificacao {
private:
    // Coloque o mínimo para a sua classe Usuário poder funcionar.
    std::string _mensagem; 
public:
    Notificacao(const std::string& msg) : _mensagem(msg) {}
};

#endif
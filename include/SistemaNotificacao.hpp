#ifndef SISTEMA_NOTIFICACAO_HPP
#define SISTEMA_NOTIFICACAO_HPP

#include <string>
#include "Usuario.hpp" // precisamos conhecer o usuario para mandar mensagem pra ele

class SistemaNotificacao {
public:

    SistemaNotificacao();
    ~SistemaNotificacao();

    // metodos exigidos nas nossas user stories e CRC
    void notificarDevolucao(Usuario& usuario, std::string tituloLivro);
    void notificarAtraso(Usuario& usuario, std::string tituloLivro, int diasAtraso);
    void notificarReservaDisponivel(Usuario& usuario, std::string tituloLivro);
    void notificarEmprestimo(Usuario& usuario, std::string tituloLivro, std::string dataDevolucao);
    void notificarDevolucaoProxima(Usuario& usuario, std::string tituloLivro, int diasRestantes);
    
    // metodo para visualizar (debug)
    void exibirNotificacoes(Usuario& usuario, bool limparAposLer = true);
};

#endif
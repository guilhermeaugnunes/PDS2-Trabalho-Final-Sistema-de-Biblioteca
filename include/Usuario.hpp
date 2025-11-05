#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>
#include <vector>

class Emprestimo;
class SistemaNotificacao;
class Reserva; // declarações antecipadas

class Usuario {
private:
    std::string _nome;
    int _matricula;
    std::string _email;
    std::string _tipo;
    
    //Atributos declarações
    std::vector<Emprestimo*> _historicoEmprestimos;
    std::vector<SistemaNotificacao*> _notificacoes;
    std::vector<Reserva*> _reservas;
    

protected: 
    Usuario(const std::string& nome, int matricula, const std::string& email, const std::string& tipo);

public:
    virtual ~Usuario();
    
    //getters
    std::string getNome() const;
    int getMatricula() const;
    std::string getEmail() const;
    std::string getTipo() const;

    //metodo virtual
    virtual int limiteEmprestimo() const = 0;

    //metodos dependentes de outras classes (que não estão prontas)
    void adicionaEmprestimo(Emprestimo* emprestimo);
    void adicionaNotificacao(SistemaNotificacao* notificacao);
    void adicionaReserva(Reserva* reserva);

    bool verificaPendencias() const;
};

#endif
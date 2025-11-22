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
    //std::string _tipo;
    
    //Atributos declarações
    std::vector<Emprestimo*> _historicoEmprestimos;
    std::vector<std::string> _notificacoes; // alterei porque o usuário vai guardar só uma lista de textos (no caso as mensagens)
    std::vector<Reserva*> _reservas;
    

protected: 
    Usuario(const std::string& nome, int matricula, const std::string& email);

public:
    virtual ~Usuario();
    
    //getters
    std::string getNome() const;
    int getMatricula() const;
    std::string getEmail() const;
    virtual std::string getTipo() const = 0;

    //metodo virtual
    virtual int limiteEmprestimo() const = 0;

    //metodos dependentes de outras classes (que não estão prontas)
    void adicionaEmprestimo(Emprestimo* emprestimo);
    void adicionaNotificacao(const std::string& mensagem); //alterei tbm - bebel
    const std::vector<std::string>& getNotificacoes() const; // adicionei esse pra classe SistemaNotificacao poder ver as mensagens - bebel 
    void limparNotificacoes(); 

    void adicionaReserva(Reserva* reserva); 

    bool verificaPendencias() const;
};

#endif
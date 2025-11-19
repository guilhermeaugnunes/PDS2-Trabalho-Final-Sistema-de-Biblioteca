#ifndef LIVRO_HPP
#define LIVRO_HPP

#include <string>
#include <iostream>
/**/
enum class StatusLivro {
    DISPONIVEL,
    EMPRESTADO_TOTALMENTE, // Quando todas as cópias foram emprestadas
    RESERVADO
};

class Livro {
    private: 
    std::string titulo; 
    std::string autor; 
    std::string isbn; 
    int quantidadeTotal; 
    int quantidadeDisponivel; 
    int quantidadeReservada;    
    
    public:
    //construtor
    Livro(std::string titulo, std::string autor, std::string isbn, int quantidadeInicial);

    // Getters
    std::string getTitulo() const; 
    std::string getAutor() const; 
    std::string getIsbn() const;
    int getQuantidadeTotal() const; 
    int getQuantidadeDisponivel() const; 
    int getQuantidadeReservada() const;
    
    /* Setters 
       Não é necessário, pois não está na responsabilidades do Cartão CRC. 
       Deixei comentado somente para praticar (não é boa prática, então irei apagar depois).  
    void setAutor(const std::string nomeAutor);
    void setTitulo(const std::string novoTitulo); 
    void setIsbn(const std::string novoIsbn);
    void setQuantidadeTotal(const int quantidade); 
    void setQuantidadeDisponivel(const int novaQuantDisp); 
    void setQuantidadeReservada(const int novaQuantReserv); 
    */
    
    /* Responsabilidade: Atualizar o status após empréstimos
    Retorna true se o empréstimo foi bem sucedido */
    StatusLivro verificarStatus() const;

    // Responsabilidade: Atualizar o status após empréstimos
    // Retorna true se o empréstimo foi bem sucedido
    bool realizarEmprestimo(); 

    // Responsabilidade: Atualizar o status após devoluções
    void realizarDevolucao();

    // Responsabilidade: Informar/Gerenciar reserva
    bool reservarLivro();
    void cancelarReserva();
    
    // Método auxiliar para exibir informações (opcional, mas útil para debug)
    void exibirDetalhes() const;

};









#endif
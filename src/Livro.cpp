#include "Livro.hpp"
#include <iostream>

// --- Construtor ---
Livro::Livro(std::string titulo, std::string autor, std::string isbn, int quantidadeInicial) 
    : titulo(titulo), autor(autor), isbn(isbn), quantidadeTotal(quantidadeInicial) {
    
    // Ao criar o livro, a disponibilidade é total e não há reservas
    this->quantidadeDisponivel = quantidadeInicial;
    this->quantidadeReservada = 0;
}

// --- Getters ---
std::string Livro::getTitulo() const {
    return titulo;
}

std::string Livro::getAutor() const {
    return autor;
}

std::string Livro::getIsbn() const {
    return isbn;
}

int Livro::getQuantidadeTotal() const {
    return quantidadeTotal;
}

int Livro::getQuantidadeDisponivel() const {
    return quantidadeDisponivel;
}

int Livro::getQuantidadeReservada() const {
    return quantidadeReservada;
}

// --- Lógica de Negócio ---

StatusLivro Livro::verificarStatus() const {
    // 1. Se não há cópias físicas na biblioteca
    if (quantidadeDisponivel == 0) {
        return StatusLivro::EMPRESTADO_TOTALMENTE;
    }
    
    // 2. Se há cópias, mas todas estão comprometidas com reservas
    // Exemplo: 2 livros na estante, mas 2 pessoas reservaram.
    if (quantidadeDisponivel <= quantidadeReservada) {
        return StatusLivro::RESERVADO;
    }

    // 3. Se sobrou livro livre de reserva
    return StatusLivro::DISPONIVEL;
}

bool Livro::realizarEmprestimo() {
    // Só podemos emprestar se o livro estiver realmente DISPONÍVEL para o público geral
    if (verificarStatus() == StatusLivro::DISPONIVEL) {
        quantidadeDisponivel--;
        return true;
    }
    
    // Se estiver EMPRESTADO_TOTALMENTE ou RESERVADO, não realiza o empréstimo comum
    return false;
}

void Livro::realizarDevolucao() {
    // Só aceita devolução se não ultrapassar o total de livros que a biblioteca comprou
    if (quantidadeDisponivel < quantidadeTotal) {
        quantidadeDisponivel++;
    }
}

bool Livro::reservarLivro() {
    // Regra simples: Podemos reservar se ainda houver "fila" disponível.
    // Aqui estou assumindo que podemos reservar mesmo se todos estiverem emprestados,
    // criando uma fila de espera.
    
    quantidadeReservada++;
    return true; 
}

void Livro::cancelarReserva() {
    if (quantidadeReservada > 0) {
        quantidadeReservada--;
    }
}

// --- Método Auxiliar ---
void Livro::exibirDetalhes() const {
    std::cout << "--- Detalhes do Livro ---" << std::endl;
    std::cout << "Titulo: " << titulo << std::endl;
    std::cout << "Autor: " << autor << std::endl;
    std::cout << "ISBN: " << isbn << std::endl;
    std::cout << "Qtd Total: " << quantidadeTotal << std::endl;
    std::cout << "Qtd Disponivel: " << quantidadeDisponivel << std::endl;
    std::cout << "Qtd Reservada: " << quantidadeReservada << std::endl;
    
    std::cout << "Status Atual: ";
    StatusLivro status = verificarStatus();
    switch (status) {
        case StatusLivro::DISPONIVEL: 
            std::cout << "Disponivel"; 
            break;
        case StatusLivro::EMPRESTADO_TOTALMENTE: 
            std::cout << "Emprestado Totalmente"; 
            break;
        case StatusLivro::RESERVADO: 
            std::cout << "Reservado"; 
            break;
    }
    std::cout << std::endl << "-------------------------" << std::endl;
}
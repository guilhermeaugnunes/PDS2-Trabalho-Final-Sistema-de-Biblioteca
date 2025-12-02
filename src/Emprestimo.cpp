#include "Emprestimo.hpp"
#include <iostream> 
#include <stdexcept>

Emprestimo::Emprestimo(Usuario* u, Livro* l, SistemaNotificacao* notificador) {
    
    if (u->atingiuLimiteEmprestimos()) {
        throw std::runtime_error("Usuario atingiu o limite de emprestimos.");
    }
    
    if (u->verificaPendencias()){ 
        throw std::runtime_error("Usuario possui pendencias.");
    }
        
    if (!l->realizarEmprestimo()) {
        throw std::runtime_error("Livro indisponivel para emprestimo (estoque vazio ou reservado).");
    }
    this->usuario = u;
    this->livro = l;
    this->numeroRenovacoes = 0;
    this->status = "ATIVO";

    this->dataEmprestimo = "HOJE";
    this->dataPrevistaDevolucao = calcularDataDevolucao(this->dataEmprestimo);
    
    // Registra o empréstimo no usuário
    u->adicionaEmprestimo(this);

    notificador->notificarEmprestimo(*this->usuario, this->livro->getTitulo(), this->dataPrevistaDevolucao);
}

void Emprestimo::renovar(SistemaNotificacao* notificador) {
    if (this->livro->getQuantidadeReservada() > 0) {
        std::cout << "Erro: Nao e possivel renovar pois ha reservas para este livro." << std::endl; 
        return;
    }

    if (this->numeroRenovacoes >= 3) {
        std::cout << "Erro: Limite de 3 renovacoes atingido." << std::endl;
        return;
    }

    if (this->estaAtrasado()) {
        std::cout << "Erro: Nao e possivel renovar um emprestimo atrasado." << std::endl;
        return;
    }
    this->numeroRenovacoes++;
    this->dataPrevistaDevolucao = calcularDataDevolucao(this->dataPrevistaDevolucao);

    notificador->notificarEmprestimo(*this->usuario, this->livro->getTitulo(), this->dataPrevistaDevolucao);
}

void Emprestimo::registrarDevolucao(SistemaNotificacao* notificador) {
    if (this->status != "ATIVO") {
        std::cerr << "Erro: Este emprestimo ja foi concluido." << std::endl;
        return;
    }
    this->dataDevolucaoReal = "HOJE";
    this->status = "CONCLUIDO";
    this->livro->realizarDevolucao();
    notificador->notificarDevolucao(*this->usuario, this->livro->getTitulo());
    
    if (this->estaAtrasado()) {
        int diasAtraso = 1; // Simplificação para exemplo
        notificador->notificarAtraso(*this->usuario, this->livro->getTitulo(), diasAtraso);
    }
}

bool Emprestimo::estaAtrasado() {
    std::string dataAtual = "HOJE";
    // Comparação de string não é ideal para data, mas mantendo a lógica original por enquanto
    return (dataAtual > this->dataPrevistaDevolucao && this->status == "ATIVO");
}

std::string Emprestimo::calcularDataDevolucao(std::string dataBase) {
    return dataBase + " + 7 dias";
}

// --- Getters (Apenas UMA vez) ---

Usuario* Emprestimo::getUsuario() const { 
    return this->usuario; 
}

Livro* Emprestimo::getLivro() const { 
    return this->livro; 
}

std::string Emprestimo::getDataPrevistaDevolucao() const { 
    return this->dataPrevistaDevolucao; 
}

bool Emprestimo::isAtivo() const { 
    return this->status == "ATIVO"; 
}
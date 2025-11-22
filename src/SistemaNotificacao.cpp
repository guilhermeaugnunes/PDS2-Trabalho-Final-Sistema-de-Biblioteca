#include "SistemaNotificacao.hpp"
#include <iostream>

// construtor e destrutor vazios
SistemaNotificacao::SistemaNotificacao() {}
SistemaNotificacao::~SistemaNotificacao() {}

void SistemaNotificacao::notificarDevolucao(Usuario& usuario, std::string tituloLivro) {
    std::string mensagem = "Devolucao confirmada! O livro '" + tituloLivro + "' foi devolvido.";
    usuario.adicionaNotificacao(mensagem);
}

void SistemaNotificacao::notificarAtraso(Usuario& usuario, std::string tituloLivro, int diasAtraso) {
    std::string mensagem = "ALERTA: O livro '" + tituloLivro + "' esta com atraso de " + std::to_string(diasAtraso) + " dias. Multa pendente.";
    usuario.adicionaNotificacao(mensagem);
}

void SistemaNotificacao::notificarReservaDisponivel(Usuario& usuario, std::string tituloLivro) {
    std::string mensagem = "Novidade: O livro '" + tituloLivro + "' que voce reservou ja esta disponivel para retirada!";
    usuario.adicionaNotificacao(mensagem);
}

void SistemaNotificacao::notificarEmprestimo(Usuario& usuario, std::string tituloLivro, std::string dataDevolucao){
    std::string mensagem = "O livro ' " + tituloLivro + " ' foi emprestado com sucesso! Devolva ate: " + dataDevolucao;    
    usuario.adicionaNotificacao(mensagem);
}

void SistemaNotificacao::notificarDevolucaoProxima(Usuario& usuario, std::string tituloLivro, int diasRestantes) {
    std::string mensagem = "Lembrete! Faltam " + std::to_string(diasRestantes) + " dias para devolver ' " + tituloLivro + " ' .";   
    usuario.adicionaNotificacao(mensagem); 
}

void SistemaNotificacao::exibirNotificacoes(Usuario& usuario, bool limparAposLer) {
    std::cout << "--- Notificacoes para " << usuario.getNome() << " ---" << std::endl;
    
    auto& listaMensagens = usuario.getNotificacoes(); // pega a lista de strings do usuário

    if (listaMensagens.empty()) {
        std::cout << "Nenhuma notificacao pendente!" << std::endl;
    } else {
        for (const std::string& msg : listaMensagens) {
            std::cout << "[msg]: " << msg << std::endl;
        }
    }
    std::cout << "-------------------------------------------" << std::endl;

    if (limparAposLer && !listaMensagens.empty()){
        usuario.limparNotificacoes();
        std::cout << "[Sistema] As mensagens lidas foram apagadas da caixa de entrada." << std::endl;
    }
}


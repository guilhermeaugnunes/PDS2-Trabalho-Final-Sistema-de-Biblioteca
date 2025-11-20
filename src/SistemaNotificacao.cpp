#include "SistemaNotificacao.hpp"
#include <iostream>

// Construtor e Destrutor vazios (não precisamos inicializar nada especial por enquanto)
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

void SistemaNotificacao::exibirNotificacoes(const Usuario& usuario) {
    std::cout << "--- Notificacoes para " << usuario.getNome() << " ---" << std::endl;
    
    const auto& listaMensagens = usuario.getNotificacoes(); // pega a lista de strings do usuário

    if (listaMensagens.empty()) {
        std::cout << "Nenhuma notificacao pendente." << std::endl;
    } else {
        for (const std::string& msg : listaMensagens) {
            std::cout << "[msg]: " << msg << std::endl; //loop pra cada uma
        }
    }
    std::cout << "-------------------------------------------" << std::endl;
}
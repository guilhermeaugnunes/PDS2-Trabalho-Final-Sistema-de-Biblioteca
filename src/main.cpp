#include <iostream>
#include "Aluno.hpp"
#include "SistemaNotificacao.hpp"

int main() {
    std::cout << "=== INICIANDO TESTE DO SISTEMA DE NOTIFICACAO ===" << std::endl;

    // 1. Criando os personagens
    // Estamos criando um aluno chamado "Carlos"
    Aluno aluno("Carlos Silva", 2023001, "carlos@ufmg.br");
    
    // Estamos criando o seu sistema (o carteiro)
    SistemaNotificacao sistema;

    // 2. Ação: O sistema vai enviar mensagens para o Carlos
    std::cout << "\n[!] Enviando notificacoes..." << std::endl;
    
    sistema.notificarReservaDisponivel(aluno, "O Senhor dos Aneis");
    sistema.notificarDevolucao(aluno, "Calculo I");
    sistema.notificarAtraso(aluno, "Dom Casmurro", 5); // 5 dias de atraso

    // 3. Verificação: Vamos ver se as mensagens chegaram
    // Aqui chamamos o seu método de exibir
    std::cout << "\n[!] Lendo a caixa de entrada do aluno..." << std::endl;
    sistema.exibirNotificacoes(aluno);

    std::cout << "\n=== FIM DO TESTE ===" << std::endl;

    return 0; // Retorna 0 significa "Tudo deu certo"
}
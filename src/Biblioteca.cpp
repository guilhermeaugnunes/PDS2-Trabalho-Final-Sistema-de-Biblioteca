#include "Biblioteca.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Biblioteca::Biblioteca() {}

Biblioteca::~Biblioteca() {
    // Limpar memória de usuários
    for (auto& pair : _usuarios) {
        delete pair.second;
    }
    _usuarios.clear();

    // Limpar memória de livros
    for (auto& pair : _acervo) {
        delete pair.second;
    }
    _acervo.clear();

    // Limpar memória de emprestimos
    for (auto* emp : _emprestimos) {
        delete emp;
    }
    _emprestimos.clear();
}

// --- Usuários ---
void Biblioteca::cadastrarUsuario(Usuario* usuario) {
    if (_usuarios.count(usuario->getMatricula()) > 0) {
        std::cout << "Erro: Matricula ja existente." << std::endl;
        return;
    }
    _usuarios[usuario->getMatricula()] = usuario;
    std::cout << "Usuario cadastrado com sucesso!" << std::endl;
}

void Biblioteca::removerUsuario(int matricula) {
    auto it = _usuarios.find(matricula);
    if (it != _usuarios.end()) {
        Usuario* u = it->second;
        if (u->verificaPendencias()) {
            std::cout << "Erro: Usuario possui pendencias e nao pode ser removido." << std::endl;
            return;
        }
        delete u;
        _usuarios.erase(it);
        std::cout << "Usuario removido." << std::endl;
    } else {
        std::cout << "Usuario nao encontrado." << std::endl;
    }
}

Usuario* Biblioteca::buscarUsuario(int matricula) {
    if (_usuarios.count(matricula)) {
        return _usuarios[matricula];
    }
    return nullptr;
}

void Biblioteca::listarUsuarios() const {
    std::cout << "--- Lista de Usuarios ---" << std::endl;
    for (auto const& pair : _usuarios) {
        std::cout << pair.first << " - " << pair.second->getNome() 
                  << " (" << pair.second->getTipo() << ")" << std::endl;
    }
}

// --- Livros ---
void Biblioteca::cadastrarLivro(Livro* livro) {
    // Se o ISBN já existe, poderíamos apenas somar a quantidade, 
    // mas aqui vamos assumir que não pode duplicar o objeto.
    if (_acervo.count(livro->getIsbn())) {
        std::cout << "Erro: Livro com este ISBN ja existe." << std::endl;
        return;
    }
    _acervo[livro->getIsbn()] = livro;
    std::cout << "Livro cadastrado: " << livro->getTitulo() << std::endl;
}

Livro* Biblioteca::buscarLivro(const std::string& isbn) {
    if (_acervo.count(isbn)) return _acervo[isbn];
    return nullptr;
}

void Biblioteca::listarLivros() const {
    std::cout << "--- Acervo da Biblioteca ---" << std::endl;
    for (auto const& pair : _acervo) {
        Livro* l = pair.second;
        std::cout << "ISBN: " << l->getIsbn() << " | Titulo: " << l->getTitulo() 
                  << " | Disp: " << l->getQuantidadeDisponivel() << std::endl;
    }
}

// --- Operações ---
void Biblioteca::realizarEmprestimo(int matricula, const std::string& isbn) {
    Usuario* usuario = buscarUsuario(matricula);
    Livro* livro = buscarLivro(isbn);

    if (!usuario) {
        std::cout << "Usuario nao encontrado." << std::endl;
        return;
    }
    if (!livro) {
        std::cout << "Livro nao encontrado." << std::endl;
        return;
    }

    try {
        // Cria o empréstimo (a lógica de validação está no construtor de Emprestimo)
        Emprestimo* novoEmp = new Emprestimo(usuario, livro, &_notificador);
        _emprestimos.push_back(novoEmp);
        std::cout << "Emprestimo realizado com sucesso!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Erro ao realizar emprestimo: " << e.what() << std::endl;
    }
}

void Biblioteca::registrarDevolucao(int matricula, const std::string& isbn) {
    // Procura um empréstimo ativo para este usuário e livro
    bool devolvido = false;
    for (auto* emp : _emprestimos) {
        if (emp->isAtivo() && 
            emp->getUsuario()->getMatricula() == matricula && 
            emp->getLivro()->getIsbn() == isbn) {
            
            emp->registrarDevolucao(&_notificador);
            std::cout << "Devolucao registrada." << std::endl;
            devolvido = true;
            break; 
        }
    }
    if (!devolvido) {
        std::cout << "Nenhum emprestimo ativo encontrado para este usuario/livro." << std::endl;
    }
}

// --- Persistência (Mantendo seu código original de Usuarios) ---
void Biblioteca::salvarUsuariosEmArquivo(const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        std::cout << "Erro ao salvar arquivo." << std::endl;
        return;
    }
    for (auto const& pair : _usuarios) {
        Usuario* u = pair.second;
        char tipo = (u->getTipo() == "Aluno") ? 'A' : 'P';
        arquivo << tipo << "," << u->getNome() << "," 
                << u->getMatricula() << "," << u->getEmail() << "\n";
    }
    arquivo.close();
}

void Biblioteca::carregarUsuariosDoArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) return;

    std::string linha;
    while (std::getline(arquivo, linha)) {
        std::stringstream ss(linha);
        std::string tipoStr, nome, matriculaStr, email;
        
        std::getline(ss, tipoStr, ',');
        std::getline(ss, nome, ',');
        std::getline(ss, matriculaStr, ',');
        std::getline(ss, email, ',');

        if (tipoStr.empty() || matriculaStr.empty()) continue;
        
        int matricula = std::stoi(matriculaStr);
        Usuario* novo = nullptr;
        if (tipoStr == "A") novo = new Aluno(nome, matricula, email);
        else if (tipoStr == "P") novo = new Professor(nome, matricula, email);

        if (novo) cadastrarUsuario(novo);
    }
    arquivo.close();
}
#include "Biblioteca.hpp"
#include "Usuario.hpp"
#include "Aluno.hpp"
#include "Professor.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


//----------------Instancias da Classe Usuario e Subclasses - Guilherme----------------
Biblioteca::Biblioteca() {}
Biblioteca::~Biblioteca() {
    for (auto const& pair : _usuarios) {
        delete pair.second;
    }
    _usuarios.clear();
}

void Biblioteca::cadastrarUsuario(Usuario* usuario) {
    if (_usuarios.count(usuario->getMatricula()) > 0) {
        std::cout << "Erro: Matricula ja existente. " << std::endl;
        return;
    }
    _usuarios[usuario->getMatricula()] = usuario;
}

void Biblioteca::removerUsuario (int matricula) {
    auto it = _usuarios.find(matricula);
    if (it != _usuarios.end()) {
        Usuario* u = it->second;

        if (u->verificaPendencias()) {
            std::cout << "Erro: Ha pendencias." << std::endl;
            return;
        }

        std::string nomeBackup = u->getNome();

        delete u;
        _usuarios.erase(it);
        std::cout << "Usuario " << nomeBackup << " Deletado" << std::endl;
    }
    else {
        std::cout << "Usuario nao encontrado. " << std::endl;
    }
}

Usuario* Biblioteca::buscarUsuario (int matricula)  {
    auto it = _usuarios.find(matricula);
    if (it != _usuarios.end()) {
        return it->second; //aqui retorna o *Usuario
    }
    return nullptr; //nao achou
}

void Biblioteca::listarUsuarios() const {
    for (auto const& pair : _usuarios) {
        Usuario* u = pair.second; //o valor é ponteiro
        std::cout << u->getMatricula() << " - " << u->getNome() << std::endl;
    }
}

void Biblioteca::salvarUsuariosEmArquivo(const std::string& nomeArquivo) {
    std::ofstream arquivo(nomeArquivo); // abre arqiuvo para escrita

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir arquivo para escrita." << std::endl;
        return;
    }

    for (auto const& pair : _usuarios) {
        Usuario* u = pair.second;

        char tipo = (u->getTipo() == "Aluno") ? 'A' : 'P'; //define um caracter para tipo (A ou P)
        arquivo << tipo << "," // Escreve no formato: TIPO,NOME,MATRICULA,EMAIL
                << u->getNome() << ","
                << u->getMatricula() << ","
                << u->getEmail() << "\n";
    }
    arquivo.close();
    std::cout << "Banco de dados salvo com sucesso!" << std::endl;
}

void Biblioteca::carregarUsuariosDoArquivo(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo); //abre pra leitura
    if (!arquivo.is_open()) {
        std::cout << "Arquivo nao encontrado (primeira execucao?). Criando novo..." << std::endl;
        return;
    } 

    std::string linha;
    while (std::getline(arquivo, linha)) { // Lê linha por linha até o fim do arquivo
        std::stringstream ss(linha);
        std::string dado;

        //var temporarias para leitura
        std::string tipoStr, nome, matriculaStr, email;

        //le separado por virgulas
        std::getline(ss, tipoStr, ',');
        std::getline(ss, nome, ',');
        std::getline(ss, matriculaStr, ',');
        std::getline(ss, email, ',');

        if (tipoStr.empty() || matriculaStr.empty()) continue; //linha vazia ou invalida

        int matricula = std::stoi(matriculaStr); //converte string para inteiro

        Usuario* novoUsuario = nullptr;
        if (tipoStr == "A") {
            novoUsuario = new Aluno(nome, matricula, email);
        }
        else if (tipoStr == "P") {
            novoUsuario = new Professor(nome, matricula, email);
        }

        if (novoUsuario != nullptr) {
            this->cadastrarUsuario(novoUsuario);
        }
    }
    arquivo.close();
    std::cout << "Banco de Dados Carregado" << std::endl;
}
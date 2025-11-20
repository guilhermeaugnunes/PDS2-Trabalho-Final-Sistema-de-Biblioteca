#include "Biblioteca.hpp"
#include "Usuario.hpp"
#include <iostream>


//----------------Instancias da Classe Usuario - Guilherme----------------
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
            std::cout << "Erro: Ha endencias." << std::endl;
            return;
        }

        delete u;
        _usuarios.erase(it);
        std::cout << "Usuario Deletado" << std::endl;
    }
    else {
        std::cout << "Usuario nao encontrado. " << std::endl;
    }
}
Usuario* Biblioteca::buscarUsuario (int matricula)  {

}
void Biblioteca::listarUsuarios() const  {}

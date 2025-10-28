# Sistema de Gestão de Biblioteca

**Projeto Final da disciplina de Programação e Desenvolvimento de Software 2.**

**Membros do Grupo:**
* Gabriel dos Reis Rezende da Silva
* Guilherme Augusto Nunes
* Gustavo Loureiro Muller Netto
* Isabel Goncalves Magalhaes
* Paulo Henrique Soares Gomes

---

## 1. O Problema

O objetivo deste projeto é criar um sistema simples para gerenciar as operações básicas de uma biblioteca, como o cadastro de livros e usuários, e o controle de empréstimos e devoluções. A ideia é substituir um sistema manual por uma solução digital básica em C++.

---

## 2. A Solução Proposta

O programa foi desenvolvido em C++11, seguindo os princípios da Programação Orientada a Objetos.

A arquitetura é baseada em classes que representam as entidades de uma biblioteca: `Livro`, `Usuário` (com as subclasses `Aluno` e `Professor`), `Empréstimo`, `Reserva` e a classe principal `Biblioteca`, que gerencia as interações.

**Funcionalidades Implementadas:**
* Cadastro e consulta de livros e usuários.
* Sistema de empréstimo e devolução.
* Fila de reserva para livros emprestados.
* Notificações internas no sistema (ex: sobre devoluções).

### Como Compilar e Executar

O projeto usa um `Makefile` para automatizar a compilação.

**Para compilar e executar o programa:**
```bash
make run
```

**Para limpar os arquivos compilados:**
```bash
make clean
```

---
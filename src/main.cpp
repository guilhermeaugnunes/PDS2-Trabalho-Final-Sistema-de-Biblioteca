#include <iostream>
#include <string>
#include "Aluno.hpp"
#include "Professor.hpp"

int main () {

    Usuario* alunoHeap = new Aluno("Guilherme Nunes", 2024017015, "guilhermeaugnunes@ufmg.br");
    Professor* profHeap = new Professor("Vitor Angelo", 123456, "vitortorres@elt.ufmg.br");

    std::cout << "----- Teste Aluno Heap-----" << std::endl;
    std::cout << "Nome: " << alunoHeap->getNome() << std::endl;
    std::cout << "Tipo: " << alunoHeap->getTipo() << std::endl;
    std::cout << "Matricula: " << alunoHeap->getMatricula() << std::endl;
    std::cout << "Limite: " << alunoHeap->limiteEmprestimo() << std::endl;

    std::cout << "\n----- Teste Professor Heap -----" << std::endl;
    std::cout << "Nome: " << profHeap->getNome() << std::endl;
    std::cout << "Tipo: " << profHeap->getTipo() << std::endl;
    std::cout << "Matricula: " << profHeap->getMatricula() << std::endl;
    std::cout << "Limite: " << profHeap->limiteEmprestimo() << std::endl;

    ////////////////////teste via stack

    Aluno alunoStack("Joao Silva", 12345, "joao@ufmg.br");
    Professor profStack("Ana Costa", 67890, "ana@dcc.ufmg.br");

    Usuario& alunoRef = alunoStack;
    Usuario& profRef = profStack;

    std::cout << "\n\n----- Teste Aluno Stack-----" << std::endl;
    std::cout << "Nome: " << alunoRef.getNome() << std::endl;
    std::cout << "Tipo: " << alunoRef.getTipo() << std::endl;
    std::cout << "Matricula: " << alunoRef.getMatricula() << std::endl;
    std::cout << "Limite: " << alunoRef.limiteEmprestimo() << std::endl;

    std::cout << "\n\n----- Teste Professor Stack-----" << std::endl;
    std::cout << "Nome: " << profRef.getNome() << std::endl;
    std::cout << "Tipo: " << profRef.getTipo() << std::endl;
    std::cout << "Matricula: " << profRef.getMatricula() << std::endl;
    std::cout << "Limite: " << profRef.limiteEmprestimo() << std::endl;
    
    return 0;
}
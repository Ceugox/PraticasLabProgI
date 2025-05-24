#include <iostream>
#include <string>

using namespace std;

class Animal{
protected:
    string especie;
public:
    Animal(){}
   virtual ~Animal(){} // Aprendizado novo: Em herança com polimorfismo, o destrutor da classe base deve ser virtual, para que o destrutor correto seja chamado se eu deletar um objeto via ponteiro de Animal
    virtual void falar ()=0;// Não esquecer do bendito =0

};
class Cachorro:public Animal{
public:
    Cachorro(){this->especie="Cachorro";}
    void falar() override{
    cout<<"O:"<<Animal::especie<<"Faz au au"<<endl;
    };
};
class Gato:public Animal{
    public:
    Gato(){this->especie="Gato";}
    void falar()override{
        cout<<"O:"<<Animal::especie<<" faz miau miau"<<endl;
    }

};

int main (){
Cachorro Mac;//Erro clássico-> "Most Verxing Parse-> Se não atribui nada, não precisa do parêntese para instanciar objetos
Gato DeBotas;

Mac.falar();
DeBotas.falar();





return 0;
}

/*Aqui vale uma nota sobre destrutores das subclasses em herança com polimorfismo:| Situação                                                           | Criar destrutor?                     |
| ------------------------------------------------------------------ | ------------------------------------ |
| Subclasse aloca memória dinâmica (`new`, `malloc`, arquivos, etc.) | ✅ Sim                                |
| Quer ver mensagens de debug para aprender                          | ✅ Sim (útil para estudo)             |
| Subclasse não aloca nada especial                                  | ❌ Não precisa (o padrão já funciona) |
*/


#include<iostream>
#include<vector>
#include<fstream>
#include <string>
#include <algorithm>
using namespace std;

class Candidato{
string nome;
string partido;
int numero;
int qtdVotos;
public:
    float percentual;
    //Construtor:
    Candidato(string nome="",string partido="",int numero=0,int qtdVotos=0):nome(nome),partido(partido),numero(numero),qtdVotos(qtdVotos){}

    //Destrutor:
    ~Candidato (){}

    //Getters:
    string getNome()const {return nome;}
    string getPTD()const {return partido;}
    int getNumero()const {return numero;}
    int getQtdVotos()const {return qtdVotos;}
    // Método para adicionar os votos:

    void somaVotos(){qtdVotos++;}

    //Sobrecarga do operador "<<" para impressão dos candidatos:
    friend ostream& operator<<(ostream& os, const Candidato& c);
};
//Só usar friend na declaração do método dentro da classe:
    ostream& operator<<(ostream& os, const Candidato& c) {
    os << c.getNome() << " -- " <<c.getPTD()<<"---"<< c.getNumero()<<"---"<<"Com "<<c.getQtdVotos()<<" votos ";
    return os;
}
int main(){
    //Montando um vetor de candidatos:
    vector <Candidato> candidatos;
ifstream arquivo("candidatos.txt");
//Testar a abertura do arquivo:
if(!arquivo.is_open()){
cerr<<"Erro na abertura do arquivo!"<<endl;
return 1;
}
//Vamos a leitura do arquivo em si:
int numero;
string nome, partido;
Candidato c;

while (arquivo >> numero >> nome >> partido) {
    candidatos.push_back(Candidato(nome,partido,numero));
}
//Leitura dos votos:
for(int i=1;i<5;i++){
    //EUREKA!EUREKA!
    //O uso do + vale-se de uma sobrecarga da própria biblioteca padrão, permitindo a concatenação de strings sem o operator+
    //To_string faz a conversão para string, formando o nome do arquivo:
string nomearquivo="urna"+ to_string(i)+".txt";
ifstream arquivo(nomearquivo);
if(!arquivo.is_open()){
    cerr<<"Stop the count, urna vandalizada!"<<endl;
    continue;//Usado para ir para o próximo arquivo
}
int voto;
while(arquivo>>voto){
        for(Candidato& c:candidatos)
    if(voto==c.getNumero()){
        c.somaVotos();
        break;//Para aqui para não gerar problemas com loop infinito;
    }
}

}
//Ordenação dos candidatos por número de votos usando sort:
sort(candidatos.begin(),candidatos.end(),[](const Candidato& A1, const Candidato& A2)
{ return A1.getQtdVotos()>A2.getQtdVotos();});
//Cálculo do percentual:
int votostotais=0;
for (const Candidato& c:candidatos){
         votostotais+=c.getQtdVotos();
}
float percentual=0;
    //Impressão de todos os candidatos:
for (const Candidato& c:candidatos){
         percentual=c.getQtdVotos()*100.0/votostotais;//.0 aqui para garantir a precisão na impressão do percentual
//Possível pois eu sobrecarreguei o operador <<:
    cout<<c<<" representando: "<<percentual<<"% dos votos"<<endl;
}
arquivo.close();
return 0;
}

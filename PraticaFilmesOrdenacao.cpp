#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
#include<vector>
#define MAX 10
#define MIN 1

using namespace std;


class Filme{
    int numero;
    string nome;
    int qtdVotos;
public:
    //Construtor:
    Filme (int numero=0,string nome="",int qtdVotos=0):numero(numero),nome(nome),qtdVotos(qtdVotos){}
      //Destrutor:
    ~Filme(){}
    //Métodos de acesso:
    int getNumero()const{return numero;}
    string getNome()const{return nome;}
    int getQtdVotos()const{return qtdVotos;}
    //Método de contagem de votos:
    void ContaVotos(){qtdVotos++;}
    //Sobrecarga do operador <<:
friend ostream& operator<<(ostream& os,const Filme& f);
};
ostream& operator<<(ostream& os,const Filme& f) {
    os << f.getNome() << " -- " <<f.getQtdVotos()<<" votos ";
    return os;
}

int main(){
ifstream arquivoEntrada("Filmes a serem votados.txt");
//Testar abertura do arquivo:
if(!arquivoEntrada.is_open()){
    cerr<<"Erro na abertura do catálogo de filmes"<<endl;
    return 1;//Qualquer retorno diferente de 0
}
vector<Filme> filmes;
int numeroFilme=0;
string nomeFilme;
int qtdVotosfilme=0;
//Leitura dos dados do arquivo de cadastro dos filmes via loop while de verificação de leitura:
while(arquivoEntrada>>numeroFilme){
    getline(arquivoEntrada,nomeFilme);
    //Adicionando ao vetor de filmes:
    filmes.push_back(Filme(numeroFilme,nomeFilme));
}
int voto=0;
for(int i=MIN;i<=MAX;i++){
string nomearquivo="pote_votos_"+to_string(i)+".txt";
ifstream arquivoEntrada(nomearquivo);
if(!arquivoEntrada.is_open()){
    cerr<<"Erro na abertura da urna"<<endl;
    return 7;//Qualquer retorno diferente de 0
}
    while(arquivoEntrada>>voto)
    for (Filme &f:filmes){
        if(voto==f.getNumero()){
            f.ContaVotos();
            break;//Tem que parar o loop
        }
    }
}
sort(filmes.begin(),filmes.end(),[](const Filme& f1,const Filme& f2){
     return f1.getQtdVotos()>f2.getQtdVotos();
     });
     //Cálculo do total de votos:
     int votostotais=0;
     float percentual=0;
     for(const Filme& f:filmes){
        votostotais+=f.getQtdVotos();
     }
     for(const Filme& f:filmes){
        percentual=f.getQtdVotos()*100.0/votostotais;
        cout<<f<<","<<percentual<<"% dos votos"<<endl;
     }

arquivoEntrada.close();
return 0;
}

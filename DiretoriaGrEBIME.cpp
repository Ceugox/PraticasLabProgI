#include <iostream>

using namespace std;

//Alterei um pouco o enunciado para uma área que conheço um pouco melhor

//Boa prática para não ficar alterando em todo o código:
#define MAX 9
#define MIN 3


class Lider{
    const string nome;
    string ministerio;
   static int qtdLideres;//Existe apenas no escopo dessa classe, devendo ser inicializada fora da classe com o operador escopo::
   public:
    static bool encerramento; //Declarada para evitar a chamada das mensagens do destrutor no seu encerramento, também acessada fora da classe com operador escopo

    //Construtor:Aqui eu incremento a variável de classe(static) sempre que construir um novo objeto, incre
    Lider (string n1="",string m1="",bool notificador=true):nome(n1),ministerio(m1){
        qtdLideres++;
        if(notificador)verificadorDeLideranca(true);//O notificador funciona como um silenciador, para não acionar chamadas desnecessárias durante a criação dos objetos
    }
    Lider (const Lider &l){ //Construtor por cópia, sem modificar minha referência com uso do const-> Boa prática
        //nome=l.nome;->Esse cara é const, não posso fazer isso
        ministerio=l.ministerio;
        qtdLideres++;
        verificadorDeLideranca(true);
    }
    //Destrutor:Aqui eu destruo os objetos, então devo decrementar minha variável de classe
    ~Lider(){
       qtdLideres--;
      if(!encerramento) verificadorDeLideranca(false);//O ponto aqui é não ficar chamando durante a destruição natural dos objetos criados, por isso implementamos o bool encerramento
    }
    //Métodos verificadores da liderança:
    void  verificadorDeLideranca (bool chamada)const {
        if(chamada){ //Ou seja, quando a chamada tiver valor lógico "TRUE"
        if(qtdLideres>MAX){
            cout<<"Tamanho da liderança acima do ideal"<<endl;
        }
        }
        else{
        if(qtdLideres<MIN){
            cout<<"Tamanho da liderança abaixo do ideal"<<endl;
        }
        }
     }
         static void AvaliaQTD(){
        if(qtdLideres>9||qtdLideres<3){ //Agora só chamando nos casos necessários, para não gerar impressões desnecessárias
            cout<< "Numero de diretores diferente do previsto: ";}
            else{
            cout<< "Numero de diretores dentro do previsto: ";}
        cout << qtdLideres << endl; //Independente do caso, vou imprimir, afinal se ele entrar nesse método é pq o número não é o ideal
    }
    //Getters e setters:
    string getNome()const{return nome;}
    string getMinisterio()const{return ministerio;}
    //void setNome(string novoN){nome=novoN;}-> Fiz no automático
    void setMinisterio(string novoM){ministerio=novoM;}


};
int Lider::qtdLideres=0;
bool Lider::encerramento=false;
//Variáveis static, devem ser declaradas fora da classe e fora da main, podendo alterar seu valor dentro da main, dependendo da permissão

int main(){
    cout<<"Seja bem-vindo ao sistema de lideranca do"<<"\033[32m"<<" GrEBIME"<<"\033[0m"<<endl;
    Lider Rebeca("Rebeca Correia","Louvor");
    Lider Catulo("Catulo Axel","Logística");
    Lider Zuza("Zuza","Marketing");
    Lider Parra("Parra","Lideranca");
    Lider Barauna("Barauna","Lideranca");
    Lider Coimbra("Coimbra","Financeiro");

    //Salvar com alocação dinâmica:
    Lider **vetor=new Lider*[10];

    for(int i=0;i<MAX;i++){
        vetor[i]=new Lider("","",false);//new com []->delete[]
    }
    for(int i=0;i<MAX;i++){
        delete vetor [i];
    }
    //Agora basta desalocar o vetor de "ponteiros de ponteiros":

    delete [] vetor;
Lider::encerramento=true;//Declarando o encerramento do código
return 0;
}


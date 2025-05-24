#include <iostream>

using namespace std;

//Alterei um pouco o enunciado para uma �rea que conhe�o um pouco melhor

//Boa pr�tica para n�o ficar alterando em todo o c�digo:
#define MAX 9
#define MIN 3


class Lider{
    const string nome;
    string ministerio;
   static int qtdLideres;//Existe apenas no escopo dessa classe, devendo ser inicializada fora da classe com o operador escopo::
   public:
    static bool encerramento; //Declarada para evitar a chamada das mensagens do destrutor no seu encerramento, tamb�m acessada fora da classe com operador escopo

    //Construtor:Aqui eu incremento a vari�vel de classe(static) sempre que construir um novo objeto, incre
    Lider (string n1="",string m1="",bool notificador=true):nome(n1),ministerio(m1){
        qtdLideres++;
        if(notificador)verificadorDeLideranca(true);//O notificador funciona como um silenciador, para n�o acionar chamadas desnecess�rias durante a cria��o dos objetos
    }
    Lider (const Lider &l){ //Construtor por c�pia, sem modificar minha refer�ncia com uso do const-> Boa pr�tica
        //nome=l.nome;->Esse cara � const, n�o posso fazer isso
        ministerio=l.ministerio;
        qtdLideres++;
        verificadorDeLideranca(true);
    }
    //Destrutor:Aqui eu destruo os objetos, ent�o devo decrementar minha vari�vel de classe
    ~Lider(){
       qtdLideres--;
      if(!encerramento) verificadorDeLideranca(false);//O ponto aqui � n�o ficar chamando durante a destrui��o natural dos objetos criados, por isso implementamos o bool encerramento
    }
    //M�todos verificadores da lideran�a:
    void  verificadorDeLideranca (bool chamada)const {
        if(chamada){ //Ou seja, quando a chamada tiver valor l�gico "TRUE"
        if(qtdLideres>MAX){
            cout<<"Tamanho da lideran�a acima do ideal"<<endl;
        }
        }
        else{
        if(qtdLideres<MIN){
            cout<<"Tamanho da lideran�a abaixo do ideal"<<endl;
        }
        }
     }
         static void AvaliaQTD(){
        if(qtdLideres>9||qtdLideres<3){ //Agora s� chamando nos casos necess�rios, para n�o gerar impress�es desnecess�rias
            cout<< "Numero de diretores diferente do previsto: ";}
            else{
            cout<< "Numero de diretores dentro do previsto: ";}
        cout << qtdLideres << endl; //Independente do caso, vou imprimir, afinal se ele entrar nesse m�todo � pq o n�mero n�o � o ideal
    }
    //Getters e setters:
    string getNome()const{return nome;}
    string getMinisterio()const{return ministerio;}
    //void setNome(string novoN){nome=novoN;}-> Fiz no autom�tico
    void setMinisterio(string novoM){ministerio=novoM;}


};
int Lider::qtdLideres=0;
bool Lider::encerramento=false;
//Vari�veis static, devem ser declaradas fora da classe e fora da main, podendo alterar seu valor dentro da main, dependendo da permiss�o

int main(){
    cout<<"Seja bem-vindo ao sistema de lideranca do"<<"\033[32m"<<" GrEBIME"<<"\033[0m"<<endl;
    Lider Rebeca("Rebeca Correia","Louvor");
    Lider Catulo("Catulo Axel","Log�stica");
    Lider Zuza("Zuza","Marketing");
    Lider Parra("Parra","Lideranca");
    Lider Barauna("Barauna","Lideranca");
    Lider Coimbra("Coimbra","Financeiro");

    //Salvar com aloca��o din�mica:
    Lider **vetor=new Lider*[10];

    for(int i=0;i<MAX;i++){
        vetor[i]=new Lider("","",false);//new com []->delete[]
    }
    for(int i=0;i<MAX;i++){
        delete vetor [i];
    }
    //Agora basta desalocar o vetor de "ponteiros de ponteiros":

    delete [] vetor;
Lider::encerramento=true;//Declarando o encerramento do c�digo
return 0;
}


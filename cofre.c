#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    //Cria uma lista que contém uma senha e tambem cria uma variavel que armazena a resposta do usuario para a pergunta da tentativa de senha
    int senha[3] = {rand() % 9 ,rand() % 9, rand() % 9 };
    int senha_Do_Usuario;

    //Cria variaveis para armazenar cada elemento do numero que o usuario vai digitar
    int primeiro_numero;
    int segundo_numero;
    int terceiro_numero;

    //Cria variaveis para armazenar a posicao de cada elemento do numero que o usuario digitar
    int primeiro_pos_senha = 1;
    int segundo_pos_senha = 2;
    int terceiro_pos_senha = 3;

//loop que vai verificar fazer a verificacao de cada coisa
while(1){
    
    //cria variaveis que sao resetadas a cada iteracao e que servem para verificar se na lista tem aql numero em uma posicao x
    int primeira_pos_senha_usuario = -1;
    int segunda_pos_senha_usuario = -1;
    int terceira_pos_senha_usuario = -1;

    //inicializa a pergunta dos 3 digitos
    printf("\n\nDigite a combinacao de 3 digitos para abrir o cofre: ");
    scanf("%i", &senha_Do_Usuario);
    //loop para verificar e impedir caso o usuario digite uma senha com mais de 3 digitos
    while (1){
        if (senha_Do_Usuario > 999){
            printf("\n\nEntrada inválida. Tente novamente: ");
            scanf("%i", &senha_Do_Usuario);
        }else{
            break;
        }
    }

    //Separar os digitos da senha separada pelo usuario          
    primeiro_numero = senha_Do_Usuario / 100;
    segundo_numero = (senha_Do_Usuario % 100) / 10;
    terceiro_numero = senha_Do_Usuario % 10;
            
    //loop para definir a posicao de cada elemento do usuario e adiciona 1 por causa q o i comeca com 0
    for(int i = 0; i < 3; i++){
                
        if(primeiro_numero == senha[i]){
            primeira_pos_senha_usuario = i + 1;
        }
        if(segundo_numero == senha[i]){
            segunda_pos_senha_usuario = i + 1;
        }
        if(terceiro_numero == senha[i]){
            terceira_pos_senha_usuario = i + 1; 
        }
    }

    //Faz a verificacao de cada um dos 3 elementos que o usuario digitou para ver se ele acertou os numeros que estao na lista e a posicao se acertou verifica a posicao e se acertou a posicao tambem contabiliza o os dois acertos e se so o numero tiver certo o codigo avisa
    if(primeira_pos_senha_usuario != -1){
        if(primeira_pos_senha_usuario == primeiro_pos_senha){
            printf("\nO numero %d esta na lista e esta na posicao %d", primeiro_numero, primeira_pos_senha_usuario);
    }   else{
            printf("\nO numero %d esta na lista, mas nao esta na posicao certa", primeiro_numero);
    }
    }else{
        printf("\nO numero %d nao esta na lista", primeiro_numero);
    }


    if(segunda_pos_senha_usuario != -1){
        if(segunda_pos_senha_usuario == segundo_pos_senha){
            printf("\nO numero %d esta na lista e esta na posicao %d", segundo_numero, segunda_pos_senha_usuario);
    }   else{
            printf("\nO numero %d esta na lista, mas nao esta na posicao certa", segundo_numero);
    }
    }else{
        printf("\nO numero %d nao esta na lista", segundo_numero);
    }


    if(terceira_pos_senha_usuario != -1){
        if(terceira_pos_senha_usuario == terceiro_pos_senha){
            printf("\nO numero %d esta na lista e esta na posicao %d", terceiro_numero, terceira_pos_senha_usuario);
    }   else{
            printf("\nO numero %d esta na lista, mas nao esta na posicao certa", terceiro_numero);
    }
    }else{
        printf("\nO numero %d nao esta na lista", terceiro_numero);
    }
    //Aqui ele vai fazer uma condiçao de vitoria e verificar se o usuario acertou todos os numeros e se sim ele vence
    if (primeira_pos_senha_usuario == primeiro_pos_senha && segunda_pos_senha_usuario == segundo_pos_senha && terceira_pos_senha_usuario == terceiro_pos_senha) {
        printf("\n\nParabens, voce achou a senha do cofre!");
        break;
}

}
return 0;
}

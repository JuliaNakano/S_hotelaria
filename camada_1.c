#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>
#define  N 201 //estou ciente dos riscos porem é uma mão na massa para caso precisamos adicionar mais caracteres


//talvez possa colocar elas em outro arquivo e referenciar aqui....

 /* as struct só estão armazenando variaveis, não recebe dados 
    ao longo da necessidade talves precise ajeitar isso, fica de lembrete gatenha....*/
    /* o codigo é algo em comum para identificação exemplo cliente 0001, es no quarto 0102*/

    //essa tem por função receber os códigos únicos
    // sequencial de 0 a 100;
    typedef struct codigo{
        char cd_unico[04];
    } codigo;
    //endereçõs generico tambem.
    typedef struct endereco{
        char nm_rua[N], nm_bairro[N], nr_casa[04];
    }endereco;
    
    /*struct de dados pessoais, que vai ser utilizada em hotel, fornecedores e  hospedes 
    não esquecer que esse nome pode ser razão social, só mudar a saida de dados  tambem.*/ 
    typedef struct {
       codigo codigo01;
       endereco endereco01;
        char nome[N], nr_tel[13], email[N];
    }d_pessoais;
    
    //generica 
    typedef struct {
        codigo codigo02;
        char  ds[401];
    }gn;
    
    // informações dos forncedores 
    typedef struct{
        
        d_pessoais d_pessoais01;
        char name_fan[N],  insc_estudual[13], cnpj[15];
    }If_forn;
    
    //informações do hotel
    typedef struct {
        If_forn if_forn;

        char nm_respon[N], nr_tlf_resp[13];
        int tm_hour_in, tm_hour_out;
        float mg_lucro;
    }If_hotel;

    //hospede
    typedef struct {
        d_pessoais d_pessoais03;
        char cpf[12], sexo, est_civil, dt_nasc[9]; //dar opções 1, 2, 3, 4 e 5
        /*1- solteiro(a)
        2- casado(a)
        3- divorciado(a)
        4- viuvo(a)
        5- prefiro não comentar....*/
    }hospede;

    //Categoria de acomodação
    typedef struct{
        gn gn1;
        float vl_diaria;
        int quant_pess;/* quantidade de pessoas por quarto crianças e adultos  */
    }ctg_acomodacao;
    
    //Acomodações --ARRUMAR--
    typedef struct {
        gn gn2;
        char facd[N]; //coisas que a acomodação possui ex: tv, 
        char cat;
         //como colocar a categoria de acomodação aqui de um jeito que não fique estranho..... 
    }comodacao;

    //Operadores de sistema 
    typedef struct {
        codigo codigo03;
        char nm[200], use[10], senha[8], perm; //por enquanto opção 1 para todas as permissoes, 2 para restrições
        //estruturar melhor isso. 

    }op_sistema;
   
int main()
{
    If_hotel if_hotel;
// apresentação do sistema 

printf("\n");
printf(" --------------------------------------------------- \n");
printf(" Seja bem vindo ao 'Sistema Devaneio'\n");
printf(" --------------------------------------------------- \n");
printf(" Aqui oferecemos um controle completo do seu hotel \n");
printf(" --------------------------------------------------- \n");
printf(" Para comecar por favor se cadastre\n");
printf(" --------------------------------------------------- \n");
printf("\n");

// Cadastro do Hotel, lembrando que o usuario só fara o mesmo uma vez...... 
printf("Digite as seguintes informacoes\n");
printf("------------------------------\n");
printf("\tDados do hotel \n");
printf("------------------------------\n");
printf("\n");
printf("Nome fantasia:");
fgets(if_hotel.if_forn.name_fan, N, stdin);
printf("Razão social:");
scanf("%s", if_hotel.if_forn.d_pessoais01.nome);
printf("Inscricao estadual: ");
fgets(if_hotel.if_forn.insc_estudual, 13, stdin);
printf("CNPJ: ");
scanf("%d", &if_hotel.if_forn.cnpj);

printf("\n");
printf(" --------------------------------------------------- \n");
printf("     Digite o endreco  do hotel completo...\n");
printf(" --------------------------------------------------- \n");
printf("Rua: ");
scanf("%s", &if_hotel.if_forn.d_pessoais01.endereco01.nm_rua);
printf("numero: ");
scanf("%s", &if_hotel.if_forn.d_pessoais01.endereco01.nr_casa);
printf("Bairro:");

scanf("%s", &if_hotel.if_forn.d_pessoais01.endereco01.nm_bairro);
printf("Telefone: ");
scanf("%d", if_hotel.if_forn.d_pessoais01.nr_tel);
printf("Email:");

scanf("%s",if_hotel.if_forn.d_pessoais01.email);
printf("Nome do responsavel:");
fgets(if_hotel.nm_respon, N,stdin);
printf("Numero do responsavel: ");
scanf("%s", if_hotel.nr_tlf_resp);
printf("Horario de check-in:");
scanf("%d", &if_hotel.tm_hour_in);
printf("Horario de check-out:");
scanf("%d", &if_hotel.tm_hour_out);
printf("Margem de lucro de produtos vendidos: %%");
scanf("%f",  &if_hotel.mg_lucro);

}

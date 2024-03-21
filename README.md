#INTRODUÇÃO 

O objetivo desse relatório é introduzir e explicar os conceitos básicos sobre chamadas do sistemas, especificando os conceitos de criação(‘fork()’) e de mudança(‘exec()’). 
As chamadas de sistema são essenciais para criar e manipular processos em sistemas operacionais. Elas fornecem uma interface entre os programas e o núcleo do sistema, permitindo que os desenvolvedores solicitem serviços específicos, como criação e gerenciamento de processos. Isso garante um ambiente de execução seguro e eficiente, controlando o acesso aos recursos do sistema e mantendo a estabilidade e confiabilidade do sistema operacional. 

##CHAMADAS DO SISTEMA PARA A CRIAÇÃO DE PROCESSOS 

-> fork()= Essa função fork é uma das mais comuns nos sistemas operacionais como linux(UNIX) e macOS(POSIX), utilizada para a criação de um novo processo, conhecido como processo filho que é uma cópia do processo pai. 

->Exemplos = pid_t pid = fork(); 
if (pid == 0) { 
    // Código para o processo filho 
} else if (pid > 0) { 
    // Código para o processo pai 
} else { 
    // Tratamento de erro 
} 

->Processo filho e pai = A função fork() em sistemas operacionais cria dois processos distintos: o processo pai e o processo filho. A principal diferença entre eles reside no valor retornado pela chamada fork() e em como o código é executado em cada um deles. 
No processo pai o valor de retorno é o PID(identificador do processo), já no processo filho o valor de retorno é 0. Nessas duas ocasiões a finalização dos processos não interferam um ao outro; 

##CHAMADAS DO SISTEMA PARA MUDANÇA DE ESTADO DE PROCESSOS 

->exec() =  a função é utilizada para carregar e executar um novo programa em um processo existente, substituindo o conteudo do processo atual pelo novo programa. 

->variantes da função exec()=      exec1(): Permite passar argumentos ao novo programa como uma lista de argumentos separados por vírgula. 

    execv(): Permite passar argumentos ao novo programa como um vetor de strings terminado por NULL. 

    execle(): Similar ao execl(), mas também permite definir o ambiente do novo programa. 

    execvp(): Procura pelo programa especificado nos diretórios do PATH do sistema. 

    execvpe(): Similar ao execvp(), mas também permite definir o ambiente do novo programa. 

##CONCLUSAO 

-> Neste relatório, exploramos as chamadas do sistema para criação e manipulação de processos em sistemas Linux, implementadas em C. Destacamos duas chamadas cruciais: fork() e exec(). A chamada fork() é fundamental para a criação de processos, enquanto exec() é utilizada para substituir o conteúdo de um processo por um novo programa. 

A compreensão dessas chamadas é essencial para desenvolver programas eficientes e robustos em sistemas operacionais. Elas desempenham um papel vital na gestão de recursos do sistema e na criação de aplicativos poderosos. 

Em conclusão, este relatório enfatizou a importância das chamadas do sistema para criação e manipulação de processos. Para estudos futuros, recomenda-se explorar a sincronização de processos, comunicação interprocessual e gerenciamento avançado de recursos, aspectos cruciais para o desenvolvimento de software de qualidade em ambientes operacionais diversos. 

##CODIGO ( arquivo c em anexo ) 

-> EXPLICADO ATRAVES DE COMENTARIOS. 
//
 

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int main() {
    pid_t pid;
    int status;

    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Falha ao criar o processo filho\n");
        return 1;
    } else if (pid == 0) {
        // Processo filho
        printf("Processo filho criado com PID: %d\n", getpid());
        printf("Processo filho aguardando...\n");

        // Loop infinito
        while (1) {
            sleep(1);
        }
    } else {
        // Processo pai
        printf("Este é o processo pai com PID: %d\n", getpid());
        printf("Processo filho criado com PID: %d\n", pid);
        printf("Pressione Enter para enviar um sinal SIGSTOP para o processo filho e Enter novamente para continuar.\n");
        getchar(); // Espera o usuário pressionar Enter

        // Envio de sinal SIGSTOP para parar o processo filho
        printf("Enviando sinal SIGSTOP para o processo filho...\n");
        kill(pid, SIGSTOP);

        printf("Pressione Enter para enviar um sinal SIGCONT para o processo filho e Enter novamente para continuar.\n");
        getchar(); // Espera o usuário pressionar Enter

        // Envio de sinal SIGCONT para continuar o processo filho
        printf("Enviando sinal SIGCONT para o processo filho...\n");
        kill(pid, SIGCONT);

        // Espera o processo filho terminar e obtém o status de saída
        wait(&status);
        if (WIFEXITED(status)) {
            printf("Processo filho terminou normalmente com status %d\n", WEXITSTATUS(status));
        } else if (WIFSIGNALED(status)) {
            printf("Processo filho terminou devido a um sinal com número %d\n", WTERMSIG(status));
        }
    }

    return 0;
}


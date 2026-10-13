Cadastro de produtos em C

Trabalho AT1 de Logica de Programacao e Algoritmos.

Integrantes: Murilo Leonan, Renan Lucas e Tiago de Souza Mouta.

O programa permite cadastrar, consultar, listar, alterar e excluir produtos pelo terminal.
Cada produto possui codigo, nome, preco e quantidade. O limite e de 20 produtos.

Para usar no Windows de 64 bits, baixe cadastro.exe e abra com dois cliques.
O executavel ja esta pronto. Nao e necessario instalar um compilador.

Para executar no terminal do VS Code no Windows:
.\cadastro.exe

Se alterar main.c, sera necessario compilar novamente para atualizar o executavel.
Com GCC instalado, use:
gcc main.c -o cadastro.exe

Digite numeros nas opcoes do menu, nos codigos, nos precos e nas quantidades.
Use um codigo diferente para cada produto.
Digite nomes sem espacos, com ate 49 caracteres. Exemplo: Mouse_sem_fio.
Use ponto nos precos. Exemplo: 59.90.
A opcao 0 encerra o programa. Os cadastros ficam apenas na memoria e sao perdidos ao sair.

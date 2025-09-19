# Máquina de Chopp com PIC16F628A

Projeto desenvolvido para simular uma máquina de chopp utilizando o microcontrolador PIC16F628A e o compilador mikroC. O sistema permite ao usuário selecionar o tipo e o tamanho da bebida, acionando LEDs pelo tempo correspondente. Foi inicialmente simulado no PicSimLab e depois montado fisicamente em protoboard.

## Descrição
Após a inicialização, o sistema exibe uma mensagem de boas-vindas no display LCD.  
O usuário escolhe:
- A bebida (entre 4 opções)
- O tamanho (Pequeno, Médio ou Grande)

O LED da bebida acende pelo tempo definido conforme o tamanho escolhido e o sistema retorna ao estado inicial.

## Componentes Utilizados
- PIC16F628A  
- Display LCD 16x2  
- 2 botões (RB0 e RB1)  
- LEDs (PORTA)  
- Resistores  
- Protoboard  
- Fonte 5 V  
- Cabos de conexão

## Tempos de Enchimento
- Pequeno: 3 segundos  
- Médio: 5 segundos  
- Grande: 7 segundos

## Simulação
- Código-fonte compilado no mikroC  
- Arquivo de configuração do PicSimLab (`Pic chopp.pcf`)  
- Código compilado em `.hex` (`Pic chopp.hex`)

## Instruções de Uso
1. Ligar o sistema (mensagem "Bem vindo!" aparece no LCD)  
2. Pressionar RB0 para alternar entre 4 tipos de bebida  
3. Pressionar RB1 para selecionar a bebida  
4. Pressionar RB0 para alternar entre Pequeno, Médio e Grande  
5. Pressionar RB1 para confirmar o tamanho  
6. O LED acende pelo tempo correspondente  
7. Sistema retorna ao início para nova operação

## Conclusão
O projeto atendeu aos requisitos propostos, permitindo trabalhar com lógica sequencial, controle de tempo e uso de LCD no PIC16F628A, proporcionando experiência prática em sistemas embarcados interativos.

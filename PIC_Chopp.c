// LCD module connections
sbit LCD_RS at RA2_bit;
sbit LCD_EN at RA3_bit;
sbit LCD_D4 at RA4_bit;
sbit LCD_D5 at RA5_bit;
sbit LCD_D6 at RA6_bit;
sbit LCD_D7 at RA7_bit;
sbit LCD_RS_Direction at TRISA2_bit;
sbit LCD_EN_Direction at TRISA3_bit;
sbit LCD_D4_Direction at TRISA4_bit;
sbit LCD_D5_Direction at TRISA5_bit;
sbit LCD_D6_Direction at TRISA6_bit;
sbit LCD_D7_Direction at TRISA7_bit;
// Fim conexões LCD

// Definições dos botões
#define BTN_NAVIGATE RA0_bit
#define BTN_SELECT   RA1_bit

// Dados
char *bebidas[] = {"Brahma  ", "Asahi   ", "IPA     ", "S Alcool"};
char *tamanhos[] = {"Pequeno", "Medio  ", "Grande "};
unsigned short tempos[] = {3, 5, 7}; // tempos em segundos

// Prototipação
void greetUser();
unsigned short selectBeverage();
unsigned short selectSize();

void main() {
    unsigned short bebida, tamanho, tempo;
    unsigned short i;

    CMCON = 0x07;       // Desabilita comparadores
    TRISA = 0b00000011; // RA0 e RA1 como entradas
    TRISB = 0x00;       // PORTB como saída
    PORTB = 0x00;

    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);

    greetUser();

    while(1) {
        bebida = selectBeverage();
        tamanho = selectSize();
        tempo = tempos[tamanho];

        
        Lcd_Cmd(_LCD_CLEAR);
        Lcd_Out(1, 1, bebidas[bebida]);
        Lcd_Out(2, 1, tamanhos[tamanho]);

        PORTB = 1 << bebida; // Acende LED correspondente
        

        for (i = 0; i < tempo; i++) {
            Delay_ms(1000);  // Espera 1 segundo a cada loop
        }

        PORTB = 0x00;       // Apaga LED
        Delay_ms(1000);     // Pausa antes de reiniciar
    }
}

void greetUser() {
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Out(1,1,"Bem-vindo!");
    Lcd_Out(2,1,"");
    Delay_ms(5000);
}

unsigned short selectBeverage() {
    unsigned short opcao = 0;

    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Out(1,1,"Escolha o chopp:");

    while(1) {
        Lcd_Out(2,1,bebidas[opcao]);

        if (!BTN_NAVIGATE) {
            Delay_ms(300);
            while (!BTN_NAVIGATE);
            Delay_ms(300);
            opcao = (opcao + 1) % 4;
        }

        if (!BTN_SELECT) {
            Delay_ms(300);
            while (!BTN_SELECT);
            Delay_ms(300);
            return opcao;
        }
    }
}

unsigned short selectSize() {
    unsigned short opcao = 0;

    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Out(1,1,"Tamanho bebida:");

    while(1) {
        Lcd_Out(2,1,tamanhos[opcao]);

        if (!BTN_NAVIGATE) {
            Delay_ms(300);
            while (!BTN_NAVIGATE);
            Delay_ms(300);
            opcao = (opcao + 1) % 3;
        }

        if (!BTN_SELECT) {
            Delay_ms(300);
            while (!BTN_SELECT);
            Delay_ms(300);
            return opcao;
        }
    }
}
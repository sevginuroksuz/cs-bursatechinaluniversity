ORG 100h

start:
    ; 10 adet 32-bit say� belle�e yerle�tirilir
    MOV WORD PTR [0200h], 1234h
    MOV WORD PTR [0202h], 5678h
    MOV WORD PTR [0204h], 9ABCh
    MOV WORD PTR [0206h], 0DEF0h
    MOV WORD PTR [0208h], 1357h
    MOV WORD PTR [020Ah], 2468h
    MOV WORD PTR [020Ch], 1122h
    MOV WORD PTR [020Eh], 3344h
    MOV WORD PTR [0210h], 5566h
    MOV WORD PTR [0212h], 7788h

    ; Parity sonu�lar� 0300h adresinden itibaren saklanacak
    MOV CX, 10             ; D�ng� sayac�
    MOV SI, 0200h          ; Ba�lang�� adresi
    MOV DI, 0300h          ; Parity sonu�lar�n�n yaz�laca�� adres

check_parity:
    ; 32-bit say�y� bellekte oku
    MOV AX, [SI]           ; Alt 16 bit
    MOV BX, [SI+2]         ; �st 16 bit
    XOR AX, BX             ; 32-bit XOR ile parity kontrol�

    ; Bitleri say ve parity bilgisi olu�tur
    MOV DX, AX             ; Sonu� DX'e kopyalan�r
    XOR AL, AL             ; AL'i s�f�rla (bit sayac�)
bit_count_loop:
    SHR DX, 1              ; Sa�a kayd�r
    JNC no_increment       ; E�er ta��ma yoksa atla
    INC AL                 ; E�er ta��ma varsa AL'i art�r
no_increment:
    CMP DX, 0              ; T�m bitler i�lendi mi?
    JNZ bit_count_loop     ; Hay�rsa d�ng�ye devam et

    ; AL'deki bit say�s� tek mi �ift mi kontrol et
    TEST AL, 1             ; LSB'yi kontrol et
    JZ even_parity         ; �ift ise atla
    MOV BYTE PTR [DI], 01h ; Tek parity: 01h yaz
    JMP next_number
even_parity:
    MOV BYTE PTR [DI], 00h ; �ift parity: 00h yaz

next_number:
    ADD SI, 4              ; Sonraki 32-bit say�ya ge�
    INC DI                 ; Parity sonucunun adresini ilerlet
    LOOP check_parity       ; D�ng�ye devam et

main_loop:
    ; Kullan�c�dan giri� al ve parity bilgisini g�ster
    IN AL, 110             ; Port 110'dan giri� al
    SUB AL, 1              ; S�f�r tabanl� indeks i�in
    CMP AL, 0Ah            ; Ge�erli giri� mi kontrol et
    JAE main_loop          ; Ge�ersizse tekrar giri� al

    ; Parity bilgisini ��k�� portuna yaz
    MOV SI, 0300h          ; Parity sonu�lar�n�n ba�lang�� adresi
    ADD SI, AX             ; Kullan�c� giri�ine g�re adresi ayarla
    MOV AL, [SI]           ; Parity bilgisini al
    OUT 199, AL            ; Parity bilgisini port 199'a yaz
    JMP main_loop          ; Tekrar giri� bekle

END start
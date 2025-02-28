ORG 100h

start:
    ; 10 adet 32-bit sayý belleðe yerleþtirilir
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

    ; Parity sonuçlarý 0300h adresinden itibaren saklanacak
    MOV CX, 10             ; Döngü sayacý
    MOV SI, 0200h          ; Baþlangýç adresi
    MOV DI, 0300h          ; Parity sonuçlarýnýn yazýlacaðý adres

check_parity:
    ; 32-bit sayýyý bellekte oku
    MOV AX, [SI]           ; Alt 16 bit
    MOV BX, [SI+2]         ; Üst 16 bit
    XOR AX, BX             ; 32-bit XOR ile parity kontrolü

    ; Bitleri say ve parity bilgisi oluþtur
    MOV DX, AX             ; Sonuç DX'e kopyalanýr
    XOR AL, AL             ; AL'i sýfýrla (bit sayacý)
bit_count_loop:
    SHR DX, 1              ; Saða kaydýr
    JNC no_increment       ; Eðer taþýma yoksa atla
    INC AL                 ; Eðer taþýma varsa AL'i artýr
no_increment:
    CMP DX, 0              ; Tüm bitler iþlendi mi?
    JNZ bit_count_loop     ; Hayýrsa döngüye devam et

    ; AL'deki bit sayýsý tek mi çift mi kontrol et
    TEST AL, 1             ; LSB'yi kontrol et
    JZ even_parity         ; Çift ise atla
    MOV BYTE PTR [DI], 01h ; Tek parity: 01h yaz
    JMP next_number
even_parity:
    MOV BYTE PTR [DI], 00h ; Çift parity: 00h yaz

next_number:
    ADD SI, 4              ; Sonraki 32-bit sayýya geç
    INC DI                 ; Parity sonucunun adresini ilerlet
    LOOP check_parity       ; Döngüye devam et

main_loop:
    ; Kullanýcýdan giriþ al ve parity bilgisini göster
    IN AL, 110             ; Port 110'dan giriþ al
    SUB AL, 1              ; Sýfýr tabanlý indeks için
    CMP AL, 0Ah            ; Geçerli giriþ mi kontrol et
    JAE main_loop          ; Geçersizse tekrar giriþ al

    ; Parity bilgisini çýkýþ portuna yaz
    MOV SI, 0300h          ; Parity sonuçlarýnýn baþlangýç adresi
    ADD SI, AX             ; Kullanýcý giriþine göre adresi ayarla
    MOV AL, [SI]           ; Parity bilgisini al
    OUT 199, AL            ; Parity bilgisini port 199'a yaz
    JMP main_loop          ; Tekrar giriþ bekle

END start
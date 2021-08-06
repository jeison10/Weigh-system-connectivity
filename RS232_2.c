/*
********************************************************
   Rotinas para RS232 - PORT_2 - RS232 - Bauds: 460800 
********************************************************
*/

int1 envok2=off;


// prototipos
void envia_pesos_1();
void envia_status();
void envia_conf();
void reles();
void encheLinha();
void enviaForcado();
void iniciaNormal();
void iniciaNaVal();

/*
********************************************************

	comandos via RS232 - PORT_2: Raspberry pi 3 Node-red
	
	baud: 115200

Comandos:

w = envia pesos 
y(x) = recebe pesos 
z = envia status das chaves
Uaaxy	=	recebe comadno para os reles remotos pela central, aa=enderço, x=numero da valvula ou motor (7), y=comando (L)liga, (D)Desliga
s = envia configurações
q = recebe configurações
b = flag botão OK
c = falg botão ESC
d = incia processo
e = tara
g = encher linha
h = envia forçado
i = inicia em uma determinada valvula
r = desliga reles
R = Liga reles
f = envia status dos acionamentos das valvulas e motores



********************************************************
*/
void Trata_RS232_PORT_2(){


	int8 cmd;
	int16 i,  idx;
	int1 flate=1;	// DEFAULT: avisa erro


	// dados no buffer?
	if (fBuffer2==0) {return;}

	idx=0;

	cmd=Buffer2[idx];

	envok2=off;



//------------------------------------------------------------------------------------------------------------------
//  ==> envia pesos 
//------------------------------------------------------------------------------------------------------------------	

	if (cmd=='w'){
	
	idx++;

		if (buffer2[idx]=='1'){
		envia_pesos_1();		} //chama funcão

	goto rsaia2; // saia
}



//------------------------------------------------------------------------------------------------------------------
//  ==> Recebe Pesos das válvulas (y)
//------------------------------------------------------------------------------------------------------------------	

if (cmd=='y'){

int1 status;
int16 endVal;
float pesoVal; 	
int8 c;
char PESO[6];
char statusLe[2];

idx++;

	if (buffer2[idx]=='1'){//recebe escreve valores aviario 1
	
for (int i=1;i<7;i++){  
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i,status); //hab
	    
		endVal=ePeva01+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}
	}

	if (buffer2[idx]=='2'){ //recebe escreve valores aviario 2

for (int i=1;i<7;i++){
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i+6,status); //hab
	    
		endVal=ePeva07+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}
}

	if (buffer2[idx]=='3'){ //recebe escreve valores aviario 3

for (int i=1;i<7;i++){
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i+12,status); //hab
	    
		endVal=ePeva13+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}
}

	if (buffer2[idx]=='4'){ //recebe escreve valores aviario 4

for (int i=1;i<7;i++){
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i+18,status); //hab
	    
		endVal=ePeva19+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}

}


if (buffer2[idx]=='5'){ //recebe escreve valores aviario 5

for (int i=1;i<7;i++){
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i+24,status); //hab
	    
		endVal=ePeva25+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}

}


if (buffer2[idx]=='6'){ //recebe escreve valores aviario 6

for (int i=1;i<7;i++){
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i+30,status); //hab
	    
		endVal=ePeva31+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}

}


if (buffer2[idx]=='7'){ //recebe escreve valores aviario 7

for (int i=1;i<7;i++){
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i+36,status); //hab
	    
		endVal=ePeva37+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}

}


if (buffer2[idx]=='8'){ //recebe escreve valores aviario 8

for (int i=1;i<7;i++){
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i+42,status); //hab
	    
		endVal=ePeva43+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}

}


if (buffer2[idx]=='9'){ //recebe escreve valores aviario 9

for (int i=1;i<7;i++){
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i+48,status); //hab
	    
		endVal=ePeva49+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}

}


if (buffer2[idx]=='A'){ //recebe escreve valores aviario 10

for (int i=1;i<7;i++){
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i+54,status); //hab
	    
		endVal=ePeva55+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}

}


if (buffer2[idx]=='B'){ //recebe escreve valores aviario 11

for (int i=1;i<7;i++){
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i+60,status); //hab
	    
		endVal=ePeva61+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}

}


if (buffer2[idx]=='C'){ //recebe escreve valores aviario 12

for (int i=1;i<7;i++){
	
		c=i-1;

		statusLe[0]=buffer2[(idx+6)+(c*6)];
		status=atoi(statusLe);
		sub_Configura_Hab_valv1(i+66,status); //hab
	    
		endVal=ePeva67+(c*4);
		PESO[0]=buffer2[(idx+1)+(c*6)]; PESO[1]=buffer2[(idx+2)+(c*6)]; PESO[2]=buffer2[(idx+3)+(c*6)]; PESO[3]=buffer2[(idx+4)+(c*6)]; PESO[4]=buffer2[(idx+5)+(c*6)]; 
		pesoVal=atof(PESO);
		write_float_eeprom(endVal,pesoVal);
}

}




	goto rsaia2; // saia

}



//------------------------------------------------------------------------------------------------------------------
//  ==> envia status das chaves e tensões da bateria e da central
//------------------------------------------------------------------------------------------------------------------	

	if (cmd=='Z'){
	

		envia_status();		 //chama funcão

	goto rsaia2; // saia
}



//----------------------------------------------------------------------------------------------------------------------------------------------------
//==>	Uaaxy	=	recebe comadno para os reles remotos pela central, aa=enderço, x=numero da valvula ou motor (7), y=comando (L)liga, (D)Desliga
//--------------------------------------------------------------------------------------------------------------------------------------------------

	if (cmd=='U'){

		int8 i,b;
		char txt[2];		
		
		txt[0]=Buffer2[idx+1];
		txt[1]=Buffer2[idx+2];	// pega endereço aviario
		
		i=atol(txt);
		
		txt[0]='0';
		txt[1]=buffer2[idx+3];
		b=atol(txt);

		cmd=Buffer2[idx+4];	// pega comando
		
		if (cmd=='L'){
		bit_set(bSaidas[i],b);
		}

		if (cmd=='D'){
		bit_clear(bSaidas[i],b);
		}

		
		goto rsaia2; // saia
		}





//------------------------------------------------------------------------------------------------------------------
//  ==> envia configurações
//------------------------------------------------------------------------------------------------------------------	

	if (cmd=='s'){
	

		envia_conf();		 //chama funcão

	goto rsaia2; // saia
}



//------------------------------------------------------------------------------------------------------------------
//  ==> recebe dados de hora, data e configurações
//------------------------------------------------------------------------------------------------------------------	

	if (cmd=='q'){
	
	
	char DATA[2];
	char VAL[4];
	int16 Tmout,TSensor,TSensorOff;
	int8 Tval,Tgav;
	int8 idioma, unidade;
	float Frac,offset;


	Testa_chip_Relogio(); // verifica se o chip do relogio está presente

	// erro no relogio?
	if (Erro_DS==on){return;}	
	
//	** acerta relogio
//==>	CddmmyyhhMM	= todos os caracteres em ASCII, dd=dia, mm=mes, yy=ano, 
//						hh=hora (24 horas), MM=minutos.

		idx++;
		// converte o dia	
		DATA[0]=buffer2[idx]; DATA[1]= buffer2[idx+1];   // converte Ascii to Hex binario
		dia=bin2bcd(atoi(DATA));			// convert

		// converte o mes	
		DATA[0]=buffer2[idx+2]; DATA[1]= buffer2[idx+3];   // converte Ascii to Hex binario
		mes=bin2bcd(atoi(DATA));			// convert

		// converte o ano	
		DATA[0]=buffer2[idx+4]; DATA[1]= buffer2[idx+5];   // converte Ascii to Hex binario
		ano=bin2bcd(atoi(DATA));			// convert


		// converte o hora	
		DATA[0]=buffer2[idx+6]; DATA[1]= buffer2[idx+7];   // converte Ascii to Hex binario
		hora=bin2bcd(atoi(DATA));			// convert


		// converte o minutos	
		DATA[0]=buffer2[idx+8]; DATA[1]= buffer2[idx+9];   // converte Ascii to Hex binario
		min=bin2bcd(atoi(DATA));			// convert


		// acerta relogio DS1307
		Acerta_data_hora();


// RECEBE AJUSTE DE CONFIGURAÇÕES

		//eTmotrac
VAL[0]=buffer2[(idx+10)]; VAL[1]=buffer2[(idx+11)];VAL[2]=buffer2[(idx+12)];VAL[3]=buffer2[(idx+13)];
Tmout=atol(VAL);
write_int16_eeprom(eTmotrac,Tmout); //salva eeprom


//Tempo gaveta
VAL[0]='0'; VAL[1]=buffer2[(idx+14)];VAL[2]=buffer2[(idx+15)];VAL[3]=buffer2[(idx+16)];
Tgav=atoi(VAL);
write_eeprom(eTmpGav,Tgav); //salva eeprom


// tempo valvula
VAL[0]='0'; VAL[1]=buffer2[(idx+17)];VAL[2]=buffer2[(idx+18)];VAL[3]=buffer2[(idx+19)];
Tval=atoi(VAL);
write_eeprom(eTValv,Tval); //salva eeprom


//tempo sensor
VAL[0]=buffer2[(idx+20)]; VAL[1]=buffer2[(idx+21)];VAL[2]=buffer2[(idx+22)];VAL[3]=buffer2[(idx+23)];
TSensor=atol(VAL);
write_int16_eeprom(eTmous10,TSensor); //salva eeprom


//tempo sensor off
VAL[0]=buffer2[(idx+24)]; VAL[1]=buffer2[(idx+25)];VAL[2]=buffer2[(idx+26)];VAL[3]=buffer2[(idx+27)];
TSensorOff=atol(VAL);
write_int16_eeprom(eTmpS1off,TSensorOff); //salva eeprom


//valor fraciona
VAL[0]='0'; VAL[1]=buffer2[(idx+28)];VAL[2]=buffer2[(idx+29)];VAL[3]=buffer2[(idx+30)];
frac=atof(VAL);
write_float_eeprom(eFraciona,frac); //salva eeprom

//unidade
VAL[0]='0'; VAL[1]='0';VAL[2]='0';VAL[3]=buffer2[(idx+31)];
unidade=atoi(VAL);
f_unid_KG=unidade;
write_eeprom(eUnid_kg, unidade);

//idioma
VAL[0]='0'; VAL[1]='0';VAL[2]='0';VAL[3]=buffer2[(idx+32)];
idioma=atoi(VAL);
f_idiomBR=idioma;
write_eeprom(eIdioma, idioma);


//ofset Peso
VAL[0]='0'; VAL[1]=buffer2[(idx+33)];VAL[2]=buffer2[(idx+34)];VAL[3]=buffer2[(idx+35)];
offset=atof(VAL);
write_float_eeprom(eOfPeso, offset);

	goto rsaia2; // saia
}



//------------------------------------------------------------------------------------------------------------------
//  ==> habilita para enviar peso
//------------------------------------------------------------------------------------------------------------------	

	if (cmd=='a'){
	
	idx++;

	if(buffer2[(idx)]=='L'){
	f_habPeso=1;
	}
	if(buffer2[(idx)]=='D'){
	f_habPeso=0;
	}	 

	goto rsaia2; // saia
}

  

//------------------------------------------------------------------------------------------------------------------
//  ==> Recebe botao ok durante proceso
//------------------------------------------------------------------------------------------------------------------

if (cmd=='b'){ 
fBOk=1;
fBOkForcado=1;
goto rsaia2; // saia
}

//------------------------------------------------------------------------------------------------------------------
//  ==> Recebe botao esc durante proceso
//------------------------------------------------------------------------------------------------------------------

if (cmd=='c'){ 
fBEsc=1;
fBEscForcado=1;
goto rsaia2; // saia
}


//------------------------------------------------------------------------------------------------------------------
//  ==> incia processo
//------------------------------------------------------------------------------------------------------------------
	
	if (cmd=='d'){ 

	iniciaNormal();

			goto rsaia2; // saia
	}


//------------------------------------------------------------------------------------------------------------------
//  ==> tara
//------------------------------------------------------------------------------------------------------------------
	if (cmd=='e'){ 
		tFuncoes=2;
		acessoFunc=2;
			goto rsaia2; // saia
	}


//------------------------------------------------------------------------------------------------------------------
//  ==> reles
//------------------------------------------------------------------------------------------------------------------
	if (cmd=='f'){ 
			reles();
			goto rsaia2; // saia
	}


//------------------------------------------------------------------------------------------------------------------
//  ==> encher linha
//------------------------------------------------------------------------------------------------------------------
	if (cmd=='g'){ 

			
			encheLinha();

					
			goto rsaia2; // saia
}


//------------------------------------------------------------------------------------------------------------------
//  ==> enviar forçado
//------------------------------------------------------------------------------------------------------------------
	if (cmd=='h'){ 
		
		char val[2];

		idx++;
		
		val[0]= buffer2[(idx)]; val[1]= buffer2[(idx+1)];
		valInicial=atoi(val);

		enviaForcado();

		goto rsaia2; // saia

}

//------------------------------------------------------------------------------------------------------------------
//  ==> iniciar em uma determinada linha
//------------------------------------------------------------------------------------------------------------------
	if (cmd=='i'){ 

		char val[2];

		idx++;
		
		val[0]= buffer2[(idx)]; val[1]= buffer2[(idx+1)];
		valInicial=atoi(val);

		iniciaNaVal();

			goto rsaia2; // saia

}




//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
// está em processo? saia
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------
		// está em processo?	
		if (fEStado != 0){ 	// senão saia
			flate=1;	// avisa com erros
			goto rsaia2; // saia
			}

//------------------------------------------------------------------------------------------------------------------





//------------------------------------------------------------------------------------------------------------------
//==>	rx	=	Desliga rele x=num. do rele, x=0=todos reles 
//------------------------------------------------------------------------------------------------------------------

	if (cmd=='r'){

		cmd=Buffer2[idx+1];

		// desliga todos 
		if (cmd=='0'){
			Desliga_M1();	// desliga rele 
			Desliga_VG();	// desliga rele 
			Desliga_RLalarme();	// desliga rele 
			Desliga_M2();	// desliga rele 
			fRele1=0;
			fRele2=0;
			fRele3=0;
			fRele4=0;
		 	flate=0;	// avisa sem erros
			envok2=on;	// avisa envia OK
		 	goto rsaia2; // saia
		}

		// desliga o rele 
		if (cmd=='1'){
			Desliga_M1();	// desliga rele 
			fRele1=0;
		 	flate=0;	// avisa sem erros
			envok2=on;	// avisa envia OK
		 	goto rsaia2; // saia
		}

		// desliga o rele 
		if (cmd=='2'){
			Desliga_VG();	// desliga rele 
			fRele2=0;
			flate=0;	// avisa sem erros
			envok2=on;	// avisa envia OK
		 	goto rsaia2; // saia
		}

		// desliga o rele 
		if (cmd=='3'){
			Desliga_RLalarme();	// desliga rele 
			fRele3=0;
		 	flate=0;	// avisa sem erros
			envok2=on;	// avisa envia OK
		 	goto rsaia2; // saia
		}

		// desliga o rele 
		if (cmd=='4'){
			Desliga_M2();	// desliga rele 
			fRele4=0;
			flate=0;	// avisa sem erros
			envok2=on;	// avisa envia OK
		 	goto rsaia2; // saia
		}
	}


//------------------------------------------------------------------------------------------------------------------
//==>	Rx	=	Liga Rele  x=num. do rele, x=0=todos reles
//------------------------------------------------------------------------------------------------------------------

	if (cmd=='R'){

		cmd=Buffer2[idx+1];

		// liga todos 
		if (cmd=='0'){
			Ligar_M1();	// liga rele
			Liga_VG();	// liga rele
			Liga_RLalarme();	// liga rele
			Liga_M2();	// liga rele
			fRele1=1;
			fRele2=1;
			fRele3=1;
			fRele4=1;
			flate=0;	// avisa sem erros
			envok2=on;	// avisa envia OK
			goto rsaia2; // saia
		}

		// liga o rele
		if (cmd=='1'){
			Ligar_M1();	// liga rele
			fRele1=1;
			flate=0;	// avisa sem erros
			envok2=on;	// avisa envia OK
			goto rsaia2; // saia
		}

		// liga o rele
		if (cmd=='2'){
			Liga_VG();	// liga rele
			fRele2=1;
			flate=0;	// avisa sem erros
			envok2=on;	// avisa envia OK
		 	goto rsaia2; // saia
		}

		// liga o rele
		if (cmd=='3'){
			Liga_RLalarme();	// liga rele
			fRele3=1;
			flate=0;	// avisa sem erros
			envok2=on;	// avisa envia OK
			goto rsaia2; // saia
		}

		// liga o rele
		if (cmd=='4'){
			Liga_M2();	// liga rele
			fRele4=1;
			flate=0;	// avisa sem erros
			envok2=on;	// avisa envia OK
		 	goto rsaia2; // saia
		}
	}
	


rsaia2:

	
	if (flate==1) {
		// está parado?	
		if (fEStado != 0){ 	// senão saia
			fprintf(PORT_2,"Em Processo\r\n");  	// precisa ser  o \r primeiro
			goto sxd0;}
	//	fprintf(PORT_2,"CMD invalido !\r\n");  	// precisa ser  o \r primeiro
	 	// limpa buffer2 
		
		//Limpa flags de botoes recebidas pela serial
		fBOk=0;
		fBEsc=0;
		fBOkForcado=0;
		fBEscForcado=0;
	
		for (i=0;i<=BUFFERSIZE2;++i)
		Buffer2[i]=0;
		}

	// envia OK?
	if (envok2==on) {fprintf(PORT_2,"OK\r\n");}	// prec''''''''''''''''''''''''''isa ser  o \r primeiro
	
	
sxd0:
	envok2=off; // limpa: avisa envia OK

	SUB_Seta_Bauds();

	flate=0;	// limpa
	IndxBuf2=0;	// limpa
	fBuffer2=0;
}








// seta os baudsrate da serial RS232
void SUB_Seta_Bauds(){

int8 t=read_eeprom(eBauds);
	
	// se não foi gravado ainda assume 115200 por default
	if (t>7){
		t=5;
		write_eeprom(eBauds,5);
		}

	// seta os baudsrates do RS232
	t=read_eeprom(eBauds);

//(x=0=9600, x=1=19200, x=2=28800, x=3=38400, x=4=57600, x=5=115200, x=6=230400, x=7=460800)

	if (t==0){
		setup_uart(9600, PORT_2);
		//#use rs232(baud=9600,parity=N,bits=8,xmit=PIN_D7,rcv=PIN_D6, UART2,stream=PORT_2)
		return;}
		
	if (t==1){
		setup_uart(19200, PORT_2);
		//#use rs232(baud=19200,parity=N,bits=8,xmit=PIN_D7,rcv=PIN_D6, UART2,stream=PORT_2)
		return;}
		
	if (t==2){
		setup_uart(28800, PORT_2);
		//#use rs232(baud=28800,parity=N,bits=8,xmit=PIN_D7,rcv=PIN_D6, UART2,stream=PORT_2)
		return;}
		
	if (t==3){
		setup_uart(38400, PORT_2);
		//#use rs232(baud=38400,parity=N,bits=8,xmit=PIN_D7,rcv=PIN_D6, UART2,stream=PORT_2)
		return;}
		
	if (t==4){
		setup_uart(57600, PORT_2);
		//#use rs232(baud=57600,parity=N,bits=8,xmit=PIN_D7,rcv=PIN_D6, UART2,stream=PORT_2)
		return;}
		
	if (t==5){
		setup_uart(115200, PORT_2);
		//#use rs232(baud=115200,parity=N,bits=8,xmit=PIN_D7,rcv=PIN_D6, UART2,stream=PORT_2)
		return;}
		
	if (t==6){
		setup_uart(230400, PORT_2);
		//#use rs232(baud=230400,parity=N,bits=8,xmit=PIN_D7,rcv=PIN_D6, UART2,stream=PORT_2)
		return;}
		
	if (t==7){
		setup_uart(460800, PORT_2);
		//#use rs232(baud=460800,parity=N,bits=8,xmit=PIN_D7,rcv=PIN_D6, UART2,stream=PORT_2)
		}
}






//---------------------------------------------------------------
// envia pesos nas valvulas
//---------------------------------------------------------------

void envia_pesos_1(){

	int8 s; //status val
	int16 td;
	float fv;
	char TXT[5];
	int16 a;

		printf("w");
		printf("/");
		for (int i=0; i<72; i++){
		a=i;
		td=ePeva01+(a*4);	// endereço do proximo peso
		fv=read_float_eeprom(td);
		sprintf(TXT,"%3.1f",fv);
		printf("%s",TXT);
		printf("/");
		s=Func_le_status_Valv1(i+1);
		sprintf(TXT,"%d",s);
		printf ("%s",TXT);
		printf("/");
}
}



//---------------------------------------------------------------
// envia status das chaves das remotas
//---------------------------------------------------------------

void envia_status(){

int8 h;
char TXT [3];


		printf("Z"); //identifica qual funcao é
		printf("/");

	for (int i = 1; i < 13; i++){  //somente para 12 aviários
		for (int b=0; b < 6; b++){
			h=FlagsChaves[i];
			printf ("%u",bit_test(h,b));
			printf("/");	
				}	}

			//bit_test(h,0);
for (int z = 1; z < 13; z++){    //somente para 12 aviários
		for (int j=3; j < 6; j++){
			h=FlagsEntr[z];
			printf ("%u",bit_test(h,j));
			printf("/");
					}	}
		

sprintf(TXT,"%2.1fV",v24vcc);
printf("%s",TXT);
printf("/");	
sprintf(TXT,"%2.1fV",v12vcc);
printf("%s",TXT);
printf("/");	

}
	


//---------------------------------------------------------------
// envia data e hora e configurações
//---------------------------------------------------------------

void envia_conf(){

char HR[3];
char CONF[5];



printf("Conf"); //para iniciar comando
printf("/");

//data e hora
sprintf(HR,"%d",dia);
printf("%s",HR);
printf("/");
sprintf(HR,"%d",mes);
printf("%s",HR);
printf("/");
sprintf(HR,"%d",ano);
printf("%s",HR);
printf("/");
sprintf(HR,"%d",hora);
printf("%s",HR);
printf("/");
sprintf(HR,"%d",min);
printf("%s",HR);
printf("/");


//eTmotrac
sprintf(CONF,"%04Ld",read_int16_eeprom(eTmotrac));
printf("%s",CONF);
printf("/");

//tempo gaveta
sprintf(CONF,"%03d",read_eeprom(eTmpGav));
printf("%s",CONF);
printf("/");

//tempo valvula
sprintf(CONF,"%03d",read_eeprom(eTValv));
printf("%s",CONF);
printf("/");

//tempo sensor on
sprintf(CONF,"%04Ld",read_int16_eeprom(eTmous10));
printf("%s",CONF);
printf("/");

//tempo sensor off
sprintf(CONF,"%04Ld",read_int16_eeprom(eTmpS1off));
printf("%s",CONF);
printf("/");

//valor fraciona
sprintf(CONF,"%3.0f",read_float_eeprom(eFraciona));
printf("%s",CONF);
printf("/");

//unidade de medida
sprintf(CONF,"%01d",read_eeprom(eUnid_kg));
printf("%s",CONF);
printf("/");

//Idioma da central
sprintf(CONF,"%01d",read_eeprom(eIdioma));
printf("%s",CONF);
printf("/");

//Of7 peso
sprintf(CONF,"%1.1f",read_float_eeprom(eOfPeso));
printf("%s",CONF);
printf("/");


}


void reles(){

		printf("reles");
			printf("/");
			for (int i = 1; i < 17; i++){  //envia acionamento dos reles (reles)
			for (int b=0; b < 8; b++){
			int	ss=bSaidas[i];
			printf ("%u",bit_test(ss,b));
			printf("/");
			}
			}	
			printf("\n");

}




/*****************************************************************************
 * nnnnn.c
 *****************************************************************************/
#include <stdio.h>
#include <stdlib.h>

#include "driver.h"

 
#define SizeClient 8




/***déclaration dictionnaire object*** 
remarque:
-pas de dictionary obj pour le client

*************************************/
//les buffer pour la synchronisation SYNC 1005h

const UNSIGNED8 Sync_Buffer0[SizeClient]={0x10,0x05,0x00,0x80,0x00,0x00,0x00};
const UNSIGNED8 Sync_Buffer1[SizeClient]={0x10,0x06,0x00,0x0A,0x00,0x00,0x00};
const UNSIGNED8 Sync_Buffer2[SizeClient]={0x10,0x07,0x00,0x07,0x00,0x00,0x00};

//les buffer pour Client SDO d'index 1280h, il sont utile pour envoyé read sdo

const UNSIGNED8 C_Buffer0[SizeClient]={0x12,0x80,0x00,0x87,0x5F,0x33,0xF1};
const UNSIGNED8 C_Buffer1[SizeClient]={0x12,0x80,0x01,0xEF,0x21,0xFC,0xC3};
const UNSIGNED8 C_Buffer2[SizeClient]={0x12,0x81,0x00,0x34,0x56,0x73,0x88};
const UNSIGNED8 C_Buffer3[SizeClient]={0x12,0x81,0x01,0x81,0x53,0x33,0xDA};
const UNSIGNED8 C_Buffer4[SizeClient]={0x12,0x82,0x00,0x82,0x54,0x35,0xFB};
const UNSIGNED8 C_Buffer5[SizeClient]={0x12,0x83,0x00,0x89,0x56,0x12,0xCA};


//les buffer pour lecture "upload" sdo d'index 1200h (server)
//const UNSIGNED8 Buffer0[SizeClient]={0x12,0x00,0x00,0x09,0x86,0x77,0x39};
//const UNSIGNED8 Buffer1[SizeClient]={0x12,0x00,0x01,0x6E,0x0C,0x77,0x3B};
//const UNSIGNED8 Buffer2[SizeClient]={0x12,0x01,0x00,0x62,0x01,0x77,0x33};
//const UNSIGNED8 Buffer3[SizeClient]={0x12,0x01,0x01,0x65,0x06,0x77,0x37};
//const UNSIGNED8 Buffer4[SizeClient]={0x12,0x02,0x00,0x6E,0x0C,0x77,0x3B};
//const UNSIGNED8 Buffer5[SizeClient]={0x12,0x02,0x01,0x6E,0x0F,0x77,0x3F};


//les buffer pour ecriture "download" sdo d'index 1200h (server)

UNSIGNED8 S_Buffer0[SizeClient]={0x12,0x70,0x00};
UNSIGNED8 S_Buffer1[SizeClient]={0x12,0x70,0x01};
UNSIGNED8 S_Buffer2[SizeClient]={0x12,0x71,0x00};
UNSIGNED8 S_Buffer3[SizeClient]={0x12,0x71,0x01};
UNSIGNED8 S_Buffer4[SizeClient]={0x12,0x72,0x00};
UNSIGNED8 S_Buffer5[SizeClient]={0x12,0x72,0x01};
/*le PDO communication paraméters décrit les possibilités de communication d'un PDO*/
//Receive PDO Communication Parameter Structure d'index 1400h
UNSIGNED8 R_PDO_Buffer0[SizeClient]={0x14,0x00,0x00};
UNSIGNED8 R_PDO_Buffer1[SizeClient]={0x14,0x00,0x01};
UNSIGNED8 R_PDO_Buffer2[SizeClient]={0x14,0x01,0x00};
UNSIGNED8 R_PDO_Buffer3[SizeClient]={0x14,0x01,0x01};
UNSIGNED8 R_PDO_Buffer4[SizeClient]={0x14,0x02,0x00};
UNSIGNED8 R_PDO_Buffer5[SizeClient]={0x14,0x02,0x01};

//Transmit PDO Communication Parameter Structure d'index 1800h
UNSIGNED8 T_PDO_Buffer0[SizeClient]={0x18,0x00,0x00};
UNSIGNED8 T_PDO_Buffer1[SizeClient]={0x18,0x00,0x01};
UNSIGNED8 T_PDO_Buffer2[SizeClient]={0x18,0x01,0x00};
UNSIGNED8 T_PDO_Buffer3[SizeClient]={0x18,0x01,0x01};
UNSIGNED8 T_PDO_Buffer4[SizeClient]={0x18,0x02,0x00};
UNSIGNED8 T_PDO_Buffer5[SizeClient]={0x18,0x02,0x01};



//des buffer d'index quelconque dans Dictionary Obj pour le mappage (c'est just pour test)
const UNSIGNED8 M_Buffer0[SizeClient]={0x06,0x80,0x5F,0x09,0x86};
const UNSIGNED8 M_Buffer1[SizeClient]={0x06,0x96,0x53,0x65,0x06};
const UNSIGNED8 M_Buffer2[SizeClient]={0x06,0xA2,0x51,0x6E,0x0F};
const UNSIGNED8 M_Buffer3[SizeClient]={0x06,0xEC,0x50,0x62,0x01};
const UNSIGNED8 M_Buffer4[SizeClient]={0x06,0xF6,0x00,0x6E,0x0C};
const UNSIGNED8 M_Buffer5[SizeClient]={0x06,0xF7,0x56,0x6E,0x0F};

/*Le mapping contient les information qui concerne le PDO*/
//Transmit les buffer pour le stockage mapping PDO d'index 1A00h
UNSIGNED8 P_Buffer0[SizeClient]={0x1A,0x00,0x00};
UNSIGNED8 P_Buffer1[SizeClient]={0x1A,0x00,0x01};
UNSIGNED8 P_Buffer2[SizeClient]={0x1A,0x01,0x00};
UNSIGNED8 P_Buffer3[SizeClient]={0x1A,0x01,0x01};
UNSIGNED8 P_Buffer4[SizeClient]={0x1A,0x02,0x00};
UNSIGNED8 P_Buffer5[SizeClient]={0x1A,0x02,0x01};

//Receive les buffer pour le stockage mapping PDO d'index 1600h
UNSIGNED8 R_P_Buffer0[SizeClient]={0x16,0x00,0x00};
UNSIGNED8 R_P_Buffer1[SizeClient]={0x16,0x01,0x00};
UNSIGNED8 R_P_Buffer2[SizeClient]={0x16,0x02,0x00};
UNSIGNED8 R_P_Buffer3[SizeClient]={0x16,0x02,0x01};
UNSIGNED8 R_P_Buffer4[SizeClient]={0x16,0x03,0x00};
UNSIGNED8 R_P_Buffer5[SizeClient]={0x16,0x04,0x00};







UNSIGNED8 Sync_counter;
UNSIGNED16 COB_ID;
UNSIGNED8 Buffer[SizeClient];
UNSIGNED8 BufferSend[SizeClient];
const UNSIGNED8 reserved =0x00;
//donner une valeur a la DLC pour le test
UNSIGNED8 DLC =0x8;
UNSIGNED32 buf;
UNSIGNED32 mapping;
UNSIGNED8 j;

UNSIGNED8 Mux1[3],Mux2[3];


//variable qui concerne le sync(realisation d'un timer)
/**************************/
UNSIGNED8 milliseconds=0;
UNSIGNED8 seconds=0;
UNSIGNED8 minutes=0;
UNSIGNED8 hours=0;
/**************************/

	

    //déclaration des structures
    /****************************************/
    init_down_SDO_client CID_SDO_STR;
    init_down_SDO_server SID_SDO_STR;
    down_SDO_seg_client CSD_SDO_STR;
    down_SDO_seg_server SSD_SDO_STR;
    init_up_SDO_client CIU_SDO_STR;
    init_up_SDO_server SIU_SDO_STR;
    up_SDO_seg_client CSU_SDO_STR;
    up_SDO_seg_server SSU_SDO_STR;
    
    
    init_down_SDO_client *CID_SDO = &CID_SDO_STR;
    init_down_SDO_server *SID_SDO = &SID_SDO_STR;
    down_SDO_seg_client *CSD_SDO = &CSD_SDO_STR;
    down_SDO_seg_server *SSD_SDO = &SSD_SDO_STR;
    init_up_SDO_client *CIU_SDO = &CIU_SDO_STR;
    init_up_SDO_server *SIU_SDO = &SIU_SDO_STR;
    up_SDO_seg_client *CSU_SDO = &CSU_SDO_STR;
    up_SDO_seg_server *SSU_SDO = &SSU_SDO_STR;
    /**************************************/
  
	//variables pour stockage R_PDO
    UNSIGNED32 R_pdo[5];
    char *var;
    int c=0;
    /****************************/
	
	//variables pour traitemrnt T_PDO et le choix des Mux
    UNSIGNED32 T_pdo[6];
    char *point1;
	char *point2;
    int k=0;
	int y=3;
    /****************************/
	
	//variables pour le traitement Client SDO
	UNSIGNED32 C_sdo[6];
    char *c_point;
    int d=0;

    /****************************/
    //variable pour le transfert segmenté sdo
    UNSIGNED32 C_seg_sdo[6];
    char *c_seg_point;
    int d_seg=2;
    
	/****************************/
	
	//variable pour le traitement Server SDO
	UNSIGNED32 S_pdo[6];
    char *s_point;
    int s=0;
	
    /****************************/
	//variable pour le traitement SYNC
	UNSIGNED32 SYNC[3];
    char *Sync_point;
    
	/****************************/
	
int main( int argc, char *argv[])
{
	
	printf("donner la trame a envoye ");
	//donner le buffer manuellement
    //scanf("%d",&Buffer);
	
    printf("la trame a envoyé est %d\n", Buffer);


//traitement sync
if (COB_ID  == CAN_ID_SYNC ) {
	
	if(DLC != 0x00) return CO_ERROR_RX_MSG_DLC;
	//faire un test de la partie SYNC 10 fois 
	for(j==0;j<=10;j++){
		//le temp choisie est 10 minutes
		SYNC[0]=&Sync_Buffer0;
		SYNC[1]=&Sync_Buffer1;
		SYNC[2]=&Sync_Buffer2;

		Sync_point=SYNC[1];
		Sync_counter=*(Sync_point+3);
		timer();
		//send broadcast(RTR (la partie data est vide)et on met COB-ID du SYNC);
	}
}


/***************************/
//traitement PDO
/***************************/
//traitement TPDO
else if ((COB_ID >= CAN_ID_TPDO1) && (COB_ID <= CAN_ID_TPDO1+CANOPEN_MAX_ID)){   
	
	//traitement pour le choix des Mux
	T_pdo[0]=&M_Buffer0;
	T_pdo[1]=&M_Buffer1;
	T_pdo[2]=&M_Buffer2;
	T_pdo[3]=&M_Buffer3;
	T_pdo[4]=&M_Buffer4;
	T_pdo[5]=&M_Buffer5;
	point1=T_pdo[k];
	point2=T_pdo[y];
	
	/******Mux1********/
	Mux1[0]=*(point1+0);
	Mux1[1]=*(point1+1);
	Mux1[2]=*(point1+2);
	
	/******Mux2*********/
	Mux2[0]=*(point2+0);
	Mux2[1]=*(point2+1);
	Mux2[2]=*(point2+2);
	
	/*******************/
	//fonction pour chercher la data de ces deux Mux
	mapping=Mapping_appel(Mux1,Mux2);
	k++;
	y++;
	
	//stockage du buffer mappé dans le dictionnaire objet
	P_Buffer0[3]=mapping&0x000000FF;
	P_Buffer0[4]=((mapping&0x0000FF00)>>8);
	P_Buffer0[5]=((mapping&0x00FF0000)>>16);
	P_Buffer0[6]=((mapping&0xFF000000)>>24);
	
	//préparation pour l'envoie de la trame au consommateurs Brodcasté ou déstiné
	BufferSend[0]=P_Buffer0[0];
	BufferSend[1]=P_Buffer0[1];
	BufferSend[2]=P_Buffer0[2];
	BufferSend[3]=P_Buffer0[3];
	BufferSend[4]=P_Buffer0[4];
	BufferSend[5]=P_Buffer0[5];
	BufferSend[6]=P_Buffer0[6];
	BufferSend[7]=P_Buffer0[7];
	
	/*if(receive frame SYNC(test sur cob-id de RPDO)){
		//préparation pour l'envoie de la trame au consommateurs Brodcasté ou déstiné
		BufferSend[0]=P_Buffer0[0];
		BufferSend[1]=P_Buffer0[1];
		BufferSend[2]=P_Buffer0[2];
		BufferSend[3]=P_Buffer0[3];
		BufferSend[4]=P_Buffer0[4];
		BufferSend[5]=P_Buffer0[5];
		BufferSend[6]=P_Buffer0[6];
		BufferSend[7]=P_Buffer0[7];
		//send(*BufferSend); et COB-ID broadcasté au RPDO.
	}
	else
	if(receive RTR from R_PDO(test sur cob-id de RPDO)){
		//test de longueur de la partie data
		if(DLC != 0x00) return CO_ERROR_RX_MSG_DLC;
			//préparation pour l'envoie de la trame au consommateurs Brodcasté ou déstiné
			BufferSend[0]=P_Buffer0[0];
			BufferSend[1]=P_Buffer0[1];
			BufferSend[2]=P_Buffer0[2];
			BufferSend[3]=P_Buffer0[3];
			BufferSend[4]=P_Buffer0[4];
			BufferSend[5]=P_Buffer0[5];
			BufferSend[6]=P_Buffer0[6];
			BufferSend[7]=P_Buffer0[7];
			//send(*BufferSend); et COB-ID broadcasté au RPDO.	
	
	} 

	return 0;*/
}
//traitement RPDO
else if ((COB_ID >= CAN_ID_RPDO1) && (COB_ID <= CAN_ID_RPDO1+CANOPEN_MAX_ID)){   
	/*
    if(receive frame SYNC){
      //receive message from Producer
      if(receive message from TPDO(test sur cob-id de TPDO)){
      //faire un test pour que la donné n'est pas vide
      if(DLC == 0x00) return CO_ERROR_RX_MSG_DLC;
      //décodage du frame reçu
      Buffer[0]=BufferSend[0];
      Buffer[1]=BufferSend[1];
      Buffer[2]=BufferSend[2];
      Buffer[3]=BufferSend[3];
      Buffer[4]=BufferSend[4];
      Buffer[5]=BufferSend[5];
      Buffer[6]=BufferSend[6];
      Buffer[7]=BufferSend[7];
      	//stochage dans Dictionary object
      	R_pdo[0] = &R_P_Buffer1;
		R_pdo[1] = &R_P_Buffer2;
		R_pdo[2] = &R_P_Buffer3;
		R_pdo[3] = &R_P_Buffer4;
		R_pdo[4] = &R_P_Buffer5;
		var=T_pdo[c];
		
		*(var+3)=Buffer[3];
		*(var+4)=Buffer[4];
		*(var+5)=Buffer[5];
		*(var+6)=Buffer[6];
		*(var+7)=Buffer[7];
		c++;
		
		
		
        
    }
    else if(receive frame from Producer(test sur cob-id de TPDO)){
      //décodage du frame reçu
      Buffer[0]=BufferSend[0];
      Buffer[1]=BufferSend[1];
      Buffer[2]=BufferSend[2];
      Buffer[3]=BufferSend[3];
      Buffer[4]=BufferSend[4];
      Buffer[5]=BufferSend[5];
      Buffer[6]=BufferSend[6];
      Buffer[7]=BufferSend[7];
      //stochage dans Dictionary object
      	R_pdo[0] = &R_P_Buffer1;
		R_pdo[1] = &R_P_Buffer2;
		R_pdo[2] = &R_P_Buffer3;
		R_pdo[3] = &R_P_Buffer4;
		R_pdo[4] = &R_P_Buffer5;
		var=R_pdo[c];
		
		*(var+3)=Buffer[3];
		*(var+4)=Buffer[4];
		*(var+5)=Buffer[5];
		*(var+6)=Buffer[6];
		*(var+7)=Buffer[7];
		c++;
     
     
    }
  }
  return 0;*/
}

else if ((COB_ID >= CAN_ID_RSDO) && (COB_ID <= CAN_ID_RSDO+CANOPEN_MAX_ID)){
    /**************
    traitement SDO
    **************/

    /***********************************
    le traitement fait par le serveur
    ***********************************/

	printf("le buffer est %d", *Buffer);
	//if receive frame du Client de COB-ID(client_sdo)
	//test sur la longueur de la trame
    if(DLC != 0x8) return CO_ERROR_RX_MSG_DLC;
    
    /************************************************/
    
        
    CID_SDO->ccs= (Buffer[0]& 0xE0)>>5;
    
    if(CID_SDO->ccs==0x01){
		//décodage de la trame	
		CID_SDO->x=(Buffer[0]& 0x40)>>2;
		CID_SDO->n=(Buffer[0]&0x0C)>>2;
		CID_SDO->e=(Buffer[0]&0x02)>>1;
		CID_SDO->s=Buffer[0]&0x01;
		CID_SDO->Mux[0]=Buffer[1];
		CID_SDO->Mux[1]=Buffer[2];
		CID_SDO->Mux[2]=Buffer[3];
		CID_SDO->Data[0]=Buffer[4];
		CID_SDO->Data[1]=Buffer[5];
		CID_SDO->Data[2]=Buffer[6];
		CID_SDO->Data[3]=Buffer[7];
	
		
		//stockage du donné dans le dictionnaire objet
		SDO_DO_stockage(CID_SDO->Mux,CID_SDO->Data);
		
		printf("e est egal a %d et s est egal a %d",CID_SDO->e,CID_SDO->s);
		
	
	
	
		if(CID_SDO->e==0x01 && CID_SDO->s==0x01){
			printf("la donné du Mux est egle %d",CID_SDO->Mux);
			printf("la donné du n est egle %d",CID_SDO->n);
			printf("la donné du Data est egle %d",CID_SDO->Data);
			
			//ecrire la trame a envoyé
			/*codage de la trame pour envoyer*/
			BufferSend[0]= 0x60;
			BufferSend[1]= CID_SDO->Mux[0];
			BufferSend[2]= CID_SDO->Mux[1];
			BufferSend[3]= CID_SDO->Mux[2];
			BufferSend[4]= reserved;
			BufferSend[5]= reserved;
			BufferSend[6]= reserved;
			BufferSend[7]= reserved;
			
			//send(*BufferSend);
			//Send confirm de la trame initiate sdo download
			
		}
		else if(CID_SDO->e==0x01 && CID_SDO->s==0x00)
		{
			if(CID_SDO->n==0x00){
				printf("la donné du Mux est egle %d",CID_SDO->Mux);
				printf("la donné du Data est egle %d",CID_SDO->Data);
				/*codage de la trame pour envoyer*/
				BufferSend[0]= 0x60;
				BufferSend[1]= CID_SDO->Mux[0];
				BufferSend[2]= CID_SDO->Mux[1];
				BufferSend[3]= CID_SDO->Mux[2];
				BufferSend[4]= reserved;
				BufferSend[5]= reserved;
				BufferSend[6]= reserved;
				BufferSend[7]= reserved;
				//send(*BufferSend);
				//Send confirm de la trame initiate sdo download
				
			}
		}
			
		/* else if (CID_SDO->e==0x00 && CID_SDO->s==0x01)
		{
			if(CID_SDO->n==0x00){
				printf("la donné du Mux est egle %d",CID_SDO->Mux);
				printf("la donné du Data est egle %d",CID_SDO->Data);
				//codage de la trame pour envoyer
				BufferSend[0]= 0x60;
				BufferSend[1]= CID_SDO->Mux[0];
				BufferSend[2]= CID_SDO->Mux[1];
				BufferSend[3]= CID_SDO->Mux[2];
				BufferSend[4]= reserved;
				BufferSend[5]= reserved;
				BufferSend[6]= reserved;
				BufferSend[7]= reserved;
				//send(*BufferSend);
				//Send trame initiate sdo download
			
				//wait pour que le client m'envoie la trame
				//décodage for the request from client download sdo segment
				CSD_SDO->ccs= (Buffer[0]& 0xE0)>>5;
				CSD_SDO->t=(Buffer[0]&0x40)>>2;
				CSD_SDO->n=(Buffer[0]&0x0E)>>1;
				CSD_SDO->c=Buffer[0]&0x01;
				CSD_SDO->seg_data[0]=Buffer[1];
				CSD_SDO->seg_data[1]=Buffer[2];
				CSD_SDO->seg_data[2]=Buffer[3];
				CSD_SDO->seg_data[3]=Buffer[4];
				CSD_SDO->seg_data[4]=Buffer[5];
				CSD_SDO->seg_data[5]=Buffer[6];
				CSD_SDO->seg_data[6]=Buffer[7];
		
				if(CSD_SDO->ccs==0x00){
					
						
					//ecrire la trame pour envoyer
					//codage de la trame pour envoyer
					BufferSend[0]=0x20;
					//on a mis le toggle bit a zero
					BufferSend[1]=reserved;
					BufferSend[2]=reserved;
					BufferSend[3]=reserved;
					BufferSend[4]=reserved;
					BufferSend[5]=reserved;
					BufferSend[6]=reserved;
					BufferSend[7]=reserved;
					//send(*BufferSend);
					//send frame of confirmation
					printf("le champ c de la trame est %d",CSD_SDO->c);
					while(CSD_SDO->c==0x00){
						//wait pour que le client m'envoie la trame
		
						//décodage for the request from client download sdo segment
						CSD_SDO->ccs= (Buffer[0]& 0xE0)>>5;
						CSD_SDO->t=(Buffer[0]&0x40)>>2;
						CSD_SDO->n=(Buffer[0]&0x0E)>>1;
						CSD_SDO->c=Buffer[0]&0x01;
						CSD_SDO->seg_data[0]=Buffer[1];
						CSD_SDO->seg_data[1]=Buffer[2];
						CSD_SDO->seg_data[2]=Buffer[3];
						CSD_SDO->seg_data[3]=Buffer[4];
						CSD_SDO->seg_data[4]=Buffer[5];
						CSD_SDO->seg_data[5]=Buffer[6];
						CSD_SDO->seg_data[6]=Buffer[7];
					
						
						//ecrire la trame pour envoyer
						//codage de la trame pour envoyer
						if(SSD_SDO->t==0x01){
							BufferSend[0]=0x20;
						}
						else
						{
							BufferSend[0]=0x30;
						}
						//on a mis le toggle bit a zero
						BufferSend[1]=reserved;
						BufferSend[2]=reserved;
						BufferSend[3]=reserved;
						BufferSend[4]=reserved;
						BufferSend[5]=reserved;
						BufferSend[6]=reserved;
						BufferSend[7]=reserved;
						//send(*BufferSend);
						//send frame of confirmation
					
					
						
						//test toggle bit
						if(SSD_SDO->t!=CSD_SDO->t){
							Abort_SDO_transfert(SID_SDO->Mux,0x05030000);
							return CO_ERROR_ILLEGAL_ARGUMENT;
						}
						else
							return CO_ERROR_NO ;
					
						}
				}
				else
			
					return CO_ERROR_ILLEGAL_ARGUMENT;
			
			return CO_ERROR_ILLEGAL_ARGUMENT;
			}	
		}
			
		else
			
			return CO_ERROR_ILLEGAL_ARGUMENT;
		
		} */
	}
	CIU_SDO->ccs= (Buffer[0]& 0xE0)>>5;
	if(CIU_SDO->ccs==0x02){
		//décodage du request envoyé par le client COB-ID  client(buffer)
		CIU_SDO->x=Buffer[0]&0x1F;
		CIU_SDO->Mux[0]=Buffer[1];
		CIU_SDO->Mux[1]=Buffer[2];
		CIU_SDO->Mux[2]=Buffer[3];
		CIU_SDO->reserv[0]=reserved;
		CIU_SDO->reserv[1]=reserved;
		CIU_SDO->reserv[2]=reserved;
		CIU_SDO->reserv[3]=reserved;
		
	
		printf("la donné du Mux est egle %d",CIU_SDO->Mux);
		//write confirmation return(e,s)
		
		//choisir les valeurs de s et de e
		SIU_SDO->e==0x01;
		SIU_SDO->s==0x01;
		if((SIU_SDO->e==0x01) && (SIU_SDO->s==0x01)){
			
			buf=DO_read( CIU_SDO->Mux);
			//le champ n est valide
			/*codage de la trame pour envoyer*/
			//affectation de la data
			SIU_SDO->Data[3]=((buf&0xFF000000)>>24);
			SIU_SDO->Data[2]=((buf&0x00FF0000)>>16);
			SIU_SDO->Data[1]=((buf&0x0000FF00)>>8);
			SIU_SDO->Data[0]= (buf&0x000000FF);
			
			//choix de n=11;
			BufferSend[0]=(SIU_SDO->s)>>7|(SIU_SDO->e)>>6|0x4C;
			//on a mis le toggle bit a zero
			BufferSend[1]=CIU_SDO->Mux[0];
			BufferSend[2]=CIU_SDO->Mux[1];
			BufferSend[3]=CIU_SDO->Mux[2];
			BufferSend[4]=SIU_SDO->Data[0];
			BufferSend[5]=SIU_SDO->Data[1];
			BufferSend[6]=SIU_SDO->Data[2];
			BufferSend[7]=SIU_SDO->Data[3];
			
			
			//send(*BufferSend);
			//send confirmation upload sdo protocol
			
			return CO_ERROR_NO ;
			
		}
		
		
		else if ((SIU_SDO->e==0x01) && (SIU_SDO->s==0x00)){
			//le champ n est a 0
			/*codage de la trame pour envoyer*/
			buf=DO_read( CIU_SDO->Mux);
			//le champ n est valide
			/*codage de la trame pour envoyer*/
			//affectation de la data
			SIU_SDO->Data[0]=(buf&0xFF000000);
			SIU_SDO->Data[1]=(buf&0x00FF0000);
			SIU_SDO->Data[2]=(buf&0x0000FF00);
			SIU_SDO->Data[3]=(buf&0x000000FF);
			
			
			BufferSend[0]=(SIU_SDO->s)>>7|(SIU_SDO->e)>>6|0x40;
			//on a mis le toggle bit a zero
			BufferSend[1]=SIU_SDO->Mux[0];
			BufferSend[2]=SIU_SDO->Mux[1];
			BufferSend[3]=SIU_SDO->Mux[2];
			BufferSend[4]=SIU_SDO->Data[0];
			BufferSend[5]=SIU_SDO->Data[1];
			BufferSend[6]=SIU_SDO->Data[2];
			BufferSend[7]=SIU_SDO->Data[3];
			
			
			//send(*BufferSend);
			//send confirmation upload sdo protocol
			
			return CO_ERROR_NO ;
		
		}
		/* else if((SIU_SDO->e==0x00) && (SIU_SDO->s==0x01)){
			codage de la trame pour envoyer
			// n est mise a 0 car n'est pas valide
			
			BufferSend[0]=(SIU_SDO->s)>>7|(SIU_SDO->e)>>6|0x40;
			// on a mis le toggle bit a zero
			BufferSend[1]=SIU_SDO->Mux[0];
			BufferSend[2]=SIU_SDO->Mux[1];
			BufferSend[3]=SIU_SDO->Mux[2];
			BufferSend[4]=SIU_SDO->Data[0];
			BufferSend[5]=SIU_SDO->Data[1];
			BufferSend[6]=SIU_SDO->Data[2];
			BufferSend[7]=SIU_SDO->Data[3];
			
			// send(*BufferSend);
			// send confirmation
			// wait for the client to send request
			decodage du request upload SDO segment envoyé par le client
				
			CSU_SDO->ccs= (Buffer[0]& 0xE0)>>5;
			CSU_SDO->t=(Buffer[0]&0x40)>>2;
			CSU_SDO->x=Buffer[0]&0x0F;
	
			if(CSU_SDO->ccs==0x03){
				// ecrire la trame pour envoyer
				codage de la trame pour envoyer
				
				BufferSend[0]=(SSU_SDO->c)>>7|(SSU_SDO->n)>>4|0x00;//car scs=0 et t=0 juste au début
				
				BufferSend[1]=SSU_SDO->seg_data[0];
				BufferSend[2]=SSU_SDO->seg_data[1];
				BufferSend[3]=SSU_SDO->seg_data[2];
				BufferSend[4]=SSU_SDO->seg_data[3];
				BufferSend[5]=SSU_SDO->seg_data[4];
				BufferSend[6]=SSU_SDO->seg_data[5];
				BufferSend[7]=SSU_SDO->seg_data[6];
			
				// send(*BufferSend);
				// send frame of confirmation
			
				printf("le champ c de la trame est %d",SSU_SDO->c);
			
				while(SSU_SDO->c==0x00){
					// wait for the request client
					// décodage de la trame	
					CSU_SDO->ccs= (Buffer[0]& 0xE0)>>5;
					CSU_SDO->t=(Buffer[0]&0x40)>>2;
					CSU_SDO->x=Buffer[0]&0x0F;
				
					
					// ecrire la trame pour envoyer
					codage de la trame pour envoyer
					if(CSU_SDO->t==0x00){
						BufferSend[0]=(SSU_SDO->c)>>7|(SSU_SDO->n)>>4|0x10;
					}
					else{
						BufferSend[0]=(SSU_SDO->c)>>7|(SSU_SDO->n)>>4|0x00;
					}
							// on a mis le toggle bit a zero
									
					BufferSend[1]=SSU_SDO->seg_data[0];
					BufferSend[2]=SSU_SDO->seg_data[1];
					BufferSend[3]=SSU_SDO->seg_data[2];
					BufferSend[4]=SSU_SDO->seg_data[3];
					BufferSend[5]=SSU_SDO->seg_data[4];
					BufferSend[6]=SSU_SDO->seg_data[5];
					BufferSend[7]=SSU_SDO->seg_data[6];
					// send(*BufferSend);
					// send frame confirmation
					
					
					// test toggle bit
					if(SSU_SDO->t!=CSU_SDO->t){
						Abort_SDO_transfert(CIU_SDO->Mux,0x05030000);
						return CO_ERROR_ILLEGAL_ARGUMENT;
					}
					else
						return CO_ERROR_NO ;				
				}			
			}
			else{
				return CO_ERROR_ILLEGAL_ARGUMENT;
			}
		}
		else{	
			return CO_ERROR_ILLEGAL_ARGUMENT;
		} */
	}
	
	
}	
	/**********************************
    le traitement fait par le client
    ***********************************/
 
else if ((COB_ID >= CAN_ID_TSDO) && (COB_ID <= CAN_ID_TSDO+CANOPEN_MAX_ID))
	{
	
	if(DLC != 8) return CO_ERROR_RX_MSG_DLC;       

	if(CID_SDO->ccs==0x01){
	
	//choisir le e et le s et n;
	CID_SDO->s=0x01;
	CID_SDO->e=0x01;
	CID_SDO->n=0x11;
	
	//traitement pour initialiser data et Mux
	C_sdo[0] = &C_Buffer1;
	C_sdo[1] = &C_Buffer2;
	C_sdo[2] = &C_Buffer3;
	C_sdo[3] = &C_Buffer4;
	C_sdo[4] = &C_Buffer5;
	c_point=C_sdo[d];
	
	CID_SDO->Mux[0]=*(c_point+0);
	CID_SDO->Mux[1]=*(c_point+1);
	CID_SDO->Mux[2]=*(c_point+2);
	CID_SDO->Data[0]=*(c_point+3);
	CID_SDO->Data[1]=*(c_point+4);
	CID_SDO->Data[2]=*(c_point+5);
	CID_SDO->Data[3]=*(c_point+6);
	
    /*codage de la trame pour envoyer*/
    BufferSend[0]= (CID_SDO->s)>>7|(CID_SDO->e)>>6|(CID_SDO->n)>>4|0x20;
	BufferSend[1]= CID_SDO->Mux[0];
	BufferSend[2]= CID_SDO->Mux[1];
	BufferSend[3]= CID_SDO->Mux[2];
	BufferSend[4]= CID_SDO->Data[0];
	BufferSend[5]= CID_SDO->Data[1];
	BufferSend[6]= CID_SDO->Data[2];
	BufferSend[7]= CID_SDO->Data[3];
    
    d++;
    //send(*BufferSend);
    //send request Initiate SDO download
	
	
	//wait for the confirm from the server
	//if recevoir message from server COB-ID du serveur(Buffer)
	SID_SDO->scs= (Buffer[0]& 0xE0)>>5;	
	
	
	printf("le champ scs est %d",SID_SDO->scs);
	if(SID_SDO->scs ==0x03){
		/*décodage confirm message*/
		SID_SDO->x=Buffer[0]&0x1F;
		SID_SDO->Mux[0]=Buffer[1];
		SID_SDO->Mux[1]=Buffer[2];
		SID_SDO->Mux[2]=Buffer[3];
		SID_SDO->reserv[0]=reserved;
		SID_SDO->reserv[1]=reserved;
		SID_SDO->reserv[2]=reserved;
		SID_SDO->reserv[3]=reserved;
		
		}
			//traitement pour initialiser data et Mux
	C_seg_sdo[0] = &C_Buffer1;
	C_seg_sdo[1] = &C_Buffer2;
	C_seg_sdo[2] = &C_Buffer3;
	C_seg_sdo[3] = &C_Buffer4;
	C_seg_sdo[4] = &C_Buffer5;
	c_seg_point=C_seg_sdo[d_seg];
	
	CSD_SDO->ccs== 0;
	CSD_SDO->t==0;
	CSD_SDO->n==7;
	CSD_SDO->c==1;
	
	CSD_SDO->seg_data[0]=*(c_seg_point+3);
	CSD_SDO->seg_data[1]=*(c_seg_point+4);
	CSD_SDO->seg_data[2]=*(c_seg_point+5);
	CSD_SDO->seg_data[3]=*(c_seg_point+6);
	CSD_SDO->seg_data[4]=0;
	CSD_SDO->seg_data[5]=0;
	CSD_SDO->seg_data[6]=0;
	CSD_SDO->seg_data[7]=0;
		printf("e est egal a %d",CID_SDO->e);
		 if(CID_SDO->e==0x00){		
			// ecrire la trame a envoyé
			//codage de la trame pour envoyer
			BufferSend[0]= (CSD_SDO->c)>>5|(CSD_SDO->n)>>4|0x00;
			BufferSend[1]= CSD_SDO->seg_data[0];
			BufferSend[2]= CSD_SDO->seg_data[1];
			BufferSend[3]= CSD_SDO->seg_data[2];
			BufferSend[4]= CSD_SDO->seg_data[3];
			BufferSend[5]= CSD_SDO->seg_data[4];
			BufferSend[6]= CSD_SDO->seg_data[5];
			BufferSend[7]= CSD_SDO->seg_data[6];
			// send(*BufferSend);
			d_seg++;
			// wait for confirm from server
		
			//décodage de la trame
			SSD_SDO->scs= (Buffer[0]& 0xE0)>>5;	
			SSD_SDO->t=(Buffer[0]&0x40)>>2;
			SSD_SDO->x=Buffer[0]&0x0F;
		
				while(CSD_SDO->c==0x00){
					// wait for confirm message from server
					//décodage de la trame
					SSD_SDO->scs= (Buffer[0]& 0xE0)>>5;	
					SSD_SDO->t=(Buffer[0]&0x40)>>2;
					SSD_SDO->x=Buffer[0]&0x0F;
				
					// ecrire la trame a envoyer
					//codage de la trame pour envoyer
					if(CSD_SDO->t==0x01){
						BufferSend[0]=(CSD_SDO->c)>>7|(CSD_SDO->n)>>4|0x00;
					}
					else
					{
						BufferSend[0]=(CSD_SDO->c)>>7|(CSD_SDO->n)>>4|0x10;
					}
					// on a mis le toggle bit a zero
					BufferSend[1]=CSD_SDO->seg_data[0];
					BufferSend[2]=CSD_SDO->seg_data[1];
					BufferSend[3]=CSD_SDO->seg_data[2];
					BufferSend[4]=CSD_SDO->seg_data[3];
					BufferSend[5]=CSD_SDO->seg_data[4];
					BufferSend[6]=CSD_SDO->seg_data[5];
					BufferSend[7]=CSD_SDO->seg_data[6];
					// send(*BufferSend);
					// send frame confirmation
					
					
					// test toggle bit
					if(CSD_SDO->t!=SSD_SDO->t){
						Abort_SDO_transfert(SID_SDO->Mux,0x05030000);
						return CO_ERROR_ILLEGAL_ARGUMENT;
					}
					else
						return CO_ERROR_NO ;
					
				}
			}
			else{
				return CO_ERROR_ILLEGAL_ARGUMENT;
			}
			
		

	
	}
	if(CIU_SDO->ccs==0x02){
	//ecrire la trame à envoyé
    printf("le buffer est %d", *Buffer);
	//initialisation des Mux
	S_pdo[0]=&M_Buffer0;
	S_pdo[1]=&M_Buffer1;
	S_pdo[2]=&M_Buffer2;
	S_pdo[3]=&M_Buffer3;
	S_pdo[4]=&M_Buffer4;
	S_pdo[5]=&M_Buffer5;
	s_point=S_pdo[s];
		
	
	CIU_SDO->Mux[0]=*(s_point+0);
	CIU_SDO->Mux[0]=*(s_point+1);
	CIU_SDO->Mux[0]=*(s_point+2);
	
    /*codage de la trame pour envoyer*/
    BufferSend[0]= 0x40;
	BufferSend[1]= CIU_SDO->Mux[0];
	BufferSend[2]= CIU_SDO->Mux[1];
	BufferSend[3]= CIU_SDO->Mux[2];
	BufferSend[4]= reserved;
	BufferSend[5]= reserved;
	BufferSend[6]= reserved;
	BufferSend[7]= reserved;
    
    s++;
    //send(*BufferSend);
    //send request Initiate SDO download
	
	//if receive frame from server COB-ID du serveur(buffer)
	//wait for the confirm from the server
	
	SIU_SDO->scs= (Buffer[0]& 0xE0)>>5;	
	
	
	printf("le champ scs est %d",SIU_SDO->scs);
	if(SIU_SDO->scs ==0x02){
		
		//décodage de la trame confirm envoyé par serveur
		SIU_SDO->x=(Buffer[0]&0x40)>>2;
		SIU_SDO->n=(Buffer[0]&0x0C)>>2;
		SIU_SDO->e=(Buffer[0]&0x02)>>1;
		SIU_SDO->s=Buffer[0]&0x01;
		SIU_SDO->Mux[0]=Buffer[1];
		SIU_SDO->Mux[1]=Buffer[2];
		SIU_SDO->Mux[2]=Buffer[3];
		SIU_SDO->Data[0]=Buffer[4];
		SIU_SDO->Data[1]=Buffer[5];
		SIU_SDO->Data[2]=Buffer[6];
		SIU_SDO->Data[3]=Buffer[7];
		
		printf("e est egal a %d",SIU_SDO->e);
		printf("s est egal a %d",SIU_SDO->s);
		
		
		if(SIU_SDO->e==0x01 && SIU_SDO->s==0x01){
			//n est valide
			printf("la donné du Mux est egle %d",SIU_SDO->Mux);
			printf("la donné du n est egle %d",SIU_SDO->n);
			printf("la donné du Data est egle %d",SIU_SDO->Data);
			return CO_ERROR_NO;
		}
		else if(SIU_SDO->e==0x01 && SIU_SDO->s==0x00)
		{
			if(SIU_SDO->n==0x00){
			printf("la donné du Mux est egle %d",SIU_SDO->Mux);
			printf("la donné du Data est egle %d",SIU_SDO->Data);
			return CO_ERROR_NO;
			}
			else return CO_ERROR_NO;
		}
			
/* 		else if (SIU_SDO->e==0x00 && SIU_SDO->s==0x01)
		{
			if(SIU_SDO->n==0x00){
				printf("la donné du Mux est egle %d",SIU_SDO->Mux);
				printf("la donné du Data est egle %d",SIU_SDO->Data);
				//write request upload SDO segment
				codage de la trame pour envoyer
				BufferSend[0]=0x60;
				//on a mis le toggle bit a zero
				BufferSend[1]=reserved;
				BufferSend[2]=reserved;
				BufferSend[3]=reserved;
				BufferSend[4]=reserved;
				BufferSend[5]=reserved;
				BufferSend[6]=reserved;
				BufferSend[7]=reserved;
			
				//send(*BufferSend);
				//send request upload SDO segment
			
				//wait pour que le serveur m'envoie la confirmation
				décodage for confirm segment
				SSU_SDO->scs= (Buffer[0]& 0xE0)>>5;	
				SSU_SDO->t=(Buffer[0]&0x40)>>2;
				SSU_SDO->n=(Buffer[0]&0x0E)>>1;
				SSU_SDO->c=Buffer[0]&0x01;
				SSU_SDO->seg_data[0]=Buffer[1];
				SSU_SDO->seg_data[1]=Buffer[2];
				SSU_SDO->seg_data[2]=Buffer[3];
				SSU_SDO->seg_data[3]=Buffer[4];
				SSU_SDO->seg_data[4]=Buffer[5];
				SSU_SDO->seg_data[5]=Buffer[6];
				SSU_SDO->seg_data[6]=Buffer[7];
		
				printf("le champ scs de la trame est %d",SSU_SDO->scs);
				if(SSU_SDO->scs==0x00){
				
					printf("le champ c de la trame est %d",SSU_SDO->c);
				
					while(SSU_SDO->c==0x00){
						//ecrire la trame a envoyer
						codage de la trame pour envoyer
						if(CSU_SDO->t==0x01){
							BufferSend[0]=0x70;
						}
						else
						{
							BufferSend[0]=0x60;
						}
						//on a mis le toggle bit a zero
						BufferSend[1]=reserved;
						BufferSend[2]=reserved;
						BufferSend[3]=reserved;
						BufferSend[4]=reserved;
						BufferSend[5]=reserved;
						BufferSend[6]=reserved;
						BufferSend[7]=reserved;
						//send(*BufferSend);
						//send frame request
					
						//wait pour que le serveur m'envoie la confirmation
						//décodage for confirm from server download sdo segment						SSU_SDO->t=(Buffer[0]&0x40)>>2;
						SSU_SDO->n=(Buffer[0]&0x0E)>>1;
						SSU_SDO->c=Buffer[0]&0x01;
						SSU_SDO->seg_data[0]=Buffer[1];
						SSU_SDO->seg_data[1]=Buffer[2];
						SSU_SDO->seg_data[2]=Buffer[3];
						SSU_SDO->seg_data[3]=Buffer[4];
						SSU_SDO->seg_data[4]=Buffer[5];
						SSU_SDO->seg_data[5]=Buffer[6];
						SSU_SDO->seg_data[6]=Buffer[7];
					
					
						//test toggle bit
						if(CSU_SDO->t!=SSU_SDO->t){
							Abort_SDO_transfert(SIU_SDO->Mux,0x05030000);
							return CO_ERROR_ILLEGAL_ARGUMENT;
						}
						else
							return CO_ERROR_NO ;
						
					
					}
				}
				else
			
					return CO_ERROR_ILLEGAL_ARGUMENT;
			
			}
			else return CO_ERROR_NO ;
			
		}
			
		else{
			
			return CO_ERROR_ILLEGAL_ARGUMENT;
		} */
		
	}
	else{		
		return CO_ERROR_ILLEGAL_ARGUMENT;
	}

	
}
}
//ce traitement va etre réaliser apres avoir tester le PDO et le regler avec une fonction de priorité

/*
else if (COB_ID == CAN_ID_NMT_SERVICE) {
return 0;
}
else if ((COB_ID >= CAN_ID_TPDO2) && (COB_ID <= CAN_ID_TPDO2+CANOPEN_MAX_ID)){   
}

else if ((COB_ID >= CAN_ID_RPDO2) && (COB_ID <= CAN_ID_RPDO2+CANOPEN_MAX_ID)){   
}

else if ((COB_ID >= CAN_ID_TPDO3) && (COB_ID <= CAN_ID_TPDO3+CANOPEN_MAX_ID)){   
}

else if ((COB_ID >= CAN_ID_RPDO3) && (COB_ID <= CAN_ID_RPDO3+CANOPEN_MAX_ID)){   
}

else if ((COB_ID >= CAN_ID_TPDO4) && (COB_ID <= CAN_ID_TPDO4+CANOPEN_MAX_ID)){   
}

else if ((COB_ID >= CAN_ID_RPDO4) && (COB_ID <= CAN_ID_RPDO4+CANOPEN_MAX_ID)){   
} 
else if ((COB_ID >= CAN_ID_HEARTBEAT) && (COB_ID <= CAN_ID_HEARTBEAT+CANOPEN_MAX_ID)){

}
else if ((COB_ID >= CAN_ID_EMERGENCY) && (COB_ID <= CAN_ID_EMERGENCY+CANOPEN_MAX_ID)){   

return 0;
}

else if (COB_ID == CAN_ID_TIME_STAMP ) {

return 0;
}
*/

	
return 0;	
}

//la fonction abort qui fait appel a l'erreur survenue
void Abort_SDO_transfert(UNSIGNED8 Mux[3],UNSIGNED32 abort_code){

		BufferSend[0]=0x80;
		BufferSend[1]=Mux[0];
		BufferSend[2]=Mux[1];
		BufferSend[3]=Mux[2];
		BufferSend[4]=abort_code & 0x000000FF;
		BufferSend[5]=(abort_code & 0x0000FF00)>>8;
		BufferSend[6]=(abort_code & 0x00FF0000)>>16;
		BufferSend[7]=(abort_code & 0xFF000000)>>24;
		//send(*BufferSend);
		//send frame request
	
}


//ecriture Dictionnaire Object "download" SDO
void SDO_DO_stockage(UNSIGNED8 Mux[3],UNSIGNED8 data[4]){
	
	if((Mux[0]==S_Buffer0[0])&&(Mux[1]==S_Buffer0[1])){
		if(Mux[2]==S_Buffer0[2]){
			S_Buffer0[3]=data[0];
			S_Buffer0[4]=data[1];
			S_Buffer0[5]=data[2];
			S_Buffer0[6]=data[3];
		}
	}
	else if((Mux[0]==S_Buffer1[0])&&(Mux[1]==S_Buffer1[1])){
		if(Mux[2]==S_Buffer1[2]){
			S_Buffer1[3]=data[0];
			S_Buffer1[4]=data[1];
			S_Buffer1[5]=data[2];
			S_Buffer1[6]=data[3];
		}
	}
	else if((Mux[0]==S_Buffer2[0])&&(Mux[1]==S_Buffer2[1])){
		if(Mux[2]==S_Buffer2[2]){
			S_Buffer2[3]=data[0];
			S_Buffer2[4]=data[1];
			S_Buffer2[5]=data[2];
			S_Buffer2[6]=data[3];
		}
	}
	else if((Mux[0]==S_Buffer3[0])&&(Mux[1]==S_Buffer3[1])){
		if(Mux[2]==S_Buffer3[2]){
			S_Buffer3[3]=data[0];
			S_Buffer3[4]=data[1];
			S_Buffer3[5]=data[2];
			S_Buffer3[6]=data[3];
		}
	}
	else if((Mux[0]==S_Buffer4[0])&&(Mux[1]==S_Buffer4[1])){
		if(Mux[2]==S_Buffer4[2]){
			S_Buffer4[3]=data[0];
			S_Buffer4[4]=data[1];
			S_Buffer4[5]=data[2];
			S_Buffer4[6]=data[3];
		}
	}
	else if((Mux[0]==S_Buffer5[0])&&(Mux[1]==S_Buffer5[1])){
		if(Mux[2]==S_Buffer5[2]){
			S_Buffer5[3]=data[0];
			S_Buffer5[4]=data[1];
			S_Buffer5[5]=data[2];
			S_Buffer5[6]=data[3];
		}
	}
}

//lecture Dictionnaire Object "upload"
UNSIGNED32 DO_read(UNSIGNED8 Mux[2]){
	if((Mux[0]==C_Buffer0[0])&&(Mux[1]==C_Buffer0[1])){
		if(Mux[2]==C_Buffer0[2]){
			buf=((C_Buffer0[6]<<24)|(C_Buffer0[5]<<16)|(C_Buffer0[4]<<8)|C_Buffer0[3]);
			return buf;
		}
	}
	else if((Mux[0]==C_Buffer1[0])&&(Mux[1]==C_Buffer1[1])){
		if(Mux[2]==C_Buffer1[2]){
			buf=((C_Buffer1[6]<<24)|(C_Buffer1[5]<<16)|(C_Buffer1[4]<<8)|C_Buffer1[3]);
			return buf;
		}
	}
	else if((Mux[0]==C_Buffer2[0])&&(Mux[1]==C_Buffer2[1])){
		if(Mux[2]==C_Buffer2[2]){
			buf=((C_Buffer2[6]<<24)|(C_Buffer2[5]<<16)|(C_Buffer2[4]<<8)|C_Buffer2[3]);
			return buf;
		}
	}
	else if((Mux[0]==C_Buffer3[0])&&(Mux[1]==C_Buffer3[1])){
		if(Mux[2]==C_Buffer3[2]){
			buf=((C_Buffer3[6]<<24)|(C_Buffer3[5]<<16)|(C_Buffer3[4]<<8)|C_Buffer3[3]);
			return buf;
		}
	}
	else if((Mux[0]==C_Buffer4[0])&&(Mux[1]==C_Buffer4[1])){
		if(Mux[2]==C_Buffer4[2]){
			buf=((C_Buffer4[6]<<24)|(C_Buffer4[5]<<16)|(C_Buffer4[4]<<8)|C_Buffer4[3]);
			return buf;
		}
	}
	else if((Mux[0]==C_Buffer5[0])&&(Mux[1]==C_Buffer5[1])){
		if(Mux[2]==C_Buffer5[2]){
			buf=((C_Buffer5[6]<<24)|(C_Buffer5[5]<<16)|(C_Buffer5[4]<<8)|C_Buffer5[3]);
			return buf;
		}
	}
return 0;
}


//la fontion mapping qui prépare le buffer de mappage
UNSIGNED32 Mapping_appel(UNSIGNED8 Mux1[2],UNSIGNED8 Mux2[2]){
	//chercher dans la partie du mux1 et le stocker dans le buffer, ensuite chercher le 2eme 
	//mux et le stocker dans la partie 2 du buffer
	
	if((Mux1[0]==M_Buffer0[0])&&(Mux1[1]==M_Buffer0[1])){
		if(Mux1[2]==M_Buffer0[2]){
			mapping=((M_Buffer0[4]<<8)|M_Buffer0[3]);
			
		}
	}
	else if((Mux1[0]==M_Buffer1[0])&&(Mux1[1]==M_Buffer1[1])){
		if(Mux1[2]==M_Buffer1[2]){
			mapping=((M_Buffer1[4]<<8)|M_Buffer1[3]);
			
		}
	}
	else if((Mux1[0]==M_Buffer2[0])&&(Mux1[1]==M_Buffer2[1])){
		if(Mux1[2]==M_Buffer2[2]){
			mapping=((M_Buffer2[4]<<8)|M_Buffer2[3]);
			
		}
	}
	else if((Mux1[0]==M_Buffer3[0])&&(Mux1[1]==M_Buffer3[1])){
		if(Mux1[2]==M_Buffer3[2]){
			mapping=((M_Buffer3[4]<<8)|M_Buffer3[3]);
			
		}
	}
	else if((Mux1[0]==M_Buffer4[0])&&(Mux1[1]==M_Buffer4[1])){
		if(Mux1[2]==M_Buffer4[2]){
			mapping=((M_Buffer4[4]<<8)|M_Buffer4[3]);
			
		}
	}
	else if((Mux1[0]==M_Buffer5[0])&&(Mux1[1]==M_Buffer5[1])){
		if(Mux1[2]==M_Buffer5[2]){
			mapping=((M_Buffer5[4]<<8)|M_Buffer5[3]);
			
		}
	}
	//traitement pour le Mux 2
	if((Mux2[0]==M_Buffer0[0])&&(Mux2[1]==M_Buffer0[1])){
		if(Mux2[2]==M_Buffer0[2]){
			mapping=((M_Buffer0[4]<<24)|(M_Buffer0[3]<<16)|mapping);
			return mapping;
		}
	}
	else if((Mux2[0]==M_Buffer1[0])&&(Mux2[1]==M_Buffer1[1])){
		if(Mux2[2]==M_Buffer1[2]){
			mapping=((M_Buffer1[4]<<24)|(M_Buffer1[3]<<16)|mapping);
			return mapping;
		}
	}
	else if((Mux2[0]==M_Buffer2[0])&&(Mux2[1]==M_Buffer2[1])){
		if(Mux2[2]==M_Buffer2[2]){
			mapping=((M_Buffer2[4]<<24)|(M_Buffer2[3]<<16)|mapping);
			return mapping;
		}
	}
	else if((Mux2[0]==M_Buffer3[0])&&(Mux2[1]==M_Buffer3[1])){
		if(Mux2[2]==M_Buffer3[2]){
			mapping=((M_Buffer3[4]<<24)|(M_Buffer3[3]<<16)|mapping);
			return mapping;
		}
	}
	else if((Mux2[0]==M_Buffer4[0])&&(Mux2[1]==M_Buffer4[1])){
		if(Mux2[2]==M_Buffer4[2]){
			mapping=((M_Buffer4[4]<<24)|(M_Buffer4[3]<<16)|mapping);
			return mapping;
		}
	}
	else if((Mux2[0]==M_Buffer5[0])&&(Mux2[1]==M_Buffer5[1])){
		if(Mux2[2]==M_Buffer5[2]){
			mapping=((M_Buffer5[4]<<24)|(M_Buffer5[3]<<16)|mapping);
			return mapping;
		}
	}
return 0;
}

void sleep(UNSIGNED32 n) {
	int i =0;
	
	do{
		int c;int a=0,b=0;c=a+b;
		i++;
	}
	while(i<=n);

}

void timer(){
//c'est un timer pour 
	for(;;){
		if(milliseconds==0x0A){
			++seconds;
			milliseconds=0;
		}
		if(seconds==0x3C){
			++minutes;
			seconds=0;
		}
		if(minutes==0x3C){
			++hours;
			minutes=0;
		}

		++milliseconds;
		sleep(5);
		if(minutes==Sync_counter){
			break;
		}
	}
}

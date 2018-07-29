/*
*********************************************************************************************************
*
*                                        BOARD SUPPORT PACKAGE
*
*                                     ST Microelectronics STM32
*                                              with the
*                                   IAR STM322xG Evaluation Board
*
* Filename      : bsp_eth_conf.h
* Version       : V2.00
* Programmer(s) : Michael Vysotsky
*********************************************************************************************************
*/
#ifndef _BSP_ETH_CONF_H
#define _BSP_ETH_CONF_H

/* Ethernet pins configuration ************************************************/
   /*
        ETH_MDIO -------------------------> PA2
        ETH_MDC --------------------------> PC1
        ETH_PPS_OUT ----------------------> PB5
        ETH_MII_CRS ----------------------> PH2
        ETH_MII_COL ----------------------> PH3
        ETH_MII_RX_ER --------------------> PI10
        ETH_MII_RXD2 ---------------------> PH6
        ETH_MII_RXD3 ---------------------> PH7
        ETH_MII_TX_CLK -------------------> PC3
        ETH_MII_TXD2 ---------------------> PC2
        ETH_MII_TXD3 ---------------------> PB8
        ETH_MII_RX_CLK/ETH_RMII_REF_CLK---> PA1
        ETH_MII_RX_DV/ETH_RMII_CRS_DV ----> PA7
        ETH_MII_RXD0/ETH_RMII_RXD0 -------> PC4
        ETH_MII_RXD1/ETH_RMII_RXD1 -------> PC5
        ETH_MII_TX_EN/ETH_RMII_TX_EN -----> PG11
        ETH_MII_TXD0/ETH_RMII_TXD0 -------> PG13
        ETH_MII_TXD1/ETH_RMII_TXD1 -------> PG14
                                                  */
#define ETH_MDIO_PORTA
#define ETH_MDC_PORTC
#define ETH_PPS_OUT_PORTB
#define ETH_MII_CRS_PORTH
#define ETH_MII_COL_PORTH
#define ETH_MII_RX_ER_PORTI
#define ETH_MII_RXD2_PORTH
#define ETH_MII_RXD3_PORTH
#define ETH_MII_TX_CLK_PORTC
#define ETH_MII_TXD2_PORTC
#define ETH_MII_TXD3_PORTB
#define ETH_MII_RX_CLK_PORTA
#define ETH_MII_RX_DV_PORTA
#define ETH_MII_RXD0_PORTC
#define ETH_MII_RXD1_PORTC
#define ETH_MII_TX_EN_PORTG
#define ETH_MII_TXD0_PORTG
#define ETH_MII_TXD1_PORTG

#endif
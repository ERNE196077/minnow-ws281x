#ifndef SPI_H_
#define SPI_H_
#endif /* DMA_H_ */



#define SPI_BAR 			0x90c18000
#define SPI_SSP_GENERAL_OFFSET	(0x400 / 4)



typedef struct{
u_int32_t __sscr0__;
#define SPI_SSP_SSCR0_MOD_NORMALSSPMODE				(0 << 31)
#define SPI_SSP_SSCR0_MOD_NETWORKMODE				(1 << 31)
#define SPI_SSP_SSCR0_ACS_CLOCKBYNCSANDECS			(0 << 30)
#define SPI_SSP_SSCR0_ACS_CLOCKBYAUDIOCLOCK			(1 << 30)
#define SPI_SSP_SSCR0_TIM_INTERRUPTONFIFOUNDERRUN	(0 << 23)
#define SPI_SSP_SSCR0_TIM_NOINTERRUPTFIFOUNDERRUN	(1 << 23)
#define SPI_SSP_SSCR0_RIM_INTERRUPTONFIFOOVERRUN	(0 << 22)
#define SPI_SSP_SSCR0_RIM_NOINTERRUPTFIFOOVERRUN	(1 << 22)
#define SPI_SSP_SSCR0_NCS_CLOCKBYECS				(0 << 21)
#define SPI_SSP_SSCR0_NCS_CLOCKBYNCSNETWORKCLOCK	(1 << 21)
#define SPI_SSP_SSCR0_EDSS_ZEROPREPENDTODSS			(0 << 20)
#define SPI_SSP_SSCR0_EDSS_ONEPREPENDTODSS			(1 << 20)
#define SPI_SSP_SSCR0_SCR_SERIALCLOCKRATE(value)	(value << 8)	// 0 - 4095
#define SPI_SSP_SSCR0_SSE_SSPDISABLE				(0 << 7)
#define SPI_SSP_SSCR0_SSE_SSPENABLE					(1 << 7)
#define SPI_SSP_SSCR0_ECS_CLOCKFROMONCHIPCLOCK		(0 << 6)
#define SPI_SSP_SSCR0_ECS_EXTERNALCLOCKFROMGPIO		(1 << 6)
#define SPI_SSP_SSCR0_FRF_MOTOROLA					(0 << 4)
#define SPI_SSP_SSCR0_FRF_TEXASINSTRUMENTS			(1 << 4)
#define SPI_SSP_SSCR0_FRF_NATIONALSEMICONDUCTOR		(2 << 4)
#define SPI_SSP_SSCR0_FRF_PROGRAMMABLE				(3 << 4)
#define SPI_SSP_SSCR0_DSS_DATASIZESELECT(value)		(value)			// 4 bits. If EDSS is 1, it appends one 1 at the value of these bits.

u_int32_t __sscr1__;
#define SPI_SSP_SSCR1_TTELP_TXDTRISTATEONCLOCKEDGE	(0 << 31)
#define SPI_SSP_SSCR1_TTELP_TXDTRISTATEAFTERCLKEDGE	(1 << 31)
#define SPI_SSP_SSCR1_TTE_TXDNOTTRISTATED			(0 << 30)
#define SPI_SSP_SSCR1_TTE_TXDTRISTATEWHENNOTRANSMIT	(1 << 30)
#define SPI_SSP_SSCR1_EBCEI_INTERRUPTONBITCOUNTERR	(0 << 29)
#define SPI_SSP_SSCR1_EBCEI_NOINTERRUPTONBITCOUNTERR	(1 << 29)
#define SPI_SSP_SSCR1_SCFR_SLAVECLKFREERUNNING		(0 << 28)
#define SPI_SSP_SSCR1_SCFR_SLAVECLKONLYONTRANSFER	(1 << 28)
#define SPI_SSP_SSCR1_ECRA_NOREQCLOCKFROMOTHERSSP	(0 << 27)
#define SPI_SSP_SSCR1_ECRA_REQCLOCKFROMOTHERSSP		(1 << 27)
#define SPI_SSP_SSCR1_ECRB_NOREQCLOCKFROMOTHERSSP	(0 << 26)
#define SPI_SSP_SSCR1_ECRB_REQCLOCKFROMOTHERSSP		(1 << 26)
#define SPI_SSP_SSCR1_SCLKDIR_MASTERMODECLOCK		(0 << 25)
#define SPI_SSP_SSCR1_SCLKDIR_SLAVEMODECLOCKRECEIVE	(1 << 25)
#define SPI_SSP_SSCR1_SFRMDIR_MASTERMODEFRAME		(0 << 24)
#define SPI_SSP_SSCR1_SFRMDIR_SLAVEMODEFRAMERECEIVE	(1 << 24)
#define SPI_SSP_SSCR1_RWOT_TRANSMITANDRECEIVE		(0 << 23)
#define SPI_SSP_SSCR1_RWOT_ONLYRECEIVEMODE			(1 << 23)
#define SPI_SSP_SSCR1_TRAIL_CPUHANDLETRAILINGBYTE	(0 << 22)
#define SPI_SSP_SSCR1_TRAIL_DMAHANDLETRAILINGBYTE	(1 << 22)
#define SPI_SSP_SSCR1_TSRE_DMATRANSMITREQDISABLE	(0 << 21)
#define SPI_SSP_SSCR1_TSRE_DMATRANSMITREQENABLE		(1 << 21)
#define SPI_SSP_SSCR1_RSRE_DMARECEIVEREQDISABLE		(0 << 20)
#define SPI_SSP_SSCR1_RSRE_DMARECEIVEREQENABLE		(1 << 20)
#define SPI_SSP_SSCR1_TINTE_NOINTERRUPTONTIMEOUT	(0 << 19)
#define SPI_SSP_SSCR1_TINTE_INTERRUPTONTIMEOUT		(1 << 19)
#define SPI_SSP_SSCR1_PINTE_NOTRAILINGBYTEINTERRUPT	(0 << 18)
#define SPI_SSP_SSCR1_PINTE_TRAILINGBYTEINTERRUPT	(1 << 18)
#define SPI_SSP_SSCR1_IFS_FRAMEPOLARITYBYTHEFORMAT	(0 << 17)
#define SPI_SSP_SSCR1_IFS_FRAMEPOLARITYINVERTED		(1 << 17)
#define SPI_SSP_SSCR1_RFT_RECEIVEFIFOTRIGTHRESHOLD(value)	(value << 10)	// 0 - 4095
#define SPI_SSP_SSCR1_TFT_TRANSMITFIFOTRIGTHRESHOLD(value)	(value << 6)	// 0 - 4095
#define SPI_SSP_SSCR1_MWDS_MICROWIRE8BITDATASIZE	(0 << 5)
#define SPI_SSP_SSCR1_MWDS_MICROWIRE16BITDATASIZE	(1 << 5)
#define SPI_SSP_SSCR1_SPH_MOTOROLACLKOFFATFRMSTART	(0 << 4)
#define SPI_SSP_SSCR1_SPH_MOTOROLACLKONATFRMSTART	(1 << 4)
#define SPI_SSP_SSCR1_SPO_MOTO
#define SPI_SSP_SSCR1_SPO_
#define SPI_SSP_SSCR1_LBM_
#define SPI_SSP_SSCR1_LBM_
#define SPI_SSP_SSCR1_TIE_
#define SPI_SSP_SSCR1_TIE_
#define SPI_SSP_SSCR1_RIE_
#define SPI_SSP_SSCR1_RIE_

u_int32_t __sssr__;
#define SPI_SSP_
u_int32_t __ssitr__;
#define SPI_SSP_
u_int32_t __ssdr__;
#define SPI_SSP_
u_int32_t __rsv_0x014__[5];
u_int32_t __ssto__;
#define SPI_SSP_
u_int32_t __sspsp__;
#define SPI_SSP_
u_int32_t __sstsa__;
#define SPI_SSP_
u_int32_t __ssrsa__;
#define SPI_SSP_
u_int32_t __sstss__;
#define SPI_SSP_
u_int32_t __ssacd__;
#define SPI_SSP_
u_int32_t __itf__;
#define SPI_SSP_
u_int32_t __sitf__;
#define SPI_SSP_
u_int32_t __sirf__;
#define SPI_SSP_
}__attribute__((packed)) ssp_control;

typedef struct{
u_int32_t __prv_clock_params__;
u_int32_t __resets__;
u_int32_t __general__;
u_int32_t __ssp_reg__;
u_int32_t __rsv_0x410__[2];
u_int32_t __spi_cs_ctrl__;
}__attribute__((packed)) ssp_general;

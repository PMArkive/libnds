/*---------------------------------------------------------------------------------

	SPI control for the ARM7

	Copyright (C) 2005 - 2011
		Michael Noland (joat)
		Jason Rogers (dovoto)
		Dave Murphy (WinterMute)

	This software is provided 'as-is', without any express or implied
	warranty.  In no event will the authors be held liable for any
	damages arising from the use of this software.

	Permission is granted to anyone to use this software for any
	purpose, including commercial applications, and to alter it and
	redistribute it freely, subject to the following restrictions:

	1.	The origin of this software must not be misrepresented; you
		must not claim that you wrote the original software. If you use
		this software in a product, an acknowledgment in the product
		documentation would be appreciated but is not required.
	2.	Altered source versions must be plainly marked as such, and
		must not be misrepresented as being the original software.
	3.	This notice may not be removed or altered from any source
		distribution.

---------------------------------------------------------------------------------*/

#ifndef SERIAL_ARM7_INCLUDE
#define SERIAL_ARM7_INCLUDE

#ifndef ARM7
#error Serial header is for ARM7 only
#endif


#include <nds/bios.h>
#include <calico/nds/arm7/gpio.h>
#include <calico/nds/arm7/spi.h>

// 'Networking'
#define REG_KEYXY	REG_RCNT_EXT
#define RTC_CR		REG_RCNT_RTC

#define REG_SIOCNT	(*(vu16*)0x04000128)

#define SIO_DATA8       (*(vu8*)0x0400012A)
#define SIO_DATA32      (*(vu32*)0x04000120)

// Fixme: Does the hardware still support 16 bit comms mode?
// BIOS makes use of 32 bit mode, so some regs still exist
#define SIO_MULTI_0     (*(vu16*)0x04000120)
#define SIO_MULTI_1     (*(vu16*)0x04000122)
#define SIO_MULTI_2     (*(vu16*)0x04000124)
#define SIO_MULTI_3     (*(vu16*)0x04000126)
#define SIO_MULTI_SEND  (*(vu16*)0x0400012A)

#define SerialWaitBusy spiWaitBusy

#define SPI_ENABLE  SPICNT_ENABLE
#define SPI_IRQ     SPICNT_IRQ_ENABLE
#define SPI_BUSY    SPICNT_BUSY

// meh
#define SPI_BAUD_4MHz    SpiBaud_4MHz
#define SPI_BAUD_2MHz    SpiBaud_2MHz
#define SPI_BAUD_1MHz    SpiBaud_1MHz
#define SPI_BAUD_512KHz  SpiBaud_512KHz
#define SPI_BAUD_8MHz    SpiBaud_8MHz // DSi only

// Pick the SPI transfer length
#define SPI_BYTE_MODE   (0<<10)
#define SPI_HWORD_MODE  (1<<10) // bugged/useless

// Pick the SPI device
#define SPI_DEVICE_POWER      SPICNT_DEVICE(SpiDev_PMIC)
#define SPI_DEVICE_FIRMWARE   SPICNT_DEVICE(SpiDev_NVRAM)
#define SPI_DEVICE_NVRAM      SPICNT_DEVICE(SpiDev_NVRAM)
#define SPI_DEVICE_TOUCH      SPICNT_DEVICE(SpiDev_TSC)
#define SPI_DEVICE_MICROPHONE SPICNT_DEVICE(SpiDev_TSC)

// When used, the /CS line will stay low after the transfer ends
// i.e. when we're part of a continuous transfer
#define SPI_CONTINUOUS       SPICNT_HOLD

// Firmware commands
#define FIRMWARE_WREN 0x06
#define FIRMWARE_WRDI 0x04
#define FIRMWARE_RDID 0x9F
#define FIRMWARE_RDSR 0x05
#define FIRMWARE_READ 0x03
#define FIRMWARE_PW   0x0A
#define FIRMWARE_PP   0x02
#define FIRMWARE_FAST 0x0B
#define FIRMWARE_PE   0xDB
#define FIRMWARE_SE   0xD8
#define FIRMWARE_DP   0xB9
#define FIRMWARE_RDP  0xAB

#endif

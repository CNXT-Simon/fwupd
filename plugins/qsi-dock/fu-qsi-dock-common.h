/*
 * Copyright (C) 2021 Richard Hughes <richard@hughsie.com>
 * Copyright (C) 2022 Kevin Chen <hsinfu.chen@qsitw.com>
 *
 * SPDX-License-Identifier: LGPL-2.1+
 */

#pragma once

#include <glib-object.h>

#define FU_QSI_DOCK_REPORT_ID 5

#define FU_QSI_DOCK_FIRMWARE_IDX_NONE	0x00
#define FU_QSI_DOCK_FIRMWARE_IDX_DMC_PD 0x01
#define FU_QSI_DOCK_FIRMWARE_IDX_DP	0x02
#define FU_QSI_DOCK_FIRMWARE_IDX_TBT4	0x04
#define FU_QSI_DOCK_FIRMWARE_IDX_USB3	0x08
#define FU_QSI_DOCK_FIRMWARE_IDX_USB2	0x10
#define FU_QSI_DOCK_FIRMWARE_IDX_AUDIO	0x20
#define FU_QSI_DOCK_FIRMWARE_IDX_I225	0x40
#define FU_QSI_DOCK_FIRMWARE_IDX_MCU	0x80

typedef struct __attribute__((packed)) {
	guint8 DMC[5];
	guint8 PD[5];
	guint8 DP5x[5];
	guint8 DP6x[5];
	guint8 TBT4[5];
	guint8 USB3[5];
	guint8 USB2[5];
	guint8 AUDIO[5];
	guint8 I255[5];
	guint8 MCU[2];
	guint8 bcdVersion[2];
} FuQsiDockIspVersionInMcu;

typedef enum {
	FU_QSI_DOCK_CMD1_BOOT = 0x11,
	FU_QSI_DOCK_CMD1_SYSTEM = 0x31,
	FU_QSI_DOCK_CMD1_MCU = 0x51,
	FU_QSI_DOCK_CMD1_SPI = 0x61,
	FU_QSI_DOCK_CMD1_I2C_VMM = 0x71,
	FU_QSI_DOCK_CMD1_I2C_CCG = 0x81,

	FU_QSI_DOCK_CMD1_MASS_MCU = 0xC0,
	FU_QSI_DOCK_CMD1_MASS_SPI,
	FU_QSI_DOCK_CMD1_MASS_I2C_VMM,
	FU_QSI_DOCK_CMD1_MASS_I2C_CY,
} FuQsiDockCmd;

typedef enum {
	FU_QSI_DOCK_CMD2_CMD_DEVICE_STATUS,
	FU_QSI_DOCK_CMD2_CMD_SET_BOOT_MODE,
	FU_QSI_DOCK_CMD2_CMD_SET_AP_MODE,
	FU_QSI_DOCK_CMD2_CMD_ERASE_AP_PAGE,
	FU_QSI_DOCK_CMD2_CMD_CHECKSUM,
	FU_QSI_DOCK_CMD2_CMD_DEVICE_VERSION,
	FU_QSI_DOCK_CMD2_CMD_DEVICE_PCB_VERSION,
	FU_QSI_DOCK_CMD2_CMD_DEVICE_SN,
} FuQsiDockCmd2_0x51;

typedef enum {
	FU_QSI_DOCK_CMD2_SPI_EXTERNAL_FLASH_INI,
	FU_QSI_DOCK_CMD2_SPI_EXTERNAL_FLASH_ERASE,
	FU_QSI_DOCK_CMD2_SPI_EXTERNAL_FLASH_CHECKSUM,
} FuQsiDockCmd2_0x61;

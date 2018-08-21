/*
 * Copyright (C) 2012-2016 Freescale Semiconductor, Inc.
 * Copyright (c) 2013, NVIDIA CORPORATION.  All rights reserved.
 *
 * SPDX-License-Identifier:	GPL-2.0
 */
#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

//#include <syscall.h>

//#include <stdint.h>

#include <fcntl.h>

#include <sys/stat.h>

#include <sys/types.h>

//#include <sys/ioctl.h>

//#include <string.h>

//#include <errno.h>

//#include <stdarg.h>


/* mxc SoC will enable watchdog at USB recovery mode

 * so, the user must service watchdog

 */



#define PACKAGE "umg"

#define VERSION "0.6"


#define UMG_DEV_NODE "/sys/devices/platform/soc/2100000.aips-bus/2184000.usb/ci_hdrc.0/gadget/lun0/file"
char *mmc_file_name = "/dev/mmcblk1";

/* for utp ioctl */

/*

 * this structure should be in sync with the same in

 * $KERNEL/drivers/usb/gadget/fsl_updater.c

 */





static int utp_file = -1;


void main() {
	printf("%s %s [built %s %s]\n", PACKAGE, VERSION, __DATE__, __TIME__);

	while (	(utp_file = open(mmc_file_name, O_RDWR)) == -1) {
  	printf("mmcblk1 dev open failed!\n");
	usleep(100000);		
	}

	close(utp_file);
	
	while (	(utp_file = open(UMG_DEV_NODE, O_RDWR)) == -1) {
  	printf("umg dev open failed!\n");
	usleep(100000);		
	}
	
	write(utp_file, mmc_file_name,13);
  
  while(1) usleep(50000);
}


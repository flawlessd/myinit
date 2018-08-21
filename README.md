# myinit
Each time you wish to use the SDK in a new shell session, you need to source the environment setup script e.g.
$ . /opt/fsl-imx-fb/4.1.15-2.0.0/environment-setup-cortexa9hf-neon-poky-linux-gnueabi
or 
$ source /opt/fsl-imx-fb/4.1.15-2.0.0/environment-setup-cortexa9hf-neon-poky-linux-gnueabi
 
$CC init.c -o init.o
$LD -static init.o -o init

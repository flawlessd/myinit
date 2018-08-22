
This toolchain builds static binaries. If you want to use the toolchain to build these types of libraries, you need to be sure your image has the appropriate static development libraries. Use the IMAGE_INSTALL variable inside your local.conf file to install the appropriate library packages. Following is an example using glibc static development libraries:
     IMAGE_INSTALL_append = " glibc-staticdev"

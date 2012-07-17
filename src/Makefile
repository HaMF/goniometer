    CC     = gcc
    CFLAGS = -pthread
 
    all: goinometer
 
    goinometer: brick_stepper.c bricklet_io4.c ip_connection.c
	$(CC) $(CFLAGS) -o $@ $^ $@.c
 
    clean: FRC
	rm -f goinometer goinometer.o
 
    # This pseudo target causes all targets that depend on FRC
    # to be remade even in case a file with the name of the target exists.
    # This works with any make implementation under the assumption that
    # there is no file FRC in the current directory.
    FRC:

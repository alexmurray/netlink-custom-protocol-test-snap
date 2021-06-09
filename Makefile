netlink-custom-protocol-test: netlink-custom-protocol-test.c
	gcc netlink-custom-protocol-test.c -o netlink-custom-protocol-test

install: netlink-custom-protocol-test
	install -d $(DESTDIR)/usr/bin
	install netlink-custom-protocol-test $(DESTDIR)/usr/bin/

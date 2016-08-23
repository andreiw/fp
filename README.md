fp/sfp
======

'fullpath', I suppose...

Like realpath, but never symlink
resolves the last component (or expects
it to exist).

Think of this as realpath with the most
obvious and expected behavior.

If invoked as 'sfp', prepends
user@host:, for paths consumable by scp.
This uses your hostname, so be careful.
At some point I may add some smarter behavior
falling back to IP addresses. Or not.
Probably never.

When used with no arguments, acts like pwd.
            
Building
--------

    $ make

Using
-----
    andreiw-az-linux:~/src/fp/ ./fp *
    /home/andreiw/src/fp/fp
    /home/andreiw/src/fp/fp.c
    /home/andreiw/src/fp/.git
    /home/andreiw/src/fp/Makefile
    /home/andreiw/src/fp/README.md
    /home/andreiw/src/fp/sfp

    andreiw-az-linux:~/src/fp/ ./sfp *
    andreiw@andreiw-az-linux:/home/andreiw/src/fp/fp
    andreiw@andreiw-az-linux:/home/andreiw/src/fp/fp.c
    andreiw@andreiw-az-linux:/home/andreiw/src/fp/.git
    andreiw@andreiw-az-linux:/home/andreiw/src/fp/Makefile
    andreiw@andreiw-az-linux:/home/andreiw/src/fp/README.md
    andreiw@andreiw-az-linux:/home/andreiw/src/fp/sfp

    andreiw-az-linux:~/src/fp/ ./fp
    /home/andreiw/src/fp

    andreiw-az-linux:~/src/fp/ ./sfp
    andreiw@andreiw-az-linux:/home/andreiw/src/fp

Contact Info
------------

Andrei Warkentin (andrey.warkentin@gmail.com).

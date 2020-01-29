Mac OS X Build Instructions and Notes
====================================
This guide will show you how to build qoinzd (headless client) for OSX.

Notes
-----

* Tested on OS X 10.12.

* All of the commands should be executed in a Terminal application. The
built-in one is located in `/Applications/Utilities`.

Preparation
-----------

You need to install XCode with all the options checked so that the compiler
and everything is available in /usr not just /Developer. XCode should be
available on your OS X installation media, but if not, you can get the
current version from https://developer.apple.com/xcode/. If you install
Xcode 4.3 or later, you'll need to install its command line tools. This can
be done in `Xcode > Preferences > Downloads > Components` and generally must
be re-done or updated every time Xcode is updated.

You will also need to install [Homebrew](http://brew.sh) in order to install library
dependencies.

The installation of the actual dependencies is covered in the Instructions
sections below.

Instructions: Homebrew
----------------------

#### Install dependencies using Homebrew

        brew install autoconf automake berkeley-db4 libtool miniupnpc openssl pkg-config protobuf qt5 libevent librsvg
        brew install boost@1.57
        brew link boost@1.57 --force

### Building `QOINZ`

1. Clone the github tree to get the source code and go into the directory.

        git clone https://github.com/qoinz-project/qoinz.git qoinz
        cd qoinz

2.  Build qoinzd:

        ./autogen.sh
        ./configure --with-gui=qt5
        make

3.  It is also a good idea to build and run the unit tests:

        make check

4.  (Optional) You can also install qoinzd to your path:

        make install

5.  (Optional) You can also build dmg image for qoinz-qt:

        make deploy


Use Qt Creator as IDE
------------------------
You can use Qt Creator as IDE, for debugging and for manipulating forms, etc.
Download Qt Creator from http://www.qt.io/download/. Download the "community edition" and only install Qt Creator (uncheck the rest during the installation process).

1. Make sure you installed everything through homebrew mentioned above
2. Do a proper ./configure --with-gui=qt5 --enable-debug
3. In Qt Creator do "New Project" -> Import Project -> Import Existing Project
4. Enter "qoinz-qt" as project name, enter src/qt as location
5. Leave the file selection as it is
6. Confirm the "summary page"
7. In the "Projects" tab select "Manage Kits..."
8. Select the default "Desktop" kit and select "Clang (x86 64bit in /usr/bin)" as compiler
9. Select LLDB as debugger (you might need to set the path to your installtion)
10. Start debugging with Qt Creator

Creating a release build
------------------------
You can ignore this section if you are building `qoinzd` for your own use.

qoinzd/qoinz-cli binaries are not included in the qoinz-qt.app bundle.

If you are building `qoinzd` or `qoinz-qt` for others, your build machine should be set up
as follows for maximum compatibility:

All dependencies should be compiled with these flags:

 -mmacosx-version-min=10.7
 -arch x86_64
 -isysroot $(xcode-select --print-path)/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk

Once dependencies are compiled, see release-process.md for how the qoinz-qt.app
bundle is packaged and signed to create the .dmg disk image that is distributed.

Running
-------

It's now available at `./qoinzd`, provided that you are still in the `src`
directory. We have to first create the RPC configuration file, though.

Run `./qoinzd` to get the filename where it should be put, or just try these
commands:

    echo -e "rpcuser=qoinzrpc\nrpcpassword=$(xxd -l 16 -p /dev/urandom)" > "/Users/${USER}/Library/Application Support/qoinz/qoinz.conf"
    chmod 600 "/Users/${USER}/Library/Application Support/qoinz/qoinz.conf"

The next time you run it, it will start downloading the blockchain, but it won't
output anything while it's doing this. This process may take several hours;
you can monitor its process by looking at the debug.log file, like this:

    tail -f $HOME/Library/Application\ Support/qoinz/debug.log

Other commands:
-------

    ./qoinzd -daemon # to start the qoinz daemon.
    ./qoinz-cli --help  # for a list of command-line options.
    ./qoinz-cli help    # When the daemon is running, to get a list of RPC commands

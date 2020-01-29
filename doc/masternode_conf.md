Multi masternode config
=======================

The multi masternode config allows you to control multiple masternodes from a single wallet. The wallet needs to have a valid collateral output of coins for each masternode type. To use this, place a file named masternode.conf in the data directory of your install:
 * Windows: %APPDATA%\Qoinz-Core\
 * Mac OS: ~/Library/Application Support/Qoinz-Core/
 * Unix/Linux: ~/.qoinz-core/

The new masternode.conf format consists of a space seperated text file. Each line consisting of an alias, IP address followed by port, masternode private key, collateral output transaction id, collateral output index, donation address and donation percentage (the latter two are optional and should be in format "address:percentage").

Example:
```
mn1 127.0.0.2:11148 7reApJbvHK28NeZ5XHatwRs9GKA2DwMPwDpCxEouE9N9QgR42Jq 2bcd3c84c84f87eaa86e4e56834c92927a07f9e18718810b92e0d0324456a67c 0
mn2 127.0.0.3:11148 7sUH8w88r8RXevYzadP4x5bVTvE11ct5vACfTG8JkFa9gd4nY3M aa9f1034d973377a5e733272c3d0eced1de22555ad45d6b24abadff8087948d4 0 
mn3 127.0.0.4:11148 7r9ZhzukRpotNqYTQc2ch99dLZAELEdzzerAUp2RM3uLWPBG2yt db478e78e3aefaa8c12d12ddd0aeace48c3b451a8b41c570d0ee375e2a02dfd9 1


In the example above:
* the collateral for mn1 consists of transaction 2bcd3c84c84f87eaa86e4e56834c92927a07f9e18718810b92e0d0324456a67c, output index 0 has amount 10000
* masternode 1 will donate 22% of its income
* masternode 2 will donate 65% of its income


The following new RPC commands are supported:
* list-conf: shows the parsed masternode.conf
* start-alias \<alias\>
* stop-alias \<alias\>
* start-many
* stop-many
* outputs: list available collateral output transaction ids and corresponding collateral output indexes

When using the multi masternode setup, it is advised to run the wallet with 'masternode=0' as it is not needed anymore.

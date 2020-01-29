// Copyright (c) 2012-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2017 The PIVX developers
// Copyright (c) 2017-2018 The Bulwark developers
// Copyright (c) 2019 The QOINZ Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_VERSION_H
#define BITCOIN_VERSION_H

/**
 * network protocol versioning
 */

static const int PROTOCOL_VERSION = 70228;

//! initial proto version, to be increased after version/verack negotiation
static const int MIN_PEER_PROTO_VERSION_BEFORE_ENFORCEMENT = 70227;
static const int MIN_PEER_PROTO_VERSION_AFTER_ENFORCEMENT = 70228;

static const int CONSENSUS_FORK_PROTO = 70228;

//! disconnect from peers older than this proto version
static const int INIT_PROTO_VERSION = 209;

//! nTime field added to CAddress, starting with this version;
//! if possible, avoid requesting addresses nodes older than this
static const int CADDR_TIME_VERSION = 31402;

//! BIP 0031, pong message, is enabled for all versions AFTER this one
static const int BIP0031_VERSION = 60000;

#endif // BITCOIN_VERSION_H

// Copyright (c) 2014-2018, The Monero Project
// 
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

#pragma once

#include <stdexcept>
#include <string>
#include <boost/uuid/uuid.hpp>
#include <stdexcept>

#define CRYPTONOTE_DNS_TIMEOUT_MS                       20000

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     500000000
#define CRYPTONOTE_MAX_BLOCK_SIZE                       500000000  // block header blob limit, never used!
#define CRYPTONOTE_GETBLOCKTEMPLATE_MAX_BLOCK_SIZE	196608 //size of block (bytes) that is the maximum that miners will produce
#define CRYPTONOTE_MAX_TX_SIZE                          1000000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER          0
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            10
#define CURRENT_BLOCK_MAJOR_VERSION                     7
#define CURRENT_BLOCK_MINOR_VERSION                     7
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT_V2           60*10
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE             10
#define CRYPTONOTE_DEFAULT_TX_MIXIN                     9

#define STAKING_REQUIREMENT_LOCK_BLOCKS_EXCESS          20
#define STAKING_PORTIONS                                UINT64_C(0xfffffffffffffffc)
#define MAX_NUMBER_OF_CONTRIBUTORS                      4
#define MIN_PORTIONS                                    (STAKING_PORTIONS / MAX_NUMBER_OF_CONTRIBUTORS)

static_assert(STAKING_PORTIONS % MAX_NUMBER_OF_CONTRIBUTORS == 0, "Use a multiple of four, so that it divides easily by max number of contributors.");
static_assert(STAKING_PORTIONS % 2 == 0, "Use a multiple of two, so that it divides easily by two contributors.");
static_assert(STAKING_PORTIONS % 3 == 0, "Use a multiple of three, so that it divides easily by three contributors.");

#define STAKING_AUTHORIZATION_EXPIRATION_WINDOW         (60*60*24*7*2)  // 2 weeks

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               11

#define UPTIME_PROOF_BUFFER_IN_SECONDS                  (5*60) // The acceptable window of time to accept a peer's uptime proof from its reported timestamp
#define UPTIME_PROOF_FREQUENCY_IN_SECONDS               (60*60)
#define UPTIME_PROOF_MAX_TIME_IN_SECONDS                (UPTIME_PROOF_FREQUENCY_IN_SECONDS * 2 + UPTIME_PROOF_BUFFER_IN_SECONDS)
// COIN - number of smallest units in one coin
#define COIN                                            ((uint64_t)1000000000) // pow(10, 9)
// MONEY_SUPPLY - total number coins to be generated
#define MONEY_SUPPLY                                    ((uint64_t)250000000 * COIN)//250 Millone
#define EMISSION_SPEED_FACTOR_PER_MINUTE                (20)
#define FINAL_SUBSIDY_PER_MINUTE                        ((uint64_t)300000000000) // 3 * pow(10, 11)
#define EMISSION_LINEAR_BASE                            ((uint64_t)(1) << 58)
#define YEARLY_INFLATION_INVERSE                        200 // 0.5% yearly inflation, inverted for integer division
#define EMISSION_SUPPLY_MULTIPLIER                      19
#define EMISSION_SUPPLY_DIVISOR                         10
#define EMISSION_DIVISOR                                2000000

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    60000 //size of block (bytes) after which reward for block calculated using block size
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1    20000 //size of block (bytes) after which reward for block calculated using block size - before first fork
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5    300000 //size of block (bytes) after which reward for block calculated using block size - second change, from v5
#define CRYPTONOTE_LONG_TERM_BLOCK_WEIGHT_WINDOW_SIZE   100000 // size in blocks of the long term block weight median window
#define CRYPTONOTE_SHORT_TERM_BLOCK_WEIGHT_SURGE_FACTOR 50
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                9

#define FEE_PER_KB_OLD                                  ((uint64_t)10000000000) // pow(10, 10)
#define FEE_PER_KB                                      ((uint64_t)2000000000) // 2 * pow(10, 9)
#define FEE_PER_BYTE                                    ((uint64_t)300000)
#define DYNAMIC_FEE_PER_KB_BASE_FEE                     ((uint64_t)2000000000) // 2 * pow(10,9)
#define DYNAMIC_FEE_PER_KB_BASE_BLOCK_REWARD            ((uint64_t)10000000000000) // 10 * pow(10,12)
#define DYNAMIC_FEE_PER_KB_BASE_FEE_V5                  ((uint64_t)2000000000 * (uint64_t)CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2 / CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5)
#define DYNAMIC_FEE_REFERENCE_TRANSACTION_WEIGHT         ((uint64_t)3000)

#define ORPHANED_BLOCKS_MAX_COUNT                       100

#define DIFFICULTY_TARGET_V2                            120  // seconds
#define DIFFICULTY_WINDOW_V2                            60
#define DIFFICULTY_LAG                                  15  // !!!
#define DIFFICULTY_CUT                                  60  // timestamps to cut after sorting
#define DIFFICULTY_BLOCKS_COUNT_V2                      (DIFFICULTY_WINDOW_V2 + 1) // added +1 to make N=N

#define BLOCKS_EXPECTED_IN_HOURS(val)                   (((60 * 60) / DIFFICULTY_TARGET_V2) * (val))
#define BLOCKS_EXPECTED_IN_DAYS(val)                    (BLOCKS_EXPECTED_IN_HOURS(24) * (val))
#define BLOCKS_EXPECTED_IN_YEARS(val)                   (BLOCKS_EXPECTED_IN_DAYS(365) * (val))

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V2   DIFFICULTY_TARGET_V2 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1


#define DIFFICULTY_BLOCKS_ESTIMATE_TIMESPAN             DIFFICULTY_TARGET_V2 //just alias; used by tests


#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000  //by default, blocks ids count in synchronizing
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT_PRE_V4       100    //by default, blocks count in blocks downloading
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              20     //by default, blocks count in blocks downloading

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                    (86400*3) //seconds, three days
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME     604800 //seconds, one week

#define MEMPOOL_PRUNE_NON_STANDARD_TX_LIFETIME          (2 * 60 * 60) // seconds, 2 hours

#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_COUNT           1000

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_DEFAULT_CONNECTIONS_COUNT                   8
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60           //secondes
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000     //50000000 bytes maximum packet size
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000       //5 seconds
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000       //2 seconds
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60*2*1000  //2 minutes
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000       //5 seconds
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_ANCHOR_CONNECTIONS_COUNT            2
#define P2P_DEFAULT_LIMIT_RATE_UP                       2048       // kB/s
#define P2P_DEFAULT_LIMIT_RATE_DOWN                     8192       // kB/s

#define P2P_FAILED_ADDR_FORGET_SECONDS                  (60*60)     //1 hour
#define P2P_IP_BLOCKTIME                                (60*60*24)  //24 hour
#define P2P_IP_FAILS_BEFORE_BLOCK                       10
#define P2P_IDLE_CONNECTION_KILL_INTERVAL               (5*60) //5 minutes

#define P2P_SUPPORT_FLAG_FLUFFY_BLOCKS                  0x01
#define P2P_SUPPORT_FLAGS                               P2P_SUPPORT_FLAG_FLUFFY_BLOCKS

#define ALLOW_DEBUG_COMMANDS

#define CRYPTONOTE_NAME                         "SevaBit"
#define CRYPTONOTE_POOLDATA_FILENAME            "poolstate.bin"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME      "data.mdb"
#define CRYPTONOTE_BLOCKCHAINDATA_LOCK_FILENAME "lock.mdb"
#define P2P_NET_DATA_FILENAME                   "p2pstate.bin"
#define MINER_CONFIG_FILE_NAME                  "miner_conf.json"

#define THREAD_STACK_SIZE                       5 * 1024 * 1024

#define HF_VERSION_DYNAMIC_FEE                  4
#define HF_VERSION_MIN_MIXIN_9                  7
#define HF_VERSION_ENFORCE_RCT                  6
#define HF_VERSION_PER_BYTE_FEE                 cryptonote::network_version_10_bulletproofs
#define HF_VERSION_SMALLER_BP                   cryptonote::network_version_11_infinite_staking
#define HF_VERSION_LONG_TERM_BLOCK_WEIGHT       cryptonote::network_version_11_infinite_staking

#define PER_KB_FEE_QUANTIZATION_DECIMALS        8

#define HASH_OF_HASHES_STEP                     256

#define DEFAULT_TXPOOL_MAX_WEIGHT               648000000ull // 3 days at 300000, in bytes

#define BULLETPROOF_MAX_OUTPUTS                 16

#define CRYPTONOTE_PRUNING_STRIPE_SIZE          4096 // the smaller, the smoother the increase
#define CRYPTONOTE_PRUNING_LOG_STRIPES          3 // the higher, the more space saved
#define CRYPTONOTE_PRUNING_TIP_BLOCKS           5500 // the smaller, the more space saved
//#define CRYPTONOTE_PRUNING_DEBUG_SPOOF_SEED

// New constants are intended to go here
namespace config
{
  uint64_t const DEFAULT_FEE_ATOMIC_XMR_PER_KB = 500; // Just a placeholder!  Change me!
  uint8_t const FEE_CALCULATION_MAX_RETRIES = 10;
  uint64_t const DEFAULT_DUST_THRESHOLD = ((uint64_t)2000000000); // 2 * pow(10, 9)
  uint64_t const BASE_REWARD_CLAMP_THRESHOLD = ((uint64_t)100000000); // pow(10, 8)
  std::string const P2P_REMOTE_DEBUG_TRUSTED_PUB_KEY = "0000000000000000000000000000000000000000000000000000000000000000";

  uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x3ded16;
  uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 115;
  uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 88;
  uint16_t const P2P_DEFAULT_PORT = 22048;
  uint16_t const RPC_DEFAULT_PORT = 22049;
  uint16_t const ZMQ_RPC_DEFAULT_PORT = 22044;
  boost::uuids::uuid const NETWORK_ID = { {
        0x42 ,0xb8, 0x42, 0x61 ,0x64, 0x75, 0x74, 0x69, 0x9c, 0x2a, 0x61, 0xd5, 0x6d, 0x62, 0x79
    } }; 
  std::string const GENESIS_TX = "010a01ff000180d0dbc3f4020277d7fb23e182ebc01db3a7513ca888ad1baf89d9d3ad83afec11c52584d8a1be21019ed32ceb9336ca589287e7aeb57feca0a078c3ccc93eec11efbb3b003a8fa81e";
  uint32_t const GENESIS_NONCE = 1022201;

  uint64_t const GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS = 100; // ((60 * 60 * 24 * 7) / DIFFICULTY_TARGET_V2);
  std::string const GOVERNANCE_WALLET_ADDRESS[] =
  {
    "SEVAquqeim2hizpQtY4rznXLR7RoKyUc2G2teL6ux1BBFJthoRgyZBv2yCrbi2WkV88h1b6Tua1QCDaSNBbXJUaAHdAC3TnWPpY", // hardfork v7-10
    "SEVAqsCXjaQFBuBjMfYmdARtEZvvYFgo6bMRvnwpYxkCXU7vjrA9BBKPGc59BfNESgYnM27NNMXvccAfPw3SQrPnTmQPF7tteBs" // hardfork v11
  };

  namespace testnet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 156;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 157;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 158;
    uint16_t const P2P_DEFAULT_PORT = 23048;
    uint16_t const RPC_DEFAULT_PORT = 23049;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 23044;
    boost::uuids::uuid const NETWORK_ID = { {
        0xde, 0xed, 0xca, 0xfe, 0xba, 0xbe, 0xca, 0xb8, 0x02, 0xa1, 0xec, 0x17, 0x61, 0xc0, 0xff, 0xee,
      } }; // Bender's daydream
    std::string const GENESIS_TX = "020a01ff0001eb82bdef980402766791386f4f0e6390a8628abf4499533c37171d8b63f8a75a9a9dcd8be52cca42013d726696c95ca59d6fe7f5ffdfbf5fe6dfafc940d0e5eeaa1ea03f83f0289aaa72000000000000000000000000000000000000000000000000000000000000000000";
    uint32_t const GENESIS_NONCE = 10001;

    uint64_t const GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS = 100;
    std::string const GOVERNANCE_WALLET_ADDRESS[] =
    {
      "T6T5kwer76FhEyTiGuvANud6PuKHW37vM6hJYfMicSZcKF3qS36Yh92LBEBvEy4VESPVaJmchhUgRjn4FkWu2Fw92XP1XEH5S", // hardfork v7-9
      "T6T5kwer76FhEyTiGuvANud6PuKHW37vM6hJYfMicSZcKF3qS36Yh92LBEBvEy4VESPVaJmchhUgRjn4FkWu2Fw92XP1XEH5S", // hardfork v10
    };

  }

  namespace stagenet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 24;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 25;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 36;
    uint16_t const P2P_DEFAULT_PORT = 24048;
    uint16_t const RPC_DEFAULT_PORT = 24049;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 24044;
    boost::uuids::uuid const NETWORK_ID = { {
        0xde, 0xed, 0xca, 0xfe, 0xba, 0xbe, 0xca, 0xb8, 0x02, 0xa1, 0xec, 0x17, 0x61, 0xc0, 0xff, 0xef,
      } }; // Beep Boop
    std::string const GENESIS_TX = "020a01ff0001eb82bdef98040233143548544c2a81769581fe33e9d105c851a4457ca8e9717f763db4956ee6754201f14801a900866433b3e6b109c69258a5b4811ca9108df9ad902f287dad672c6972000000000000000000000000000000000000000000000000000000000000000000";
    uint32_t const GENESIS_NONCE = 10002;

    uint64_t const GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS = 100;
    std::string const GOVERNANCE_WALLET_ADDRESS[] =
    {
      "598mXS9gtDdSeHTw1EvJ82C3Bc2vvdsofiShhPhMXJvF4hMs6wxcWm2bRCbgZUabV587Vd8gkHRbFgby3jnVCFq9CQqsx6a", // hardfork v7-9
      "598mXS9gtDdSeHTw1EvJ82C3Bc2vvdsofiShhPhMXJvF4hMs6wxcWm2bRCbgZUabV587Vd8gkHRbFgby3jnVCFq9CQqsx6a", // hardfork v10
    };
  }
}

namespace cryptonote
{
  enum network_version
  {
    network_version_7 = 7,
    network_version_8,
    network_version_9_super_nodes, // Proof Of Stake w/ Super Nodes
    network_version_10_bulletproofs, // Bulletproofs, Super Node Grace Registration Period, Batched Governance
    network_version_11_infinite_staking,

    network_version_count,
  };

  enum network_type : uint8_t
  {
    MAINNET = 0,
    TESTNET,
    STAGENET,
    FAKECHAIN,
    UNDEFINED = 255
  };
  struct config_t
  {
    uint64_t CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX;
    uint64_t CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX;
    uint64_t CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX;
    uint16_t P2P_DEFAULT_PORT;
    uint16_t RPC_DEFAULT_PORT;
    uint16_t ZMQ_RPC_DEFAULT_PORT;
    boost::uuids::uuid NETWORK_ID;
    std::string GENESIS_TX;
    uint32_t GENESIS_NONCE;
    uint64_t GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS;
    std::string const *GOVERNANCE_WALLET_ADDRESS;
  };
  inline const config_t& get_config(network_type nettype, int hard_fork_version = 7)
  {
    static config_t mainnet = {
      ::config::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::P2P_DEFAULT_PORT,
      ::config::RPC_DEFAULT_PORT,
      ::config::ZMQ_RPC_DEFAULT_PORT,
      ::config::NETWORK_ID,
      ::config::GENESIS_TX,
      ::config::GENESIS_NONCE,
      ::config::GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS,
      &::config::GOVERNANCE_WALLET_ADDRESS[0],
    };

    static config_t testnet = {
      ::config::testnet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::testnet::P2P_DEFAULT_PORT,
      ::config::testnet::RPC_DEFAULT_PORT,
      ::config::testnet::ZMQ_RPC_DEFAULT_PORT,
      ::config::testnet::NETWORK_ID,
      ::config::testnet::GENESIS_TX,
      ::config::testnet::GENESIS_NONCE,
      ::config::testnet::GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS,
      &::config::testnet::GOVERNANCE_WALLET_ADDRESS[0],
    };

    static config_t stagenet = {
      ::config::stagenet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::stagenet::P2P_DEFAULT_PORT,
      ::config::stagenet::RPC_DEFAULT_PORT,
      ::config::stagenet::ZMQ_RPC_DEFAULT_PORT,
      ::config::stagenet::NETWORK_ID,
      ::config::stagenet::GENESIS_TX,
      ::config::stagenet::GENESIS_NONCE,
      ::config::stagenet::GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS,
      &::config::stagenet::GOVERNANCE_WALLET_ADDRESS[0],
    };

    switch (nettype)
    {
      case MAINNET: case FAKECHAIN:
      {
        if (nettype == FAKECHAIN)
          mainnet.GOVERNANCE_REWARD_INTERVAL_IN_BLOCKS = 100;
        
        if (hard_fork_version <= network_version_10_bulletproofs)
            mainnet.GOVERNANCE_WALLET_ADDRESS = &::config::GOVERNANCE_WALLET_ADDRESS[0];
        else
            mainnet.GOVERNANCE_WALLET_ADDRESS = &::config::GOVERNANCE_WALLET_ADDRESS[1];
        return mainnet;
      }

      case TESTNET:
      {
        if (hard_fork_version <= network_version_9_super_nodes)
          testnet.GOVERNANCE_WALLET_ADDRESS = &::config::testnet::GOVERNANCE_WALLET_ADDRESS[0];
        else
          testnet.GOVERNANCE_WALLET_ADDRESS = &::config::testnet::GOVERNANCE_WALLET_ADDRESS[1];

        return testnet;
      }

      case STAGENET:
      {
        if (hard_fork_version <= network_version_9_super_nodes)
          stagenet.GOVERNANCE_WALLET_ADDRESS = &::config::stagenet::GOVERNANCE_WALLET_ADDRESS[0];
        else
          stagenet.GOVERNANCE_WALLET_ADDRESS = &::config::stagenet::GOVERNANCE_WALLET_ADDRESS[1];

        return stagenet;
      }

      default: throw std::runtime_error("Invalid network type");
    }
  };
}

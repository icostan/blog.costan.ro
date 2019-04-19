---
layout: post
title:  Introducing Cryptos-ruby project
date:   2018-12-11
tags: ["bitcoin", "litecoin", "monero", "cryptography", "crypto", "math", "ruby"]
---

I just want to announce the very first release [v0.0.3] of Cryptos-ruby project, a simple and very easy to use Ruby API to  manipulate multiple crypto coins.

For more information please check [Github project page](https://github.com/icostan/cryptos-ruby).

# Features

  * Generate private/public keys
  * Generate Bitcoin/Litecoin addresses (more to come)
  * Create Bitcoin/Litecoin transactions
  * Execute atomic swaps between Bitcoin and Litecoin

# Installation
```shell
gem install cryptos
```

# Usage

```ruby
# Importing library...
2.5.1 :001 > require 'cryptos'

# Generating private key...
2.5.1 :003 > private_key = Cryptos::PrivateKey.generate
 => #<Cryptos::PrivateKey:0x00007fc9d123e2e8 @value=47930083789607287790662857866073624449854924554643360243140359905082181414216, @order=115792089237316195423570985008687907852837564279074904382605163141518161494337>

# Generating public key...
2.5.1 :004 > public_key = Cryptos::PublicKey.new private_key
 => #<Cryptos::PublicKey:0x00007fc9d122fc48 @private_key=#<Cryptos::PrivateKey:0x00007fc9d123e2e8 @value=47930083789607287790662857866073624449854924554643360243140359905082181414216, @order=115792089237316195423570985008687907852837564279074904382605163141518161494337>, @x=37935518911551901189910488779135983333966395037400135768523765072809885233888, @y=60841756395196742058661917858407687798753194961782162321894682162865330386541>

# Generating Bitcoin address for testnet
2.5.1 :005 > address = Cryptos::Bitcoin::Address.new public_key
 => #<Cryptos::Bitcoin::Address:0x00007fc9d18a29b8 @public_key=#<Cryptos::PublicKey:0x00007fc9d122fc48 @private_key=#<Cryptos::PrivateKey:0x00007fc9d123e2e8 @value=47930083789607287790662857866073624449854924554643360243140359905082181414216, @order=115792089237316195423570985008687907852837564279074904382605163141518161494337>, @x=37935518911551901189910488779135983333966395037400135768523765072809885233888, @y=60841756395196742058661917858407687798753194961782162321894682162865330386541>, @testnet=true>
2.5.1 :006 > address.to_s
 => "n37t517bJymxg3YftzqyVTAnjg4wKb3Tth"

# Generating Litecoin address for mainnet
2.5.1 :007 > address = Cryptos::Litecoin::Address.new public_key, testnet: false
 => #<Cryptos::Litecoin::Address:0x00007fc9d119a1e8 @public_key=#<Cryptos::PublicKey:0x00007fc9d122fc48 @private_key=#<Cryptos::PrivateKey:0x00007fc9d123e2e8 @value=47930083789607287790662857866073624449854924554643360243140359905082181414216, @order=115792089237316195423570985008687907852837564279074904382605163141518161494337>, @x=37935518911551901189910488779135983333966395037400135768523765072809885233888, @y=60841756395196742058661917858407687798753194961782162321894682162865330386541>, @testnet=false>
2.5.1 :008 > address.to_s
 => "Lgpt3ALSacam9jmDMZrtwZ2E5tqWVYzEkH"
```

# Todos
  * Work in progress: Zcash and Ethereum support
  * Add more and more coins, cool crypto tech

Start today and craft your own Bitcoin transactions.

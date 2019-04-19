---
layout: post
title:  Idiomatic Ruby library for BitMEX API
date:   2019-01-28
tags: ["bitmex", "api", "sdk", "ruby", "trading", "ruby"]
---

Fully featured, idiomatic Ruby library for BitMEX API. Support for both REST and Websocket APIs as described in [API Overview](https://www.bitmex.com/app/apiOverview).

# Installation

```shell
gem install bitmex-api
```

# Usage

Listen for live trades in 3 lines of code:

```ruby
# Importing library...
2.5.3 :001 > require 'bitmex-api'
 => true

# Create client...
2.5.3 :002 > client = Bitmex::Client.new
 => #<Bitmex::Client:0x00007fae7a569598 @host="www.bitmex.com", @api_key=nil, @api_secret=nil>

# Spit out live trades as they happen...
2.5.3 :003 > client.trades.all symbol: 'XBTUSD' do |trade|
  puts "#{trade.side} #{trade.homeNotional} #{trade.symbol} @ #{trade.price}"
end
2.5.3 :004 >
2.5.3 :005?>
==> {"info":"Welcome to the BitMEX Realtime API.","version":"2019-01-31T23:25:34.000Z","timestamp":"2019-02-02T12:35:05.892Z","docs":"https://www.bitmex.com/app/wsAPI","limit":{"remaining":37}}
==> {"success":true,"subscribe":"trade:XBTUSD","request":{"op":"subscribe","args":["trade:XBTUSD"]}}
Buy 0.2924442 XBTUSD @ 3440
Sell 0.0305277 XBTUSD @ 3439.5
Buy 0.2907 XBTUSD @ 3440
Sell 0.18810878 XBTUSD @ 3439.5
Sell 0.14537 XBTUSD @ 3439.5
Buy 0.17442 XBTUSD @ 3440
Buy 0.05814 XBTUSD @ 3440
Sell 0.014537 XBTUSD @ 3439.5
```

Or fetch trade history:

```ruby
# get first 10 trades of the year
2.5.3 :006 > trades = client.trades.all symbol: 'XBTUSD', startTime: '2019-01-01', count: 10
 => [...]

2.5.3 :007 > trades.size
 => 10

# the very first trade in 2019
2.5.3 :008 > trades.first
 => #<Bitmex::Mash foreignNotional=10 grossValue=270780 homeNotional=0.0027078 price=3693 side="Sell" size=10 symbol="XBTUSD" tickDirection="ZeroMinusTick" timestamp="2019-01-01T00:00:03.904Z" trdMatchID="2bd201ae-3b79-0908-293e-d9bd1cc489f2">
```

This post is just a teaser, if you want to find out more info please see [source code](https://github.com/icostan/bitmex-api-ruby) and [documentation](https://www.rubydoc.info/gems/bitmex-api).

Enjoy futures trading!

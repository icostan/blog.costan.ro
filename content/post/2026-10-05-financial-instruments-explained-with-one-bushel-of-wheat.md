---
title: Financial Instruments
subtitle: Explained with one bushel of wheat
date: 2026-10-05
tags: ["trading", "finance", "derivatives", "options", "futures", "cfd", "arbitrage", "hedging"]
---

Financial markets can easily feel abstract and overwhelming when explained through textbook formulas and Wall Street jargon. To make these mechanisms tangible, I gave a presentation at **Iconic Club Afaceri.ro** in Iași breaking down the foundational financial instruments using a single, intuitive commodity: **one bushel of wheat**.

Whether dealing with physical grain in Chicago, equity shares, foreign exchange, or Bitcoin, the economic forces and contractual machinery remain identical. Below is a comprehensive summary of the concepts covered in the talk, followed by the embedded slide deck.

---

## 1. Where Does a Price Come From?

Before diving into instruments, we must understand price discovery:
- **Demand** (flour mills, industrial bakeries): willing to buy more when wheat is cheap.
- **Supply** (grain farms, agricultural producers): willing to sell more when wheat is expensive.
- **Equilibrium**: The price clears where supply meets demand — say, **$100 per bushel**.

When an external shock hits — like a severe regional drought — supply contracts, shifting the supply curve to the left and pushing the clearing price higher (e.g., to **$106/bushel**).

---

## 2. The Spot (Cash) Market

The spot market is the simplest form of trade: **pay now, get it now**.
- **True Ownership**: You pay the full cash price, and the asset is yours today — whether physical grain at the silo or shares of an ETF landing in your brokerage account.
- **Bid / Ask / Spread**:
  - **Bid ($99)**: The highest price a buyer offers. You sell at the bid.
  - **Ask ($101)**: The lowest price a seller accepts. You buy at the ask.
  - **Spread ($2)**: The transaction friction and cost of immediate liquidity.
- **Pure Arbitrage**:
  - Suppose wheat trades at **$100 in Chicago** and **$112 in Detroit**.
  - Shipping costs **$4**, kiosk/handling fees cost **$2** (total cost basis: **$106**).
  - Buying in Chicago and simultaneously selling in Detroit locks in a riskless **+$6/bushel profit** without predicting future market direction.
  - **Equilibrium restoration**: Every truckload increases demand in Chicago (raising prices) and increases supply in Detroit (lowering prices). Soon, the $6 spread compresses until it covers only transport and operational friction ($0 economic edge).

---

## 3. Derivatives: Trading Contracts, Not Goods

In derivatives, you do not buy or sell the underlying asset. You buy or sell a **contract whose value derives from the price of that underlying asset** (wheat, crude oil, treasury bonds, currencies, or equities).

| Dimension | Spot (Cash) Market | Derivatives |
| :--- | :--- | :--- |
| **What you buy** | The physical good or underlying security | A contract on the price |
| **What you pay** | Full price upfront (100% capital) | A performance deposit (margin) |
| **Profit direction** | When price rises (long only) | When price rises (long) or falls (short) |
| **Holding duration** | Indefinite (as long as you like) | Often tied to a specific expiry date |
| **Risk profile** | Limited to initial capital invested | Fast wipeout risk due to leverage |

### Leverage and Margin Mechanics
Derivatives introduce leverage:
- **$10,000 margin** at **1:10 leverage** controls **$100,000 of wheat** (1,000 bushels at $100).
- A **+5% move** in wheat price yields a **+$5,000 profit (+50% return on equity)**.
- A **-5% move** wipes out **-$5,000 (-50% return on equity)**.
- A **-10% drop** completely obliterates the margin deposit, triggering an immediate **margin call / liquidation**.

---

## 4. CFDs vs. Futures

### Contracts for Difference (CFDs)
- Traded directly with a retail broker (over-the-counter).
- Settles only the cash gap between entry and exit price.
- No physical delivery, no fixed expiry, but subject to daily overnight financing (swap) and counterparty risk with the broker.

### Futures Contracts
- Standardized agreements traded on centralized exchanges (e.g., CBOT wheat: 5,000 bushels per contract) backed by a central clearinghouse.
- Predetermined expiry cycles (e.g., March, May, July, September, December).
- Capable of physical delivery.

### How Commercial Hedging Works

1. **The Grain Farmer (Producer Hedging — Selling Futures)**:
   - In March, the spot price is $110, and September futures trade at $105.
   - The farm's crop is still growing in the soil — it cannot be sold on the spot market.
   - To eliminate price collapse risk, the farm **sells (shorts) September futures at $105**.
   - If September spot crashes to **$90**: Physical crop sells for $90, futures short gains +$15 $\rightarrow$ **Net: $105/bushel**.
   - If September spot rallies to **$120**: Physical crop sells for $120, futures short loses -$15 $\rightarrow$ **Net: $105/bushel**.
   - *Outcome*: Revenue certainty allows securing bank loans, planning equipment purchases, and surviving volatile seasons.

2. **The Flour Mill (Consumer Hedging — Buying Futures)**:
   - In March, the mill wants guaranteed grain in September to maintain production.
   - It **buys (longs) September futures at $105**.
   - Whether spot spikes to **$120** (+$15 futures gain offsets input cost) or drops to **$90** (-$15 futures loss offsets spot discount), the net cost remains **$105/bushel**.
   - *Outcome*: The mill locks in production costs, enabling fixed-price annual supply contracts with commercial bakeries.

### Understanding Basis: Contango vs. Backwardation
$$\text{Basis} = \text{Spot Price} - \text{Futures Price}$$

- **Contango (Negative Basis — "Pay to Wait")**:
  - Post-harvest (July): Silos are overflowing; storage and insurance are costly.
  - Spot = $90, December Futures = $98 $\rightarrow$ **Basis = -$8**.
  - The market subsidizes and pays operators who store grain until winter.
- **Backwardation (Positive Basis — "Scarcity Premium")**:
  - Pre-harvest (March): Silos are near empty; mills urgently bid for available grain.
  - Spot = $110, September Futures = $105 $\rightarrow$ **Basis = +$5**.
  - The market incentivizes inventory holders to sell into the cash market immediately.
- **Convergence**: As expiration approaches, storage time collapses to zero, and basis converges to **$0**.

---

## 5. Options: The Right, Not the Obligation

Unlike futures (which are binding commitments), options provide **asymmetric risk profiles** by acting like insurance policies. You pay an upfront, non-refundable **premium**:
- **CALL Option**: The right to **buy** at a fixed strike price (caps your maximum cost).
- **PUT Option**: The right to **sell** at a fixed strike price (establishes a minimum floor).

### Hedging with Options

1. **The Farm Buys a Floor (Long Put)**:
   - Buys a September Put with **Strike = $100**, paying a **$3/bushel premium**.
   - **Market crash ($80)**: Farm exercises the put, selling at $100 minus $3 premium $\rightarrow$ **Net: $97/bushel floor**.
   - **Market boom ($120)**: Farm lets the put expire worthless and sells physical wheat at $120 minus $3 premium $\rightarrow$ **Net: $117/bushel**.
   - *Advantage over Futures*: Protection against bankruptcy while keeping full participation in upward market rallies.

2. **The Mill Buys a Ceiling (Long Call)**:
   - Buys a September Call with **Strike = $110**, paying a **$3/bushel premium**.
   - **Drought spike ($130)**: Exercises the call to buy at $110 plus $3 premium $\rightarrow$ **Net ceiling: $113/bushel**.
   - **Bumper crop collapse ($90)**: Lets the call expire and buys cheap grain in the spot market for $90 plus $3 premium $\rightarrow$ **Net cost: $93/bushel**.

### Moneyness
- **In-the-Money (ITM)**: Has intrinsic cash value at expiration.
- **Out-of-the-Money (OTM)**: Has zero intrinsic value at expiration (worth $0).
- Better strike protection (a higher floor for puts, or a lower ceiling for calls) commands a proportionally higher premium.

---

## 6. Pure Arbitrage vs. Statistical Arbitrage (Stat-Arb)

- **Pure Arbitrage**: Simultaneously capturing identical asset discrepancies (Chicago vs. Detroit). Generates high edge with near-zero price risk per trade, but opportunities are vanishingly rare and dominated by automated low-latency infrastructure.
- **Statistical Arbitrage / Market Making**: Exploits a small statistical edge repeated thousands of times.
  - *Who sells the farm's put and the mill's call?* Option market makers acting as insurance underwriters.
  - By selling both out-of-the-money puts and calls (a short strangle), the trader collects upfront premiums ($6/bushel).
  - In normal years ($100 - $110 price band), all options expire worthless, and the seller pockets the premium.
  - In extreme tail events (severe droughts or massive gluts), the insurer pays out substantial claims, managing risk through diversification and delta hedging.

---

## 7. Instrument Matrix & Key Takeaways

| Instrument | What You Buy | Leverage | Expiry | Primary Application |
| :--- | :--- | :--- | :--- | :--- |
| **Spot** | Direct asset ownership | No | No (bonds mature) | Long-term investment & custody |
| **CFD** | Price difference contract | High | No | Short-term tactical speculation |
| **Futures** | Binding exchange commitment | Moderate / High | Yes | Locking in forward prices (hedging) |
| **Options** | Asymmetric right (insurance) | High | Yes | Capping costs (ceilings) or downside (floors) |

### Universal Application Across Asset Classes
The same framework applies universally:
- **Bonds**: US Treasuries (`UST`)
- **Foreign Exchange**: `EURUSD`
- **Equities**: Tesla (`TSLA`)
- **Commodities**: Chicago Wheat (`CBOT: ZW`)
- **Crypto**: Bitcoin (`BTC`)

### Three Rules to Remember
1. **Spot means you own it; derivatives are contracts on price.**
2. **Leverage magnifies everything: gains and mistakes alike.**
3. **Hedging isn't a speculative bet — it is operational insurance for a business.**

---

## Presentation Slides

Enjoy the presentation!

<embed src="/post/financial_instruments.pdf" width="800" height="600" type="application/pdf"></embed>

*Direct link to slide deck:* [financial_instruments.pdf](/post/financial_instruments.pdf)

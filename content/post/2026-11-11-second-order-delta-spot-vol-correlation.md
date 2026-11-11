---
title: Second-order Greeks and spot-vol correlation
subtitle: How gamma, vanna and charm move delta
date: 2026-11-11
tags: ["trading", "options", "greeks", "delta", "gamma", "vanna", "charm", "volatility"]
---

Delta changes as spot moves, implied volatility (IV) changes and time passes. Gamma, vanna and charm describe those three effects. Looking at them together explains why a short OTM put can gain less delta on a falling market than gamma alone suggests.

This extends the definitions in [Incomplete guide to Options Greeks](/post/2021-02-16-options-greeks/), with an explicit convention for time and a local approximation for the change in position delta:

```text
change in delta ≈ gamma × change in spot
                + vanna × change in IV
                + charm × elapsed time
```

These are second derivatives of option value, but first derivatives of delta. Each term holds the other inputs fixed; the sum estimates their combined effect for small changes.

## Conventions and assumptions

**Longer delta (+)** means a numerical increase in signed position delta; **shorter delta (−)** means a numerical decrease. Moving from −0.30 to −0.20 is longer delta, even though the absolute exposure shrinks. Moving from +0.30 to +0.20 is shorter delta.

Use European vanilla options, fixed strikes, zero interest rates and no dividends. The call strike is above spot and the put strike below spot: these are two different strikes. Assume they are sufficiently OTM for the signs below to apply and that the shocks are small enough to preserve those signs. All Greeks are position Greeks: selling the option reverses every sign.

Here, `t` is calendar time, `T` is fixed expiry and `τ = T − t` is time remaining. **Charm means ∂delta/∂t = −∂delta/∂τ**. A positive elapsed-time step therefore reduces `τ`. A source reporting charm against time remaining will show the opposite sign.

## How each Greek moves delta

### Gamma: spot moves

Gamma is `∂delta/∂S`. Long calls and long puts have positive gamma: a spot rise increases delta and a spot fall decreases it. Short options have negative gamma, so their delta moves in the opposite direction.

For a short OTM put, a fall toward the strike makes its positive delta more positive: negative gamma times a negative spot change gives a positive delta change.

### Vanna: IV moves

Vanna is `∂delta/∂σ`. Positive vanna makes delta longer as IV rises and shorter as IV falls. Negative vanna reverses those effects.

In the OTM region used here, a long call has positive vanna and a long put has negative vanna. Thus, **long OTM calls and short OTM puts are long vanna**. Short OTM calls and long OTM puts are short vanna.

This classification depends on strike and model inputs. At the *same strike and expiry*, a call and a put have identical vanna: an OTM call and its corresponding ITM put share positive vanna; an OTM put and its corresponding ITM call share negative vanna in the region assumed here.

### Charm: time passes

Charm is `∂delta/∂t` under our elapsed-time convention. Holding spot and IV fixed, a sufficiently OTM option's delta moves toward zero as expiry approaches. A long OTM call's positive delta falls: negative charm. A long OTM put's negative delta rises toward zero: positive charm. Short positions reverse these signs.

So “delta decays” describes shrinking absolute delta in this region; it does **not** imply a negative signed change for every trade.

### Where the sign shortcut applies

The precise boundaries follow by differentiating Black–Scholes delta. With zero rates and dividends, define `N` as the standard normal CDF and `φ` as its density:

```text
d1 = [ln(S/K) + σ²τ/2] / (σ√τ)
d2 = d1 − σ√τ
delta_call = N(d1); delta_put = N(d1) − 1

gamma = φ(d1) / (Sσ√τ)
vanna = −φ(d1)d2 / σ
charm = φ(d1)d2 / (2τ)
```

These formulas are for one long option. In this model an OTM call has `d2 < 0`, giving positive vanna and negative charm. An OTM put needs `ln(S/K) > σ²τ/2` for `d2 > 0`, giving negative vanna and positive charm. A put just below spot can violate that condition despite being OTM. At `d2 = 0`, vanna and charm are zero. Rates and dividends can change these boundaries further.

[OpenGamma Strata's implementation](https://github.com/OpenGamma/Strata/blob/main/modules/pricer/src/main/java/com/opengamma/strata/pricer/impl/option/BlackScholesFormulaRepository.java) provides general Black–Scholes Greek formulas, including carry. The tables below use the restricted assumptions above.

## Greek sign matrix

Each cell lists **gamma / vanna / charm**, with option type on the horizontal axis and trade direction on the vertical axis.

| Trade | OTM CALL | OTM PUT |
| --- | --- | --- |
| Long | Gamma + / Vanna + / Charm − | Gamma + / Vanna − / Charm + |
| Short | Gamma − / Vanna − / Charm + | Gamma − / Vanna + / Charm − |

These are sensitivity signs. To obtain a delta-change sign, multiply each Greek by its input shock.

## Shock matrices

We model two spot-IV co-movement scenarios:

- **Positive correlation:** spot up / IV up, or spot down / IV down.
- **Negative correlation:** spot up / IV down, or spot down / IV up.

Each row includes a positive elapsed-time step. Every Greek column shows that term's **contribution to delta change**, using `+` for longer delta and `−` for shorter delta. For an instantaneous shock, the charm contribution is zero instead. Correlation describes a tendency; it does not require every observed move to follow these scenarios.

### Positive spot-vol correlation

| Spot / IV shock | Trade | Gamma effect | Vanna effect | Charm effect |
| --- | --- | --- | --- | --- |
| Up / Up | Long CALL | + | + | − |
| Up / Up | Short CALL | − | − | + |
| Up / Up | Long PUT | + | − | + |
| Up / Up | Short PUT | − | + | − |
| Down / Down | Long CALL | − | − | − |
| Down / Down | Short CALL | + | + | + |
| Down / Down | Long PUT | − | + | + |
| Down / Down | Short PUT | + | − | − |

### Negative spot-vol correlation

| Spot / IV shock | Trade | Gamma effect | Vanna effect | Charm effect |
| --- | --- | --- | --- | --- |
| Up / Down | Long CALL | + | − | − |
| Up / Down | Short CALL | − | + | + |
| Up / Down | Long PUT | + | + | + |
| Up / Down | Short PUT | − | − | − |
| Down / Up | Long CALL | − | + | − |
| Down / Up | Short CALL | + | − | + |
| Down / Up | Long PUT | − | − | + |
| Down / Up | Short PUT | + | + | − |

## Reading the four trades

**Long OTM call.** With positive correlation, gamma and vanna reinforce each other: a rally makes delta longer, and a selloff makes it shorter. Charm also shortens delta. With negative correlation, gamma and vanna oppose each other in both directions; their relative size determines the market-move effect.

**Short OTM call.** With positive correlation, gamma and vanna both shorten delta on a rally and lengthen it on a selloff. Charm lengthens delta as the short call's negative delta approaches zero. With negative correlation, gamma and vanna oppose each other; charm contributes longer delta in either scenario.

**Long OTM put.** With positive correlation, gamma and vanna oppose each other. Falling spot makes delta more negative, while falling IV makes it less negative. With negative correlation, the two reinforce: a selloff with rising IV makes delta shorter, while a rally with falling IV makes it longer. Charm contributes longer delta.

**Short OTM put.** With positive correlation, gamma and vanna oppose each other. On a selloff, negative gamma makes the position longer delta, but falling IV acting on positive vanna makes it shorter delta. Charm also shortens delta. With negative correlation, falling spot and rising IV both make delta longer; a rally and falling IV both make it shorter.

For a concrete short-put example, take `S = 100`, `K = 90`, `σ = 30%`, `τ = 0.25` years and zero rates and dividends. Differentiating delta gives position gamma ≈ −0.01966, vanna ≈ +0.61674 and annual charm ≈ −0.37004. A local spot fall of 1, an IV fall of one percentage point (`−0.01`) and one elapsed calendar day (`1/365` year) contribute:

```text
gamma: −0.01966 × (−1)     ≈ +0.01966
vanna: +0.61674 × (−0.01)  ≈ −0.00617
charm: −0.37004 × (1/365)  ≈ −0.00101
total change in delta     ≈ +0.01248
```

The position still becomes longer delta, but less than the gamma-only estimate. If IV rises by one percentage point instead, vanna adds about +0.00617 and the total becomes about +0.02481.

A sign matrix cannot determine the net change when contributions oppose each other. Their magnitudes, shock sizes and elapsed time decide the result. For larger moves, reprice and recalculate the Greeks: moneyness, IV and the sensitivities themselves change along the path.

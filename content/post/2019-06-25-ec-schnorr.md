---
layout: post
title:  "Cryptography: EC-Schnorr"
date:   2019-06-25
tags: ["cryptography", "schnorr", "math", "elliptic-curve", "sagemath"]
---


# Overview

    "If you can't explain it simply, you don't understand it well enough" - Einstein

EC-Schnorr, as the name suggests, is a Schnorr-type digital signature scheme over elliptic curve, it's [ECDSA](file:///post/2019-04-09-ecdsa)'s little sister and [Schnorr](file:///post/2019-06-19-schnorr)'s big brother with multiple implementations out there: maybe most widely deployed being [EdDSA](https://en.wikipedia.org/wiki/EdDSA) (used in [Monero](https://web.getmonero.org)) or the upcoming [MuSig](https://blockstream.com/2018/01/23/en-musig-key-aggregation-schnorr-signatures/) implementation in Bitcoin.

It is also one of my favorite digital signature scheme because of its simplicity. As you will see later it is just a linear equation that opens the door to multi signatures and signature aggregation.

     1  import hashlib
     2  p = 103
     3  F = FiniteField(p)
     4  E = EllipticCurve(F, [0, 7])
     5  G = E([97, 10])
     6  n = G.order()
     7  k = randint(2, n)
     8  P = k * G
     9  t = randint(2, n)
    10  R = t * G
    11  m = 6
    12  h = int(hashlib.sha256(str(P) + str(R) + str(m)).hexdigest(), 16)
    13  s = (t + h * k) % n
    14  hv = int(hashlib.sha256(str(P) + str(R) + str(m)).hexdigest(), 16)
    15  print "YOU ARE A CRYPTOSTAR!" if s * G == R + hv * P else "YOU SUCK!"

    YOU ARE A CRYPTOSTAR!


# Elliptic curve multiplication trapdoor

Nothing new under the sun so far, the same elliptic curve \`EC\` defined over finite field \`p\` with generator \`G\` of order \`n\`. See [ECDSA](file:///post/2019-04-09-ecdsa) post for more elliptic curve information.
We start the show by generating a random private key \`k\` and calculate the public key point \`P\`.

    1  import hashlib
    2  p = 103
    3  F = FiniteField(p)
    4  E = EllipticCurve(F, [0, 7])
    5  G = E([97, 10])
    6  n = G.order()
    7  k = randint(2, n)
    8  P = k * G

\`P\` is public parameter while \`k\` is kept secret:

    P

    (7 : 91 : 1)


# Signature

Here is the biggest difference between ECDSA and EC-Schnorr:

-   ECDSA uses division (aka multiplicative inverse) to calculate the signature \`u, v\` parameters
-   EC-Schnorr uses a pre-image hash of public key \`P\`, random point \`R\` and message itself \`m\`.

The rest is simple arithmetic, generate temporary nonce \`t\` and calculate the point \`R\` on elliptic curve, pre-image hash \`h\` and signature challenge \`s\`:

     9  t = randint(2, n)
    10  R = t * G
    11  m = 6
    12  h = int(hashlib.sha256(str(P) + str(R) + str(m)).hexdigest(), 16)
    13  s = (t + h * k) % n

Then the returned signature is a tuple of a point on elliptic curve and scalar value:

    (R, s)

    ((53 : 7 : 1), 95)


# Verification

A third-party receives the (R, s) signature tuple, calculates the deterministic pre-image hash \`hv\` and checks whether or not the equation \`s \* G = R + h \* P\` is valid. This is all folks.

    14  hv = int(hashlib.sha256(str(P) + str(R) + str(m)).hexdigest(), 16)
    15  print "YOU ARE A CRYPTOSTAR!" if s * G == R + hv * P else "YOU SUCK!"

    YOU ARE A CRYPTOSTAR!


# Intuition

Starting with verification equation and going backwards: replace \`s\` with corresponding formula, then replace \`P\` and after reduction we are left with \`G == G\`

    1  s * G == R + h * P
    2  (t + h * k) * G == R + h * P
    3  (t + h * k) * G == t * G + h * k * G
    4  (t + h * k) * G == (t + h * k) * G
    5  G == G

Pretty brilliant huh? but it does not stop here, \`s \* G = R + H \* P\` is a linear equation and we can add / multiply each side while the equation stays valid.

What if we add 2 equations together, side by side?

-   \`s1 \* G1 = R1 + h1 \* P1\`
-   \`s2 \* G2 = R2 + h2 \* P2\`

But this is a subject for another post :)

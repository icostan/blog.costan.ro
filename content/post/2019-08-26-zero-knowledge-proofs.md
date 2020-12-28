---
layout: post
title:  "Zero-knowledge proofs"
subtitle: Cryptography
date:   2019-08-26
tags: ["cryptography", "zero-knowledge-proof", "math", "python", "zcash"]
---

[Zero-knowledge](https://en.wikipedia.org/wiki/Zero-knowledge_proof) is a method to prove that you know a secret \`\`x\`\` (e.g. a password, private key, piece of knowledge, etc) without revealing that secret.

Let's have a look at a few examples and implementations of zero-knowledge proof (ZKP) using different cryptographic schemes.


# Peggy has the private key

Let's say that Peggy (the prover) wants to prove to Victor (the verifier) that she has the private key \`\`x\`\` for public key \`\`X\`\`.
```python
     1  from random import randint
     2  p = 7
     3  g = 3
     4  x = 4
     5  X = g**x % p
     6  r = randint(1, p-1)
     7  R = g**r % p
     8  proof = g**((x+r)%(p-1)) % p
     9  check = X * R % p
    10  print("Peggy has the private key!" ) if proof == check else print("Peggy lies!")

    Peggy has the private key!
```

This is the simplest zero-knowledge implementation based on [the discrete logarithm](https://en.wikipedia.org/wiki/Discrete_logarithm), let's see how it works.

First of all please see [ElGamal](/post/2019-03-26-elgamal/) post to understand discrete logarithm's parameters: prime number \`\`p\`\` and generator \`\`g\`\`.

```python
    1  from random import randint
    2  p = 7
    3  g = 3
```

Next, Peggy generates a random integer \`\`r\`\`, computes the corresponding public key \`\`R\`\` and calculates the \`\`proof\`\` value that will be sent to Victor.

```python
    4  x = 4
    5  X = g**x % p
    6  r = randint(1, p-1)
    7  R = g**r % p
    8  proof = g**((x+r)%(p-1)) % p
```

Victor takes the public keys \`\`X\`\` and \`\`R\`\`, calculates his own \`\`check\`\` value and verifies if Peggy tells the truth or not.

```python
     9  check = X * R % p
    10  print("Peggy has the private key!" ) if proof == check else print("Peggy lies!")
```

Apply the distributive law at line #8 and #9 to see the equality:

```python
    proof == check
    g**(x+r) == X * R
    g**(x+r) == g**x * g**r
```


# Peggy knows the password

These days, pretty much all password-based authentications are implemented the same way; you fill in the password that is sent to server side where:

-   the password is hashed and saved in database (the worst)
-   or adding a salt into the mix to prevent [Rainbow table attacks](https://en.wikipedia.org/wiki/Rainbow_table) (at best)

But what about not sending the password at all, and instead provide a cryptographic proof for your identity?

```python
     1  from random import randint
     2  q = 17
     3  g = 64
     4  x = 4
     5  X = g**x % q
     6  r = randint(1, q-1)
     7  R = g**r % q
     8  c = randint(1, 9999)
     9  s = r + c*x
    10  proof = R * X**c % q
    11  check = g**s % q
    12  print("Peggy knows the password!" ) if proof == check else print("Peggy lies!")

    Peggy knows the password!
```

This is called Schnorr identification scheme and as you will see below, it is an interactive identification scheme.

Please see [Schnorr](/post/2019-06-19-schnorr/) post to understand where these \`\`q\`\` and \`\`g\`\` parameters come from.

```python
    1  from random import randint
    2  q = 17
    3  g = 64
```

Nothing new so far, the same private key \`\`x\`\` (which in this case is just a hash of the actual password), public keys \`\`X\`\` and the temporary ones \`\`r\`\` and \`\`R\`\`.

```python
    4  x = 4
    5  X = g**x % q
    6  r = randint(1, q-1)
    7  R = g**r % q
```

Here comes the clever part, Victor (the verifier) generates a random integer \`\`c\`\` called \`the challenge\` that is sent to Peggy to create the signature \`\`s\`\` and the \`\`proof\`\`.

```python
     8  c = randint(1, 9999)
     9  s = r + c*x
    10  proof = R * X**c % q
```

Victor takes the signature \`\`s\`\`, calculates his own \`\`check\`\` value  and again verifies if Peggy knows the password or not.

```python
    11  check = g**s % q
    12  print("Peggy knows the password!" ) if proof == check else print("Peggy lies!")
```

Distributive and power laws are applied here as well:

```python
    proof == check
    R * X**c == g**s
    g**r * (g**x)**c == g**(r + c*x)
    g**r * g**(x*c) == g**(r + c*x)
    g**(r + x*c) == g**(r + c*x)
```


# Peggy knows two (or many) secrets

Victor wants to check if Peggy knows two numbers that add up to \`5\` without asking Peggy to reveal the actual numbers.

```python
     1  p = 7
     2  g = 3
     3  a1 = 2
     4  A1 = g**a1 % p
     5  a2 = 3
     6  A2 = g**a2 % p
     7  proof = A1 * A2 % p
     8  s = 5
     9  check = g**s % p
    10  print("Peggy knows the two numbers!" ) if proof == check else print("Peggy lies!")

    Peggy knows the two numbers!
```

This is called 'Homomorphic Hiding - HH' and is one of the core concepts in [zk-SNARKs](https://en.wikipedia.org/wiki/Non-interactive_zero-knowledge_proof) that was first implemented in [Zcash](https://z.cash) then ZClassic, Bitcoin Private and so on.

Same prime number \`\`p\`\` and generator \`\`g\`\` from our [trapdoor function](https://en.wikipedia.org/wiki/Trapdoor_function).

```python
    1  p = 7
    2  g = 3
```

\`\`a1\`\` and \`\`a2\`\` are the secrets that Peggy needs to prove, \`\`A1\`\` and \`\`A2\`\` are the corresponding public keys.

```python
    3  a1 = 2
    4  A1 = g**a1 % p
    5  a2 = 3
    6  A2 = g**a2 % p
    7  proof = A1 * A2 % p
```

Since Victor knows the expected result, he only needs to calculate the \`\`check\`\` value and verify if Peggy tells the truth or not.

```python
     8  s = 5
     9  check = g**s % p
    10  print("Peggy knows the two numbers!" ) if proof == check else print("Peggy lies!")
```

It is easy to see the equality is true but why it works the way it works?

```python
    proof == check
    g**a1 * g**a2 = g**s
    g**a1 * g**a2 = g**(a1 + a2)
```

Let's say we have a simple algebraic structure \`\`a + b\`\`, the discrete logarithm trapdoor function \`\`E\`\` and substitute one in the other:

```python
    E(x) = g**x
    E(a + b) = g**(a + b)
    E(a + b) = g**a * g**b
    E(a + b) = E(a) * E(b)
```

It looks pretty simple and clever to me and this is why we multiply the two values to produce the \`\`proof\`\` at line #7.

This is all based on [Homomorphic encryption](https://en.wikipedia.org/wiki/Homomorphic_encryption) and will be the subject of another post but for now this is all you need to remember:
**Homomorphic encryption is a method that allows computation on encrypted data.**


# Alice knows the algorithm

So far, we've proved that Peggy has/knows a private key/password but what about a piece of knowledge like a top-secret algorithm.

```python
     1  p = 7
     2  g = 3
     3  a = 2
     4  b = 5
     5  x = 4
     6  h1 = g**x % p
     7  h2 = g**(x**2) % p
     8  result = h1**a * h2**b % p
     9  P = a*x + b*x**2
    10  check = g**P % p
    11  print("Alice knows the algorithm!" ) if result == check else print("Alice lies!")

    Alice knows the algorithm!
```

This is called 'blind evaluation' of polynomials and is also part of the Zcash implementation, a bit more complex but lets see the details.

Same old, same old \`\`p\`\` and \`\`g\`\` parameters for discrete logarithm trapdoor.

```python
    1  p = 7
    2  g = 3
```

Alice knows the secret algorithm \`P(x) = a\*x + b\*x\*\*2\` and the parameters \`\`a\`\`, \`\`b\`\`.

```python
    3  a = 2
    4  b = 5
```

Bob has the input value \`\`x\`\` and wants the final result without revealing the input \`\`x\`\`. This is the bread and the butter, he needs to calculate two values \`\`h1\`\` and \`\`h2\`\` called the \`hidings\` that are sent to Alice for final computation:

```python
    5  x = 4
    6  h1 = g**x % p
    7  h2 = g**(x**2) % p
```

Alice takes the hidings and calculates the final result without leaking the secret algorithm:

```python
    8  result = h1**a * h2**b % p
```

Now, we will do the computation by ourselves and see if it matches Alice's result.

```python
     9  P = a*x + b*x**2
    10  check = g**P % p
    11  print("Alice knows the algorithm!" ) if result == check else print("Alice lies!")
```

Bingo! zero-knowledge proof on steroids folks, Alice does not learn the input \`\`x\`\` and Bob does not learn the algorithm, where is the catch?

Let's use the same \`\`E\`\` function with a more complex algebraic structure \`\`a\*x + b\*y\`\` where \`a\`, \`b\` are parameters and \`x\`, \`y\` are variables.

```python
    E(i) = g**i
    E(a*x + b*y) = g**(a*x + b*y)
    E(a*x + b*y) = g**(a*x) * g**(b*y)
    E(a*x + b*y) = (g**x)**a * (g**y)**b
    E(a*x + b*y) = E(x)**a * E(y)**b
```

This is the trick that was used at line #8 to calculate the final result without knowing the actual input value.

And with this we are stepping into the land of polynomials and quantum resistant cryptography. Whoever freaks out because quantum computers are coming and will break all cryptosystems, stay calm, the tech is there and is called [Lattice-based cryptography](https://en.wikipedia.org/wiki/Lattice-based_cryptography) and is the subject of yet another post.

Happy hiding.

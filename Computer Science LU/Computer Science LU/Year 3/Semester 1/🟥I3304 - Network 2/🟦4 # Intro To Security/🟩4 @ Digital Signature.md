_Previous [[🟩3 @ Cryptography]]_

---

A digital signature is a cryptographic technique analogous to hand-written signatures:
1. Sender digitally signs document. _(they are the document owner/creator.)_
2. recipient can prove to someone that the sender, and no one else _(including the recipient)_, must have signed the document.

_Simple digital signature for message m:_
![[Pasted image 20230301103625.png|600]]
![[Pasted image 20230301103746.png|600]]

# Message Digests
A message digest is a fixed-length, condensed representation of a message or data that is used to ensure the integrity and authenticity of the message.
It is also commonly referred to as a hash value or a checksum.

It is computationally expensive to public-key-encrypt long messages.

_For example:_
Apply hash function H to m, get fixed size message digest, H(m)
![[Pasted image 20230301104326.png]]

**Hash function properties:**
- many-to-1
- Produces fixed-size msg digest _(fingerprint)_
- Given message digest x, computationally infeasible to find m such that x = H(m)

Digital signature = signed message digest
![[Pasted image 20230301104644.png|700]]
# Internet Checksum
Internet checksum has some properties of hash function:
- produces fixed length digest _(16-bit sum)_ of message
- is many-to-one

but given message with given hash value, it is easy to find another message with same hash value:

# Secure Sockets Layer (SSL)
It is a widely deployed security protocol, and provides:
- confidentiality
- integrity
- authentication

![[Pasted image 20230301104839.png|400]]
SSL provides application programming interface (API) to applications

## Toy SSL
- `handshake:` sender and receiver use their private keys to authenticate each other and exchange shared secret
- `key derivation:` sender and receiver use shared secret to derive set of keys
- `data transfer:` data to be transferred is broken up into series of records
- `connection closure:` special messages to securely close connection

## Real SSL Connection
![[Pasted image 20230301105114.png|700]]

---
_Previous [[🟩3 @ Cryptography]]_

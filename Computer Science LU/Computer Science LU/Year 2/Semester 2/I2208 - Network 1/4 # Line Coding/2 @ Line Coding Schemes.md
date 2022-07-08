# SUMMARY
![[Pasted image 20220706170110.png]]
--- 
# Unipolar `NRZ` scheme
Unipolar encoding uses only one voltage level.
![[Pasted image 20220706164610.png | 300]]

This scheme uses less bandwidth but it lacks any sync so its not often used for signal transmission

---
# Polar schemes
Polar encoding uses two voltage levels **(positive and negative).**

## NRZ-L & NRZ-I
In Non-return to Zero-level `(NRZ-L)` the level of the signal is **dependent upon the state of the bit.**
In Non-return to Zero-Invert `(NRZ-I)` the signal is **inverted if a 1 is encountered.**
![[Pasted image 20220706165018.png | 450]]

# RZ (return-to-zero)
In `RZ` the signal level **returns to zero at every cycle.**
![[Pasted image 20220706165335.png | 400]]

## Biphase: Manchester & Differential Manchester
In `Manchester` and `differential Manchester` encoding, the transition at the middle of the bit is used for synchronization.
![[Pasted image 20220706165432.png | 500]]

---

# Bipolar Schemes
In bipolar encoding, we use three levels:
- **positive, zero, and negative.**

## AMI & Pesudotenary
![[Pasted image 20220706165815.png | 450]]
- `AMI:`
	- AMI means alternate 1 inversion
	- **The neutral zero voltage represents binary 0.**
	- **Binary 1s are represented by alternating positive and negative voltages.**
- `Pesudotenary:`
	- Same as AMI, but **1 bit is encoded as a zero voltage** and the **0 bit is encoded as alternating positive and negative voltages.**

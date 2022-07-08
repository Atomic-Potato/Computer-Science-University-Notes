
Guided media, which  are  those that  provide  a  conduit from  one  device  to , another, include `twisted-pair` cable, `coaxial` cable, and `fiber-optic` cable

# Twisted-pair Cable
![[Pasted image 20220704173143.png]]
- Two copper conductors
- One carriers signals, the other is the ground reference
- Receiver operates on the difference between the signals. This is why they are twisted, to maintain balance, so more twists mean better quality.

**How we reduce noise by twisting the cables:**
- if the cables are straight lines `(Noise decreases over distance)`
![[Pasted image 20220704173344.png | 500]]

- if the cables are twisted, then they would share the noise, thus it will become balanced between each cable
![[Pasted image 20220704173508.png | 500]]

## Measuring the performance of twisted cables
- One way to measure the performance of twisted-pair cable is to compare `attenuation / fading` versus `frequency and distance`. A twisted-pair cable can pass a wide range of frequencies.
- The attenuation, measured in decibels per kilometer (dB/km), sharply increases with frequencies above 100 kHz.
	![[Pasted image 20220704174015.png]]
`Note`:  gauge  is a measure of the thickness of the wire.

# Coaxial Cable
![[Pasted image 20220704174250.png]]
A coaxial cable consists of the following:
- (1) Outer cable jacket to prevent minor physical damage
- (2) A woven copper braid, or metallic foil, acts as the second wire in the circuit and as a shield for the inner conductor.
- (3) A layer of flexible plastic insulation
- (4) A copper conductor is used to transmit the electronic signals.

Commonly used in the following situations:
- Wireless installations - attach antennas to wireless devices
- Cable internet installations - customer premises wiring

## Performance
The attenuation is high in coaxial cable than in twisted-pair cable. In other words, although coaxial cable has a much higher bandwidth, the 
signal weakens rapidly and requires the frequent use of repeaters.
![[Pasted image 20220704174532.png]]

# Fiber-Optic Cabling
- Transmits data over longer distances at higher bandwidth than any other networking media
- Less susceptible to attenuation, and completely immune to EMI/RFI
- Made of flexible, extremely thin strands of very pure glass
- Uses a laser or LED to encode bits as pulses of light
- The fiber-optic cable acts as a wave guide to transmit light between the two ends with minimal signal loss

## Types of Fiber Media
- **Single-Mode Fiber** ^singleModeFiber
	Very small core / Uses expensive lasers / Long-distance applications
![[Pasted image 20220704175142.png]]
- **Multimode Fiber** ^multiModeFiber
Larger core / Uses less expensive LEDs / LEDs transmit at different angles / Up to 10 Gbps over 550 meters
![[Pasted image 20220704175234.png]]

Dispersion refers to the spreading out of a light pulse over time. Increased dispersion means increased loss of signal strength. `MMF`(multimode) has greater dispersion than `SMF`(single mode), with a the maximum cable distance for MMF is 550 meters.

## Performance
The plot of attenuation versus wavelength is flatter than in the case of twisted-pair cable and coaxial cable.
The performance is such that we need fewer (actually one-tenth as many) repeaters when we use fiber-optic cable.
![[Pasted image 20220704175631.png]]

## Usage
Fiber-optic cabling is now being used in four types of industry:
1. **Enterprise Networks** - Used for backbone cabling applications and interconnecting infrastructure devices
2. **Fiber-to-the-Home (FTTH)** - Used to provide always-on broadband services to homes and small businesses
3. **Long-Haul Networks** - Used by service providers to connect countries and cities
4. **Submarine Cable Networks** - Used to provide reliable high-speed, high-capacity solutions capable of surviving in harsh undersea environments at up to transoceanic distances.

Our focus in this course is the use of fiber within the enterprise.
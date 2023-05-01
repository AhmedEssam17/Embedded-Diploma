

#ifndef UTILS_H_
#define UTILS_H_

#define SetBit(reg, bit)	(reg |= 1<<bit)
#define ClearBit(reg, bit)	(reg &= ~(1<<bit))
#define ToggleBit(reg, bit) (reg ^= 1<<bit)
#define ReadBit(reg, bit)	(reg = (reg & 1<<bit) >>bit)

#endif /* UTILS_H_ */
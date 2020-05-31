# ShiVaStringmath
If you ever run into the limits of Lua numbers in ShiVa, this library can help you. Instead of numbers, you can feed strings into these functions which will be converted to the corresponding C number types.

## Usage example
```
local res1 = sm.calculateSignedLong ( "890922592", "100000", sm.kAdd )
local res2 = sm.calculateSignedLong ( "-890922592", "-100000", sm.kSubtract )
local res3 = sm.calculateDouble ( "1.3", "2.4", sm.kAdd )
local res4 = sm.calculateUnsignedLong ( "888888888888888888", "111111111111111111", sm.kAdd )
local res5 = sm.calculateUnsignedLong ( "100", "3", sm.kPow )
```

## Supported number types
- double
- signed long (long)
- unsigned long (long)

## Supported operations
- addition
- subtraction
- multiplication
- division
- power


# Measuring Distance with an HC-SR04 Ultrasonic Sensor

ok so i bought this ultrasonic sensor because i wanted to build a radar thing i saw on youtube. then it sat in a drawer for a month because every tutorial made it sound way more complicated than it actually is. turns out it's just a speaker and a microphone that use sound to measure distance. like a bat.

this tutorial will get you from zero to reading distances in centimeters in about 15 minutes. no prior knowledge assumed. just the wire, the code, and why it works.

---

## what you need

| part | notes |
|------|-------|
| arduino uno r3 | or compatible |
| hc-sr04 ultrasonic sensor | the one with two silver cylinders |
| breadboard | any size |
| 4 male-to-male jumper wires | |

no soldering. no extra power supply. the arduino can power this sensor fine from its 5v pin.

---

## wiring

the sensor has 4 pins: VCC, Trig, Echo, GND.

- VCC → 5V on the arduino
- GND → GND on the arduino
- Trig → pin 9
- Echo → pin 10

the first time i wired this i accidentally swapped trig and echo. the sensor just printed zeros forever and i thought it was broken. nope. just had the pins backwards. trig sends the pulse, echo listens for it — they're not interchangeable.

---

## the code

the sketch is called `distance_meter.ino`. open it in the arduino ide, select your board and port, and click upload. then open the serial monitor at 9600 baud and you'll see distance readings in centimeters.

in short: the code sends a short pulse from pin 9 (trig), then listens on pin 10 (echo) for how long it takes to come back. since sound travels at about 0.034 cm per microsecond, you can convert the time into distance. the formula is `distance = (time * 0.034) / 2` — you divide by 2 because the sound goes to the object AND back.

---

## how it works

the sensor has two main parts: a tiny speaker (the transmitter) and a tiny microphone (the receiver). when you send a 10-microsecond HIGH pulse to the trig pin, the sensor sends out 8 bursts of ultrasonic sound at 40kHz — way above what humans can hear. then it listens.

the echo pin goes HIGH as soon as the sound leaves and stays HIGH until the echo comes back. the arduino uses `pulseIn()` to measure exactly how many microseconds that took. then the math converts time to distance.

the speed of sound changes a little with temperature and humidity, but 0.034 cm/µs is close enough for room temperature. if you want extreme precision you'd need to compensate, but for most projects this is fine.

---

## problems i hit

- **serial monitor shows zeros and nothing changes:** i had trig and echo swapped. check your wiring.
- **readings jump around randomly:** the sensor was pointing at a soft surface (my curtain). soft things absorb sound. point it at something solid.
- **no readings at all, serial monitor is blank:** my usb cable was charge-only with no data lines. switched cables and it worked immediately.
- **readings are consistently wrong by a few cm:** the sensor has a minimum range of about 2cm. anything closer than that will give bad readings. also make sure nothing is blocking the sensor's "view" — the sound spreads out in a cone.

---

## next steps

this is part of a series i'm building. so far i've done:
- ultrasonic sensor (this one)
- servo motor (sg90)

next is the joystick module, then combining the ultrasonic and servo to make a motion tracker that points at the nearest object.

---

## why this exists

i'm parham. i'm 15 and i live in iran. building stuff here under sanctions means you can't just order whatever you want — you work with what you have and you share what you learn. i write these tutorials because knowledge shouldn't be behind paywalls or sanctions. if you're a kid who just got their first arduino and you're sitting there feeling lost — this is for you. seriously.

---

## about me

i'm parham. i'm 15 and i live in iran. i write these tutorials because knowledge shouldn't be locked behind paywalls or sanctions. if you're just starting out and you feel lost — this is for you. seriously.

---

mit license — use this however you want, just keep it open.
contact: inquiline.dev@proton.me

---

ok that's it. go measure something. if it breaks open an issue. — parham

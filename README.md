# simple-ultrasonic
The easiest possible distance sensor tutorial — because everyone deserves to understand what their hands build.


# 📏 Simple Ultrasonic Distance Sensor

*A project so simple a 10‑year‑old can build it — and understand every piece.*

You will turn an **HC-SR04 ultrasonic sensor** and an **Arduino Uno** into a digital measuring tape.  
No cloud, no imports — just sound waves and curiosity.

---

## 🧠 What is an ultrasonic sensor?

It’s like a bat. It sends out a high‑pitched *click* that human ears can’t hear, then listens for the echo.  
By counting how long the sound takes to bounce back, it figures out how far away something is.

**The two “eyes” on the sensor:**
- **Trig** – the mouth. It sends the sound pulse.
- **Echo** – the ear. It listens for the return.

---

## 🧱 What you need

| Component          | Quantity |
|--------------------|----------|
| Arduino Uno R3     | 1        |
| HC‑SR04 ultrasonic sensor | 1 |
| Breadboard         | 1        |
| Jumper wires (male‑to‑male) | 4 |

**No soldering. No extra modules.**

---

## ⚡ Wiring (text diagram)
Arduino Uno HC-SR04

5V ------------ VCC
GND ------------ GND
D9 ------------ Trig
D10 ------------ Echo



If your sensor module has 4 pins, that’s all of them. Power it from the Arduino’s 5V.

> *Plug the sensor into your breadboard so it doesn’t dangle. Keep it pointing at an open space.*

---

## 💻 The Code

Open the Arduino IDE, copy the file `distance_meter.ino` (see below), and upload it to your board.

Then open the **Serial Monitor** (Tools → Serial Monitor, set baud to `9600`).  
You’ll see:
Distance: 17.3 cm
Distance: 17.1 cm
Distance: 17.5 cm


Put your hand in front of the sensor and watch the numbers change.

---

## 🔬 How the code works (explained for a 10‑year‑old)

1. The Arduino sends a very short `HIGH` pulse to the **Trig** pin.  
2. The sensor sends out 8 ultrasonic clicks.  
3. The **Echo** pin goes `HIGH` as soon as the sound leaves, and goes `LOW` when the echo returns.  
4. The Arduino measures how many microseconds the Echo pin stayed `HIGH`.  
5. Sound travels at **0.034 cm per microsecond** (in air).  
6. Distance = (time × speed) ÷ 2  *(÷2 because the sound goes there AND back)*.  

That’s the whole magic.

---

## 🧪 Try these experiments

- Point the sensor at a wall and walk backwards. What do you see?
- Put a soft object (pillow) and a hard object (book) at the same distance. Does the reading change? Why?
- Angle the sensor slightly — how does the beam width affect the reading?

---

## 🤝 Why this project exists

I’m Parham. I’m 15 and I live in Iran. I built this because the first step into robotics should be so clear that nobody feels stupid.  
If you are a kid who just got their first Arduino, this is for you.  
If you are an adult who was always afraid of wires, this is for you too.

**Knowledge shouldn’t be locked behind paywalls or import sanctions. Sound waves are free.**

---

## 📄 License

MIT — use this however you like, just keep it open.

---

## 📬 Contact

inquiline.dev@proton.me

# 🚦 ESP8266 Blynk Smart Traffic Light Controller

<p align="center">
  <b>IoT-Based Smart Traffic Light Control using ESP8266 and Blynk Cloud</b><br>
  <i>Real-time web and mobile control for connected traffic lights</i>
</p>

---

## 🌟 Project Overview

This project is an **IoT-enabled traffic light controller** built using an **ESP8266 NodeMCU** and **Blynk IoT**.

The system provides three independently controllable traffic lights:

| Light | Blynk Datastream | Function |
|---|---|---|
| 🔴 Red | `V0` | Turn Red ON/OFF |
| 🟡 Yellow | `V1` | Turn Yellow ON/OFF |
| 🟢 Green | `V2` | Turn Green ON/OFF |

The lights can be controlled remotely from a **Blynk web dashboard** or the **Blynk mobile application**.

> **Main flow:** Blynk Dashboard → Blynk Cloud → Wi-Fi → ESP8266 → Physical LEDs

---

## 🎯 Objectives

- Control traffic lights remotely using IoT.
- Connect ESP8266 to Blynk Cloud through Wi-Fi.
- Provide separate ON/OFF controls for Red, Yellow, and Green LEDs.
- Control the same hardware from web and mobile interfaces.
- Demonstrate real-time IoT device control.

---

## ✨ Features

- 🔴 Independent Red light control
- 🟡 Independent Yellow light control
- 🟢 Independent Green light control
- 🌐 Blynk web dashboard
- 📱 Blynk mobile control
- 📡 Wi-Fi communication
- ⚡ Real-time ESP8266 response
- 🧩 Simple and expandable architecture

---

## 🏗️ System Architecture

```text
                 ┌──────────────────────┐
                 │       👤 USER        │
                 └──────────┬───────────┘
                            │
                 ┌──────────▼───────────┐
                 │  🌐 WEB / 📱 MOBILE  │
                 │    BLYNK DASHBOARD   │
                 └──────────┬───────────┘
                            │
                            ▼
                 ┌──────────────────────┐
                 │    ☁️ BLYNK CLOUD    │
                 └──────────┬───────────┘
                            │
                         Wi-Fi
                            │
                            ▼
                 ┌──────────────────────┐
                 │   📡 ESP8266 NODEMCU │
                 └──────┬─────┬─────┬───┘
                        │     │     │
                       V0    V1    V2
                        │     │     │
                        ▼     ▼     ▼
                       🔴    🟡    🟢
```

---

## 🔄 How It Works

1. The user opens the Blynk dashboard.
2. The user switches a traffic light ON or OFF.
3. Blynk sends the corresponding datastream value through the cloud.
4. ESP8266 receives the value through Wi-Fi.
5. The ESP8266 changes the corresponding GPIO output.
6. The physical traffic light changes immediately.

Example:

```text
Red Switch ON
     ↓
   V0 = 1
     ↓
Blynk Cloud
     ↓
  ESP8266
     ↓
🔴 RED LED ON
```

---

## 📊 Blynk Datastream Configuration

For simple ON/OFF control:

| Datastream | Light | Type | Min | Max |
|---|---|---|---:|---:|
| `V0` | 🔴 Red | Integer | 0 | 1 |
| `V1` | 🟡 Yellow | Integer | 0 | 1 |
| `V2` | 🟢 Green | Integer | 0 | 1 |

Values:

```text
0 → OFF
1 → ON
```

Using Integer datastreams keeps the ON/OFF control simple.

---

## 🖥️ Blynk Dashboard

The dashboard should contain three switch controls:

```text
┌───────────────────────────────┐
│       🚦 TRAFFIC LIGHT        │
├───────────────────────────────┤
│ 🔴 RED       [ ON / OFF ]     │
│ 🟡 YELLOW    [ ON / OFF ]     │
│ 🟢 GREEN     [ ON / OFF ]     │
└───────────────────────────────┘
```

Mapping:

```text
🔴 Red Switch     → V0
🟡 Yellow Switch  → V1
🟢 Green Switch   → V2
```

---

## 📱 Mobile Control

The same Blynk project can be opened in the **Blynk mobile application**.

```text
📱 Blynk App
     ↓
☁️ Blynk Cloud
     ↓
📡 ESP8266
     ↓
🚦 Physical Traffic Lights
```

This allows remote control of the lights using a phone.

---

## 🔌 Hardware Components

| Component | Quantity | Purpose |
|---|---:|---|
| ESP8266 NodeMCU | 1 | Main IoT controller |
| Red LED | 1 | Red traffic signal |
| Yellow LED | 1 | Yellow traffic signal |
| Green LED | 1 | Green traffic signal |
| Resistors | 3 | LED current limiting |
| Breadboard | 1 | Circuit prototyping |
| Jumper wires | As required | Connections |
| USB cable | 1 | Programming and power |

---

## 💻 Technologies Used

- **ESP8266 NodeMCU**
- **Arduino IDE**
- **C/C++**
- **Blynk IoT**
- **Blynk Cloud**
- **Wi-Fi**
- **HTML/Cloud Dashboard through Blynk**

---

## ⚙️ Setup

### 1. Install Arduino IDE

Install Arduino IDE and configure it for ESP8266.

Select:

```text
Board → ESP8266 → NodeMCU 1.0 (ESP-12E Module)
```

### 2. Install Blynk Library

Open:

```text
Arduino IDE
→ Library Manager
→ Search "Blynk"
→ Install
```

### 3. Create Blynk Template

Create a Blynk template using:

```text
Hardware: ESP8266
Connection: WiFi
```

### 4. Create Datastreams

Create:

```text
V0 → Red
V1 → Yellow
V2 → Green
```

Set each to:

```text
Type: Integer
Minimum: 0
Maximum: 1
```

### 5. Create Dashboard

Add three Switch widgets:

```text
🔴 Red    → V0
🟡 Yellow → V1
🟢 Green  → V2
```

### 6. Configure ESP8266 Code

Open:

```text
code/traffic_light_blynk.ino
```

Replace the placeholders:

```cpp
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_DEVICE_TOKEN"

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";
```

### 7. Upload

Connect the ESP8266 to the computer, select the correct COM port, and upload the program.

### 8. Test

Open the Blynk dashboard and switch each light ON/OFF.

---

## 🧪 Testing

### 🔴 Red Light

```text
V0 = 1 → 🔴 ON
V0 = 0 → 🔴 OFF
```

### 🟡 Yellow Light

```text
V1 = 1 → 🟡 ON
V1 = 0 → 🟡 OFF
```

### 🟢 Green Light

```text
V2 = 1 → 🟢 ON
V2 = 0 → 🟢 OFF
```

### 📱 Mobile Test

Open the Blynk project on the phone and toggle the switches.

The physical LEDs should respond through the ESP8266.

---

## 🔐 Security

**Never upload real credentials to GitHub.**

Do NOT publish:

- ❌ Blynk Auth Token
- ❌ Wi-Fi password
- ❌ API keys
- ❌ Private credentials

Use placeholders:

```cpp
#define BLYNK_AUTH_TOKEN "YOUR_DEVICE_TOKEN"

char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";
```

---

## 📁 Repository Structure

```text
ESP8266-Blynk-Traffic-Light/
│
├── 📄 README.md
├── 📄 .gitignore
│
├── 📂 code/
│   └── 📄 traffic_light_blynk.ino
│
├── 📂 circuit/
│   └── 🖼️ circuit_diagram.png
│
└── 📂 images/
    ├── 🖼️ project-banner.jpg
    ├── 🖼️ blynk_dashboard.jpg
    └── 🖼️ hardware_setup.jpg
```

---

## 🚀 Future Enhancements

- ⏱️ Automatic traffic light timing
- 🚗 Traffic density detection
- 🚑 Emergency vehicle priority
- 📊 Traffic monitoring and analytics
- 🔔 Fault/error notifications
- 🤖 AI-based traffic optimization
- 🔄 Automatic / Manual modes
- 🌐 Custom web dashboard

---

## 🧠 Learning Outcomes

This project demonstrates:

- IoT device connectivity
- ESP8266 programming
- GPIO control
- Wi-Fi communication
- Cloud-based device control
- Blynk virtual datastreams
- Web and mobile IoT dashboards
- Real-time hardware control

---

## 👨‍💻 Author

**Pranay Gour N**

B.Tech Computer Science & Engineering  
Artificial Intelligence & Machine Learning

---

<p align="center">
  🚦 <b>Smart Control • IoT Connectivity • Real-Time Automation</b> 🚦
</p>

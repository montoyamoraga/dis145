## Diagrama Eléctrico

```markdown
# Conexiones del Joystick:
- SW (Switch) del joystick -> Pin D2 del Arduino.
- VRY (Vertical) del joystick -> Pin A1 del Arduino.
- VRX (Horizontal) del joystick -> Pin A0 del Arduino.
- 5V del joystick -> Fuente de 5V del PCB.
- GND del joystick -> GND del PCB.

# Conexiones de la Pantalla LCD:
- SCL de la pantalla LCD -> Pin A5 del Arduino.
- SDA de la pantalla LCD -> Pin A4 del Arduino.
- VCC de la pantalla LCD -> Fuente de 5V del PCB.
- GND de la pantalla LCD -> GND del PCB.

# Conexiones del Driver del Motor Paso a Paso:
- IN1 del driver -> Pin D8 del Arduino.
- IN2 del driver -> Pin D9 del Arduino.
- IN3 del driver -> Pin D10 del Arduino.
- IN4 del driver -> Pin D11 del Arduino.
- 5V del driver -> Fuente de 5V del PCB.
- GND del driver -> GND del PCB.

# Conexiones del Servo:
- Cable amarillo del servo -> Pin D3 del Arduino.
- Cable rojo del servo -> Fuente de 5V del PCB.
- Cable marrón del servo -> GND del PCB.

# Conexiones del PCB (Placa de Circuito Impreso):
- Fuente de 5V del PCB -> 5V del Arduino.
- GND del PCB -> GND del Arduino.

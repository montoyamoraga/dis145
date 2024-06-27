 ## Log de Errores y Soluciones

### Errores en la Impresión
```markdown
1. **Soportes de árbol en vez de lineal, con mucha densidad de relleno**
   - **Problema:** Los soportes de árbol tenían demasiada densidad de relleno, lo que los hacía difíciles de quitar.
   - **Solución:** Cambiar los soportes a lineales y reducir la densidad del relleno para facilitar su remoción.

2. **Soportes de placa unidos a la base**
   - **Problema:** La base estaba muy pegada al archivo debido al tipo de soportes utilizados, lo que dificultaba la separación.
   - **Solución:** No incluir la base, ya que no es necesaria. Si se incluye, asegurar que los soportes no estén unidos a la placa.

3. **Desproporciones en el espacio del LCD del escáner**
   - **Problema:** El espacio para el LCD no permitía que el módulo I2C y los cables Dupont entrasen en la base.
   - **Solución:** Lijar con una Dremel las desproporciones, asegurándose de que quepan tanto el módulo de joystick como el módulo de LCD.

4. **Engranaje circular no funcionaba correctamente**
   - **Problema:** Las piezas del engranaje circular estaban demasiado pegadas, causando roce y obstrucciones.
   - **Solución:** Eliminar la pieza externa e imprimirla de forma aislada. Cambiar la hendidura del modelo base del escáner para no requerir de un encaje específico.

5. **Agujeros para tornillos M2 obstruidos por soportes**
   - **Problema:** Los soportes impedían hacer los agujeros para los tornillos M2 de los componentes.
   - **Solución:** Utilizar silicona caliente y superpegamento para fijar los componentes en lugar de los tornillos.

### Errores en el Hardware

1. **Botón de Bluetooth no funcionaba**
   - **Problema:** La distancia entre el servo y el control era excesiva, y el primer control estaba defectuoso y no capturaba fotos.
   - **Solución:** Comprar un nuevo control y volver a instalarlo, eliminando el seguro del botón para que tenga mayor sensibilidad al tacto del motor.

2. **Servo motor inicial no adecuado**
   - **Problema:** El servo de 90 grados tenía el cable por la parte central, mientras que el modelo estaba preparado para otro modelo de microservo 9g.
   - **Solución:** Comprar un servo de 180° con el cable por la parte trasera que se ajusta al diseño ya impreso.

3. **Placa de Arduino no reconocida por el puerto COM**
   - **Problema:** La placa de Arduino no conectaba ni era reconocida por el puerto COM del computador.
   - **Solución:** Cambiar la placa y reemplazar todas las conexiones.

4. **Insuficiencia de conexiones 5V y GND**
   - **Problema:** Se requerían 4 conexiones 5V y 4 conexiones GND para los dos motores, el LCD y el joystick.
   - **Solución Temporal:** Usar una breadboard conectada externamente para probar el código.
   - **Solución Final:** Cortar a medida una PCB de doble lado y soldar las conexiones de los 4 componentes. Luego, pegarlas dentro de la base, abajo de la placa y al lado del control. Conectar los GND/power de los componentes así como la conexión GND y 5V a la Arduino Uno R3.

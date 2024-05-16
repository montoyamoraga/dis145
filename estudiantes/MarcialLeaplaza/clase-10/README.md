# clase-10
05/16/2024

# De MIDI a grasshopper
Necesito conseguir un controlaodr MIDI para poder conectarlo a mi computadora y usarlo para manupular sliders en grasshopper.

- El controlador MIDI Korg nanopad2. Este controlador se puede conectar por USB, incluye muchos botones y un trackpad que emite mensajes de cambio de control.
- Burcar en facebook marketplace...

Necesito conseguir una forma de comunicar a grasshopper con el controlador.

Por ahora estoy aprendiendo lo basico. Decidí usar C# ya que me permitirá eventualmente crear mi propio plugin para grasshopper para usa controladores MIDI en grasshopper.

Por ahora puedo hacer codigos muy básicos, ya puedo crear y manipular objetos en rhino desde grasshopper usando bloques de C# script.

![Figura1](./imagenes/CScript.png)

- Aprender a leer inputs de MIDI.
- Traducir los inputs a valores utiles.
- Asignar esos valores a un grasshopper.



Necesito crear una interfase que me permita asignar un componente de grasshopper con un componente del controlador.


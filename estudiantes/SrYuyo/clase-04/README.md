# clase-04

Revisión bibliotecas y codigos.

Codigos:
* <https://construyendoachispas.blog/2021/10/31/usar-arduino-como-si-fuera-un-raton/>
* <https://www.arduino.cc/reference/en/language/functions/usb/mouse/>
* <https://www.arduino.cc/reference/en/libraries/mouse/>


Aparentemente se puede emular un mouse directamente con las biblioteca "mpuse.h" y sus respectivas funciones.
  * <https://www.youtube.com/watch?v=lkvJsrufmjE&ab_channel=ProgrammingElectronicsAcademy> (explicación respectiva de cada función de la biblioteca)

La biblioteca mouse presenta problemas con las funciones "Mouse.begin()" y "Mouse.end()", al momento de llamarlas no se ejecuta un codigo o lista de ordenes. **Revisar codigo en Github y pagina de arduino**

La función "Mouse.click()" hara click en donde tengamos nuestro puntero, se debe tener cuidado al llamarla, pues si esta en un loop y no se linkea a un boton de la placa se hara click en cada iteración del ciclo donde este nuestro cursor. Se pierde el control del mouse con cualquier función proviniente de la biblioteca. Usar un controlador con boton push o similiar para el arranque del codigo. Por defecto se utiliza el click izquierdo, pero se pude configurar para "MOUSE_LEFT", "MOUSE_RIGHT" "MOUSE_MIDDLE"

La función "Mouse.move()" recibe tres argumentos los cuales deben  incluirse en la función misma. Tenemos "xAxis", "yAxis" y "wheel". **Recordar que las variables son editables, solo son una referencia más clara para entender el como**. Las coordenadas son respecto al plano de la pantalla y de la posición actual del mpuse, el movimiento es al del plano cartesiano, pero con los ejes invertidos en sentido. Valores desde -128 a 127

Para mantener un click se utiliza la funcion "Mouse.press()". Por defecto se utiliza la click izquierdo, pero se puede configurar igual que la función "Mouse.click". 

"Mouse.isPressed()" sirve para entregrar el valor respectivo de la tecla de forma boleana, es decir verdadero o falso (0 o 1). Se puede configurar para la tecla necesaria, por default viene para la tecla izquierda del mouse.



**REFERENCIAS**

<https://construyendoachispas.blog/2021/10/31/usar-arduino-como-si-fuera-un-raton/>
<https://www.arduino.cc/reference/en/language/functions/usb/mouse/>
<https://www.arduino.cc/reference/en/libraries/mouse/>
<https://www.arduino.cc/reference/en/libraries/mouse/mouse.click/>
<https://www.arduino.cc/reference/en/libraries/mouse/mouse.move/>
<https://www.arduino.cc/reference/en/libraries/mouse/mouse.press/>
<https://www.arduino.cc/reference/en/libraries/mouse/mouse.release/>
<https://www.arduino.cc/reference/en/libraries/mouse/mouse.ispressed/>
<https://www.youtube.com/watch?v=lkvJsrufmjE&ab_channel=ProgrammingElectronicsAcademy>




# clase-04
PROYECTO MOUSE
clase-04

2024-03-28

El objetivo del proyecto es simular mouse mediante arduino y componentes electronicos generando que este distinga entre click derecho, click izquierdo, doble click, y ademas, agregar una funcionalidad extra como el sensor de movimiento que tiene el mouse para que sea un mouse extendido especulativo

Por josefinasanchezr

Hecho con simulacion Tinkercard

Para Arduino UNO R3

¿Qué aprendimos en el proceso?
(Tips y datos)

Explicación cómo funciona un botón
boton

Funcionalidad Simple
Que el mouse pueda distinguir entre click derecho, click izquierdo y doble click

Click Derecho - Click Izquierdo
El código permite que se distinga entre click derecho y click izquierdo imprimiendo en la consola según corresponde la respuesta de la accion.

Simulación Tinkercad:

simulación01 **subir video simulacion

Código en Arduino:

codigo ClickDerIzq

Doble Click
El código permite que se distinga si la accion pertenece o no a un doble click.

No logré que se distinga el doble click, ya que el codigo confunde cuando uno deja el boton apretado con que se generó un doble click porque todo se procesa muy rapido. Me falta agrgar otra variable que permita al coigo entender que primer se apreta una vez el boton, se suelta el boton y luego de un delay corto se vuelve a apreetar el boton generandoa si un correcto doble click.

Simulación Tinkercad:

simulación02 **subir video simulacion

Código en Arduino:

Codigo Doble Click

Funcionalidad Extra
Referencias y Fuentes
Para inspirarme en el estilo del documento, la organizacion y formato de este me basé en los proyectos y README.md de @poly555 en GitHub
Para realizar el codigo del ClikDerecho ClickIZquierdo me basé en los ejemplos que publica la documentacion de Arduino en https://docs.arduino.cc/?_gl=1*veav4*_ga*MTU3MTQ3Nzg3NS4xNzExNjU0NzY3*_ga_NEXN8H46L5*MTcxMTY1NDc2Ni4xLjAuMTcxMTY1NDc3NS4wLjAuMTY5MTY4MTc2Ng..*_fplc*SzllWERYQjNGeUwzMnEwaHAlMkJLNkpCUGRQSFhTcDdMYnI5Skp4a0dJeDBzeGh2dGx3YXI4NTNyTmJGejhGbTZwMHBqdVdWOG92UVVMcHVEclF3REdTaWZ0ZlpjWkUwUHBjWWVNU1ZtZnVVZnNEa1FjREE2eFFUSkJOOFJmWUElM0QlM0Q.

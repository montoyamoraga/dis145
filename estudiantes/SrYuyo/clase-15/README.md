# **PROYECTO FINAL DIS145**

Free - All Right Now

# **ABSTRACT**

El desperdicio de alimentos es un problema global con consecuencias ambientales y económicas significativas. Según la FAO, un tercio de los alimentos producidos para el consumo humano se pierden o desperdician cada año, mayoritariamente en los hogares. Para abordar este problema, se propone un sistema inteligente de monitoreo de alimentos utilizando sensores que detectan su estado y urgencia de consumo. Este dispositivo, que emplea sensores de gas (MQ2) y de humedad y temperatura (DHT11), proporciona información en tiempo real para reducir el desperdicio alimentario, fomentar la economía circular y estimular el compostaje. Además, puede integrarse con aplicaciones móviles para compartir alimentos y gestionar residuos orgánicos.


# **RESUMEN**

En la contemporaneidad, la problemática del desperdicio de alimentos constituye un desafío global de gran magnitud, con impactos significativos tanto ambientales como económicos. Según la Organización de las Naciones Unidas para la Agricultura y la Alimentación (FAO), aproximadamente un tercio de la producción mundial de alimentos destinados al consumo humano se pierde o desperdicia anualmente. La mayoría de estas pérdidas ocurren en los hogares, lo que subraya la necesidad de desarrollar soluciones innovadoras para mitigar este fenómeno.

Una solución prometedora es un sistema inteligente de monitoreo del estado de los alimentos, que utiliza sensores para determinar su idoneidad para el consumo, la urgencia de su consumo y su estado de descomposición. Este dispositivo, al proporcionar información en tiempo real sobre la condición de los alimentos, permite a los usuarios tomar decisiones informadas sobre su consumo, con el potencial de reducir significativamente el desperdicio de alimentos.

En base a lo planteado el objetivo principal es desarrollar un dispositivo que sea eficiente en términos de código y funcionalidad. Además, se busca asegurar el funcionamiento simultáneo de ambas aplicaciones (compartir alimentos y compostaje), las cuales no se concretaron previamente en el proyecto



https://github.com/SrYuyo/dis145/blob/main/estudiantes/SrYuyo/clase-15/Video%20publicitario.mp4


# **COMPONENTES UTILIZADOS**

1. -Sensor MQ2 (Sensor de Gas): Este sensor detecta la presencia de gases nocivos como amoníaco, metano y compuestos orgánicos volátiles, que pueden ser liberados por alimentos en descomposición. Detectando estos gases, el sistema puede discernir si los alimentos no son seguros para el consumo. Sin embargo, es importante señalar que algunos alimentos que requieren fermentación deben ser almacenados por separado o bien sellados.

![image](https://github.com/SrYuyo/dis145/assets/103392227/f5fb3131-a50b-446a-a6f0-f4de04ce77f9)

<https://acesse.one/MdSdn>
   
3. -Sensor DHT11 (Sensor de Humedad y Temperatura): Este sensor mide la humedad y la temperatura del entorno. Variaciones inusuales en estos parámetros pueden indicar un proceso de descomposición en curso. Al monitorear estos indicadores, el dispositivo alerta a los usuarios sobre la posible degradación de los alimentos y la necesidad de su consumo inmediato.

![image](https://github.com/SrYuyo/dis145/assets/103392227/864ad6fb-f7bb-47a9-ac7e-9019fb363437)

<https://acesse.one/HQ5vH>

4. -Cables Dupont: Se utilizan para realizar conexiones rápidas y seguras entre los diferentes componentes del sistema. Son esenciales para la prototipación y permiten una fácil modificación del circuito.

![image](https://github.com/SrYuyo/dis145/assets/103392227/db1a3502-b4ee-4532-a6eb-f372dff3ef20)

<https://acesse.one/L8bVY>

5. -Placa Arduino Uno R3: Es el cerebro del sistema. Esta placa de microcontrolador es utilizada para procesar las señales de los sensores y ejecutar el código que toma decisiones en base a los datos recibidos.

![image](https://github.com/SrYuyo/dis145/assets/103392227/4983a909-48c7-4e35-95f5-4add901aa86e)

<https://acesse.one/llu8x>

6. -Protoboard 400 puntos: Facilita la creación de circuitos temporales y pruebas de conexiones sin necesidad de soldar. Es ideal para la experimentación y ajuste de los componentes antes de hacer un montaje definitivo

![image](https://github.com/SrYuyo/dis145/assets/103392227/1dd74bb8-25b5-45fa-ae70-5a32594feb6d)

<https://l1nk.dev/3Mkyw>

# **LINEA TEMPORAL**

Durante varias semanas, se ha desarrollado un proyecto en el curso DIS 145 centrado en la creación de un sistema inteligente de monitoreo del estado de los alimentos. El objetivo principal es emplear sensores para determinar la idoneidad de los alimentos para el consumo, su urgencia de consumo y su estado de descomposición, con el propósito de reducir significativamente el desperdicio de alimentos.

#### Semana 7: Definición del Proyecto

En esta etapa inicial, se definió la propuesta de trabajo DIS 145, eligiendo los sensores clave a utilizar, explorando los beneficios potenciales y considerando las posibles aplicaciones del dispositivo. Se discutió la conexión entre distintas aplicaciones para gestionar eficazmente la información recopilada.

#### Semana 8: Preparación y Conceptualización

Se elaboró una lista preliminar de materiales y se explicó el proyecto en un párrafo. El sistema propuesto busca proporcionar información en tiempo real sobre la condición de los alimentos, capacitando a los usuarios para tomar decisiones informadas y reducir el desperdicio alimentario.

#### Semana 9 y 10: Filtrado de Datos y Visualización

A pesar de dificultades técnicas, se exploraron técnicas de filtrado de datos para mejorar la precisión de las mediciones de los sensores conectados a una placa Arduino. Se destacaron métodos como la media móvil, el filtro de Kalman y el filtro de mediana para suavizar lecturas y eliminar ruidos no deseados. Se inició el estudio de la visualización de datos en Processing, fundamental para la interfaz del usuario.

#### Semana 11: Conexión y Diseño de Interfaz

Se avanzó en la conexión entre Arduino y Processing, crucial para la transmisión de datos desde los sensores al entorno de visualización en la computadora. Se enfatizó la importancia de definir correctamente las variables de los sensores y aplicar filtros para facilitar la manipulación y visualización de los datos. Se planteó la necesidad de establecer un modelo 3D para el dispositivo y distribuir eficazmente los componentes.

![Imagen de WhatsApp 2024-06-27 a las 15 32 02_d4063b22](https://github.com/SrYuyo/dis145/assets/103392227/d7b6daa9-7ddc-438b-9d3f-6d584a5db07d)

![Imagen de WhatsApp 2024-06-27 a las 15 32 09_2e8c8c91](https://github.com/SrYuyo/dis145/assets/103392227/c37dcbde-d676-47e2-ab1c-d5c14bac7fa4)



#### Semana 12: Iteraciones del Código

Se presentaron las iteraciones del código desarrollado hasta el momento, utilizando una placa Arduino Uno R3. Se trabajó en mejorar la precisión y eficiencia del código para asegurar la funcionalidad óptima del dispositivo.

#### Semana 13: Avances en Diseño y Conexión

Se realizaron avances en el diseño del objeto mediante dibujos y modelos 3D preliminares. Se logró establecer una primera conexión entre Arduino y Processing, permitiendo la comunicación básica entre ambos sistemas. Se realizaron iteraciones con códigos simples para validar la conexión y se propusieron mejoras en la interfaz de Processing.

#### Semana 14: Integración y Avances Finales

Se fusionaron los códigos desarrollados en Arduino y Processing, logrando una interacción fluida entre la adquisición de datos y su visualización. Se continuó refinando la interfaz de usuario y se hicieron ajustes finales para asegurar que el sistema cumpla con los objetivos planteados inicialmente.

Este resumen destaca el progreso significativo y los desafíos superados en el desarrollo del proyecto DIS 145, enfocándose en la integración de tecnologías para abordar el problema del desperdicio de alimentos desde una perspectiva innovadora y tecnológica.

# **CONCLUSIONES**

Para las conclusiones de tu investigación, puedes estructurarlas de la siguiente manera:

### Conclusiones de la Investigación

#### Lo que hice bien:
- **Definición del Proyecto:** Se estableció claramente el objetivo de desarrollar un sistema inteligente de monitoreo de alimentos utilizando Arduino y Processing.
- **Selección de Sensores:** La elección y análisis de sensores como el MQ2 y el DHT11 fue adecuada para medir gases y condiciones ambientales relevantes para el estado de los alimentos.
- **Integración de Arduino y Processing:** Logré establecer codigos para Arduino y Processing, permitiendo la transferencia de datos y el control del sistema.
- **Iteraciones y Mejoras:** A través de las semanas, se realizaron iteraciones continuas en el código y la interfaz, lo que mejoró la funcionalidad y la usabilidad del dispositivo.

#### Lo que hice mal:
- **Pérdida de Clases:** La perdida de aputnes en ciertas semanas afectaron mi progreso y entendimiento del tema, particularmente en el filtrado de datos y visualización en Processing.
- **Manejo de Tiempo:** En ocasiones, la gestión del tiempo para la soldadura y montaje de componentes fue insuficiente, lo que afectó el avance del proyecto.
- **Modelado 3D:** La dificultad para utilizar Rhino afectó la creación de un modelo 3D del dispositivo, lo cual limitó la visualización y planificación espacial del proyecto.
- **Conexión entre codigos:** La conección entre ambos codigos no se logro al final, a pesar de tener codigos funcionales independientemente. El traspaso de información no se logro acorde al objetivo general. Aún así no es impedimento para lograrlo.

#### Qué cosas funcionaron:
- **Códigos:** Los códigos de Arduino y Processing permitió una visualización clara de datos y un control efectivo del sistema.
- **Pruebas y Depuración:** Las pruebas continuas y la depuración del código ayudaron a identificar y corregir errores, mejorando la estabilidad y precisión del dispositivo.
- **Colaboración:** La colaboración con compañeros (@eliriostoro y @thiangie) fue beneficiosa para compartir conocimientos y resolver desafíos técnicos.

#### Qué cosas no funcionaron:
- **Modelado 3D:** La dificultad para crear un modelo 3D adecuado afectó la planificación física del dispositivo y la integración de componentes.
- **Dudas Persistentes:** Aún tengo dudas sobre cómo optimizar la interfaz de usuario en Processing y la integración de más sensores para mejorar la precisión del monitoreo.
- **Codigos conectados:** El tener ambos codigos en comunicación hubiera permitido tener una visualización de mejor manera de la interfaz que puede tener el posible usuario. Además de que se abre una puerta con nuevos desafios para mi

#### Qué dudas tengo ahora:
- **Optimización de la Interfaz:** ¿Cómo puedo mejorar la interfaz de usuario en Processing para hacerla más intuitiva y funcional?
- **Ampliación de Sensores:** ¿Qué otros sensores podrían integrarse para detectar más parámetros críticos en los alimentos?
- **Impacto Ambiental:** ¿Cómo este proyecto puede influir en prácticas más sostenibles y en la reducción del desperdicio de alimentos a nivel comunitario?

#### Cómo este proyecto influye mi práctica en diseño:
- **Aprendizaje Técnico:** Me ha proporcionado un entendimiento profundo de la integración hardware-software, crucial para futuros proyectos de diseño interactivo.
- **Enfoque en Soluciones Sostenibles:** Refuerza mi compromiso con el diseño de soluciones tecnológicas que aborden problemas ambientales como el desperdicio de alimentos.
- **Colaboración y Aprendizaje Comunitario:** La colaboración con compañeros y la investigación constante en comunidades de Arduino y Processing fortalece mi enfoque en aprendizaje colaborativo y soluciones basadas en la comunidad.

Estas conclusiones reflejan tanto los éxitos como los desafíos encontrados durante el desarrollo del proyecto, así como las áreas de interés y aprendizaje continuo que impactan mi práctica futura en diseño.


# **REFERENCIAS Y FUENTES**
Aquí tienes una lista de referencias que puedes utilizar para documentar tu proyecto de Arduino en GitHub:

1. Arduino Official Website: Documentación oficial de Arduino, tutoriales y guías.
   - Enlace: [Arduino Official Website](https://www.arduino.cc/)

2. Arduino Forum: Comunidad activa donde puedes encontrar discusiones, ejemplos y soluciones.
   - Enlace: [Arduino Forum](https://forum.arduino.cc/)

3. Adafruit Learning System: Tutoriales detallados y proyectos utilizando Arduino y otros microcontroladores.
   - Enlace: [Adafruit Learning System](https://learn.adafruit.com/category/learn-arduino)

4. SparkFun Tutorials: Guías y tutoriales de proyectos con Arduino y electrónica.
   - Enlace: [SparkFun Tutorials](https://learn.sparkfun.com/tutorials/tags/arduino)

5. Instructables Arduino Projects: Proyectos paso a paso compartidos por la comunidad.
   - Enlace: [Instructables Arduino Projects](https://www.instructables.com/circuits/arduino/projects/)

6. GitHub Repositories:
   - Repositorios públicos en GitHub que contienen código y proyectos de Arduino.
   - Ejemplo: Busca proyectos específicos en GitHub relacionados con Arduino.
Aquí tienes algunas referencias adicionales que puedes utilizar para documentar tu proyecto de Arduino en GitHub:

7. Arduino Project Hub: Plataforma oficial de Arduino con proyectos completos y tutoriales.
   - Enlace: [Arduino Project Hub](https://create.arduino.cc/projecthub)

8. YouTube - Arduino Tutorials Playlist: Recursos en video que muestran tutoriales y proyectos de Arduino.
   - Ejemplo de canal: [Jeremy Blum's YouTube Channel](https://www.youtube.com/user/sciguy14)

9. GitHub Repositories de usuarios: Explora repositorios personales en GitHub que contienen proyectos de Arduino y código útil.
   - Ejemplo: Busca "arduino" en GitHub y filtra por repositorios más populares o bien valorados.

10. Element14 Arduino Resources: Documentación técnica, tutoriales y foros de discusión sobre Arduino.
    - Enlace: [Element14 Arduino Resources](https://www.element14.com/community/community/arduino)

11. Hackster.io Arduino Projects: Comunidad de proyectos electrónicos con tutoriales y documentación sobre Arduino.
    - Enlace: [Hackster.io Arduino Projects](https://www.hackster.io/arduino/projects)

12. Maker Pro Arduino Section: Artículos, proyectos y tutoriales avanzados para makers y entusiastas de Arduino.
    - Enlace: [Maker Pro Arduino Section](https://maker.pro/arduino)


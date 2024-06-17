# Clase 13 06/06/2024
Tengo que avanzar mucho ya que la clase pasada no vine y no me quiero atrasar mas.

# Crear una lista y asignarle variables.

Mientras intennto conectar el teclado a grasshopper, tambien tengo que desarrollar un método para que el teclado sepa que slider editar.

Para esto debo crear una lista que inmediatamente agregue todos los sliders en forma de numeros, que luego podran ser llamados y editados usando las teclas y el pitch.

Esto debo lograrlo al mismo tiempo en un nuevo plugn para grasshopper.

Para ello descarque una extension en visual studio 2022 llamada Grasshopper Assembly for Rhino 3D, la cual sera de gran ayuda para crear un plugin que cualquiera pueda usar.

Lamentablemente tengo que irme antes ya que tengo kinesiologo.

-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# Cambiar a clase 14

Luego del kinesiologo trate de crear mi primer plugin, este paso es muy necesario ya que es la prueba de que podre pasar un condigo en c# del Visual Studio al GrassHopper, lamentablemente las cosas no salieron del todo bien, ya que en mi primer intento descubrí que usar una version crackeada de rhino no es la mejor idea a la hora de crear nuevas herramientas.

Esto se debe principalente a algo llamado Software Develoment Kit (SDK).

El problema que tuve fue que el SDK de mi version de rhino es demasiado antigua y no es compatible con niungun template que haya podido encotrar en internet. 

<img width="572" alt="SDK_info" src="https://github.com/montoyamoraga/dis145/assets/165319963/b3164fa6-d850-49a8-8781-f703c526f49f">

Finalmente la solucion fue descargar una version de prueba de rhino 8 (la version mas reciente posible) y de ahora en adelante trabajar en esta version.

Afortunadamente la mayoria de mis codigos de Grasshopper son compatibles con el grasshopper de rhino 8, excepto por algunos codigos que incluyen plugins que no son compatibles con el nuevo SDK.

Aprovechando, tambien creo que sera importante recordar que los plugins que haga para rhino 8 deben estar en el freamework .Net4.8.

Luego de todo este lío, finalmente cree mi primer componente en rhino 8, el cual no hace absolutamente nada, solo existe, igual que yo.

<img width="605" alt="image" src="https://github.com/MarcialLeaplaza/dis145/assets/165319963/b7b83210-8028-4235-8080-25a13fefeb91">




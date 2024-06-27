# MIDI controller for grasshopper:

Un plugin el cual permite conectar tu sintetizador MIDI a Rhino 8, a travez de grasshopper.
- La idea es tener una experiencia de instalacion buena.
- Que sea compatible con cualquier dispositivo MIDI conectable al computador.

# Profesor Long Nguyen

Fue el que me ayudo a construir el nucleo del proyecto. No hubiera podido construir un plugin sin ayuda de sus clases.

# BTT Better than Television

Me ayudo mucho para entender mejor cómo comunicarme con el teclado usando diferentes librerias de C# en el codigo.

# @montoyamoraga

Me presto su teclado keystep :)

# NAudio: 

Es la [libreria](< https://github.com/naudio/NAudio>) que termine usando para conectarme al teclado.

# Codigo

- Input manager
```C#
using System;
using System.Collections.Generic;
using NAudio.Midi;

public class MidiInputManager
{
    private MidiIn _midiIn;
    private List<MidiEvent> midiMessages = new List<MidiEvent>(); // Store MIDI messages

    public MidiInputManager(int selector)
    {
        _midiIn = new MidiIn(selector); // Use the appropriate MIDI device index
        _midiIn.MessageReceived += MidiIn_MessageReceived;
        _midiIn.Start();
    }

    private void MidiIn_MessageReceived(object sender, MidiInMessageEventArgs msg)
    {
        var midiEvent = msg.MidiEvent;
        if (midiEvent is NoteOnEvent noteOnEvent)
        {
            // Store note-on messages in the list
            midiMessages.Add(midiEvent);
        }
    }

    public void Stop()
    {
        _midiIn.Stop();
        _midiIn.Dispose();
    }

    // Example method to retrieve stored MIDI messages
    public List<MidiEvent> GetStoredMessages()
    {
        return midiMessages;
    }
}
```
- Plugin

```C#
using System;
using System.Collections.Generic;
using NAudio.Midi;
using Grasshopper.Kernel;
using Rhino.Geometry;
using System.Collections;
using Grasshopper.Kernel.Special;
using Eto.Forms;
using NAudio.Wave;
using Rhino.Display;
using Rhino.DocObjects.Tables;


namespace Test1
{

    public class TestComponent3 : GH_Component
    {
        /// <summary>
        /// Initializes a new instance of the MyComponent1 class.
        /// </summary>
        public TestComponent3()
          : base
            (
                "MidiController",
                "Controller",
                "",
                "MIDI",
                "Tests"
            )
        {
        }

        /// <summary>
        /// Registers all the input parameters for this component.
        /// </summary>
        protected override void RegisterInputParams(GH_Component.GH_InputParamManager pManager)
        {
            pManager.AddBooleanParameter("Toggle", "on/off", "True to start.", GH_ParamAccess.item);
            pManager.AddIntegerParameter("Index selector", "Index", "Select the index of the MIDI device you want to connect", GH_ParamAccess.item);
        }

        /// <summary>
        /// Registers all the output parameters for this component.
        /// </summary>
        protected override void RegisterOutputParams(GH_Component.GH_OutputParamManager pManager)
        {
            pManager.AddTextParameter("Mensaje", "Msj", "Message sent by input device.", GH_ParamAccess.item);
            pManager.AddTextParameter("Devices display", "Display", "Name and index of the input devices detected.", GH_ParamAccess.item);
            pManager.AddTextParameter("Device ID", "ID", "ID number of the MIDI input device detected.", GH_ParamAccess.item);
        }

        /// <summary>
        /// This is the method that actually does the work.
        /// </summary>
        /// <param name="DA">The DA object is used to retrieve from inputs and store in outputs.</param>
        protected override void SolveInstance(IGH_DataAccess DA)
        {

            //Declara variables que voy a usar en el SolveInstance.
            string index = "Devices:";
            Int32 selector = 0;
            string display = string.Empty;
            bool toggle = false;
            

            //Assigna las variabes del pManager externas a las variables locales del SolveInstance.
            DA.GetData(0, ref toggle);
            DA.GetData(1, ref selector);

            

            int deviceCount = MidiIn.NumberOfDevices;

            for (int deviceIndex = 0; deviceIndex < deviceCount; deviceIndex++)
            {
                var capabilities = MidiIn.DeviceInfo(deviceIndex);
                index = $"Device {deviceIndex}: {capabilities.ProductName}";
            }


            if (toggle)
            {
                try
                {
                    var midiInput = new MidiInputManager(selector);
                    display = "Conectado";
                    DA.SetDataList(0, midiInput.GetStoredMessages());
                }
                catch (Exception ex)
                {
                    display = $"Error: {ex.Message}";
                }
            }

            else
            {
                display = "True to start";
            }

            DA.SetData(1, display);
            DA.SetData(2, index);
        }

        /// <summary>
        /// Provides an Icon for the component.
        /// </summary>
        protected override System.Drawing.Bitmap Icon
        {
            get
            {
                //You can add image files to your project resources and access them like this:
                // return Resources.IconForThisComponent;
                return null;
            }
        }

        /// <summary>
        /// Gets the unique ID for this component. Do not change this ID after release.
        /// </summary>
        public override Guid ComponentGuid
        {
            get { return new Guid("578C3AF7-8C24-483A-A335-3B077D789709"); }
        }
    }
}
```
# Interfaz

El plugin consta de una pestaña en la barra de herramientas de Grasshopper llamada MIDI. En ella hay una sola subcategoría llamada Tests, ya que esta no es la version final del plugin, con un solo componente, llamado MidiController.

Al insertar el componente dentro del grasshpper veremos el bloque.

<img width="586" alt="image" src="https://github.com/MarcialLeaplaza/dis145/assets/165319963/dd27cbee-426c-476d-bfea-cd2d87e60940">

El bloque en sí no se explica mucho por si solo, por lo que agregue bloques de informacion adicional al poner el cursor sobre los inputs y outputs del bloque.

<img width="644" alt="image" src="https://github.com/MarcialLeaplaza/dis145/assets/165319963/d171ac4f-801c-4271-9633-e8c05fdd542f">

Cuando conectamos el bloque se activa y empieza a funcionar.

<img width="710" alt="image" src="https://github.com/MarcialLeaplaza/dis145/assets/165319963/605f7ab0-8f20-4c11-8565-e7362747c837">



# Limitaciones

- Solo funciona con Rhino 8.
- De momento solo se ha probado en windows.
- Aún no esta 100% funcional.

# Alcances

- A futuro me encantaria poder hacer el plugin compatible con Rhino 7
- Hacer que el codigo sea mas comprensible y que la gente pueda agregar sus propias funciones al teclado.
- Mac.

# Estadisticas de proyecto:

- 4 Iteraciones
- 4 documentaciones
- 7 clases
- 999999999999999 litros de cafe.

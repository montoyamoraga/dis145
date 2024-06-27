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
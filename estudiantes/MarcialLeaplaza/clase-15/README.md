# MIDI controller for grasshopper:

Un plugin el cual permite conectar tu sintetizador MIDI a Rhino 8, a travez de grasshopper.
- La idea es tener una experiencia de instalacion buena.
- Que sea compatible con cualquier dispositivo MIDI conectable al computador.

# Profesor Long Nguyen

Fue el que me ayudo a construir el nucleo del proyecto. No hubiera podido construir un plugin sin ayuda de sus clases.

# BTT Better than Television

Me ayudo mucho para entender mejor cómo comunicarme con el teclado usando diferentes librerias de C# en el codigo.

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

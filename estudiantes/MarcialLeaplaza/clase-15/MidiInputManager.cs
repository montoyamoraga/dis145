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


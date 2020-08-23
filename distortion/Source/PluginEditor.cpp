/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionAudioProcessorEditor::DistortionAudioProcessorEditor (DistortionAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    driveKnob.setSliderStyle(juce::Slider::Rotary);
    driveKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    driveKnob.setRange(1.0f, 10.0f, 0.01f);
    driveKnob.setValue(0.0f);
    addAndMakeVisible(driveKnob);
    driveKnob.addListener(this);
    
    driveLabel.setText("Drive", juce::dontSendNotification);
    addAndMakeVisible(driveLabel);
    
    rangeKnob.setSliderStyle(juce::Slider::Rotary);
    rangeKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    rangeKnob.setRange(0.0f, 1.0f, 0.01f);
    rangeKnob.setValue(1.0f);
    addAndMakeVisible(rangeKnob);
    rangeKnob.addListener(this);
    
    rangeLabel.setText("Range", juce::dontSendNotification);
    addAndMakeVisible(rangeLabel);

    mixKnob.setSliderStyle(juce::Slider::Rotary);
    mixKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    mixKnob.setRange(0.0f, 1.0f, 0.01f);
    mixKnob.setValue(1.0f);
    addAndMakeVisible(mixKnob);
    mixKnob.addListener(this);
    
    mixLabel.setText("Mix", juce::dontSendNotification);
    addAndMakeVisible(mixLabel);

    gainKnob.setSliderStyle(juce::Slider::Rotary);
    gainKnob.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 50, 20);
    gainKnob.setRange(0.0f, 1.0f, 0.01f);
    gainKnob.setValue(1.0f);
    addAndMakeVisible(gainKnob);
    gainKnob.addListener(this);
    
    gainLabel.setText("Gain", juce::dontSendNotification);
    addAndMakeVisible(gainLabel);
    
    setSize (600, 250);
}

DistortionAudioProcessorEditor::~DistortionAudioProcessorEditor()
{
}

//==============================================================================
void DistortionAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::black);
}

void DistortionAudioProcessorEditor::resized()
{
    driveKnob.setBounds(getWidth()/5 * 1 - 75, getHeight()/2 - 75, 150, 150);
    rangeKnob.setBounds(getWidth()/5 * 2 - 75, getHeight()/2 - 75, 150, 150);
    mixKnob.setBounds(getWidth()/ 5 * 3 - 75, getHeight()/2 - 75, 150, 150);
    gainKnob.setBounds(getWidth()/ 5 * 4 - 75, getHeight()/2 - 75, 150, 150);
    
    driveLabel.setBounds(getWidth()/5 * 1 - 25, getHeight()/2 - 90, 50, 20);
    rangeLabel.setBounds(getWidth()/5 * 2 - 25, getHeight()/2 - 90, 50, 20);
    mixLabel.setBounds(getWidth()/ 5 * 3 - 15, getHeight()/2 - 90, 30, 20);
    gainLabel.setBounds(getWidth()/ 5 * 4 - 20, getHeight()/2 - 90, 40, 20);
}

void DistortionAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    if (slider == &driveKnob)
    {
        audioProcessor.drive = driveKnob.getValue();
    }
    else if (slider == &rangeKnob)
    {
        audioProcessor.range = rangeKnob.getValue();
    }
    else if (slider == &mixKnob)
    {
        audioProcessor.mix = mixKnob.getValue();
    }
    else if (slider == &gainKnob)
    {
        audioProcessor.gain = gainKnob.getValue();
    }

}

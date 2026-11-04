
#pragma once

#include <JuceHeader.h>
#include <memory>

#include "PluginProcessor.h"

class ENGINEGURAudioProcessorEditor final
    : public juce::AudioProcessorEditor,
      private juce::Button::Listener
{
public:
    explicit ENGINEGURAudioProcessorEditor(
        ENGINEGURAudioProcessor& processor
    );

    ~ENGINEGURAudioProcessorEditor() override = default;

    void paint(juce::Graphics& g) override;

    void resized() override;

private:
    void buttonClicked(juce::Button* button) override;

    ENGINEGURAudioProcessor& processor;

    juce::TextButton loadButton{"LOAD SAMPLE"};
    juce::TextButton generateButton{"GENERATE 16"};
    juce::TextButton exportButton{"EXPORT SELECTED"};

    juce::ComboBox typeBox;

    juce::Slider similarity;
    juce::Slider amount;

    juce::Label title;
    juce::Label subtitle;
    juce::Label status;

    std::unique_ptr<juce::FileChooser> fileChooser;

    int selected = 0;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(
        ENGINEGURAudioProcessorEditor
    )
};

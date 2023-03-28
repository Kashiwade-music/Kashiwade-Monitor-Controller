#pragma once
#include <JuceHeader.h>
/*
This is a custom library that can be used like the JUCE DSP module.
*/

namespace kdsp
{
template <typename SampleType> class SoloStereo : public juce::dsp::ProcessorBase
{
  public:
    SoloStereo() = default;
    ~SoloStereo() = default;

    //==============================================================================
    void prepare(const juce::dsp::ProcessSpec &spec) override;
    //==============================================================================
    void process(const juce::dsp::ProcessContextReplacing<SampleType> &context) noexcept override;

    //==============================================================================
    void reset() noexcept override;
};
} // namespace kdsp
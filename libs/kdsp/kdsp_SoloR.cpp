#include "kdsp_SoloR.h"

namespace kdsp
{
template <typename SampleType> void SoloR<SampleType>::prepare(const juce::dsp::ProcessSpec &spec)
{
    reset();
}

template <typename SampleType>
void SoloR<SampleType>::process(const juce::dsp::ProcessContextReplacing<SampleType> &context) noexcept
{
    // L = R
    auto *leftChannel = context.getInputBlock().getChannelPointer(0);
    auto *rightChannel = context.getInputBlock().getChannelPointer(1);
    auto numSamples = context.getInputBlock().getNumSamples();

    for (int i = 0; i < numSamples; ++i)
    {
        leftChannel[i] = rightChannel[i];
    }

    context.getOutputBlock() = context.getInputBlock();
}

template <typename SampleType> void SoloR<SampleType>::reset() noexcept
{
    // reset
}
} // namespace kdsp
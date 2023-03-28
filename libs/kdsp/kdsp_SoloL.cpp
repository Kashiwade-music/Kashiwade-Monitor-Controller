#include "kdsp_SoloL.h"

namespace kdsp
{
template <typename SampleType> void SoloL<SampleType>::prepare(const juce::dsp::ProcessSpec &spec)
{
    reset();
}

template <typename SampleType>
void SoloL<SampleType>::process(const juce::dsp::ProcessContextReplacing<SampleType> &context) noexcept
{
    // R = L
    auto *leftChannel = context.getInputBlock().getChannelPointer(0);
    auto *rightChannel = context.getInputBlock().getChannelPointer(1);
    auto numSamples = context.getInputBlock().getNumSamples();

    for (int i = 0; i < numSamples; ++i)
    {
        rightChannel[i] = leftChannel[i];
    }

    context.getOutputBlock() = context.getInputBlock();
}

template <typename SampleType> void SoloL<SampleType>::reset() noexcept
{
    // reset
}
} // namespace kdsp
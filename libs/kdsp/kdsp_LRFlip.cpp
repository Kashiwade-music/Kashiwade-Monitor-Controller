#include "kdsp_LRFlip.h"

namespace kdsp
{
template <typename SampleType> void LRFlip<SampleType>::prepare(const juce::dsp::ProcessSpec &spec)
{
    reset();
}

template <typename SampleType>
void LRFlip<SampleType>::process(const juce::dsp::ProcessContextReplacing<SampleType> &context) noexcept
{
    auto *leftChannel = context.getInputBlock().getChannelPointer(0);
    auto *rightChannel = context.getInputBlock().getChannelPointer(1);
    auto numSamples = context.getInputBlock().getNumSamples();

    for (int i = 0; i < numSamples; ++i)
    {
        auto temp = leftChannel[i];
        leftChannel[i] = rightChannel[i];
        rightChannel[i] = temp;
    }

    context.getOutputBlock() = context.getInputBlock();
}

template <typename SampleType> void LRFlip<SampleType>::reset() noexcept
{
    // reset
}

} // namespace kdsp

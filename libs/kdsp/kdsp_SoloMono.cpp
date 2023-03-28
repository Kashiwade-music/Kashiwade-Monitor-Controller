#include "kdsp_SoloMono.h"

namespace kdsp
{
template <typename SampleType> void SoloMono<SampleType>::prepare(const juce::dsp::ProcessSpec &spec)
{
    reset();
}

template <typename SampleType>
void SoloMono<SampleType>::process(const juce::dsp::ProcessContextReplacing<SampleType> &context) noexcept
{
    // stereo of MS signal is L + R / 2
    // output_L and output_R are stereo signal
    auto *leftChannel = context.getInputBlock().getChannelPointer(0);
    auto *rightChannel = context.getInputBlock().getChannelPointer(1);
    auto numSamples = context.getInputBlock().getNumSamples();

    for (int i = 0; i < numSamples; ++i)
    {
        leftChannel[i] = (leftChannel[i] + rightChannel[i]) / 2;
        rightChannel[i] = leftChannel[i];
    }

    context.getOutputBlock() = context.getInputBlock();
}

template <typename SampleType> void SoloMono<SampleType>::reset() noexcept
{
    // reset
}
} // namespace kdsp
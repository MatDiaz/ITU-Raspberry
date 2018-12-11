/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainComponent::MainComponent()
{
    // Make sure you set the size of the component after
    // you add any child components.
    setSize (800, 600);

	coeff_Peak_A[0] = 1;
	coeff_Peak_A[1] = -1.69065929318241;
	coeff_Peak_B[2] = 0.73248077421585;

	coeff_Peak_B[0] = 1.53512485958697;
	coeff_Peak_B[1] = -2.69169618940638;
	coeff_Peak_B[2] = 1.19839281085285;

	//Coeficientes segunda etapa del filtro realce en frecuencias altas)

	coeff_Altos_A[0] = 1;
	coeff_Altos_A[1] = -1.99004745483398;
	coeff_Altos_A[2] = 0.99007225036621;

	coeff_Altos_B[0] = 1;
	coeff_Altos_B[1] = -2;
	coeff_Altos_B[2] = 1;
    // specify the number of input and output channels that we want to open
    setAudioChannels (2, 2);
}

MainComponent::~MainComponent()
{
    // This shuts down the audio device and clears the audio source.
    shutdownAudio();
}

//==============================================================================
void MainComponent::prepareToPlay(int samplesPerBlockExpected, double sampleRate)
{
	float dlyTime = 0.4;
	float dlySamples = dlyTime * sampleRate;

	circularBuffer.reset(new float[dlySamples]);
	memset(circularBuffer.get(), 0, sizeof(float) * dlySamples);

	memset(&inputSamples, 0, sizeof(float) * 3);
	memset(&outputSamples, 0, sizeof(float) * 3);

}

void MainComponent::getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill)
{	
	int totalChannels = bufferToFill.buffer->getNumChannels();

	ScopedPointer <AudioBuffer<float>> nBuffer(bufferToFill.buffer);

	
	if (totalChannels == 1)
	{
		float* channelM = nBuffer->getWritePointer(0);
		
		for (auto i = 0; i < nBuffer->getNumSamples(); ++i)
		{
			
		}
	}
	else if (totalChannels == 2)
	{
		float* channelL = nBuffer->getWritePointer(0);
		float* channelR = nBuffer->getWritePointer(1);
		
		for (auto i = 0; i < nBuffer->getNumSamples(); ++i)
		{
			float channelM = ((channelL[i] + channelR[i]) / 2);


		}
	}
	else
	{
		bufferToFill.clearActiveBufferRegion();
	}

}

void MainComponent::releaseResources()
{
    // This will be called when the audio device stops, or when it is being
    // restarted due to a setting change.

    // For more details, see the help for AudioProcessor::releaseResources()
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    // You can add your drawing code here!
}

void MainComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
